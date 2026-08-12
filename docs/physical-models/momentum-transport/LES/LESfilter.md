# `LESfilter`

## 一句话

LES 动态模型用的滤波算子基类；具体类型见 `simple` / `laplace` / `anisotropic`。

## 适用条件（求解器 / 场 / 前提）

- 适用: 使用动态 LES（`dynamicKEqn`、`dynamicLagrangian` 等）的 incompressible / compressible 路径
- 字典位于 `LES` { filter <type>; ... }`
- 不适用: 纯 RAS；不需要动态系数的 Smagorinsky/WALE（可不配 filter）

## 字典示例



> （由源码构造函数推断，无官方教程实例）

```c++
// constant/momentumTransport
simulationType LES;

LES
{
    model           LESfilter;
    turbulence      on;
}
```

## 参数表

基类本身无统一系数；各派生 filter 有自身参数（见对应页）。

## 控制方程与关联式

滤波算子 $\overline{\phi}$ 用于动态 Germano 类过程中测试滤波尺度上的应力，以确定模型系数。

## 文献与源码依据

- 基类：`src/MomentumTransportModels/momentumTransportModels/LES/LESfilters/LESfilter/LESfilter.H`
- 派生：[`simpleFilter`](simpleFilter.md)、[`laplaceFilter`](laplaceFilter.md)、[`anisotropicFilter`](anisotropicFilter.md)

## 教程与模板

- 仓库 tutorials 中未检索到 `LESfilter` 字面配置；可参考同类 `simulationType` 案例并改 `model`。
- 注册见 [`README`](../README.md) 工厂表。


## 注意事项

- `filter` 注册名通常为短名（`simple`），与类名 `simpleFilter` 对应。
- 与 `delta` 独立配置，二者都影响动态过程。
