# externalTemperature

## 一句话
温度相关边界条件。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`externalTemperature`
- **典型场**：`T`
- **库 / 加载**：需 `libthermophysicalTransportModels`（`fluid`、`multicomponentFluid`、CHT 等）

## 字典示例

对流换热模式（`h` + `Ta`），摘自 `tutorials/fluid/roomHeating/0/T`：

```cpp
glass
{
    type            externalTemperature;
    Ta              constant 270;  // [K] Function1
    h               uniform 8;     // [W/m^2/K]
    value           uniform 270;   // [K]
}
```

固定热流 / 功率 / 薄层热阻（源码可选关键字）：

```cpp
wall
{
    type            externalTemperature;
    // 任选其一：Q [W] 或 q [W/m^2]；可与 h/Ta 叠加
    q               constant 1000; // [W/m^2]
    // h / Ta 可选
    thicknessLayers (0.01);        // [m]
    kappaLayers     (0.2);         // [W/m/K]
    emissivity      0;             // [-] 默认 0
    // qr / qrRelaxation / relaxation 可选
    value           $internalField;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `Q` | Power [W] | no |  |
| `q` | Heat flux [W/m^2] | no |  |
| `h` | Heat transfer coefficient [W/m^2/K] | no |  |
| `Ta` | Ambient temperature [K] | if h is given |  |
| `thicknessLayers` | Layer thicknesses [m] | no |  |
| `kappaLayers` | Layer thermal conductivities [W/m/K] | no |  |
| `relaxation` | Relaxation for the wall temperature | no | 1 |
| `emissivity` | Surface emissivity for radiative flux to ambient | no | 0 |
| `qr` | Name of the radiative field | no | none |
| `qrRelaxation` | Relaxation factor for radiative field | no | 1 |

## 控制方程与关联式
温度相关边界条件。

类头 `Description` 原文：

> This boundary condition applies a heat flux condition to temperature
> on an external wall. Heat flux can be specified in the following ways:
> 
>   - Fixed power: requires \c Q
>   - Fixed heat flux: requires \c q
>   - Fixed heat transfer coefficient: requires \c h and \c Ta
> 
> where:
> 
>     Q  | Power Function1 of time [W]
>     q  | Heat flux Function1 of time [W/m^2]
>     h  | Heat transfer coefficient Function1 of time [W/m^2/K]
>     Ta | Ambient temperature Function1 of time [K]
> 
> 
> Only one of \c Q or \c q may be specified, if \c h and \c Ta are also
> specified the corresponding heat-flux is added.
> 
> If the heat transfer coefficient \c h is specified an optional thin thermal
> layer resistances can also be specified through thicknessLayers and
> kappaLayers entries.
> 
> The patch thermal conductivity \c kappa is obtained from the region
> thermophysicalTransportModel so that this boundary condition can be applied
> directly to either fluid or solid regions.

## 文献与源码依据
- 源码：[`src/ThermophysicalTransportModels/coupledThermophysicalTransportModels/externalTemperature/externalTemperatureFvPatchScalarField.C`](../../../src/ThermophysicalTransportModels/coupledThermophysicalTransportModels/externalTemperature/externalTemperatureFvPatchScalarField.C)
- 头文件：[`src/ThermophysicalTransportModels/coupledThermophysicalTransportModels/externalTemperature/externalTemperatureFvPatchScalarField.H`](../../../src/ThermophysicalTransportModels/coupledThermophysicalTransportModels/externalTemperature/externalTemperatureFvPatchScalarField.H)
- Inventory 备注：thermophysical transport BCs

## 教程与模板
- [`tutorials/multiRegion/CHT/wallBoiling/0/solid/T`](../../../tutorials/multiRegion/CHT/wallBoiling/0/solid/T)
- [`tutorials/multiRegion/CHT/reverseBurner/0/solid/T`](../../../tutorials/multiRegion/CHT/reverseBurner/0/solid/T)
- [`tutorials/multiRegion/CHT/notchedRoller/0/solid/T`](../../../tutorials/multiRegion/CHT/notchedRoller/0/solid/T)
- [`tutorials/multiRegion/CHT/misalignedDuct/0/solid/T.orig`](../../../tutorials/multiRegion/CHT/misalignedDuct/0/solid/T.orig)
- [`tutorials/fluid/roomHeating/0/T`](../../../tutorials/fluid/roomHeating/0/T)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
