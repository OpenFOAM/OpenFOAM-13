# multiphaseExternalTemperature

## 一句话
混合（Robin）条件：`valueFraction` 在固定值与固定梯度间插值。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`multiphaseExternalTemperature`
- **典型场**：`T`
- **库 / 加载**：模块本地：仅 `multiphaseEuler`
- **适用标签**：见库说明；不确定时查求解器 `Make/options`。

## 字典示例
摘录 `tutorials/multiphaseEuler/wallBoilingPolydisperse/0/T.liquid`：

```
wall
{
    type            multiphaseExternalTemperature;
    q
    {
        type            scale;
        value           73890;
        scale
        {
            type            linearRamp;
            start           0.5;
            duration        0.01;
        }
    }
    relaxation      0.2;
    value           $internalField;
}
```

## 参数表
| 参数 | 含义 | 必需 |
|------|------|------|
| `q` | 热通量 Function1 / 字典 | 常见 |
| `relaxation` | 松弛因子 | 可选 |
| `value` | 初值 | 常见 |

## 控制方程与关联式
混合（Robin）条件：`valueFraction` 在固定值与固定梯度间插值。

类头 `Description` 原文：

> Mixed boundary condition for the phase temperature of a phase in an
> Euler-Euler multiphase simulation, to be used for heat-transfer with another
> region in a CHT case.  Optional thin wall material layer resistances can be
> specified through thicknessLayers and kappaLayers entries.

## 文献与源码依据
- 源码：[`applications/modules/multiphaseEuler/thermophysicalTransportModels/derivedFvPatchFields/multiphaseExternalTemperature/multiphaseExternalTemperatureFvPatchScalarField.C`](../../../applications/modules/multiphaseEuler/thermophysicalTransportModels/derivedFvPatchFields/multiphaseExternalTemperature/multiphaseExternalTemperatureFvPatchScalarField.C)
- 头文件：[`applications/modules/multiphaseEuler/thermophysicalTransportModels/derivedFvPatchFields/multiphaseExternalTemperature/multiphaseExternalTemperatureFvPatchScalarField.H`](../../../applications/modules/multiphaseEuler/thermophysicalTransportModels/derivedFvPatchFields/multiphaseExternalTemperature/multiphaseExternalTemperatureFvPatchScalarField.H)
- Inventory 备注：module-local BCs

## 教程与模板
- [`tutorials/multiphaseEuler/wallBoilingPolydisperseTwoGroups/0/T.gas`](../../../tutorials/multiphaseEuler/wallBoilingPolydisperseTwoGroups/0/T.gas)
- [`tutorials/multiphaseEuler/wallBoilingPolydisperseTwoGroups/0/T.gas2`](../../../tutorials/multiphaseEuler/wallBoilingPolydisperseTwoGroups/0/T.gas2)
- [`tutorials/multiphaseEuler/wallBoilingPolydisperseTwoGroups/0/T.liquid`](../../../tutorials/multiphaseEuler/wallBoilingPolydisperseTwoGroups/0/T.liquid)
- [`tutorials/multiphaseEuler/wallBoilingPolydisperse/0/T.gas`](../../../tutorials/multiphaseEuler/wallBoilingPolydisperse/0/T.gas)
- [`tutorials/multiphaseEuler/wallBoilingPolydisperse/0/T.liquid`](../../../tutorials/multiphaseEuler/wallBoilingPolydisperse/0/T.liquid)
- [`tutorials/multiphaseEuler/wallBoilingIATE/0/T.gas`](../../../tutorials/multiphaseEuler/wallBoilingIATE/0/T.gas)

## 注意事项
- 模块本地 BC：其他 solver 即使同名字段也不会注册该 `type`。
