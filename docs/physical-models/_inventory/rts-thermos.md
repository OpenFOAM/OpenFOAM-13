# 热物性 / thermoType 相关清单

> 机器生成清单（Phase 0）。

综合：`specie` 包目录（EOS/thermo/transport/energy）、`for*.H` 拼装部件、liquid/solid Properties、`*Thermos.C` 工厂，以及 thermophysicalModels 下全部 RTS。

**条目数**: 168

## 说明

完整 `thermoType` 组合由 `forGases.H` / `forLiquids.H` / `forTabulated.H` / `forSolids.H` 等宏展开，并非每个组合单独 RTS。 本表列出可拼装部件与已注册物性包；合法组合以 include 宏为准（Phase 1 展开）。


| 类型名 | 基类/宏键 | 源码路径 | 备注 |
|--------|-----------|----------|------|
| `Boussinesq` | `equationOfState` | `src/thermophysicalModels/specie/equationOfState/Boussinesq` | EOS |
| `PengRobinsonGas` | `equationOfState` | `src/thermophysicalModels/specie/equationOfState/PengRobinsonGas` | EOS |
| `adiabaticPerfectFluid` | `equationOfState` | `src/thermophysicalModels/specie/equationOfState/adiabaticPerfectFluid` | EOS |
| `icoPolynomial` | `equationOfState` | `src/thermophysicalModels/specie/equationOfState/icoPolynomial` | EOS |
| `icoTabulated` | `equationOfState` | `src/thermophysicalModels/specie/equationOfState/icoTabulated` | EOS |
| `incompressiblePerfectGas` | `equationOfState` | `src/thermophysicalModels/specie/equationOfState/incompressiblePerfectGas` | EOS |
| `linear` | `equationOfState` | `src/thermophysicalModels/specie/equationOfState/linear` | EOS |
| `perfectFluid` | `equationOfState` | `src/thermophysicalModels/specie/equationOfState/perfectFluid` | EOS |
| `perfectGas` | `equationOfState` | `src/thermophysicalModels/specie/equationOfState/perfectGas` | EOS |
| `rPolynomial` | `equationOfState` | `src/thermophysicalModels/specie/equationOfState/rPolynomial` | EOS |
| `rhoConst` | `equationOfState` | `src/thermophysicalModels/specie/equationOfState/rhoConst` | EOS |
| `rhoTabulated` | `equationOfState` | `src/thermophysicalModels/specie/equationOfState/rhoTabulated` | EOS |
| `ISAT` | `chemistryTabulationMethod` | `src/thermophysicalModels/chemistryModel/chemistryModel/tabulation/ISAT/ISAT.C` | chemistry |
| `adjustTimeStepToChemistry` | `functionObject` | `src/thermophysicalModels/chemistryModel/functionObjects/adjustTimeStepToChemistry/adjustTimeStepToChemistry.C` | chemistry |
| `none` | `chemistryTabulationMethod` | `src/thermophysicalModels/chemistryModel/chemistryModel/tabulation/noChemistryTabulation/noChemistryTabulation.C` | chemistry |
| `reactionRates` | `functionObject` | `src/thermophysicalModels/chemistryModel/functionObjects/reactionRates/reactionRates.C` | chemistry |
| `specieReactionRates` | `functionObject` | `src/thermophysicalModels/chemistryModel/functionObjects/specieReactionRates/specieReactionRates.C` | chemistry |
| `Gulder` | `laminarFlameSpeed` | `src/thermophysicalModels/laminarFlameSpeed/Gulder/Gulder.C` | laminarFlameSpeed |
| `RaviPetersen` | `laminarFlameSpeed` | `src/thermophysicalModels/laminarFlameSpeed/RaviPetersen/RaviPetersen.C` | laminarFlameSpeed |
| `constant` | `laminarFlameSpeed` | `src/thermophysicalModels/laminarFlameSpeed/constant/constant.C` | laminarFlameSpeed |
| `Ar` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/Ar` | liquidProperties |
| `Ar` | `liquidProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/Ar/Ar.C` | liquidProperties |
| `C10H22` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/C10H22` | liquidProperties |
| `C10H22` | `liquidProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/C10H22/C10H22.C` | liquidProperties |
| `C12H26` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/C12H26` | liquidProperties |
| `C12H26` | `liquidProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/C12H26/C12H26.C` | liquidProperties |
| `C13H28` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/C13H28` | liquidProperties |
| `C13H28` | `liquidProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/C13H28/C13H28.C` | liquidProperties |
| `C14H30` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/C14H30` | liquidProperties |
| `C14H30` | `liquidProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/C14H30/C14H30.C` | liquidProperties |
| `C16H34` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/C16H34` | liquidProperties |
| `C16H34` | `liquidProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/C16H34/C16H34.C` | liquidProperties |
| `C2H5OH` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/C2H5OH` | liquidProperties |
| `C2H5OH` | `liquidProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/C2H5OH/C2H5OH.C` | liquidProperties |
| `C2H6` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/C2H6` | liquidProperties |
| `C2H6` | `liquidProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/C2H6/C2H6.C` | liquidProperties |
| `C2H6O` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/C2H6O` | liquidProperties |
| `C2H6O` | `liquidProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/C2H6O/C2H6O.C` | liquidProperties |
| `C3H6O` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/C3H6O` | liquidProperties |
| `C3H6O` | `liquidProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/C3H6O/C3H6O.C` | liquidProperties |
| `C3H8` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/C3H8` | liquidProperties |
| `C3H8` | `liquidProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/C3H8/C3H8.C` | liquidProperties |
| `C4H10O` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/C4H10O` | liquidProperties |
| `C4H10O` | `liquidProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/C4H10O/C4H10O.C` | liquidProperties |
| `C6H14` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/C6H14` | liquidProperties |
| `C6H14` | `liquidProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/C6H14/C6H14.C` | liquidProperties |
| `C6H6` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/C6H6` | liquidProperties |
| `C6H6` | `liquidProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/C6H6/C6H6.C` | liquidProperties |
| `C7H16` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/C7H16` | liquidProperties |
| `C7H16` | `liquidProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/C7H16/C7H16.C` | liquidProperties |
| `C7H8` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/C7H8` | liquidProperties |
| `C7H8` | `liquidProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/C7H8/C7H8.C` | liquidProperties |
| `C8H10` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/C8H10` | liquidProperties |
| `C8H10` | `liquidProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/C8H10/C8H10.C` | liquidProperties |
| `C8H18` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/C8H18` | liquidProperties |
| `C8H18` | `liquidProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/C8H18/C8H18.C` | liquidProperties |
| `C9H20` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/C9H20` | liquidProperties |
| `C9H20` | `liquidProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/C9H20/C9H20.C` | liquidProperties |
| `CH3OH` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/CH3OH` | liquidProperties |
| `CH3OH` | `liquidProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/CH3OH/CH3OH.C` | liquidProperties |
| `CH4N2O` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/CH4N2O` | liquidProperties |
| `CH4N2O` | `liquidProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/CH4N2O/CH4N2O.C` | liquidProperties |
| `H2O` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/H2O` | liquidProperties |
| `H2O` | `liquidProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/H2O/H2O.C` | liquidProperties |
| `IC8H18` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/IC8H18` | liquidProperties |
| `IC8H18` | `liquidProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/IC8H18/IC8H18.C` | liquidProperties |
| `IDEA` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/IDEA` | liquidProperties |
| `IDEA` | `liquidProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/IDEA/IDEA.C` | liquidProperties |
| `MB` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/MB` | liquidProperties |
| `MB` | `liquidProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/MB/MB.C` | liquidProperties |
| `N2` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/N2` | liquidProperties |
| `N2` | `liquidProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/N2/N2.C` | liquidProperties |
| `NH3` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/NH3` | liquidProperties |
| `NH3` | `liquidProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/NH3/NH3.C` | liquidProperties |
| `aC10H7CH3` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/aC10H7CH3` | liquidProperties |
| `aC10H7CH3` | `liquidProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/aC10H7CH3/aC10H7CH3.C` | liquidProperties |
| `bC10H7CH3` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/bC10H7CH3` | liquidProperties |
| `bC10H7CH3` | `liquidProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/bC10H7CH3/bC10H7CH3.C` | liquidProperties |
| `iC3H8O` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/iC3H8O` | liquidProperties |
| `iC3H8O` | `liquidProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/iC3H8O/iC3H8O.C` | liquidProperties |
| `liquid` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/liquid` | liquidProperties |
| `liquid` | `liquidProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/liquid/liquid.C` | liquidProperties |
| `liquidMixtureProperties` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/liquidMixtureProperties` | liquidProperties |
| `liquidProperties` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/liquidProperties` | liquidProperties |
| `nC3H8O` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/nC3H8O` | liquidProperties |
| `nC3H8O` | `liquidProperties` | `src/thermophysicalModels/thermophysicalProperties/liquidProperties/nC3H8O/nC3H8O.C` | liquidProperties |
| `liquidThermos` | `thermo factory` | `src/thermophysicalModels/basic/liquidThermo/liquidThermos.C` | makeThermo 工厂源文件 |
| `psiMulticomponentThermos` | `thermo factory` | `src/thermophysicalModels/multicomponentThermo/psiMulticomponentThermo/psiMulticomponentThermos.C` | makeThermo 工厂源文件 |
| `psiThermos` | `thermo factory` | `src/thermophysicalModels/basic/psiThermo/psiThermos.C` | makeThermo 工厂源文件 |
| `psiuMulticomponentThermos` | `thermo factory` | `src/thermophysicalModels/multicomponentThermo/psiuMulticomponentThermo/psiuMulticomponentThermos.C` | makeThermo 工厂源文件 |
| `rhoFluidMulticomponentThermos` | `thermo factory` | `src/thermophysicalModels/multicomponentThermo/rhoFluidMulticomponentThermo/rhoFluidMulticomponentThermos.C` | makeThermo 工厂源文件 |
| `rhoFluidThermos` | `thermo factory` | `src/thermophysicalModels/basic/rhoFluidThermo/rhoFluidThermos.C` | makeThermo 工厂源文件 |
| `solidThermos` | `thermo factory` | `src/thermophysicalModels/solidThermo/solidThermo/solidThermos.C` | makeThermo 工厂源文件 |
| `massFractions` | `functionObject` | `src/thermophysicalModels/multicomponentThermo/functionObjects/massFractions/massFractions.C` | multicomponent |
| `moleFractions` | `functionObject` | `src/thermophysicalModels/multicomponentThermo/functionObjects/moleFractions/moleFractions.C` | multicomponent |
| `reaction` | `reaction` | `src/thermophysicalModels/specie/reaction/reaction` | reaction |
| `specieCoeffs` | `reaction` | `src/thermophysicalModels/specie/reaction/specieCoeffs` | reaction |
| `specieExponent` | `reaction` | `src/thermophysicalModels/specie/reaction/specieExponent` | reaction |
| `Antoine` | `saturationPressureModel` | `src/thermophysicalModels/saturationModels/Antoine/Antoine.C` | saturationModels |
| `Antoine` | `saturationTemperatureModel` | `src/thermophysicalModels/saturationModels/Antoine/Antoine.C` | saturationModels |
| `AntoineExtended` | `saturationPressureModel` | `src/thermophysicalModels/saturationModels/AntoineExtended/AntoineExtended.C` | saturationModels |
| `ArdenBuck` | `saturationPressureModel` | `src/thermophysicalModels/saturationModels/ArdenBuck/ArdenBuck.C` | saturationModels |
| `constantPressure` | `saturationPressureModel` | `src/thermophysicalModels/saturationModels/constantPressure/constantPressure.C` | saturationModels |
| `constantTemperature` | `saturationTemperatureModel` | `src/thermophysicalModels/saturationModels/constantTemperature/constantTemperature.C` | saturationModels |
| `function1Temperature` | `saturationTemperatureModel` | `src/thermophysicalModels/saturationModels/function1Temperature/function1Temperature.C` | saturationModels |
| `polynomialTemperature` | `saturationTemperatureModel` | `src/thermophysicalModels/saturationModels/polynomialTemperature/polynomialTemperature.C` | saturationModels |
| `C` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/solidProperties/C` | solidProperties |
| `C` | `solidProperties` | `src/thermophysicalModels/thermophysicalProperties/solidProperties/C/C.C` | solidProperties |
| `CaCO3` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/solidProperties/CaCO3` | solidProperties |
| `CaCO3` | `solidProperties` | `src/thermophysicalModels/thermophysicalProperties/solidProperties/CaCO3/CaCO3.C` | solidProperties |
| `ash` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/solidProperties/ash` | solidProperties |
| `ash` | `solidProperties` | `src/thermophysicalModels/thermophysicalProperties/solidProperties/ash/ash.C` | solidProperties |
| `solidMixtureProperties` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/solidProperties/solidMixtureProperties` | solidProperties |
| `solidProperties` | `thermophysicalProperties` | `src/thermophysicalModels/thermophysicalProperties/solidProperties/solidProperties` | solidProperties |
| `constAnisoSolidThermo` | `basicThermo` | `src/thermophysicalModels/solidThermo/constAnisoSolidThermo/constAnisoSolidThermo.C` | solidThermo |
| `constAnisoSolidThermo` | `solidThermo` | `src/thermophysicalModels/solidThermo/constAnisoSolidThermo/constAnisoSolidThermo.C` | solidThermo |
| `constSolidThermo` | `basicThermo` | `src/thermophysicalModels/solidThermo/constSolidThermo/constSolidThermo.C` | solidThermo |
| `constSolidThermo` | `solidThermo` | `src/thermophysicalModels/solidThermo/constSolidThermo/constSolidThermo.C` | solidThermo |
| `absoluteEnthalpy` | `thermo` | `src/thermophysicalModels/specie/thermo/absoluteEnthalpy` | thermo model |
| `absoluteInternalEnergy` | `thermo` | `src/thermophysicalModels/specie/thermo/absoluteInternalEnergy` | thermo model |
| `sensibleEnthalpy` | `thermo` | `src/thermophysicalModels/specie/thermo/sensibleEnthalpy` | thermo model |
| `sensibleInternalEnergy` | `thermo` | `src/thermophysicalModels/specie/thermo/sensibleInternalEnergy` | thermo model |
| `thermo` | `thermo` | `src/thermophysicalModels/specie/thermo/thermo` | thermo model |
| `Boussinesq` | `included by forGases` | `src/thermophysicalModels/specie/include/forGases.H` | thermo 拼装部件 |
| `NamedThermo` | `included by makeThermo` | `src/thermophysicalModels/specie/include/makeThermo.H` | thermo 拼装部件 |
| `absoluteEnthalpy` | `included by forAbsoluteGases` | `src/thermophysicalModels/specie/include/forAbsoluteGases.H` | thermo 拼装部件 |
| `addToRunTimeSelectionTable` | `included by makeThermo` | `src/thermophysicalModels/specie/include/makeThermo.H` | thermo 拼装部件 |
| `adiabaticPerfectFluid` | `included by forLiquids` | `src/thermophysicalModels/specie/include/forLiquids.H` | thermo 拼装部件 |
| `basicThermo` | `included by makeThermo` | `src/thermophysicalModels/specie/include/makeThermo.H` | thermo 拼装部件 |
| `constTransport` | `included by forAbsoluteGases` | `src/thermophysicalModels/specie/include/forAbsoluteGases.H` | thermo 拼装部件 |
| `constTransport` | `included by forGases` | `src/thermophysicalModels/specie/include/forGases.H` | thermo 拼装部件 |
| `constTransport` | `included by forLiquids` | `src/thermophysicalModels/specie/include/forLiquids.H` | thermo 拼装部件 |
| `eConstThermo` | `included by forAbsoluteGases` | `src/thermophysicalModels/specie/include/forAbsoluteGases.H` | thermo 拼装部件 |
| `eConstThermo` | `included by forGases` | `src/thermophysicalModels/specie/include/forGases.H` | thermo 拼装部件 |
| `eConstThermo` | `included by forLiquids` | `src/thermophysicalModels/specie/include/forLiquids.H` | thermo 拼装部件 |
| `eIcoTabulatedThermo` | `included by forTabulated` | `src/thermophysicalModels/specie/include/forTabulated.H` | thermo 拼装部件 |
| `eTabulatedThermo` | `included by forTabulated` | `src/thermophysicalModels/specie/include/forTabulated.H` | thermo 拼装部件 |
| `hConstThermo` | `included by forAbsoluteGases` | `src/thermophysicalModels/specie/include/forAbsoluteGases.H` | thermo 拼装部件 |
| `hConstThermo` | `included by forGases` | `src/thermophysicalModels/specie/include/forGases.H` | thermo 拼装部件 |
| `hConstThermo` | `included by forLiquids` | `src/thermophysicalModels/specie/include/forLiquids.H` | thermo 拼装部件 |
| `hIcoTabulatedThermo` | `included by forTabulated` | `src/thermophysicalModels/specie/include/forTabulated.H` | thermo 拼装部件 |
| `hTabulatedThermo` | `included by forTabulated` | `src/thermophysicalModels/specie/include/forTabulated.H` | thermo 拼装部件 |
| `icoTabulated` | `included by forTabulated` | `src/thermophysicalModels/specie/include/forTabulated.H` | thermo 拼装部件 |
| `icoTabulatedTransport` | `included by forTabulated` | `src/thermophysicalModels/specie/include/forTabulated.H` | thermo 拼装部件 |
| `janafThermo` | `included by forAbsoluteGases` | `src/thermophysicalModels/specie/include/forAbsoluteGases.H` | thermo 拼装部件 |
| `janafThermo` | `included by forGases` | `src/thermophysicalModels/specie/include/forGases.H` | thermo 拼装部件 |
| `perfectGas` | `included by forAbsoluteGases` | `src/thermophysicalModels/specie/include/forAbsoluteGases.H` | thermo 拼装部件 |
| `perfectGas` | `included by forGases` | `src/thermophysicalModels/specie/include/forGases.H` | thermo 拼装部件 |
| `rPolynomial` | `included by forLiquids` | `src/thermophysicalModels/specie/include/forLiquids.H` | thermo 拼装部件 |
| `rhoConst` | `included by forLiquids` | `src/thermophysicalModels/specie/include/forLiquids.H` | thermo 拼装部件 |
| `rhoTabulated` | `included by forTabulated` | `src/thermophysicalModels/specie/include/forTabulated.H` | thermo 拼装部件 |
| `sensibleEnthalpy` | `included by forGases` | `src/thermophysicalModels/specie/include/forGases.H` | thermo 拼装部件 |
| `sensibleEnthalpy` | `included by forLiquids` | `src/thermophysicalModels/specie/include/forLiquids.H` | thermo 拼装部件 |
| `sensibleEnthalpy` | `included by forTabulated` | `src/thermophysicalModels/specie/include/forTabulated.H` | thermo 拼装部件 |
| `sensibleInternalEnergy` | `included by forGases` | `src/thermophysicalModels/specie/include/forGases.H` | thermo 拼装部件 |
| `sensibleInternalEnergy` | `included by forLiquids` | `src/thermophysicalModels/specie/include/forLiquids.H` | thermo 拼装部件 |
| `sensibleInternalEnergy` | `included by forTabulated` | `src/thermophysicalModels/specie/include/forTabulated.H` | thermo 拼装部件 |
| `sutherlandTransport` | `included by forAbsoluteGases` | `src/thermophysicalModels/specie/include/forAbsoluteGases.H` | thermo 拼装部件 |
| `sutherlandTransport` | `included by forGases` | `src/thermophysicalModels/specie/include/forGases.H` | thermo 拼装部件 |
| `tabulatedTransport` | `included by forTabulated` | `src/thermophysicalModels/specie/include/forTabulated.H` | thermo 拼装部件 |
| `typedefThermo` | `included by forThermo` | `src/thermophysicalModels/specie/include/forThermo.H` | thermo 拼装部件 |
| `forAbsoluteGases` | `include macro` | `src/thermophysicalModels/specie/include/forAbsoluteGases.H` | thermoType 组合宏 |
| `forGases` | `include macro` | `src/thermophysicalModels/specie/include/forGases.H` | thermoType 组合宏 |
| `forLiquids` | `include macro` | `src/thermophysicalModels/specie/include/forLiquids.H` | thermoType 组合宏 |
| `forTabulated` | `include macro` | `src/thermophysicalModels/specie/include/forTabulated.H` | thermoType 组合宏 |
| `forThermo` | `include macro` | `src/thermophysicalModels/specie/include/forThermo.H` | thermoType 组合宏 |
| `makeThermo` | `include macro` | `src/thermophysicalModels/specie/include/makeThermo.H` | thermoType 组合宏 |
| `typedefThermo` | `include macro` | `src/thermophysicalModels/specie/include/typedefThermo.H` | thermoType 组合宏 |
