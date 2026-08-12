# tractionDisplacement

## 一句话
固体位移类边界条件 `tractionDisplacement`。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`tractionDisplacement`
- **典型场**：D (displacement)
- **库 / 加载**：模块本地：仅 `solidDisplacement`
- **适用标签**：见库说明；不确定时查求解器 `Make/options`。

## 字典示例
```
<patchName>
{
    type            tractionDisplacement;
    // 其余条目见源码 Usage / 教程
    value           $internalField;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| | *以下关键字自 `.C` 构造函数字典读取推断，完整语义见源码* | | |
| `pressure` | （自构造函数字典读取） | yes |  |

## 控制方程与关联式
固体位移类边界条件 `tractionDisplacement`。

类头 `Description` 原文：

> Fixed traction boundary condition for the standard linear elastic, fixed
> coefficient displacement equation.

## 文献与源码依据
- 源码：[`applications/modules/solidDisplacement/derivedFvPatchFields/tractionDisplacement/tractionDisplacementFvPatchVectorField.C`](../../../applications/modules/solidDisplacement/derivedFvPatchFields/tractionDisplacement/tractionDisplacementFvPatchVectorField.C)
- 头文件：[`applications/modules/solidDisplacement/derivedFvPatchFields/tractionDisplacement/tractionDisplacementFvPatchVectorField.H`](../../../applications/modules/solidDisplacement/derivedFvPatchFields/tractionDisplacement/tractionDisplacementFvPatchVectorField.H)
- Inventory 备注：module-local BCs

## 教程与模板
- [`tutorials/solidDisplacement/plateHole/0/D`](../../../tutorials/solidDisplacement/plateHole/0/D)
- [`tutorials/solidDisplacement/beamEndLoad/0/D`](../../../tutorials/solidDisplacement/beamEndLoad/0/D)

## 注意事项
- 模块本地 BC：其他 solver 即使同名字段也不会注册该 `type`。
