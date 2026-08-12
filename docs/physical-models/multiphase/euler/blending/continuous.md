# continuous

## 一句话
Blending method for the case in which the continuous phase is always the

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: BlendedInterfacialModel 混合方法（基类 `blendingMethod`）
- **注册名**: `continuous`

## 字典示例


```c++
// `tutorials/multiRegion/CHT/wallBoiling/constant/fluid/phaseProperties`
residualAlpha   1e-6;
}

blending
{
    default
    {
        type            continuous;
        phase           liquid;
    }
}

surfaceTension
{
    gas_liquid
    {
        type            constant;
        sigma           0.00176574;
    }
}

// ************************************************************************* //
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `continuous`
- 基类: `blendingMethod`


## 控制方程与关联式
Blending method for the case in which the continuous phase is always the
same. E.g., for an air-particles flow, the air phase is always continuous.

This method requires the continuous phase to be specified.

## 文献与源码依据
- 类: `Foam`::blendingMethods::continuous`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/BlendedInterfacialModel/blendingMethods/continuous/continuous.C`

## 教程与模板
- `tutorials/multiRegion/CHT/wallBoiling/constant/fluid/phaseProperties`
- `tutorials/multiphaseEuler/wallBoilingPolydisperseTwoGroups/constant/phaseProperties`
- `tutorials/multiphaseEuler/wallBoilingPolydisperse/constant/phaseProperties`
- `tutorials/multiphaseEuler/wallBoilingIATE/constant/phaseProperties`
- `tutorials/multiphaseEuler/titaniaSynthesisSurface/constant/phaseProperties`

## 注意事项
- 类型名必须与 RTS 注册名一致：`continuous`。
