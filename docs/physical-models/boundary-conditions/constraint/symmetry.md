# symmetry

## 一句话
对称面约束。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`symmetry`
- **典型场**：任意场（模板）
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）
- **前提**：`blockMeshDict`/`polyMesh` 中 patch 类型必须匹配（如 `type` wedge;` 配 `wedge` BC）。

## 字典示例
```
<patchName>
{
    type            symmetry;
}
```

## 参数表
通常无额外物理参数；由约束 patch 拓扑决定行为。

## 控制方程与关联式
对称面约束。

类头 `Description` 原文：

> This boundary condition enforces a symmetry constraint

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/constraint/symmetry/symmetryFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/constraint/symmetry/symmetryFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/constraint/symmetry/symmetryFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/constraint/symmetry/symmetryFvPatchField.H)
- Inventory 备注：constraint

## 教程与模板
- [`tutorials/shockFluid/biconic25-55Run35/0/p`](../../../tutorials/shockFluid/biconic25-55Run35/0/p)
- [`tutorials/shockFluid/biconic25-55Run35/0/T`](../../../tutorials/shockFluid/biconic25-55Run35/0/T)
- [`tutorials/shockFluid/biconic25-55Run35/0/U`](../../../tutorials/shockFluid/biconic25-55Run35/0/U)
- [`tutorials/shockFluid/biconic25-55Run35/system/blockMeshDict`](../../../tutorials/shockFluid/biconic25-55Run35/system/blockMeshDict)
- [`tutorials/potentialFoam/cylinder/0/p.orig`](../../../tutorials/potentialFoam/cylinder/0/p.orig)
- [`tutorials/potentialFoam/cylinder/0/U.orig`](../../../tutorials/potentialFoam/cylinder/0/U.orig)

## 注意事项
- 约束 BC 名称必须与 mesh patch 类型一致，否则构造期报错。
