# `janafThermo`

## 一句话

JANAF 多项式 Cp(T)

## 适用条件（求解器 / 场 / 前提）

- `thermoType`.thermo` 字典值常用：`janaf`（对应类 `janafThermo`）
- 气体：`hConst`/`janaf`/`eConst` 见 `forGases`.H`；液体仅 const；表格式见 `forTabulated`.H`；固体：`eConst`/`ePolynomial`/`ePower`/`eIcoTabulated` 见 `forSolids`.H`

## 字典示例

```c++
thermoType
{
    // ...
    thermo          janaf;
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

Enthalpy based thermodynamics package using JANAF tables:

```
Cp/R = (((a4*T + a3)*T + a2)*T + a1)*T + a0
ha/R = ((((a4/5*T + a3/4)*T + a2/3)*T + a1/2)*T + a0)*T + a5
```

\table
Property     | Description
Tlow         | Lower temperature limit [K]
Thigh        | Upper temperature limit [K]
Tcommon      | Transition temperature from low to high polynomials [K]
lowCpCoeffs  | Low temperature range heat capacity coefficients
highCpCoeffs | High temperature range heat capacity coefficients
\endtable

Example specification of janafThermo for air:
```
thermodynamics
{
Tlow            100;
Thigh           10000;
Tcommon         1000;

lowCpCoeffs
(
3.5309628
-0.0001236595
-5.0299339e-07
2.4352768e-09
-1.4087954e-12
-1046.9637
2.9674391
);

highCpCoeffs
(
2.9525407
0.0013968838
-4.9262577e-07
7.8600091e-11
-4.6074978e-15
-923.93753
5.8718221
);
}
```

## 文献与源码依据

- 源码：[`src/thermophysicalModels/specie/thermo/janaf/janafThermo.H`](../../../src/thermophysicalModels/specie/thermo/janaf/janafThermo.H)

## 教程与模板

- `tutorials/**/physicalProperties` 中 `thermo` 字段

## 注意事项

- 与 `energy` 配对：焓类模型配 `sensibleEnthalpy`/`absoluteEnthalpy`；内能类配 `sensibleInternalEnergy`。
- JANAF 多项式 Cp(T)
