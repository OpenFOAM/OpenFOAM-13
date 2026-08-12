# MarshakRadiation

## 一句话
辐射边界（Marshak / 漫反射等）。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`MarshakRadiation`
- **典型场**：G / I / qr
- **库 / 加载**：需 `libradiationModels`；案例中启用辐射模型时加载
- **适用标签**：见库说明；不确定时查求解器 `Make/options`。

## 字典示例
```
<patchName>
{
    type            MarshakRadiation;
    T               T;
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

> A 'mixed' boundary condition that implements a Marshak condition for the
> incident radiation field (usually written as G)
> 
> The radiation temperature is retrieved from the mesh database, using a
> user specified temperature field name.

## 文献与源码依据
- 源码：[`src/radiationModels/derivedFvPatchFields/MarshakRadiation/MarshakRadiationFvPatchScalarField.C`](../../../src/radiationModels/derivedFvPatchFields/MarshakRadiation/MarshakRadiationFvPatchScalarField.C)
- 头文件：[`src/radiationModels/derivedFvPatchFields/MarshakRadiation/MarshakRadiationFvPatchScalarField.H`](../../../src/radiationModels/derivedFvPatchFields/MarshakRadiation/MarshakRadiationFvPatchScalarField.H)
- Inventory 备注：radiation BCs

## 教程与模板
- [`tutorials/multiRegion/CHT/reverseBurner/0/gas/G`](../../../tutorials/multiRegion/CHT/reverseBurner/0/gas/G)
- [`tutorials/multicomponentFluid/smallPoolFire3D/0/G`](../../../tutorials/multicomponentFluid/smallPoolFire3D/0/G)
- [`tutorials/multicomponentFluid/smallPoolFire2D/0/G`](../../../tutorials/multicomponentFluid/smallPoolFire2D/0/G)
- [`tutorials/multicomponentFluid/simplifiedSiwek/0/G`](../../../tutorials/multicomponentFluid/simplifiedSiwek/0/G)
- [`tutorials/multicomponentFluid/SandiaD_LTS/0/G`](../../../tutorials/multicomponentFluid/SandiaD_LTS/0/G)
- [`tutorials/multicomponentFluid/parcelInBox/0/G`](../../../tutorials/multicomponentFluid/parcelInBox/0/G)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
