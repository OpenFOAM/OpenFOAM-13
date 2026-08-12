# greyDiffusiveRadiationMixed

## 一句话
辐射边界（Marshak / 漫反射等）。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`greyDiffusiveRadiationMixed`
- **RTS `TypeName`**：`greyDiffusiveRadiation`（与字典名不同时以字典 `type` 为准）
- **典型场**：G / I / qr
- **库 / 加载**：需 `libradiationModels`；案例中启用辐射模型时加载
- **适用标签**：见库说明；不确定时查求解器 `Make/options`。

## 字典示例
```
<patchName>
{
    type            greyDiffusiveRadiation;
    T               T;
    emissivityMode  solidRadiation;
    value           uniform 0;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `T` | temperature field name | no | T |
| `emissivityMode` | emissivity mode: solidRadiation or lookup | yes |  |

## 控制方程与关联式
辐射边界（Marshak / 漫反射等）。

类头 `Description` 原文：

> This boundary condition provides a grey-diffuse condition for radiation
> intensity, \c I, for use with the finite-volume discrete-ordinates model
> (fvDOM), in which the radiation temperature is retrieved from the
> temperature field boundary condition.

## 文献与源码依据
- 源码：[`src/radiationModels/derivedFvPatchFields/greyDiffusiveRadiation/greyDiffusiveRadiationMixedFvPatchScalarField.C`](../../../src/radiationModels/derivedFvPatchFields/greyDiffusiveRadiation/greyDiffusiveRadiationMixedFvPatchScalarField.C)
- 头文件：[`src/radiationModels/derivedFvPatchFields/greyDiffusiveRadiation/greyDiffusiveRadiationMixedFvPatchScalarField.H`](../../../src/radiationModels/derivedFvPatchFields/greyDiffusiveRadiation/greyDiffusiveRadiationMixedFvPatchScalarField.H)
- Inventory 备注：radiation BCs

## 教程与模板
- [`tutorials/multicomponentFluid/smallPoolFire3D/0/IDefault`](../../../tutorials/multicomponentFluid/smallPoolFire3D/0/IDefault)
- [`tutorials/multicomponentFluid/smallPoolFire2D/0/IDefault`](../../../tutorials/multicomponentFluid/smallPoolFire2D/0/IDefault)
- [`tutorials/fluid/hotRadiationRoomFvDOM/0/IDefault`](../../../tutorials/fluid/hotRadiationRoomFvDOM/0/IDefault)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
