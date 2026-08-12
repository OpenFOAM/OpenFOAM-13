# uniformInletOutlet

## 一句话
按通量方向在入口值与零梯度间切换。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`uniformInletOutlet`
- **典型场**：见源码 / 场量纲匹配
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type                uniformInletOutlet;
    phi                 phi;
    uniformInletValue   0;
    value               uniform 0;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `phi` | flux field name | no | phi |
| `uniformInletValue` | inlet value for reverse flow | yes |  |

## 控制方程与关联式
按通量方向在入口值与零梯度间切换。

类头 `Description` 原文：

> Variant of inletOutlet boundary condition with uniform inletValue.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/uniformInletOutlet/uniformInletOutletFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/uniformInletOutlet/uniformInletOutletFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/uniformInletOutlet/uniformInletOutletFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/uniformInletOutlet/uniformInletOutletFvPatchField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/multiphaseEuler/injection/0/T.air`](../../../tutorials/multiphaseEuler/injection/0/T.air)
- [`tutorials/multiphaseEuler/injection/0/U.air`](../../../tutorials/multiphaseEuler/injection/0/U.air)
- [`tutorials/multiphaseEuler/bubbleColumnEvaporatingReacting/0/epsilon.gas`](../../../tutorials/multiphaseEuler/bubbleColumnEvaporatingReacting/0/epsilon.gas)
- [`tutorials/multiphaseEuler/bubbleColumnEvaporatingReacting/0/k.gas`](../../../tutorials/multiphaseEuler/bubbleColumnEvaporatingReacting/0/k.gas)
- [`tutorials/multiphaseEuler/bed/0/T.water`](../../../tutorials/multiphaseEuler/bed/0/T.water)
- [`tutorials/multiphaseEuler/bed/0/U.water`](../../../tutorials/multiphaseEuler/bed/0/U.water)

## 注意事项
- Sign conventions:   - positive flux (out of domain): apply zero-gradient condition   - negative flux (into of domain): apply the user-specified fixed value
