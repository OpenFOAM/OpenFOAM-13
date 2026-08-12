# nutURoughWallFunction

## 一句话
高 Re 壁面函数，用近壁解析关联闭合湍流量。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`nutURoughWallFunction`
- **典型场**：nut / nuTilda, k / epsilon / omega / f / v2
- **库 / 加载**：需动量输运库（如 `libmomentumTransportModels` / 相专用库）；通常由启用湍流的求解器链接
- **前提**：启用 RAS/LES 壁面函数湍流模型；近壁网格满足 y+ 假设。

## 字典示例

```cpp
wall
{
    type            nutURoughWallFunction;
    Ks              uniform 1e-5;  // [m]
    Cs              uniform 0.5;   // [-]
    value           uniform 0;     // [m^2/s]
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `Ks` | sand-grain roughness height | yes |  |
| `Cs` | roughness constant | yes |  |

## 控制方程与关联式
高 Re 壁面函数，用近壁解析关联闭合湍流量。

类头 `Description` 原文：

> This boundary condition provides a turbulent kinematic viscosity condition
> when using wall functions for rough walls, based on velocity.  The
> condition manipulates the E parameter to account for roughness effects.
> 
> Reference:
> 
>     Cebeci, T., & Bradshaw, P. (1977).
>     Momentum transfer in boundary layers.
>     Washington, DC, Hemisphere Publishing Corp.; New York,
>     McGraw-Hill Book Co., 1977. 407 p.
> 

## 文献与源码依据
- 源码：[`src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/wallFunctions/nutWallFunctions/nutURoughWallFunction/nutURoughWallFunctionFvPatchScalarField.C`](../../../src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/wallFunctions/nutWallFunctions/nutURoughWallFunction/nutURoughWallFunctionFvPatchScalarField.C)
- 头文件：[`src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/wallFunctions/nutWallFunctions/nutURoughWallFunction/nutURoughWallFunctionFvPatchScalarField.H`](../../../src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/wallFunctions/nutWallFunctions/nutURoughWallFunction/nutURoughWallFunctionFvPatchScalarField.H)
- Inventory 备注：momentum transport / wall functions

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            nutURoughWallFunction`。

## 注意事项
- 壁面函数场（`nut`/`k`/`epsilon`/`omega`/`alphat`）需成套配置，勿与低 Re 积分壁面混用。
