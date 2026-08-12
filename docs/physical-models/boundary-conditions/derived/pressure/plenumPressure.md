# plenumPressure

## 一句话
零维上游气室压力入口：以供给质量流与气室状态驱动边界压力。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`plenumPressure`
- **典型场**：p / p_rgh
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例

摘自 `tutorials/fluid/helmholtzResonance/0/p`（支持带单位字面量）：

```cpp
plenum
{
    type            plenumPressure;
    gamma           1.4;                  // [-] Cp/Cv
    R               287.04;               // [J/kg/K]
    supplyMassFlowRate 0.1 [g/s];         // [kg/s]
    supplyTotalTemperature 300;           // [K]
    plenumVolume    0.125 [l];            // [m^3]
    plenumDensity   1.1613;               // [kg/m^3]
    plenumTemperature 300;                // [K]
    inletAreaRatio  100 [%];              // [-]
    inletDischargeCoefficient 80 [%];     // [-]
    timeScale       1e-4;                 // [s]
    // 可选: U phi rho（场名）
    value           $internalField;       // [Pa]
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `gamma` | ratio of specific heats | yes | none |
| `R` | specific gas constant | yes | none |
| `supplyMassFlowRate` | flow rate into the plenum | yes | none |
| `supplyTotalTemperature` | temperature into the plenum | yes | none |
| `plenumVolume` | plenum volume | yes | none |
| `plenumDensity` | plenum density | yes | none |
| `plenumTemperature` | plenum temperature | yes | none |
| `U` | velocity field name | no | U |
| `phi` | flux field name | no | phi |
| `rho` | inlet density | no | none |
| `inletAreaRatio` | inlet open fraction | yes | none |
| `inletDischargeCoefficient` | inlet loss coefficient | yes | none |
| `timeScale` | relaxation time scale | yes | none |

## 控制方程与关联式
按指定质量/体积流量或平均速度构造入口速度剖面。

类头 `Description` 原文：

> This boundary condition provides a plenum pressure inlet condition. This
> condition creates a zero-dimensional model of an enclosed volume of gas
> upstream of the inlet. The pressure that the boundary condition exerts on
> the inlet boundary is dependent on the thermodynamic state of the upstream
> volume. The upstream plenum density and temperature are time-stepped along
> with the rest of the simulation, and momentum is neglected. The plenum is
> supplied with a user specified mass flow and temperature.
> 
> The result is a boundary condition which blends between a pressure inlet
> condition condition and a fixed mass flow. The smaller the plenum
> volume, the quicker the pressure responds to a deviation from the supply
> mass flow, and the closer the model approximates a fixed mass flow. As
> the plenum size increases, the model becomes more similar to a specified
> pressure.
> 
> The expansion from the plenum to the inlet boundary is controlled by an
> area ratio and a discharge coefficient. The area ratio can be used to
> represent further acceleration between a sub-grid blockage such as fins.
> The discharge coefficient represents a fractional deviation from an
> ideal expansion process.
> 
> This condition is useful for simulating unsteady internal flow problems
> for which both a mass flow boundary is unrealistic, and a pressure
> boundary is susceptible to flow reversal. It was developed for use in
> simulating confined combustion.
> 
> Reference:
> 
>     Bainbridge, W. (2013).
>     The Numerical Simulation of Oscillations in Gas Turbine Combustion
>     Chambers,
>     PhD Thesis,
>     Chapter 4, Section 4.3.1.2, 77-80.
> 

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/plenumPressure/plenumPressureFvPatchScalarField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/plenumPressure/plenumPressureFvPatchScalarField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/plenumPressure/plenumPressureFvPatchScalarField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/plenumPressure/plenumPressureFvPatchScalarField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/fluid/helmholtzResonance/0/p`](../../../tutorials/fluid/helmholtzResonance/0/p)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
