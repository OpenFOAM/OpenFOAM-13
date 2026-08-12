# `ePowerThermo`

## 一句话

幂律 Cv 热力学模型

## 适用条件（求解器 / 场 / 前提）

- `thermoType`.thermo` 字典值常用：`ePower`（对应类 `ePowerThermo`）
- 气体：`hConst`/`janaf`/`eConst` 见 `forGases`.H`；液体仅 const；表格式见 `forTabulated`.H`；固体：`eConst`/`ePolynomial`/`ePower`/`eIcoTabulated` 见 `forSolids`.H`

## 字典示例

```c++
thermoType
{
    // ...
    thermo          ePower;
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

Internal energy based thermodynamics package using a power function of
temperature for the constant heat capacity at constant volume which is
particularly suitable for solids at low temperatures:

```
Cv = c0*pow(T/Tref, n0)
```

\table
Property     | Description
c0           | Reference heat capacity at constant volume [J/kg/K]
n0           | Exponent of the power function
Tref         | Reference temperature [K]
hf           | Heat of formation [J/kg]
\endtable

Example specification of ePowerThermo:
```
thermodynamics
{
c0          230;
Tref        470;
n0          3;
hf          0;
}
```

## 文献与源码依据

- 源码：[`src/thermophysicalModels/specie/thermo/ePower/ePowerThermo.H`](../../../src/thermophysicalModels/specie/thermo/ePower/ePowerThermo.H)

## 教程与模板

- `tutorials/**/physicalProperties` 中 `thermo` 字段

## 注意事项

- 与 `energy` 配对：焓类模型配 `sensibleEnthalpy`/`absoluteEnthalpy`；内能类配 `sensibleInternalEnergy`。
- 幂律 Cv 热力学模型
