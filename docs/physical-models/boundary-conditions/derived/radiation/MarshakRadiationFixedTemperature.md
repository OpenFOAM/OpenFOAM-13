# MarshakRadiationFixedTemperature

## 一句话
辐射边界（Marshak / 漫反射等）。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`MarshakRadiationFixedTemperature`
- **典型场**：`T`, G / I / qr
- **库 / 加载**：需 `libradiationModels`；案例中启用辐射模型时加载
- **适用标签**：见库说明；不确定时查求解器 `Make/options`。

## 字典示例
```
<patchName>
{
    type            MarshakRadiationFixedTemperature;
    Trad            uniform 1000;       // radiation temperature field
    value           uniform 0;          // place holder
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `Trad` | radiation temperature field | yes |  |

## 控制方程与关联式
辐射边界（Marshak / 漫反射等）。

类头 `Description` 原文：

> A 'mixed' boundary condition that implements a Marshak condition for the
> incident radiation field (usually written as G)
> 
> The radiation temperature field across the patch is supplied by the user
> using the \c Trad entry.

## 文献与源码依据
- 源码：[`src/radiationModels/derivedFvPatchFields/MarshakRadiationFixedTemperature/MarshakRadiationFixedTemperatureFvPatchScalarField.C`](../../../src/radiationModels/derivedFvPatchFields/MarshakRadiationFixedTemperature/MarshakRadiationFixedTemperatureFvPatchScalarField.C)
- 头文件：[`src/radiationModels/derivedFvPatchFields/MarshakRadiationFixedTemperature/MarshakRadiationFixedTemperatureFvPatchScalarField.H`](../../../src/radiationModels/derivedFvPatchFields/MarshakRadiationFixedTemperature/MarshakRadiationFixedTemperatureFvPatchScalarField.H)
- Inventory 备注：radiation BCs

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            MarshakRadiationFixedTemperature`。

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
