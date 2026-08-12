# prghCyclicPressure

## 一句话
周期/循环配对边界。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`prghCyclicPressure`
- **典型场**：p / p_rgh
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            prghCyclicPressure;
    patchType       cyclic;
    rhoInf          1;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `patchType` | underlying patch type (should be \c cyclic) | yes |  |
| `rhoInf` | far-field density | yes |  |

## 控制方程与关联式
周期/循环配对边界。

类头 `Description` 原文：

> This boundary condition provides a cyclic condition for p_rgh. It applies
> corrections to the value and gradient on both sides of the cyclic to
> account for the non-cylicity of the gravitational force.
> 
> This condition is only needed when the cyclic patches have a transformation
> and a normal component in the direction of gravity. If the cyclic patches
> are orthogonal to the direction gravity, then a normal cyclic boundary
> condition can be used instead.
> 
> Care must be taken when using this boundary condition that the simulation
> is actually cyclic. The following constraints apply:
> 
> - Both cyclic patches must be oriented in the same way with respect to
>   gravity. In practice this means that applicability is limited to cyclics
>   with translational transformations.
> 
> - The model cannot have any dependence on the absolute value of the
>   pressure field. The absolute value of the pressure, in reality, varies
>   between each repetition of the geometry; it is not actually formally
>   cyclic. Only the gradient of the pressure field can be truly cyclic. This
>   model is therefore only valid if the absolute value of the pressure is
>   arbitrary, and only the gradient has an effect on the solution. This is
>   the case for incompressible multiphase solutions or incompressible
>   Boussinesq-like models of density variation. It is not true if (for
>   example) a compressible thermodynamic model is being used.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/prghCyclicPressure/prghCyclicPressureFvPatchScalarField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/prghCyclicPressure/prghCyclicPressureFvPatchScalarField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/prghCyclicPressure/prghCyclicPressureFvPatchScalarField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/prghCyclicPressure/prghCyclicPressureFvPatchScalarField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/incompressibleVoF/trayedPipe/0/p_rgh`](../../../tutorials/incompressibleVoF/trayedPipe/0/p_rgh)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
