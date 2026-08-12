# `icoTabulatedTransport`

## 一句话

不可压表格式输运

## 适用条件（求解器 / 场 / 前提）

- `thermoType`.transport` ≈ `icoTabulated`（类 `icoTabulatedTransport`）
- 气体：`const`/`sutherland`（`forGases`）；液体：仅 `const`；表格式：`tabulated`/`icoTabulated`；固体：`constIso`/`constAniso`/`exponential`/`polynomial`/`tabulated`（`forSolids`）

## 字典示例

```c++
thermoType
{
transport icoTabulated;
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
viscosity and thermal conductivity vs temperature.

\table
Property        | Description
mu              | Dynamic viscosity vs temperature table
kappa           | Thermal conductivity vs temperature table
\endtable

Example of the specification of the transport properties:
```
transport
{
mu
{
values
(
(200 1.82e-05)
(350 2.61e-05)
(400 3.93e-05)
);
}

kappa
{
values
(
(200 2.56e-5)
(350 3.33e-5)
(400 4.72e-5)
);
}
}
```

## 文献与源码依据

- 源码：[`src/thermophysicalModels/specie/transport/icoTabulated/icoTabulatedTransport.H`](../../../src/thermophysicalModels/specie/transport/icoTabulated/icoTabulatedTransport.H)

## 教程与模板

- 教程 `physicalProperties` 的 `transport` 块

## 注意事项

- 输运模型必须与 `for`*` 宏允许的组合一致。
