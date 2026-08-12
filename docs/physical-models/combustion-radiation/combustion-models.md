# 燃烧模型（combustionProperties）

`constant/combustionProperties` 选择 `combustionModel`。适用于 **`multicomponentFluid`**（链接 `-lcombustionModels`）。**XiFluid** 使用独立的 b-Xi 字典树，见 [xi-submodels.md](xi-submodels.md)，不在此表选 EDC/PaSR。

证据：`applications/modules/multicomponentFluid/Make/options`；RTS：`src/combustionModels/*/`.C。

---

# laminar

## 一句话
有限速率层流化学：直接用化学源项，无湍流–化学相互作用缩放。

## 适用条件（求解器 / 场 / 前提）
- **适用**: `multicomponentFluid`（及加载 combustionModels 的多区域 gas）
- **前提**: `chemistryProperties` 中 `chemistry` on` 且配置反应机理；多组分 `Y_i`

## 字典示例

```cpp
// constant/combustionProperties
combustionModel  laminar;
```

（`tutorials/multicomponentFluid/counterFlowFlame2D`）

## 参数表
| 入口 | 含义 | 量纲 |
|------|------|------|
| `combustionModel` | 类型名 `laminar` | — |

可选子字典依实现而定；多数案例仅一行类型名。

## 控制方程与关联式
组分方程源项 \(\dot{\omega}_i\) 由 `chemistryModel` 按局部 \(T,p,Y\) 积分得到，燃烧模型不做额外混合时间缩放（对比 PaSR/EDC）。

## 文献与源码依据
- `src/combustionModels/laminar/laminar.H`

## 教程与模板
- `tutorials/multicomponentFluid/counterFlowFlame2D`
- `tutorials/multicomponentFluid/counterFlowFlame2D_GRI`（+ TDAC 变体）

## 注意事项
- 湍流火焰若不加 PaSR/EDC，反应区可能过薄、过快；网格与化学时间步需匹配。

---

# PaSR

## 一句话
部分搅拌反应器：用湍流与化学时间尺度组合得到有限速率因子。

## 适用条件（求解器 / 场 / 前提）
- **适用**: `multicomponentFluid`
- **前提**: 化学开启；动量输运提供湍流时间尺度（\(k/\varepsilon\) 等）

## 字典示例

```cpp
combustionModel  PaSR;

PaSRCoeffs
{
    Cmix    1.0;   // 混合时间尺度缩放（视网格分辨率）
}
```

## 参数表
| 入口 | 含义 | 量纲 |
|------|------|------|
| `Cmix` | 湍流混合时间尺度系数 | 无量纲 |

## 控制方程与关联式
在层流化学速率上乘以与 \(\tau_{\mathrm{mix}}/\tau_{\mathrm{chem}}\) 相关的反应度因子（见类 Description：finite rate based on turbulence and chemistry time scales）。

## 文献与源码依据
- `src/combustionModels/PaSR/PaSR.H`（继承 `laminar`）

## 教程与模板
教程中较少单独标名；机制与 `laminar` 相同路径，改类型名即可。

## 注意事项
- `Cmix` 对网格敏感；过小/过大分别导致过反应/欠反应。

---

# EDC

## 一句话
涡耗散概念：反应发生在细结构中，由能量串级给出细结构质量分数与停留时间。

## 适用条件（求解器 / 场 / 前提）
- **适用**: `multicomponentFluid`
- **前提**: 湍流场；化学机理

## 字典示例

```cpp
// tutorials/multicomponentFluid/SandiaD_LTS
combustionModel  EDC;

EDCCoeffs
{
    version v2005;   // v1981 | v1996 | v2005 | v2016；缺省 v2005
}
```

## 参数表
| 入口 | 含义 | 量纲 |
|------|------|------|
| `version` | 系数组：v1981 / v1996 / v2005 / v2016 | — |
| （各版本）`Cgamma`, `Ctau`, `exp1`, `exp2` | 细结构体积分数与时间尺度系数 | 见源码头 |

## 控制方程与关联式
细结构质量分数与停留时间由串级模型给出；反应在细结构内进行。v2005：`Cgamma`=2.1377`, `Ctau`=0.4083`，\(\kappa=\gamma_L^{\mathrm{exp1}}/(1-\gamma_L^{\mathrm{exp2}})\)（exp1=exp2=2）。文献见类头 Magnussen 1981/2005、Gran & Magnussen 1996 等。

## 文献与源码依据
- `src/combustionModels/EDC/EDC.H`

## 教程与模板
- `tutorials/multicomponentFluid/SandiaD_LTS`
- `tutorials/multicomponentFluid/DLR_A_LTS`

## 注意事项
- `version` 拼写必须带 `v` 前缀；与 LES/RANS 时间尺度定义一致方可对比文献。

---

# FSD

## 一句话
Flame Surface Density：用火焰面密度与消耗速度构造燃烧速率。

## 适用条件（求解器 / 场 / 前提）
- **适用**: `multicomponentFluid`
- **前提**: 配置 `reactionRateFlameArea` 子模型（如 `relaxation`）

## 字典示例

```cpp
combustionModel  FSD;

FSDCoeffs
{
    // reactionRateFlameArea 等子字典，见源码 Usage
}
```

## 参数表
| 入口 | 含义 | 量纲 |
|------|------|------|
| `reactionRateFlameArea` | 火焰面反应速率模型，如 `relaxation` | — |

## 控制方程与关联式
燃烧速率与火焰面密度 \(\Sigma\) 及层流/湍流火焰消耗速度相关；`relaxation` 为已注册的 `reactionRateFlameArea` 模型。

## 文献与源码依据
- `src/combustionModels/FSD/FSD.H`
- `src/combustionModels/FSD/reactionRateFlameAreaModels/relaxation/`

## 教程与模板
仓库教程中较少；以源码 Usage 为准。

## 注意事项
- 与 XiFluid 的火焰褶皱 \(\Xi\) 框架不同，勿混用字典关键字。

---

# diffusion

## 一句话
扩散燃烧单步型模型（与混合物分数/燃料消耗相关）。

## 适用条件（求解器 / 场 / 前提）
- **适用**: `multicomponentFluid`
- **前提**: 适合扩散主导、可用简化化学的配置

## 字典示例

```cpp
combustionModel  diffusion;
```

## 参数表
见 `src/combustionModels/diffusion/diffusion.H` Usage（燃料名、\(C\) 等系数，以源码为准）。

## 控制方程与关联式
基于扩散火焰假设的燃料消耗速率闭合（类头 Description）。

## 文献与源码依据
- `src/combustionModels/diffusion/diffusion.C`

## 教程与模板
需验证具体教程；可与 `infinitelyFastChemistry` 对照。

## 注意事项
- 与详细机理 `laminar`/`EDC` 路径不同，通常配合单步/简化混合物。

---

# infinitelyFastChemistry

## 一句话
无限快化学：混合控制的燃料消耗（Magnussen 型单步）。

## 适用条件（求解器 / 场 / 前提）
- **适用**: `multicomponentFluid`
- **前提**: 单步燃料–氧化剂体系字段齐全

## 字典示例

```cpp
combustionModel  infinitelyFastChemistry;

infinitelyFastChemistryCoeffs
{
    // C, semiImplicit 等，见源码
}
```

## 参数表
以 `src/combustionModels/infinitelyFastChemistry/infinitelyFastChemistry.H` 为准。

## 控制方程与关联式
反应速率由湍流混合时间尺度限制，化学本身视为瞬时完成。

## 文献与源码依据
- `src/combustionModels/infinitelyFastChemistry/`

## 教程与模板
常见于简化池火/扩散焰设置；与 `smallPoolFire`*` 对照时注意该案例多用辐射+EDC/laminar 组合。

## 注意事项
- 不能捕捉慢化学/熄火；富燃区需核对燃料场定义。

---

# zoneCombustion

## 一句话
将另一燃烧模型的源项限制在指定 cellZone。

## 适用条件（求解器 / 场 / 前提）
- **适用**: `multicomponentFluid`
- **前提**: 网格含命名 zone；内嵌 `combustionModel`

## 字典示例

```cpp
combustionModel  zoneCombustion;

zoneCombustionCoeffs
{
    // zone 名称 + 子燃烧模型，见源码 Usage
}
```

## 参数表
| 入口 | 含义 |
|------|------|
| zone 列表 | 允许反应的单元区 |
| 子 `combustionModel` | 区内实际模型 |

## 控制方程与关联式
区外源项为零；区内委托子模型。

## 文献与源码依据
- `src/combustionModels/zoneCombustion/zoneCombustion.H`

## 教程与模板
源码为主；教程覆盖弱。

## 注意事项
- zone 名必须与 `constant/polyMesh/cellZones` 一致。

---

# noCombustion

## 一句话
关闭燃烧源项（仍可有组分输运，无反应释放）。

## 适用条件（求解器 / 场 / 前提）
- **适用**: 需要保留 combustion 框架但不反应时

## 字典示例

```cpp
combustionModel  noCombustion;
```

## 参数表
无。

## 控制方程与关联式
\(\dot{\omega}_i=0\)（燃烧模型层）。

## 文献与源码依据
- `src/combustionModels/noCombustion/noCombustion.C`

## 教程与模板
调试/冷态混合。

## 注意事项
- 与 `chemistry` off` 效果相近但层级不同；两者同时关闭更清晰。

---

## 覆盖计数

| 项目 | 数量 |
|------|------|
| RTS `combustionModel`（本页） | **8**（含 `noCombustion`；`infinitelyFastChemistry` 已注册） |
| Inventory 中 combustion 目录镜像 | 另计，不重复成页 |
| FSD 子模型 `relaxation` | 见上；`consumptionSpeed` 为支撑类 |

**缺口**: 教程未全覆盖 `FSD` / `zoneCombustion` / `diffusion` 端到端案例；字典细参以源码 Usage 为准标「需验证」处见各节。
