# singleSizeGroup

## 一句话
multiphaseEuler类边界条件 `singleSizeGroup`。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`singleSizeGroup`
- **典型场**：f.* (size group)
- **库 / 加载**：模块本地：仅 `multiphaseEuler`
- **适用标签**：见库说明；不确定时查求解器 `Make/options`。

## 字典示例
```
<patchName>
{
    type        singleSizeGroup;
    index       0;
    value       $internalField;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| | *以下关键字自 `.C` 构造函数字典读取推断，完整语义见源码* | | |
| `index` | （自构造函数字典读取） | yes |  |

## 控制方程与关联式
multiphaseEuler类边界条件 `singleSizeGroup`。

类头 `Description` 原文：

> Boundary condition for size-group fractions that sets a value of one in a
> single group, identified by its index, and a value of zero in all other
> groups

## 文献与源码依据
- 源码：[`applications/modules/multiphaseEuler/populationBalance/derivedFvPatchFields/singleSizeGroup/singleSizeGroupFvPatchScalarField.C`](../../../applications/modules/multiphaseEuler/populationBalance/derivedFvPatchFields/singleSizeGroup/singleSizeGroupFvPatchScalarField.C)
- 头文件：[`applications/modules/multiphaseEuler/populationBalance/derivedFvPatchFields/singleSizeGroup/singleSizeGroupFvPatchScalarField.H`](../../../applications/modules/multiphaseEuler/populationBalance/derivedFvPatchFields/singleSizeGroup/singleSizeGroupFvPatchScalarField.H)
- Inventory 备注：module-local BCs

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            singleSizeGroup`。

## 注意事项
- 模块本地 BC：其他 solver 即使同名字段也不会注册该 `type`。
