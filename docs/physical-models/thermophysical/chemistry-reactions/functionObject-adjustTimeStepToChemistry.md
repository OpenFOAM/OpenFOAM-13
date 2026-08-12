# `adjustTimeStepToChemistry`

## 一句话

functionObject：`adjustTimeStepToChemistry`。

## 适用条件（求解器 / 场 / 前提）

- 在 `system/controlDict` / `functions` 中启用

## 字典示例

```c++
functions
{
    adjustTimeStepToChemistry
    {
        type adjustTimeStepToChemistry;
        libs ("libchemicalFunctionObjects.so"); // 以实际 Make 为准
    }
}
```

## 参数表

见源码。

## 控制方程与关联式

Returns the minimum chemistry chemical time scale

This allows the solver to temporally resolve chemical changes, in order to
better couple the chemistry and transport, or in order to accurately
post-process the chemical changes.

Note that this function only does anything if time step adjustment is
enabled in the controlDict.

Example of function object specification:
```
adjustTimeStepToChemistry
{
type            adjustTimeStepToChemistry;
libs            ("libchemistryModel.so");
}
```

## 文献与源码依据

- [`src/thermophysicalModels/chemistryModel/functionObjects/adjustTimeStepToChemistry/adjustTimeStepToChemistry.H`](../../../src/thermophysicalModels/chemistryModel/functionObjects/adjustTimeStepToChemistry/adjustTimeStepToChemistry.H)

## 教程与模板

- 多组分/化学教程的 `functions`

## 注意事项

- 库名以模块链接为准。
