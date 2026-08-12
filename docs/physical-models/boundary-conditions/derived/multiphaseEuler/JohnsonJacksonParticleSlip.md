# JohnsonJacksonParticleSlip

## 一句话
滑移：法向速度约束、切向自由或按比例滑移。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`JohnsonJacksonParticleSlip`
- **典型场**：见源码 / 场量纲匹配
- **库 / 加载**：模块本地：仅 `multiphaseEuler`
- **适用标签**：见库说明；不确定时查求解器 `Make/options`。

## 字典示例
摘录 `tutorials/multiphaseEuler/LBend/0/U.solids`：

```
"wall.*"
{
    type            JohnsonJacksonParticleSlip;
    restitutionCoefficient 0.2;
    specularityCoefficient   0.1;
    muF             0.25;
    sigma           2;
    value           uniform (0 0 0);
}
```

## 参数表
| 参数 | 含义 | 必需 |
|------|------|------|
| `restitutionCoefficient` | 壁面恢复系数 | yes |
| `specularityCoefficient` | 镜面度系数 | yes |
| `muF` | 摩擦相关 | yes（见 ctor） |
| `sigma` | 应力相关 | yes（见 ctor） |
| `value` | 初值 | 常见 |

## 控制方程与关联式
滑移：法向速度约束、切向自由或按比例滑移。

类头 `Description` 原文：

> Partial slip boundary condition for the particulate velocity.
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
- 源码：[`applications/modules/multiphaseEuler/momentumTransportModels/derivedFvPatchFields/JohnsonJacksonParticleSlip/JohnsonJacksonParticleSlipFvPatchVectorField.C`](../../../applications/modules/multiphaseEuler/momentumTransportModels/derivedFvPatchFields/JohnsonJacksonParticleSlip/JohnsonJacksonParticleSlipFvPatchVectorField.C)
- 头文件：[`applications/modules/multiphaseEuler/momentumTransportModels/derivedFvPatchFields/JohnsonJacksonParticleSlip/JohnsonJacksonParticleSlipFvPatchVectorField.H`](../../../applications/modules/multiphaseEuler/momentumTransportModels/derivedFvPatchFields/JohnsonJacksonParticleSlip/JohnsonJacksonParticleSlipFvPatchVectorField.H)
- Inventory 备注：module-local BCs

## 教程与模板
- [`tutorials/multiphaseEuler/LBend/0/U.solids`](../../../tutorials/multiphaseEuler/LBend/0/U.solids)
- [`tutorials/multiphaseEuler/fluidisedBed/0/U.particles`](../../../tutorials/multiphaseEuler/fluidisedBed/0/U.particles)

## 注意事项
- 模块本地 BC：其他 solver 即使同名字段也不会注册该 `type`。
