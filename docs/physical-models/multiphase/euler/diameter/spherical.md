# spherical

## 一句话
Uniform spherical shape.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler（velocityGroup）
- **族**: 粒径组形状（基类 `shapeModel`）
- **注册名**: `spherical`

## 字典示例


```c++
// `tutorials/XiFluid/kivaTest/constant/fvModels`
cellZone        ignition;

    start           -15;
    duration        20;
    strength        2;

    XiCorr
    {
        type            spherical;
        cellZone        all;
    }
}


// ************************************************************************* //
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `spherical`
- 基类: `shapeModel`


## 控制方程与关联式
Uniform spherical shape.

## 文献与源码依据
- 类: `Foam`::diameterModels::shapeModels::spherical`
- 源码路径: `applications/modules/multiphaseEuler/populationBalance/diameterModels/velocityGroup/sizeGroup/shapeModels/spherical/spherical.C`

## 教程与模板
- `tutorials/multiphaseEuler/wallBoilingPolydisperseTwoGroups/constant/phaseProperties`
- `tutorials/multiphaseEuler/wallBoilingPolydisperse/constant/phaseProperties`
- `tutorials/multiphaseEuler/pipeBend/constant/phaseProperties`
- `tutorials/multiphaseEuler/bubblePipe/constant/phaseProperties`
- `tutorials/XiFluid/kivaTest/constant/fvModels`

## 注意事项
- 类型名必须与 RTS 注册名一致：`spherical`。
