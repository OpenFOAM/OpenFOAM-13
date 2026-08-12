# linear

## 一句话
Blending method based on piecewise linear functions. Supports the full

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: BlendedInterfacialModel 混合方法（基类 `blendingMethod`）
- **注册名**: `linear`

## 字典示例


```c++
// `tutorials/multiRegion/CHT/multiphaseCoolingCylinder2D/constant/fluid/phaseProperties`
residualAlpha   1e-6;
}

blending
{
    default
    {
        type            linear;
        minFullyContinuousAlpha.oil 0.7;
        minPartlyContinuousAlpha.oil 0.3;
        minFullyContinuousAlpha.water 0.7;
        minPartlyContinuousAlpha.water 0.3;
    }

    segregated
    {
        type            linear;
        minFullyContinuousAlpha.oil 0.7;
        minPartlyContinuousAlpha.oil 0.5;
        minFullyContinuousAlpha.water 0.7;
        minPartlyContinuousAlpha.water 0.5;
    }
}

surfaceTension
{
    oil_water
    {
        type            constant;
        sigma           0.07;
    }
}

// ************************************************************************* //
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `linear`
- 基类: `blendingMethod`


## 控制方程与关联式
Blending method based on piecewise linear functions. Supports the full
range of phase fraction space. E.g., from droplets in air, through a
segregated regime, to bubbly flow.

This method requires two volume fractions between which the phase is
considered to become continuous to be specified for both phases.

Alternatively, these volume fractions can be omitted or replaced with the
keyword "none" to represent a phase which cannot become continuous. E.g.,
a particulate phase.

## 文献与源码依据
- 类: `Foam`::blendingMethods::linear`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/BlendedInterfacialModel/blendingMethods/linear/linear.C`

## 教程与模板
- `tutorials/multiRegion/CHT/multiphaseCoolingCylinder2D/constant/fluid/phaseProperties`
- `tutorials/multiphaseEuler/mixerVessel2DMRF/constant/phaseProperties`
- `tutorials/multiphaseEuler/mixerVessel2D/constant/phaseProperties`
- `tutorials/multiphaseEuler/injection/constant/phaseProperties`
- `tutorials/multiphaseEuler/bubbleColumnLES/constant/phaseProperties`

## 注意事项
- 类型名必须与 RTS 注册名一致：`linear`。
