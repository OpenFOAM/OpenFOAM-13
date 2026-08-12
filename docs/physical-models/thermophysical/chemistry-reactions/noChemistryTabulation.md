# `none`

## 一句话

关闭化学表化（type none）

## 适用条件（求解器 / 场 / 前提）

- 类别：`chemistryTabulationMethod`
- 适用: `multicomponentFluid` / `XiFluid` / 相变饱和模型相关求解器（见矩阵）

## 字典示例

```c++
// chemistryProperties / combustionProperties / saturation 子字典
type none;
```

## 参数表

见源码头文件。

## 控制方程与关联式

A chemistryTabulationMethod which does nothing to allow tabulation to be
switched-off.

## 文献与源码依据

- [`src/thermophysicalModels/chemistryModel/chemistryModel/tabulation/noChemistryTabulation/noChemistryTabulation.H`](../../../src/thermophysicalModels/chemistryModel/chemistryModel/tabulation/noChemistryTabulation/noChemistryTabulation.H)

## 教程与模板

- `tutorials/multicomponentFluid/**`、`tutorials/XiFluid/**`、相变教程

## 注意事项

- Phase 4 将补充燃烧机理与反应速率全谱；此处给出物性/化学支撑模型。
