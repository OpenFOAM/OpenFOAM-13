# `generalisedNewtonian`-Newtonian`

## 一句话

generalisedNewtonian 粘度子模型：牛顿子模型

## 适用条件（求解器 / 场 / 前提）

- 父模型：`generalisedNewtonian`
- 子字典 `viscosityModel Newtonian;`

## 字典示例



```c++
// `tutorials/incompressibleFluid/pitzDailySteady/constant/momentumTransport`
{
    // Tested with kEpsilon, realizableKE, kOmega, kOmega2006, kOmegaSST, v2f,
    // ShihQuadraticKE, LienCubicKE.
    model           kEpsilon;

    turbulence      on;


    viscosityModel  Newtonian;
}


// ************************************************************************* //
```

## 参数表

系数通常可在模型子字典覆盖（`Cmu`、`Ck` 等）；默认值见源码 `read`()`。

## 控制方程与关联式

Newtonian viscosity model which returns the fluid Newtonian viscosity

## 文献与源码依据

- [`src/MomentumTransportModels/momentumTransportModels/laminar/generalisedNewtonian/generalisedNewtonianViscosityModels/Newtonian/NewtonianViscosityModel.H`](../../../src/MomentumTransportModels/momentumTransportModels/laminar/generalisedNewtonian/generalisedNewtonianViscosityModels/Newtonian/NewtonianViscosityModel.H)

## 教程与模板

- `tutorials/incompressibleFluid/pitzDailySteady/constant/momentumTransport`
- `tutorials/incompressibleFluid/pitzDailyScalarTransport/constant/momentumTransport`
- `tutorials/incompressibleFluid/offsetCylinder/constant/momentumTransport`
- `tutorials/incompressibleFluid/waveSubSurface/constant/physicalProperties`
- `tutorials/incompressibleFluid/moodyChart/constant/physicalProperties`
- `tutorials/incompressibleFluid/cylinder/constant/physicalProperties`


## 注意事项

- 模型必须在对应库中注册（不可压/可压/相）；见族 README 注册表。
