# `ISAT`

## 一句话

ISAT（In-situ Adaptive Tabulation）化学表化，加速重复成分空间上的反应映射查询。

## 适用条件（求解器 / 场 / 前提）

- 类别：`chemistryTabulationMethod`，字典 `tabulation`.method ISAT;`
- **适用**: `multicomponentFluid`（常与 `reduction` 联用 → TDAC）
- 需 `chemistry` on` 且化学求解器有效（通常 `ode`）

## 字典示例

```c++
// constant/chemistryProperties（节选）
tabulation
{
    log         on;
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
    // 其余见 etc/caseDicts/solvers/chemistry/TDAC/chemistryProperties.cfg
}
```

## 参数表

| 关键字 | 含义 |
|--------|------|
| `tolerance` | retrieve/grow 容差 |
| `scaleFactor` | 成分空间各维尺度 |
| `maxNLeafs` | 二叉树最大叶数 |
| `chPMaxLifeTime` / `maxGrowth` / `growPoints` | 叶寿命、生长限制（见 TDAC cfg） |

## 控制方程与关联式

Implementation of the ISAT (In-situ adaptive tabulation), for chemistry calculation.

Reference（源码头文件）：

```
Pope, S. B. (1997).
Computationally efficient implementation of combustion chemistry using
in situ adaptive tabulation.
Combustion Theory and Modelling, 1, 41-63.
```

## 文献与源码依据

- [`src/thermophysicalModels/chemistryModel/chemistryModel/tabulation/ISAT/ISAT.H`](../../../src/thermophysicalModels/chemistryModel/chemistryModel/tabulation/ISAT/ISAT.H)
- 模板：[`etc/caseDicts/solvers/chemistry/TDAC/chemistryProperties.cfg`](../../../etc/caseDicts/solvers/chemistry/TDAC/chemistryProperties.cfg)

## 教程与模板

- `tutorials/multicomponentFluid/counterFlowFlame2D_GRI_TDAC/constant/chemistryProperties`
- `tutorials/multicomponentFluid/counterFlowFlame2DLTS_GRI_TDAC/constant/chemistryProperties`
- `tutorials/multicomponentFluid/DLR_A_LTS/constant/chemistryProperties`

## 注意事项

- 字典写在 `tabulation` { method ISAT; }`，不是顶层 `type` ISAT;`。
- 关闭表化用 `method` none`（见 [noChemistryTabulation](noChemistryTabulation.md)）。
- 燃烧模型本身见 Phase 4。
