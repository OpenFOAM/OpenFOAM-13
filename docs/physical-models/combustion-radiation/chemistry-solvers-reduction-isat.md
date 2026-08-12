# 化学求解、降维与 ISAT

配置文件：`constant/chemistryProperties`。与 `combustionProperties` 配合用于 **`multicomponentFluid`**。权威片段：`etc/caseDicts/solvers/chemistry/TDAC/chemistryProperties.cfg`。

---

# chemistryProperties 总览

## 一句话
控制是否解化学、用何种 ODE/隐式求解器、可选机理降维与 ISAT 表化。

## 适用条件（求解器 / 场 / 前提）
- **适用**: `multicomponentFluid`（`-lchemistryModel`）；多区域 gas（如 `reverseBurner`）
- **前提**: 反应列表（`reactions` / `#include "reactionsGRI"`）与多组分 thermo

## 字典示例

基础（`counterFlowFlame2D` 风格）：

```cpp
chemistryType
{
    solver          ode;
}

chemistry       on;
initialChemicalTimeStep 1e-7;

odeCoeffs
{
    solver          seulex;
    absTol          1e-8;
    relTol          1e-1;
}

#include "reactions"
```

TDAC（`counterFlowFlame2D_GRI_TDAC`）：

```cpp
#includeEtc "caseDicts/solvers/chemistry/TDAC/chemistryProperties.cfg"

chemistryType
{
    solver            ode;
}

chemistry       on;
initialChemicalTimeStep 1e-7;

odeCoeffs
{
    solver          seulex;
    absTol          1e-8;
    relTol          1e-1;
}

reduction
{
    tolerance   1e-4;
}

tabulation
{
    tolerance   3e-3;
}

#include "reactionsGRI"
```

## 参数表
| 入口 | 含义 | 量纲 |
|------|------|------|
| `chemistry` | `on`/`off` | — |
| `chemistryType`.solver` | `ode` / `EulerImplicit` / `none` | — |
| `initialChemicalTimeStep` | 化学子步初值 | [0 0 1 0 0 0 0] |
| `odeCoeffs`.solver` | ODE 库求解器名，如 `seulex` | — |
| `reduction` / `tabulation` | 降维与 ISAT 子字典 | 见下 |

## 控制方程与关联式
每个计算单元上积分 \(\mathrm{d}Y_i/\mathrm{d}t=\dot{\omega}_i/\rho\)（及能量耦合形式，依 thermo）。燃烧模型再决定如何把 \(\dot{\omega}\) 注入流场。

## 文献与源码依据
- `src/thermophysicalModels/chemistryModel/`
- `etc/caseDicts/solvers/chemistry/TDAC/`

## 教程与模板
| 案例 | 要点 |
|------|------|
| `counterFlowFlame2D` | ode + 简单机理 |
| `counterFlowFlame2D_GRI_TDAC` | GRI + DAC + ISAT |
| `nc7h16` / `aachenBomb` | 复杂燃料 + 喷雾 |

## 注意事项
- `chemistry` off` 时燃烧模型无化学源；与 `noCombustion` 勿混淆层级。

---

# ode（chemistrySolver）

## 一句话
用 ODE 积分器求解刚性化学 ODE。

## 适用条件（求解器 / 场 / 前提）
- **适用**: 详细机理；与 `odeCoeffs` 联用

## 字典示例
见上 `chemistryType` { solver ode; }`。

## 参数表
| 入口 | 含义 |
|------|------|
| `odeCoeffs`.solver` | 如 `seulex` |
| `absTol` / `relTol` | 绝对/相对容差 |

## 控制方程与关联式
标准化学 ODE 积分；时间步可小于流动步（`initialChemicalTimeStep`）。

## 文献与源码依据
- `src/thermophysicalModels/chemistryModel/chemistrySolver/ode/`

## 教程与模板
几乎所有详细化学教程。

## 注意事项
- 容差过松导致质量不守恒或假熄火；过严拖慢计算。

---

# EulerImplicit

## 一句话
Euler 隐式化学求解器（简化刚性处理）。

## 适用条件（求解器 / 场 / 前提）
- **适用**: 可用隐式化学的案例；与 `ode` 二选一

## 字典示例

```cpp
chemistryType
{
    solver          EulerImplicit;
}

EulerImplicitCoeffs
{
    // cTauChem 等，见源码
}
```

## 参数表
见 `EulerImplicit` 目录头文件。

## 控制方程与关联式
对化学源项做隐式 Euler 型更新。

## 文献与源码依据
- `src/thermophysicalModels/chemistryModel/chemistrySolver/EulerImplicit/`

## 教程与模板
教程少；源码为主。

## 注意事项
- 与 ODE `seulex` 精度/稳定性权衡不同。

---

# noChemistrySolver / none

## 一句话
无化学积分（占位）。

## 适用条件（求解器 / 场 / 前提）
冷态或多孔介质等不需要组分反应源时。

## 字典示例

```cpp
chemistryType
{
solver none;
}
// 或 chemistry off;
```

## 参数表
无。

## 控制方程与关联式
不积分化学。

## 文献与源码依据
- `noChemistrySolver`/`

## 教程与模板
—
## 注意事项
类型名以运行时报错提示为准（`none` vs 类名）。

---

# 降维方法（chemistryReductionMethod）

## 一句话
运行时缩小活性物种/反应集合，加速详细机理。

## 适用条件（求解器 / 场 / 前提）
- **适用**: TDAC 工作流；与 `tabulation` 常一起开
- **方法**: `DRG`, `DAC`, `DRGEP`, `PFA`, `EFA`；关闭为 `none` / `noChemistryReduction`

## 字典示例

摘自 `chemistryProperties`.cfg`：

```cpp
reduction
{
    log         on;
    tolerance   1e-4;
    method      DAC;   // DRG | DAC | DRGEP | PFA | EFA

    initialSet
    (
        CO
        CH4
        HO2
    );

    automaticSIS    off;
    fuelSpecies
    (
        (CH4 1)
    );
}
```

## 参数表
| 入口 | 含义 |
|------|------|
| `method` | 降维算法名 |
| `tolerance` | 算法相关阈值 |
| `initialSet` | 搜索起始物种 SIS |
| `automaticSIS` | DAC 可自动切换 SIS（HO2↔H2O 等） |
| `fuelSpecies` | `automaticSIS` 时需要燃料定义 |

## 控制方程与关联式
各方法基于物种耦合图/误差传播估计移除次要物种与反应（DRG/DRGEP/PFA/DAC/EFA）；具体阈值定义见各子目录 Description。

## 文献与源码依据
- `src/thermophysicalModels/chemistryModel/chemistryModel/reduction/{DAC,DRG,DRGEP,EFA,PFA,noChemistryReduction}/`
- `etc/caseDicts/solvers/chemistry/TDAC/chemistryProperties.cfg`

## 教程与模板
- `counterFlowFlame2D_GRI_TDAC`、`counterFlowFlame2DLTS_GRI_TDAC`

## 注意事项
- `initialSet` 物种名必须与机理一致；DAC 的 `automaticSIS`/`fuelSpecies` 配错会导致错误活性集。

---

# ISAT（chemistryTabulationMethod）

## 一句话
In Situ Adaptive Tabulation：用二叉树存储化学映射，检索/增长加速重复状态查询。

## 适用条件（求解器 / 场 / 前提）
- **适用**: 与降维联用的 TDAC；`tabulation`.method ISAT`
- **关闭**: `method` none` / `noChemistryTabulation`

## 字典示例

```cpp
tabulation
{
    log         on;
    printProportion    off;
    tolerance   3e-3;
    method      ISAT;

    scaleFactor
    {
        otherSpecies 1;
        Temperature  10000;
        Pressure     1e15;
        deltaT       1;
    }

    maxNLeafs  2000;
    chPMaxLifeTime 100;
    maxGrowth  10;
    checkEntireTreeInterval  5;
    maxDepthFactor   2;
    minBalanceThreshold 30;
    MRURetrieve false;
    maxMRUSize 0;
    growPoints  true;
    maxNumNewDim 10;
}
```

## 参数表
| 入口 | 含义 | 典型量纲 |
|------|------|----------|
| `tolerance` | 检索/增长 EOA 容差 | 无量纲（缩放空间） |
| `scaleFactor`.*` | 组成空间各维缩放 | 与场一致 |
| `maxNLeafs` | 叶节点上限 | — |
| `chPMaxLifeTime` | 叶最大存活步数（非定常刷新） | 时间步数 |
| `maxGrowth` | 单点最大增长次数 | — |
| `growPoints` | 是否允许生长 | bool |

## 控制方程与关联式
查询点落在已存化学映射的精度椭球（EOA）内则直接取表；否则积分并插入/增长。实现：`binaryTree` / `chemPointISAT`。

## 文献与源码依据
- `src/thermophysicalModels/chemistryModel/chemistryModel/tabulation/ISAT/`
- 配置注释见 `chemistryProperties`.cfg`

## 教程与模板
同 TDAC 教程；`chemistryPropertiesFlame`.cfg` 为火焰专用变体。

## 注意事项
- `Temperature`/`Pressure` 缩放与工况差几个量级时检索失败率升高；`maxNLeafs` 过小频繁重建。

---

# 相关 functionObjects

| 类型 | 作用 | 路径 |
|------|------|------|
| `adjustTimeStepToChemistry` | 按化学时间步限制 \(\Delta t\) | `chemistryModel/functionObjects/` |
| `reactionRates` / `specieReactionRates` | 输出反应速率诊断 | 同上 |
| `adjustTimeStepToCombustion` / `Qdot` | 燃烧侧时间步与放热 | `src/combustionModels/functionObjects/` |

## 覆盖计数

| RTS 族 | 本页覆盖 |
|--------|----------|
| chemistrySolver | ode, EulerImplicit, none |
| chemistryReductionMethod | DAC, DRG, DRGEP, PFA, EFA, none |
| chemistryTabulationMethod | ISAT, none |
| Inventory chemistry 目录条目 | 含 binaryTree 等实现细节 → **不单独成页**（缺口：实现类非用户 RTS） |
