# interstitialInletVelocity

## 一句话
按体积分数缩放的相间（空隙）入口速度。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`interstitialInletVelocity`
- **典型场**：`U`
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
inlet
{
    type              interstitialInletVelocity;
    inletVelocity     uniform (0 0.2 0);// Non-interstitial inlet velocity
    alpha             alpha.particles;  // Name of the phase-fraction field
    value             uniform (0 0 0);
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| | *以下关键字自 `.C` 构造函数字典读取推断，完整语义见源码* | | |
| `alpha` | （自构造函数字典读取） | no | "alpha" |

## 控制方程与关联式
按体积分数缩放的相间（空隙）入口速度。

类头 `Description` 原文：

> Inlet velocity in which the actual interstitial velocity is calculated
> by dividing the specified inletVelocity field with the local phase-fraction.
> 
> Example of the boundary condition specification:
> 
> inlet
> {
>     type              interstitialInletVelocity;
>     inletVelocity     uniform (0 0.2 0);// Non-interstitial inlet velocity
>     alpha             alpha.particles;  // Name of the phase-fraction field
>     value             uniform (0 0 0);
> }
> 

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/interstitialInletVelocity/interstitialInletVelocityFvPatchVectorField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/interstitialInletVelocity/interstitialInletVelocityFvPatchVectorField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/interstitialInletVelocity/interstitialInletVelocityFvPatchVectorField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/interstitialInletVelocity/interstitialInletVelocityFvPatchVectorField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/multiphaseEuler/fluidisedBedLaminar/0/U.air`](../../../tutorials/multiphaseEuler/fluidisedBedLaminar/0/U.air)
- [`tutorials/multiphaseEuler/fluidisedBed/0/U.air`](../../../tutorials/multiphaseEuler/fluidisedBed/0/U.air)
- [`tutorials/incompressibleDenseParticleFluid/GoldschmidtMPPIC/0/U.air`](../../../tutorials/incompressibleDenseParticleFluid/GoldschmidtMPPIC/0/U.air)
- [`tutorials/incompressibleDenseParticleFluid/Goldschmidt/0/U.air`](../../../tutorials/incompressibleDenseParticleFluid/Goldschmidt/0/U.air)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
