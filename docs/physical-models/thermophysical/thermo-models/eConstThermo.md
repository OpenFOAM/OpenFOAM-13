# `eConstThermo`

## 一句话

常 Cv 内能热力学模型

## 适用条件（求解器 / 场 / 前提）

- `thermoType`.thermo` 字典值常用：`eConst`（对应类 `eConstThermo`）
- 气体：`hConst`/`janaf`/`eConst` 见 `forGases`.H`；液体仅 const；表格式见 `forTabulated`.H`；固体：`eConst`/`ePolynomial`/`ePower`/`eIcoTabulated` 见 `forSolids`.H`

## 字典示例

```c++
thermoType
{
    // ...
    thermo          eConst;
    energy          sensibleEnthalpy; // 或 sensibleInternalEnergy
}
mixture
{
    thermodynamics
    {
        // 参数随模型而变：Cp/hf、JANAF 系数、或 tables
    }
}
```

## 参数表

见源码头文件 `Usage` 与 `mixture`.thermodynamics` 子字典。

## 控制方程与关联式

Internal energy based thermodynamics package using a constant heat capacity
at constant volume.

The sensible internal energy is evaluated as:
```
es = Cv*(T - Tref) + esRef
```

\table
Property     | Description
Cv           | Constant Heat capacity at constant volume [J/kg/K]
Tref         | Reference temperature [K] (defaults to Tstd)
esRef        | Reference sensible internal energy [J/kg] (defaults to 0)
hf           | Heat of formation [J/kg]
\endtable

Example specification of eConstThermo for air:
```
thermodynamics
{
Cv          724;
hf          0;
}
```

## 文献与源码依据

- 源码：[`src/thermophysicalModels/specie/thermo/eConst/eConstThermo.H`](../../../src/thermophysicalModels/specie/thermo/eConst/eConstThermo.H)

## 教程与模板

- `tutorials/**/physicalProperties` 中 `thermo` 字段

## 注意事项

- 与 `energy` 配对：焓类模型配 `sensibleEnthalpy`/`absoluteEnthalpy`；内能类配 `sensibleInternalEnergy`。
- 常 Cv 内能热力学模型
