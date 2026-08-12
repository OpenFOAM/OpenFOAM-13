# turbulentMixingLengthFrequencyInlet

## 一句话
用湍流强度与混合长度指定 `omega` 入口。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`turbulentMixingLengthFrequencyInlet`
- **典型场**：k / epsilon / omega / f / v2
- **库 / 加载**：需动量输运库（如 `libmomentumTransportModels` / 相专用库）；通常由启用湍流的求解器链接

## 字典示例
```
<patchName>
{
    type            turbulentMixingLengthFrequencyInlet;
    mixingLength    0.005;
    value           uniform 200;   // placeholder
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `mixingLength` | Length scale [m] | yes |  |
| `phi` | flux field name | no | phi |
| `k` | turbulence kinetic energy field name | no | k |
| `Cmu` | Turbulence model coefficient | no | 0.09 |

## 控制方程与关联式
用湍流强度与混合长度指定 `omega` 入口。

类头 `Description` 原文：

> This boundary condition provides a turbulence specific dissipation,
> $\omega$ (omega) inlet condition based on a specified mixing length.
> The patch values are calculated using:
> 
>     $$
>         \omega_p = \frac{k^{0.5}}{C_{\mu}^{0.25} L}
>     $$
> 
> where
> 
> 
>     \omega_p | patch omega values
>     C_{\mu} | Model coefficient, set to 0.09
>     k       | turbulence kinetic energy
>     L       | length scale
> 

## 文献与源码依据
- 源码：[`src/MomentumTransportModels/momentumTransportModels/RAS/derivedFvPatchFields/turbulentMixingLengthFrequencyInlet/turbulentMixingLengthFrequencyInletFvPatchScalarField.C`](../../../src/MomentumTransportModels/momentumTransportModels/RAS/derivedFvPatchFields/turbulentMixingLengthFrequencyInlet/turbulentMixingLengthFrequencyInletFvPatchScalarField.C)
- 头文件：[`src/MomentumTransportModels/momentumTransportModels/RAS/derivedFvPatchFields/turbulentMixingLengthFrequencyInlet/turbulentMixingLengthFrequencyInletFvPatchScalarField.H`](../../../src/MomentumTransportModels/momentumTransportModels/RAS/derivedFvPatchFields/turbulentMixingLengthFrequencyInlet/turbulentMixingLengthFrequencyInletFvPatchScalarField.H)
- Inventory 备注：momentum transport / wall functions

## 教程与模板
- [`tutorials/XiFluid/engine2Valve2D/0/omega`](../../../tutorials/XiFluid/engine2Valve2D/0/omega)
- [`tutorials/shockFluid/diffuserIntake/0/omega`](../../../tutorials/shockFluid/diffuserIntake/0/omega)
- [`tutorials/multiRegion/CHT/VoFcoolingCylinder2D/0/fluid/omega`](../../../tutorials/multiRegion/CHT/VoFcoolingCylinder2D/0/fluid/omega)
- [`tutorials/multiRegion/CHT/notchedRoller/0/fluid/omega`](../../../tutorials/multiRegion/CHT/notchedRoller/0/fluid/omega)
- [`tutorials/multiRegion/CHT/coolingSphere/templates/0/fluid/omega`](../../../tutorials/multiRegion/CHT/coolingSphere/templates/0/fluid/omega)
- [`tutorials/multiRegion/CHT/coolingCylinder2D/0/fluid/omega`](../../../tutorials/multiRegion/CHT/coolingCylinder2D/0/fluid/omega)

## 注意事项
- In the event of reverse flow, a zero-gradient condition is applied
