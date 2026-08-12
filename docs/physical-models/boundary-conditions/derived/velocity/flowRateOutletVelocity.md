# flowRateOutletVelocity

## 一句话
按指定质量/体积流量或平均速度构造入口速度剖面。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`flowRateOutletVelocity`
- **典型场**：`U`
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type                flowRateOutletVelocity;
    volumetricFlowRate  0.2;
    value               uniform (0 0 0);
}
```

```
<patchName>
{
    type                flowRateOutletVelocity;
    massFlowRate        0.2;
    rhoOutlet           1.0;
    value               uniform (0 0 0);
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `massFlowRate` | Mass flow rate [kg/s] | no |  |
| `volumetricFlowRate` | Volumetric flow rate [m^3/s] | no |  |
| `rho` | Density field name | no | rho |
| `rhoOutlet` | Outlet density | no |  |

## 控制方程与关联式
按指定质量/体积流量或平均速度构造入口速度剖面。

类头 `Description` 原文：

> Velocity outlet boundary condition which corrects the extrapolated velocity
> to match the specified flow rate.
> 
> For a mass-based flux:
> - the flow rate should be provided in kg/s
> - if \c rho is "none" the flow rate is in m^3/s
> - otherwise \c rho should correspond to the name of the density field
> - if the density field cannot be found in the database, the user must
>   specify the outlet density using the \c rhoOutlet entry
> 
> For a volumetric-based flux:
> - the flow rate is in m^3/s

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/flowRateOutletVelocity/flowRateOutletVelocityFvPatchVectorField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/flowRateOutletVelocity/flowRateOutletVelocityFvPatchVectorField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/flowRateOutletVelocity/flowRateOutletVelocityFvPatchVectorField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/flowRateOutletVelocity/flowRateOutletVelocityFvPatchVectorField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/multiRegion/film/VoFToFilm/0/VoF/U`](../../../tutorials/multiRegion/film/VoFToFilm/0/VoF/U)

## 注意事项
- - rhoOutlet is required for the case of a mass flow rate, where the     density field is not available at start-up   - The value is positive out of the domain (as an outlet)   - May not work correctly for transonic outlets   - Strange behaviour with potentialFoam since the U equation is not solved
