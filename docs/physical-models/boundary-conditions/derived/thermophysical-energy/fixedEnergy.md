# fixedEnergy

## 一句话
给定固定边界值（Dirichlet）。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`fixedEnergy`
- **典型场**：h / e / ha / ea
- **库 / 加载**：需 `libfluidThermophysicalModels`（能量场 `e`/`h` 由 thermo 构造）

## 字典示例
```
<patchName>
{
    type            fixedEnergy;
    // 其余条目见源码 Usage / 教程
    value           $internalField;
}
```

## 参数表
源码头文件未提供标准 `Usage` 表，或参数由基类继承——请对照源码构造函数读取字典关键字。

## 控制方程与关联式
给定固定边界值（Dirichlet）。

类头 `Description` 原文：

> This boundary condition provides a fixed condition for energy. This is
> selected when the corresponding temperature condition is fixedValue.

## 文献与源码依据
- 源码：[`src/thermophysicalModels/basic/derivedFvPatchFields/fixedEnergy/fixedEnergyFvPatchScalarField.C`](../../../src/thermophysicalModels/basic/derivedFvPatchFields/fixedEnergy/fixedEnergyFvPatchScalarField.C)
- 头文件：[`src/thermophysicalModels/basic/derivedFvPatchFields/fixedEnergy/fixedEnergyFvPatchScalarField.H`](../../../src/thermophysicalModels/basic/derivedFvPatchFields/fixedEnergy/fixedEnergyFvPatchScalarField.H)
- Inventory 备注：thermophysical BCs

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            fixedEnergy`。

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
