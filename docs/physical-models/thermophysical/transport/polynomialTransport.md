# `polynomialTransport`

## 一句话

多项式 μ(T)、κ(T)

## 适用条件（求解器 / 场 / 前提）

- `thermoType`.transport` ≈ `polynomial`（类 `polynomialTransport`）
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

Transport package using polynomial functions of temperature for the
dynamic viscosity and thermal conductivity:

```
mu = muCoeffs[0] + muCoeffs[1]*T + muCoeffs[2]*sqr(T)
+ muCoeffs[3]*pow3(T) + muCoeffs[4]*pow4(T)
+ muCoeffs[5]*pow(T, 5) + muCoeffs[6]*pow(T, 6)
+ muCoeffs[7]*pow(T, 7)

kappa = kappaCoeffs[0] + kappaCoeffs[1]*T + kappaCoeffs[2]*sqr(T)
+ kappaCoeffs[3]*pow3(T) + kappaCoeffs[4]*pow4(T)
+ kappaCoeffs[5]*pow(T, 5) + kappaCoeffs[6]*pow(T, 6)
+ kappaCoeffs[7]*pow(T, 7)
```

The polynomial function is templated on the order of the polynomial which
defaults to 8.

\table
Property        | Description
muCoeffs<8>     | Dynamic viscosity polynomial coefficients
kappaCoeffs<8>  | Thermal conductivity polynomial coefficients
\endtable

Example of the specification of the transport properties:
```
transport
{
muCoeffs<8>     (1000 -0.05 0.003 0 0 0 0 0);
kappaCoeffs<8>  (2000 -0.15 0.023 0 0 0 0 0);
}
```

## 文献与源码依据

- 源码：[`src/thermophysicalModels/specie/transport/polynomial/polynomialTransport.H`](../../../src/thermophysicalModels/specie/transport/polynomial/polynomialTransport.H)

## 教程与模板

- 教程 `physicalProperties` 的 `transport` 块

## 注意事项

- 输运模型必须与 `for`*` 宏允许的组合一致。
