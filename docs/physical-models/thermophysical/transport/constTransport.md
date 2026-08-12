# `constTransport`

## 一句话

常 μ、常 Pr 输运

## 适用条件（求解器 / 场 / 前提）

- `thermoType`.transport` ≈ `const`（类 `constTransport`）
- 气体：`const`/`sutherland`（`forGases`）；液体：仅 `const`；表格式：`tabulated`/`icoTabulated`；固体：`constIso`/`constAniso`/`exponential`/`polynomial`/`tabulated`（`forSolids`）

## 字典示例

```c++
thermoType
{
transport const;
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

Transport package with constant properties

\table
Property     | Description
mu           | Constant dynamic viscosity [Pa.s]
Pr           | Constant Prandtl number []
\endtable

Example specification of constTransport for air:
```
transport
{
mu              1.82e-05;
Pr              0.71;
}
```

## 文献与源码依据

- 源码：[`src/thermophysicalModels/specie/transport/const/constTransport.H`](../../../src/thermophysicalModels/specie/transport/const/constTransport.H)

## 教程与模板

- 教程 `physicalProperties` 的 `transport` 块

## 注意事项

- 输运模型必须与 `for`*` 宏允许的组合一致。
