# nutkWallFunction

## 一句话
基于近壁 `k` 的高 Re `nut` 壁面函数。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`nutkWallFunction`
- **典型场**：nut / nuTilda, k / epsilon / omega / f / v2
- **库 / 加载**：需动量输运库（如 `libmomentumTransportModels` / 相专用库）；通常由启用湍流的求解器链接
- **前提**：启用 RAS/LES 壁面函数湍流模型；近壁网格满足 y+ 假设。

## 字典示例

```cpp
wall
{
    type            nutkWallFunction;
    value           uniform 0;     // [m^2/s]
}
```

## 参数表
源码头文件未提供标准 `Usage` 表，或参数由基类继承——请对照源码构造函数读取字典关键字。

## 控制方程与关联式
基于近壁 `k` 的高 Re `nut` 壁面函数。

类头 `Description` 原文：

> Turbulent viscosity wall-function boundary condition
> for high Reynolds number flows based on near-wall turbulence kinetic energy.

## 文献与源码依据
- 源码：[`src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/wallFunctions/nutWallFunctions/nutkWallFunction/nutkWallFunctionFvPatchScalarField.C`](../../../src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/wallFunctions/nutWallFunctions/nutkWallFunction/nutkWallFunctionFvPatchScalarField.C)
- 头文件：[`src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/wallFunctions/nutWallFunctions/nutkWallFunction/nutkWallFunctionFvPatchScalarField.H`](../../../src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/wallFunctions/nutWallFunctions/nutkWallFunction/nutkWallFunctionFvPatchScalarField.H)
- Inventory 备注：momentum transport / wall functions

## 教程与模板
- [`tutorials/XiFluid/kivaTest/-180/nut`](../../../tutorials/XiFluid/kivaTest/-180/nut)
- [`tutorials/XiFluid/engine2Valve2D/0/nut`](../../../tutorials/XiFluid/engine2Valve2D/0/nut)
- [`tutorials/shockFluid/diffuserIntake/0/nut`](../../../tutorials/shockFluid/diffuserIntake/0/nut)
- [`tutorials/multiRegion/film/hotBoxes/0/fluid/nut`](../../../tutorials/multiRegion/film/hotBoxes/0/fluid/nut)
- [`tutorials/multiRegion/CHT/wallBoiling/0/fluid/nut.gas`](../../../tutorials/multiRegion/CHT/wallBoiling/0/fluid/nut.gas)
- [`tutorials/multiRegion/CHT/wallBoiling/0/fluid/nut.liquid`](../../../tutorials/multiRegion/CHT/wallBoiling/0/fluid/nut.liquid)

## 注意事项
- 壁面函数场（`nut`/`k`/`epsilon`/`omega`/`alphat`）需成套配置，勿与低 Re 积分壁面混用。
