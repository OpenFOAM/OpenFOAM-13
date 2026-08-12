# mixed

## 一句话
给定固定边界值（Dirichlet）。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`mixed`
- **典型场**：任意场（模板）
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            mixed;
    refValue        uniform 0;
    refGradient     uniform 0;
    valueFraction   uniform 1;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `refValue` | reference value | yes |  |
| `refGradient` | reference normal gradient | yes |  |
| `valueFraction` | weight field | yes |  |

## 控制方程与关联式
给定固定边界值（Dirichlet）。

类头 `Description` 原文：

> This boundary condition provides a base class for 'mixed' type boundary
> conditions, i.e. conditions that mix fixed value and patch-normal gradient
> conditions.
> 
> The respective contributions from each is determined by a weight field:
> 
>     $$
>         x_p = w x_p + (1-w) \left(x_c + \frac{\nabla_\perp x}{\Delta}\right)
>     $$
> 
> where
> 
>     x_p    | patch values
>     x_c    | patch internal cell values
>     w      | weight field (0-1)
>     \Delta | inverse distance from face centre to internal cell centre
> 

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/basic/mixed/mixedFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/basic/mixed/mixedFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/basic/mixed/mixedFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/basic/mixed/mixedFvPatchField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (basic dir)

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            mixed`。

## 注意事项
- This condition is not usually applied directly; instead, use a derived     mixed condition such as inletOutlet
