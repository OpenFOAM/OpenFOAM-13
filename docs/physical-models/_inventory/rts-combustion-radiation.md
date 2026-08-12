# 燃烧 / 化学 / 辐射 / Xi 子模型清单

> 机器生成清单（Phase 0）。

RTS + 目录级模型名；覆盖 combustion、radiation、chemistry、reaction、laminarFlameSpeed、XiFluid、multiphaseEuler reactions。

**条目数**: 163

| 类型名 | 基类/宏键 | 源码路径 | 备注 |
|--------|-----------|----------|------|
| `Gulder` | `XiEqModel` | `applications/modules/XiFluid/XiModels/XiEqModels/Gulder/Gulder.C` | XiFluid |
| `KTS` | `XiGModel` | `applications/modules/XiFluid/XiModels/XiGModels/KTS/KTS.C` | XiFluid |
| `XiFluid` | `solver` | `applications/modules/XiFluid/XiFluid.C` | XiFluid |
| `bXiIgnited` | `fvModel` | `applications/modules/XiFluid/fvModels/ignition/bXiIgnited/bXiIgnited.C` | XiFluid |
| `constant` | `XiEqModel` | `applications/modules/XiFluid/XiModels/XiEqModels/constant/constant.C` | XiFluid |
| `constantbXiIgnition` | `fvModel` | `applications/modules/XiFluid/fvModels/ignition/constantbXiIgnition/constantbXiIgnition.C` | XiFluid |
| `cubic` | `XiProfile` | `applications/modules/XiFluid/XiModels/XiProfiles/cubic/cubic.C` | XiFluid |
| `cylindrical` | `XiCorrModel` | `applications/modules/XiFluid/fvModels/ignition/XiCorrModels/cylindrical/cylindricalXiCorr.C` | XiFluid |
| `equilibrium` | `XiModel` | `applications/modules/XiFluid/XiModels/equilibrium/equilibrium.C` | XiFluid |
| `instability` | `XiEqModel` | `applications/modules/XiFluid/XiModels/XiEqModels/instability/instability.C` | XiFluid |
| `instability` | `XiGModel` | `applications/modules/XiFluid/XiModels/XiGModels/instability/instability_XiGModel.C` | XiFluid |
| `linear` | `XiProfile` | `applications/modules/XiFluid/XiModels/XiProfiles/linear/linear.C` | XiFluid |
| `linearEquilibrium` | `SuModel` | `applications/modules/XiFluid/SuModels/linearEquilibrium/linearEquilibrium_SuModel.C` | XiFluid |
| `multiCycleConstantbXiIgnition` | `fvModel` | `applications/modules/XiFluid/fvModels/ignition/multiCycleConstantbXiIgnition/multiCycleConstantbXiIgnition.C` | XiFluid |
| `planar` | `XiCorrModel` | `applications/modules/XiFluid/fvModels/ignition/XiCorrModels/planar/planarXiCorr.C` | XiFluid |
| `spherical` | `XiCorrModel` | `applications/modules/XiFluid/fvModels/ignition/XiCorrModels/spherical/sphericalXiCorr.C` | XiFluid |
| `transport` | `SuModel` | `applications/modules/XiFluid/SuModels/transport/transport_SuModel.C` | XiFluid |
| `transport` | `XiModel` | `applications/modules/XiFluid/XiModels/transport/transport.C` | XiFluid |
| `uniform` | `XiProfile` | `applications/modules/XiFluid/XiModels/XiProfiles/uniform/uniform.C` | XiFluid |
| `uniformConstant` | `SuModel` | `applications/modules/XiFluid/SuModels/uniformConstant/uniformConstant_SuModel.C` | XiFluid |
| `uniformConstant` | `XiModel` | `applications/modules/XiFluid/XiModels/uniformConstant/uniformConstant.C` | XiFluid |
| `unstrained` | `SuModel` | `applications/modules/XiFluid/SuModels/unstrained/unstrained.C` | XiFluid |
| `Gulder` | `directory` | `applications/modules/XiFluid/XiModels/XiEqModels/Gulder` | XiFluid (dir) |
| `KTS` | `directory` | `applications/modules/XiFluid/XiModels/XiGModels/KTS` | XiFluid (dir) |
| `SuModel` | `directory` | `applications/modules/XiFluid/SuModels/SuModel` | XiFluid (dir) |
| `XiCorrModel` | `directory` | `applications/modules/XiFluid/fvModels/ignition/XiCorrModels/XiCorrModel` | XiFluid (dir) |
| `XiEqModel` | `directory` | `applications/modules/XiFluid/XiModels/XiEqModels/XiEqModel` | XiFluid (dir) |
| `XiGModel` | `directory` | `applications/modules/XiFluid/XiModels/XiGModels/XiGModel` | XiFluid (dir) |
| `XiModel` | `directory` | `applications/modules/XiFluid/XiModels/XiModel` | XiFluid (dir) |
| `XiProfile` | `directory` | `applications/modules/XiFluid/XiModels/XiProfiles/XiProfile` | XiFluid (dir) |
| `bXiIgnited` | `directory` | `applications/modules/XiFluid/fvModels/ignition/bXiIgnited` | XiFluid (dir) |
| `bXiIgnition` | `directory` | `applications/modules/XiFluid/fvModels/ignition/bXiIgnition` | XiFluid (dir) |
| `constant` | `directory` | `applications/modules/XiFluid/XiModels/XiEqModels/constant` | XiFluid (dir) |
| `constantbXiIgnition` | `directory` | `applications/modules/XiFluid/fvModels/ignition/constantbXiIgnition` | XiFluid (dir) |
| `cubic` | `directory` | `applications/modules/XiFluid/XiModels/XiProfiles/cubic` | XiFluid (dir) |
| `equilibrium` | `directory` | `applications/modules/XiFluid/XiModels/equilibrium` | XiFluid (dir) |
| `instability` | `directory` | `applications/modules/XiFluid/XiModels/XiEqModels/instability` | XiFluid (dir) |
| `linear` | `directory` | `applications/modules/XiFluid/XiModels/XiProfiles/linear` | XiFluid (dir) |
| `multiCycleConstantbXiIgnition` | `directory` | `applications/modules/XiFluid/fvModels/ignition/multiCycleConstantbXiIgnition` | XiFluid (dir) |
| `transport` | `directory` | `applications/modules/XiFluid/XiModels/transport` | XiFluid (dir) |
| `uniform` | `directory` | `applications/modules/XiFluid/XiModels/XiProfiles/uniform` | XiFluid (dir) |
| `uniformConstant` | `directory` | `applications/modules/XiFluid/XiModels/uniformConstant` | XiFluid (dir) |
| `unstrained` | `directory` | `applications/modules/XiFluid/SuModels/unstrained` | XiFluid (dir) |
| `ISAT` | `chemistryTabulationMethod` | `src/thermophysicalModels/chemistryModel/chemistryModel/tabulation/ISAT/ISAT.C` | chemistry |
| `adjustTimeStepToChemistry` | `functionObject` | `src/thermophysicalModels/chemistryModel/functionObjects/adjustTimeStepToChemistry/adjustTimeStepToChemistry.C` | chemistry |
| `none` | `chemistryTabulationMethod` | `src/thermophysicalModels/chemistryModel/chemistryModel/tabulation/noChemistryTabulation/noChemistryTabulation.C` | chemistry |
| `reactionRates` | `functionObject` | `src/thermophysicalModels/chemistryModel/functionObjects/reactionRates/reactionRates.C` | chemistry |
| `specieReactionRates` | `functionObject` | `src/thermophysicalModels/chemistryModel/functionObjects/specieReactionRates/specieReactionRates.C` | chemistry |
| `DAC` | `directory` | `src/thermophysicalModels/chemistryModel/chemistryModel/reduction/DAC` | chemistry (dir) |
| `DRG` | `directory` | `src/thermophysicalModels/chemistryModel/chemistryModel/reduction/DRG` | chemistry (dir) |
| `DRGEP` | `directory` | `src/thermophysicalModels/chemistryModel/chemistryModel/reduction/DRGEP` | chemistry (dir) |
| `EFA` | `directory` | `src/thermophysicalModels/chemistryModel/chemistryModel/reduction/EFA` | chemistry (dir) |
| `EulerImplicit` | `directory` | `src/thermophysicalModels/chemistryModel/chemistrySolver/EulerImplicit` | chemistry (dir) |
| `ISAT` | `directory` | `src/thermophysicalModels/chemistryModel/chemistryModel/tabulation/ISAT` | chemistry (dir) |
| `PFA` | `directory` | `src/thermophysicalModels/chemistryModel/chemistryModel/reduction/PFA` | chemistry (dir) |
| `adjustTimeStepToChemistry` | `directory` | `src/thermophysicalModels/chemistryModel/functionObjects/adjustTimeStepToChemistry` | chemistry (dir) |
| `basicChemistryModel` | `directory` | `src/thermophysicalModels/chemistryModel/basicChemistryModel` | chemistry (dir) |
| `binaryNode` | `directory` | `src/thermophysicalModels/chemistryModel/chemistryModel/tabulation/ISAT/binaryNode` | chemistry (dir) |
| `binaryTree` | `directory` | `src/thermophysicalModels/chemistryModel/chemistryModel/tabulation/ISAT/binaryTree` | chemistry (dir) |
| `chemPointISAT` | `directory` | `src/thermophysicalModels/chemistryModel/chemistryModel/tabulation/ISAT/chemPointISAT` | chemistry (dir) |
| `chemistryModel` | `directory` | `src/thermophysicalModels/chemistryModel/chemistryModel` | chemistry (dir) |
| `chemistryReductionMethod` | `directory` | `src/thermophysicalModels/chemistryModel/chemistryModel/reduction/chemistryReductionMethod` | chemistry (dir) |
| `chemistrySolver` | `directory` | `src/thermophysicalModels/chemistryModel/chemistrySolver/chemistrySolver` | chemistry (dir) |
| `chemistryTabulationMethod` | `directory` | `src/thermophysicalModels/chemistryModel/chemistryModel/tabulation/chemistryTabulationMethod` | chemistry (dir) |
| `noChemistryReduction` | `directory` | `src/thermophysicalModels/chemistryModel/chemistryModel/reduction/noChemistryReduction` | chemistry (dir) |
| `noChemistrySolver` | `directory` | `src/thermophysicalModels/chemistryModel/chemistrySolver/noChemistrySolver` | chemistry (dir) |
| `noChemistryTabulation` | `directory` | `src/thermophysicalModels/chemistryModel/chemistryModel/tabulation/noChemistryTabulation` | chemistry (dir) |
| `ode` | `directory` | `src/thermophysicalModels/chemistryModel/chemistrySolver/ode` | chemistry (dir) |
| `odeChemistryModel` | `directory` | `src/thermophysicalModels/chemistryModel/odeChemistryModel` | chemistry (dir) |
| `reactionRates` | `directory` | `src/thermophysicalModels/chemistryModel/functionObjects/reactionRates` | chemistry (dir) |
| `specieReactionRates` | `directory` | `src/thermophysicalModels/chemistryModel/functionObjects/specieReactionRates` | chemistry (dir) |
| `EDC` | `combustionModel` | `src/combustionModels/EDC/EDC.C` | combustion |
| `FSD` | `combustionModel` | `src/combustionModels/FSD/FSD.C` | combustion |
| `PaSR` | `combustionModel` | `src/combustionModels/PaSR/PaSR.C` | combustion |
| `Qdot` | `functionObject` | `src/combustionModels/functionObjects/Qdot/Qdot.C` | combustion |
| `adjustTimeStepToCombustion` | `functionObject` | `src/combustionModels/functionObjects/adjustTimeStepToCombustion/adjustTimeStepToCombustion.C` | combustion |
| `diffusion` | `combustionModel` | `src/combustionModels/diffusion/diffusion.C` | combustion |
| `greyMeanCombustion` | `absorptionEmissionModel` | `src/combustionModels/radiationModels/absorptionEmissionModels/greyMeanCombustion/greyMeanCombustion.C` | combustion |
| `infinitelyFastChemistry` | `combustionModel` | `src/combustionModels/infinitelyFastChemistry/infinitelyFastChemistry.C` | combustion |
| `laminar` | `combustionModel` | `src/combustionModels/laminar/laminar.C` | combustion |
| `mixtureFraction` | `sootModel` | `src/combustionModels/radiationModels/sootModels/mixtureFraction/mixtureFraction.C` | combustion |
| `noCombustion` | `combustionModel` | `src/combustionModels/noCombustion/noCombustion.C` | combustion |
| `relaxation` | `reactionRateFlameArea` | `src/combustionModels/FSD/reactionRateFlameAreaModels/relaxation/relaxation.C` | combustion |
| `wideBandCombustion` | `absorptionEmissionModel` | `src/combustionModels/radiationModels/absorptionEmissionModels/wideBandCombustion/wideBandCombustion.C` | combustion |
| `zoneCombustion` | `combustionModel` | `src/combustionModels/zoneCombustion/zoneCombustion.C` | combustion |
| `EDC` | `directory` | `src/combustionModels/EDC` | combustion (dir) |
| `FSD` | `directory` | `src/combustionModels/FSD` | combustion (dir) |
| `PaSR` | `directory` | `src/combustionModels/PaSR` | combustion (dir) |
| `Qdot` | `directory` | `src/combustionModels/functionObjects/Qdot` | combustion (dir) |
| `adjustTimeStepToCombustion` | `directory` | `src/combustionModels/functionObjects/adjustTimeStepToCombustion` | combustion (dir) |
| `combustionModel` | `directory` | `src/combustionModels/combustionModel` | combustion (dir) |
| `consumptionSpeed` | `directory` | `src/combustionModels/FSD/reactionRateFlameAreaModels/consumptionSpeed` | combustion (dir) |
| `diffusion` | `directory` | `src/combustionModels/diffusion` | combustion (dir) |
| `greyMeanCombustion` | `directory` | `src/combustionModels/radiationModels/absorptionEmissionModels/greyMeanCombustion` | combustion (dir) |
| `infinitelyFastChemistry` | `directory` | `src/combustionModels/infinitelyFastChemistry` | combustion (dir) |
| `laminar` | `directory` | `src/combustionModels/laminar` | combustion (dir) |
| `mixtureFraction` | `directory` | `src/combustionModels/radiationModels/sootModels/mixtureFraction` | combustion (dir) |
| `noCombustion` | `directory` | `src/combustionModels/noCombustion` | combustion (dir) |
| `reactionRateFlameArea` | `directory` | `src/combustionModels/FSD/reactionRateFlameAreaModels/reactionRateFlameArea` | combustion (dir) |
| `relaxation` | `directory` | `src/combustionModels/FSD/reactionRateFlameAreaModels/relaxation` | combustion (dir) |
| `singleStepCombustion` | `directory` | `src/combustionModels/singleStepCombustion` | combustion (dir) |
| `wideBandCombustion` | `directory` | `src/combustionModels/radiationModels/absorptionEmissionModels/wideBandCombustion` | combustion (dir) |
| `zoneCombustion` | `directory` | `src/combustionModels/zoneCombustion` | combustion (dir) |
| `Gulder` | `laminarFlameSpeed` | `src/thermophysicalModels/laminarFlameSpeed/Gulder/Gulder.C` | laminarFlameSpeed |
| `RaviPetersen` | `laminarFlameSpeed` | `src/thermophysicalModels/laminarFlameSpeed/RaviPetersen/RaviPetersen.C` | laminarFlameSpeed |
| `constant` | `laminarFlameSpeed` | `src/thermophysicalModels/laminarFlameSpeed/constant/constant.C` | laminarFlameSpeed |
| `Gulder` | `directory` | `src/thermophysicalModels/laminarFlameSpeed/Gulder` | laminarFlameSpeed (dir) |
| `RaviPetersen` | `directory` | `src/thermophysicalModels/laminarFlameSpeed/RaviPetersen` | laminarFlameSpeed (dir) |
| `constant` | `directory` | `src/thermophysicalModels/laminarFlameSpeed/constant` | laminarFlameSpeed (dir) |
| `laminarFlameSpeed` | `directory` | `src/thermophysicalModels/laminarFlameSpeed/laminarFlameSpeed` | laminarFlameSpeed (dir) |
| `phaseSurfaceArrheniusReactionRate` | `directory` | `applications/modules/multiphaseEuler/reactions/phaseSurfaceArrheniusReactionRate` | multiphaseEuler reactions (dir) |
| `binary` | `absorptionEmissionModel` | `src/radiationModels/absorptionEmissionModels/binary/binary.C` | radiation |
| `constant` | `absorptionEmissionModel` | `src/radiationModels/absorptionEmissionModels/constantAbsorptionEmission/constantAbsorptionEmission.C` | radiation |
| `constant` | `scatterModel` | `src/radiationModels/scatterModels/constantScatter/constantScatter.C` | radiation |
| `greyMean` | `absorptionEmissionModel` | `src/radiationModels/absorptionEmissionModels/greyMean/greyMean.C` | radiation |
| `noAbsorptionEmission` | `absorptionEmissionModel` | `src/radiationModels/absorptionEmissionModels/noAbsorptionEmission/noAbsorptionEmission.C` | radiation |
| `noScatter` | `scatterModel` | `src/radiationModels/scatterModels/noScatter/noScatter.C` | radiation |
| `noSoot` | `sootModel` | `src/radiationModels/sootModels/noSoot/noSoot.C` | radiation |
| `radiation` | `fvModel` | `src/radiationModels/fvModels/radiation/radiation.C` | radiation |
| `wideBand` | `absorptionEmissionModel` | `src/radiationModels/absorptionEmissionModels/wideBand/wideBand.C` | radiation |
| `P1` | `directory` | `src/radiationModels/radiationModels/P1` | radiation (dir) |
| `absorptionCoeffs` | `directory` | `src/radiationModels/radiationModels/fvDOM/absorptionCoeffs` | radiation (dir) |
| `absorptionEmissionModel` | `directory` | `src/radiationModels/absorptionEmissionModels/absorptionEmissionModel` | radiation (dir) |
| `binary` | `directory` | `src/radiationModels/absorptionEmissionModels/binary` | radiation (dir) |
| `blackBodyEmission` | `directory` | `src/radiationModels/radiationModels/fvDOM/blackBodyEmission` | radiation (dir) |
| `constantAbsorptionEmission` | `directory` | `src/radiationModels/absorptionEmissionModels/constantAbsorptionEmission` | radiation (dir) |
| `constantScatter` | `directory` | `src/radiationModels/scatterModels/constantScatter` | radiation (dir) |
| `fvDOM` | `directory` | `src/radiationModels/radiationModels/fvDOM` | radiation (dir) |
| `greyMean` | `directory` | `src/radiationModels/absorptionEmissionModels/greyMean` | radiation (dir) |
| `interpolationLookUpTable` | `directory` | `src/radiationModels/absorptionEmissionModels/interpolationLookUpTable` | radiation (dir) |
| `noAbsorptionEmission` | `directory` | `src/radiationModels/absorptionEmissionModels/noAbsorptionEmission` | radiation (dir) |
| `noRadiation` | `directory` | `src/radiationModels/radiationModels/noRadiation` | radiation (dir) |
| `noScatter` | `directory` | `src/radiationModels/scatterModels/noScatter` | radiation (dir) |
| `noSoot` | `directory` | `src/radiationModels/sootModels/noSoot` | radiation (dir) |
| `opaqueSolid` | `directory` | `src/radiationModels/radiationModels/opaqueSolid` | radiation (dir) |
| `radiation` | `directory` | `src/radiationModels/fvModels/radiation` | radiation (dir) |
| `radiationCoupledBase` | `directory` | `src/radiationModels/derivedFvPatchFields/radiationCoupledBase` | radiation (dir) |
| `radiationModel` | `directory` | `src/radiationModels/radiationModels/radiationModel` | radiation (dir) |
| `radiativeIntensityRay` | `directory` | `src/radiationModels/radiationModels/fvDOM/radiativeIntensityRay` | radiation (dir) |
| `scatterModel` | `directory` | `src/radiationModels/scatterModels/scatterModel` | radiation (dir) |
| `sootModel` | `directory` | `src/radiationModels/sootModels/sootModel` | radiation (dir) |
| `viewFactor` | `directory` | `src/radiationModels/radiationModels/viewFactor` | radiation (dir) |
| `wideBand` | `directory` | `src/radiationModels/absorptionEmissionModels/wideBand` | radiation (dir) |
| `ArrheniusReactionRate` | `directory` | `src/thermophysicalModels/specie/reaction/reactionRate/ArrheniusReactionRate` | reaction (dir) |
| `ChemicallyActivatedReactionRate` | `directory` | `src/thermophysicalModels/specie/reaction/reactionRate/ChemicallyActivatedReactionRate` | reaction (dir) |
| `FallOffReactionRate` | `directory` | `src/thermophysicalModels/specie/reaction/reactionRate/FallOffReactionRate` | reaction (dir) |
| `IrreversibleReaction` | `directory` | `src/thermophysicalModels/specie/reaction/Reactions/IrreversibleReaction` | reaction (dir) |
| `JanevReactionRate` | `directory` | `src/thermophysicalModels/specie/reaction/reactionRate/JanevReactionRate` | reaction (dir) |
| `LandauTellerReactionRate` | `directory` | `src/thermophysicalModels/specie/reaction/reactionRate/LandauTellerReactionRate` | reaction (dir) |
| `LindemannFallOffFunction` | `directory` | `src/thermophysicalModels/specie/reaction/reactionRate/fallOffFunctions/LindemannFallOffFunction` | reaction (dir) |
| `NonEquilibriumReversibleReaction` | `directory` | `src/thermophysicalModels/specie/reaction/Reactions/NonEquilibriumReversibleReaction` | reaction (dir) |
| `Reaction` | `directory` | `src/thermophysicalModels/specie/reaction/Reactions/Reaction` | reaction (dir) |
| `ReactionList` | `directory` | `src/thermophysicalModels/specie/reaction/Reactions/ReactionList` | reaction (dir) |
| `ReversibleReaction` | `directory` | `src/thermophysicalModels/specie/reaction/Reactions/ReversibleReaction` | reaction (dir) |
| `SRIFallOffFunction` | `directory` | `src/thermophysicalModels/specie/reaction/reactionRate/fallOffFunctions/SRIFallOffFunction` | reaction (dir) |
| `TroeFallOffFunction` | `directory` | `src/thermophysicalModels/specie/reaction/reactionRate/fallOffFunctions/TroeFallOffFunction` | reaction (dir) |
| `fluxLimitedLangmuirHinshelwoodReactionRate` | `directory` | `src/thermophysicalModels/specie/reaction/reactionRate/fluxLimitedLangmuirHinshelwoodReactionRate` | reaction (dir) |
| `reaction` | `directory` | `src/thermophysicalModels/specie/reaction/reaction` | reaction (dir) |
| `specieCoeffs` | `directory` | `src/thermophysicalModels/specie/reaction/specieCoeffs` | reaction (dir) |
| `specieExponent` | `directory` | `src/thermophysicalModels/specie/reaction/specieExponent` | reaction (dir) |
| `surfaceArrheniusReactionRate` | `directory` | `src/thermophysicalModels/specie/reaction/reactionRate/surfaceArrheniusReactionRate` | reaction (dir) |
| `thirdBodyArrheniusReactionRate` | `directory` | `src/thermophysicalModels/specie/reaction/reactionRate/thirdBodyArrheniusReactionRate` | reaction (dir) |
| `thirdBodyEfficiencies` | `directory` | `src/thermophysicalModels/specie/reaction/reactionRate/thirdBodyEfficiencies` | reaction (dir) |
