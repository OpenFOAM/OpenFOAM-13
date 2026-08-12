# none

## 一句话
Dummy packing dispersion model

## 适用条件（求解器 / 场 / 前提）
- 适用: incompressibleDriftFlux
- **族**: 堆积弥散（基类 `packingDispersionModel`）
- **注册名**: `none`

## 字典示例


```c++
// `tutorials/multiRegion/CHT/wallBoiling/constant/fluid/phaseProperties`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

phases          (gas liquid);

gas
{
    type            purePhaseModel;

    diameterModel   constant;
    constantCoeffs
    {
        d               0.00045;
    }

    residualAlpha   1e-6;
}

liquid
{
    type            purePhaseModel;

    diameterModel   none;

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

- 注册名 / `type`: `none`
- 基类: `packingDispersionModel`


## 控制方程与关联式
Dummy packing dispersion model

## 文献与源码依据
- 类: `Foam`::packingDispersionModels::none`
- 源码路径: `applications/modules/incompressibleDriftFlux/packingDispersionModels/none/none_packingDispersionModel.C`

## 教程与模板
- `tutorials/multiRegion/CHT/wallBoiling/constant/fluid/phaseProperties`
- `tutorials/multiphaseEuler/wallBoilingPolydisperseTwoGroups/constant/phaseProperties`
- `tutorials/multiphaseEuler/wallBoilingPolydisperse/constant/phaseProperties`
- `tutorials/multiphaseEuler/wallBoilingIATE/constant/phaseProperties`
- `tutorials/multiphaseEuler/titaniaSynthesisSurface/constant/phaseProperties`

## 注意事项
- 类型名必须与 RTS 注册名一致：`none`。
