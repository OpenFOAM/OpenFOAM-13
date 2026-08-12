# `AndradeTransport`

## 一句话

Andrade 粘度律

## 适用条件（求解器 / 场 / 前提）

- `thermoType`.transport` ≈ `Andrade`（类 `AndradeTransport`）
- 气体：`const`/`sutherland`（`forGases`）；液体：仅 `const`；表格式：`tabulated`/`icoTabulated`；固体：`constIso`/`constAniso`/`exponential`/`polynomial`/`tabulated`（`forSolids`）

## 字典示例

```c++
thermoType
{
transport Andrade;
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

Transport package using the Andrade function for the natural logarithm of
dynamic viscosity and thermal conductivity of liquids:

```
log(mu) = muCoeffs[0] + muCoeffs[1]*T + muCoeffs[2]*sqr(T)
+ muCoeffs_[3]/(muCoeffs_[4] + T)

log(kappa) = kappaCoeffs[0] + kappaCoeffs[1]*T + kappaCoeffs[2]*sqr(T)
+ kappaCoeffs_[3]/(kappaCoeffs_[4] + T)
);
```

References:
```
Andrade, E. D. C. (1934).
XLI. A theory of the viscosity of liquids.—Part I.
The London, Edinburgh, and Dublin Philosophical Magazine
and Journal of Science, 17(112), 497-511.

Andrade, E. D. C. (1934).
LVIII. A theory of the viscosity of liquids.—Part II.
The London, Edinburgh, and Dublin Philosophical Magazine
and Journal of Science, 17(113), 698-732.
```

\table
Property        | Description
muCoeffs        | Dynamic viscosity polynomial coefficients
kappaCoeffs     | Thermal conductivity polynomial coefficients
\endtable

Example of the specification of the transport properties for water@200bar:
```
transport
{
muCoeffs    (-25.8542 0.031256 -2.2e-05 3289.918 -11.4784);
kappaCoeffs (-2.56543 0.008794 -9.8e-06 100.368 0);
}
```

## 文献与源码依据

- 源码：[`src/thermophysicalModels/specie/transport/Andrade/AndradeTransport.H`](../../../src/thermophysicalModels/specie/transport/Andrade/AndradeTransport.H)

## 教程与模板

- 教程 `physicalProperties` 的 `transport` 块

## 注意事项

- 输运模型必须与 `for`*` 宏允许的组合一致。
