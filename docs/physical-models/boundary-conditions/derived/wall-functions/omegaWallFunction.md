# omegaWallFunction

## 一句话
高 Re 壁面函数，用近壁解析关联闭合湍流量。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`omegaWallFunction`
- **典型场**：nut / nuTilda, k / epsilon / omega / f / v2
- **库 / 加载**：需动量输运库（如 `libmomentumTransportModels` / 相专用库）；通常由启用湍流的求解器链接
- **前提**：启用 RAS/LES 壁面函数湍流模型；近壁网格满足 y+ 假设。

## 字典示例


```c++
// `tutorials/incompressibleFluid/pitzDaily/0/omega`（同类壁面）
walls
{
    type            omegaWallFunction;
    value           $internalField;

    // 可选（源码 lookupOrDefault）:
    // beta1     0.075;
    // blended   false;   // true 时粘性/对数区混合
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `beta1` | Model coefficient | no | 0.075 |
| `blended` | Blending switch | no | false |

## 控制方程与关联式
高 Re 壁面函数，用近壁解析关联闭合湍流量。

类头 `Description` 原文：

> This boundary condition provides a wall constraint on turbulnce specific
> dissipation, omega for both low and high Reynolds number turbulence models.
> 
> The near-wall omega may be either blended between the viscous region and
> logarithmic region values or switched between these values based on the
> laminar-to-turbulent y+ value derived from kappa and E specified in the
> corresponding nutWallFunction.  Recent tests have shown that the standard
> switching method provides more accurate results for 10 < y+ < 30 when used
> with high Reynolds number wall-functions and both methods provide accurate
> results when used with continuous wall-functions.  Based on this the
> standard switching method is used by default.

## 文献与源码依据
- 源码：[`src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/wallFunctions/omegaWallFunctions/omegaWallFunction/omegaWallFunctionFvPatchScalarField.C`](../../../src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/wallFunctions/omegaWallFunctions/omegaWallFunction/omegaWallFunctionFvPatchScalarField.C)
- 头文件：[`src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/wallFunctions/omegaWallFunctions/omegaWallFunction/omegaWallFunctionFvPatchScalarField.H`](../../../src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/wallFunctions/omegaWallFunctions/omegaWallFunction/omegaWallFunctionFvPatchScalarField.H)
- Inventory 备注：momentum transport / wall functions

## 教程与模板
- [`tutorials/XiFluid/engine2Valve2D/0/omega`](../../../tutorials/XiFluid/engine2Valve2D/0/omega)
- [`tutorials/shockFluid/diffuserIntake/0/omega`](../../../tutorials/shockFluid/diffuserIntake/0/omega)
- [`tutorials/multiRegion/CHT/wallBoiling/0/fluid/omega.gas`](../../../tutorials/multiRegion/CHT/wallBoiling/0/fluid/omega.gas)
- [`tutorials/multiRegion/CHT/wallBoiling/0/fluid/omega.liquid`](../../../tutorials/multiRegion/CHT/wallBoiling/0/fluid/omega.liquid)
- [`tutorials/multiRegion/CHT/VoFcoolingCylinder2D/0/fluid/omega`](../../../tutorials/multiRegion/CHT/VoFcoolingCylinder2D/0/fluid/omega)
- [`tutorials/multiRegion/CHT/notchedRoller/0/fluid/omega`](../../../tutorials/multiRegion/CHT/notchedRoller/0/fluid/omega)

## 注意事项
- 壁面函数场（`nut`/`k`/`epsilon`/`omega`/`alphat`）需成套配置，勿与低 Re 积分壁面混用。
