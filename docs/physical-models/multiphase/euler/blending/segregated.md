# segregated

## 一句话
Blending method for segregated configurations. E.g., a churning flow in

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: BlendedInterfacialModel 混合方法（基类 `blendingMethod`）
- **注册名**: `segregated`

## 字典示例


```c++
// `tutorials/multiRegion/CHT/multiphaseCoolingCylinder2D/constant/fluid/phaseProperties`
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

- 注册名 / `type`: `segregated`
- 基类: `blendingMethod`


## 控制方程与关联式
Blending method for segregated configurations. E.g., a churning flow in
which it is never appropriate to consider one phase continuous.

## 文献与源码依据
- 类: `Foam`::blendingMethods::segregated`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/BlendedInterfacialModel/blendingMethods/segregatedBlendingMethod/segregatedBlendingMethod.C`

## 教程与模板
- `tutorials/multiRegion/CHT/multiphaseCoolingCylinder2D/constant/fluid/phaseProperties`
- `tutorials/multiphaseEuler/mixerVessel2DMRF/constant/phaseProperties`
- `tutorials/multiphaseEuler/mixerVessel2D/constant/phaseProperties`
- `tutorials/multiphaseEuler/injection/constant/phaseProperties`
- `tutorials/multiphaseEuler/damBreak4phase/constant/phaseProperties`

## 注意事项
- 类型名必须与 RTS 注册名一致：`segregated`。
