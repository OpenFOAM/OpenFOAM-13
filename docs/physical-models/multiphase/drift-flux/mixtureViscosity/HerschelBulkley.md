# HerschelBulkley

## 一句话
HerschelBulkley viscosity model

## 适用条件（求解器 / 场 / 前提）
- 适用: incompressibleDriftFlux
- **族**: 混合物粘度（基类 `mixtureViscosityModel`）
- **注册名**: `HerschelBulkley`

## 字典示例
```
viscosityModel HerschelBulkley;

rho        1996; // Dispersed phase density

tau0       10.0;
k          0.001;
n          0.2;
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `HerschelBulkley`
- 基类: `mixtureViscosityModel`


## 控制方程与关联式
HerschelBulkley viscosity model

The Herschel-Bulkley model combines the effects of a Bingham plastic
and power-law behaviour of a fluid. At a low strain rate $$
the fluid adopts a viscosity $_0$. Beyond a threshold stress
$_0$, the viscosity is described as a power law.

Kinematic viscosity [m^2/s]

[
= (_0, (_0 + k^{n})/)
]

## 文献与源码依据
- 类: `Foam`::mixtureViscosityModels::HerschelBulkley`
- 源码路径: `applications/modules/incompressibleDriftFlux/mixtureViscosityModels/HerschelBulkley/HerschelBulkley.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`HerschelBulkley`。
