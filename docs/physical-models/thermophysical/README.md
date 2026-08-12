# 热物性与热输运

OpenFOAM-13 流体/固体物性由 **`thermoType` 拼装**（或少数专用 thermo 类）描述；热通量与组分扩散由 **`thermophysicalTransport`** 描述。不可压无能量方程求解器则只用 `physicalProperties` 粘度模型。

清单对照：[`../_inventory/rts-thermos.md`](../_inventory/rts-thermos.md)、[`../_inventory/rts-thermophysicalTransport.md`](../_inventory/rts-thermophysicalTransport.md)、[`../_inventory/rts-physicalProperties.md`](../_inventory/rts-physicalProperties.md)。

## 本目录结构

| 子目录 | 内容 |
|--------|------|
| [equations-of-state/](equations-of-state/) | 状态方程 |
| [thermo-models/](thermo-models/) | `hConstThermo`、`janafThermo` 等 |
| [transport/](transport/) | `constTransport`、`sutherlandTransport` 等 |
| [mixtures-and-energy/](mixtures-and-energy/) | 混合物与能量形式 |
| [solid-liquid-tabulated/](solid-liquid-tabulated/) | 固/液预置物性、常固体 thermo、不可压粘度与漂移通量粘度 |
| [chemistry-reactions/](chemistry-reactions/) | 化学表化/火焰速度/饱和模型概览（燃烧全谱见 Phase 4） |
| [thermophysical-transport/](thermophysical-transport/) | `thermophysicalTransport` 模型 |

---

## `thermoType` 拼装规则

字典（通常 `constant/physicalProperties`）中：

```c++
thermoType
{
    type            hePsiThermo;   // 或 heRhoThermo / heSolidThermo / ...
    mixture         pureMixture;
    transport       const;         // → constTransport
    thermo          hConst;        // → hConstThermo
    equationOfState perfectGas;    // → perfectGas
    specie          specie;
    energy          sensibleEnthalpy;
}
```

**嵌套顺序（内→外）**：

```text
specie
  └─ equationOfState
       └─ thermo          (Cp/h 或 Cv/e)
            └─ energy     (sensible*/absolute*)
                 └─ transport (μ, κ/Pr)
                      └─ mixture 包装
                           └─ 顶层 Thermo 类型 (psi/rho/solid/…)
```

源码用 `typedefThermo` / `forThermo` 展开（[`src/thermophysicalModels/specie/include/`](../../src/thermophysicalModels/specie/include/)）。**不是任意字段都能组合**——只有下面宏表里的笛卡尔积会被 `*Thermos.C` 注册。

字典短名与类名对应（常见）：

| 字典字段 | 短名示例 | C++ 类 |
|----------|----------|--------|
| `transport` | `const`, `sutherland` | `constTransport`, `sutherlandTransport` |
| `thermo` | `hConst`, `eConst`, `janaf` | `hConstThermo`, `eConstThermo`, `janafThermo` |
| `equationOfState` | `perfectGas`, `rhoConst` | 同名 |
| `energy` | `sensibleEnthalpy` | 同名 |
| `mixture` | `pureMixture` | 同名 |

---

## 合法组合表（来自 `for`*.H`）

下列为宏展开的**笛卡尔积**部件；`*Thermos.C` 再与 `mixture` / 顶层 `type` 组合注册。计数仅计 specie 层（不含 mixture）。

### 气体 — `forGases`.H`

| 层 | 允许类型 |
|----|----------|
| EOS | `perfectGas`, `Boussinesq`（×2） |
| energy+thermo | `sensibleEnthalpy`+`hConstThermo`；`sensibleEnthalpy`+`janafThermo`；`sensibleInternalEnergy`+`eConstThermo`；`sensibleInternalEnergy`+`hConstThermo`；`sensibleInternalEnergy`+`janafThermo`（×5） |
| transport | `constTransport`, `sutherlandTransport`（×2） |

**组合数**：2 × 5 × 2 = **20** 种 specie thermo。

`forCoeffGases`：同上但 EOS **仅** `perfectGas` → 1 × 5 × 2 = **10**（供系数型多组分混合物）。

### 绝对焓气体 — `forAbsoluteGases`.H`

| 层 | 允许类型 |
|----|----------|
| EOS | `perfectGas` |
| energy | **仅** `absoluteEnthalpy` |
| thermo | `hConstThermo`, `janafThermo` |
| transport | `constTransport`, `sutherlandTransport` |

**组合数**：1 × 2 × 2 = **4**。

### 液体 — `forLiquids`.H`

| 层 | 允许类型 |
|----|----------|
| EOS | `adiabaticPerfectFluid`, `rhoConst`, `rPolynomial`（×3） |
| energy+thermo | `sensibleEnthalpy`+`hConstThermo`；`sensibleInternalEnergy`+`eConstThermo`；`sensibleInternalEnergy`+`hConstThermo`（×3） |
| transport | **仅** `constTransport` |

**组合数**：3 × 3 × 1 = **9**。

`forCoeffLiquids`：EOS 为 `rhoConst`, `rPolynomial`（无 `adiabaticPerfectFluid`）→ 2 × 3 × 1 = **6**。

### 表格式 — `forTabulated`.H`

| 分支 | EOS | thermo | energy | transport | 组合数 |
|------|-----|--------|--------|-----------|--------|
| 可压表 | `rhoTabulated` | `hTabulatedThermo` / `eTabulatedThermo` | sensible h / e | `tabulatedTransport` | 2 |
| 不可压表 | `icoTabulated` | `hIcoTabulatedThermo` / `eIcoTabulatedThermo` | sensible h / e | `icoTabulatedTransport` | 2 |

**合计** `forTabulated`：**4**。

### 固体 — `forSolids`.H`（`src/thermophysicalModels/solidThermo/solidSpecie/include/`）

| 层 | 允许类型 |
|----|----------|
| EOS | **仅** `rhoConst` |
| energy | **仅** `sensibleInternalEnergy` |
| thermo | `eConstThermo`, `ePolynomialThermo`, `ePowerThermo`, `eIcoTabulatedThermo`（×4） |
| transport | `constIsoSolidTransport`, `constAnisoSolidTransport`, `exponentialSolidTransport`, `polynomialSolidTransport`, `tabulatedSolidTransport`（×5） |

**组合数**：1 × 4 × 5 = **20**。

### 工厂文件谁注册了什么

| 工厂 | 宏调用 | 典型顶层 `type` |
|------|--------|-----------------|
| [`psiThermos`.C`](../../src/thermophysicalModels/basic/psiThermo/psiThermos.C) | `forGases` + `pureMixture` | `hePsiThermo` |
| [`rhoFluidThermos`.C`](../../src/thermophysicalModels/basic/rhoFluidThermo/rhoFluidThermos.C) | `forGases` + `forLiquids` + `forTabulated` | `heRhoThermo` |
| [`solidThermos`.C`](../../src/thermophysicalModels/solidThermo/solidThermo/solidThermos.C) | `forSolids` | `heSolidThermo` |
| [`liquidThermos`.C`](../../src/thermophysicalModels/basic/liquidThermo/liquidThermos.C) | `liquidPropertiesSelector` + sensible h/e | `liquidThermo` 路径 |
| [`rhoFluidMulticomponentThermos`.C`](../../src/thermophysicalModels/multicomponentThermo/rhoFluidMulticomponentThermo/rhoFluidMulticomponentThermos.C) | `forCoeffGases`/`forGases`/`forCoeffLiquids`/`forLiquids`/`forTabulated` + 多种 mixture | 多组分 `heRhoThermo` |
| [`psiMulticomponentThermos`.C`](../../src/thermophysicalModels/multicomponentThermo/psiMulticomponentThermo/psiMulticomponentThermos.C) | 气体多组分 | `hePsiThermo` 多组分 |
| [`psiuMulticomponentThermos`.C`](../../src/thermophysicalModels/multicomponentThermo/psiuMulticomponentThermo/psiuMulticomponentThermos.C) | 未燃/已燃（Xi） | `heheuPsiThermo` 等 |

**未进入上述 `for`*` 宏的 EOS**（如 `PengRobinsonGas`, `perfectFluid`, `linear`, `icoPolynomial`, `incompressiblePerfectGas`）仍在 specie 库中实现，可供专用代码路径使用；默认 `*Thermos.C` **不会**为其生成 RTS 组合——案例里选它们会报 unknown combination。

---

## 与求解器的关系（摘要）

| 求解器族 | 物性入口 | 热输运 |
|----------|----------|--------|
| `incompressibleFluid` / 不可压 VoF | `viscosityModel` + `nu` | 无 |
| `isothermalFluid` | `rhoFluidThermo`/`psiThermo`（等温） | 无能量方程 |
| `fluid` / `shockFluid` | fluid thermo | `thermophysicalTransport`（内建/可选） |
| `multicomponentFluid` / `XiFluid` | 多组分 / psiu | 多组分或流体 TTM |
| `compressibleVoF` | 各相 thermo | coupled TTM |
| `multiphaseEuler` | 相 `physicalProperties`.*` | 相 TTM |
| `solid` | `solidThermo` / `constSolidThermo` | 固体 TTM |
| `incompressibleDriftFlux` | mixture + 专用粘度/弥散 | 无 |

细表见 [`../01-solver-matrix.md`](../01-solver-matrix.md)。

---

## 字典示例（气体）

改编自 [`tutorials/fluid/aerofoilNACA0012Steady/constant/physicalProperties`](../../tutorials/fluid/aerofoilNACA0012Steady/constant/physicalProperties)：

```c++
thermoType
{
    type            hePsiThermo;
    mixture         pureMixture;
    transport       const;
    thermo          hConst;
    equationOfState perfectGas;
    specie          specie;
    energy          sensibleEnthalpy;
}
```

## 字典示例（热输运）

```c++
// constant/thermophysicalTransport — 须与 momentumTransport.simulationType 一致
laminar
{
    model           Fourier;   // 或多组分 unityLewisFourier / FickianFourier ...
}
```

湍流时改为 `RAS`/`LES` 块，常用 `unityLewisEddyDiffusivity` 等（见 [thermophysical-transport/](thermophysical-transport/)）。

---

## 注意事项

1. **拼写与短名**：`thermo` hConst` 对应类 `hConstThermo`；写 `hConstThermo` 作字典值通常会失败。
2. **能量匹配**：`h`*` 焓模型配 `sensibleEnthalpy`/`absoluteEnthalpy`；固体 `forSolids` 只有内能。
3. **库链接**：求解器 `Make/options` 未链 `fluidThermophysicalModels` 时，再合法的 `thermoType` 也无法构造。
4. **液体预置物性**：`liquidThermo` + `liquidProperties`（`H2O`、`C7H16`…）是另一条路径，见 [solid-liquid-tabulated/](solid-liquid-tabulated/)。

## 导航

- [`../01-solver-matrix.md`](../01-solver-matrix.md) · [`../README.md`](../README.md) · [`../00-conventions.md`](../00-conventions.md)
