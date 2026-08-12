# wideBandDiffusiveRadiationMixed

## 一句话
辐射边界（Marshak / 漫反射等）。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`wideBandDiffusiveRadiationMixed`
- **RTS `TypeName`**：`wideBandDiffusiveRadiation`（与字典名不同时以字典 `type` 为准）
- **典型场**：G / I / qr
- **库 / 加载**：需 `libradiationModels`；案例中启用辐射模型时加载
- **适用标签**：见库说明；不确定时查求解器 `Make/options`。

## 字典示例
```
<patchName>
{
    type            wideBandDiffusiveRadiation;
    value           uniform 0;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `T` | temperature field name | no | T |

## 控制方程与关联式
辐射边界（Marshak / 漫反射等）。

类头 `Description` 原文：

> This boundary condition provides a wide-band, diffusive radiation
> condition, where the patch temperature is specified.

## 文献与源码依据
- 源码：[`src/radiationModels/derivedFvPatchFields/wideBandDiffusiveRadiation/wideBandDiffusiveRadiationMixedFvPatchScalarField.C`](../../../src/radiationModels/derivedFvPatchFields/wideBandDiffusiveRadiation/wideBandDiffusiveRadiationMixedFvPatchScalarField.C)
- 头文件：[`src/radiationModels/derivedFvPatchFields/wideBandDiffusiveRadiation/wideBandDiffusiveRadiationMixedFvPatchScalarField.H`](../../../src/radiationModels/derivedFvPatchFields/wideBandDiffusiveRadiation/wideBandDiffusiveRadiationMixedFvPatchScalarField.H)
- Inventory 备注：radiation BCs

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            wideBandDiffusiveRadiationMixed`。

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
