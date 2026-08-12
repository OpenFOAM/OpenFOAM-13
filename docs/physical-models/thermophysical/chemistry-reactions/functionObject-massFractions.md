# `massFractions`

## 一句话

functionObject：`massFractions`。

## 适用条件（求解器 / 场 / 前提）

- 在 `system/controlDict` / `functions` 中启用

## 字典示例

```c++
functions
{
    massFractions
    {
        type massFractions;
        libs ("libchemicalFunctionObjects.so"); // 以实际 Make 为准
    }
}
```

## 参数表

见源码。

## 控制方程与关联式

This function object calculates mass-fraction fields from mole-fraction or
moles fields present on disk. This is intended to be used for
initialisation where mole-fractions are known. If any mass fraction fields
are found (other than Ydefault) then an error will be generated and the
fields will not be overwritten. The names of the mole-fraction fields are
obtained from the corresponding mass-fraction fields prepended by "X_", and
the moles fields are prepended by "n_". Either mole-fraction fields or
moles fields should be present, not both.

Example of function object specification:
```
massFractions
{
type massFractions;
}
```

Optionally, the name of the phase can be specified for multiphase cases.

See also
Foam::functionObjects::fvMeshFunctionObject

## 文献与源码依据

- [`src/thermophysicalModels/multicomponentThermo/functionObjects/massFractions/massFractions.H`](../../../src/thermophysicalModels/multicomponentThermo/functionObjects/massFractions/massFractions.H)

## 教程与模板

- 多组分/化学教程的 `functions`

## 注意事项

- 库名以模块链接为准。
