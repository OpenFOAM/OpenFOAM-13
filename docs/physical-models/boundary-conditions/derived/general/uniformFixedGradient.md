# uniformFixedGradient

## 一句话
给定固定法向梯度。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`uniformFixedGradient`
- **典型场**：见源码 / 场量纲匹配
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            uniformFixedGradient;
    uniformGradient constant 0.2;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `uniformGradient` | uniform gradient | yes |  |

## 控制方程与关联式
给定固定法向梯度。

类头 `Description` 原文：

> This boundary condition provides a uniform fixed gradient condition.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/uniformFixedGradient/uniformFixedGradientFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/uniformFixedGradient/uniformFixedGradientFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/uniformFixedGradient/uniformFixedGradientFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/uniformFixedGradient/uniformFixedGradientFvPatchField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            uniformFixedGradient`。

## 注意事项
- The uniformGradient entry is a Function1 type, able to describe time     varying functions.  The example above gives the usage for supplying a     constant value.
