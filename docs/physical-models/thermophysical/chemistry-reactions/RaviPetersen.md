# `RaviPetersen`

## 一句话

Ravi–Petersen 层流火焰速度

## 适用条件（求解器 / 场 / 前提）

- 类别：`laminarFlameSpeed`
- 适用: `multicomponentFluid` / `XiFluid` / 相变饱和模型相关求解器（见矩阵）

## 字典示例

```c++
// chemistryProperties / combustionProperties / saturation 子字典
type RaviPetersen;
```

## 参数表

见源码头文件。

## 控制方程与关联式

Laminar flame speed obtained from Ravi and Petersen's correlation.

The correlation for the laminar flame speed $Su$ is of the following
form:
$$
Su = \left( \sum \alpha_i \phi^i \right)
\left( \frac{T}{T_{ref}} \right)^{\left( \sum \beta_j \phi^j \right)}
$$

Where $\phi$ is the equivalence ratio, and $\alpha$ and $\beta$
are polynomial coefficients given for a number of pressure and equivalence
ratio points.

## 文献与源码依据

- [`src/thermophysicalModels/laminarFlameSpeed/RaviPetersen/RaviPetersen.H`](../../../src/thermophysicalModels/laminarFlameSpeed/RaviPetersen/RaviPetersen.H)

## 教程与模板

- `tutorials/multicomponentFluid/**`、`tutorials/XiFluid/**`、相变教程

## 注意事项

- Phase 4 将补充燃烧机理与反应速率全谱；此处给出物性/化学支撑模型。
