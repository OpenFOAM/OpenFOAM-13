# maxwellSlipU

## 一句话
滑移：法向速度约束、切向自由或按比例滑移。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`maxwellSlipU`
- **典型场**：`U`
- **库 / 加载**：模块本地：仅 `shockFluid` 求解器链接
- **适用标签**：见库说明；不确定时查求解器 `Make/options`。

## 字典示例
```
<patchName>
{
    type            maxwellSlipU;
    // 其余条目见源码 Usage / 教程
    value           $internalField;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| | *以下关键字自 `.C` 构造函数字典读取推断，完整语义见源码* | | |
| `T` | （自构造函数字典读取） | no | "T" |
| `rho` | （自构造函数字典读取） | no | "rho" |
| `psi` | （自构造函数字典读取） | no | "psi" |
| `mu` | （自构造函数字典读取） | no | "mu" |
| `thermalCreep` | （自构造函数字典读取） | no | true |
| `curvature` | （自构造函数字典读取） | no | true |
| `accommodationCoeff` | （自构造函数字典读取） | yes |  |

## 控制方程与关联式
滑移：法向速度约束、切向自由或按比例滑移。

类头 `Description` 原文：

> Maxwell slip boundary condition including thermal creep and surface
> curvature terms that can be optionally switched off.

## 文献与源码依据
- 源码：[`applications/modules/shockFluid/derivedFvPatchFields/U/maxwellSlipUFvPatchVectorField.C`](../../../applications/modules/shockFluid/derivedFvPatchFields/U/maxwellSlipUFvPatchVectorField.C)
- 头文件：[`applications/modules/shockFluid/derivedFvPatchFields/U/maxwellSlipUFvPatchVectorField.H`](../../../applications/modules/shockFluid/derivedFvPatchFields/U/maxwellSlipUFvPatchVectorField.H)
- Inventory 备注：shockFluid module BCs

## 教程与模板
- [`tutorials/shockFluid/biconic25-55Run35/0/U`](../../../tutorials/shockFluid/biconic25-55Run35/0/U)

## 注意事项
- 模块本地 BC：其他 solver 即使同名字段也不会注册该 `type`。
