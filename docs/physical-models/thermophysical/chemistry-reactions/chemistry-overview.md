# `chemistryModel`（概览：求解 / 降维 / 表化 / 反应）

## 一句话

有限速率化学的配置入口：`chemistryProperties` 中选择 ODE/隐式求解器，可选机理降维与 ISAT 表化，反应式来自 `reactions` 字典。

## 适用条件（求解器 / 场 / 前提）

- **适用**: `multicomponentFluid`（链接 `chemistryModel`）；燃烧教程常配合 `combustionProperties`
- **部分适用**: `multiphaseEuler` 反应库（`-lmultiphaseEulerReactions`）— 反应形式见 Phase 4
- **不适用**: 纯 `incompressibleFluid` / 无组分能量方程的求解器
- 字典：`constant/chemistryProperties`；机理常 `#include "reactions"` / `reactionsGRI`
- 完整燃烧模型（PaSR、EDC、`Xi`…）见 Phase 4 [`combustion`-radiation/`](../../combustion-radiation/)

## 字典示例

改编自 [`tutorials/multicomponentFluid/counterFlowFlame2D_GRI_TDAC/constant/chemistryProperties`](../../../tutorials/multicomponentFluid/counterFlowFlame2D_GRI_TDAC/constant/chemistryProperties) 与 [`etc/caseDicts/solvers/chemistry/TDAC/chemistryProperties.cfg`](../../../etc/caseDicts/solvers/chemistry/TDAC/chemistryProperties.cfg)：

```c++
#includeEtc "caseDicts/solvers/chemistry/TDAC/chemistryProperties.cfg"

chemistryType
{
    solver          ode;          // 或 EulerImplicit / none
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
    log         on;
    tolerance   1e-4;
    method      DAC;          // DRG | DAC | DRGEP | PFA | EFA | none
    initialSet
    (
        CO
        CH4
        HO2
    );
}

tabulation
{
    log         on;
    tolerance   3e-3;
    method      ISAT;         // 或 none
    // scaleFactor / maxNLeafs / ... 见 TDAC cfg
}

#include "reactionsGRI"
```

无 TDAC 时只需 `chemistryType` + `odeCoeffs` + 反应 include（如 `counterFlowFlame2D`）。

## 参数表

| 关键字 | 含义 |
|--------|------|
| `chemistryType`.solver` | 化学积分器：`ode`、`EulerImplicit`、`none` |
| `chemistry` | 开关有限速率化学 |
| `initialChemicalTimeStep` | 化学子步初始 Δt |
| `odeCoeffs` | ODE 求解器名与容差（如 `seulex`） |
| `reduction`.method` | 机理降维方法 |
| `reduction`.tolerance` / `initialSet` | 降维容差与搜索起始物种集 |
| `tabulation`.method` | `ISAT` 或 `none` |
| `tabulation`.tolerance` / `scaleFactor` / `maxNLeafs` | ISAT 表化参数 |

## 控制方程与关联式

组分源项 $\dot{\omega}_i$ 由反应机理（Arrhenius 等，见 `reaction` / Phase 4）与化学求解器积分得到。

| 层 | 注册类型 | 作用 |
|----|----------|------|
| **Solver** | `ode`, `EulerImplicit`, `none` | 对刚性 ODE 积分或关闭 |
| **Reduction** | `none`, `DRG`, `DAC`, `DRGEP`, `PFA`, `EFA` | 动态删减活性物种/反应（TDAC） |
| **Tabulation** | `ISAT`, `none` | 现场自适应表化加速查询（Pope 1997，见 [ISAT](ISAT.md)） |

降维与表化可组合（TDAC = Tabulation of Dynamic Adaptive Chemistry）。工厂对气体/液体系数型 thermo 用 `forCoeffGases` / `forCoeffLiquids` 注册。

## 文献与源码依据

- 化学模型根：`src/thermophysicalModels/chemistryModel/`
- 求解器：`chemistrySolver/ode`、`EulerImplicit`、`noChemistrySolver`
- 降维：`chemistryModel/reduction/{DRG,DAC,DRGEP,PFA,EFA,noChemistryReduction}`
- 表化：[`ISAT`](ISAT.md)、[`noChemistryTabulation`](noChemistryTabulation.md)
- 模板：`etc/caseDicts/solvers/chemistry/TDAC/chemistryProperties.cfg`
- 清单：[`../../_inventory/rts-thermos.md`](../../_inventory/rts-thermos.md)（表化/火焰速度/饱和等）

## 教程与模板

- `tutorials/multicomponentFluid/counterFlowFlame2D_GRI_TDAC/constant/chemistryProperties`
- `tutorials/multicomponentFluid/counterFlowFlame2DLTS_GRI_TDAC/constant/chemistryProperties`
- `tutorials/multicomponentFluid/counterFlowFlame2D_GRI/constant/chemistryProperties`（无降维表化）
- `tutorials/multicomponentFluid/aachenBomb/constant/chemistryProperties`
- `tutorials/multicomponentFluid/nc7h16/constant/chemistryProperties`

## 注意事项

1. `chemistryType`.solver` 与 `tabulation`.method` / `reduction`.method` 是不同层，勿混写到同一字段。
2. 未链接 `chemistryModel` 库的求解器无法构造化学对象。
3. ISAT/`reduction` 参数敏感；先用小机理或关闭表化验证再开 TDAC。
4. 反应速率**形式**（Arrhenius、fall-off…）与燃烧模型全谱属 Phase 4；本页只给化学支撑树。

## 本目录相关页

- 求解器短页：[ode](chemistrySolver-ode.md) · [EulerImplicit](chemistrySolver-EulerImplicit.md) · [none](chemistrySolver-none.md)
- 降维短页：[DRG](reduction-DRG.md) · [DAC](reduction-DAC.md) · [DRGEP](reduction-DRGEP.md) · [PFA](reduction-PFA.md) · [EFA](reduction-EFA.md) · [none](reduction-none.md)
- 表化：[ISAT](ISAT.md) · [none](noChemistryTabulation.md)
- 反应概览：[reaction](reaction.md)
