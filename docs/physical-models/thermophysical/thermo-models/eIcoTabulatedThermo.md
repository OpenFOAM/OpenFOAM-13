# `eIcoTabulatedThermo`

## 一句话

不可压表格式内能热力学

## 适用条件（求解器 / 场 / 前提）

- `thermoType`.thermo` 字典值常用：`eIcoTabulated`（对应类 `eIcoTabulatedThermo`）
- 气体：`hConst`/`janaf`/`eConst` 见 `forGases`.H`；液体仅 const；表格式见 `forTabulated`.H`；固体：`eConst`/`ePolynomial`/`ePower`/`eIcoTabulated` 见 `forSolids`.H`

## 字典示例

```c++
thermoType
{
    // ...
    thermo          eIcoTabulated;
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

Internal energy based thermodynamics package using non-uniform tabulated
data for heat capacity vs temperature.

\table
Property     | Description
hf           | Heat of formation
sf           | Standard entropy
Cv           | Specific heat at constant volume vs temperature table
\endtable

Example of the specification of the thermodynamic properties:
```
thermodynamics
{
hf              0;
sf              0;
Cv
{
values
(
(200     1005)
(350     1010)
(400     1020)
);
}
}
```

## 文献与源码依据

- 源码：[`src/thermophysicalModels/specie/thermo/eIcoTabulated/eIcoTabulatedThermo.H`](../../../src/thermophysicalModels/specie/thermo/eIcoTabulated/eIcoTabulatedThermo.H)

## 教程与模板

- `tutorials/**/physicalProperties` 中 `thermo` 字段

## 注意事项

- 与 `energy` 配对：焓类模型配 `sensibleEnthalpy`/`absoluteEnthalpy`；内能类配 `sensibleInternalEnergy`。
- 不可压表格式内能热力学
