# fvModels RTS 清单

> 机器生成清单（Phase 0）。

来自 `src/fvModels` 与 modules（多行 RTS + 目录名）。

**条目数**: 88

| 类型名 | 基类/宏键 | 源码路径 | 备注 |
|--------|-----------|----------|------|
| `KochFriedlanderSintering` | `fvModel` | `applications/modules/multiphaseEuler/fvModels/KochFriedlanderSintering/KochFriedlanderSintering.C` | module |
| `VoFCavitation` | `fvModel` | `applications/modules/compressibleVoF/fvModels/VoFCavitation/VoFCavitation.C` | module |
| `VoFCavitation` | `fvModel` | `applications/modules/incompressibleVoF/fvModels/VoFCavitation/VoFCavitation.C` | module |
| `VoFClouds` | `fvModel` | `applications/modules/compressibleVoF/fvModels/VoFClouds/VoFClouds.C` | module |
| `VoFFilmTransfer` | `fvModel` | `applications/modules/isothermalFilm/fvModels/filmVoFTransfer/VoFFilmTransfer.C` | module |
| `VoFSolidificationMelting` | `fvModel` | `applications/modules/compressibleVoF/fvModels/VoFSolidificationMelting/VoFSolidificationMelting.C` | module |
| `VoFTurbulenceDamping` | `fvModel` | `applications/modules/compressibleVoF/fvModels/VoFTurbulenceDamping/VoFTurbulenceDamping.C` | module |
| `VoFTurbulenceDamping` | `fvModel` | `applications/modules/incompressibleVoF/fvModels/VoFTurbulenceDamping/VoFTurbulenceDamping.C` | module |
| `bXiIgnited` | `fvModel` | `applications/modules/XiFluid/fvModels/ignition/bXiIgnited/bXiIgnited.C` | module |
| `constantbXiIgnition` | `fvModel` | `applications/modules/XiFluid/fvModels/ignition/constantbXiIgnition/constantbXiIgnition.C` | module |
| `filmCloudTransfer` | `fvModel` | `applications/modules/isothermalFilm/fvModels/filmCloudTransfer/filmCloudTransfer.C` | module |
| `filmVoFTransfer` | `fvModel` | `applications/modules/isothermalFilm/fvModels/filmVoFTransfer/filmVoFTransfer.C` | module |
| `heatTransferLimitedPhaseChange` | `fvModel` | `applications/modules/multiphaseEuler/fvModels/heatTransferLimitedPhaseChange/heatTransferLimitedPhaseChange.C` | module |
| `homogeneousCondensation` | `fvModel` | `applications/modules/multiphaseEuler/fvModels/homogeneousCondensation/homogeneousCondensation.C` | module |
| `homogeneousLiquidPhaseSeparation` | `fvModel` | `applications/modules/multiphaseEuler/fvModels/homogeneousLiquidPhaseSeparation/homogeneousLiquidPhaseSeparation.C` | module |
| `interfaceTurbulenceDamping` | `fvModel` | `applications/modules/multiphaseEuler/fvModels/interfaceTurbulenceDamping/interfaceTurbulenceDamping.C` | module |
| `massDiffusionLimitedPhaseChange` | `fvModel` | `applications/modules/multiphaseEuler/fvModels/massDiffusionLimitedPhaseChange/massDiffusionLimitedPhaseChange.C` | module |
| `multiCycleConstantbXiIgnition` | `fvModel` | `applications/modules/XiFluid/fvModels/ignition/multiCycleConstantbXiIgnition/multiCycleConstantbXiIgnition.C` | module |
| `multiphaseEulerCavitation` | `fvModel` | `applications/modules/multiphaseEuler/fvModels/multiphaseEulerCavitation/multiphaseEulerCavitation.C` | module |
| `phaseSurfaceBoiling` | `fvModel` | `applications/modules/multiphaseEuler/fvModels/phaseSurfaceBoiling/phaseSurfaceBoiling.C` | module |
| `phaseTurbulenceStabilisation` | `fvModel` | `applications/modules/multiphaseEuler/fvModels/phaseTurbulenceStabilisation/phaseTurbulenceStabilisation.C` | module |
| `reactionDrivenPhaseChange` | `fvModel` | `applications/modules/multiphaseEuler/fvModels/reactionDrivenPhaseChange/reactionDrivenPhaseChange.C` | module |
| `wallBoiling` | `fvModel` | `applications/modules/multiphaseEuler/fvModels/wallBoiling/wallBoiling.C` | module |
| `acceleration` | `fvModel` | `src/fvModels/general/acceleration/acceleration.C` | src |
| `actuationDisk` | `fvModel` | `src/fvModels/general/actuationDisk/actuationDisk.C` | src |
| `buoyancyEnergy` | `fvModel` | `src/fvModels/general/buoyancyEnergy/buoyancyEnergy.C` | src |
| `buoyancyForce` | `fvModel` | `src/fvModels/general/buoyancyForce/buoyancyForce.C` | src |
| `codedFvModel` | `fvModel` | `src/fvModels/general/codedFvModel/codedFvModel.C` | src |
| `coefficientMassTransfer` | `fvModel` | `src/fvModels/general/massTransfer/coefficientMassTransfer.C` | src |
| `coefficientPhaseChange` | `fvModel` | `src/fvModels/general/phaseChange/coefficientPhaseChange.C` | src |
| `effectivenessHeatExchanger` | `fvModel` | `src/fvModels/general/effectivenessHeatExchanger/effectivenessHeatExchanger.C` | src |
| `heatSource` | `fvModel` | `src/fvModels/general/heatSource/heatSource.C` | src |
| `heatTransfer` | `fvModel` | `src/fvModels/interRegion/heatTransfer/heatTransfer.C` | src |
| `interRegionHeatTransfer` | `fvModel` | `src/fvModels/interRegion/interRegionHeatTransfer/interRegionHeatTransfer.C` | src |
| `interRegionPorosityForce` | `fvModel` | `src/fvModels/interRegion/interRegionPorosityForce/interRegionPorosityForce.C` | src |
| `massSource` | `fvModel` | `src/fvModels/general/massSource/massSource.C` | src |
| `phaseLimitStabilisation` | `fvModel` | `src/fvModels/general/phaseLimitStabilisation/phaseLimitStabilisation.C` | src |
| `porosityForce` | `fvModel` | `src/fvModels/general/porosityForce/porosityForce.C` | src |
| `propellerDisk` | `fvModel` | `src/fvModels/propellerDisk/propellerDisk.C` | src |
| `radialActuationDisk` | `fvModel` | `src/fvModels/general/radialActuationDisk/radialActuationDisk.C` | src |
| `rigidBodyPropellerDisk` | `fvModel` | `src/fvModels/rigidBodyPropellerDisk/rigidBodyPropellerDisk.C` | src |
| `rotorDisk` | `fvModel` | `src/fvModels/rotorDisk/rotorDisk.C` | src |
| `semiImplicitSource` | `fvModel` | `src/fvModels/general/semiImplicitSource/semiImplicitSource.C` | src |
| `sixDoFAcceleration` | `fvModel` | `src/fvModels/general/sixDoFAcceleration/sixDoFAcceleration.C` | src |
| `solidThermalEquilibrium` | `fvModel` | `src/fvModels/general/solidThermalEquilibrium/solidThermalEquilibrium.C` | src |
| `solidificationMelting` | `fvModel` | `src/fvModels/general/solidificationMelting/solidificationMelting.C` | src |
| `viscousHeating` | `fvModel` | `src/fvModels/general/viscousHeating/viscousHeating.C` | src |
| `volumeBlockage` | `fvModel` | `src/fvModels/general/volumeBlockage/volumeBlockage.C` | src |
| `volumeSource` | `fvModel` | `src/fvModels/general/volumeSource/volumeSource.C` | src |
| `zeroDimensionalMassSource` | `fvModel` | `src/fvModels/general/zeroDimensionalMassSource/zeroDimensionalMassSource.C` | src |
| `acceleration` | `directory` | `src/fvModels/general/acceleration` | src (dir) |
| `actuationDisk` | `directory` | `src/fvModels/general/actuationDisk` | src (dir) |
| `bladeModel` | `directory` | `src/fvModels/rotorDisk/bladeModel` | src (dir) |
| `buoyancyEnergy` | `directory` | `src/fvModels/general/buoyancyEnergy` | src (dir) |
| `buoyancyForce` | `directory` | `src/fvModels/general/buoyancyForce` | src (dir) |
| `codedFvModel` | `directory` | `src/fvModels/general/codedFvModel` | src (dir) |
| `constant` | `directory` | `src/fvModels/interRegion/heatTransferCoefficientModels/constant` | src (dir) |
| `effectivenessHeatExchanger` | `directory` | `src/fvModels/general/effectivenessHeatExchanger` | src (dir) |
| `function1` | `directory` | `src/fvModels/interRegion/heatTransferCoefficientModels/function1` | src (dir) |
| `function2` | `directory` | `src/fvModels/interRegion/heatTransferCoefficientModels/function2` | src (dir) |
| `heatSource` | `directory` | `src/fvModels/general/heatSource` | src (dir) |
| `heatTransfer` | `directory` | `src/fvModels/interRegion/heatTransfer` | src (dir) |
| `heatTransferAv` | `directory` | `src/fvModels/interRegion/heatTransfer/heatTransferAv` | src (dir) |
| `heatTransferCoefficientModel` | `directory` | `src/fvModels/interRegion/heatTransferCoefficientModels/heatTransferCoefficientModel` | src (dir) |
| `interRegionHeatTransfer` | `directory` | `src/fvModels/interRegion/interRegionHeatTransfer` | src (dir) |
| `interRegionModel` | `directory` | `src/fvModels/interRegion/interRegionModel` | src (dir) |
| `interRegionPorosityForce` | `directory` | `src/fvModels/interRegion/interRegionPorosityForce` | src (dir) |
| `massSource` | `directory` | `src/fvModels/general/massSource` | src (dir) |
| `massTransfer` | `directory` | `src/fvModels/general/massTransfer` | src (dir) |
| `phaseChange` | `directory` | `src/fvModels/general/phaseChange` | src (dir) |
| `phaseLimitStabilisation` | `directory` | `src/fvModels/general/phaseLimitStabilisation` | src (dir) |
| `porosityForce` | `directory` | `src/fvModels/general/porosityForce` | src (dir) |
| `profileModel` | `directory` | `src/fvModels/rotorDisk/profileModel` | src (dir) |
| `propellerDisk` | `directory` | `src/fvModels/propellerDisk` | src (dir) |
| `propellerDiskForce` | `directory` | `src/fvModels/rigidBodyPropellerDisk/propellerDiskForce` | src (dir) |
| `radialActuationDisk` | `directory` | `src/fvModels/general/radialActuationDisk` | src (dir) |
| `rigidBodyPropellerDisk` | `directory` | `src/fvModels/rigidBodyPropellerDisk` | src (dir) |
| `rotorDisk` | `directory` | `src/fvModels/rotorDisk` | src (dir) |
| `semiImplicitSource` | `directory` | `src/fvModels/general/semiImplicitSource` | src (dir) |
| `sixDoFAcceleration` | `directory` | `src/fvModels/general/sixDoFAcceleration` | src (dir) |
| `solidThermalEquilibrium` | `directory` | `src/fvModels/general/solidThermalEquilibrium` | src (dir) |
| `solidificationMelting` | `directory` | `src/fvModels/general/solidificationMelting` | src (dir) |
| `trimModel` | `directory` | `src/fvModels/rotorDisk/trimModel/trimModel` | src (dir) |
| `variable` | `directory` | `src/fvModels/interRegion/heatTransferCoefficientModels/variable` | src (dir) |
| `viscousHeating` | `directory` | `src/fvModels/general/viscousHeating` | src (dir) |
| `volumeBlockage` | `directory` | `src/fvModels/general/volumeBlockage` | src (dir) |
| `volumeSource` | `directory` | `src/fvModels/general/volumeSource` | src (dir) |
| `zeroDimensionalMassSource` | `directory` | `src/fvModels/general/zeroDimensionalMassSource` | src (dir) |
