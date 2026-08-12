# wedge

## 一句话
轴对称楔形几何的约束边界。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`wedge`
- **典型场**：任意场（模板）
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）
- **前提**：`blockMeshDict`/`polyMesh` 中 patch 类型必须匹配（如 `type` wedge;` 配 `wedge` BC）。

## 字典示例
```
<patchName>
{
    type            wedge;
}
```

## 参数表
通常无额外物理参数；由约束 patch 拓扑决定行为。

## 控制方程与关联式
轴对称楔形几何的约束边界。

类头 `Description` 原文：

> This boundary condition is similar to the cyclic condition, except that
> it is applied to 2-D geometries.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/constraint/wedge/wedgeFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/constraint/wedge/wedgeFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/constraint/wedge/wedgeFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/constraint/wedge/wedgeFvPatchField.H)
- Inventory 备注：constraint

## 教程与模板
- [`tutorials/shockFluid/movingCone/system/blockMeshDict`](../../../tutorials/shockFluid/movingCone/system/blockMeshDict)
- [`tutorials/shockFluid/movingCone/system/meshes/1e-05/blockMeshDict`](../../../tutorials/shockFluid/movingCone/system/meshes/1e-05/blockMeshDict)
- [`tutorials/shockFluid/movingCone/system/meshes/2e-05/blockMeshDict`](../../../tutorials/shockFluid/movingCone/system/meshes/2e-05/blockMeshDict)
- [`tutorials/shockFluid/LadenburgJet60psi/0/p`](../../../tutorials/shockFluid/LadenburgJet60psi/0/p)
- [`tutorials/shockFluid/LadenburgJet60psi/0/T`](../../../tutorials/shockFluid/LadenburgJet60psi/0/T)
- [`tutorials/shockFluid/LadenburgJet60psi/0/U`](../../../tutorials/shockFluid/LadenburgJet60psi/0/U)

## 注意事项
- 约束 BC 名称必须与 mesh patch 类型一致，否则构造期报错。
