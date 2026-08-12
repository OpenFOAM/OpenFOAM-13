# `logPolynomialTransport`

## 一句话

对数多项式输运

## 适用条件（求解器 / 场 / 前提）

- `thermoType`.transport` ≈ `logPolynomial`（类 `logPolynomialTransport`）
- 气体：`const`/`sutherland`（`forGases`）；液体：仅 `const`；表格式：`tabulated`/`icoTabulated`；固体：`constIso`/`constAniso`/`exponential`/`polynomial`/`tabulated`（`forSolids`）

## 字典示例

```c++
thermoType
{
transport logPolynomial;
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

Transport package using polynomial functions of the natural logarithm of
temperature for the natural logarithm of dynamic viscosity and thermal
conductivity:

```
log(mu) = muLogCoeffs[0] + muLogCoeffs[1]*log(T)
+ muLogCoeffs[2]*sqr(log(T)) + muLogCoeffs[3]*pow3(log(T))
+ muLogCoeffs[4]*pow4(log(T)) + muLogCoeffs[5]*pow(log(T), 5)
+ muLogCoeffs[6]*pow(log(T), 6) + muLogCoeffs[7]*pow(log(T), 7)

log(kappa) = kappaLogCoeffs[0] + kappaLogCoeffs[1]*log(T)
+ kappaLogCoeffs[2]*sqr(log(T)) + kappaLogCoeffs[3]*pow3(log(T))
+ kappaLogCoeffs[4]*pow4(log(T)) + kappaLogCoeffs[5]*pow(log(T), 5)
+ kappaLogCoeffs[6]*pow(log(T), 6) + kappaLogCoeffs[7]*pow(log(T), 7)
```

The polynomial function is templated on the order of the polynomial which
defaults to 8.

\table
Property           | Description
muLogCoeffs<8>     | Dynamic viscosity polynomial coefficients
kappaLogCoeffs<8>  | Thermal conductivity polynomial coefficients
\endtable

Example of the specification of the transport properties:
```
transport
{
muLogCoeffs<8>     (1000 -0.05 0.003 0 0 0 0 0);
kappaLogCoeffs<8>  (2000 -0.15 0.023 0 0 0 0 0);
}
```

## 文献与源码依据

- 源码：[`src/thermophysicalModels/specie/transport/logPolynomial/logPolynomialTransport.H`](../../../src/thermophysicalModels/specie/transport/logPolynomial/logPolynomialTransport.H)

## 教程与模板

- 教程 `physicalProperties` 的 `transport` 块

## 注意事项

- 输运模型必须与 `for`*` 宏允许的组合一致。
