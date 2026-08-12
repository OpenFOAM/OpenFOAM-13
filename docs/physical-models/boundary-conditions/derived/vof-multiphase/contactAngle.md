# contactAngle

## 一句话
VoF 壁面接触角条件，控制 `alpha` 壁面法向梯度/限幅。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`contactAngle`
- **典型场**：`alpha`.*`
- **库 / 加载**：需两相/VoF 相关库（`libtwoPhaseProperties` / interfaceProperties）

## 字典示例
```
<patchName>
{
    type            contactAngle;
    limit           none;
    contactAngle
    {
        type            constant;
        theta0          70;
    }
}
```

```
<patchName>
{
    type            contactAngle;
    limit           none;
    theta0          70;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `limit` | Limiting option | yes |  |
| `contantAngle` | Contact angle model settings | no | none |

## 控制方程与关联式
VoF 壁面接触角条件，控制 `alpha` 壁面法向梯度/限幅。

类头 `Description` 原文：

> General alpha contact angle boundary condition.
> 
> The essential entry "limit" controls the gradient of alpha1 on the wall:
>   - none - Calculate the gradient from the contact-angle without limiter
>   - gradient - Limit the wall-gradient such that alpha1 remains bounded
>     on the wall
>   - alpha - Bound the calculated alpha1 on the wall
>   - zeroGradient - Set the gradient of alpha1 to 0 on the wall, i.e.
>     reproduce previous behaviour, the pressure BCs can be left as before.
> 
> Note that if any of the first three options are used the boundary condition
> on \c p_rgh must set to guarantee that the flux is corrected to be zero at
> the wall.

## 文献与源码依据
- 源码：[`src/twoPhaseModels/interfaceProperties/contactAngle/contactAngleFvPatchScalarField.C`](../../../src/twoPhaseModels/interfaceProperties/contactAngle/contactAngleFvPatchScalarField.C)
- 头文件：[`src/twoPhaseModels/interfaceProperties/contactAngle/contactAngleFvPatchScalarField.H`](../../../src/twoPhaseModels/interfaceProperties/contactAngle/contactAngleFvPatchScalarField.H)
- Inventory 备注：twoPhase BCs

## 教程与模板
- [`tutorials/incompressibleVoF/capillaryRise/0/alpha.water.orig`](../../../tutorials/incompressibleVoF/capillaryRise/0/alpha.water.orig)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
