# `polynomialSolidTransport`

## 一句话

多项式固体导热

## 适用条件（求解器 / 场 / 前提）

- `thermoType`.transport` ≈ `polynomial`（类 `polynomialSolidTransport`）
- 气体：`const`/`sutherland`（`forGases`）；液体：仅 `const`；表格式：`tabulated`/`icoTabulated`；固体：`constIso`/`constAniso`/`exponential`/`polynomial`/`tabulated`（`forSolids`）

## 字典示例

```c++
thermoType
{
transport polynomial;
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

Transport package using polynomial functions for solid `kappa`.

\table
Property        | Description
kappaCoeffs<8>  | Thermal conductivity polynomial coefficients
\endtable

Example of the specification of the transport properties:
```
transport
{
kappaCoeffs<8>     ( 1000 -0.05 0.003 0 0 0 0 0 );
}
```

The polynomial expression is evaluated as so:

$$
\kappa = 1000 - 0.05 T + 0.003 T^2
$$

Note:
Thermal conductivity polynomial coefficients evaluate to an expression
in [W/m/K].

## 文献与源码依据

- 源码：[`src/thermophysicalModels/solidThermo/solidSpecie/transport/polynomial/polynomialSolidTransport.H`](../../../src/thermophysicalModels/solidThermo/solidSpecie/transport/polynomial/polynomialSolidTransport.H)

## 教程与模板

- 教程 `physicalProperties` 的 `transport` 块

## 注意事项

- 输运模型必须与 `for`*` 宏允许的组合一致。
