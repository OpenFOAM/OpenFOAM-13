# zeroGradient

## 一句话
零梯度（Neumann）：边界法向梯度为零。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`zeroGradient`
- **典型场**：任意场（模板）
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            zeroGradient;
}
```

## 参数表
见类头 `Usage`；多数仅需 `value` / `gradient` / mixed 三元组。

## 控制方程与关联式
零梯度（Neumann）：边界法向梯度为零。

类头 `Description` 原文：

> This boundary condition applies a zero-gradient condition from the patch
> internal field onto the patch faces.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/basic/zeroGradient/zeroGradientFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/basic/zeroGradient/zeroGradientFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/basic/zeroGradient/zeroGradientFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/basic/zeroGradient/zeroGradientFvPatchField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (basic dir)

## 教程与模板
- [`tutorials/XiFluid/kivaTest/-180/b`](../../../tutorials/XiFluid/kivaTest/-180/b)
- [`tutorials/XiFluid/kivaTest/-180/ft`](../../../tutorials/XiFluid/kivaTest/-180/ft)
- [`tutorials/XiFluid/kivaTest/-180/fu`](../../../tutorials/XiFluid/kivaTest/-180/fu)
- [`tutorials/XiFluid/kivaTest/-180/p`](../../../tutorials/XiFluid/kivaTest/-180/p)
- [`tutorials/XiFluid/kivaTest/-180/Su`](../../../tutorials/XiFluid/kivaTest/-180/Su)
- [`tutorials/XiFluid/kivaTest/-180/Xi`](../../../tutorials/XiFluid/kivaTest/-180/Xi)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
