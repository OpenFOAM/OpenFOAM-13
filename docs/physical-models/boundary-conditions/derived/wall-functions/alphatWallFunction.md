# alphatWallFunction

## 一句话
可压缩/热输运 `alphat` 壁面函数。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`alphatWallFunction`
- **RTS `TypeName`**：`compressible`::alphatWallFunction`（与字典名不同时以字典 `type` 为准）
- **典型场**：`alpha`.*`, nut / nuTilda, k / epsilon / omega / f / v2, `alphat`
- **库 / 加载**：需 `libthermophysicalTransportModels`（`fluid`、`multicomponentFluid`、CHT 等）
- **前提**：启用 RAS/LES 壁面函数湍流模型；近壁网格满足 y+ 假设。

## 字典示例
```
<patchName>
{
    type            alphatWallFunction;
    nut             nut;
    Prt             0.85;
    value           uniform 0; // optional value entry
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `nut` | turbulence viscosity field name | no | nut |
| `Prt` | turbulent Prandtl number | no | 0.85 |

## 控制方程与关联式
可压缩/热输运 `alphat` 壁面函数。

类头 `Description` 原文：

> This boundary condition provides a turbulent thermal diffusivity condition
> when using wall functions
> - replicates OpenFOAM v1.5 (and earlier) behaviour
> 
> The turbulent thermal diffusivity calculated using:
> 
>     $$
>         \alpha_t = \frac{\mu_t}{Pr_t}
>     $$
> 
> where
> 
> 
>     \alpha_t| turbulence thermal diffusivity
>     \mu_t   | turbulence viscosity
>     Pr_t    | turblent Prandtl number
> 

## 文献与源码依据
- 源码：[`src/ThermophysicalTransportModels/fluid/derivedFvPatchFields/alphatWallFunctions/alphatWallFunction/alphatWallFunctionFvPatchScalarField.C`](../../../src/ThermophysicalTransportModels/fluid/derivedFvPatchFields/alphatWallFunctions/alphatWallFunction/alphatWallFunctionFvPatchScalarField.C)
- 头文件：[`src/ThermophysicalTransportModels/fluid/derivedFvPatchFields/alphatWallFunctions/alphatWallFunction/alphatWallFunctionFvPatchScalarField.H`](../../../src/ThermophysicalTransportModels/fluid/derivedFvPatchFields/alphatWallFunctions/alphatWallFunction/alphatWallFunctionFvPatchScalarField.H)
- Inventory 备注：thermophysical transport BCs

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            alphatWallFunction`。

## 注意事项
- 壁面函数场（`nut`/`k`/`epsilon`/`omega`/`alphat`）需成套配置，勿与低 Re 积分壁面混用。
