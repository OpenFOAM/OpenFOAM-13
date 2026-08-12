# fixedNormalInletOutletVelocity

## 一句话
按通量方向在入口值与零梯度间切换。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`fixedNormalInletOutletVelocity`
- **典型场**：`U`
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            fixedNormalInletOutletVelocity;

    fixTangentialInflow false;
    normalVelocity
    {
        type            uniformFixedValue;
        uniformValue    sine;
        uniformValueCoeffs
        {
            frequency 1;
            amplitude table
            (
                (0  0)
                (2  0.088)
                (8  0.088)
            );
            scale     (0 1 0);
            level     (0 0 0);
        }
    }

    value           uniform (0 0 0);
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `phi` | flux field name | no | phi |
| `fixTangentialInflow` | If true fix the tangential component for inflow | yes |  |
| `normalVelocity` | patchField providing the normal velocity field | yes |  |

## 控制方程与关联式
按通量方向在入口值与零梯度间切换。

类头 `Description` 原文：

> This velocity inlet/outlet boundary condition combines a fixed normal
> component obtained from the "normalVelocity" patchField supplied with a
> fixed or zero-gradiented tangential component depending on the direction
> of the flow and the setting of "fixTangentialInflow":
> - Outflow: apply zero-gradient condition to tangential components
> - Inflow:
>   - fixTangentialInflow is true
>     apply value provided by the normalVelocity patchField to the
>     tangential components
>   - fixTangentialInflow is false
>     apply zero-gradient condition to tangential components.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/fixedNormalInletOutletVelocity/fixedNormalInletOutletVelocityFvPatchVectorField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/fixedNormalInletOutletVelocity/fixedNormalInletOutletVelocityFvPatchVectorField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/fixedNormalInletOutletVelocity/fixedNormalInletOutletVelocityFvPatchVectorField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/fixedNormalInletOutletVelocity/fixedNormalInletOutletVelocityFvPatchVectorField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/isothermalFluid/potentialFreeSurfaceOscillatingBox/0/U`](../../../tutorials/isothermalFluid/potentialFreeSurfaceOscillatingBox/0/U)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
