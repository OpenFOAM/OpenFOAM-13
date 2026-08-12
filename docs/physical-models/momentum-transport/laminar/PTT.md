# `PTT`

## 一句话

Phan–Thien–Tanner 粘弹性

## 适用条件（求解器 / 场 / 前提）
- 注册：incompressible / compressible / phaseIncompressible / phaseCompressible / film（子集）
- `simulationType` laminar;` + `model` PTT;`

## 字典示例

```c++
// constant/momentumTransport simulationType laminar;
laminar
{
model PTT;
turbulence on;
// RAS/LES
}

```
## 参数表

系数通常可在模型子字典覆盖（`Cmu`、`Ck` 等）；默认值见源码 `read`()`。

## 控制方程与关联式

PTT model for viscoelasticity using the upper-convected time derivative of the stress tensor with support for multiple modes.



See also
Foam::laminarModels::Maxwell
Foam::laminarModels::Giesekus

## 文献与源码依据

- [`src/MomentumTransportModels/momentumTransportModels/laminar/PTT/PTT.H`](../../../src/MomentumTransportModels/momentumTransportModels/laminar/PTT/PTT.H)

## 教程与模板

- `tutorials/incompressibleFluid/planarContraction/constant/momentumTransport`


## 注意事项

- 模型必须在对应库中注册（不可压/可压/相）；见族 README 注册表。
