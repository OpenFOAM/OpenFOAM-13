# calculated

## 一句话
由求解器/其他场计算得到，通常不由用户直接指定物理模型。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`calculated`
- **典型场**：任意场（模板）
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            calculated;
    value           uniform (0 0 0);    // Required value entry
}
```

## 参数表
见类头 `Usage`；多数仅需 `value` / `gradient` / mixed 三元组。

## 控制方程与关联式
由求解器/其他场计算得到，通常不由用户直接指定物理模型。

类头 `Description` 原文：

> This boundary condition is not designed to be evaluated; it is assumed
> that the value is assigned via field assignment, and not via a call to
> e.g. \c updateCoeffs or \c evaluate.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/basic/calculated/calculatedFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/basic/calculated/calculatedFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/basic/calculated/calculatedFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/basic/calculated/calculatedFvPatchField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (basic dir)

## 教程与模板
- [`tutorials/XiFluid/engine2Valve2D/0/alphat`](../../../tutorials/XiFluid/engine2Valve2D/0/alphat)
- [`tutorials/XiFluid/engine2Valve2D/0/nut`](../../../tutorials/XiFluid/engine2Valve2D/0/nut)
- [`tutorials/XiFluid/1D/0/alphat`](../../../tutorials/XiFluid/1D/0/alphat)
- [`tutorials/XiFluid/1D/0/nut`](../../../tutorials/XiFluid/1D/0/nut)
- [`tutorials/solidDisplacement/beamEndLoad/0/T`](../../../tutorials/solidDisplacement/beamEndLoad/0/T)
- [`tutorials/shockFluid/shockTube/0/mag(U)`](../../../tutorials/shockFluid/shockTube/0/mag(U))

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
