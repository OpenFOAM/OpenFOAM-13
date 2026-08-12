# alphaFixedPressure

## 一句话
接触角条件，用于 VoF 壁面润湿。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`alphaFixedPressure`
- **典型场**：p / p_rgh, `alpha`.*`
- **库 / 加载**：需两相/VoF 相关库（`libtwoPhaseProperties` / interfaceProperties）

## 字典示例
```
<patchName>
{
    type            alphaFixedPressure;
    // 其余条目见源码 Usage / 教程
    value           $internalField;
}
```

## 参数表
源码头文件未提供标准 `Usage` 表，或参数由基类继承——请对照源码构造函数读取字典关键字。

## 控制方程与关联式
接触角条件，用于 VoF 壁面润湿。

类头 `Description` 原文：

> A fixed-pressure alphaContactAngle boundary

## 文献与源码依据
- 源码：[`src/twoPhaseModels/twoPhaseProperties/alphaFixedPressure/alphaFixedPressureFvPatchScalarField.C`](../../../src/twoPhaseModels/twoPhaseProperties/alphaFixedPressure/alphaFixedPressureFvPatchScalarField.C)
- 头文件：[`src/twoPhaseModels/twoPhaseProperties/alphaFixedPressure/alphaFixedPressureFvPatchScalarField.H`](../../../src/twoPhaseModels/twoPhaseProperties/alphaFixedPressure/alphaFixedPressureFvPatchScalarField.H)
- Inventory 备注：twoPhase BCs

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            alphaFixedPressure`。

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
