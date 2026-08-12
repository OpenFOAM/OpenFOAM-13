# fixedInternalValue

## 一句话
零梯度（Neumann）：边界法向梯度为零。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`fixedInternalValue`
- **典型场**：见源码 / 场量纲匹配
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            fixedInternalValue;
    value           uniform 0;              // place holder
}
```

## 参数表
源码头文件未提供标准 `Usage` 表，或参数由基类继承——请对照源码构造函数读取字典关键字。

## 控制方程与关联式
零梯度（Neumann）：边界法向梯度为零。

类头 `Description` 原文：

> This boundary condition provides a mechanism to set boundary (cell) values
> directly into a matrix, i.e. to set a constraint condition.  Default
> behaviour is to act as a zero gradient condition.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/fixedInternalValue/fixedInternalValueFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/fixedInternalValue/fixedInternalValueFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/fixedInternalValue/fixedInternalValueFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/fixedInternalValue/fixedInternalValueFvPatchField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            fixedInternalValue`。

## 注意事项
- This is used as a base for conditions such as the turbulence epsilon     wall function, which applies a near-wall constraint for high Reynolds     number flows.
