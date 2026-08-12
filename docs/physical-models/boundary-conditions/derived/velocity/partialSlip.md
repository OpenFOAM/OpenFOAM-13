# partialSlip

## 一句话
（部分）滑移：法向约束、切向按比例或固定。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`partialSlip`
- **典型场**：见源码 / 场量纲匹配
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例

```cpp
wall
{
    type            partialSlip;
    valueFraction   uniform 0.1;   // [-] 0=全滑移 … 1=无滑移（fixedValue）
    value           uniform (0 0 0); // [m/s] 参考切向
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `valueFraction` | fraction of value used for boundary [0-1] | yes |  |

## 控制方程与关联式
（部分）滑移：法向约束、切向按比例或固定。

类头 `Description` 原文：

> This boundary condition provides a partial slip condition.  The amount of
> slip is controlled by a user-supplied field.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/partialSlip/partialSlipFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/partialSlip/partialSlipFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/partialSlip/partialSlipFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/partialSlip/partialSlipFvPatchField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            partialSlip`。

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
