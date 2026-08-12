# `nonUnityLewisEddyDiffusivity`

## 一句话

非统一 Le 涡流扩散

## 适用条件（求解器 / 场 / 前提）

- 与 RAS/LES `momentumTransport` 联用
- `fluid` / `multicomponentFluid` / 相流体 TTM 工厂

## 字典示例

```c++
```
LES
{
model           nonUnityLewisEddyDiffusivity;
Prt             0.85;
Sct             0.7;
}
```
```

## 参数表

湍流模型常见 `Prt`（湍流 Prandtl）；多组分另有 `Sct` / 二元扩散系数表。详见源码。

## 控制方程与关联式

Non-unity-Lewis-Eddy-diffusivity based temperature gradient heat flux model
for RAS or LES of turbulent flow. Allows independent specification of
turbulent Prandtl and Schmidt numbers.  Unity laminar Lewis number is
assumed.

The heat flux source is implemented as an implicit energy correction to the
temperature gradient based flux source.  At convergence the energy
correction is 0.

## 文献与源码依据

- [`src/ThermophysicalTransportModels/fluid/turbulence/nonUnityLewisEddyDiffusivity/nonUnityLewisEddyDiffusivity.H`](../../../src/ThermophysicalTransportModels/fluid/turbulence/nonUnityLewisEddyDiffusivity/nonUnityLewisEddyDiffusivity.H)
- 注册：`src/ThermophysicalTransportModels/**/*ThermophysicalTransportModels.C`

## 教程与模板

- `tutorials/fluid/**/thermophysicalTransport`、`tutorials/multicomponentFluid/**`

## 注意事项

- TTM 的 `simulationType` 必须与动量输运一致（laminar/RAS/LES）。
