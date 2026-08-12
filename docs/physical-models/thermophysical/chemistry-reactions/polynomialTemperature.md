# `polynomialTemperature`

## 一句话

多项式饱和温度

## 适用条件（求解器 / 场 / 前提）

- 类别：`saturationModels`
- 适用: `multicomponentFluid` / `XiFluid` / 相变饱和模型相关求解器（见矩阵）

## 字典示例



> （由源码构造函数推断，无官方教程实例）

```c++
// saturationPressureModel / saturationTemperatureModel
type polynomialTemperature;
// 无额外入口或见父类
```

## 参数表

见源码头文件。

## 控制方程与关联式

Polynomial equation for the saturation vapour temperature in terms of
the vapour pressure (in Pa).

$$
T_sat = \sum_i C_i p^i
$$

where $p$ is the pressure in Pa and $C$ are the coefficients.

## 文献与源码依据

- [`src/thermophysicalModels/saturationModels/polynomialTemperature/polynomialTemperature.H`](../../../src/thermophysicalModels/saturationModels/polynomialTemperature/polynomialTemperature.H)

## 教程与模板

- `tutorials/multicomponentFluid/**`、`tutorials/XiFluid/**`、相变教程

## 注意事项

- Phase 4 将补充燃烧机理与反应速率全谱；此处给出物性/化学支撑模型。
