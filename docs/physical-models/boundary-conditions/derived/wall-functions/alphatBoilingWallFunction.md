# alphatBoilingWallFunction

## 一句话
高 Re 壁面函数，用近壁解析关联闭合湍流量。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`alphatBoilingWallFunction`
- **典型场**：`alpha`.*`, nut / nuTilda, k / epsilon / omega / f / v2, `alphat`
- **库 / 加载**：模块本地：仅 `multiphaseEuler`
- **前提**：启用 RAS/LES 壁面函数湍流模型；近壁网格满足 y+ 假设。

## 字典示例
```
<patchType>
{
    type            alphatBoilingWallFunction;
    libs            ("libmultiphaseEulerFvModels.so");
    value           uniform 0;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| | *以下关键字自 `.C` 构造函数字典读取推断，完整语义见源码* | | |
| `model` | （自构造函数字典读取） | no | word::null |

## 控制方程与关联式
高 Re 壁面函数，用近壁解析关联闭合湍流量。

类头 `Description` 原文：

> This boundary condition provides a thermal wall function or the turbulent
> thermal diffusivity for walls on which a wall boiling fvModel is in
> operation. The controls for the boiling model are not specified in this
> condition; they are provided to the wall boiling fvModel. The presence of
> this condition is used, however, to determine on which walls boiling takes
> place.

## 文献与源码依据
- 源码：[`applications/modules/multiphaseEuler/fvModels/wallBoiling/alphatBoilingWallFunctionFvPatchScalarField.C`](../../../applications/modules/multiphaseEuler/fvModels/wallBoiling/alphatBoilingWallFunctionFvPatchScalarField.C)
- 头文件：[`applications/modules/multiphaseEuler/fvModels/wallBoiling/alphatBoilingWallFunctionFvPatchScalarField.H`](../../../applications/modules/multiphaseEuler/fvModels/wallBoiling/alphatBoilingWallFunctionFvPatchScalarField.H)
- Inventory 备注：module-local BCs

## 教程与模板
- [`tutorials/multiRegion/CHT/wallBoiling/0/fluid/alphat.gas`](../../../tutorials/multiRegion/CHT/wallBoiling/0/fluid/alphat.gas)
- [`tutorials/multiRegion/CHT/wallBoiling/0/fluid/alphat.liquid`](../../../tutorials/multiRegion/CHT/wallBoiling/0/fluid/alphat.liquid)
- [`tutorials/multiphaseEuler/wallBoilingPolydisperseTwoGroups/0/alphat.gas`](../../../tutorials/multiphaseEuler/wallBoilingPolydisperseTwoGroups/0/alphat.gas)
- [`tutorials/multiphaseEuler/wallBoilingPolydisperseTwoGroups/0/alphat.liquid`](../../../tutorials/multiphaseEuler/wallBoilingPolydisperseTwoGroups/0/alphat.liquid)
- [`tutorials/multiphaseEuler/wallBoilingPolydisperse/0/alphat.gas`](../../../tutorials/multiphaseEuler/wallBoilingPolydisperse/0/alphat.gas)
- [`tutorials/multiphaseEuler/wallBoilingPolydisperse/0/alphat.liquid`](../../../tutorials/multiphaseEuler/wallBoilingPolydisperse/0/alphat.liquid)

## 注意事项
- 壁面函数场（`nut`/`k`/`epsilon`/`omega`/`alphat`）需成套配置，勿与低 Re 积分壁面混用。
