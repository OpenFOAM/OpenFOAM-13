# nutUSpaldingWallFunction

## 一句话
高 Re 壁面函数，用近壁解析关联闭合湍流量。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`nutUSpaldingWallFunction`
- **典型场**：nut / nuTilda, k / epsilon / omega / f / v2
- **库 / 加载**：需动量输运库（如 `libmomentumTransportModels` / 相专用库）；通常由启用湍流的求解器链接
- **前提**：启用 RAS/LES 壁面函数湍流模型；近壁网格满足 y+ 假设。

## 字典示例

```cpp
wall
{
    type            nutUSpaldingWallFunction;
    value           uniform 0;     // [m^2/s]
}
```

文献（Spalding 1961）见下方「控制方程与关联式」，勿放入字典栅栏。

## 参数表
源码头文件未提供标准 `Usage` 表，或参数由基类继承——请对照源码构造函数读取字典关键字。

## 控制方程与关联式
高 Re 壁面函数，用近壁解析关联闭合湍流量。

类头 `Description` 原文：

> This boundary condition provides a turbulent kinematic viscosity condition
> when using wall functions for rough walls, based on velocity,  using
> Spalding's law to give a continuous nut profile to the wall (y+ = 0)
> 
> $$
>     y^+ = u^+ + \frac{1}{E} \left[exp(\kappa u^+) - 1 - \kappa u^+\,
>         - 0.5 (\kappa u^+)^2 - \frac{1}{6} (\kappa u^+)^3\right]
> $$
> 
> where
> 
>     y^+     | non-dimensional position
>     u^+     | non-dimensional velocity
>     \kappa  | Von Karman constant
> 
> 
> Reference:
> 
>     Spalding, D. B., (1961).
>     A Single Formula for the "Law of the Wall".
>     Journal of Applied Mechanics, 28(3), 455-458
> 

## 文献与源码依据
- 源码：[`src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/wallFunctions/nutWallFunctions/nutUSpaldingWallFunction/nutUSpaldingWallFunctionFvPatchScalarField.C`](../../../src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/wallFunctions/nutWallFunctions/nutUSpaldingWallFunction/nutUSpaldingWallFunctionFvPatchScalarField.C)
- 头文件：[`src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/wallFunctions/nutWallFunctions/nutUSpaldingWallFunction/nutUSpaldingWallFunctionFvPatchScalarField.H`](../../../src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/wallFunctions/nutWallFunctions/nutUSpaldingWallFunction/nutUSpaldingWallFunctionFvPatchScalarField.H)
- Inventory 备注：momentum transport / wall functions

## 教程与模板
- [`tutorials/multiphaseEuler/hydrofoil/0/nut.gas`](../../../tutorials/multiphaseEuler/hydrofoil/0/nut.gas)
- [`tutorials/multiphaseEuler/hydrofoil/0/nut.liquid`](../../../tutorials/multiphaseEuler/hydrofoil/0/nut.liquid)
- [`tutorials/incompressibleFluid/motorBike/motorBike/0/nut`](../../../tutorials/incompressibleFluid/motorBike/motorBike/0/nut)
- [`tutorials/incompressibleFluid/drivaerFastback/0/nut`](../../../tutorials/incompressibleFluid/drivaerFastback/0/nut)
- [`tutorials/incompressibleFluid/airFoil2D/0/nut`](../../../tutorials/incompressibleFluid/airFoil2D/0/nut)

## 注意事项
- 壁面函数场（`nut`/`k`/`epsilon`/`omega`/`alphat`）需成套配置，勿与低 Re 积分壁面混用。
