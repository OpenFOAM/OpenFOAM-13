# extrapolatedCalculated

## 一句话
外推型 calculated：用内部场外推更新边界值。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`extrapolatedCalculated`
- **典型场**：任意场（模板）
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            extrapolatedCalculated;
}
```

## 参数表
见类头 `Usage`；多数仅需 `value` / `gradient` / mixed 三元组。

## 控制方程与关联式
外推型 calculated：用内部场外推更新边界值。

类头 `Description` 原文：

> This boundary condition applies a zero-gradient condition from the patch
> internal field onto the patch faces when \c evaluated but may also be
> assigned.  \c snGrad returns the patch gradient evaluated from the current
> internal and patch field values rather than returning zero.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/basic/extrapolatedCalculated/extrapolatedCalculatedFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/basic/extrapolatedCalculated/extrapolatedCalculatedFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/basic/extrapolatedCalculated/extrapolatedCalculatedFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/basic/extrapolatedCalculated/extrapolatedCalculatedFvPatchField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (basic dir)

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            extrapolatedCalculated`。

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
