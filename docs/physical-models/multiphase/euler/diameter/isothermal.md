# isothermal

## 一句话
Isothermal dispersed-phase particle diameter model.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 相直径模型（基类 `diameterModel`）
- **注册名**: `isothermal`

## 字典示例

```c++
// `tutorials/multiphaseEuler/steamInjection/constant/phaseProperties`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

phases          (steam water);

steam
{
    type            purePhaseModel;

    diameterModel   isothermal;
    isothermalCoeffs
    {
        d0              3e-3;
        p0              1e5;
    }

    residualAlpha   1e-3;
}

water
{
    type            purePhaseModel;

    diameterModel   none;

    residualAlpha   1e-3;
}

blending
{
    default
    {
        type            continuous;
        phase           water;
    }
}

surfaceTension
{}

// ************************************************************************* //
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `isothermal`
- 基类: `diameterModel`


## 控制方程与关联式
Isothermal dispersed-phase particle diameter model.

## 文献与源码依据
- 类: `Foam`::diameterModels::isothermal`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/diameterModels/isothermalDiameter/isothermalDiameter.C`

## 教程与模板
- `tutorials/multiRegion/CHT/multiphaseCoolingCylinder2D/constant/fluid/phaseProperties`
- `tutorials/multiphaseEuler/steamInjection/constant/phaseProperties`
- `tutorials/multiphaseEuler/mixerVessel2D/constant/phaseProperties`
- `tutorials/multiphaseEuler/injection/constant/phaseProperties`
- `tutorials/multiphaseEuler/bubbleColumnLES/constant/phaseProperties`

## 注意事项
- 类型名必须与 RTS 注册名一致：`isothermal`。
