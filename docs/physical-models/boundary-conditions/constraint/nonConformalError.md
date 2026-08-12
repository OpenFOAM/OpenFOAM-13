# nonConformalError

## 一句话
网格约束类型 `nonConformalError`，须与 `polyMesh` patch 类型一致。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`nonConformalError`
- **典型场**：任意场（模板）
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）
- **前提**：`blockMeshDict`/`polyMesh` 中 patch 类型必须匹配（如 `type` wedge;` 配 `wedge` BC）。

## 字典示例
```
<patchName>
{
    type            nonConformalError;
}
```

## 参数表
通常无额外物理参数；由约束 patch 拓扑决定行为。

## 控制方程与关联式
网格约束类型 `nonConformalError`，须与 `polyMesh` patch 类型一致。

类头 `Description` 原文：

> This boundary condition enforces a non-conformal error condition.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/constraint/nonConformalError/nonConformalErrorFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/constraint/nonConformalError/nonConformalErrorFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/constraint/nonConformalError/nonConformalErrorFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/constraint/nonConformalError/nonConformalErrorFvPatchField.H)
- Inventory 备注：constraint

## 教程与模板
- [`tutorials/multiRegion/CHT/engine2Valve2D/0/cylinderHead/T`](../../../tutorials/multiRegion/CHT/engine2Valve2D/0/cylinderHead/T)
- [`tutorials/multiRegion/CHT/engine2Valve2D/0/exhaustValve/T`](../../../tutorials/multiRegion/CHT/engine2Valve2D/0/exhaustValve/T)
- [`tutorials/multiRegion/CHT/engine2Valve2D/0/fluid/p`](../../../tutorials/multiRegion/CHT/engine2Valve2D/0/fluid/p)
- [`tutorials/multiRegion/CHT/engine2Valve2D/0/fluid/T`](../../../tutorials/multiRegion/CHT/engine2Valve2D/0/fluid/T)
- [`tutorials/multiRegion/CHT/engine2Valve2D/0/fluid/U`](../../../tutorials/multiRegion/CHT/engine2Valve2D/0/fluid/U)
- [`tutorials/multiRegion/CHT/engine2Valve2D/0/intakeValve/T`](../../../tutorials/multiRegion/CHT/engine2Valve2D/0/intakeValve/T)

## 注意事项
- 约束 BC 名称必须与 mesh patch 类型一致，否则构造期报错。
