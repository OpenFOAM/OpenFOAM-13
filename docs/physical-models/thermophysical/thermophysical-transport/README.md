# thermophysicalTransport

配置入口：`constant/thermophysicalTransport`。分支名 **`laminar` / `RAS` / `LES`** 必须与 `momentumTransport`.simulationType` 一致。

注册工厂（摘自 inventory）：

| 工厂 | 典型模型 |
|------|----------|
| `fluidThermoThermophysicalTransportModels`.C` | `Fourier`、`unityLewisFourier`、RAS/LES eddy |
| `fluidMulticomponentThermophysicalTransportModels`.C` | + `Fickian`*`、`MaxwellStefan`*` |
| `phaseFluidThermo`*` / `phaseFluidMulticomponent`*` | 相流体同上子集 |
| `solidThermophysicalTransportModels`.C` / `phaseSolid`*` | `isotropic`、`anisotropic` |

## 层流

- [`Fourier`](Fourier.md)
- [`unityLewisFourier`](unityLewisFourier.md)
- [`Fickian`](Fickian.md)
- [`FickianFourier`](FickianFourier.md)
- [`MaxwellStefan`](MaxwellStefan.md)
- [`MaxwellStefanFourier`](MaxwellStefanFourier.md)

## 湍流

- [`eddyDiffusivity`](eddyDiffusivity.md)
- [`unityLewisEddyDiffusivity`](unityLewisEddyDiffusivity.md)
- [`nonUnityLewisEddyDiffusivity`](nonUnityLewisEddyDiffusivity.md)
- [`FickianEddyDiffusivity`](FickianEddyDiffusivity.md)

## 固体

- [`isotropic`](isotropic.md)
- [`anisotropic`](anisotropic.md)

## 框架

- [`laminarThermophysicalTransportModel`](laminarThermophysicalTransportModel.md)
- [`RASThermophysicalTransportModel`](RASThermophysicalTransportModel.md)
- [`LESThermophysicalTransportModel`](LESThermophysicalTransportModel.md)

导航：[`../README.md`](../README.md)
