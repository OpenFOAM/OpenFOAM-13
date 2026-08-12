# alphatJayatillekeWallFunction

## 一句话
高 Re 壁面函数，用近壁解析关联闭合湍流量。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`alphatJayatillekeWallFunction`
- **RTS `TypeName`**：`compressible`::alphatJayatillekeWallFunction`（与字典名不同时以字典 `type` 为准）
- **典型场**：`alpha`.*`, nut / nuTilda, k / epsilon / omega / f / v2, `alphat`
- **库 / 加载**：需 `libthermophysicalTransportModels`（`fluid`、`multicomponentFluid`、CHT 等）
- **前提**：启用 RAS/LES 壁面函数湍流模型；近壁网格满足 y+ 假设。

## 字典示例

```c++
// `tutorials/fluid/BernardCells/0/alphat`
dimensions      [1 -1 -1 0 0 0 0];

internalField   uniform 0;

boundaryField
{
    wall
    {
        type            compressible::alphatJayatillekeWallFunction;
        Prt             0.85;
        value           $internalField;
    }

    #includeEtc "caseDicts/setConstraintTypes"
}


// ************************************************************************* //
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `Prt` | turbulent Prandtl number | no | 0.85 |

## 控制方程与关联式
高 Re 壁面函数，用近壁解析关联闭合湍流量。

类头 `Description` 原文：

> This boundary condition provides a thermal wall function for turbulent
> thermal diffusivity (usually\c alphat) based on the Jayatilleke model.

## 文献与源码依据
- 源码：[`src/ThermophysicalTransportModels/fluid/derivedFvPatchFields/alphatWallFunctions/alphatJayatillekeWallFunction/alphatJayatillekeWallFunctionFvPatchScalarField.C`](../../../src/ThermophysicalTransportModels/fluid/derivedFvPatchFields/alphatWallFunctions/alphatJayatillekeWallFunction/alphatJayatillekeWallFunctionFvPatchScalarField.C)
- 头文件：[`src/ThermophysicalTransportModels/fluid/derivedFvPatchFields/alphatWallFunctions/alphatJayatillekeWallFunction/alphatJayatillekeWallFunctionFvPatchScalarField.H`](../../../src/ThermophysicalTransportModels/fluid/derivedFvPatchFields/alphatWallFunctions/alphatJayatillekeWallFunction/alphatJayatillekeWallFunctionFvPatchScalarField.H)
- Inventory 备注：thermophysical transport BCs

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            alphatJayatillekeWallFunction`。

## 注意事项
- 壁面函数场（`nut`/`k`/`epsilon`/`omega`/`alphat`）需成套配置，勿与低 Re 积分壁面混用。
