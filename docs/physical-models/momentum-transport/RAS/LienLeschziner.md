# `LienLeschziner`

## 一句话

Lien–Leschziner（仅不可压）

## 适用条件（求解器 / 场 / 前提）

- **仅 incompressible** 额外 RAS（`incompressible/RAS/...`）
- 不适用: compressible 注册表

## 字典示例

```c++
// constant/momentumTransport
simulationType RAS;

RAS
{
    model           LienLeschziner;
    turbulence      on;   // RAS/LES
}
```

## 参数表

系数通常可在模型子字典覆盖（`Cmu`、`Ck` 等）；默认值见源码 `read`()`。

## 控制方程与关联式

Lien and Leschziner low-Reynolds number k-epsilon turbulence model for
incompressible flows.

This turbulence model is described in:
```
Lien, F. S., & Leschziner, M. A. (1993).
A pressure-velocity solution strategy for compressible flow
and its application to shock/boundary-layer interaction
using second-moment turbulence closure.
Journal of fluids engineering, 115(4), 717-725.
```

Implemented according to the specification in:
<a href=
"https://personalpages.manchester.ac.uk/staff/david.d.apsley/turbmod.pdf"
>Apsley: Turbulence Models 2002</a>

In addition to the low-Reynolds number damping functions support for
wall-functions is also included to allow for low- and high-Reynolds number
operation.

## 文献与源码依据

- [`src/MomentumTransportModels/incompressible/RAS/LienLeschziner/LienLeschziner.H`](../../../src/MomentumTransportModels/incompressible/RAS/LienLeschziner/LienLeschziner.H)

## 教程与模板

- 仓库 tutorials 中未检索到 `LienLeschziner` 字面配置；可参考同类 `simulationType` 案例并改 `model`。
- 注册见 [`README`](../README.md) 工厂表。


## 注意事项

- 模型必须在对应库中注册（不可压/可压/相）；见族 README 注册表。
