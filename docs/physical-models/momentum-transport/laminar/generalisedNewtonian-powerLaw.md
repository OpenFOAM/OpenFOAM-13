# `generalisedNewtonian`-powerLaw`

## 一句话

generalisedNewtonian 粘度子模型：幂律

## 适用条件（求解器 / 场 / 前提）

- 父模型：`generalisedNewtonian`
- 子字典 `viscosityModel powerLaw;`

## 字典示例



> （由源码构造函数推断，无官方教程实例）

```c++
// constant/momentumTransport
simulationType laminar;

laminar
{
    model           generalisedNewtonian;
    viscosityModel  powerLaw;

             nuMax      1e-3;
             nuMin      1e-5;
             k          1;
             n          0.5;
}
```

## 参数表


| 参数 | 默认/示例 | 说明 |
|------|-----------|------|
| `nuMax` | 1e-3 | Usage |
| `nuMin` | 1e-5 | Usage |
| `k` | 1 | Usage |
| `n` | 0.5 | Usage |

正确写法：`laminar`.model = generalisedNewtonian`，再设 `viscosityModel powerLaw;`（不是 `model` generalisedNewtonian-powerLaw`）。

## 控制方程与关联式

Standard power-law generalised Newtonian viscosity model

The power-law model provides a function for viscosity, limited by
minimum and maximum values $
u_{\min}$ and $
u_{\max}$
respectively.

Kinematic viscosity [m^2/s]

$$

u = k\gamma^{n - 1}, 
u_{\min} \le 
u \le 
u_{\max}
$$

Example specification:
```
viscosityModel powerLaw;

nuMax      1e-3;
nuMin      1e-5;
k          1;
n          0.5;
```

## 文献与源码依据

- [`src/MomentumTransportModels/momentumTransportModels/laminar/generalisedNewtonian/generalisedNewtonianViscosityModels/strainRateViscosityModels/powerLaw/powerLaw.H`](../../../src/MomentumTransportModels/momentumTransportModels/laminar/generalisedNewtonian/generalisedNewtonianViscosityModels/strainRateViscosityModels/powerLaw/powerLaw.H)

## 教程与模板

- 仓库 tutorials 中未检索到 `powerLaw` 字面配置；可参考同类 `simulationType` 案例并改 `model`。
- 注册见 [`README`](../README.md) 工厂表。


## 注意事项

- 模型必须在对应库中注册（不可压/可压/相）；见族 README 注册表。
