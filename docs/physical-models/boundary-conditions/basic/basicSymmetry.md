# basicSymmetry

## 一句话
对称面约束。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`basicSymmetry`
- **典型场**：任意场（模板）
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            basicSymmetry;
    // 其余条目见源码 Usage / 教程
    value           $internalField;
}
```

## 参数表
见类头 `Usage`；多数仅需 `value` / `gradient` / mixed 三元组。

## 控制方程与关联式
对称面约束。

类头 `Description` 原文：

> A symmetry patch

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/basic/basicSymmetry`](../../../src/finiteVolume/fields/fvPatchFields/basic/basicSymmetry)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/basic/basicSymmetry/basicSymmetryFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/basic/basicSymmetry/basicSymmetryFvPatchField.H)
- Inventory 备注：core finiteVolume (basic dir)

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            basicSymmetry`。

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
