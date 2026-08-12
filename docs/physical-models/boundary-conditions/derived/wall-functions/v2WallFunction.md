# v2WallFunction

## 一句话
高 Re 壁面函数，用近壁解析关联闭合湍流量。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`v2WallFunction`
- **典型场**：nut / nuTilda, k / epsilon / omega / f / v2
- **库 / 加载**：需动量输运库（如 `libmomentumTransportModels` / 相专用库）；通常由启用湍流的求解器链接
- **前提**：启用 RAS/LES 壁面函数湍流模型；近壁网格满足 y+ 假设。

## 字典示例
```
<patchName>
{
    type            v2WallFunction;
}
```

## 参数表
源码头文件未提供标准 `Usage` 表，或参数由基类继承——请对照源码构造函数读取字典关键字。

## 控制方程与关联式
高 Re 壁面函数，用近壁解析关联闭合湍流量。

类头 `Description` 原文：

> This boundary condition provides a turbulence stress normal to streamlines
> wall function condition for low- and high-Reynolds number, turbulent flow
> cases.
> 
> The model operates in two modes, based on the computed laminar-to-turbulent
> switch-over y+ value derived from kappa and E specified in the corresponding
> nutWallFunction.

## 文献与源码依据
- 源码：[`src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/wallFunctions/v2WallFunctions/v2WallFunction/v2WallFunctionFvPatchScalarField.C`](../../../src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/wallFunctions/v2WallFunctions/v2WallFunction/v2WallFunctionFvPatchScalarField.C)
- 头文件：[`src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/wallFunctions/v2WallFunctions/v2WallFunction/v2WallFunctionFvPatchScalarField.H`](../../../src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/wallFunctions/v2WallFunctions/v2WallFunction/v2WallFunctionFvPatchScalarField.H)
- Inventory 备注：momentum transport / wall functions

## 教程与模板
- [`tutorials/incompressibleFluid/pitzDailySteady/0/v2`](../../../tutorials/incompressibleFluid/pitzDailySteady/0/v2)

## 注意事项
- 壁面函数场（`nut`/`k`/`epsilon`/`omega`/`alphat`）需成套配置，勿与低 Re 积分壁面混用。
