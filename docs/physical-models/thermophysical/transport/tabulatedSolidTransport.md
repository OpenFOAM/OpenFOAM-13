# `tabulatedSolidTransport`

## 一句话

表格式固体导热

## 适用条件（求解器 / 场 / 前提）

- `thermoType`.transport` ≈ `tabulated`（类 `tabulatedSolidTransport`）
- 气体：`const`/`sutherland`（`forGases`）；液体：仅 `const`；表格式：`tabulated`/`icoTabulated`；固体：`constIso`/`constAniso`/`exponential`/`polynomial`/`tabulated`（`forSolids`）

## 字典示例

```c++
thermoType
{
transport tabulated;
/* ... */
}
mixture
{
    transport
    {
        // const: mu, Pr; sutherland: As, Ts, Pr; ...
    }
}
```

## 参数表

参数位于 `mixture`.transport`；量纲见源码头文件。

## 控制方程与关联式

Transport properties package using non-uniformly-spaced tabulated data for
thermal conductivity vs temperature.

\table
Property        | Description
kappa           | Thermal conductivity vs temperature table
\endtable

Example of the specification of the transport properties:
```
transport
{
kappa
{
values
(
(200 380)
(350 400)
(400 450)
);
}
}
```

## 文献与源码依据

- 源码：[`src/thermophysicalModels/solidThermo/solidSpecie/transport/tabulated/tabulatedSolidTransport.H`](../../../src/thermophysicalModels/solidThermo/solidSpecie/transport/tabulated/tabulatedSolidTransport.H)

## 教程与模板

- 教程 `physicalProperties` 的 `transport` 块

## 注意事项

- 输运模型必须与 `for`*` 宏允许的组合一致。
