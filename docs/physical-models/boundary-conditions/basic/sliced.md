# sliced

## 一句话
基本边界条件类型 `sliced`。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`sliced`
- **典型场**：任意场（模板）
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            sliced;
    // 其余条目见源码 Usage / 教程
    value           $internalField;
}
```

## 参数表
见类头 `Usage`；多数仅需 `value` / `gradient` / mixed 三元组。

## 控制方程与关联式
基本边界条件类型 `sliced`。

类头 `Description` 原文：

> Specialisation of fvPatchField which creates the underlying
> fvPatchField as a slice of the given complete field.
> 
> The destructor is wrapped to avoid deallocation of the storage of the
> complete fields when this is destroyed.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/basic/sliced`](../../../src/finiteVolume/fields/fvPatchFields/basic/sliced)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/basic/sliced/slicedFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/basic/sliced/slicedFvPatchField.H)
- Inventory 备注：core finiteVolume (basic dir)

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            sliced`。

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
