# `isotropic`

## 一句话

固体各向同性热输运

## 适用条件（求解器 / 场 / 前提）

- 适用: `solid` / `solidDisplacement` / 相固体
- `constant/thermophysicalTransport` 中 `type` isotropic;`（或 isotropic/anisotropic 注册名）

## 字典示例

```c++
// constant/thermophysicalTransport（固体）
type isotropic;
```

## 参数表

湍流模型常见 `Prt`（湍流 Prandtl）；多组分另有 `Sct` / 二元扩散系数表。详见源码。

## 控制方程与关联式

Solid thermophysical transport model for isotropic thermal conductivity

This is the default transport model for solids and selected automatically if
the thermophysicalTransport dictionary is not present in the constant or
region directory.

## 文献与源码依据

- [`src/ThermophysicalTransportModels/solid/isotropic/isotropic.H`](../../../src/ThermophysicalTransportModels/solid/isotropic/isotropic.H)
- 注册：`src/ThermophysicalTransportModels/**/*ThermophysicalTransportModels.C`

## 教程与模板

- `tutorials/fluid/**/thermophysicalTransport`、`tutorials/multicomponentFluid/**`

## 注意事项

- TTM 的 `simulationType` 必须与动量输运一致（laminar/RAS/LES）。
