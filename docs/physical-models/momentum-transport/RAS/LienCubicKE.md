# `LienCubicKE`

## 一句话

Lien 三次 k–ε（仅不可压）

## 适用条件（求解器 / 场 / 前提）

- **仅 incompressible** 额外 RAS（`incompressible/RAS/...`）
- 不适用: compressible 注册表

## 字典示例

```c++
// constant/momentumTransport
simulationType RAS;

RAS
{
    model           LienCubicKE;
    turbulence      on;   // RAS/LES
}
```

## 参数表

系数通常可在模型子字典覆盖（`Cmu`、`Ck` 等）；默认值见源码 `read`()`。

## 控制方程与关联式

Lien cubic non-linear low-Reynolds k-epsilon turbulence models for
incompressible flows.

This turbulence model is described in:
```
Lien, F.S., Chen, W.L. & Leschziner, M.A. (1996).
Low-Reynolds-number eddy-viscosity modeling based on non-linear
stress-strain/vorticity relations.
Engineering Turbulence Modelling and Experiments 3, 91-100.
```

Implemented according to the specification in:
<a href=
"https://personalpages.manchester.ac.uk/staff/david.d.apsley/turbmod.pdf"
>Apsley: Turbulence Models 2002</a>

In addition to the low-Reynolds number damping functions support for
wall-functions is also included to allow for low- and high-Reynolds number
operation.

See also
Foam::incompressible::RASModels::ShihQuadraticKE

## 文献与源码依据

- [`src/MomentumTransportModels/incompressible/RAS/LienCubicKE/LienCubicKE.H`](../../../src/MomentumTransportModels/incompressible/RAS/LienCubicKE/LienCubicKE.H)

## 教程与模板

- `tutorials/incompressibleFluid/pitzDailySteady/constant/momentumTransport`
- `tutorials/incompressibleFluid/pitzDailyScalarTransport/constant/momentumTransport`


## 注意事项

- 模型必须在对应库中注册（不可压/可压/相）；见族 README 注册表。
