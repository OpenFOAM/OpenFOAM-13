# `generalisedNewtonian`-strainRateFunction`

## 一句话

generalisedNewtonian 粘度子模型：任意应变率函数

## 适用条件（求解器 / 场 / 前提）

- 父模型：`generalisedNewtonian`
- 子字典 `viscosityModel strainRateFunction;`

## 字典示例



> （由源码构造函数推断，无官方教程实例）

```c++
// constant/momentumTransport
simulationType laminar;

laminar
{
    model           generalisedNewtonian;
    viscosityModel  strainRateFunction;
    strainRateModel strainRateFunction;

            function polynomial ((0 0.1) (1 1.3));
}
```

## 参数表


| 参数 | 默认/示例 | 说明 |
|------|-----------|------|
| `strainRateModel` | strainRateFunction | Usage |
| `function` | polynomial ((0 0.1) (1 1.3)) | Usage |

正确写法：`laminar`.model = generalisedNewtonian`，再设 `viscosityModel strainRateFunction;`（不是 `model` generalisedNewtonian-strainRateFunction`）。

## 控制方程与关联式

Run-time selected strain-rate function generalised Newtonian viscosity model

Example linear function of strain-rate:
```
strainRateModel strainRateFunction;

function polynomial ((0 0.1) (1 1.3));
```

See also
Foam::strainRateViscosityModel
Foam::Function1

## 文献与源码依据

- [`src/MomentumTransportModels/momentumTransportModels/laminar/generalisedNewtonian/generalisedNewtonianViscosityModels/strainRateViscosityModels/strainRateFunction/strainRateFunction.H`](../../../src/MomentumTransportModels/momentumTransportModels/laminar/generalisedNewtonian/generalisedNewtonianViscosityModels/strainRateViscosityModels/strainRateFunction/strainRateFunction.H)

## 教程与模板

- 仓库 tutorials 中未检索到 `strainRateFunction` 字面配置；可参考同类 `simulationType` 案例并改 `model`。
- 注册见 [`README`](../README.md) 工厂表。


## 注意事项

- 模型必须在对应库中注册（不可压/可压/相）；见族 README 注册表。
