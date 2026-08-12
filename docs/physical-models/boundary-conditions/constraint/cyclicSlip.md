# cyclicSlip

## 一句话
周期/循环配对边界。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`cyclicSlip`
- **典型场**：任意场（模板）
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）
- **前提**：`blockMeshDict`/`polyMesh` 中 patch 类型必须匹配（如 `type` wedge;` 配 `wedge` BC）。

## 字典示例
```
<patchName>
{
    type            cyclicSlip;
}
```

## 参数表
通常无额外物理参数；由约束 patch 拓扑决定行为。

## 控制方程与关联式
周期/循环配对边界。

类头 `Description` 原文：

> This boundary condition is a light wrapper around the cyclicFvPatchField
> condition, providing no new functionality.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/constraint/cyclicSlip/cyclicSlipFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/constraint/cyclicSlip/cyclicSlipFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/constraint/cyclicSlip/cyclicSlipFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/constraint/cyclicSlip/cyclicSlipFvPatchField.H)
- Inventory 备注：constraint

## 教程与模板
- [`etc/caseDicts/setConstraintTypes`](../../../etc/caseDicts/setConstraintTypes)

## 注意事项
- 约束 BC 名称必须与 mesh patch 类型一致，否则构造期报错。
