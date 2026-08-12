# turbulentInlet

## 一句话
湍流入口类边界条件 `turbulentInlet`。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`turbulentInlet`
- **典型场**：见源码 / 场量纲匹配
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            turbulentInlet;
    fluctuationScale 0.1;
    referenceField  uniform 10;
    alpha           0.1;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `fluctuationScale` | RMS fluctuation scale (fraction of mean) | yes |  |
| `referenceField` | reference (mean) field | yes |  |
| `alpha` | fraction of new random component added to previous | no | 0.1 |

## 控制方程与关联式
湍流入口类边界条件 `turbulentInlet`。

类头 `Description` 原文：

> This boundary condition generates a fluctuating inlet condition by adding
> a random component to a reference (mean) field.
> 
> $$
>     x_p = (1 - \alpha) x_p^{n-1} + \alpha (x_{ref} + s C_{RMS} x_{ref})
> $$
> 
> where
> 
> 
>     x_p     | patch values
>     x_{ref} | reference patch values
>     n       | time level
>     \alpha  | fraction of new random component added to previous time value
>     C_{RMS} | RMS coefficient
>     s       | fluctuation scale
> 

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/turbulentInlet/turbulentInletFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/turbulentInlet/turbulentInletFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/turbulentInlet/turbulentInletFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/turbulentInlet/turbulentInletFvPatchField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/multiRegion/film/rivuletPanel/0/film/delta`](../../../tutorials/multiRegion/film/rivuletPanel/0/film/delta)
- [`tutorials/multiRegion/film/rivuletBox/0/film/delta`](../../../tutorials/multiRegion/film/rivuletBox/0/film/delta)
- [`tutorials/isothermalFilm/rivuletPanel/0/delta`](../../../tutorials/isothermalFilm/rivuletPanel/0/delta)
- [`tutorials/incompressibleFluid/pitzDailyLES/0/U`](../../../tutorials/incompressibleFluid/pitzDailyLES/0/U)
- [`tutorials/fluid/pitzDaily/0/U`](../../../tutorials/fluid/pitzDaily/0/U)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
