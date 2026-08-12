# BinghamPlastic

## 一句话
Viscosity correction model for Bingham plastics.

## 适用条件（求解器 / 场 / 前提）
- 适用: incompressibleDriftFlux
- **族**: 混合物粘度（基类 `mixtureViscosityModel`）
- **注册名**: `BinghamPlastic`

## 字典示例


```c++
// `tutorials/incompressibleDriftFlux/dahl/constant/physicalProperties.sludge`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

viscosityModel  BinghamPlastic;

"(plastic|BinghamPlastic)Coeffs"
{
    coeff       0.00023143;
    exponent    179.26;

    BinghamCoeff    0.0005966;
    BinghamExponent 1050.8;
    BinghamOffset   0;

    muMax       10;
}

rho         1996;


// ************************************************************************* //
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `BinghamPlastic`
- 基类: `mixtureViscosityModel`


## 控制方程与关联式
Viscosity correction model for Bingham plastics.

The strain-rate used is defined as sqrt(2.0)*mag(symm(grad(U)))

## 文献与源码依据
- 类: `Foam`::mixtureViscosityModels::BinghamPlastic`
- 源码路径: `applications/modules/incompressibleDriftFlux/mixtureViscosityModels/BinghamPlastic/BinghamPlastic.C`

## 教程与模板
- `tutorials/incompressibleDriftFlux/tank3D/constant/physicalProperties.sludge`
- `tutorials/incompressibleDriftFlux/mixerVessel2DMRF/constant/physicalProperties.sludge`
- `tutorials/incompressibleDriftFlux/dahl/constant/physicalProperties.sludge`

## 注意事项
- 类型名必须与 RTS 注册名一致：`BinghamPlastic`。
