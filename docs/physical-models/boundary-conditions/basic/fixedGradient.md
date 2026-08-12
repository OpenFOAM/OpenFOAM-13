# fixedGradient

## 一句话
给定固定法向梯度。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`fixedGradient`
- **典型场**：任意场（模板）
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            fixedGradient;
    gradient        uniform 0;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `gradient` | gradient | yes |  |

## 控制方程与关联式
给定固定法向梯度。

类头 `Description` 原文：

> This boundary condition supplies a fixed gradient condition, such that
> the patch values are calculated using:
> 
>     $$
>         x_p = x_c + \frac{\nabla(x)}{\Delta}
>     $$
> 
> where
> 
>     x_p      | patch values
>     x_c      | internal field values
>     \nabla(x)| gradient (user-specified)
>     \Delta   | inverse distance from patch face centre to cell centre
> 

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/basic/fixedGradient/fixedGradientFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/basic/fixedGradient/fixedGradientFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/basic/fixedGradient/fixedGradientFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/basic/fixedGradient/fixedGradientFvPatchField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (basic dir)

## 教程与模板
- [`tutorials/legacy/basic/financialFoam/europeanCall/0/V`](../../../tutorials/legacy/basic/financialFoam/europeanCall/0/V)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
