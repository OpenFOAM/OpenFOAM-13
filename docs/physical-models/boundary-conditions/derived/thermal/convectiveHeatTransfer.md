# convectiveHeatTransfer

## 一句话
热 / 温度类边界条件 `convectiveHeatTransfer`。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`convectiveHeatTransfer`
- **典型场**：`T`
- **库 / 加载**：需 `libthermophysicalTransportModels`（`fluid`、`multicomponentFluid`、CHT 等）

## 字典示例

> （由源码构造函数推断，无官方教程实例）

```cpp
wall
{
    type            convectiveHeatTransfer;
    L               0.1;           // [m] 特征长度（必填）
    value           uniform 0;     // [W/m^2/K] htc 初值
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `L` | Length scale [m] | yes |  |

## 控制方程与关联式
热 / 温度类边界条件 `convectiveHeatTransfer`。

类头 `Description` 原文：

> This boundary condition provides a convective heat transfer coefficient
> condition
> 
> if Re > 500000
> $$
>     htc_p = \frac{0.664 Re^{0.5} Pr^{0.333} \kappa_p}{L}
> $$
> else
> $$
>     htc_p = \frac{0.037 Re^{0.8} Pr^{0.333} \kappa_p}{L}
> $$
> 
> where
> 
> 
>     htc_p   | patch convective heat transfer coefficient
>     Re      | Reynolds number
>     Pr      | Prandtl number
>     \kappa_p | thermal conductivity
>     L       | length scale
> 

## 文献与源码依据
- 源码：[`src/ThermophysicalTransportModels/fluid/derivedFvPatchFields/convectiveHeatTransfer/convectiveHeatTransferFvPatchScalarField.C`](../../../src/ThermophysicalTransportModels/fluid/derivedFvPatchFields/convectiveHeatTransfer/convectiveHeatTransferFvPatchScalarField.C)
- 头文件：[`src/ThermophysicalTransportModels/fluid/derivedFvPatchFields/convectiveHeatTransfer/convectiveHeatTransferFvPatchScalarField.H`](../../../src/ThermophysicalTransportModels/fluid/derivedFvPatchFields/convectiveHeatTransfer/convectiveHeatTransferFvPatchScalarField.H)
- Inventory 备注：thermophysical transport BCs

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            convectiveHeatTransfer`。

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
