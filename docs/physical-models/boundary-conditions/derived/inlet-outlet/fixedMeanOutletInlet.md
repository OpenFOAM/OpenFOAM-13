# fixedMeanOutletInlet

## 一句话
按通量方向在入口值与零梯度间切换。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`fixedMeanOutletInlet`
- **典型场**：见源码 / 场量纲匹配
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            fixedMeanOutletInlet;
    meanValue       1.0;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `meanValue` | mean value Function1 | yes |  |
| `phi` | Flux field name | no | phi |

## 控制方程与关联式
按通量方向在入口值与零梯度间切换。

类头 `Description` 原文：

> This boundary condition extrapolates field to the patch using the near-cell
> values and adjusts the distribution to match the specified, optionally
> time-varying, mean value.  This extrapolated field is applied as a
> fixedValue for outflow faces but zeroGradient is applied to inflow faces.
> 
> This boundary condition can be applied to pressure when inletOutlet is
> applied to the velocity so that a zeroGradient condition is applied to the
> pressure at inflow faces where the velocity is specified to avoid an
> unphysical over-specification of the set of boundary conditions.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/fixedMeanOutletInlet/fixedMeanOutletInletFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/fixedMeanOutletInlet/fixedMeanOutletInletFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/fixedMeanOutletInlet/fixedMeanOutletInletFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/fixedMeanOutletInlet/fixedMeanOutletInletFvPatchField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            fixedMeanOutletInlet`。

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
