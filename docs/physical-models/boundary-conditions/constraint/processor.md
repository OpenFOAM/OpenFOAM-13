# processor

## 一句话
并行分区交界面。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`processor`
- **典型场**：任意场（模板）
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）
- **前提**：`blockMeshDict`/`polyMesh` 中 patch 类型必须匹配（如 `type` wedge;` 配 `wedge` BC）。

## 字典示例
```
<patchName>
{
    type            processor;
}
```

## 参数表
通常无额外物理参数；由约束 patch 拓扑决定行为。

## 控制方程与关联式
并行分区交界面。

类头 `Description` 原文：

> This boundary condition enables processor communication across patches.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/constraint/processor/processorFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/constraint/processor/processorFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/constraint/processor/processorFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/constraint/processor/processorFvPatchField.H)
- Inventory 备注：constraint

## 教程与模板
- [`tutorials/incompressibleFluid/turbineSiting/0/include/sideAndTopPatches`](../../../tutorials/incompressibleFluid/turbineSiting/0/include/sideAndTopPatches)
- [`tutorials/incompressibleFluid/motorBike/motorBike/0/k`](../../../tutorials/incompressibleFluid/motorBike/motorBike/0/k)
- [`tutorials/incompressibleFluid/motorBike/motorBike/0/nut`](../../../tutorials/incompressibleFluid/motorBike/motorBike/0/nut)
- [`tutorials/incompressibleFluid/motorBike/motorBike/0/nuTilda`](../../../tutorials/incompressibleFluid/motorBike/motorBike/0/nuTilda)
- [`tutorials/incompressibleFluid/motorBike/motorBike/0/p`](../../../tutorials/incompressibleFluid/motorBike/motorBike/0/p)
- [`tutorials/incompressibleFluid/motorBike/motorBike/0/U`](../../../tutorials/incompressibleFluid/motorBike/motorBike/0/U)

## 注意事项
- 约束 BC 名称必须与 mesh patch 类型一致，否则构造期报错。
