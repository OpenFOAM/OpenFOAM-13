# `cubeRootVolDelta`

## 一句话

Δ = V^{1/3}

## 适用条件（求解器 / 场 / 前提）

- LES `delta` 模型：`delta` cubeRootVolDelta;`
- 所有 LES 求解路径

## 字典示例



> （由源码构造函数推断，无官方教程实例）

```c++
// constant/momentumTransport
simulationType LES;

LES
{
    model           cubeRootVolDelta;
    turbulence      on;
}
```

## 参数表

系数通常可在模型子字典覆盖（`Cmu`、`Ck` 等）；默认值见源码 `read`()`。

## 控制方程与关联式

Simple cube-root of cell volume delta used in LES SGS models.

## 文献与源码依据

- [`src/MomentumTransportModels/momentumTransportModels/LES/LESdeltas/cubeRootVolDelta/cubeRootVolDelta.H`](../../../src/MomentumTransportModels/momentumTransportModels/LES/LESdeltas/cubeRootVolDelta/cubeRootVolDelta.H)

## 教程与模板

- 仓库 tutorials 中未检索到 `cubeRootVolDelta` 字面配置；可参考同类 `simulationType` 案例并改 `model`。
- 注册见 [`README`](../README.md) 工厂表。


## 注意事项

- 模型必须在对应库中注册（不可压/可压/相）；见族 README 注册表。
