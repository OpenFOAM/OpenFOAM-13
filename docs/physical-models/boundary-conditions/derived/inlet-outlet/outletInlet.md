# outletInlet

## 一句话
进出流混合类边界条件 `outletInlet`。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`outletInlet`
- **典型场**：见源码 / 场量纲匹配
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            outletInlet;
    phi             phi;
    outletValue     uniform 0;
    value           uniform 0;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `phi` | Flux field name | no | phi |
| `outletValue` | Outlet value for reverse flow | yes |  |

## 控制方程与关联式
进出流混合类边界条件 `outletInlet`。

类头 `Description` 原文：

> This boundary condition provides a generic inflow condition, with
> specified outflow for the case of reverse flow.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/outletInlet/outletInletFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/outletInlet/outletInletFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/outletInlet/outletInletFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/outletInlet/outletInletFvPatchField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            outletInlet`。

## 注意事项
- Sign conventions:   - Positive flux (out of domain): apply the "outletValue" fixed-value   - Negative flux (into of domain): apply zero-gradient condition
