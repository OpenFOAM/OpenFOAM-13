# `qZeta`

## 一句话

q–ζ（仅不可压）

## 适用条件（求解器 / 场 / 前提）

- **仅 incompressible** 额外 RAS（`incompressible/RAS/...`）
- 不适用: compressible 注册表

## 字典示例

```c++
// constant/momentumTransport
simulationType RAS;

RAS
{
    model           qZeta;
    turbulence      on;   // RAS/LES
}
```

## 参数表

系数通常可在模型子字典覆盖（`Cmu`、`Ck` 等）；默认值见源码 `read`()`。

## 控制方程与关联式

Gibson and Dafa'Alla's q-zeta two-equation low-Re turbulence model
for incompressible flows

This turbulence model is described in:
```
Dafa'Alla, A.A., Juntasaro, E. & Gibson, M.M. (1996).
Calculation of oscillating boundary layers with the
q-zeta turbulence model.
Engineering Turbulence Modelling and Experiments 3:
Proceedings of the Third International Symposium,
Crete, Greece, May 27-29, 141.
```
which is a development of the original q-zeta model described in:
```
Gibson, M. M., & Dafa'Alla, A. A. (1995).
Two-equation model for turbulent wall flow.
AIAA journal, 33(8), 1514-1518.
```

## 文献与源码依据

- [`src/MomentumTransportModels/incompressible/RAS/qZeta/qZeta.H`](../../../src/MomentumTransportModels/incompressible/RAS/qZeta/qZeta.H)

## 教程与模板

- 仓库 tutorials 中未检索到 `qZeta` 字面配置；可参考同类 `simulationType` 案例并改 `model`。
- 注册见 [`README`](../README.md) 工厂表。


## 注意事项

- 模型必须在对应库中注册（不可压/可压/相）；见族 README 注册表。
