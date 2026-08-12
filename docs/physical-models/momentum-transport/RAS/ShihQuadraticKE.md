# `ShihQuadraticKE`

## 一句话

Shih 二次 k–ε（仅不可压）

## 适用条件（求解器 / 场 / 前提）

- **仅 incompressible** 额外 RAS（`incompressible/RAS/...`）
- 不适用: compressible 注册表

## 字典示例

```c++
// constant/momentumTransport
simulationType RAS;

RAS
{
    model           ShihQuadraticKE;
    turbulence      on;   // RAS/LES
}
```

## 参数表

系数通常可在模型子字典覆盖（`Cmu`、`Ck` 等）；默认值见源码 `read`()`。

## 控制方程与关联式

Shih's quadratic algebraic Reynolds stress k-epsilon turbulence model for
incompressible flows

This turbulence model is described in:
```
Shih, T. H., Zhu, J., & Lumley, J. L. (1993).
A realizable Reynolds stress algebraic equation model.
NASA technical memorandum 105993.
```

Implemented according to the specification in:
<a href=
"https://personalpages.manchester.ac.uk/staff/david.d.apsley/turbmod.pdf"
>Apsley: Turbulence Models 2002</a>

## 文献与源码依据

- [`src/MomentumTransportModels/incompressible/RAS/ShihQuadraticKE/ShihQuadraticKE.H`](../../../src/MomentumTransportModels/incompressible/RAS/ShihQuadraticKE/ShihQuadraticKE.H)

## 教程与模板

- `tutorials/incompressibleFluid/pitzDailySteady/constant/momentumTransport`
- `tutorials/incompressibleFluid/pitzDailyScalarTransport/constant/momentumTransport`


## 注意事项

- 模型必须在对应库中注册（不可压/可压/相）；见族 README 注册表。
