# fixedNormalSlip

## 一句话
给定固定边界值（Dirichlet）。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`fixedNormalSlip`
- **典型场**：见源码 / 场量纲匹配
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            fixedNormalSlip;
    fixedValue      uniform 0;     // example entry for a scalar field
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `fixedValue` | fixed value | yes |  |

## 控制方程与关联式
给定固定边界值（Dirichlet）。

类头 `Description` 原文：

> This boundary condition sets the patch-normal component to a fixed value.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/fixedNormalSlip`](../../../src/finiteVolume/fields/fvPatchFields/derived/fixedNormalSlip)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/fixedNormalSlip/fixedNormalSlipFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/fixedNormalSlip/fixedNormalSlipFvPatchField.H)
- Inventory 备注：core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/movingMesh/SnakeRiverCanyon/0/pointDisplacement`](../../../tutorials/movingMesh/SnakeRiverCanyon/0/pointDisplacement)
- [`tutorials/isothermalFluid/potentialFreeSurfaceMovingOscillatingBox/0.orig/pointDisplacement`](../../../tutorials/isothermalFluid/potentialFreeSurfaceMovingOscillatingBox/0.orig/pointDisplacement)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
