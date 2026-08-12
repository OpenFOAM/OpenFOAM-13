# `unityLewisEddyDiffusivity`

## 一句话

统一 Le 涡流扩散

## 适用条件（求解器 / 场 / 前提）

- 与 RAS/LES `momentumTransport` 联用
- `fluid` / `multicomponentFluid` / 相流体 TTM 工厂

## 字典示例

```c++
```
LES
{
model           unityLewisEddyDiffusivity;
Prt             0.85;
}
```
```

## 参数表

湍流模型常见 `Prt`（湍流 Prandtl）；多组分另有 `Sct` / 二元扩散系数表。详见源码。

## 控制方程与关联式

Eddy-diffusivity based energy gradient heat flux model for RAS or LES
of turbulent flow.  Specie fluxes are computed assuming a unity turbulent
Lewis number.

## 文献与源码依据

- [`src/ThermophysicalTransportModels/fluid/turbulence/unityLewisEddyDiffusivity/unityLewisEddyDiffusivity.H`](../../../src/ThermophysicalTransportModels/fluid/turbulence/unityLewisEddyDiffusivity/unityLewisEddyDiffusivity.H)
- 注册：`src/ThermophysicalTransportModels/**/*ThermophysicalTransportModels.C`

## 教程与模板

- `tutorials/fluid/**/thermophysicalTransport`、`tutorials/multicomponentFluid/**`

## 注意事项

- TTM 的 `simulationType` 必须与动量输运一致（laminar/RAS/LES）。
