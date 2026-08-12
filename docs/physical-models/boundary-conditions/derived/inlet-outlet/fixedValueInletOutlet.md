# fixedValueInletOutlet

## 一句话
按通量方向在入口值与零梯度间切换。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`fixedValueInletOutlet`
- **典型场**：见源码 / 场量纲匹配
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            fixedValueInletOutlet;
    phi             phi;
    value           0;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `phi` | Name of the flux field | no | phi |

## 控制方程与关联式
按通量方向在入口值与零梯度间切换。

类头 `Description` 原文：

> This boundary condition sets a fixed value. When the flow direction is
> inwards this acts exactly like a fixed value condition. In the presence of
> outflow, however, this condition approximates the fixed value constraint in
> advective terms by fixing the gradient instead.
> 
> This condition is not likely to be used on its own. It is more suitable as
> a base class for conditions that need to specify the value of a field even
> when the flow reverses.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/fixedValueInletOutlet/fixedValueInletOutletFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/fixedValueInletOutlet/fixedValueInletOutletFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/fixedValueInletOutlet/fixedValueInletOutletFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/fixedValueInletOutlet/fixedValueInletOutletFvPatchField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            fixedValueInletOutlet`。

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
