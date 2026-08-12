# 动量输运（laminar/RAS/LES/相专用）RTS 清单

> 机器生成清单（Phase 0）。由源码 RTS / make* 宏检索得到；供后续 Phase 逐条撰写。

来自 `MomentumTransportModels`、`TurbulenceModels` 及 multiphaseEuler/film 相专用注册。

**条目数**: 113

| 类型名 | 基类/宏键 | 源码路径 | 备注 |
|--------|-----------|----------|------|
| `DeardorffDiffStress` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/compressible/compressibleMomentumTransportModels.C` | compressible |
| `DeardorffDiffStress` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/incompressible/incompressibleMomentumTransportModels.C` | compressible |
| `Giesekus` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/compressible/compressibleMomentumTransportModels.C` | compressible |
| `Giesekus` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/incompressible/incompressibleMomentumTransportModels.C` | compressible |
| `LRR` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/compressible/compressibleMomentumTransportModels.C` | compressible |
| `LRR` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/incompressible/incompressibleMomentumTransportModels.C` | compressible |
| `LaunderSharmaKE` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/compressible/compressibleMomentumTransportModels.C` | compressible |
| `LaunderSharmaKE` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/incompressible/incompressibleMomentumTransportModels.C` | compressible |
| `Maxwell` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/compressible/compressibleMomentumTransportModels.C` | compressible |
| `Maxwell` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/incompressible/incompressibleMomentumTransportModels.C` | compressible |
| `PTT` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/compressible/compressibleMomentumTransportModels.C` | compressible |
| `PTT` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/incompressible/incompressibleMomentumTransportModels.C` | compressible |
| `RNGkEpsilon` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/compressible/compressibleMomentumTransportModels.C` | compressible |
| `RNGkEpsilon` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/incompressible/incompressibleMomentumTransportModels.C` | compressible |
| `SSG` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/compressible/compressibleMomentumTransportModels.C` | compressible |
| `SSG` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/incompressible/incompressibleMomentumTransportModels.C` | compressible |
| `Smagorinsky` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/compressible/compressibleMomentumTransportModels.C` | compressible |
| `Smagorinsky` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/incompressible/incompressibleMomentumTransportModels.C` | compressible |
| `SpalartAllmaras` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/compressible/compressibleMomentumTransportModels.C` | compressible |
| `SpalartAllmaras` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/incompressible/incompressibleMomentumTransportModels.C` | compressible |
| `SpalartAllmarasDDES` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/compressible/compressibleMomentumTransportModels.C` | compressible |
| `SpalartAllmarasDDES` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/incompressible/incompressibleMomentumTransportModels.C` | compressible |
| `SpalartAllmarasDES` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/compressible/compressibleMomentumTransportModels.C` | compressible |
| `SpalartAllmarasDES` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/incompressible/incompressibleMomentumTransportModels.C` | compressible |
| `SpalartAllmarasIDDES` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/compressible/compressibleMomentumTransportModels.C` | compressible |
| `SpalartAllmarasIDDES` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/incompressible/incompressibleMomentumTransportModels.C` | compressible |
| `Stokes` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/compressible/compressibleMomentumTransportModels.C` | compressible |
| `Stokes` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/incompressible/incompressibleMomentumTransportModels.C` | compressible |
| `WALE` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/compressible/compressibleMomentumTransportModels.C` | compressible |
| `WALE` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/incompressible/incompressibleMomentumTransportModels.C` | compressible |
| `buoyantKEpsilon` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/compressible/compressibleMomentumTransportModels.C` | compressible |
| `dynamicKEqn` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/compressible/compressibleMomentumTransportModels.C` | compressible |
| `dynamicKEqn` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/incompressible/incompressibleMomentumTransportModels.C` | compressible |
| `dynamicLagrangian` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/compressible/compressibleMomentumTransportModels.C` | compressible |
| `dynamicLagrangian` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/incompressible/incompressibleMomentumTransportModels.C` | compressible |
| `generalisedNewtonian` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/compressible/compressibleMomentumTransportModels.C` | compressible |
| `generalisedNewtonian` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/incompressible/incompressibleMomentumTransportModels.C` | compressible |
| `kEpsilon` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/compressible/compressibleMomentumTransportModels.C` | compressible |
| `kEpsilon` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/incompressible/incompressibleMomentumTransportModels.C` | compressible |
| `kEqn` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/compressible/compressibleMomentumTransportModels.C` | compressible |
| `kEqn` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/incompressible/incompressibleMomentumTransportModels.C` | compressible |
| `kOmega` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/compressible/compressibleMomentumTransportModels.C` | compressible |
| `kOmega` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/incompressible/incompressibleMomentumTransportModels.C` | compressible |
| `kOmega2006` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/compressible/compressibleMomentumTransportModels.C` | compressible |
| `kOmega2006` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/incompressible/incompressibleMomentumTransportModels.C` | compressible |
| `kOmegaSST` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/compressible/compressibleMomentumTransportModels.C` | compressible |
| `kOmegaSST` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/incompressible/incompressibleMomentumTransportModels.C` | compressible |
| `kOmegaSSTDES` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/compressible/compressibleMomentumTransportModels.C` | compressible |
| `kOmegaSSTDES` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/incompressible/incompressibleMomentumTransportModels.C` | compressible |
| `kOmegaSSTLM` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/compressible/compressibleMomentumTransportModels.C` | compressible |
| `kOmegaSSTLM` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/incompressible/incompressibleMomentumTransportModels.C` | compressible |
| `kOmegaSSTSAS` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/compressible/compressibleMomentumTransportModels.C` | compressible |
| `kOmegaSSTSAS` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/incompressible/incompressibleMomentumTransportModels.C` | compressible |
| `lambdaThixotropic` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/compressible/compressibleMomentumTransportModels.C` | compressible |
| `lambdaThixotropic` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/incompressible/incompressibleMomentumTransportModels.C` | compressible |
| `realizableKE` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/compressible/compressibleMomentumTransportModels.C` | compressible |
| `realizableKE` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/incompressible/incompressibleMomentumTransportModels.C` | compressible |
| `v2f` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/compressible/compressibleMomentumTransportModels.C` | compressible |
| `v2f` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/incompressible/incompressibleMomentumTransportModels.C` | compressible |
| `LamBremhorstKE` | `RASincompressibleMomentumTransportModel` | `src/MomentumTransportModels/incompressible/RAS/LamBremhorstKE/LamBremhorstKE.C` | compressible; RAS |
| `LienCubicKE` | `RASincompressibleMomentumTransportModel` | `src/MomentumTransportModels/incompressible/RAS/LienCubicKE/LienCubicKE.C` | compressible; RAS |
| `LienLeschziner` | `RASincompressibleMomentumTransportModel` | `src/MomentumTransportModels/incompressible/RAS/LienLeschziner/LienLeschziner.C` | compressible; RAS |
| `ShihQuadraticKE` | `RASincompressibleMomentumTransportModel` | `src/MomentumTransportModels/incompressible/RAS/ShihQuadraticKE/ShihQuadraticKE.C` | compressible; RAS |
| `kkLOmega` | `RASincompressibleMomentumTransportModel` | `src/MomentumTransportModels/incompressible/RAS/kkLOmega/kkLOmega.C` | compressible; RAS |
| `qZeta` | `RASincompressibleMomentumTransportModel` | `src/MomentumTransportModels/incompressible/RAS/qZeta/qZeta.C` | compressible; RAS |
| `IDDESDelta` | `LESdelta` | `src/MomentumTransportModels/momentumTransportModels/LES/LESdeltas/IDDESDelta/IDDESDelta.C` | core; LES |
| `PrandtlDelta` | `LESdelta` | `src/MomentumTransportModels/momentumTransportModels/LES/LESdeltas/PrandtlDelta/PrandtlDelta.C` | core; LES |
| `anisotropicFilter` | `LESfilter` | `src/MomentumTransportModels/momentumTransportModels/LES/LESfilters/anisotropicFilter/anisotropicFilter.C` | core; LES |
| `cubeRootVolDelta` | `LESdelta` | `src/MomentumTransportModels/momentumTransportModels/LES/LESdeltas/cubeRootVolDelta/cubeRootVolDelta.C` | core; LES |
| `laplaceFilter` | `LESfilter` | `src/MomentumTransportModels/momentumTransportModels/LES/LESfilters/laplaceFilter/laplaceFilter.C` | core; LES |
| `maxDeltaxyz` | `LESdelta` | `src/MomentumTransportModels/momentumTransportModels/LES/LESdeltas/maxDeltaxyz/maxDeltaxyz.C` | core; LES |
| `simpleFilter` | `LESfilter` | `src/MomentumTransportModels/momentumTransportModels/LES/LESfilters/simpleFilter/simpleFilter.C` | core; LES |
| `smoothDelta` | `LESdelta` | `src/MomentumTransportModels/momentumTransportModels/LES/LESdeltas/smoothDelta/smoothDelta.C` | core; LES |
| `vanDriestDelta` | `LESdelta` | `src/MomentumTransportModels/momentumTransportModels/LES/LESdeltas/vanDriestDelta/vanDriestDelta.C` | core; LES |
| `Giesekus` | `makeRAS/LES/LaminarModel` | `applications/modules/isothermalFilm/filmCompressibleMomentumTransportModels/filmCompressibleMomentumTransportModels.C` | film; core |
| `Maxwell` | `makeRAS/LES/LaminarModel` | `applications/modules/isothermalFilm/filmCompressibleMomentumTransportModels/filmCompressibleMomentumTransportModels.C` | film; core |
| `PTT` | `makeRAS/LES/LaminarModel` | `applications/modules/isothermalFilm/filmCompressibleMomentumTransportModels/filmCompressibleMomentumTransportModels.C` | film; core |
| `Stokes` | `makeRAS/LES/LaminarModel` | `applications/modules/isothermalFilm/filmCompressibleMomentumTransportModels/filmCompressibleMomentumTransportModels.C` | film; core |
| `generalisedNewtonian` | `makeRAS/LES/LaminarModel` | `applications/modules/isothermalFilm/filmCompressibleMomentumTransportModels/filmCompressibleMomentumTransportModels.C` | film; core |
| `lambdaThixotropic` | `makeRAS/LES/LaminarModel` | `applications/modules/isothermalFilm/filmCompressibleMomentumTransportModels/filmCompressibleMomentumTransportModels.C` | film; core |
| `laminarfilmCompressibleMomentumTransportModel` | `filmCompressibleMomentumTransportModel` | `applications/modules/isothermalFilm/filmCompressibleMomentumTransportModels/filmCompressibleMomentumTransportModels.C` | film; core |
| `Gidaspow` | `viscosityModel` | `applications/modules/multiphaseEuler/momentumTransportModels/kineticTheoryModels/viscosityModel/Gidaspow/GidaspowViscosity.C` | multiphaseEuler phase-specific; core |
| `HrenyaSinclair` | `viscosityModel` | `applications/modules/multiphaseEuler/momentumTransportModels/kineticTheoryModels/viscosityModel/HrenyaSinclair/HrenyaSinclairViscosity.C` | multiphaseEuler phase-specific; core |
| `LaheyKEpsilon` | `makeRAS/LES/LaminarModel` | `applications/modules/multiphaseEuler/momentumTransportModels/momentumTransportModels.C` | multiphaseEuler phase-specific; core |
| `NicenoKEqn` | `makeRAS/LES/LaminarModel` | `applications/modules/multiphaseEuler/momentumTransportModels/momentumTransportModels.C` | multiphaseEuler phase-specific; core |
| `SmagorinskyZhang` | `makeRAS/LES/LaminarModel` | `applications/modules/multiphaseEuler/momentumTransportModels/momentumTransportModels.C` | multiphaseEuler phase-specific; core |
| `Syamlal` | `viscosityModel` | `applications/modules/multiphaseEuler/momentumTransportModels/kineticTheoryModels/viscosityModel/Syamlal/SyamlalViscosity.C` | multiphaseEuler phase-specific; core |
| `continuousGasKEpsilon` | `makeRAS/LES/LaminarModel` | `applications/modules/multiphaseEuler/momentumTransportModels/momentumTransportModels.C` | multiphaseEuler phase-specific; core |
| `continuousGasKEqn` | `makeRAS/LES/LaminarModel` | `applications/modules/multiphaseEuler/momentumTransportModels/momentumTransportModels.C` | multiphaseEuler phase-specific; core |
| `kOmegaSSTSato` | `makeRAS/LES/LaminarModel` | `applications/modules/multiphaseEuler/momentumTransportModels/momentumTransportModels.C` | multiphaseEuler phase-specific; core |
| `mixtureKEpsilon` | `makeRAS/LES/LaminarModel` | `applications/modules/multiphaseEuler/momentumTransportModels/momentumTransportModels.C` | multiphaseEuler phase-specific; core |
| `none` | `viscosityModel` | `applications/modules/multiphaseEuler/momentumTransportModels/kineticTheoryModels/viscosityModel/none/noneViscosity.C` | multiphaseEuler phase-specific; core |
| `Giesekus` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/phaseCompressible/phaseCompressibleMomentumTransportModels.C` | phaseCompressible |
| `Maxwell` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/phaseCompressible/phaseCompressibleMomentumTransportModels.C` | phaseCompressible |
| `PTT` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/phaseCompressible/phaseCompressibleMomentumTransportModels.C` | phaseCompressible |
| `RNGkEpsilon` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/phaseCompressible/phaseCompressibleMomentumTransportModels.C` | phaseCompressible |
| `Smagorinsky` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/phaseCompressible/phaseCompressibleMomentumTransportModels.C` | phaseCompressible |
| `Stokes` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/phaseCompressible/phaseCompressibleMomentumTransportModels.C` | phaseCompressible |
| `generalisedNewtonian` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/phaseCompressible/phaseCompressibleMomentumTransportModels.C` | phaseCompressible |
| `kEpsilon` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/phaseCompressible/phaseCompressibleMomentumTransportModels.C` | phaseCompressible |
| `kEqn` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/phaseCompressible/phaseCompressibleMomentumTransportModels.C` | phaseCompressible |
| `kOmegaSST` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/phaseCompressible/phaseCompressibleMomentumTransportModels.C` | phaseCompressible |
| `lambdaThixotropic` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/phaseCompressible/phaseCompressibleMomentumTransportModels.C` | phaseCompressible |
| `Giesekus` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/phaseIncompressible/phaseIncompressibleMomentumTransportModels.C` | phaseIncompressible |
| `Maxwell` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/phaseIncompressible/phaseIncompressibleMomentumTransportModels.C` | phaseIncompressible |
| `PTT` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/phaseIncompressible/phaseIncompressibleMomentumTransportModels.C` | phaseIncompressible |
| `Smagorinsky` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/phaseIncompressible/phaseIncompressibleMomentumTransportModels.C` | phaseIncompressible |
| `Stokes` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/phaseIncompressible/phaseIncompressibleMomentumTransportModels.C` | phaseIncompressible |
| `generalisedNewtonian` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/phaseIncompressible/phaseIncompressibleMomentumTransportModels.C` | phaseIncompressible |
| `kEpsilon` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/phaseIncompressible/phaseIncompressibleMomentumTransportModels.C` | phaseIncompressible |
| `kEqn` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/phaseIncompressible/phaseIncompressibleMomentumTransportModels.C` | phaseIncompressible |
| `kOmegaSST` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/phaseIncompressible/phaseIncompressibleMomentumTransportModels.C` | phaseIncompressible |
| `lambdaThixotropic` | `makeRAS/LES/LaminarModel` | `src/MomentumTransportModels/phaseIncompressible/phaseIncompressibleMomentumTransportModels.C` | phaseIncompressible |
