# mixedEnergy

## 一句话
温度相关边界条件。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`mixedEnergy`
- **RTS `TypeName`**：`mixedEnergyCalculatedTemperature`（与字典名不同时以字典 `type` 为准）
- **典型场**：h / e / ha / ea
- **库 / 加载**：需 `libfluidThermophysicalModels`（能量场 `e`/`h` 由 thermo 构造）

## 字典示例
```
<patchName>
{
    type            mixedEnergy;
    // 其余条目见源码 Usage / 教程
    value           $internalField;
}
```

## 参数表
源码头文件未提供标准 `Usage` 表，或参数由基类继承——请对照源码构造函数读取字典关键字。

## 控制方程与关联式
温度相关边界条件。

类头 `Description` 原文：

> Base class for temperature boundary conditions in which the parameters of
> the mixed energy condition can be set directly.

## 文献与源码依据
- 源码：[`src/thermophysicalModels/basic/derivedFvPatchFields/mixedEnergy/mixedEnergyFvPatchScalarField.C`](../../../src/thermophysicalModels/basic/derivedFvPatchFields/mixedEnergy/mixedEnergyFvPatchScalarField.C)
- 头文件：[`src/thermophysicalModels/basic/derivedFvPatchFields/mixedEnergy/mixedEnergyCalculatedTemperatureFvPatchScalarField.H`](../../../src/thermophysicalModels/basic/derivedFvPatchFields/mixedEnergy/mixedEnergyCalculatedTemperatureFvPatchScalarField.H)
- Inventory 备注：thermophysical BCs

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            mixedEnergy`。

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
