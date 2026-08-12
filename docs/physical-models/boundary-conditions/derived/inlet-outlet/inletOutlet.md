# inletOutlet

## 一句话
按通量方向在入口值与零梯度间切换。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`inletOutlet`
- **典型场**：见源码 / 场量纲匹配
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例

```cpp
outlet
{
    type            inletOutlet;
    inletValue      uniform 0;     // 回流时的固定值 [与场同量纲]
    value           uniform 0;
    // 可选: phi（默认 phi）
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `phi` | Flux field name | no | phi |
| `inletValue` | Inlet value for reverse flow | yes |  |

## 控制方程与关联式
按通量方向在入口值与零梯度间切换。

类头 `Description` 原文：

> This boundary condition provides a generic outflow condition, with
> specified inflow for the case of return flow.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/inletOutlet/inletOutletFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/inletOutlet/inletOutletFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/inletOutlet/inletOutletFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/inletOutlet/inletOutletFvPatchField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/XiFluid/engine2Valve2D/0/b`](../../../tutorials/XiFluid/engine2Valve2D/0/b)
- [`tutorials/XiFluid/engine2Valve2D/0/egr`](../../../tutorials/XiFluid/engine2Valve2D/0/egr)
- [`tutorials/XiFluid/engine2Valve2D/0/ft`](../../../tutorials/XiFluid/engine2Valve2D/0/ft)
- [`tutorials/XiFluid/engine2Valve2D/0/fu`](../../../tutorials/XiFluid/engine2Valve2D/0/fu)
- [`tutorials/XiFluid/engine2Valve2D/0/T`](../../../tutorials/XiFluid/engine2Valve2D/0/T)
- [`tutorials/XiFluid/engine2Valve2D/0/Tu`](../../../tutorials/XiFluid/engine2Valve2D/0/Tu)

## 注意事项
- Sign conventions:   - Positive flux (out of domain): apply zero-gradient condition   - Negative flux (into of domain): apply the "inletValue" fixed-value
