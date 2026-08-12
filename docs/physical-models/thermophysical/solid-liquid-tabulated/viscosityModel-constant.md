# `constant`

## 一句话

不可压 `physicalProperties` 常粘度模型（`viscosityModel`）。

## 适用条件（求解器 / 场 / 前提）

- 适用: `incompressibleFluid`、`incompressibleVoF` 等无能量/thermo 拼装的求解器
- 不适用: 已用 `thermoType` 提供 μ 的可压能量求解器（粘度来自 transport）

## 字典示例

```c++
// tutorials 常见：constant/physicalProperties
viscosityModel  constant;
nu              [0 2 -1 0 0 0 0] 1e-05;
```

## 参数表

| 参数 | 含义 | 量纲 |
|------|------|------|
| `nu` | 运动粘度 | `[0 2 -1 0 0 0 0]` |

## 控制方程与关联式

A uniform constant Newtonian viscosity model.

## 文献与源码依据

- [`src/physicalProperties/viscosityModels/constant/constantViscosityModel.H`](../../../src/physicalProperties/viscosityModels/constant/constantViscosityModel.H)

## 教程与模板

- `tutorials/incompressibleFluid/**/constant/physicalProperties`

## 注意事项

- 与 `momentumTransport` 的 laminar/RAS 叠加：分子粘度来自此处，湍流粘度来自模型。
