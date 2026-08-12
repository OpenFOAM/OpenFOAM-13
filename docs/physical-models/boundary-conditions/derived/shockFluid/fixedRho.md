# fixedRho

## 一句话
shockFluid：按压力/温度EOS或固定值设置密度边界。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`fixedRho`
- **典型场**：`rho`
- **库 / 加载**：模块本地：仅 `shockFluid` 求解器链接
- **适用标签**：见库说明；不确定时查求解器 `Make/options`。

## 字典示例
```
<patchName>
{
    type            fixedRho;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `p` | Pressure field name | no | p |
| `psi` | Compressibility field name | no | psi |

## 控制方程与关联式
shockFluid：按压力/温度EOS或固定值设置密度边界。

类头 `Description` 原文：

> Foam::fixedRhoFvPatchScalarField
> 
> This boundary condition provides a fixed density inlet condition for
> compressible solvers, where the density of calculated using:
> 
> $$
>     \rho = \psi p
> $$
> 
> where
> 
>     p     | pressure [Pa]
>     \rho  | density [kg/m^3]
> 

## 文献与源码依据
- 源码：[`applications/modules/shockFluid/derivedFvPatchFields/rho/fixedRhoFvPatchScalarField.C`](../../../applications/modules/shockFluid/derivedFvPatchFields/rho/fixedRhoFvPatchScalarField.C)
- 头文件：[`applications/modules/shockFluid/derivedFvPatchFields/rho/fixedRhoFvPatchScalarField.H`](../../../applications/modules/shockFluid/derivedFvPatchFields/rho/fixedRhoFvPatchScalarField.H)
- Inventory 备注：shockFluid module BCs

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            fixedRho`。

## 注意事项
- 模块本地 BC：其他 solver 即使同名字段也不会注册该 `type`。
