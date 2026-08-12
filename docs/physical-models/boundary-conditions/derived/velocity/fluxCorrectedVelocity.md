# fluxCorrectedVelocity

## 一句话
按通量方向在入口值与零梯度间切换。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`fluxCorrectedVelocity`
- **典型场**：`U`
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            fluxCorrectedVelocity;
    phi             phi;
    rho             rho;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `phi` | name of flux field | no | phi |
| `rho` | name of density field | no | rho |

## 控制方程与关联式
按通量方向在入口值与零梯度间切换。

类头 `Description` 原文：

> This boundary condition provides a velocity outlet boundary condition for
> patches where the pressure is specified.  The outflow velocity is obtained
> by "zeroGradient" and then corrected from the flux:
> 
>     $$
>         U_p = U_c - n (n \cdot U_c) + \frac{n \phi_p}{|S_f|}
>     $$
> 
> where
> 
> 
>     U_p | velocity at the patch [m/s]
>     U_c | velocity in cells adjacent to the patch [m/s]
>     n   | patch normal vectors
>     \phi_p | flux at the patch [m^3/s or kg/s]
>     S_f | patch face area vectors [m^2]
> 
> 
> where
> 
> \table
>     Property     | Description             | Required    | Default value
>     phi          | name of flux field      | no          | phi
>     rho          | name of density field   | no          | rho
> \endtable
> 
> Example of the boundary condition specification:
> 
> <patchName>
> {
>     type            fluxCorrectedVelocity;
>     phi             phi;
>     rho             rho;
> }
> 
> 
> Note:
>     If reverse flow is possible or expected use the
>     pressureInletOutletVelocity condition instead.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/fluxCorrectedVelocity/fluxCorrectedVelocityFvPatchVectorField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/fluxCorrectedVelocity/fluxCorrectedVelocityFvPatchVectorField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/fluxCorrectedVelocity/fluxCorrectedVelocityFvPatchVectorField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/fluxCorrectedVelocity/fluxCorrectedVelocityFvPatchVectorField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/multiphaseEuler/damBreak4phase/0/U`](../../../tutorials/multiphaseEuler/damBreak4phase/0/U)
- [`tutorials/fluid/angledDuctLTS/0/U`](../../../tutorials/fluid/angledDuctLTS/0/U)

## 注意事项
- If reverse flow is possible or expected use the     pressureInletOutletVelocity condition instead.
