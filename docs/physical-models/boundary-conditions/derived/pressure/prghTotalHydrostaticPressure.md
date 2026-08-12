# prghTotalHydrostaticPressure

## 一句话
基于总静水压的 `p_rgh` 边界。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`prghTotalHydrostaticPressure`
- **典型场**：p / p_rgh
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            prghTotalHydrostaticPressure;
    value           uniform 0;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `U` | Velocity field name | no | U |
| `phi` | Flux field name | no | phi |
| `rho` | Density field name | no | rho |
| `ph_rgh` | ph_rgh field name | no | ph_rgh |
| `value` | Patch face values | yes |  |

## 控制方程与关联式
基于总静水压的 `p_rgh` 边界。

类头 `Description` 原文：

> This boundary condition provides static pressure condition for p_rgh,
> calculated as:
> 
>     $$
>         p_rgh = ph_rgh - 0.5 \rho |U|^2
>     $$
> 
> where
> 
>     p_rgh   | Pressure - rho g.(h - hRef) [Pa]
>     ph_rgh  | Hydrostatic pressure - rho g.(h - hRef) [Pa]
>     h       | Height in the opposite direction to gravity
>     hRef    | Reference height in the opposite direction to gravity
>     rho     | Density
>     g       | Acceleration due to gravity [m/s^2]
> \endtable

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/prghTotalHydrostaticPressure/prghTotalHydrostaticPressureFvPatchScalarField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/prghTotalHydrostaticPressure/prghTotalHydrostaticPressureFvPatchScalarField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/prghTotalHydrostaticPressure/prghTotalHydrostaticPressureFvPatchScalarField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/prghTotalHydrostaticPressure/prghTotalHydrostaticPressureFvPatchScalarField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/multiRegion/film/rivuletBox/0/box/p_rgh`](../../../tutorials/multiRegion/film/rivuletBox/0/box/p_rgh)
- [`tutorials/multicomponentFluid/smallPoolFire3D/0/p_rgh`](../../../tutorials/multicomponentFluid/smallPoolFire3D/0/p_rgh)
- [`tutorials/multicomponentFluid/smallPoolFire2D/0/p_rgh`](../../../tutorials/multicomponentFluid/smallPoolFire2D/0/p_rgh)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
