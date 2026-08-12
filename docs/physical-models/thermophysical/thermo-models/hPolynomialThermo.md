# `hPolynomialThermo`

## 一句话

多项式 Cp → 焓

## 适用条件（求解器 / 场 / 前提）

- `thermoType`.thermo` 字典值常用：`hPolynomial`（对应类 `hPolynomialThermo`）
- 气体：`hConst`/`janaf`/`eConst` 见 `forGases`.H`；液体仅 const；表格式见 `forTabulated`.H`；固体：`eConst`/`ePolynomial`/`ePower`/`eIcoTabulated` 见 `forSolids`.H`

## 字典示例

```c++
thermoType
{
    // ...
    thermo          hPolynomial;
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

Enthalpy based thermodynamics package using a polynomial function
of temperature for the constant heat capacity at constant pressure:

```
Cp = a0 + a1*T + a2*sqr(T) + a3*pow3(T) + a4*pow4(T)
+ a5*pow(T, 5) + a6*pow(T, 6) + a7*pow(T, 7)
```

The polynomial function is templated on the order of the polynomial which
defaults to 8.

\table
Property     | Description
hf           | Heat of formation
sf           | Standard entropy
CpCoeffs<8>  | Specific heat at constant pressure polynomial coeffs
\endtable

Example of the specification of the thermodynamic properties:
```
thermodynamics
{
hf              0;
sf              0;
CpCoeffs<8>     (1000 -0.05 0.003 0 0 0 0 0);
}
```

Note:
Specific heat at constant pressure polynomial coefficients evaluate to
an expression in [J/kg/K].

## 文献与源码依据

- 源码：[`src/thermophysicalModels/specie/thermo/hPolynomial/hPolynomialThermo.H`](../../../src/thermophysicalModels/specie/thermo/hPolynomial/hPolynomialThermo.H)

## 教程与模板

- `tutorials/**/physicalProperties` 中 `thermo` 字段

## 注意事项

- 与 `energy` 配对：焓类模型配 `sensibleEnthalpy`/`absoluteEnthalpy`；内能类配 `sensibleInternalEnergy`。
- 多项式 Cp → 焓
