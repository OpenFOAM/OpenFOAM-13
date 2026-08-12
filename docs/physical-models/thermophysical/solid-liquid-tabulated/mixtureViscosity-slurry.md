# `slurry`

## 一句话

漂移通量混合物粘度模型 `slurry`。

## 适用条件（求解器 / 场 / 前提）
- 适用: `incompressibleDriftFlux`
- 不适用: 单相 `incompressibleFluid`

## 字典示例

```c++
// constant/physicalProperties（漂移通量案例） mixtureViscosityModel slurry;
// 子字典参数见源码

```
## 参数表

见源码头文件字典构造。

## 控制方程与关联式

Thomas' viscosity correction for slurry.



## 文献与源码依据

- [`applications/modules/incompressibleDriftFlux/mixtureViscosityModels/slurry/slurry.H`](../../../applications/modules/incompressibleDriftFlux/mixtureViscosityModels/slurry/slurry.H)

## 教程与模板

- `tutorials/incompressibleDriftFlux/**`

## 注意事项

- 与相对速度 / packingDispersion 模型联用。
