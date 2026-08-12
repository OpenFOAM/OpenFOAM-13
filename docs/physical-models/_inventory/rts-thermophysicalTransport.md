# 热输运 thermophysicalTransport RTS 清单

> 机器生成清单（Phase 0）。

来自 `src/ThermophysicalTransportModels` 与 multiphaseEuler 相关注册/目录。

**条目数**: 49

| 类型名 | 基类/宏键 | 源码路径 | 备注 |
|--------|-----------|----------|------|
| `FickianEddyDiffusivity` | `directory` | `src/ThermophysicalTransportModels/fluid/turbulence/FickianEddyDiffusivity` | TTM directory |
| `PhaseThermophysicalTransportModel` | `directory` | `src/ThermophysicalTransportModels/fluid/PhaseThermophysicalTransportModel` | TTM directory |
| `ThermophysicalTransportModel` | `directory` | `src/ThermophysicalTransportModels/fluid/ThermophysicalTransportModel` | TTM directory |
| `anisotropic` | `directory` | `src/ThermophysicalTransportModels/solid/anisotropic` | TTM directory |
| `eddyDiffusivity` | `directory` | `src/ThermophysicalTransportModels/fluid/turbulence/eddyDiffusivity` | TTM directory |
| `fluidThermophysicalTransportModel` | `directory` | `src/ThermophysicalTransportModels/fluid/fluidThermophysicalTransportModel` | TTM directory |
| `isotropic` | `directory` | `src/ThermophysicalTransportModels/solid/isotropic` | TTM directory |
| `nonUnityLewisEddyDiffusivity` | `directory` | `src/ThermophysicalTransportModels/fluid/turbulence/nonUnityLewisEddyDiffusivity` | TTM directory |
| `phaseSolidThermophysicalTransportModel` | `directory` | `src/ThermophysicalTransportModels/phaseSolid/phaseSolidThermophysicalTransportModel` | TTM directory |
| `solidThermophysicalTransportModel` | `directory` | `src/ThermophysicalTransportModels/solid/solidThermophysicalTransportModel` | TTM directory |
| `thermophysicalTransportModel` | `directory` | `src/ThermophysicalTransportModels/thermophysicalTransportModel` | TTM directory |
| `unityLewisEddyDiffusivity` | `directory` | `src/ThermophysicalTransportModels/fluid/turbulence/unityLewisEddyDiffusivity` | TTM directory |
| `LESThermophysicalTransportModel` | `directory` | `src/ThermophysicalTransportModels/fluid/turbulence/LES/LESThermophysicalTransportModel` | TTM directory; LES |
| `RASThermophysicalTransportModel` | `directory` | `src/ThermophysicalTransportModels/fluid/turbulence/RAS/RASThermophysicalTransportModel` | TTM directory; RAS |
| `Fickian` | `directory` | `src/ThermophysicalTransportModels/fluid/laminar/Fickian` | TTM directory; laminar |
| `FickianFourier` | `directory` | `src/ThermophysicalTransportModels/fluid/laminar/FickianFourier` | TTM directory; laminar |
| `Fourier` | `directory` | `src/ThermophysicalTransportModels/fluid/laminar/Fourier` | TTM directory; laminar |
| `MaxwellStefan` | `directory` | `src/ThermophysicalTransportModels/fluid/laminar/MaxwellStefan` | TTM directory; laminar |
| `MaxwellStefanFourier` | `directory` | `src/ThermophysicalTransportModels/fluid/laminar/MaxwellStefanFourier` | TTM directory; laminar |
| `laminarThermophysicalTransportModel` | `directory` | `src/ThermophysicalTransportModels/fluid/laminar/laminarThermophysicalTransportModel` | TTM directory; laminar |
| `unityLewisFourier` | `directory` | `src/ThermophysicalTransportModels/fluid/laminar/unityLewisFourier` | TTM directory; laminar |
| `FickianFourier` | `make*ThermophysicalTransport*` | `src/ThermophysicalTransportModels/fluidMulticomponentThermo/fluidMulticomponentThermophysicalTransportModels.C` | macro |
| `FickianFourier` | `make*ThermophysicalTransport*` | `src/ThermophysicalTransportModels/phaseFluidMulticomponentThermo/phaseFluidMulticomponentThermophysicalTransportModels.C` | macro |
| `Fourier` | `make*ThermophysicalTransport*` | `src/ThermophysicalTransportModels/fluidMulticomponentThermo/fluidMulticomponentThermophysicalTransportModels.C` | macro |
| `Fourier` | `make*ThermophysicalTransport*` | `src/ThermophysicalTransportModels/fluidThermo/fluidThermoThermophysicalTransportModels.C` | macro |
| `Fourier` | `make*ThermophysicalTransport*` | `src/ThermophysicalTransportModels/phaseFluidMulticomponentThermo/phaseFluidMulticomponentThermophysicalTransportModels.C` | macro |
| `Fourier` | `make*ThermophysicalTransport*` | `src/ThermophysicalTransportModels/phaseFluidThermo/phaseFluidThermophysicalTransportModels.C` | macro |
| `LES` | `make*ThermophysicalTransport*` | `src/ThermophysicalTransportModels/fluidMulticomponentThermo/fluidMulticomponentThermophysicalTransportModels.C` | macro |
| `LES` | `make*ThermophysicalTransport*` | `src/ThermophysicalTransportModels/fluidThermo/fluidThermoThermophysicalTransportModels.C` | macro |
| `LES` | `make*ThermophysicalTransport*` | `src/ThermophysicalTransportModels/phaseFluidMulticomponentThermo/phaseFluidMulticomponentThermophysicalTransportModels.C` | macro |
| `LES` | `make*ThermophysicalTransport*` | `src/ThermophysicalTransportModels/phaseFluidThermo/phaseFluidThermophysicalTransportModels.C` | macro |
| `MaxwellStefanFourier` | `make*ThermophysicalTransport*` | `src/ThermophysicalTransportModels/fluidMulticomponentThermo/fluidMulticomponentThermophysicalTransportModels.C` | macro |
| `MaxwellStefanFourier` | `make*ThermophysicalTransport*` | `src/ThermophysicalTransportModels/phaseFluidMulticomponentThermo/phaseFluidMulticomponentThermophysicalTransportModels.C` | macro |
| `PhaseThermophysicalTransportModel` | `make*ThermophysicalTransport*` | `src/ThermophysicalTransportModels/phaseFluidMulticomponentThermo/phaseFluidMulticomponentThermophysicalTransportModels.C` | macro |
| `PhaseThermophysicalTransportModel` | `make*ThermophysicalTransport*` | `src/ThermophysicalTransportModels/phaseFluidThermo/phaseFluidThermophysicalTransportModels.C` | macro |
| `RAS` | `make*ThermophysicalTransport*` | `src/ThermophysicalTransportModels/fluidMulticomponentThermo/fluidMulticomponentThermophysicalTransportModels.C` | macro |
| `RAS` | `make*ThermophysicalTransport*` | `src/ThermophysicalTransportModels/fluidThermo/fluidThermoThermophysicalTransportModels.C` | macro |
| `RAS` | `make*ThermophysicalTransport*` | `src/ThermophysicalTransportModels/phaseFluidMulticomponentThermo/phaseFluidMulticomponentThermophysicalTransportModels.C` | macro |
| `RAS` | `make*ThermophysicalTransport*` | `src/ThermophysicalTransportModels/phaseFluidThermo/phaseFluidThermophysicalTransportModels.C` | macro |
| `ThermophysicalTransportModel` | `make*ThermophysicalTransport*` | `src/ThermophysicalTransportModels/fluidMulticomponentThermo/fluidMulticomponentThermophysicalTransportModels.C` | macro |
| `ThermophysicalTransportModel` | `make*ThermophysicalTransport*` | `src/ThermophysicalTransportModels/fluidThermo/fluidThermoThermophysicalTransportModels.C` | macro |
| `unityLewisFourier` | `make*ThermophysicalTransport*` | `src/ThermophysicalTransportModels/fluidMulticomponentThermo/fluidMulticomponentThermophysicalTransportModels.C` | macro |
| `unityLewisFourier` | `make*ThermophysicalTransport*` | `src/ThermophysicalTransportModels/fluidThermo/fluidThermoThermophysicalTransportModels.C` | macro |
| `unityLewisFourier` | `make*ThermophysicalTransport*` | `src/ThermophysicalTransportModels/phaseFluidMulticomponentThermo/phaseFluidMulticomponentThermophysicalTransportModels.C` | macro |
| `unityLewisFourier` | `make*ThermophysicalTransport*` | `src/ThermophysicalTransportModels/phaseFluidThermo/phaseFluidThermophysicalTransportModels.C` | macro |
| `anisotropicSolidThermophysicalTransportModel` | `phaseSolidThermophysicalTransportModel` | `src/ThermophysicalTransportModels/phaseSolid/phaseSolidThermophysicalTransportModels.C` | thermophysicalTransport; solid |
| `anisotropicSolidThermophysicalTransportModel` | `solidThermophysicalTransportModel` | `src/ThermophysicalTransportModels/solid/solidThermophysicalTransportModels.C` | thermophysicalTransport; solid |
| `isotropicSolidThermophysicalTransportModel` | `phaseSolidThermophysicalTransportModel` | `src/ThermophysicalTransportModels/phaseSolid/phaseSolidThermophysicalTransportModels.C` | thermophysicalTransport; solid |
| `isotropicSolidThermophysicalTransportModel` | `solidThermophysicalTransportModel` | `src/ThermophysicalTransportModels/solid/solidThermophysicalTransportModels.C` | thermophysicalTransport; solid |
