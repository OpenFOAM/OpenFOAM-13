# hydrostaticDisplacement

## 一句话
压力相关边界条件。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`hydrostaticDisplacement`
- **典型场**：p / p_rgh, D (displacement)
- **库 / 加载**：模块本地：仅 `solidDisplacement`
- **适用标签**：见库说明；不确定时查求解器 `Make/options`。

## 字典示例
```
<patchName>
{
    type            hydrostaticDisplacement;
    // 其余条目见源码 Usage / 教程
    value           $internalField;
}
```

## 参数表
源码头文件未提供标准 `Usage` 表，或参数由基类继承——请对照源码构造函数读取字典关键字。

## 控制方程与关联式
压力相关边界条件。

类头 `Description` 原文：

> Fixed traction boundary condition for the standard linear elastic, fixed
> coefficient displacement equation in which the traction is caused by
> the hydrostatic pressure of an external liquid reservoir.

## 文献与源码依据
- 源码：[`applications/modules/solidDisplacement/derivedFvPatchFields/hydrostaticDisplacement/hydrostaticDisplacementFvPatchVectorField.C`](../../../applications/modules/solidDisplacement/derivedFvPatchFields/hydrostaticDisplacement/hydrostaticDisplacementFvPatchVectorField.C)
- 头文件：[`applications/modules/solidDisplacement/derivedFvPatchFields/hydrostaticDisplacement/hydrostaticDisplacementFvPatchVectorField.H`](../../../applications/modules/solidDisplacement/derivedFvPatchFields/hydrostaticDisplacement/hydrostaticDisplacementFvPatchVectorField.H)
- Inventory 备注：module-local BCs

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            hydrostaticDisplacement`。

## 注意事项
- 模块本地 BC：其他 solver 即使同名字段也不会注册该 `type`。
