# saturated

## 一句话
Model which uses a saturation pressure model for a single species to

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 界面组分平衡（基类 `interfaceCompositionModel`）
- **注册名**: `saturated`

## 字典示例


```c++
// `tutorials/multiphaseEuler/bubbleColumnEvaporatingDissolving/constant/fvModels`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

phaseChange
{
    type            massDiffusionLimitedPhaseChange;
    libs            ("libmultiphaseEulerFvModels.so");

    phases          (gas liquid);

    energySemiImplicit yes;

    interfaceComposition
    {
        gas_liquid_inThe_gas
        {
            type            saturated;
            species         (water);
            Le              1.0;
            pSat            ArdenBuck;
        }

        gas_liquid_inThe_liquid
        {
            type            Henry;
            species         (air);
            k               (1.492e-2);
            Le              1.0;
        }
    }

    diffusiveMassTransfer
    {
        blending        heatAndDiffusiveMassTransfer;

        gas_dispersedIn_liquid_inThe_gas
        {
            type            spherical;
        }

        gas_dispersedIn_liquid_inThe_liquid
        {
            type            Frossling;
            Le              1.0;
        }

        liquid_dispersedIn_gas_inThe_gas
        {
            type            Frossling;
            Le              1.0;
        }

        liquid_dispersedIn_gas_inThe_liquid
        {
            type            spherical;
        }
    }
}

// ************************************************************************* //
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `saturated`
- 基类: `interfaceCompositionModel`


## 控制方程与关联式
Model which uses a saturation pressure model for a single species to
calculate the interface composition.

## 文献与源码依据
- 类: `Foam`::interfaceCompositionModels::saturated`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/interfaceCompositionModels/saturated/saturated.C`

## 教程与模板
- `tutorials/multiphaseEuler/bubbleColumnEvaporatingReacting/constant/fvModels`
- `tutorials/multiphaseEuler/bubbleColumnEvaporatingDissolving/constant/fvModels`
- `tutorials/multiphaseEuler/bubbleColumnEvaporating/constant/fvModels`

## 注意事项
- 类型名必须与 RTS 注册名一致：`saturated`。
