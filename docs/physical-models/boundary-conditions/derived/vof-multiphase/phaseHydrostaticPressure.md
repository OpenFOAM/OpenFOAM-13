# phaseHydrostaticPressure

## 一句话
零梯度（Neumann）：边界法向梯度为零。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`phaseHydrostaticPressure`
- **典型场**：p / p_rgh, `alpha`.*`
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            phaseHydrostaticPressure;
    phaseFraction   alpha1;
    rho             rho;
    pRefValue       1e5;
    pRefPoint       (0 0 0);
    value           uniform 0; // optional initial value
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `phaseFraction` | phase-fraction field name | no | alpha |
| `rho` | density field name | no | rho |
| `pRefValue` | reference pressure [Pa] | yes |  |
| `pRefPoint` | reference pressure location | yes |  |

## 控制方程与关联式
零梯度（Neumann）：边界法向梯度为零。

类头 `Description` 原文：

> This boundary condition provides a phase-based hydrostatic pressure
> condition, calculated as:
> 
>     $$
>         p_{hyd} = p_{ref} + \rho g (x - x_{ref})
>     $$
> 
> where
> 
>     p_{hyd} | hyrostatic pressure [Pa]
>     p_{ref} | reference pressure [Pa]
>     x_{ref} | reference point in Cartesian co-ordinates
>     \rho    | density (assumed uniform)
>     g       | acceleration due to gravity [m/s^2]
> \endtable
> 
> The values are assigned according to the phase-fraction field:
> - 1: apply \$fp_{hyd}\$f
> - 0: apply a zero-gradient condition

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/phaseHydrostaticPressure/phaseHydrostaticPressureFvPatchScalarField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/phaseHydrostaticPressure/phaseHydrostaticPressureFvPatchScalarField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/phaseHydrostaticPressure/phaseHydrostaticPressureFvPatchScalarField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/phaseHydrostaticPressure/phaseHydrostaticPressureFvPatchScalarField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            phaseHydrostaticPressure`。

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
