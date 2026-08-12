# outletPhaseMeanVelocity

## 一句话
按指定质量/体积流量或平均速度构造入口速度剖面。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`outletPhaseMeanVelocity`
- **典型场**：`U`
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            outletPhaseMeanVelocity;
    UnMean          1.2;
    alpha           alpha.water;
    value           uniform (1.2 0 0);
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `UnMean` | mean velocity normal to the boundary [m/s] | yes |  |
| `alpha` | phase-fraction field | yes |  |

## 控制方程与关联式
按指定质量/体积流量或平均速度构造入口速度剖面。

类头 `Description` 原文：

> This boundary condition adjusts the velocity for the given phase to achieve
> the specified mean thus causing the phase-fraction to adjust according to
> the mass flow rate.
> 
> Typical usage is as the outlet condition for a towing-tank ship simulation
> to maintain the outlet water level at the level as the inlet.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/outletPhaseMeanVelocity/outletPhaseMeanVelocityFvPatchVectorField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/outletPhaseMeanVelocity/outletPhaseMeanVelocityFvPatchVectorField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/outletPhaseMeanVelocity/outletPhaseMeanVelocityFvPatchVectorField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/outletPhaseMeanVelocity/outletPhaseMeanVelocityFvPatchVectorField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/incompressibleVoF/wave/0/U.orig`](../../../tutorials/incompressibleVoF/wave/0/U.orig)
- [`tutorials/incompressibleVoF/rotatingCube/0/U`](../../../tutorials/incompressibleVoF/rotatingCube/0/U)
- [`tutorials/incompressibleVoF/planingHullW3/0/U`](../../../tutorials/incompressibleVoF/planingHullW3/0/U)
- [`tutorials/incompressibleVoF/forcedUpstreamWave/0/U.orig`](../../../tutorials/incompressibleVoF/forcedUpstreamWave/0/U.orig)
- [`tutorials/incompressibleVoF/DTCHullWave/0/U.orig`](../../../tutorials/incompressibleVoF/DTCHullWave/0/U.orig)
- [`tutorials/incompressibleVoF/DTCHullMoving/0/U.orig`](../../../tutorials/incompressibleVoF/DTCHullMoving/0/U.orig)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
