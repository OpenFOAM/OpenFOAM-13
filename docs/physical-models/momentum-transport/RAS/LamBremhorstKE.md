# `LamBremhorstKE`

## 一句话

Lam–Bremhorst 低 Re k–ε（仅不可压）

## 适用条件（求解器 / 场 / 前提）

- **仅 incompressible** 额外 RAS（`incompressible/RAS/...`）
- 不适用: compressible 注册表

## 字典示例

```c++
// constant/momentumTransport
simulationType RAS;

RAS
{
    model           LamBremhorstKE;
    turbulence      on;   // RAS/LES
}
```

## 参数表

系数通常可在模型子字典覆盖（`Cmu`、`Ck` 等）；默认值见源码 `read`()`。

## 控制方程与关联式

Lam and Bremhorst low-Reynolds number k-epsilon turbulence model
for incompressible flows

This turbulence model is described in:
```
Lam, C. K. G., & Bremhorst, K. (1981).
A modified form of the k-ε model for predicting wall turbulence.
Journal of Fluids Engineering, 103(3), 456-460.
```

## 文献与源码依据

- [`src/MomentumTransportModels/incompressible/RAS/LamBremhorstKE/LamBremhorstKE.H`](../../../src/MomentumTransportModels/incompressible/RAS/LamBremhorstKE/LamBremhorstKE.H)

## 教程与模板

- 仓库 tutorials 中未检索到 `LamBremhorstKE` 字面配置；可参考同类 `simulationType` 案例并改 `model`。
- 注册见 [`README`](../README.md) 工厂表。


## 注意事项

- 模型必须在对应库中注册（不可压/可压/相）；见族 README 注册表。
