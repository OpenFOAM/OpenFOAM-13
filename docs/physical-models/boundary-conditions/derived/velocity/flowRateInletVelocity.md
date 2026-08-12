# flowRateInletVelocity

## 一句话
按质量/体积流量或平均速度构造入口法向速度剖面。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`flowRateInletVelocity`
- **典型场**：`U`
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type                flowRateInletVelocity;
    volumetricFlowRate  0.2;
    profile             laminarBL;
}
```

```
<patchName>
{
    type                flowRateInletVelocity;
    massFlowRate        0.2;
    profile             turbulentBL;
    rho                 rho;
    rhoInlet            1.0;
}
```

```
<patchName>
{
    type                flowRateInletVelocity;
    meanVelocity        5;
    profile             turbulentBL;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `massFlowRate` | Mass flow rate [kg/s] | no |  |
| `volumetricFlowRate` | Volumetric flow rate [m^3/s] | no |  |
| `meanVelocity` | Mean velocity [m/s] | no |  |
| `profile` | Velocity profile | no |  |
| `rho` | Density field name | no | rho |
| `rhoInlet` | Inlet density | no |  |
| `alpha` | Volume fraction field name | no |  |

## 控制方程与关联式
按质量/体积流量或平均速度构造入口法向速度剖面。

类头 `Description` 原文：

> Velocity inlet boundary condition creating a velocity field with
> optionally specified profile normal to the patch adjusted to match the
> specified mass flow rate, volumetric flow rate or mean velocity.
> 
> For a mass-based flux:
> - the flow rate should be provided in kg/s
> - if \c rho is "none" the flow rate is in m3/s
> - otherwise \c rho should correspond to the name of the density field
> - if the density field cannot be found in the database, the user must
>   specify the inlet density using the \c rhoInlet entry
> 
> For a volumetric-based flux:
> - the flow rate is in m3/s

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/flowRateInletVelocity/flowRateInletVelocityFvPatchVectorField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/flowRateInletVelocity/flowRateInletVelocityFvPatchVectorField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/flowRateInletVelocity/flowRateInletVelocityFvPatchVectorField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/flowRateInletVelocity/flowRateInletVelocityFvPatchVectorField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/XiFluid/engine2Valve2D/0/U`](../../../tutorials/XiFluid/engine2Valve2D/0/U)
- [`tutorials/multiRegion/CHT/shellAndTubeHeatExchanger/0/shell/U`](../../../tutorials/multiRegion/CHT/shellAndTubeHeatExchanger/0/shell/U)
- [`tutorials/multiRegion/CHT/shellAndTubeHeatExchanger/0/tube/U`](../../../tutorials/multiRegion/CHT/shellAndTubeHeatExchanger/0/tube/U)
- [`tutorials/multiRegion/CHT/coolingSphere/templates/0/fluid/U`](../../../tutorials/multiRegion/CHT/coolingSphere/templates/0/fluid/U)
- [`tutorials/multiphaseEuler/titaniaSynthesisSurface/0/U.vapour`](../../../tutorials/multiphaseEuler/titaniaSynthesisSurface/0/U.vapour)
- [`tutorials/multiphaseEuler/titaniaSynthesis/0/U.vapour`](../../../tutorials/multiphaseEuler/titaniaSynthesis/0/U.vapour)

## 注意事项
- - rhoInlet is required for the case of a mass flow rate, where the     density field is not available at start-up   - The value is positive into the domain (as an inlet)   - May not work correctly for transonic inlets   - Strange behaviour with potentialFoam since the U equation is not solved
