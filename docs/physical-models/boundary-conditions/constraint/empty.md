# empty

## 一句话
二维空补丁：该方向不求解。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`empty`
- **典型场**：任意场（模板）
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）
- **前提**：`blockMeshDict`/`polyMesh` 中 patch 类型必须匹配（如 `type` wedge;` 配 `wedge` BC）。

## 字典示例
```
<patchName>
{
    type            empty;
}
```

## 参数表
通常无额外物理参数；由约束 patch 拓扑决定行为。

## 控制方程与关联式
二维空补丁：该方向不求解。

类头 `Description` 原文：

> This boundary condition provides an 'empty' condition for reduced
> dimensions cases, i.e. 1- and 2-D geometries.  Apply this condition to
> patches whose normal is aligned to geometric directions that do not
> constitute solution directions.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/constraint/empty/emptyFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/constraint/empty/emptyFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/constraint/empty/emptyFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/constraint/empty/emptyFvPatchField.H)
- Inventory 备注：constraint

## 教程与模板
- [`tutorials/XiFluid/stratified/0/alphat`](../../../tutorials/XiFluid/stratified/0/alphat)
- [`tutorials/XiFluid/stratified/0/b`](../../../tutorials/XiFluid/stratified/0/b)
- [`tutorials/XiFluid/stratified/0/egr.orig`](../../../tutorials/XiFluid/stratified/0/egr.orig)
- [`tutorials/XiFluid/stratified/0/epsilon`](../../../tutorials/XiFluid/stratified/0/epsilon)
- [`tutorials/XiFluid/stratified/0/ft.orig`](../../../tutorials/XiFluid/stratified/0/ft.orig)
- [`tutorials/XiFluid/stratified/0/fu.orig`](../../../tutorials/XiFluid/stratified/0/fu.orig)

## 注意事项
- 约束 BC 名称必须与 mesh patch 类型一致，否则构造期报错。
