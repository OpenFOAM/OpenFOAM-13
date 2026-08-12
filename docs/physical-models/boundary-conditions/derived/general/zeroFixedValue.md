# zeroFixedValue

## 一句话
给定固定边界值（Dirichlet）。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`zeroFixedValue`
- **典型场**：见源码 / 场量纲匹配
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            zeroFixedValue;
}
```

## 参数表
源码头文件未提供标准 `Usage` 表，或参数由基类继承——请对照源码构造函数读取字典关键字。

## 控制方程与关联式
给定固定边界值（Dirichlet）。

类头 `Description` 原文：

> This boundary condition provides a zero fixed value condition.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/zeroFixedValue/zeroFixedValueFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/zeroFixedValue/zeroFixedValueFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/zeroFixedValue/zeroFixedValueFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/zeroFixedValue/zeroFixedValueFvPatchField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            zeroFixedValue`。

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
