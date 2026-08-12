# swirlFlowRateInletVelocity

## 一句话
按指定质量/体积流量或平均速度构造入口速度剖面。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`swirlFlowRateInletVelocity`
- **典型场**：`U`
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
inlet
{
    type            swirlFlowRateInletVelocity;
    origin          (0 0 0);              // [m] 可选，默认 patch 中心
    axis            (0 0 1);              // [-] 可选，默认 patch 法向
    volumetricFlowRate constant 0.2;      // [m^3/s]；或 massFlowRate [kg/s]
    // rho           rho;
    // rhoInlet      1.2;                 // [kg/m^3]
    radialVelocity  constant 10;          // [m/s] Function1(t,r)
    omega           constant 100 [rpm];   // 与 tangentialVelocity 二选一
    // tangentialVelocity constant 5;     // [m/s]
    value           uniform (0 0 0);
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `origin` | Origin of rotation | no | patch centre |
| `axis` | Axis of rotation | no | patch normal |
| `massFlowRate` | Mass flow rate [kg/s] | no |  |
| `volumetricFlowRate` | Volumetric flow rate [m^3/s] | no |  |
| `rho` | Density field name | no | rho |
| `rhoInlet` | Inlet density | no |  |
| `radialVelocity` | Radial velocity [m/s] | yes |  |
| `omega` | Angular velocity of the frame | no |  |
| `tangentialVelocity` | Tangential velocity [m/s] | no |  |

## 控制方程与关联式
按指定质量/体积流量或平均速度构造入口速度剖面。

类头 `Description` 原文：

> Velocity inlet boundary condition creating a normal velocity field to match
> the specified mass or volumetric flow rate, and radial and tangential
> velocity fields specified by functions of time and radius or by a given
> angular speed.
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
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/swirlFlowRateInletVelocity/swirlFlowRateInletVelocityFvPatchVectorField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/swirlFlowRateInletVelocity/swirlFlowRateInletVelocityFvPatchVectorField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/swirlFlowRateInletVelocity/swirlFlowRateInletVelocityFvPatchVectorField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/swirlFlowRateInletVelocity/swirlFlowRateInletVelocityFvPatchVectorField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            swirlFlowRateInletVelocity`。

## 注意事项
- - rhoInlet is required for the case of a mass flow rate, where the     density field is not available at start-up   - The value is positive into the domain (as an inlet)   - May not work correctly for transonic inlets   - Strange behaviour with potentialFoam since the U equation is not solved
