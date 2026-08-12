# freestream

## 一句话
按通量方向在入口值与零梯度间切换。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`freestream`
- **典型场**：见源码 / 场量纲匹配
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            freestream;
    freestreamValue uniform (300 0 0);
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `freestreamValue` | freestream velocity | yes |  |
| `phi` | flux field name | no | phi |

## 控制方程与关联式
按通量方向在入口值与零梯度间切换。

类头 `Description` 原文：

> This boundary condition provides a free-stream condition.  It is a 'mixed'
> condition derived from the \c inletOutlet condition, whereby the mode of
> operation switches between fixed (free stream) value and zero gradient
> based on the sign of the flux.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/freestream/freestreamFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/freestream/freestreamFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/freestream/freestreamFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/freestream/freestreamFvPatchField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/incompressibleFluid/airFoil2D/0/nut`](../../../tutorials/incompressibleFluid/airFoil2D/0/nut)
- [`tutorials/incompressibleFluid/airFoil2D/0/nuTilda`](../../../tutorials/incompressibleFluid/airFoil2D/0/nuTilda)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
