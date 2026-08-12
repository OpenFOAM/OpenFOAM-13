# multiphaseCoupledTemperature

## 一句话
混合（Robin）条件：`valueFraction` 在固定值与固定梯度间插值。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`multiphaseCoupledTemperature`
- **典型场**：`T`
- **库 / 加载**：模块本地：仅 `multiphaseEuler`
- **适用标签**：见库说明；不确定时查求解器 `Make/options`。

## 字典示例
摘录 `tutorials/multiRegion/CHT/wallBoiling/0/fluid/T.liquid`：

```
wall
{
    type            multiphaseCoupledTemperature;
    value           $internalField;
}
```

可选薄壁层（头文件 Description）：`thicknessLayers` / `kappaLayers`。

## 参数表
| 参数 | 含义 | 必需 |
|------|------|------|
| `value` | 初值 | 常见 |
| `thicknessLayers` | 薄壁厚度列表 | 可选 |
| `kappaLayers` | 薄壁导热列表 | 可选 |

## 控制方程与关联式
混合（Robin）条件：`valueFraction` 在固定值与固定梯度间插值。

类头 `Description` 原文：

> Mixed boundary condition for the phase temperature of a phase in an
> Euler-Euler multiphase simulation, to be used for heat-transfer with another
> region in a CHT case.  Optional thin wall material layer resistances can be
> specified through thicknessLayers and kappaLayers entries.

## 文献与源码依据
- 源码：[`applications/modules/multiphaseEuler/thermophysicalTransportModels/derivedFvPatchFields/multiphaseCoupledTemperature/multiphaseCoupledTemperatureFvPatchScalarField.C`](../../../applications/modules/multiphaseEuler/thermophysicalTransportModels/derivedFvPatchFields/multiphaseCoupledTemperature/multiphaseCoupledTemperatureFvPatchScalarField.C)
- 头文件：[`applications/modules/multiphaseEuler/thermophysicalTransportModels/derivedFvPatchFields/multiphaseCoupledTemperature/multiphaseCoupledTemperatureFvPatchScalarField.H`](../../../applications/modules/multiphaseEuler/thermophysicalTransportModels/derivedFvPatchFields/multiphaseCoupledTemperature/multiphaseCoupledTemperatureFvPatchScalarField.H)
- Inventory 备注：module-local BCs

## 教程与模板
- [`tutorials/multiRegion/CHT/wallBoiling/0/fluid/T.gas`](../../../tutorials/multiRegion/CHT/wallBoiling/0/fluid/T.gas)
- [`tutorials/multiRegion/CHT/wallBoiling/0/fluid/T.liquid`](../../../tutorials/multiRegion/CHT/wallBoiling/0/fluid/T.liquid)
- [`tutorials/multiRegion/CHT/multiphaseCoolingCylinder2D/0/fluid/T.oil`](../../../tutorials/multiRegion/CHT/multiphaseCoolingCylinder2D/0/fluid/T.oil)
- [`tutorials/multiRegion/CHT/multiphaseCoolingCylinder2D/0/fluid/T.water`](../../../tutorials/multiRegion/CHT/multiphaseCoolingCylinder2D/0/fluid/T.water)

## 注意事项
- 模块本地 BC：其他 solver 即使同名字段也不会注册该 `type`。
