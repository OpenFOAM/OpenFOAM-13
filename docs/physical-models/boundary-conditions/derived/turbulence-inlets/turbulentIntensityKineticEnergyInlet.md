# turbulentIntensityKineticEnergyInlet

## 一句话
零梯度（Neumann）：边界法向梯度为零。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`turbulentIntensityKineticEnergyInlet`
- **典型场**：h / e / ha / ea, k / epsilon / omega / f / v2
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type        turbulentIntensityKineticEnergyInlet;
    intensity   0.05;           // 5% turbulence
    value       uniform 1;      // placeholder
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `intensity` | fraction of mean field [0-1] | yes |  |
| `U` | velocity field name | no | U |
| `phi` | flux field name | no | phi |

## 控制方程与关联式
零梯度（Neumann）：边界法向梯度为零。

类头 `Description` 原文：

> This boundary condition provides a turbulent kinetic energy condition,
> based on user-supplied turbulence intensity, defined as a fraction of the
> mean velocity:
> 
>     $$
>         k_p = 1.5 (I |U|)^2
>     $$
> 
> where
> 
> 
>     k_p     | kinetic energy at the patch
>     I       | turbulence intensity
>     U       | velocity field
> 
> 
> In the event of reverse flow, a zero-gradient condition is applied.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/turbulentIntensityKineticEnergyInlet/turbulentIntensityKineticEnergyInletFvPatchScalarField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/turbulentIntensityKineticEnergyInlet/turbulentIntensityKineticEnergyInletFvPatchScalarField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/turbulentIntensityKineticEnergyInlet/turbulentIntensityKineticEnergyInletFvPatchScalarField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/turbulentIntensityKineticEnergyInlet/turbulentIntensityKineticEnergyInletFvPatchScalarField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/XiFluid/engine2Valve2D/0/k`](../../../tutorials/XiFluid/engine2Valve2D/0/k)
- [`tutorials/shockFluid/diffuserIntake/0/k`](../../../tutorials/shockFluid/diffuserIntake/0/k)
- [`tutorials/multiRegion/CHT/VoFcoolingCylinder2D/0/fluid/k`](../../../tutorials/multiRegion/CHT/VoFcoolingCylinder2D/0/fluid/k)
- [`tutorials/multiRegion/CHT/shellAndTubeHeatExchanger/0/shell/k`](../../../tutorials/multiRegion/CHT/shellAndTubeHeatExchanger/0/shell/k)
- [`tutorials/multiRegion/CHT/shellAndTubeHeatExchanger/0/tube/k`](../../../tutorials/multiRegion/CHT/shellAndTubeHeatExchanger/0/tube/k)
- [`tutorials/multiRegion/CHT/reverseBurner/0/gas/k`](../../../tutorials/multiRegion/CHT/reverseBurner/0/gas/k)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
