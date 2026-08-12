# uniformFixedValue

## 一句话
给定固定边界值（Dirichlet）。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`uniformFixedValue`
- **典型场**：见源码 / 场量纲匹配
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            uniformFixedValue;
    uniformValue    constant 0.2;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `uniformValue` | uniform value | yes |  |

## 控制方程与关联式
给定固定边界值（Dirichlet）。

类头 `Description` 原文：

> This boundary condition provides a uniform fixed value condition.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/uniformFixedValue/uniformFixedValueFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/uniformFixedValue/uniformFixedValueFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/uniformFixedValue/uniformFixedValueFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/uniformFixedValue/uniformFixedValueFvPatchField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/shockFluid/movingCone/0/pointMotionUx`](../../../tutorials/shockFluid/movingCone/0/pointMotionUx)
- [`tutorials/potentialFoam/cylinder/0/U.orig`](../../../tutorials/potentialFoam/cylinder/0/U.orig)
- [`tutorials/multiphaseEuler/steamInjection/0/U.steam`](../../../tutorials/multiphaseEuler/steamInjection/0/U.steam)
- [`tutorials/multiphaseEuler/bubblePipe/0/f0.air1`](../../../tutorials/multiphaseEuler/bubblePipe/0/f0.air1)
- [`tutorials/multiphaseEuler/bubblePipe/0/f2.air1`](../../../tutorials/multiphaseEuler/bubblePipe/0/f2.air1)
- [`tutorials/multiphaseEuler/bubblePipe/0/f5.air2`](../../../tutorials/multiphaseEuler/bubblePipe/0/f5.air2)

## 注意事项
- The uniformValue entry is a Function1 type, able to describe time     varying functions.  The example above gives the usage for supplying a     constant value.
