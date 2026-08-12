# `moleFractions`

## 一句话

functionObject：`moleFractions`。

## 适用条件（求解器 / 场 / 前提）

- 在 `system/controlDict` / `functions` 中启用

## 字典示例

```c++
functions
{
    moleFractions
    {
        type moleFractions;
        libs ("libchemicalFunctionObjects.so"); // 以实际 Make 为准
    }
}
```

## 参数表

见源码。

## 控制方程与关联式

This function object calculates mole-fraction fields from the mass-fraction
fields of the multicomponent thermo. The names of the mole-fraction fields
are obtained from the corresponding mass-fraction fields prepended by "X_".

Example of function object specification:
```
moleFractions
{
type moleFractions;
}
```

Optionally, the name of the phase can be specified for multiphase cases.

See also
Foam::functionObjects::fvMeshFunctionObject

## 文献与源码依据

- [`src/thermophysicalModels/multicomponentThermo/functionObjects/moleFractions/moleFractions.H`](../../../src/thermophysicalModels/multicomponentThermo/functionObjects/moleFractions/moleFractions.H)

## 教程与模板

- 多组分/化学教程的 `functions`

## 注意事项

- 库名以模块链接为准。
