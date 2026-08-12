# `generalisedNewtonian`-Casson`

## 一句话

generalisedNewtonian 粘度子模型：Casson

## 适用条件（求解器 / 场 / 前提）

- 父模型：`generalisedNewtonian`
- 子字典 `viscosityModel Casson;`

## 字典示例



> （由源码构造函数推断，无官方教程实例）

```c++
// constant/momentumTransport
simulationType laminar;

laminar
{
    model           generalisedNewtonian;
    viscosityModel  Casson;
    Casson, N. (1959).
            Rheology of disperse systems.
            In Proceedings of a Conference Organised by the
            British Society of Rheology.
            Pergamon Press, New York.

            Fournier, R. L. (2011).
            Basic transport phenomena in biomedical engineering.
            CRC Press.
}
```

## 参数表

系数通常可在模型子字典覆盖（`Cmu`、`Ck` 等）；默认值见源码 `read`()`。

## 控制方程与关联式

Casson generalised Newtonian viscosity model

References:
```
Casson, N. (1959).
Rheology of disperse systems.
In Proceedings of a Conference Organised by the
British Society of Rheology.
Pergamon Press, New York.

Fournier, R. L. (2011).
Basic transport phenomena in biomedical engineering.
CRC Press.
```

Example specification for blood:
```
viscosityModel Casson;

m       3.934986e-6;
tau0    2.9032e-6;
nuMax   13.3333e-6;
nuMin   3.9047e-6;
```

## 文献与源码依据

- [`src/MomentumTransportModels/momentumTransportModels/laminar/generalisedNewtonian/generalisedNewtonianViscosityModels/strainRateViscosityModels/Casson/Casson.H`](../../../src/MomentumTransportModels/momentumTransportModels/laminar/generalisedNewtonian/generalisedNewtonianViscosityModels/strainRateViscosityModels/Casson/Casson.H)

## 教程与模板

- 仓库 tutorials 中未检索到 `Casson` 字面配置；可参考同类 `simulationType` 案例并改 `model`。
- 注册见 [`README`](../README.md) 工厂表。


## 注意事项

- 模型必须在对应库中注册（不可压/可压/相）；见族 README 注册表。
