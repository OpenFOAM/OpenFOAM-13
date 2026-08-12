# `HerschelBulkley`

## 一句话

漂移通量混合物粘度模型 `HerschelBulkley`。

## 适用条件（求解器 / 场 / 前提）

- 适用: `incompressibleDriftFlux`
- 不适用: 单相 `incompressibleFluid`

## 字典示例

```c++
// constant/physicalProperties（漂移通量案例）
mixtureViscosityModel HerschelBulkley;
// 子字典参数见源码
```

## 参数表

见源码头文件字典构造。

## 控制方程与关联式

HerschelBulkley viscosity model

The Herschel-Bulkley model combines the effects of a Bingham plastic
and power-law behaviour of a fluid. At a low strain rate $\gamma$
the fluid adopts a viscosity $\mu_0$. Beyond a threshold stress
$\tau_0$, the viscosity is described as a power law.

Kinematic viscosity [m^2/s]

$$
\mu = \min(\mu_0, (\tau_0 + k\gamma^{n})/\gamma)
$$

## 文献与源码依据

- [`applications/modules/incompressibleDriftFlux/mixtureViscosityModels/HerschelBulkley/HerschelBulkley.H`](../../../applications/modules/incompressibleDriftFlux/mixtureViscosityModels/HerschelBulkley/HerschelBulkley.H)

## 教程与模板

- `tutorials/incompressibleDriftFlux/**`

## 注意事项

- 与相对速度 / packingDispersion 模型联用。
