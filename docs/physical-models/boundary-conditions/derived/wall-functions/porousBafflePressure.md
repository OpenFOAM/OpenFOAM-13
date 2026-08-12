# porousBafflePressure

## 一句话
周期/循环配对边界。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`porousBafflePressure`
- **典型场**：p / p_rgh
- **库 / 加载**：需动量输运库（如 `libmomentumTransportModels` / 相专用库）；通常由启用湍流的求解器链接
- **前提**：启用 RAS/LES 壁面函数湍流模型；近壁网格满足 y+ 假设。

## 字典示例
```
baffle
{
    type            porousBafflePressure;
    patchType       cyclic;
    D               0.001;     // Darcy 系数 [与实现量纲一致]
    I               1e6;       // 惯性系数
    length          0.1;       // [m] 流向多孔长度
    relaxation      0.2;       // [-] 压跳松弛，默认 1
    // phi           phi;
    // rho           rho;
    value           uniform 0;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `patchType` | underlying patch type (should be \c cyclic) | yes |  |
| `phi` | flux field name | no | phi |
| `rho` | density field name | no | rho |
| `D` | Darcy coefficient | yes |  |
| `I` | inertial coefficient | yes |  |
| `length` | porous media length in the flow direction | yes |  |
| `relaxation` | relaxation factor for pressure jump | no | 1 |

## 控制方程与关联式
周期/循环配对边界。

类头 `Description` 原文：

> This boundary condition provides a porous baffle pressure jump condition,
> using the \c cyclic condition as a base. The jump in pressure is defined
> by:
> 
>     $$
>         \Delta p = -(D \mu U + 0.5 I \rho |U|^2 )L
>     $$
> 
> where
> 
> 
>     p      | pressure [Pa]
>     \rho   | density [kg/m^3]
>     \mu    | laminar viscosity [Pa s]
>     D      | Darcy coefficient
>     I      | inertial coefficient
>     L      | porous media length in the flow direction
> 

## 文献与源码依据
- 源码：[`src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/porousBafflePressure/porousBafflePressureFvPatchField.C`](../../../src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/porousBafflePressure/porousBafflePressureFvPatchField.C)
- 头文件：[`src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/porousBafflePressure/porousBafflePressureFvPatchField.H`](../../../src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/porousBafflePressure/porousBafflePressureFvPatchField.H)
- Inventory 备注：momentum transport / wall functions

## 教程与模板
- [`tutorials/incompressibleVoF/damBreakPorousBaffle/system/createBafflesDict`](../../../tutorials/incompressibleVoF/damBreakPorousBaffle/system/createBafflesDict)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
