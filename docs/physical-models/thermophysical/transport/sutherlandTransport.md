# `sutherlandTransport`

## 一句话

Sutherland 粘度律

## 适用条件（求解器 / 场 / 前提）

- `thermoType`.transport` ≈ `sutherland`（类 `sutherlandTransport`）
- 气体：`const`/`sutherland`（`forGases`）；液体：仅 `const`；表格式：`tabulated`/`icoTabulated`；固体：`constIso`/`constAniso`/`exponential`/`polynomial`/`tabulated`（`forSolids`）

## 字典示例

```c++
thermoType
{
transport sutherland;
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

Transport package using Sutherland's formula for viscosity:

```
mu = As*sqrt(T)/(1 + Ts/T)
```

and the thermal conductivity (for gases) is obtained from:

```
kappa = mu*Cv*(1.32 + 1.77*R/Cv)
```

\table
Property     | Description
As           | Sutherland constant kg/(ms K^1/2)
Ts           | Sutherland temperature [K]
\endtable

Example specification of sutherlandTransport for air:
```
transport
{
As              1.458e-06;
Ts              110.4;
}
```

## 文献与源码依据

- 源码：[`src/thermophysicalModels/specie/transport/sutherland/sutherlandTransport.H`](../../../src/thermophysicalModels/specie/transport/sutherland/sutherlandTransport.H)

## 教程与模板

- 教程 `physicalProperties` 的 `transport` 块

## 注意事项

- 输运模型必须与 `for`*` 宏允许的组合一致。
