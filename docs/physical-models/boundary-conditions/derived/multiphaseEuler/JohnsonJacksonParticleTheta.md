# JohnsonJacksonParticleTheta

## 一句话
温度相关边界条件。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`JohnsonJacksonParticleTheta`
- **典型场**：Theta (granular)
- **库 / 加载**：模块本地：仅 `multiphaseEuler`
- **适用标签**：见库说明；不确定时查求解器 `Make/options`。

## 字典示例
摘录 `tutorials/multiphaseEuler/fluidisedBed/0/Theta.particles`：

```
walls
{
    type            JohnsonJacksonParticleTheta;
    restitutionCoefficient 0.8;
    specularityCoefficient 0.01;
    value           uniform 1e-4;
}
```

## 参数表
| 参数 | 含义 | 必需 |
|------|------|------|
| `restitutionCoefficient` | 壁面恢复系数 | yes |
| `specularityCoefficient` | 镜面度系数 | yes |
| `value` | 初值 | 常见 |

## 控制方程与关联式
温度相关边界条件。

类头 `Description` 原文：

> Robin condition for the particulate granular temperature.
> 
> References:
> 
>     Reuge, N., Cadoret, L., Coufort-Saudejaud, C., Pannala, S., Syamlal, M.,
>     & Caussat, B. (2008).
>     Multifluid Eulerian modeling of dense gas–solids fluidised bed
>     hydrodynamics: influence of the dissipation parameters.
>     Chemical Engineering Science, 63(22), 5540-5551.
> 
> 
> 
>     Johnson, P. C., & Jackson, R. (1987).
>     Frictional–collisional constitutive relations for granular materials,
>     with application to plane shearing.
>     Journal of fluid Mechanics, 176, 67-93.
> 

## 文献与源码依据
- 源码：[`applications/modules/multiphaseEuler/momentumTransportModels/derivedFvPatchFields/JohnsonJacksonParticleTheta/JohnsonJacksonParticleThetaFvPatchScalarField.C`](../../../applications/modules/multiphaseEuler/momentumTransportModels/derivedFvPatchFields/JohnsonJacksonParticleTheta/JohnsonJacksonParticleThetaFvPatchScalarField.C)
- 头文件：[`applications/modules/multiphaseEuler/momentumTransportModels/derivedFvPatchFields/JohnsonJacksonParticleTheta/JohnsonJacksonParticleThetaFvPatchScalarField.H`](../../../applications/modules/multiphaseEuler/momentumTransportModels/derivedFvPatchFields/JohnsonJacksonParticleTheta/JohnsonJacksonParticleThetaFvPatchScalarField.H)
- Inventory 备注：module-local BCs

## 教程与模板
- [`tutorials/multiphaseEuler/LBend/0/Theta.solids`](../../../tutorials/multiphaseEuler/LBend/0/Theta.solids)
- [`tutorials/multiphaseEuler/fluidisedBed/0/Theta.particles`](../../../tutorials/multiphaseEuler/fluidisedBed/0/Theta.particles)

## 注意事项
- 模块本地 BC：其他 solver 即使同名字段也不会注册该 `type`。
