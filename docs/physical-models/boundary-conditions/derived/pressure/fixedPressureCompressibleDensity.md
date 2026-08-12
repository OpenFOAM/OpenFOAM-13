# fixedPressureCompressibleDensity

## 一句话
压力相关边界条件。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`fixedPressureCompressibleDensity`
- **典型场**：p / p_rgh, `rho`
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type        fixedPressureCompressibleDensity;
    p           p;
    value       uniform 1;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `p` | pressure field name | no | p |

## 控制方程与关联式
压力相关边界条件。

类头 `Description` 原文：

> This boundary condition calculates a (liquid) compressible density as a
> function of pressure and fluid properties:
> 
>     $$
>         \rho = \rho_{l,sat} + \psi_l*(p - p_{sat})
>     $$
> 
> where
> 
> 
>     \rho    | density [kg/m^3]
>     \rho_{l,sat} | saturation liquid density [kg/m^3]
>     \psi_l  | liquid compressibility
>     p       | pressure [Pa]
>     p_{sat} | saturation pressure [Pa]
> 
> 
> The variables \c rholSat, \c pSat and \c psil are retrieved from the
> \c thermodynamicProperties dictionary.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/fixedPressureCompressibleDensity/fixedPressureCompressibleDensityFvPatchScalarField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/fixedPressureCompressibleDensity/fixedPressureCompressibleDensityFvPatchScalarField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/fixedPressureCompressibleDensity/fixedPressureCompressibleDensityFvPatchScalarField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/fixedPressureCompressibleDensity/fixedPressureCompressibleDensityFvPatchScalarField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            fixedPressureCompressibleDensity`。

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
