# `generalisedNewtonian`

## 一句话

广义牛顿流体层流

## 适用条件（求解器 / 场 / 前提）

- 注册：incompressible / compressible / phaseIncompressible / phaseCompressible / film（子集）
- `simulationType` laminar;` + `model` generalisedNewtonian;`

## 字典示例

```c++
// constant/momentumTransport
simulationType laminar;

laminar
{
    model           generalisedNewtonian;
    turbulence      on;   // RAS/LES
}
```

## 参数表

系数通常可在模型子字典覆盖（`Cmu`、`Ck` 等）；默认值见源码 `read`()`。

## 控制方程与关联式

Momentum transport model for shear-dependent Non-Newtonian flow.

## 文献与源码依据

- [`src/MomentumTransportModels/momentumTransportModels/laminar/generalisedNewtonian/generalisedNewtonian.H`](../../../src/MomentumTransportModels/momentumTransportModels/laminar/generalisedNewtonian/generalisedNewtonian.H)

## 教程与模板

- `tutorials/incompressibleFluid/offsetCylinder/constant/momentumTransport`


## 注意事项

- 模型必须在对应库中注册（不可压/可压/相）；见族 README 注册表。
