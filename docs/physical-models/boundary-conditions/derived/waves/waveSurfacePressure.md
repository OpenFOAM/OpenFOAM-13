# waveSurfacePressure

## 一句话
自由面附近由波高/静水关系给出的压力条件。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`waveSurfacePressure`
- **典型场**：p / p_rgh
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）
- **适用标签**：见库说明；不确定时查求解器 `Make/options`。

## 字典示例
```
<patchName>
{
    type            waveSurfacePressure;
    phi             phi;
    rho             rho;
    zeta            zeta;
    value           uniform 0;  // Initial value
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `phi` | flux field name | no | phi |
| `rho` | density field name | no | rho |
| `zeta` | wave amplitude field name | no | zeta |

## 控制方程与关联式
自由面附近由波高/静水关系给出的压力条件。

类头 `Description` 原文：

> This is a pressure boundary condition, the value of which is calculated as
> the hydrostatic pressure based on a given displacement:
> 
>     $$
>         p_rgh = -\rho*g*\zeta
>     $$
> 
> 
>     \rho  | density [kg/m^3]
>     g     | acceleration due to gravity [m/s^2]
>     \zeta | wave amplitude [m]
> 
> 
> The wave amplitude is updated as part of the calculation, derived from the
> local volumetric flux.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/waveSurfacePressure/waveSurfacePressureFvPatchScalarField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/waveSurfacePressure/waveSurfacePressureFvPatchScalarField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/waveSurfacePressure/waveSurfacePressureFvPatchScalarField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/waveSurfacePressure/waveSurfacePressureFvPatchScalarField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/isothermalFluid/potentialFreeSurfaceOscillatingBox/0/p_rgh`](../../../tutorials/isothermalFluid/potentialFreeSurfaceOscillatingBox/0/p_rgh)
- [`tutorials/isothermalFluid/potentialFreeSurfaceMovingOscillatingBox/0.orig/p_rgh`](../../../tutorials/isothermalFluid/potentialFreeSurfaceMovingOscillatingBox/0.orig/p_rgh)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
