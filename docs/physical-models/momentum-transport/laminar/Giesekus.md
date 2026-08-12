# `Giesekus`

## 一句话

Giesekus 粘弹性

## 适用条件（求解器 / 场 / 前提）
- 注册：incompressible / compressible / phaseIncompressible / phaseCompressible / film（子集）
- `simulationType` laminar;` + `model` Giesekus;`

## 字典示例

```c++
// constant/momentumTransport simulationType laminar;
laminar
{
model Giesekus;
turbulence on;
// RAS/LES
}

```
## 参数表

系数通常可在模型子字典覆盖（`Cmu`、`Ck` 等）；默认值见源码 `read`()`。

## 控制方程与关联式

Giesekus model for viscoelasticity using the upper-convected time derivative of the stress tensor with support for multiple modes.



See also
Foam::laminarModels::Maxwell

## 文献与源码依据

- [`src/MomentumTransportModels/momentumTransportModels/laminar/Giesekus/Giesekus.H`](../../../src/MomentumTransportModels/momentumTransportModels/laminar/Giesekus/Giesekus.H)

## 教程与模板

- `tutorials/incompressibleVoF/climbingRod/constant/momentumTransport.liquid`
- `tutorials/incompressibleFluid/planarContraction/constant/momentumTransport`
- `tutorials/compressibleVoF/climbingRod/constant/momentumTransport.liquid`


## 注意事项

- 模型必须在对应库中注册（不可压/可压/相）；见族 README 注册表。
