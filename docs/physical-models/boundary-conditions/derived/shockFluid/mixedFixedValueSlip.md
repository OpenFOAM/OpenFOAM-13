# mixedFixedValueSlip

## 一句话
给定固定边界值（Dirichlet）。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`mixedFixedValueSlip`
- **典型场**：见源码 / 场量纲匹配
- **库 / 加载**：模块本地：仅 `shockFluid` 求解器链接
- **适用标签**：见库说明；不确定时查求解器 `Make/options`。

## 字典示例
```
<patchName>
{
    type            mixedFixedValueSlip;
    // 其余条目见源码 Usage / 教程
    value           $internalField;
}
```

## 参数表
源码头文件未提供标准 `Usage` 表，或参数由基类继承——请对照源码构造函数读取字典关键字。

## 控制方程与关联式
给定固定边界值（Dirichlet）。

类头 `Description` 原文：

> A mixed boundary type that blends between fixedValue and slip, as opposed
> to the standard mixed condition that blends between fixedValue and
> fixedGradient; required to implement maxwellSlipU condition.

## 文献与源码依据
- 源码：[`applications/modules/shockFluid/derivedFvPatchFields/mixedFixedValueSlip/mixedFixedValueSlipFvPatchFields.C`](../../../applications/modules/shockFluid/derivedFvPatchFields/mixedFixedValueSlip/mixedFixedValueSlipFvPatchFields.C)
- 头文件：[`applications/modules/shockFluid/derivedFvPatchFields/mixedFixedValueSlip/mixedFixedValueSlipFvPatchField.H`](../../../applications/modules/shockFluid/derivedFvPatchFields/mixedFixedValueSlip/mixedFixedValueSlipFvPatchField.H)
- Inventory 备注：shockFluid module BCs

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            mixedFixedValueSlip`。

## 注意事项
- 模块本地 BC：其他 solver 即使同名字段也不会注册该 `type`。
