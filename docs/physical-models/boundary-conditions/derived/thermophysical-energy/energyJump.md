# energyJump

## 一句话
循环/跳跃补丁上的能量（焓）跳跃。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`energyJump`
- **典型场**：h / e / ha / ea
- **库 / 加载**：需 `libfluidThermophysicalModels`（能量场 `e`/`h` 由 thermo 构造）

## 字典示例
```
<patchName>
{
    type            energyJump;
    // 其余条目见源码 Usage / 教程
    value           $internalField;
}
```

## 参数表
源码头文件未提供标准 `Usage` 表，或参数由基类继承——请对照源码构造函数读取字典关键字。

## 控制方程与关联式
循环/跳跃补丁上的能量（焓）跳跃。

类头 `Description` 原文：

> This boundary condition provides an energy jump condition, using the \c
> cyclic condition as a base. The jump is calculated from the corresponding
> temperature jump. This condition is not applied directly by the user, but
> is constructed automatically by the thermodynamic model when the
> corresponding temperature boundary condition is a jump cyclic.

## 文献与源码依据
- 源码：[`src/thermophysicalModels/basic/derivedFvPatchFields/energyJump/energyJumpFvPatchScalarField.C`](../../../src/thermophysicalModels/basic/derivedFvPatchFields/energyJump/energyJumpFvPatchScalarField.C)
- 头文件：[`src/thermophysicalModels/basic/derivedFvPatchFields/energyJump/energyJumpFvPatchScalarField.H`](../../../src/thermophysicalModels/basic/derivedFvPatchFields/energyJump/energyJumpFvPatchScalarField.H)
- Inventory 备注：thermophysical BCs

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            energyJump`。

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
