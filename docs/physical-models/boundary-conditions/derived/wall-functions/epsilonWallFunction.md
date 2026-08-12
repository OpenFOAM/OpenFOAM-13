# epsilonWallFunction

## 一句话
高 Re 壁面函数，用近壁解析关联闭合湍流量。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`epsilonWallFunction`
- **典型场**：nut / nuTilda, k / epsilon / omega / f / v2
- **库 / 加载**：需动量输运库（如 `libmomentumTransportModels` / 相专用库）；通常由启用湍流的求解器链接
- **前提**：启用 RAS/LES 壁面函数湍流模型；近壁网格满足 y+ 假设。

## 字典示例

```c++
// `tutorials/multicomponentFluid/aachenBomb/0/epsilon`
internalField   uniform 90;

boundaryField
{
    #includeEtc "caseDicts/setConstraintTypes"

    walls
    {
        type            epsilonWallFunction;
        value           uniform 90;
    }
}


// ************************************************************************* //
```

## 参数表
源码头文件未提供标准 `Usage` 表，或参数由基类继承——请对照源码构造函数读取字典关键字。

## 控制方程与关联式
高 Re 壁面函数，用近壁解析关联闭合湍流量。

类头 `Description` 原文：

> This boundary condition provides a turbulence dissipation wall constraint
> for low- and high-Reynolds number turbulence models.
> 
> The condition can be applied to wall boundaries for which it
> - calculates \c epsilon and \c G
> - specifies the near-wall epsilon value
> 
> where
> 
> 
>     epsilon | turbulence dissipation field
>     G       | turbulence generation field
> 
> 
> The model switches between laminar and turbulent functions based on the
> laminar-to-turbulent y+ value derived from the kappa and E specified in the
> corresponding nutWallFunction.

## 文献与源码依据
- 源码：[`src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/wallFunctions/epsilonWallFunctions/epsilonWallFunction/epsilonWallFunctionFvPatchScalarField.C`](../../../src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/wallFunctions/epsilonWallFunctions/epsilonWallFunction/epsilonWallFunctionFvPatchScalarField.C)
- 头文件：[`src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/wallFunctions/epsilonWallFunctions/epsilonWallFunction/epsilonWallFunctionFvPatchScalarField.H`](../../../src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/wallFunctions/epsilonWallFunctions/epsilonWallFunction/epsilonWallFunctionFvPatchScalarField.H)
- Inventory 备注：momentum transport / wall functions

## 教程与模板
- [`tutorials/XiFluid/kivaTest/-180/epsilon`](../../../tutorials/XiFluid/kivaTest/-180/epsilon)
- [`tutorials/multiRegion/film/hotBoxes/0/fluid/epsilon`](../../../tutorials/multiRegion/film/hotBoxes/0/fluid/epsilon)
- [`tutorials/multiRegion/CHT/wallBoiling/0/fluid/epsilon.gas`](../../../tutorials/multiRegion/CHT/wallBoiling/0/fluid/epsilon.gas)
- [`tutorials/multiRegion/CHT/wallBoiling/0/fluid/epsilon.liquid`](../../../tutorials/multiRegion/CHT/wallBoiling/0/fluid/epsilon.liquid)
- [`tutorials/multiRegion/CHT/shellAndTubeHeatExchanger/0/shell/epsilon`](../../../tutorials/multiRegion/CHT/shellAndTubeHeatExchanger/0/shell/epsilon)
- [`tutorials/multiRegion/CHT/shellAndTubeHeatExchanger/0/tube/epsilon`](../../../tutorials/multiRegion/CHT/shellAndTubeHeatExchanger/0/tube/epsilon)

## 注意事项
- 壁面函数场（`nut`/`k`/`epsilon`/`omega`/`alphat`）需成套配置，勿与低 Re 积分壁面混用。
