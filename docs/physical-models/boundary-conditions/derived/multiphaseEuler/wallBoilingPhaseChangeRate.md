# wallBoilingPhaseChangeRate

## 一句话
multiphaseEuler类边界条件 `wallBoilingPhaseChangeRate`。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`wallBoilingPhaseChangeRate`
- **典型场**：见源码 / 场量纲匹配
- **库 / 加载**：模块本地：仅 `multiphaseEuler`
- **适用标签**：见库说明；不确定时查求解器 `Make/options`。

## 字典示例
由 `wallBoiling` fvModel **自动构造**，用户通常无需手写。若需理解字段结构，参考源码头文件 Description：

```
// 自动生成于 wall boiling 相变率场；勿在 0/ 中手动指定（除非调试）
<patchName>
{
    type            wallBoilingPhaseChangeRate;
    value           $internalField;
}
```

## 参数表
无用户侧必需系数；状态字段由 wall boiling 模型维护。

## 控制方程与关联式
multiphaseEuler类边界条件 `wallBoilingPhaseChangeRate`。

类头 `Description` 原文：

> This boundary condition is used for the phase change rate field of the wall
> boiling fvModel. It contains the phase change rate, and also all the other
> state fields used by the wall boiling model. The phase change rate field
> and its boundary conditions are constructed automatically so the user need
> never manually specify this condition.

## 文献与源码依据
- 源码：[`applications/modules/multiphaseEuler/fvModels/wallBoiling/wallBoilingPhaseChangeRateFvPatchScalarField.C`](../../../applications/modules/multiphaseEuler/fvModels/wallBoiling/wallBoilingPhaseChangeRateFvPatchScalarField.C)
- 头文件：[`applications/modules/multiphaseEuler/fvModels/wallBoiling/wallBoilingPhaseChangeRateFvPatchScalarField.H`](../../../applications/modules/multiphaseEuler/fvModels/wallBoiling/wallBoilingPhaseChangeRateFvPatchScalarField.H)
- Inventory 备注：module-local BCs

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            wallBoilingPhaseChangeRate`。

## 注意事项
- 模块本地 BC：其他 solver 即使同名字段也不会注册该 `type`。
