# alphaOne

## 一句话
给定固定边界值（Dirichlet）。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`alphaOne`
- **典型场**：`alpha`.*`
- **库 / 加载**：模块本地：`isothermalFilm` / `film`
- **适用标签**：见库说明；不确定时查求解器 `Make/options`。

## 字典示例
```
surface
{
    type            alphaOne;
    value           $internalField;
}
```

（将边界 `alpha` 固定为 1；无额外系数。推断自源码 Description / ctor。）

## 参数表
| 参数 | 含义 |
|------|------|
| `value` | 初值（可选，常见写法） |

## 控制方程与关联式
给定固定边界值（Dirichlet）。

类头 `Description` 原文：

> This boundary condition provides a uniform fixed value one condition.

## 文献与源码依据
- 源码：[`applications/modules/isothermalFilm/derivedFvPatchFields/alphaOne/alphaOneFvPatchScalarField.C`](../../../applications/modules/isothermalFilm/derivedFvPatchFields/alphaOne/alphaOneFvPatchScalarField.C)
- 头文件：[`applications/modules/isothermalFilm/derivedFvPatchFields/alphaOne/alphaOneFvPatchScalarField.H`](../../../applications/modules/isothermalFilm/derivedFvPatchFields/alphaOne/alphaOneFvPatchScalarField.H)
- Inventory 备注：module-local BCs

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            alphaOne`。

## 注意事项
- 模块本地 BC：其他 solver 即使同名字段也不会注册该 `type`。
