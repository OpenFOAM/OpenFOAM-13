# fvPatchFields RTS 清单

> 机器生成清单（Phase 0）。

覆盖多行 addToRunTimeSelectionTable、makePatchFields / makeNullConstructablePatchFields、makePatchTypeField，以及 basic/constraint/derived 目录名。备注标明所属库（壁面函数、辐射、大气、波、shockFluid、模块本地等）。

**条目数**: 299

## 分类说明

- **core finiteVolume / constraint**: `src/finiteVolume/fields/fvPatchFields`
- **wall functions**: MomentumTransport / TurbulenceModels
- **radiation / atmospheric / waves**: 对应物理库
- **shockFluid / module-local**: 模块内 BC

| 类型名 | 基类/宏键 | 源码路径 | 备注 |
|--------|-----------|----------|------|
| `atmBoundaryLayerInletEpsilonFvPatchScalarField` | `fvPatchScalarField` | `src/atmosphericModels/derivedFvPatchFields/atmBoundaryLayerInletEpsilon/atmBoundaryLayerInletEpsilonFvPatchScalarField.C` | atmospheric BCs |
| `atmBoundaryLayerInletKFvPatchScalarField` | `fvPatchScalarField` | `src/atmosphericModels/derivedFvPatchFields/atmBoundaryLayerInletK/atmBoundaryLayerInletKFvPatchScalarField.C` | atmospheric BCs |
| `atmBoundaryLayerInletVelocityFvPatchVectorField` | `fvPatchVectorField` | `src/atmosphericModels/derivedFvPatchFields/atmBoundaryLayerInletVelocity/atmBoundaryLayerInletVelocityFvPatchVectorField.C` | atmospheric BCs |
| `nutkAtmRoughWallFunctionFvPatchScalarField` | `fvPatchScalarField` | `src/atmosphericModels/derivedFvPatchFields/nutkAtmRoughWallFunction/nutkAtmRoughWallFunctionFvPatchScalarField.C` | atmospheric BCs |
| `cyclic` | `directory` | `src/finiteVolume/fields/fvPatchFields/constraint/cyclic` | constraint |
| `cyclic` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/constraint/cyclic/cyclicFvPatchFields.C` | constraint |
| `cyclicSlip` | `directory` | `src/finiteVolume/fields/fvPatchFields/constraint/cyclicSlip` | constraint |
| `cyclicSlip` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/constraint/cyclicSlip/cyclicSlipFvPatchFields.C` | constraint |
| `empty` | `directory` | `src/finiteVolume/fields/fvPatchFields/constraint/empty` | constraint |
| `empty` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/constraint/empty/emptyFvPatchFields.C` | constraint |
| `internal` | `directory` | `src/finiteVolume/fields/fvPatchFields/constraint/internal` | constraint |
| `internal` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/constraint/internal/internalFvPatchFields.C` | constraint |
| `jumpCyclic` | `directory` | `src/finiteVolume/fields/fvPatchFields/constraint/jumpCyclic` | constraint |
| `nonConformalCyclic` | `directory` | `src/finiteVolume/fields/fvPatchFields/constraint/nonConformalCyclic` | constraint |
| `nonConformalCyclic` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/constraint/nonConformalCyclic/nonConformalCyclicFvPatchFields.C` | constraint |
| `nonConformalError` | `directory` | `src/finiteVolume/fields/fvPatchFields/constraint/nonConformalError` | constraint |
| `nonConformalError` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/constraint/nonConformalError/nonConformalErrorFvPatchFields.C` | constraint |
| `nonConformalProcessorCyclic` | `directory` | `src/finiteVolume/fields/fvPatchFields/constraint/nonConformalProcessorCyclic` | constraint |
| `nonConformalProcessorCyclic` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/constraint/nonConformalProcessorCyclic/nonConformalProcessorCyclicFvPatchFields.C` | constraint |
| `processor` | `directory` | `src/finiteVolume/fields/fvPatchFields/constraint/processor` | constraint |
| `processor` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/constraint/processor/processorFvPatchFields.C` | constraint |
| `processorCyclic` | `directory` | `src/finiteVolume/fields/fvPatchFields/constraint/processorCyclic` | constraint |
| `processorCyclic` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/constraint/processorCyclic/processorCyclicFvPatchFields.C` | constraint |
| `symmetry` | `directory` | `src/finiteVolume/fields/fvPatchFields/constraint/symmetry` | constraint |
| `symmetry` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/constraint/symmetry/symmetryFvPatchFields.C` | constraint |
| `symmetryPlane` | `directory` | `src/finiteVolume/fields/fvPatchFields/constraint/symmetryPlane` | constraint |
| `symmetryPlane` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/constraint/symmetryPlane/symmetryPlaneFvPatchFields.C` | constraint |
| `wedge` | `directory` | `src/finiteVolume/fields/fvPatchFields/constraint/wedge` | constraint |
| `wedge` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/constraint/wedge/wedgeFvPatchFields.C` | constraint |
| `advective` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/derived/advective/advectiveFvPatchFields.C` | core finiteVolume |
| `calculated` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/basic/calculated/calculatedFvPatchFields.C` | core finiteVolume |
| `codedFixedValue` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/derived/codedFixedValue/codedFixedValueFvPatchFields.C` | core finiteVolume |
| `codedMixed` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/derived/codedMixed/codedMixedFvPatchFields.C` | core finiteVolume |
| `directionMixed` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/basic/directionMixed/directionMixedFvPatchFields.C` | core finiteVolume |
| `entrainmentPressureFvPatchScalarField` | `fvPatchScalarField` | `src/finiteVolume/fields/fvPatchFields/derived/entrainmentPressure/entrainmentPressureFvPatchScalarField.C` | core finiteVolume |
| `externalCoupledMixed` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/derived/externalCoupledMixed/externalCoupledMixedFvPatchFields.C` | core finiteVolume |
| `extrapolatedCalculated` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/basic/extrapolatedCalculated/extrapolatedCalculatedFvPatchFields.C` | core finiteVolume |
| `fanPressureFvPatchScalarField` | `fvPatchScalarField` | `src/finiteVolume/fields/fvPatchFields/derived/fanPressure/fanPressureFvPatchScalarField.C` | core finiteVolume |
| `fanPressureJumpFvPatchScalarField` | `fvPatchScalarField` | `src/finiteVolume/fields/fvPatchFields/derived/fanPressureJump/fanPressureJumpFvPatchScalarField.C` | core finiteVolume |
| `fixedFluxExtrapolatedPressureFvPatchScalarField` | `fvPatchScalarField` | `src/finiteVolume/fields/fvPatchFields/derived/fixedFluxExtrapolatedPressure/fixedFluxExtrapolatedPressureFvPatchScalarField.C` | core finiteVolume |
| `fixedFluxPressureFvPatchScalarField` | `fvPatchScalarField` | `src/finiteVolume/fields/fvPatchFields/derived/fixedFluxPressure/fixedFluxPressureFvPatchScalarField.C` | core finiteVolume |
| `fixedGradient` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/basic/fixedGradient/fixedGradientFvPatchFields.C` | core finiteVolume |
| `fixedInternalValue` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/derived/fixedInternalValue/fixedInternalValueFvPatchFields.C` | core finiteVolume |
| `fixedJump` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/derived/fixedJump/fixedJumpFvPatchFields.C` | core finiteVolume |
| `fixedMean` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/derived/fixedMean/fixedMeanFvPatchFields.C` | core finiteVolume |
| `fixedMeanOutletInlet` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/derived/fixedMeanOutletInlet/fixedMeanOutletInletFvPatchFields.C` | core finiteVolume |
| `fixedNormalInletOutletVelocityFvPatchVectorField` | `fvPatchVectorField` | `src/finiteVolume/fields/fvPatchFields/derived/fixedNormalInletOutletVelocity/fixedNormalInletOutletVelocityFvPatchVectorField.C` | core finiteVolume |
| `fixedPressureCompressibleDensityFvPatchScalarField` | `fvPatchScalarField` | `src/finiteVolume/fields/fvPatchFields/derived/fixedPressureCompressibleDensity/fixedPressureCompressibleDensityFvPatchScalarField.C` | core finiteVolume |
| `fixedProfile` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/derived/fixedProfile/fixedProfileFvPatchFields.C` | core finiteVolume |
| `fixedValue` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/basic/fixedValue/fixedValueFvPatchFields.C` | core finiteVolume |
| `fixedValueInletOutlet` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/derived/fixedValueInletOutlet/fixedValueInletOutletFvPatchFields.C` | core finiteVolume |
| `flowRateInletVelocityFvPatchVectorField` | `fvPatchVectorField` | `src/finiteVolume/fields/fvPatchFields/derived/flowRateInletVelocity/flowRateInletVelocityFvPatchVectorField.C` | core finiteVolume |
| `flowRateOutletVelocityFvPatchVectorField` | `fvPatchVectorField` | `src/finiteVolume/fields/fvPatchFields/derived/flowRateOutletVelocity/flowRateOutletVelocityFvPatchVectorField.C` | core finiteVolume |
| `fluxCorrectedVelocityFvPatchVectorField` | `fvPatchVectorField` | `src/finiteVolume/fields/fvPatchFields/derived/fluxCorrectedVelocity/fluxCorrectedVelocityFvPatchVectorField.C` | core finiteVolume |
| `freestream` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/derived/freestream/freestreamFvPatchFields.C` | core finiteVolume |
| `freestreamPressureFvPatchScalarField` | `fvPatchScalarField` | `src/finiteVolume/fields/fvPatchFields/derived/freestreamPressure/freestreamPressureFvPatchScalarField.C` | core finiteVolume |
| `freestreamVelocityFvPatchVectorField` | `fvPatchVectorField` | `src/finiteVolume/fields/fvPatchFields/derived/freestreamVelocity/freestreamVelocityFvPatchVectorField.C` | core finiteVolume |
| `inletOutlet` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/derived/inletOutlet/inletOutletFvPatchFields.C` | core finiteVolume |
| `inletOutletTotalTemperatureFvPatchScalarField` | `fvPatchScalarField` | `src/finiteVolume/fields/fvPatchFields/derived/inletOutletTotalTemperature/inletOutletTotalTemperatureFvPatchScalarField.C` | core finiteVolume |
| `interfaceCompressionFvPatchScalarField` | `fvPatchScalarField` | `src/finiteVolume/fields/fvPatchFields/derived/interfaceCompression/interfaceCompressionFvPatchScalarField.C` | core finiteVolume |
| `interstitialInletVelocityFvPatchVectorField` | `fvPatchVectorField` | `src/finiteVolume/fields/fvPatchFields/derived/interstitialInletVelocity/interstitialInletVelocityFvPatchVectorField.C` | core finiteVolume |
| `mappedFlowRateVelocityFvPatchVectorField` | `fvPatchVectorField` | `src/finiteVolume/fields/fvPatchFields/derived/mappedFlowRateVelocity/mappedFlowRateVelocityFvPatchVectorField.C` | core finiteVolume |
| `mappedInternalValue` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/derived/mappedInternalValue/mappedInternalValueFvPatchFields.C` | core finiteVolume |
| `mappedValue` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/derived/mappedValue/mappedValueFvPatchFields.C` | core finiteVolume |
| `mappedVelocityFluxFvPatchField` | `fvPatchVectorField` | `src/finiteVolume/fields/fvPatchFields/derived/mappedVelocityFlux/mappedVelocityFluxFvPatchField.C` | core finiteVolume |
| `matchedFlowRateOutletVelocityFvPatchVectorField` | `fvPatchVectorField` | `src/finiteVolume/fields/fvPatchFields/derived/matchedFlowRateOutletVelocity/matchedFlowRateOutletVelocityFvPatchVectorField.C` | core finiteVolume |
| `mixed` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/basic/mixed/mixedFvPatchFields.C` | core finiteVolume |
| `movingMappedWallVelocityFvPatchVectorField` | `fvPatchVectorField` | `src/finiteVolume/fields/fvPatchFields/derived/movingMappedWallVelocity/movingMappedWallVelocityFvPatchVectorField.C` | core finiteVolume |
| `movingWallSlipVelocityFvPatchVectorField` | `fvPatchVectorField` | `src/finiteVolume/fields/fvPatchFields/derived/movingWallSlipVelocity/movingWallSlipVelocityFvPatchVectorField.C` | core finiteVolume |
| `movingWallVelocityFvPatchVectorField` | `fvPatchVectorField` | `src/finiteVolume/fields/fvPatchFields/derived/movingWallVelocity/movingWallVelocityFvPatchVectorField.C` | core finiteVolume |
| `noSlipFvPatchVectorField` | `fvPatchVectorField` | `src/finiteVolume/fields/fvPatchFields/derived/noSlip/noSlipFvPatchVectorField.C` | core finiteVolume |
| `outletInlet` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/derived/outletInlet/outletInletFvPatchFields.C` | core finiteVolume |
| `outletMappedUniformInlet` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/derived/outletMappedUniformInlet/outletMappedUniformInletFvPatchFields.C` | core finiteVolume |
| `outletPhaseMeanVelocityFvPatchVectorField` | `fvPatchVectorField` | `src/finiteVolume/fields/fvPatchFields/derived/outletPhaseMeanVelocity/outletPhaseMeanVelocityFvPatchVectorField.C` | core finiteVolume |
| `partialSlip` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/derived/partialSlip/partialSlipFvPatchFields.C` | core finiteVolume |
| `phaseHydrostaticPressureFvPatchScalarField` | `fvPatchScalarField` | `src/finiteVolume/fields/fvPatchFields/derived/phaseHydrostaticPressure/phaseHydrostaticPressureFvPatchScalarField.C` | core finiteVolume |
| `plenumPressureFvPatchScalarField` | `fvPatchScalarField` | `src/finiteVolume/fields/fvPatchFields/derived/plenumPressure/plenumPressureFvPatchScalarField.C` | core finiteVolume |
| `pressureDirectedInletOutletVelocityFvPatchVectorField` | `fvPatchVectorField` | `src/finiteVolume/fields/fvPatchFields/derived/pressureDirectedInletOutletVelocity/pressureDirectedInletOutletVelocityFvPatchVectorField.C` | core finiteVolume |
| `pressureDirectedInletVelocityFvPatchVectorField` | `fvPatchVectorField` | `src/finiteVolume/fields/fvPatchFields/derived/pressureDirectedInletVelocity/pressureDirectedInletVelocityFvPatchVectorField.C` | core finiteVolume |
| `pressureFvPatchScalarField` | `fvPatchScalarField` | `src/finiteVolume/fields/fvPatchFields/derived/pressure/pressureFvPatchScalarField.C` | core finiteVolume |
| `pressureInletOutletParSlipVelocityFvPatchVectorField` | `fvPatchVectorField` | `src/finiteVolume/fields/fvPatchFields/derived/pressureInletOutletParSlipVelocity/pressureInletOutletParSlipVelocityFvPatchVectorField.C` | core finiteVolume |
| `pressureInletOutletVelocityFvPatchVectorField` | `fvPatchVectorField` | `src/finiteVolume/fields/fvPatchFields/derived/pressureInletOutletVelocity/pressureInletOutletVelocityFvPatchVectorField.C` | core finiteVolume |
| `pressureInletUniformVelocityFvPatchVectorField` | `fvPatchVectorField` | `src/finiteVolume/fields/fvPatchFields/derived/pressureInletUniformVelocity/pressureInletUniformVelocityFvPatchVectorField.C` | core finiteVolume |
| `pressureInletVelocityFvPatchVectorField` | `fvPatchVectorField` | `src/finiteVolume/fields/fvPatchFields/derived/pressureInletVelocity/pressureInletVelocityFvPatchVectorField.C` | core finiteVolume |
| `pressureNormalInletOutletVelocityFvPatchVectorField` | `fvPatchVectorField` | `src/finiteVolume/fields/fvPatchFields/derived/pressureNormalInletOutletVelocity/pressureNormalInletOutletVelocityFvPatchVectorField.C` | core finiteVolume |
| `prghCyclicPressureFvPatchScalarField` | `fvPatchScalarField` | `src/finiteVolume/fields/fvPatchFields/derived/prghCyclicPressure/prghCyclicPressureFvPatchScalarField.C` | core finiteVolume |
| `prghTotalHydrostaticPressureFvPatchScalarField` | `fvPatchScalarField` | `src/finiteVolume/fields/fvPatchFields/derived/prghTotalHydrostaticPressure/prghTotalHydrostaticPressureFvPatchScalarField.C` | core finiteVolume |
| `rotatingPressureInletOutletVelocityFvPatchVectorField` | `fvPatchVectorField` | `src/finiteVolume/fields/fvPatchFields/derived/rotatingPressureInletOutletVelocity/rotatingPressureInletOutletVelocityFvPatchVectorField.C` | core finiteVolume |
| `rotatingTotalPressureFvPatchScalarField` | `fvPatchScalarField` | `src/finiteVolume/fields/fvPatchFields/derived/rotatingTotalPressure/rotatingTotalPressureFvPatchScalarField.C` | core finiteVolume |
| `rotatingWallVelocityFvPatchVectorField` | `fvPatchVectorField` | `src/finiteVolume/fields/fvPatchFields/derived/rotatingWallVelocity/rotatingWallVelocityFvPatchVectorField.C` | core finiteVolume |
| `slip` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/derived/slip/slipFvPatchFields.C` | core finiteVolume |
| `supersonicFreestreamFvPatchVectorField` | `fvPatchVectorField` | `src/finiteVolume/fields/fvPatchFields/derived/supersonicFreestream/supersonicFreestreamFvPatchVectorField.C` | core finiteVolume |
| `surfaceNormalFixedValueFvPatchVectorField` | `fvPatchVectorField` | `src/finiteVolume/fields/fvPatchFields/derived/surfaceNormalFixedValue/surfaceNormalFixedValueFvPatchVectorField.C` | core finiteVolume |
| `surfaceNormalUniformFixedValueFvPatchVectorField` | `fvPatchVectorField` | `src/finiteVolume/fields/fvPatchFields/derived/surfaceNormalUniformFixedValue/surfaceNormalUniformFixedValueFvPatchVectorField.C` | core finiteVolume |
| `swirlFlowRateInletVelocityFvPatchVectorField` | `fvPatchVectorField` | `src/finiteVolume/fields/fvPatchFields/derived/swirlFlowRateInletVelocity/swirlFlowRateInletVelocityFvPatchVectorField.C` | core finiteVolume |
| `swirlInletVelocityFvPatchVectorField` | `fvPatchVectorField` | `src/finiteVolume/fields/fvPatchFields/derived/swirlInletVelocity/swirlInletVelocityFvPatchVectorField.C` | core finiteVolume |
| `syringePressureFvPatchScalarField` | `fvPatchScalarField` | `src/finiteVolume/fields/fvPatchFields/derived/syringePressure/syringePressureFvPatchScalarField.C` | core finiteVolume |
| `timeVaryingMappedFixedValue` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/derived/timeVaryingMappedFixedValue/timeVaryingMappedFixedValueFvPatchFields.C` | core finiteVolume |
| `totalPressureFvPatchScalarField` | `fvPatchScalarField` | `src/finiteVolume/fields/fvPatchFields/derived/totalPressure/totalPressureFvPatchScalarField.C` | core finiteVolume |
| `totalTemperatureFvPatchScalarField` | `fvPatchScalarField` | `src/finiteVolume/fields/fvPatchFields/derived/totalTemperature/totalTemperatureFvPatchScalarField.C` | core finiteVolume |
| `translatingWallVelocityFvPatchVectorField` | `fvPatchVectorField` | `src/finiteVolume/fields/fvPatchFields/derived/translatingWallVelocity/translatingWallVelocityFvPatchVectorField.C` | core finiteVolume |
| `transonicEntrainmentPressureFvPatchScalarField` | `fvPatchScalarField` | `src/finiteVolume/fields/fvPatchFields/derived/transonicEntrainmentPressure/transonicEntrainmentPressureFvPatchScalarField.C` | core finiteVolume |
| `turbulentInlet` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/derived/turbulentInlet/turbulentInletFvPatchFields.C` | core finiteVolume |
| `turbulentIntensityKineticEnergyInletFvPatchScalarField` | `fvPatchScalarField` | `src/finiteVolume/fields/fvPatchFields/derived/turbulentIntensityKineticEnergyInlet/turbulentIntensityKineticEnergyInletFvPatchScalarField.C` | core finiteVolume |
| `uniformDensityHydrostaticPressureFvPatchScalarField` | `fvPatchScalarField` | `src/finiteVolume/fields/fvPatchFields/derived/uniformDensityHydrostaticPressure/uniformDensityHydrostaticPressureFvPatchScalarField.C` | core finiteVolume |
| `uniformFixedGradient` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/derived/uniformFixedGradient/uniformFixedGradientFvPatchFields.C` | core finiteVolume |
| `uniformFixedValue` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/derived/uniformFixedValue/uniformFixedValueFvPatchFields.C` | core finiteVolume |
| `uniformInletOutlet` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/derived/uniformInletOutlet/uniformInletOutletFvPatchFields.C` | core finiteVolume |
| `uniformJump` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/derived/uniformJump/uniformJumpFvPatchFields.C` | core finiteVolume |
| `uniformTotalPressureFvPatchScalarField` | `fvPatchScalarField` | `src/finiteVolume/fields/fvPatchFields/derived/uniformTotalPressure/uniformTotalPressureFvPatchScalarField.C` | core finiteVolume |
| `variableHeightFlowRateFvPatchScalarField` | `fvPatchScalarField` | `src/finiteVolume/fields/fvPatchFields/derived/variableHeightFlowRate/variableHeightFlowRateFvPatchField.C` | core finiteVolume |
| `variableHeightFlowRateInletVelocityFvPatchVectorField` | `fvPatchVectorField` | `src/finiteVolume/fields/fvPatchFields/derived/variableHeightFlowRateInletVelocity/variableHeightFlowRateInletVelocityFvPatchVectorField.C` | core finiteVolume |
| `waveSurfacePressureFvPatchScalarField` | `fvPatchScalarField` | `src/finiteVolume/fields/fvPatchFields/derived/waveSurfacePressure/waveSurfacePressureFvPatchScalarField.C` | core finiteVolume |
| `waveTransmissive` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/derived/waveTransmissive/waveTransmissiveFvPatchFields.C` | core finiteVolume |
| `zeroFixedValue` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/derived/zeroFixedValue/zeroFixedValueFvPatchFields.C` | core finiteVolume |
| `zeroGradient` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/basic/zeroGradient/zeroGradientFvPatchFields.C` | core finiteVolume |
| `zeroInletOutlet` | `makePatchFields*` | `src/finiteVolume/fields/fvPatchFields/derived/zeroInletOutlet/zeroInletOutletFvPatchFields.C` | core finiteVolume |
| `basicSymmetry` | `directory` | `src/finiteVolume/fields/fvPatchFields/basic/basicSymmetry` | core finiteVolume (basic dir) |
| `calculated` | `directory` | `src/finiteVolume/fields/fvPatchFields/basic/calculated` | core finiteVolume (basic dir) |
| `coupled` | `directory` | `src/finiteVolume/fields/fvPatchFields/basic/coupled` | core finiteVolume (basic dir) |
| `directionMixed` | `directory` | `src/finiteVolume/fields/fvPatchFields/basic/directionMixed` | core finiteVolume (basic dir) |
| `extrapolatedCalculated` | `directory` | `src/finiteVolume/fields/fvPatchFields/basic/extrapolatedCalculated` | core finiteVolume (basic dir) |
| `fixedGradient` | `directory` | `src/finiteVolume/fields/fvPatchFields/basic/fixedGradient` | core finiteVolume (basic dir) |
| `fixedValue` | `directory` | `src/finiteVolume/fields/fvPatchFields/basic/fixedValue` | core finiteVolume (basic dir) |
| `mixed` | `directory` | `src/finiteVolume/fields/fvPatchFields/basic/mixed` | core finiteVolume (basic dir) |
| `sliced` | `directory` | `src/finiteVolume/fields/fvPatchFields/basic/sliced` | core finiteVolume (basic dir) |
| `transform` | `directory` | `src/finiteVolume/fields/fvPatchFields/basic/transform` | core finiteVolume (basic dir) |
| `zeroGradient` | `directory` | `src/finiteVolume/fields/fvPatchFields/basic/zeroGradient` | core finiteVolume (basic dir) |
| `PrghPressure` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/PrghPressure` | core finiteVolume (derived dir) |
| `advective` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/advective` | core finiteVolume (derived dir) |
| `codedFixedValue` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/codedFixedValue` | core finiteVolume (derived dir) |
| `codedMixed` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/codedMixed` | core finiteVolume (derived dir) |
| `dynamicPressure` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/dynamicPressure` | core finiteVolume (derived dir) |
| `entrainmentPressure` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/entrainmentPressure` | core finiteVolume (derived dir) |
| `externalCoupledMixed` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/externalCoupledMixed` | core finiteVolume (derived dir) |
| `fanPressure` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/fanPressure` | core finiteVolume (derived dir) |
| `fanPressureJump` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/fanPressureJump` | core finiteVolume (derived dir) |
| `fixedFluxExtrapolatedPressure` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/fixedFluxExtrapolatedPressure` | core finiteVolume (derived dir) |
| `fixedFluxPressure` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/fixedFluxPressure` | core finiteVolume (derived dir) |
| `fixedInternalValue` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/fixedInternalValue` | core finiteVolume (derived dir) |
| `fixedJump` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/fixedJump` | core finiteVolume (derived dir) |
| `fixedMean` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/fixedMean` | core finiteVolume (derived dir) |
| `fixedMeanOutletInlet` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/fixedMeanOutletInlet` | core finiteVolume (derived dir) |
| `fixedNormalInletOutletVelocity` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/fixedNormalInletOutletVelocity` | core finiteVolume (derived dir) |
| `fixedNormalSlip` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/fixedNormalSlip` | core finiteVolume (derived dir) |
| `fixedPressureCompressibleDensity` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/fixedPressureCompressibleDensity` | core finiteVolume (derived dir) |
| `fixedProfile` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/fixedProfile` | core finiteVolume (derived dir) |
| `fixedValueInletOutlet` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/fixedValueInletOutlet` | core finiteVolume (derived dir) |
| `flowRateInletVelocity` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/flowRateInletVelocity` | core finiteVolume (derived dir) |
| `flowRateOutletVelocity` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/flowRateOutletVelocity` | core finiteVolume (derived dir) |
| `fluxCorrectedVelocity` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/fluxCorrectedVelocity` | core finiteVolume (derived dir) |
| `freestream` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/freestream` | core finiteVolume (derived dir) |
| `freestreamPressure` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/freestreamPressure` | core finiteVolume (derived dir) |
| `freestreamVelocity` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/freestreamVelocity` | core finiteVolume (derived dir) |
| `inletOutlet` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/inletOutlet` | core finiteVolume (derived dir) |
| `inletOutletTotalTemperature` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/inletOutletTotalTemperature` | core finiteVolume (derived dir) |
| `interfaceCompression` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/interfaceCompression` | core finiteVolume (derived dir) |
| `interstitialInletVelocity` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/interstitialInletVelocity` | core finiteVolume (derived dir) |
| `mappedFlowRateVelocity` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/mappedFlowRateVelocity` | core finiteVolume (derived dir) |
| `mappedInternalValue` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/mappedInternalValue` | core finiteVolume (derived dir) |
| `mappedValue` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/mappedValue` | core finiteVolume (derived dir) |
| `mappedVelocityFlux` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/mappedVelocityFlux` | core finiteVolume (derived dir) |
| `matchedFlowRateOutletVelocity` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/matchedFlowRateOutletVelocity` | core finiteVolume (derived dir) |
| `movingMappedWallVelocity` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/movingMappedWallVelocity` | core finiteVolume (derived dir) |
| `movingWallSlipVelocity` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/movingWallSlipVelocity` | core finiteVolume (derived dir) |
| `movingWallVelocity` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/movingWallVelocity` | core finiteVolume (derived dir) |
| `noSlip` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/noSlip` | core finiteVolume (derived dir) |
| `outletInlet` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/outletInlet` | core finiteVolume (derived dir) |
| `outletMappedUniformInlet` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/outletMappedUniformInlet` | core finiteVolume (derived dir) |
| `outletPhaseMeanVelocity` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/outletPhaseMeanVelocity` | core finiteVolume (derived dir) |
| `partialSlip` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/partialSlip` | core finiteVolume (derived dir) |
| `phaseHydrostaticPressure` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/phaseHydrostaticPressure` | core finiteVolume (derived dir) |
| `plenumPressure` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/plenumPressure` | core finiteVolume (derived dir) |
| `pressure` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/pressure` | core finiteVolume (derived dir) |
| `pressureDirectedInletOutletVelocity` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/pressureDirectedInletOutletVelocity` | core finiteVolume (derived dir) |
| `pressureDirectedInletVelocity` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/pressureDirectedInletVelocity` | core finiteVolume (derived dir) |
| `pressureInletOutletParSlipVelocity` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/pressureInletOutletParSlipVelocity` | core finiteVolume (derived dir) |
| `pressureInletOutletVelocity` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/pressureInletOutletVelocity` | core finiteVolume (derived dir) |
| `pressureInletUniformVelocity` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/pressureInletUniformVelocity` | core finiteVolume (derived dir) |
| `pressureInletVelocity` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/pressureInletVelocity` | core finiteVolume (derived dir) |
| `pressureNormalInletOutletVelocity` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/pressureNormalInletOutletVelocity` | core finiteVolume (derived dir) |
| `prghCyclicPressure` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/prghCyclicPressure` | core finiteVolume (derived dir) |
| `prghTotalHydrostaticPressure` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/prghTotalHydrostaticPressure` | core finiteVolume (derived dir) |
| `rotatingPressureInletOutletVelocity` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/rotatingPressureInletOutletVelocity` | core finiteVolume (derived dir) |
| `rotatingTotalPressure` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/rotatingTotalPressure` | core finiteVolume (derived dir) |
| `rotatingWallVelocity` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/rotatingWallVelocity` | core finiteVolume (derived dir) |
| `slip` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/slip` | core finiteVolume (derived dir) |
| `supersonicFreestream` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/supersonicFreestream` | core finiteVolume (derived dir) |
| `surfaceNormalFixedValue` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/surfaceNormalFixedValue` | core finiteVolume (derived dir) |
| `surfaceNormalUniformFixedValue` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/surfaceNormalUniformFixedValue` | core finiteVolume (derived dir) |
| `swirlFlowRateInletVelocity` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/swirlFlowRateInletVelocity` | core finiteVolume (derived dir) |
| `swirlInletVelocity` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/swirlInletVelocity` | core finiteVolume (derived dir) |
| `syringePressure` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/syringePressure` | core finiteVolume (derived dir) |
| `timeVaryingMappedFixedValue` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/timeVaryingMappedFixedValue` | core finiteVolume (derived dir) |
| `totalPressure` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/totalPressure` | core finiteVolume (derived dir) |
| `totalTemperature` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/totalTemperature` | core finiteVolume (derived dir) |
| `translatingWallVelocity` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/translatingWallVelocity` | core finiteVolume (derived dir) |
| `transonicEntrainmentPressure` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/transonicEntrainmentPressure` | core finiteVolume (derived dir) |
| `turbulentInlet` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/turbulentInlet` | core finiteVolume (derived dir) |
| `turbulentIntensityKineticEnergyInlet` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/turbulentIntensityKineticEnergyInlet` | core finiteVolume (derived dir) |
| `uniformDensityHydrostaticPressure` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/uniformDensityHydrostaticPressure` | core finiteVolume (derived dir) |
| `uniformFixedGradient` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/uniformFixedGradient` | core finiteVolume (derived dir) |
| `uniformFixedValue` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/uniformFixedValue` | core finiteVolume (derived dir) |
| `uniformInletOutlet` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/uniformInletOutlet` | core finiteVolume (derived dir) |
| `uniformJump` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/uniformJump` | core finiteVolume (derived dir) |
| `uniformTotalPressure` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/uniformTotalPressure` | core finiteVolume (derived dir) |
| `variableHeightFlowRate` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/variableHeightFlowRate` | core finiteVolume (derived dir) |
| `variableHeightFlowRateInletVelocity` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/variableHeightFlowRateInletVelocity` | core finiteVolume (derived dir) |
| `waveSurfacePressure` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/waveSurfacePressure` | core finiteVolume (derived dir) |
| `waveTransmissive` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/waveTransmissive` | core finiteVolume (derived dir) |
| `zeroFixedValue` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/zeroFixedValue` | core finiteVolume (derived dir) |
| `zeroInletOutlet` | `directory` | `src/finiteVolume/fields/fvPatchFields/derived/zeroInletOutlet` | core finiteVolume (derived dir) |
| `LagrangianPatch` | `LagrangianPatch` | `src/lagrangian/Lagrangian/LagrangianMesh/LagrangianPatches/LagrangianPatch/LagrangianPatch.C` | lagrangian-related |
| `cloudVelocityLagrangianPatch` | `LagrangianPatch` | `src/lagrangian/cloud/derivedLagrangianPatches/cloudVelocity/cloudVelocityLagrangianPatch.C` | lagrangian-related |
| `cyclicLagrangianPatch` | `LagrangianPatch` | `src/lagrangian/Lagrangian/LagrangianMesh/LagrangianPatches/constraint/cyclic/cyclicLagrangianPatch.C` | lagrangian-related |
| `emptyLagrangianPatch` | `LagrangianPatch` | `src/lagrangian/Lagrangian/LagrangianMesh/LagrangianPatches/constraint/empty/emptyLagrangianPatch.C` | lagrangian-related |
| `internalLagrangianPatch` | `LagrangianPatch` | `src/lagrangian/Lagrangian/LagrangianMesh/LagrangianPatches/constraint/internal/internalLagrangianPatch.C` | lagrangian-related |
| `nonConformalCyclicLagrangianPatch` | `LagrangianPatch` | `src/lagrangian/Lagrangian/LagrangianMesh/LagrangianPatches/constraint/nonConformalCyclic/nonConformalCyclicLagrangianPatch.C` | lagrangian-related |
| `nonConformalErrorLagrangianPatch` | `LagrangianPatch` | `src/lagrangian/Lagrangian/LagrangianMesh/LagrangianPatches/constraint/nonConformalError/nonConformalErrorLagrangianPatch.C` | lagrangian-related |
| `nonConformalProcessorCyclicLagrangianPatch` | `LagrangianPatch` | `src/lagrangian/Lagrangian/LagrangianMesh/LagrangianPatches/constraint/nonConformalProcessorCyclic/nonConformalProcessorCyclicLagrangianPatch.C` | lagrangian-related |
| `processorCyclicLagrangianPatch` | `LagrangianPatch` | `src/lagrangian/Lagrangian/LagrangianMesh/LagrangianPatches/constraint/processorCyclic/processorCyclicLagrangianPatch.C` | lagrangian-related |
| `processorLagrangianPatch` | `LagrangianPatch` | `src/lagrangian/Lagrangian/LagrangianMesh/LagrangianPatches/constraint/processor/processorLagrangianPatch.C` | lagrangian-related |
| `symmetryLagrangianPatch` | `LagrangianPatch` | `src/lagrangian/Lagrangian/LagrangianMesh/LagrangianPatches/constraint/symmetry/symmetryLagrangianPatch.C` | lagrangian-related |
| `symmetryPlaneLagrangianPatch` | `LagrangianPatch` | `src/lagrangian/Lagrangian/LagrangianMesh/LagrangianPatches/constraint/symmetryPlane/symmetryPlaneLagrangianPatch.C` | lagrangian-related |
| `wallLagrangianPatch` | `LagrangianPatch` | `src/lagrangian/Lagrangian/LagrangianMesh/LagrangianPatches/derived/wall/wallLagrangianPatch.C` | lagrangian-related |
| `wedgeLagrangianPatch` | `LagrangianPatch` | `src/lagrangian/Lagrangian/LagrangianMesh/LagrangianPatches/constraint/wedge/wedgeLagrangianPatch.C` | lagrangian-related |
| `JohnsonJacksonParticleSlipFvPatchVectorField` | `fvPatchVectorField` | `applications/modules/multiphaseEuler/momentumTransportModels/derivedFvPatchFields/JohnsonJacksonParticleSlip/JohnsonJacksonParticleSlipFvPatchVectorField.C` | module-local BCs |
| `JohnsonJacksonParticleThetaFvPatchScalarField` | `fvPatchScalarField` | `applications/modules/multiphaseEuler/momentumTransportModels/derivedFvPatchFields/JohnsonJacksonParticleTheta/JohnsonJacksonParticleThetaFvPatchScalarField.C` | module-local BCs |
| `alphaOneFvPatchScalarField` | `fvPatchScalarField` | `applications/modules/isothermalFilm/derivedFvPatchFields/alphaOne/alphaOneFvPatchScalarField.C` | module-local BCs |
| `alphatBoilingWallFunctionFvPatchScalarField` | `fvPatchScalarField` | `applications/modules/multiphaseEuler/fvModels/wallBoiling/alphatBoilingWallFunctionFvPatchScalarField.C` | module-local BCs |
| `distributionSizeGroupFvPatchScalarField` | `fvPatchScalarField` | `applications/modules/multiphaseEuler/populationBalance/derivedFvPatchFields/distributionSizeGroup/distributionSizeGroupFvPatchScalarField.C` | module-local BCs |
| `filmContactAngleFvPatchScalarField` | `fvPatchScalarField` | `applications/modules/isothermalFilm/derivedFvPatchFields/filmContactAngle/filmContactAngleFvPatchScalarField.C` | module-local BCs |
| `filmSurfaceFvPatch` | `fvPatch` | `applications/modules/isothermalFilm/patches/filmSurface/filmSurfaceFvPatch/filmSurfaceFvPatch.C` | module-local BCs |
| `filmSurfacePointPatch` | `facePointPatch` | `applications/modules/isothermalFilm/patches/filmSurface/filmSurfacePointPatch/filmSurfacePointPatch.C` | module-local BCs |
| `filmSurfacePolyPatch` | `polyPatch` | `applications/modules/isothermalFilm/patches/filmSurface/filmSurfacePolyPatch/filmSurfacePolyPatch.C` | module-local BCs |
| `filmSurfaceVelocityFvPatchVectorField` | `fvPatchVectorField` | `applications/modules/isothermalFilm/derivedFvPatchFields/filmSurfaceVelocity/filmSurfaceVelocityFvPatchVectorField.C` | module-local BCs |
| `filmWallFvPatch` | `fvPatch` | `applications/modules/isothermalFilm/patches/filmWall/filmWallFvPatch/filmWallFvPatch.C` | module-local BCs |
| `filmWallPointPatch` | `facePointPatch` | `applications/modules/isothermalFilm/patches/filmWall/filmWallPointPatch/filmWallPointPatch.C` | module-local BCs |
| `filmWallPolyPatch` | `polyPatch` | `applications/modules/isothermalFilm/patches/filmWall/filmWallPolyPatch/filmWallPolyPatch.C` | module-local BCs |
| `hydrostaticDisplacementFvPatchVectorField` | `fvPatchVectorField` | `applications/modules/solidDisplacement/derivedFvPatchFields/hydrostaticDisplacement/hydrostaticDisplacementFvPatchVectorField.C` | module-local BCs |
| `mappedFilmPressureFvPatchScalarField` | `fvPatchScalarField` | `applications/modules/isothermalFilm/derivedFvPatchFields/mappedFilmPressure/mappedFilmPressureFvPatchScalarField.C` | module-local BCs |
| `mappedFilmSurfaceFvPatch` | `fvPatch` | `applications/modules/isothermalFilm/patches/mappedFilmSurface/mappedFilmSurfaceFvPatch/mappedFilmSurfaceFvPatch.C` | module-local BCs |
| `mappedFilmSurfacePointPatch` | `facePointPatch` | `applications/modules/isothermalFilm/patches/mappedFilmSurface/mappedFilmSurfacePointPatch/mappedFilmSurfacePointPatch.C` | module-local BCs |
| `mappedFilmSurfacePolyPatch` | `polyPatch` | `applications/modules/isothermalFilm/patches/mappedFilmSurface/mappedFilmSurfacePolyPatch/mappedFilmSurfacePolyPatch.C` | module-local BCs |
| `mappedFilmWallFvPatch` | `fvPatch` | `applications/modules/isothermalFilm/patches/mappedFilmWall/mappedFilmWallFvPatch/mappedFilmWallFvPatch.C` | module-local BCs |
| `mappedFilmWallPointPatch` | `facePointPatch` | `applications/modules/isothermalFilm/patches/mappedFilmWall/mappedFilmWallPointPatch/mappedFilmWallPointPatch.C` | module-local BCs |
| `mappedFilmWallPolyPatch` | `polyPatch` | `applications/modules/isothermalFilm/patches/mappedFilmWall/mappedFilmWallPolyPatch/mappedFilmWallPolyPatch.C` | module-local BCs |
| `multiphaseCoupledTemperatureFvPatchScalarField` | `fvPatchScalarField` | `applications/modules/multiphaseEuler/thermophysicalTransportModels/derivedFvPatchFields/multiphaseCoupledTemperature/multiphaseCoupledTemperatureFvPatchScalarField.C` | module-local BCs |
| `multiphaseExternalTemperatureFvPatchScalarField` | `fvPatchScalarField` | `applications/modules/multiphaseEuler/thermophysicalTransportModels/derivedFvPatchFields/multiphaseExternalTemperature/multiphaseExternalTemperatureFvPatchScalarField.C` | module-local BCs |
| `singleSizeGroupFvPatchScalarField` | `fvPatchScalarField` | `applications/modules/multiphaseEuler/populationBalance/derivedFvPatchFields/singleSizeGroup/singleSizeGroupFvPatchScalarField.C` | module-local BCs |
| `tractionDisplacementFvPatchVectorField` | `fvPatchVectorField` | `applications/modules/solidDisplacement/derivedFvPatchFields/tractionDisplacement/tractionDisplacementFvPatchVectorField.C` | module-local BCs |
| `wallBoilingPhaseChangeRateFvPatchScalarField` | `fvPatchScalarField` | `applications/modules/multiphaseEuler/fvModels/wallBoiling/wallBoilingPhaseChangeRateFvPatchScalarField.C` | module-local BCs |
| `epsilonWallFunctionFvPatchScalarField` | `fvPatchScalarField` | `src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/wallFunctions/epsilonWallFunctions/epsilonWallFunction/epsilonWallFunctionFvPatchScalarField.C` | momentum transport / wall functions |
| `epsilonmWallFunctionFvPatchScalarField` | `fvPatchScalarField` | `src/MomentumTransportModels/phaseCompressible/derivedFvPatchFields/wallFunctions/epsilonWallFunctions/epsilonmWallFunction/epsilonmWallFunctionFvPatchScalarField.C` | momentum transport / wall functions |
| `fWallFunctionFvPatchScalarField` | `fvPatchScalarField` | `src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/wallFunctions/fWallFunctions/fWallFunction/fWallFunctionFvPatchScalarField.C` | momentum transport / wall functions |
| `fixedShearStressFvPatchVectorField` | `fvPatchVectorField` | `src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/fixedShearStress/fixedShearStressFvPatchVectorField.C` | momentum transport / wall functions |
| `kLowReWallFunctionFvPatchScalarField` | `fvPatchScalarField` | `src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/wallFunctions/kqRWallFunctions/kLowReWallFunction/kLowReWallFunctionFvPatchScalarField.C` | momentum transport / wall functions |
| `kqRWallFunction` | `makePatchFields*` | `src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/wallFunctions/kqRWallFunctions/kqRWallFunction/kqRWallFunctionFvPatchFields.C` | momentum transport / wall functions |
| `nutLowReWallFunctionFvPatchScalarField` | `fvPatchScalarField` | `src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/wallFunctions/nutWallFunctions/nutLowReWallFunction/nutLowReWallFunctionFvPatchScalarField.C` | momentum transport / wall functions |
| `nutURoughWallFunctionFvPatchScalarField` | `fvPatchScalarField` | `src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/wallFunctions/nutWallFunctions/nutURoughWallFunction/nutURoughWallFunctionFvPatchScalarField.C` | momentum transport / wall functions |
| `nutUSpaldingWallFunctionFvPatchScalarField` | `fvPatchScalarField` | `src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/wallFunctions/nutWallFunctions/nutUSpaldingWallFunction/nutUSpaldingWallFunctionFvPatchScalarField.C` | momentum transport / wall functions |
| `nutUWallFunctionFvPatchScalarField` | `fvPatchScalarField` | `src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/wallFunctions/nutWallFunctions/nutUWallFunction/nutUWallFunctionFvPatchScalarField.C` | momentum transport / wall functions |
| `nutkRoughWallFunctionFvPatchScalarField` | `fvPatchScalarField` | `src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/wallFunctions/nutWallFunctions/nutkRoughWallFunction/nutkRoughWallFunctionFvPatchScalarField.C` | momentum transport / wall functions |
| `nutkWallFunctionFvPatchScalarField` | `fvPatchScalarField` | `src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/wallFunctions/nutWallFunctions/nutkWallFunction/nutkWallFunctionFvPatchScalarField.C` | momentum transport / wall functions |
| `omegaWallFunctionFvPatchScalarField` | `fvPatchScalarField` | `src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/wallFunctions/omegaWallFunctions/omegaWallFunction/omegaWallFunctionFvPatchScalarField.C` | momentum transport / wall functions |
| `porousBafflePressureFvPatchField` | `fvPatchScalarField` | `src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/porousBafflePressure/porousBafflePressureFvPatchField.C` | momentum transport / wall functions |
| `turbulentMixingLengthDissipationRateInletFvPatchScalarField` | `fvPatchScalarField` | `src/MomentumTransportModels/momentumTransportModels/RAS/derivedFvPatchFields/turbulentMixingLengthDissipationRateInlet/turbulentMixingLengthDissipationRateInletFvPatchScalarField.C` | momentum transport / wall functions |
| `turbulentMixingLengthFrequencyInletFvPatchScalarField` | `fvPatchScalarField` | `src/MomentumTransportModels/momentumTransportModels/RAS/derivedFvPatchFields/turbulentMixingLengthFrequencyInlet/turbulentMixingLengthFrequencyInletFvPatchScalarField.C` | momentum transport / wall functions |
| `v2WallFunctionFvPatchScalarField` | `fvPatchScalarField` | `src/MomentumTransportModels/momentumTransportModels/derivedFvPatchFields/wallFunctions/v2WallFunctions/v2WallFunction/v2WallFunctionFvPatchScalarField.C` | momentum transport / wall functions |
| `alphaContactAngleFvPatchScalarField` | `fvPatchScalarField` | `src/multiphaseModels/multiphaseProperties/alphaContactAngle/alphaContactAngleFvPatchScalarField.C` | multiphase BCs |
| `MarshakRadiationFixedTemperatureFvPatchScalarField` | `fvPatchScalarField` | `src/radiationModels/derivedFvPatchFields/MarshakRadiationFixedTemperature/MarshakRadiationFixedTemperatureFvPatchScalarField.C` | radiation BCs |
| `MarshakRadiationFvPatchScalarField` | `fvPatchScalarField` | `src/radiationModels/derivedFvPatchFields/MarshakRadiation/MarshakRadiationFvPatchScalarField.C` | radiation BCs |
| `greyDiffusiveRadiationMixedFvPatchScalarField` | `fvPatchScalarField` | `src/radiationModels/derivedFvPatchFields/greyDiffusiveRadiation/greyDiffusiveRadiationMixedFvPatchScalarField.C` | radiation BCs |
| `greyDiffusiveViewFactorFixedValueFvPatchScalarField` | `fvPatchScalarField` | `src/radiationModels/derivedFvPatchFields/greyDiffusiveViewFactor/greyDiffusiveViewFactorFixedValueFvPatchScalarField.C` | radiation BCs |
| `wideBandDiffusiveRadiationMixedFvPatchScalarField` | `fvPatchScalarField` | `src/radiationModels/derivedFvPatchFields/wideBandDiffusiveRadiation/wideBandDiffusiveRadiationMixedFvPatchScalarField.C` | radiation BCs |
| `fixedRhoFvPatchScalarField` | `fvPatchScalarField` | `applications/modules/shockFluid/derivedFvPatchFields/rho/fixedRhoFvPatchScalarField.C` | shockFluid module BCs |
| `maxwellSlipUFvPatchVectorField` | `fvPatchVectorField` | `applications/modules/shockFluid/derivedFvPatchFields/U/maxwellSlipUFvPatchVectorField.C` | shockFluid module BCs |
| `mixedFixedValueSlip` | `makePatchFields*` | `applications/modules/shockFluid/derivedFvPatchFields/mixedFixedValueSlip/mixedFixedValueSlipFvPatchFields.C` | shockFluid module BCs |
| `smoluchowskiJumpTFvPatchScalarField` | `fvPatchScalarField` | `applications/modules/shockFluid/derivedFvPatchFields/T/smoluchowskiJumpTFvPatchScalarField.C` | shockFluid module BCs |
| `energyJumpFvPatchScalarField` | `fvPatchScalarField` | `src/thermophysicalModels/basic/derivedFvPatchFields/energyJump/energyJumpFvPatchScalarField.C` | thermophysical BCs |
| `fixedEnergyFvPatchScalarField` | `fvPatchScalarField` | `src/thermophysicalModels/basic/derivedFvPatchFields/fixedEnergy/fixedEnergyFvPatchScalarField.C` | thermophysical BCs |
| `fixedUnburntEnthalpyFvPatchScalarField` | `fvPatchScalarField` | `src/thermophysicalModels/multicomponentThermo/derivedFvPatchFields/fixedUnburntEnthalpy/fixedUnburntEnthalpyFvPatchScalarField.C` | thermophysical BCs |
| `gradientEnergyFvPatchScalarField` | `fvPatchScalarField` | `src/thermophysicalModels/basic/derivedFvPatchFields/gradientEnergy/gradientEnergyFvPatchScalarField.C` | thermophysical BCs |
| `gradientUnburntEnthalpyFvPatchScalarField` | `fvPatchScalarField` | `src/thermophysicalModels/multicomponentThermo/derivedFvPatchFields/gradientUnburntEnthalpy/gradientUnburntEnthalpyFvPatchScalarField.C` | thermophysical BCs |
| `mixedEnergyFvPatchScalarField` | `fvPatchScalarField` | `src/thermophysicalModels/basic/derivedFvPatchFields/mixedEnergy/mixedEnergyFvPatchScalarField.C` | thermophysical BCs |
| `mixedUnburntEnthalpyFvPatchScalarField` | `fvPatchScalarField` | `src/thermophysicalModels/multicomponentThermo/derivedFvPatchFields/mixedUnburntEnthalpy/mixedUnburntEnthalpyFvPatchScalarField.C` | thermophysical BCs |
| `alphatJayatillekeWallFunctionFvPatchScalarField` | `fvPatchScalarField` | `src/ThermophysicalTransportModels/fluid/derivedFvPatchFields/alphatWallFunctions/alphatJayatillekeWallFunction/alphatJayatillekeWallFunctionFvPatchScalarField.C` | thermophysical transport BCs |
| `alphatWallFunctionFvPatchScalarField` | `fvPatchScalarField` | `src/ThermophysicalTransportModels/fluid/derivedFvPatchFields/alphatWallFunctions/alphatWallFunction/alphatWallFunctionFvPatchScalarField.C` | thermophysical transport BCs |
| `convectiveHeatTransferFvPatchScalarField` | `fvPatchScalarField` | `src/ThermophysicalTransportModels/fluid/derivedFvPatchFields/convectiveHeatTransfer/convectiveHeatTransferFvPatchScalarField.C` | thermophysical transport BCs |
| `coupledTemperatureFvPatchScalarField` | `fvPatchScalarField` | `src/ThermophysicalTransportModels/coupledThermophysicalTransportModels/coupledTemperature/coupledTemperatureFvPatchScalarField.C` | thermophysical transport BCs |
| `externalCoupledTemperatureMixedFvPatchScalarField` | `fvPatchScalarField` | `src/ThermophysicalTransportModels/fluid/derivedFvPatchFields/externalCoupledTemperatureMixed/externalCoupledTemperatureMixedFvPatchScalarField.C` | thermophysical transport BCs |
| `externalTemperatureFvPatchScalarField` | `fvPatchScalarField` | `src/ThermophysicalTransportModels/coupledThermophysicalTransportModels/externalTemperature/externalTemperatureFvPatchScalarField.C` | thermophysical transport BCs |
| `lumpedMassTemperatureFvPatchScalarField` | `fvPatchScalarField` | `src/ThermophysicalTransportModels/coupledThermophysicalTransportModels/lumpedMassTemperature/lumpedMassTemperatureFvPatchScalarField.C` | thermophysical transport BCs |
| `totalFlowRateAdvectiveDiffusiveFvPatchScalarField` | `fvPatchScalarField` | `src/ThermophysicalTransportModels/fluid/derivedFvPatchFields/totalFlowRateAdvectiveDiffusive/totalFlowRateAdvectiveDiffusiveFvPatchScalarField.C` | thermophysical transport BCs |
| `alphaFixedPressureFvPatchScalarField` | `fvPatchScalarField` | `src/twoPhaseModels/twoPhaseProperties/alphaFixedPressure/alphaFixedPressureFvPatchScalarField.C` | twoPhase BCs |
| `contactAngleFvPatchScalarField` | `fvPatchScalarField` | `src/twoPhaseModels/interfaceProperties/contactAngle/contactAngleFvPatchScalarField.C` | twoPhase BCs |
| `waveAlphaFvPatchScalarField` | `fvPatchScalarField` | `src/waves/derivedFvPatchFields/waveAlpha/waveAlphaFvPatchScalarField.C` | wave BCs |
| `waveInletOutlet` | `makePatchFields*` | `src/waves/derivedFvPatchFields/waveInletOutlet/waveInletOutletFvPatchFields.C` | wave BCs |
| `waveVelocityFvPatchVectorField` | `fvPatchVectorField` | `src/waves/derivedFvPatchFields/waveVelocity/waveVelocityFvPatchVectorField.C` | wave BCs |
