# `WLFTransport`

## 一句话

Williams–Landel–Ferry 粘度

## 适用条件（求解器 / 场 / 前提）

- `thermoType`.transport` ≈ `WLF`（类 `WLFTransport`）
- 气体：`const`/`sutherland`（`forGases`）；液体：仅 `const`；表格式：`tabulated`/`icoTabulated`；固体：`constIso`/`constAniso`/`exponential`/`polynomial`/`tabulated`（`forSolids`）

## 字典示例

```c++
thermoType
{
transport WLF;
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

Transport package using the Williams-Landel-Ferry model for viscosity of
polymer melts:

```
mu = mu0*exp(-C1*(T - Tr)/(C2 + T - Tr))
```

References:
```
Williams, M. L., Landel, R. F., & Ferry, J. D. (1955).
The temperature dependence of relaxation mechanisms
in amorphous polymers and other glass-forming liquids.
Journal of the American Chemical society, 77(14), 3701-3707.
```

The thermal conductivity is obtained using a constant Prandtl number.

\table
Property     | Description
mu0          | Reference dynamic viscosity [Pa.s]
Tref         | Reference temperature [K]
C1           | WLF constant []
C2           | WLF constant [K]
Pr           | Constant Prandtl number []
\endtable

Example specification of WLFTransport for a polymer:
```
transport
{
mu0         50000;
Tr          416;
C1          20.4;
C2          101.6;
Pr          10000;
}
```

## 文献与源码依据

- 源码：[`src/thermophysicalModels/specie/transport/WLF/WLFTransport.H`](../../../src/thermophysicalModels/specie/transport/WLF/WLFTransport.H)

## 教程与模板

- 教程 `physicalProperties` 的 `transport` 块

## 注意事项

- 输运模型必须与 `for`*` 宏允许的组合一致。
