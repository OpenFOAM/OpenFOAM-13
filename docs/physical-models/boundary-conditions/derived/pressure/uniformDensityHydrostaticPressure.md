# uniformDensityHydrostaticPressure

## 一句话
常密度静水压分布边界。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`uniformDensityHydrostaticPressure`
- **典型场**：p / p_rgh
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            uniformDensityHydrostaticPressure;
    rhoRef          1000;
    pRef            1e5;
    pRefPoint       (0 0 0);
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `rhoRef` | Uniform density [kg/m^3] | yes |  |
| `pRef` | Reference pressure [Pa] | yes |  |
| `pRefPoint` | Reference pressure location | no | hRef |
| `value` | Initial value | no | pRef |

## 控制方程与关联式
常密度静水压分布边界。

类头 `Description` 原文：

> This boundary condition provides a hydrostatic pressure condition,
> calculated as:
> 
>     $$
>         p_{hyd} = p_{ref} + \rho_{ref} g (x - x_{ref})
>     $$
> 
> where
> 
>     p_{hyd}    | Hydrostatic pressure [Pa]
>     p_{ref}    | Reference pressure [Pa]
>     x_{ref}    | Reference point in Cartesian co-ordinates
>     \rho_{ref} | Density (assumed uniform)
>     g          | Acceleration due to gravity [m/s^2]
> \endtable

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/uniformDensityHydrostaticPressure/uniformDensityHydrostaticPressureFvPatchScalarField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/uniformDensityHydrostaticPressure/uniformDensityHydrostaticPressureFvPatchScalarField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/uniformDensityHydrostaticPressure/uniformDensityHydrostaticPressureFvPatchScalarField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/uniformDensityHydrostaticPressure/uniformDensityHydrostaticPressureFvPatchScalarField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            uniformDensityHydrostaticPressure`。

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
