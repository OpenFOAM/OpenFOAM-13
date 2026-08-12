# `FickianEddyDiffusivity`

## 一句话

Fickian + 涡流扩散

## 适用条件（求解器 / 场 / 前提）

- 与 RAS/LES `momentumTransport` 联用
- `fluid` / `multicomponentFluid` / 相流体 TTM 工厂

## 字典示例

```
RAS
{
model           FickianEddyDiffusivity;

mixtureDiffusionCoefficients yes;

Prt             0.85;
Sct             0.7;

Dm // [m^2/s]
{
O2 1e-2;
O3 5e-2;
N2 1e-2;
}

DT // [kg/m/s] Optional
{
O2 1e-2;
O3 5e-2;
N2 1e-2;
}
}

```c++
or if binary mass diffusion coefficient functions are available they can be
mixed to form the mass diffusion coefficients w.r.t. the mixture:

```
RAS
{
model           FickianEddyDiffusivity;

mixtureDiffusionCoefficients no;

Prt             0.85;
Sct             0.7;

D // [m^2/s]
{
O2-O2 1e-2;
O3-O3 5e-2;
N2-N2 1e-2;
O3-O2 5e-2;
O3-N2 5e-2;
O2-N2 1e-2;
}

DT // [kg/m/s] Optional
{
O2 1e-2;
O3 5e-2;
N2 1e-2;
}
}
```

## 参数表

湍流模型常见 `Prt`（湍流 Prandtl）；多组分另有 `Sct` / 二元扩散系数表。详见源码。

## 控制方程与关联式

Multi-component Fickian and eddy-diffusivity turbulent based temperature
gradient heat flux model for RAS or LES of turbulent flow with optional
Soret thermal diffusion of species.

The mixture diffusion coefficients are specified as Function2<scalar>s of
pressure and temperature but independent of composition.

The heat flux source is implemented as an implicit energy correction to the
temperature gradient based flux source.  At convergence the energy
correction is 0.

## 文献与源码依据

- [`src/ThermophysicalTransportModels/fluid/turbulence/FickianEddyDiffusivity/FickianEddyDiffusivity.H`](../../../src/ThermophysicalTransportModels/fluid/turbulence/FickianEddyDiffusivity/FickianEddyDiffusivity.H)
- 注册：`src/ThermophysicalTransportModels/**/*ThermophysicalTransportModels.C`

## 教程与模板

- `tutorials/fluid/**/thermophysicalTransport`、`tutorials/multicomponentFluid/**`

## 注意事项

- TTM 的 `simulationType` 必须与动量输运一致（laminar/RAS/LES）。
