# `hTabulatedThermo`

## 一句话

表格式焓热力学

## 适用条件（求解器 / 场 / 前提）

- `thermoType`.thermo` 字典值常用：`hTabulated`（对应类 `hTabulatedThermo`）
- 气体：`hConst`/`janaf`/`eConst` 见 `forGases`.H`；液体仅 const；表格式见 `forTabulated`.H`；固体：`eConst`/`ePolynomial`/`ePower`/`eIcoTabulated` 见 `forSolids`.H`

## 字典示例

```c++
thermoType
{
    // ...
    thermo          hTabulated;
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

Enthalpy based thermodynamics package using uniform tabulated data for
enthalpy and heat capacity vs pressure and temperature.

\table
Property     | Description
hf           | Heat of formation
sf           | Standard entropy
hs           | Sensible enthalpy vs pressure and temperature table
Cp           | Specific heat capacity vs pressure and temperature table
\endtable

Example of the specification of the thermodynamic properties:
```
thermodynamics
{
hf              0;
sf              0;

hs
{
pLow    1e4;
pHigh   5e5;

Tlow    200;
Thigh   1500;

values
<m> <n>
(
(..........)
.
.
.
(..........)
);
}

Cp
{
pLow    1e3;
pHigh   1e6;

Tlow    200;
Thigh   1500;

values
<m> <n>
(
(..........)
.
.
.
(..........)
);
}
}
```

## 文献与源码依据

- 源码：[`src/thermophysicalModels/specie/thermo/hTabulated/hTabulatedThermo.H`](../../../src/thermophysicalModels/specie/thermo/hTabulated/hTabulatedThermo.H)

## 教程与模板

- `tutorials/**/physicalProperties` 中 `thermo` 字段

## 注意事项

- 与 `energy` 配对：焓类模型配 `sensibleEnthalpy`/`absoluteEnthalpy`；内能类配 `sensibleInternalEnergy`。
- 表格式焓热力学
