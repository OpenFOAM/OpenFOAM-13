# Henry

## 一句话
Henry's law for gas solubility in liquid. The concentration of a dissolved

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 界面组分平衡（基类 `interfaceCompositionModel`）
- **注册名**: `Henry`

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

- 注册名 / `type`: `Henry`
- 基类: `interfaceCompositionModel`


## 控制方程与关联式
Henry's law for gas solubility in liquid. The concentration of a dissolved
species in the liquid is proportional to its partial pressure in the gas. A
dimensionless solubility, $k$, is given for each species. This is the
ratio of the concentration of the species in the liquid to the
corresponding concentration in the gas; i.e., $k =
c_{i,liq}/c_{i,gas}$. Mixing in the gas is assumed to be ideal.

## 文献与源码依据
- 类: `Foam`::interfaceCompositionModels::Henry`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/interfaceCompositionModels/Henry/Henry.C`

## 教程与模板
- `tutorials/multiphaseEuler/bubbleColumnEvaporatingDissolving/constant/fvModels`

## 注意事项
- 类型名必须与 RTS 注册名一致：`Henry`。
