# XiFluid 子模型树（Xi / XiEq / XiG / Su / 点火）

**适用**: 仅 [`XiFluid`](../solvers/XiFluid.md)（Weller b-Xi）。字典在 `constant/combustionProperties`，结构与 `multicomponentFluid` 的 `combustionModel` EDC` **不同**。

源码根：`applications/modules/XiFluid/`。

典型字段：`b`（regress）、`Xi`；非均质另需 `ft`/`fu`/`egr`（混合物类型决定）。

---

# 总配置模式

## 一句话
用 `flameWrinkling` 选 Xi 模型，并用 `laminarFlameSpeed`/`Su` 提供 \(S_u\)。

## 适用条件（求解器 / 场 / 前提）
- **适用**: `XiFluid`
- **前提**: 多组分/预混 thermo（psiu 系）；可选点火 fvModel

## 字典示例

传输型褶皱（`moriyoshiHomogeneous`）：

```cpp
#include "combustionPropertiesInclude"
// 内含 laminarFlameSpeed / Gulder

flameWrinkling
{
    model           transport;

    equilibrium
    {
        model           Gulder;
    }

    profile
    {
        model      linear;
    }

    generationRate
    {
        model           KTS;
    }
}
```

代数平衡型（`engine2Valve2D`）：

```cpp
flameWrinkling
{
    model           equilibrium;

    equilibrium
    {
        model           Gulder;
        SuMin           0.001;
    }

    profile
    {
        model           cubic;
    }

    generationRate
    {
        model           KTS;
    }
}
```

## 参数表
见下列各子模型。

## 控制方程与关联式
火焰面积比 \(\Xi\)：可输运或代数；与 \(S_u\)、湍流强度相关。回归变量 \(b\) 输运描述未燃/已燃。文献：Weller TF 9307；Gulder；Weller et al. Combustion Symposium 等（见 `XiFluid`.H`）。

## 文献与源码依据
- `applications/modules/XiFluid/XiFluid.H`
- `applications/modules/XiFluid/XiModels/`

## 教程与模板
`tutorials/XiFluid/{moriyoshiHomogeneous,engine2Valve2D,1D,stratified,kivaTest}`

## 注意事项
- 不要写 `combustionModel` laminar`——XiFluid 不走该 RTS。

---

# XiModel

## transport

### 一句话
求解 \(\Xi\) 输运方程（含生成/耗散）。

### 适用条件
应变敏感、需输运褶皱时（见 XiFluid Description）。

### 字典示例
`flameWrinkling` { model transport; ... }`

### 参数表
子模型：`equilibrium`（XiEq）、`profile`（XiProfile）、`generationRate`（XiG）。

### 控制方程与关联式
\(\Xi\) 输运；应变项进入方程（代数近似不含全部应变效应——见模块 Description）。

### 文献与源码依据
`XiModels/transport/transport.C`

### 教程与模板
`moriyoshiHomogeneous`

### 注意事项
需同时配置 XiEq / XiG / profile。

## equilibrium

### 一句话
代数平衡 \(\Xi\)（不输运）。

### 适用条件
准平衡褶皱假设足够时。

### 字典示例
`model` equilibrium;` + `equilibrium` { model Gulder; }`

### 参数表
| `SuMin` | \(S_u\) 下限 | [0 1 -1 0 0 0 0] |

### 控制方程与关联式
\(\Xi=\Xi_{\mathrm{eq}}(\ldots)\)。

### 文献与源码依据
`XiModels/equilibrium/`

### 教程与模板
`engine2Valve2D`

### 注意事项
—
## uniformConstant

### 一句话
常值 \(\Xi\)。

### 适用条件
调试/指定褶皱。

### 字典示例
`model` uniformConstant;`（系数见源码）

### 参数表
常值 \(\Xi\)。

### 控制方程与关联式
\(\Xi=\mathrm{const}\)。

### 文献与源码依据
`XiModels/uniformConstant/`

### 教程与模板
—
### 注意事项
—

---

# XiEqModel（equilibrium 子字典）

| 类型 | 一句话 | 源码 |
|------|--------|------|
| `Gulder` | Gulder 平衡褶皱 | `XiEqModels/Gulder/` |
| `constant` | 常值 \(\Xi_{\mathrm{eq}}\) | `XiEqModels/constant/` |
| `instability` | 含不稳定性的平衡模型 | `XiEqModels/instability/` |

### 通用模板小节

#### 一句话 / 适用 / 字典 / 参数 / 方程 / 依据 / 教程 / 注意
- **Gulder**：最常用；教程均见；依赖 \(u'/S_u\) 等。
- **constant**：指定常数平衡褶皱。
- **instability**：与同名 `XiGModel`::instability` 成对出现于高级设置；字典关键字易混淆，注意父类。

---

# XiGModel（generationRate）

| 类型 | 一句话 | 源码 |
|------|--------|------|
| `KTS` | 常用生成率模型 | `XiGModels/KTS/` |
| `instability` | 不稳定性生成 | `XiGModels/instability/` |

### KTS
- **适用**: 几乎所有 Xi 教程
- **字典**: `generationRate` { model KTS; }`
- **方程**: 褶皱生成项闭合（见类头）
- **注意**: 与 XiEq 的 Gulder 常组合

### instability
- **适用**: 需火焰不稳定性增强生成时
- **注意**: 类型名与 XiEq `instability` 相同，分属不同 RTS

---

# XiProfile

| 类型 | 一句话 |
|------|--------|
| `linear` | 线性剖面 |
| `cubic` | 三次剖面 |
| `uniform` | 均匀剖面 |

源码：`XiModels/XiProfiles/{linear,cubic,uniform}/`。  
教程：`moriyoshi`→`linear`；`engine2Valve2D`→`cubic`。

---

# SuModel（层流火焰速度输运/代数）

与 `laminarFlameSpeed` 库配合；`laminarFlameSpeed`.model` 可选 `unstrained` 等。

| 类型 | 一句话 | 源码 |
|------|--------|------|
| `unstrained` | 无应变 \(S_u\)（常用外壳） | `SuModels/unstrained/` |
| `uniformConstant` | 常值 \(S_u\) | `SuModels/uniformConstant/` |
| `linearEquilibrium` | 线性平衡 | `SuModels/linearEquilibrium/` |
| `transport` | \(S_u\) 输运（极贫/应变敏感） | `SuModels/transport/` |

XiFluid Description：对极贫丙烷等应变敏感火焰，存在 \(S_u\) 输运方程，输运速度与 \(\Xi\) 方程相同。

层流火焰速度关联见 [laminar-flame-speed.md](laminar-flame-speed.md)。

---

# 点火 fvModels（bXi）

## constantbXiIgnition

### 一句话
在指定时空窗内将 \(b\) Ignite 为燃烧。

### 适用条件
`XiFluid` + `constant/fvModels`

### 字典示例
见 `applications/modules/XiFluid/fvModels/ignition/constantbXiIgnition/` Usage 与引擎教程。

### 参数表
点火位置、开始/持续时刻、强度等（源码）。

### 控制方程与关联式
在点火区内修改 \(b\)（及关联场）。

### 文献与源码依据
`fvModels/ignition/constantbXiIgnition/`

### 教程与模板
`XiFluid/engine2Valve2D`、`kivaTest`（核对 fvModels）

### 注意事项
未点火则 \(b\) 保持未燃，燃烧不传播。

## multiCycleConstantbXiIgnition

### 一句话
多循环重复的常值点火（发动机）。

### 适用条件
多循环发动机 Xi 案例。

### 字典 / 参数 / 方程
见 `multiCycleConstantbXiIgnition`/`。

### 依据 / 教程 / 注意
同目录；注意循环相位与 `SOI`。

## bXiIgnited

### 一句话
已点火状态辅助/标记类 fvModel。

### 适用条件
与点火工作流配合。

### 依据
`fvModels/ignition/bXiIgnited/`

---

# XiCorrModel（点火修正）

| 类型 | 一句话 | 源码 |
|------|--------|------|
| `spherical` | 球形核修正 | `XiCorrModels/spherical/` |
| `cylindrical` | 柱形 | `cylindrical`/` |
| `planar` | 平面 | `planar`/` |

用于点火早期火焰核几何修正（见各类 Description）。

---

## 覆盖计数

| 族 | Inventory RTS | 本页 |
|----|---------------|------|
| XiModel | transport, equilibrium, uniformConstant | ✓ |
| XiEqModel | Gulder, constant, instability | ✓ |
| XiGModel | KTS, instability | ✓ |
| XiProfile | linear, cubic, uniform | ✓ |
| SuModel | unstrained, uniformConstant, linearEquilibrium, transport | ✓ |
| 点火 fvModel | constantbXiIgnition, multiCycleConstantbXiIgnition, bXiIgnited | ✓ |
| XiCorrModel | spherical, cylindrical, planar | ✓ |

**缺口**: 各点火/XiCorr 完整可复制字典以源码 Usage 与引擎教程为准，部分参数未在教程中逐项出现。
