# coupledTemperature

## 一句话
混合（Robin）条件：`valueFraction` 在固定值与固定梯度间插值。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`coupledTemperature`
- **典型场**：`T`
- **库 / 加载**：需 `libthermophysicalTransportModels`（`fluid`、`multicomponentFluid`、CHT 等）

## 字典示例
```
<patchName>
{
    type            coupledTemperature;
    thicknessLayers (0.1 0.2 0.3 0.4); // Optional wall layer thicknesses
    kappaLayers     (1 2 3 4); // Optional wall layer conductivities
    qs              uniform 100;    // Optional source heat flux [W/m^2]
    value           uniform 300;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `Tnbr` | name of the field | no | T |
| `thicknessLayers` | list of thicknesses per layer [m] | no |  |
| `kappaLayers` | list of thermal conductivities per layer [W/m/K] | no |  |
| `qs` | Optional source heat flux [W/m^2] | no | 0 |
| `Qs` | Optional heat source [W] | no | 0 |
| `qrNbr` | name of the radiative flux in the nbr region | no | none |
| `qr` | name of the radiative flux in this region | no | none |

## 控制方程与关联式
混合（Robin）条件：`valueFraction` 在固定值与固定梯度间插值。

类头 `Description` 原文：

> Mixed boundary condition for temperature, to be used for heat-transfer
> with another region in a CHT case.  Optional thin wall material layer
> resistances can be specified through thicknessLayers and kappaLayers
> entries.
> 
> Specifies gradient and temperature such that the equations are the same
> on both sides:
>   - refGradient = qs_/kappa
>   - refValue = neighbour value
>   - valueFraction = kappaByDeltaNbr/(kappaByDeltaNbr + kappaByDelta)
> 
> where kappaByDelta is heat-transfer coefficient kappa*deltaCoeffs
> and qs is the optional source heat flux.

## 文献与源码依据
- 源码：[`src/ThermophysicalTransportModels/coupledThermophysicalTransportModels/coupledTemperature/coupledTemperatureFvPatchScalarField.C`](../../../src/ThermophysicalTransportModels/coupledThermophysicalTransportModels/coupledTemperature/coupledTemperatureFvPatchScalarField.C)
- 头文件：[`src/ThermophysicalTransportModels/coupledThermophysicalTransportModels/coupledTemperature/coupledTemperatureFvPatchScalarField.H`](../../../src/ThermophysicalTransportModels/coupledThermophysicalTransportModels/coupledTemperature/coupledTemperatureFvPatchScalarField.H)
- Inventory 备注：thermophysical transport BCs

## 教程与模板
- [`tutorials/multiRegion/film/VoFToFilm/0/film/T`](../../../tutorials/multiRegion/film/VoFToFilm/0/film/T)
- [`tutorials/multiRegion/film/VoFToFilm/0/VoF/T`](../../../tutorials/multiRegion/film/VoFToFilm/0/VoF/T)
- [`tutorials/multiRegion/film/splashPanel/0/film/T`](../../../tutorials/multiRegion/film/splashPanel/0/film/T)
- [`tutorials/multiRegion/film/splashPanel/0/fluid/T`](../../../tutorials/multiRegion/film/splashPanel/0/fluid/T)
- [`tutorials/multiRegion/film/rivuletPanel/0/film/T`](../../../tutorials/multiRegion/film/rivuletPanel/0/film/T)
- [`tutorials/multiRegion/film/rivuletPanel/0/panel/T`](../../../tutorials/multiRegion/film/rivuletPanel/0/panel/T)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
