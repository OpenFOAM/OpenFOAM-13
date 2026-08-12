# `hConstThermo`

## 一句话

常 Cp 焓热力学模型

## 适用条件（求解器 / 场 / 前提）

- `thermoType`.thermo` 字典值常用：`hConst`（对应类 `hConstThermo`）
- 气体：`hConst`/`janaf`/`eConst` 见 `forGases`.H`；液体仅 const；表格式见 `forTabulated`.H`；固体：`eConst`/`ePolynomial`/`ePower`/`eIcoTabulated` 见 `forSolids`.H`

## 字典示例

```c++
thermoType
{
    // ...
    thermo          hConst;
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

Enthalpy based thermodynamics package using a constant heat capacity
at constant pressure.

The sensible enthalpy is evaluated as:
```
hs = Cp*(T - Tref) + hsRef
```

\table
Property     | Description
Cp           | Constant Heat capacity at constant pressure [J/kg/K]
Tref         | Reference temperature [K] (defaults to Tstd)
hsRef        | Reference sensible enthalpy [J/kg] (defaults to 0)
hf           | Heat of formation [J/kg]
\endtable

Example specification of hConstThermo for air:
```
thermodynamics
{
Cp          1007;
hf          0;
}
```

## 文献与源码依据

- 源码：[`src/thermophysicalModels/specie/thermo/hConst/hConstThermo.H`](../../../src/thermophysicalModels/specie/thermo/hConst/hConstThermo.H)

## 教程与模板

- `tutorials/**/physicalProperties` 中 `thermo` 字段

## 注意事项

- 与 `energy` 配对：焓类模型配 `sensibleEnthalpy`/`absoluteEnthalpy`；内能类配 `sensibleInternalEnergy`。
- 常 Cp 焓热力学模型
