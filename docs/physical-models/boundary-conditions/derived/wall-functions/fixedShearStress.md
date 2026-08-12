# fixedShearStress

## 一句话
壁面函数类边界条件 `fixedShearStress`。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`fixedShearStress`
- **典型场**：见源码 / 场量纲匹配
- **库 / 加载**：需动量输运库（如 `libmomentumTransportModels` / 相专用库）；通常由启用湍流的求解器链接
- **前提**：启用 RAS/LES 壁面函数湍流模型；近壁网格满足 y+ 假设。

## 字典示例
```
<patchName>
{
    type            fixedShearStress;
    // 其余条目见源码 Usage / 教程
    value           $internalField;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| | *以下关键字自 `.C` 构造函数字典读取推断，完整语义见源码* | | |
| `tau` | （自构造函数字典读取） | no | sqr(dimVelocity |

## 控制方程与关联式
壁面函数类边界条件 `fixedShearStress`。

类头 `Description` 原文：

> Set a constant shear stress as tau0 = -nuEff dU/dn.

## 文献与源码依据
- 源码：[`src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/fixedShearStress/fixedShearStressFvPatchVectorField.C`](../../../src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/fixedShearStress/fixedShearStressFvPatchVectorField.C)
- 头文件：[`src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/fixedShearStress/fixedShearStressFvPatchVectorField.H`](../../../src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/fixedShearStress/fixedShearStressFvPatchVectorField.H)
- Inventory 备注：momentum transport / wall functions

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            fixedShearStress`。

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
