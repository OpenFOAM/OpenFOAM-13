# cyclic

## 一句话
周期/循环配对边界。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`cyclic`
- **典型场**：任意场（模板）
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）
- **前提**：`blockMeshDict`/`polyMesh` 中 patch 类型必须匹配（如 `type` wedge;` 配 `wedge` BC）。

## 字典示例
```
<patchName>
{
    type            cyclic;
}
```

## 参数表
通常无额外物理参数；由约束 patch 拓扑决定行为。

## 控制方程与关联式
周期/循环配对边界。

类头 `Description` 原文：

> This boundary condition enforces a cyclic condition between a pair of
> boundaries.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/constraint/cyclic/cyclicFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/constraint/cyclic/cyclicFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/constraint/cyclic/cyclicFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/constraint/cyclic/cyclicFvPatchField.H)
- Inventory 备注：constraint

## 教程与模板
- [`tutorials/multicomponentFluid/filter/0/alphat`](../../../tutorials/multicomponentFluid/filter/0/alphat)
- [`tutorials/multicomponentFluid/filter/0/epsilon`](../../../tutorials/multicomponentFluid/filter/0/epsilon)
- [`tutorials/multicomponentFluid/filter/0/G`](../../../tutorials/multicomponentFluid/filter/0/G)
- [`tutorials/multicomponentFluid/filter/0/H2O`](../../../tutorials/multicomponentFluid/filter/0/H2O)
- [`tutorials/multicomponentFluid/filter/0/k`](../../../tutorials/multicomponentFluid/filter/0/k)
- [`tutorials/multicomponentFluid/filter/0/N2`](../../../tutorials/multicomponentFluid/filter/0/N2)

## 注意事项
- The patches must be topologically similar, i.e. if the owner patch is     transformed to the neighbour patch, the patches should be identical (or     very similar).
- 约束 BC 名称必须与 mesh patch 类型一致，否则构造期报错。
