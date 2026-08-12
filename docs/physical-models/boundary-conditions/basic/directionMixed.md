# directionMixed

## 一句话
方向混合条件：法向/切向分量分别约束。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`directionMixed`
- **典型场**：任意场（模板）
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            directionMixed;
    // 其余条目见源码 Usage / 教程
    value           $internalField;
}
```

## 参数表
见类头 `Usage`；多数仅需 `value` / `gradient` / mixed 三元组。

## 控制方程与关联式
方向混合条件：法向/切向分量分别约束。

类头 `Description` 原文：

> Base class for direction-mixed boundary conditions.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/basic/directionMixed/directionMixedFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/basic/directionMixed/directionMixedFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/basic/directionMixed/directionMixedFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/basic/directionMixed/directionMixedFvPatchField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (basic dir)

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            directionMixed`。

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
