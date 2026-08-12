# residualDiameter

## 一句话
A diameter model which switches form constant diameter to constant residual

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 相直径模型（基类 `diameterModel`）
- **注册名**: `residualDiameter`

## 字典示例


```c++
// `tutorials/multiphaseEuler/boilingBed/constant/phaseProperties`
residualAlpha   1e-6;
}

liquid
{
    type            purePhaseModel;

    diameterModel   residualDiameter;
    residualDiameterCoeffs
    {
        d               0.003;
        dResidual       0.0001;
    }

    residualAlpha   1e-6;
}

solid
{
    type            pureStationaryPhaseModel;

    diameterModel   constant;
    constantCoeffs
    {
        d               0.01;
    }

    residualAlpha   1e-6;
}

blending
{
    default
    {
        type            linear;
        minFullyContinuousAlpha.gas 0.7;
        minPartlyContinuousAlpha.gas 0.5;
        minFullyContinuousAlpha.liquid 0.5;
        minPartlyContinuousAlpha.liquid 0.3;
        minFullyContinuousAlpha.solid none;
        minPartlyContinuousAlpha.solid none;
    }
}

surfaceTension
{
    liquid_gas
    {
        type            constant;
        sigma           0.0589;
    }
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `residualDiameter`
- 基类: `diameterModel`


## 控制方程与关联式
A diameter model which switches form constant diameter to constant residual
diameter when the volume fraction of the phase is below residualAlpha.

A typical use case for this is to set a small residual diameter to prevent
excessive phase velocities in regions where the phase volume fraction is
small.

## 文献与源码依据
- 类: `Foam`::diameterModels::residualDiameter`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/diameterModels/residualDiameter/residualDiameter.C`

## 教程与模板
- `tutorials/multiphaseEuler/boilingBed/constant/phaseProperties`

## 注意事项
- 类型名必须与 RTS 注册名一致：`residualDiameter`。
