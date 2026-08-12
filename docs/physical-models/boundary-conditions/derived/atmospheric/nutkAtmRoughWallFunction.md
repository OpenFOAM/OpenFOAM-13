# nutkAtmRoughWallFunction

## 一句话
大气粗糙壁 `nut` 壁面函数（大气边界层）。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`nutkAtmRoughWallFunction`
- **典型场**：nut / nuTilda, k / epsilon / omega / f / v2
- **库 / 加载**：需 `libatmosphericModels`
- **适用标签**：见库说明；不确定时查求解器 `Make/options`。

## 字典示例
摘录 `tutorials/incompressibleFluid/turbineSiting/0/nut`：

```
terrain
{
    type            nutkAtmRoughWallFunction;
    z0              $z0;
    value           uniform 0.0;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `z0` | surface roughness length | yes |  |
| `value` | 初值 | 常见 |  |

## 控制方程与关联式
大气粗糙壁 `nut` 壁面函数（大气边界层）。

类头 `Description` 原文：

> This boundary condition provides a turbulent kinematic viscosity for
> atmospheric velocity profiles.  It is designed to be used in conjunction
> with the atmBoundaryLayerInletVelocity boundary condition.  The values
> are calculated using:
> 
>     $$
>         U = frac{U_f}{\kappa} ln(\frac{z + z_0}{z_0})
>     $$
> 
> where
> 
> 
>     U_f    | frictional velocity
>     \kappa | Von Karman's constant
>     z_0    | surface roughness length
>     z      | vertical co-ordinate
> 

## 文献与源码依据
- 源码：[`src/atmosphericModels/derivedFvPatchFields/nutkAtmRoughWallFunction/nutkAtmRoughWallFunctionFvPatchScalarField.C`](../../../src/atmosphericModels/derivedFvPatchFields/nutkAtmRoughWallFunction/nutkAtmRoughWallFunctionFvPatchScalarField.C)
- 头文件：[`src/atmosphericModels/derivedFvPatchFields/nutkAtmRoughWallFunction/nutkAtmRoughWallFunctionFvPatchScalarField.H`](../../../src/atmosphericModels/derivedFvPatchFields/nutkAtmRoughWallFunction/nutkAtmRoughWallFunctionFvPatchScalarField.H)
- Inventory 备注：atmospheric BCs

## 教程与模板
- [`tutorials/incompressibleFluid/turbineSiting/0/nut`](../../../tutorials/incompressibleFluid/turbineSiting/0/nut)
- [`tutorials/fluid/stackPlume/0/nut`](../../../tutorials/fluid/stackPlume/0/nut)

## 注意事项
- 壁面函数场（`nut`/`k`/`epsilon`/`omega`/`alphat`）需成套配置，勿与低 Re 积分壁面混用。
