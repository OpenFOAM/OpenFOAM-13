# smoluchowskiJumpT

## 一句话
温度相关边界条件。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`smoluchowskiJumpT`
- **典型场**：`T`
- **库 / 加载**：模块本地：仅 `shockFluid` 求解器链接
- **适用标签**：见库说明；不确定时查求解器 `Make/options`。

## 字典示例
```
<patchName>
{
    type            smoluchowskiJumpT;
    // 其余条目见源码 Usage / 教程
    value           $internalField;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| | *以下关键字自 `.C` 构造函数字典读取推断，完整语义见源码* | | |
| `U` | （自构造函数字典读取） | no | "U" |
| `rho` | （自构造函数字典读取） | no | "rho" |
| `psi` | （自构造函数字典读取） | no | "psi" |
| `mu` | （自构造函数字典读取） | no | "mu" |
| `gamma` | （自构造函数字典读取） | no | dimless, 1.4 |
| `Pr` | （自构造函数字典读取） | yes |  |

## 控制方程与关联式
温度相关边界条件。

类头 `Description` 原文：

> Smoluchowski temperature jump boundary condition

## 文献与源码依据
- 源码：[`applications/modules/shockFluid/derivedFvPatchFields/T/smoluchowskiJumpTFvPatchScalarField.C`](../../../applications/modules/shockFluid/derivedFvPatchFields/T/smoluchowskiJumpTFvPatchScalarField.C)
- 头文件：[`applications/modules/shockFluid/derivedFvPatchFields/T/smoluchowskiJumpTFvPatchScalarField.H`](../../../applications/modules/shockFluid/derivedFvPatchFields/T/smoluchowskiJumpTFvPatchScalarField.H)
- Inventory 备注：shockFluid module BCs

## 教程与模板
- [`tutorials/shockFluid/biconic25-55Run35/0/T`](../../../tutorials/shockFluid/biconic25-55Run35/0/T)

## 注意事项
- 模块本地 BC：其他 solver 即使同名字段也不会注册该 `type`。
