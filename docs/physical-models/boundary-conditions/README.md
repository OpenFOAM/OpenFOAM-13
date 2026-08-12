# 边界条件

Phase **2** 全谱：`fvPatchField` 及 inventory 中相关 patch 类型。

- Inventory 原始行：**299**
- 去重后文档页：**199**（目录 stub 与 RTS 注册合并为一条）
- 其中标准 `fvPatchField`：**173**；Lagrangian/网格 patch 等：**26**

## 本目录结构

| 子目录 | 内容 | 条目 |
|--------|------|------|
| [basic/](basic/) | `fixedValue`、`zeroGradient`、`mixed` 等基本类型 | 11 |
| [constraint/](constraint/) | `empty`、`wedge`、`symmetry`、`cyclic`、`processor` 等 | 13 |
| [derived/](derived/) | 按物理意图分组的派生 BC | 175 |

### derived 分组

| 分组 | 说明 | 条目 |
|------|------|------|
| [pressure/](derived/pressure/) | 压力 | 27 |
| [velocity/](derived/velocity/) | 速度 / 壁面运动 | 21 |
| [thermal/](derived/thermal/) | 热 / 温度 | 6 |
| [thermophysical-energy/](derived/thermophysical-energy/) | 能量 / 焓（thermo） | 8 |
| [inlet-outlet/](derived/inlet-outlet/) | 进出流混合 | 8 |
| [mapped/](derived/mapped/) | 映射 / 耦合 | 8 |
| [turbulence-inlets/](derived/turbulence-inlets/) | 湍流入口 | 4 |
| [vof-multiphase/](derived/vof-multiphase/) | VoF / 多相 | 9 |
| [coded/](derived/coded/) | 编码 BC | 2 |
| [wall-functions/](derived/wall-functions/) | 壁面函数 | 18 |
| [radiation/](derived/radiation/) | 辐射 | 5 |
| [atmospheric/](derived/atmospheric/) | 大气 | 4 |
| [waves/](derived/waves/) | 波浪 | 4 |
| [shockFluid/](derived/shockFluid/) | shockFluid | 4 |
| [film/](derived/film/) | 薄膜 | 16 |
| [solid-displacement/](derived/solid-displacement/) | 固体位移 | 2 |
| [multiphaseEuler/](derived/multiphaseEuler/) | multiphaseEuler | 7 |
| [lagrangian/](derived/lagrangian/) | Lagrangian patch | 14 |
| [general/](derived/general/) | 通用派生 | 8 |

## 场类型对照（速查）

| 场 | 常用 BC 族 | 入口目录 |
|----|------------|----------|
| `U` | `noSlip`、`fixedValue`、`flowRateInletVelocity`、`pressureInletOutletVelocity`、壁面运动 | [derived/velocity](derived/velocity/) |
| `p` / `p_rgh` | `fixedFluxPressure`、`totalPressure`、`prgh`*`、`waveSurfacePressure` | [derived/pressure](derived/pressure/) |
| `T` | `fixedValue`、`inletOutlet`、`externalTemperature`、`coupledTemperature` | [derived/thermal](derived/thermal/) |
| `h`/`e` | `fixedEnergy`、`mixedEnergy`、`gradientEnergy`（由 thermo 映射） | [derived/thermophysical-energy](derived/thermophysical-energy/) |
| `alpha`.*` | `contactAngle`、`inletOutlet`、`waveAlpha`、`variableHeightFlowRate` | [derived/vof-multiphase](derived/vof-multiphase/) |
| `nut`/`k`/`epsilon`/`omega` | `*WallFunction`、湍流入口 | [derived/wall-functions](derived/wall-functions/)、[turbulence-inlets](derived/turbulence-inlets/) |
| `alphat` | `alphatWallFunction`、`alphatJayatillekeWallFunction` | [derived/wall-functions](derived/wall-functions/) |
| 辐射 `G`/`I`/`qr` | `MarshakRadiation`*`、`greyDiffusive`*` | [derived/radiation](derived/radiation/) |
| 大气入口 | `atmBoundaryLayerInlet`*` | [derived/atmospheric](derived/atmospheric/) |
| 波浪 | `waveVelocity`、`waveAlpha`、`waveInletOutlet` | [derived/waves](derived/waves/) |

## 库外 / 模块本地 BC

下列分组**不会**出现在纯 `libfiniteVolume` 中，使用前确认求解器 `Make/options` 已链接对应库：

- 壁面函数 → MomentumTransport
- 辐射 → `libradiationModels`
- 大气 → `libatmosphericModels`
- 波浪 → `libwaves`
- `shockFluid` / `film` / `multiphaseEuler` / `solidDisplacement` → 模块本地

## 全量索引（按类型名）

| 类型 | 分组 | 文档 |
|------|------|------|
| `advective` | derived/inlet-outlet | [derived/inlet-outlet/advective.md](derived/inlet-outlet/advective.md) |
| `alphaContactAngle` | derived/vof-multiphase | [derived/vof-multiphase/alphaContactAngle.md](derived/vof-multiphase/alphaContactAngle.md) |
| `alphaFixedPressure` | derived/vof-multiphase | [derived/vof-multiphase/alphaFixedPressure.md](derived/vof-multiphase/alphaFixedPressure.md) |
| `alphaOne` | derived/film | [derived/film/alphaOne.md](derived/film/alphaOne.md) |
| `alphatBoilingWallFunction` | derived/wall-functions | [derived/wall-functions/alphatBoilingWallFunction.md](derived/wall-functions/alphatBoilingWallFunction.md) |
| `alphatJayatillekeWallFunction` / `compressible`::alphatJayatillekeWallFunction` | derived/wall-functions | [derived/wall-functions/alphatJayatillekeWallFunction.md](derived/wall-functions/alphatJayatillekeWallFunction.md) |
| `alphatWallFunction` / `compressible`::alphatWallFunction` | derived/wall-functions | [derived/wall-functions/alphatWallFunction.md](derived/wall-functions/alphatWallFunction.md) |
| `atmBoundaryLayerInletEpsilon` | derived/atmospheric | [derived/atmospheric/atmBoundaryLayerInletEpsilon.md](derived/atmospheric/atmBoundaryLayerInletEpsilon.md) |
| `atmBoundaryLayerInletK` | derived/atmospheric | [derived/atmospheric/atmBoundaryLayerInletK.md](derived/atmospheric/atmBoundaryLayerInletK.md) |
| `atmBoundaryLayerInletVelocity` | derived/atmospheric | [derived/atmospheric/atmBoundaryLayerInletVelocity.md](derived/atmospheric/atmBoundaryLayerInletVelocity.md) |
| `basicSymmetry` | basic | [basic/basicSymmetry.md](basic/basicSymmetry.md) |
| `calculated` | basic | [basic/calculated.md](basic/calculated.md) |
| `cloudVelocityLagrangianPatch` / `cloudVelocity` | derived/lagrangian | [derived/lagrangian/cloudVelocityLagrangianPatch.md](derived/lagrangian/cloudVelocityLagrangianPatch.md) |
| `codedFixedValue` | derived/coded | [derived/coded/codedFixedValue.md](derived/coded/codedFixedValue.md) |
| `codedMixed` | derived/coded | [derived/coded/codedMixed.md](derived/coded/codedMixed.md) |
| `contactAngle` | derived/vof-multiphase | [derived/vof-multiphase/contactAngle.md](derived/vof-multiphase/contactAngle.md) |
| `convectiveHeatTransfer` | derived/thermal | [derived/thermal/convectiveHeatTransfer.md](derived/thermal/convectiveHeatTransfer.md) |
| `coupled` | basic | [basic/coupled.md](basic/coupled.md) |
| `coupledTemperature` | derived/thermal | [derived/thermal/coupledTemperature.md](derived/thermal/coupledTemperature.md) |
| `cyclic` | constraint | [constraint/cyclic.md](constraint/cyclic.md) |
| `cyclicLagrangianPatch` | derived/lagrangian | [derived/lagrangian/cyclicLagrangianPatch.md](derived/lagrangian/cyclicLagrangianPatch.md) |
| `cyclicSlip` | constraint | [constraint/cyclicSlip.md](constraint/cyclicSlip.md) |
| `directionMixed` | basic | [basic/directionMixed.md](basic/directionMixed.md) |
| `distributionSizeGroup` | derived/multiphaseEuler | [derived/multiphaseEuler/distributionSizeGroup.md](derived/multiphaseEuler/distributionSizeGroup.md) |
| `dynamicPressure` | derived/pressure | [derived/pressure/dynamicPressure.md](derived/pressure/dynamicPressure.md) |
| `empty` | constraint | [constraint/empty.md](constraint/empty.md) |
| `emptyLagrangianPatch` | derived/lagrangian | [derived/lagrangian/emptyLagrangianPatch.md](derived/lagrangian/emptyLagrangianPatch.md) |
| `energyJump` | derived/thermophysical-energy | [derived/thermophysical-energy/energyJump.md](derived/thermophysical-energy/energyJump.md) |
| `entrainmentPressure` | derived/pressure | [derived/pressure/entrainmentPressure.md](derived/pressure/entrainmentPressure.md) |
| `epsilonmWallFunction` | derived/wall-functions | [derived/wall-functions/epsilonmWallFunction.md](derived/wall-functions/epsilonmWallFunction.md) |
| `epsilonWallFunction` | derived/wall-functions | [derived/wall-functions/epsilonWallFunction.md](derived/wall-functions/epsilonWallFunction.md) |
| `externalCoupledMixed` / `externalCoupled` | derived/mapped | [derived/mapped/externalCoupledMixed.md](derived/mapped/externalCoupledMixed.md) |
| `externalCoupledTemperatureMixed` / `externalCoupledTemperature` | derived/mapped | [derived/mapped/externalCoupledTemperatureMixed.md](derived/mapped/externalCoupledTemperatureMixed.md) |
| `externalTemperature` | derived/thermal | [derived/thermal/externalTemperature.md](derived/thermal/externalTemperature.md) |
| `extrapolatedCalculated` | basic | [basic/extrapolatedCalculated.md](basic/extrapolatedCalculated.md) |
| `fanPressure` | derived/pressure | [derived/pressure/fanPressure.md](derived/pressure/fanPressure.md) |
| `fanPressureJump` | derived/pressure | [derived/pressure/fanPressureJump.md](derived/pressure/fanPressureJump.md) |
| `filmContactAngle` | derived/film | [derived/film/filmContactAngle.md](derived/film/filmContactAngle.md) |
| `filmSurfaceFvPatch` | derived/film | [derived/film/filmSurfaceFvPatch.md](derived/film/filmSurfaceFvPatch.md) |
| `filmSurfacePointPatch` | derived/film | [derived/film/filmSurfacePointPatch.md](derived/film/filmSurfacePointPatch.md) |
| `filmSurfacePolyPatch` / `filmSurface` | derived/film | [derived/film/filmSurfacePolyPatch.md](derived/film/filmSurfacePolyPatch.md) |
| `filmSurfaceVelocity` | derived/film | [derived/film/filmSurfaceVelocity.md](derived/film/filmSurfaceVelocity.md) |
| `filmWallFvPatch` | derived/film | [derived/film/filmWallFvPatch.md](derived/film/filmWallFvPatch.md) |
| `filmWallPointPatch` | derived/film | [derived/film/filmWallPointPatch.md](derived/film/filmWallPointPatch.md) |
| `filmWallPolyPatch` / `filmWall` | derived/film | [derived/film/filmWallPolyPatch.md](derived/film/filmWallPolyPatch.md) |
| `fixedEnergy` | derived/thermophysical-energy | [derived/thermophysical-energy/fixedEnergy.md](derived/thermophysical-energy/fixedEnergy.md) |
| `fixedFluxExtrapolatedPressure` | derived/pressure | [derived/pressure/fixedFluxExtrapolatedPressure.md](derived/pressure/fixedFluxExtrapolatedPressure.md) |
| `fixedFluxPressure` | derived/pressure | [derived/pressure/fixedFluxPressure.md](derived/pressure/fixedFluxPressure.md) |
| `fixedGradient` | basic | [basic/fixedGradient.md](basic/fixedGradient.md) |
| `fixedInternalValue` | derived/general | [derived/general/fixedInternalValue.md](derived/general/fixedInternalValue.md) |
| `fixedJump` | derived/general | [derived/general/fixedJump.md](derived/general/fixedJump.md) |
| `fixedMean` | derived/general | [derived/general/fixedMean.md](derived/general/fixedMean.md) |
| `fixedMeanOutletInlet` | derived/inlet-outlet | [derived/inlet-outlet/fixedMeanOutletInlet.md](derived/inlet-outlet/fixedMeanOutletInlet.md) |
| `fixedNormalInletOutletVelocity` | derived/velocity | [derived/velocity/fixedNormalInletOutletVelocity.md](derived/velocity/fixedNormalInletOutletVelocity.md) |
| `fixedNormalSlip` | derived/velocity | [derived/velocity/fixedNormalSlip.md](derived/velocity/fixedNormalSlip.md) |
| `fixedPressureCompressibleDensity` | derived/pressure | [derived/pressure/fixedPressureCompressibleDensity.md](derived/pressure/fixedPressureCompressibleDensity.md) |
| `fixedProfile` | derived/general | [derived/general/fixedProfile.md](derived/general/fixedProfile.md) |
| `fixedRho` | derived/shockFluid | [derived/shockFluid/fixedRho.md](derived/shockFluid/fixedRho.md) |
| `fixedShearStress` | derived/wall-functions | [derived/wall-functions/fixedShearStress.md](derived/wall-functions/fixedShearStress.md) |
| `fixedUnburntEnthalpy` | derived/thermophysical-energy | [derived/thermophysical-energy/fixedUnburntEnthalpy.md](derived/thermophysical-energy/fixedUnburntEnthalpy.md) |
| `fixedValue` | basic | [basic/fixedValue.md](basic/fixedValue.md) |
| `fixedValueInletOutlet` | derived/inlet-outlet | [derived/inlet-outlet/fixedValueInletOutlet.md](derived/inlet-outlet/fixedValueInletOutlet.md) |
| `flowRateInletVelocity` | derived/velocity | [derived/velocity/flowRateInletVelocity.md](derived/velocity/flowRateInletVelocity.md) |
| `flowRateOutletVelocity` | derived/velocity | [derived/velocity/flowRateOutletVelocity.md](derived/velocity/flowRateOutletVelocity.md) |
| `fluxCorrectedVelocity` | derived/velocity | [derived/velocity/fluxCorrectedVelocity.md](derived/velocity/fluxCorrectedVelocity.md) |
| `freestream` | derived/velocity | [derived/velocity/freestream.md](derived/velocity/freestream.md) |
| `freestreamPressure` | derived/pressure | [derived/pressure/freestreamPressure.md](derived/pressure/freestreamPressure.md) |
| `freestreamVelocity` | derived/velocity | [derived/velocity/freestreamVelocity.md](derived/velocity/freestreamVelocity.md) |
| `fWallFunction` | derived/wall-functions | [derived/wall-functions/fWallFunction.md](derived/wall-functions/fWallFunction.md) |
| `gradientEnergy` / `gradientEnergyCalculatedTemperature` | derived/thermophysical-energy | [derived/thermophysical-energy/gradientEnergy.md](derived/thermophysical-energy/gradientEnergy.md) |
| `gradientUnburntEnthalpy` | derived/thermophysical-energy | [derived/thermophysical-energy/gradientUnburntEnthalpy.md](derived/thermophysical-energy/gradientUnburntEnthalpy.md) |
| `greyDiffusiveRadiationMixed` / `greyDiffusiveRadiation` | derived/radiation | [derived/radiation/greyDiffusiveRadiationMixed.md](derived/radiation/greyDiffusiveRadiationMixed.md) |
| `greyDiffusiveViewFactorFixedValue` / `greyDiffusiveRadiationViewFactor` | derived/radiation | [derived/radiation/greyDiffusiveViewFactorFixedValue.md](derived/radiation/greyDiffusiveViewFactorFixedValue.md) |
| `hydrostaticDisplacement` | derived/solid-displacement | [derived/solid-displacement/hydrostaticDisplacement.md](derived/solid-displacement/hydrostaticDisplacement.md) |
| `inletOutlet` | derived/inlet-outlet | [derived/inlet-outlet/inletOutlet.md](derived/inlet-outlet/inletOutlet.md) |
| `inletOutletTotalTemperature` | derived/thermal | [derived/thermal/inletOutletTotalTemperature.md](derived/thermal/inletOutletTotalTemperature.md) |
| `interfaceCompression` | derived/vof-multiphase | [derived/vof-multiphase/interfaceCompression.md](derived/vof-multiphase/interfaceCompression.md) |
| `internal` | constraint | [constraint/internal.md](constraint/internal.md) |
| `internalLagrangianPatch` | derived/lagrangian | [derived/lagrangian/internalLagrangianPatch.md](derived/lagrangian/internalLagrangianPatch.md) |
| `interstitialInletVelocity` | derived/vof-multiphase | [derived/vof-multiphase/interstitialInletVelocity.md](derived/vof-multiphase/interstitialInletVelocity.md) |
| `JohnsonJacksonParticleSlip` | derived/multiphaseEuler | [derived/multiphaseEuler/JohnsonJacksonParticleSlip.md](derived/multiphaseEuler/JohnsonJacksonParticleSlip.md) |
| `JohnsonJacksonParticleTheta` | derived/multiphaseEuler | [derived/multiphaseEuler/JohnsonJacksonParticleTheta.md](derived/multiphaseEuler/JohnsonJacksonParticleTheta.md) |
| `jumpCyclic` | constraint | [constraint/jumpCyclic.md](constraint/jumpCyclic.md) |
| `kLowReWallFunction` | derived/wall-functions | [derived/wall-functions/kLowReWallFunction.md](derived/wall-functions/kLowReWallFunction.md) |
| `kqRWallFunction` | derived/wall-functions | [derived/wall-functions/kqRWallFunction.md](derived/wall-functions/kqRWallFunction.md) |
| `LagrangianPatch` | derived/lagrangian | [derived/lagrangian/LagrangianPatch.md](derived/lagrangian/LagrangianPatch.md) |
| `lumpedMassTemperature` | derived/thermal | [derived/thermal/lumpedMassTemperature.md](derived/thermal/lumpedMassTemperature.md) |
| `mappedFilmPressure` | derived/film | [derived/film/mappedFilmPressure.md](derived/film/mappedFilmPressure.md) |
| `mappedFilmSurfaceFvPatch` | derived/film | [derived/film/mappedFilmSurfaceFvPatch.md](derived/film/mappedFilmSurfaceFvPatch.md) |
| `mappedFilmSurfacePointPatch` | derived/film | [derived/film/mappedFilmSurfacePointPatch.md](derived/film/mappedFilmSurfacePointPatch.md) |
| `mappedFilmSurfacePolyPatch` / `mappedFilmSurface` | derived/film | [derived/film/mappedFilmSurfacePolyPatch.md](derived/film/mappedFilmSurfacePolyPatch.md) |
| `mappedFilmWallFvPatch` | derived/film | [derived/film/mappedFilmWallFvPatch.md](derived/film/mappedFilmWallFvPatch.md) |
| `mappedFilmWallPointPatch` | derived/film | [derived/film/mappedFilmWallPointPatch.md](derived/film/mappedFilmWallPointPatch.md) |
| `mappedFilmWallPolyPatch` / `mappedFilmWall` | derived/film | [derived/film/mappedFilmWallPolyPatch.md](derived/film/mappedFilmWallPolyPatch.md) |
| `mappedFlowRateVelocity` | derived/mapped | [derived/mapped/mappedFlowRateVelocity.md](derived/mapped/mappedFlowRateVelocity.md) |
| `mappedInternalValue` | derived/mapped | [derived/mapped/mappedInternalValue.md](derived/mapped/mappedInternalValue.md) |
| `mappedValue` | derived/mapped | [derived/mapped/mappedValue.md](derived/mapped/mappedValue.md) |
| `mappedVelocityFlux` | derived/mapped | [derived/mapped/mappedVelocityFlux.md](derived/mapped/mappedVelocityFlux.md) |
| `MarshakRadiation` | derived/radiation | [derived/radiation/MarshakRadiation.md](derived/radiation/MarshakRadiation.md) |
| `MarshakRadiationFixedTemperature` | derived/radiation | [derived/radiation/MarshakRadiationFixedTemperature.md](derived/radiation/MarshakRadiationFixedTemperature.md) |
| `matchedFlowRateOutletVelocity` | derived/velocity | [derived/velocity/matchedFlowRateOutletVelocity.md](derived/velocity/matchedFlowRateOutletVelocity.md) |
| `maxwellSlipU` | derived/shockFluid | [derived/shockFluid/maxwellSlipU.md](derived/shockFluid/maxwellSlipU.md) |
| `mixed` | basic | [basic/mixed.md](basic/mixed.md) |
| `mixedEnergy` / `mixedEnergyCalculatedTemperature` | derived/thermophysical-energy | [derived/thermophysical-energy/mixedEnergy.md](derived/thermophysical-energy/mixedEnergy.md) |
| `mixedFixedValueSlip` | derived/shockFluid | [derived/shockFluid/mixedFixedValueSlip.md](derived/shockFluid/mixedFixedValueSlip.md) |
| `mixedUnburntEnthalpy` | derived/thermophysical-energy | [derived/thermophysical-energy/mixedUnburntEnthalpy.md](derived/thermophysical-energy/mixedUnburntEnthalpy.md) |
| `movingMappedWallVelocity` | derived/velocity | [derived/velocity/movingMappedWallVelocity.md](derived/velocity/movingMappedWallVelocity.md) |
| `movingWallSlipVelocity` | derived/velocity | [derived/velocity/movingWallSlipVelocity.md](derived/velocity/movingWallSlipVelocity.md) |
| `movingWallVelocity` | derived/velocity | [derived/velocity/movingWallVelocity.md](derived/velocity/movingWallVelocity.md) |
| `multiphaseCoupledTemperature` | derived/multiphaseEuler | [derived/multiphaseEuler/multiphaseCoupledTemperature.md](derived/multiphaseEuler/multiphaseCoupledTemperature.md) |
| `multiphaseExternalTemperature` | derived/multiphaseEuler | [derived/multiphaseEuler/multiphaseExternalTemperature.md](derived/multiphaseEuler/multiphaseExternalTemperature.md) |
| `nonConformalCyclic` | constraint | [constraint/nonConformalCyclic.md](constraint/nonConformalCyclic.md) |
| `nonConformalCyclicLagrangianPatch` | derived/lagrangian | [derived/lagrangian/nonConformalCyclicLagrangianPatch.md](derived/lagrangian/nonConformalCyclicLagrangianPatch.md) |
| `nonConformalError` | constraint | [constraint/nonConformalError.md](constraint/nonConformalError.md) |
| `nonConformalErrorLagrangianPatch` | derived/lagrangian | [derived/lagrangian/nonConformalErrorLagrangianPatch.md](derived/lagrangian/nonConformalErrorLagrangianPatch.md) |
| `nonConformalProcessorCyclic` | constraint | [constraint/nonConformalProcessorCyclic.md](constraint/nonConformalProcessorCyclic.md) |
| `nonConformalProcessorCyclicLagrangianPatch` | derived/lagrangian | [derived/lagrangian/nonConformalProcessorCyclicLagrangianPatch.md](derived/lagrangian/nonConformalProcessorCyclicLagrangianPatch.md) |
| `noSlip` | derived/velocity | [derived/velocity/noSlip.md](derived/velocity/noSlip.md) |
| `nutkAtmRoughWallFunction` | derived/atmospheric | [derived/atmospheric/nutkAtmRoughWallFunction.md](derived/atmospheric/nutkAtmRoughWallFunction.md) |
| `nutkRoughWallFunction` | derived/wall-functions | [derived/wall-functions/nutkRoughWallFunction.md](derived/wall-functions/nutkRoughWallFunction.md) |
| `nutkWallFunction` | derived/wall-functions | [derived/wall-functions/nutkWallFunction.md](derived/wall-functions/nutkWallFunction.md) |
| `nutLowReWallFunction` | derived/wall-functions | [derived/wall-functions/nutLowReWallFunction.md](derived/wall-functions/nutLowReWallFunction.md) |
| `nutURoughWallFunction` | derived/wall-functions | [derived/wall-functions/nutURoughWallFunction.md](derived/wall-functions/nutURoughWallFunction.md) |
| `nutUSpaldingWallFunction` | derived/wall-functions | [derived/wall-functions/nutUSpaldingWallFunction.md](derived/wall-functions/nutUSpaldingWallFunction.md) |
| `nutUWallFunction` | derived/wall-functions | [derived/wall-functions/nutUWallFunction.md](derived/wall-functions/nutUWallFunction.md) |
| `omegaWallFunction` | derived/wall-functions | [derived/wall-functions/omegaWallFunction.md](derived/wall-functions/omegaWallFunction.md) |
| `outletInlet` | derived/inlet-outlet | [derived/inlet-outlet/outletInlet.md](derived/inlet-outlet/outletInlet.md) |
| `outletMappedUniformInlet` | derived/mapped | [derived/mapped/outletMappedUniformInlet.md](derived/mapped/outletMappedUniformInlet.md) |
| `outletPhaseMeanVelocity` | derived/vof-multiphase | [derived/vof-multiphase/outletPhaseMeanVelocity.md](derived/vof-multiphase/outletPhaseMeanVelocity.md) |
| `partialSlip` | derived/velocity | [derived/velocity/partialSlip.md](derived/velocity/partialSlip.md) |
| `phaseHydrostaticPressure` | derived/vof-multiphase | [derived/vof-multiphase/phaseHydrostaticPressure.md](derived/vof-multiphase/phaseHydrostaticPressure.md) |
| `plenumPressure` | derived/pressure | [derived/pressure/plenumPressure.md](derived/pressure/plenumPressure.md) |
| `porousBafflePressure` | derived/wall-functions | [derived/wall-functions/porousBafflePressure.md](derived/wall-functions/porousBafflePressure.md) |
| `pressure` | derived/pressure | [derived/pressure/pressure.md](derived/pressure/pressure.md) |
| `pressureDirectedInletOutletVelocity` | derived/pressure | [derived/pressure/pressureDirectedInletOutletVelocity.md](derived/pressure/pressureDirectedInletOutletVelocity.md) |
| `pressureDirectedInletVelocity` | derived/pressure | [derived/pressure/pressureDirectedInletVelocity.md](derived/pressure/pressureDirectedInletVelocity.md) |
| `pressureInletOutletParSlipVelocity` | derived/pressure | [derived/pressure/pressureInletOutletParSlipVelocity.md](derived/pressure/pressureInletOutletParSlipVelocity.md) |
| `pressureInletOutletVelocity` | derived/pressure | [derived/pressure/pressureInletOutletVelocity.md](derived/pressure/pressureInletOutletVelocity.md) |
| `pressureInletUniformVelocity` | derived/pressure | [derived/pressure/pressureInletUniformVelocity.md](derived/pressure/pressureInletUniformVelocity.md) |
| `pressureInletVelocity` | derived/pressure | [derived/pressure/pressureInletVelocity.md](derived/pressure/pressureInletVelocity.md) |
| `pressureNormalInletOutletVelocity` | derived/pressure | [derived/pressure/pressureNormalInletOutletVelocity.md](derived/pressure/pressureNormalInletOutletVelocity.md) |
| `prghCyclicPressure` | derived/pressure | [derived/pressure/prghCyclicPressure.md](derived/pressure/prghCyclicPressure.md) |
| `PrghPressure` | derived/pressure | [derived/pressure/PrghPressure.md](derived/pressure/PrghPressure.md) |
| `prghTotalHydrostaticPressure` | derived/pressure | [derived/pressure/prghTotalHydrostaticPressure.md](derived/pressure/prghTotalHydrostaticPressure.md) |
| `processor` | constraint | [constraint/processor.md](constraint/processor.md) |
| `processorCyclic` | constraint | [constraint/processorCyclic.md](constraint/processorCyclic.md) |
| `processorCyclicLagrangianPatch` | derived/lagrangian | [derived/lagrangian/processorCyclicLagrangianPatch.md](derived/lagrangian/processorCyclicLagrangianPatch.md) |
| `processorLagrangianPatch` | derived/lagrangian | [derived/lagrangian/processorLagrangianPatch.md](derived/lagrangian/processorLagrangianPatch.md) |
| `rotatingPressureInletOutletVelocity` | derived/pressure | [derived/pressure/rotatingPressureInletOutletVelocity.md](derived/pressure/rotatingPressureInletOutletVelocity.md) |
| `rotatingTotalPressure` | derived/pressure | [derived/pressure/rotatingTotalPressure.md](derived/pressure/rotatingTotalPressure.md) |
| `rotatingWallVelocity` | derived/velocity | [derived/velocity/rotatingWallVelocity.md](derived/velocity/rotatingWallVelocity.md) |
| `singleSizeGroup` | derived/multiphaseEuler | [derived/multiphaseEuler/singleSizeGroup.md](derived/multiphaseEuler/singleSizeGroup.md) |
| `sliced` | basic | [basic/sliced.md](basic/sliced.md) |
| `slip` | derived/velocity | [derived/velocity/slip.md](derived/velocity/slip.md) |
| `smoluchowskiJumpT` | derived/shockFluid | [derived/shockFluid/smoluchowskiJumpT.md](derived/shockFluid/smoluchowskiJumpT.md) |
| `supersonicFreestream` | derived/velocity | [derived/velocity/supersonicFreestream.md](derived/velocity/supersonicFreestream.md) |
| `surfaceNormalFixedValue` | derived/velocity | [derived/velocity/surfaceNormalFixedValue.md](derived/velocity/surfaceNormalFixedValue.md) |
| `surfaceNormalUniformFixedValue` | derived/velocity | [derived/velocity/surfaceNormalUniformFixedValue.md](derived/velocity/surfaceNormalUniformFixedValue.md) |
| `swirlFlowRateInletVelocity` | derived/velocity | [derived/velocity/swirlFlowRateInletVelocity.md](derived/velocity/swirlFlowRateInletVelocity.md) |
| `swirlInletVelocity` | derived/velocity | [derived/velocity/swirlInletVelocity.md](derived/velocity/swirlInletVelocity.md) |
| `symmetry` | constraint | [constraint/symmetry.md](constraint/symmetry.md) |
| `symmetryLagrangianPatch` | derived/lagrangian | [derived/lagrangian/symmetryLagrangianPatch.md](derived/lagrangian/symmetryLagrangianPatch.md) |
| `symmetryPlane` | constraint | [constraint/symmetryPlane.md](constraint/symmetryPlane.md) |
| `symmetryPlaneLagrangianPatch` | derived/lagrangian | [derived/lagrangian/symmetryPlaneLagrangianPatch.md](derived/lagrangian/symmetryPlaneLagrangianPatch.md) |
| `syringePressure` | derived/pressure | [derived/pressure/syringePressure.md](derived/pressure/syringePressure.md) |
| `timeVaryingMappedFixedValue` | derived/mapped | [derived/mapped/timeVaryingMappedFixedValue.md](derived/mapped/timeVaryingMappedFixedValue.md) |
| `totalFlowRateAdvectiveDiffusive` | derived/thermophysical-energy | [derived/thermophysical-energy/totalFlowRateAdvectiveDiffusive.md](derived/thermophysical-energy/totalFlowRateAdvectiveDiffusive.md) |
| `totalPressure` | derived/pressure | [derived/pressure/totalPressure.md](derived/pressure/totalPressure.md) |
| `totalTemperature` | derived/thermal | [derived/thermal/totalTemperature.md](derived/thermal/totalTemperature.md) |
| `tractionDisplacement` | derived/solid-displacement | [derived/solid-displacement/tractionDisplacement.md](derived/solid-displacement/tractionDisplacement.md) |
| `transform` | basic | [basic/transform.md](basic/transform.md) |
| `translatingWallVelocity` | derived/velocity | [derived/velocity/translatingWallVelocity.md](derived/velocity/translatingWallVelocity.md) |
| `transonicEntrainmentPressure` | derived/pressure | [derived/pressure/transonicEntrainmentPressure.md](derived/pressure/transonicEntrainmentPressure.md) |
| `turbulentInlet` | derived/turbulence-inlets | [derived/turbulence-inlets/turbulentInlet.md](derived/turbulence-inlets/turbulentInlet.md) |
| `turbulentIntensityKineticEnergyInlet` | derived/turbulence-inlets | [derived/turbulence-inlets/turbulentIntensityKineticEnergyInlet.md](derived/turbulence-inlets/turbulentIntensityKineticEnergyInlet.md) |
| `turbulentMixingLengthDissipationRateInlet` | derived/turbulence-inlets | [derived/turbulence-inlets/turbulentMixingLengthDissipationRateInlet.md](derived/turbulence-inlets/turbulentMixingLengthDissipationRateInlet.md) |
| `turbulentMixingLengthFrequencyInlet` | derived/turbulence-inlets | [derived/turbulence-inlets/turbulentMixingLengthFrequencyInlet.md](derived/turbulence-inlets/turbulentMixingLengthFrequencyInlet.md) |
| `uniformDensityHydrostaticPressure` | derived/pressure | [derived/pressure/uniformDensityHydrostaticPressure.md](derived/pressure/uniformDensityHydrostaticPressure.md) |
| `uniformFixedGradient` | derived/general | [derived/general/uniformFixedGradient.md](derived/general/uniformFixedGradient.md) |
| `uniformFixedValue` | derived/general | [derived/general/uniformFixedValue.md](derived/general/uniformFixedValue.md) |
| `uniformInletOutlet` | derived/inlet-outlet | [derived/inlet-outlet/uniformInletOutlet.md](derived/inlet-outlet/uniformInletOutlet.md) |
| `uniformJump` | derived/general | [derived/general/uniformJump.md](derived/general/uniformJump.md) |
| `uniformTotalPressure` | derived/pressure | [derived/pressure/uniformTotalPressure.md](derived/pressure/uniformTotalPressure.md) |
| `v2WallFunction` | derived/wall-functions | [derived/wall-functions/v2WallFunction.md](derived/wall-functions/v2WallFunction.md) |
| `variableHeightFlowRate` | derived/vof-multiphase | [derived/vof-multiphase/variableHeightFlowRate.md](derived/vof-multiphase/variableHeightFlowRate.md) |
| `variableHeightFlowRateInletVelocity` | derived/vof-multiphase | [derived/vof-multiphase/variableHeightFlowRateInletVelocity.md](derived/vof-multiphase/variableHeightFlowRateInletVelocity.md) |
| `wallBoilingPhaseChangeRate` | derived/multiphaseEuler | [derived/multiphaseEuler/wallBoilingPhaseChangeRate.md](derived/multiphaseEuler/wallBoilingPhaseChangeRate.md) |
| `wallLagrangianPatch` | derived/lagrangian | [derived/lagrangian/wallLagrangianPatch.md](derived/lagrangian/wallLagrangianPatch.md) |
| `waveAlpha` | derived/waves | [derived/waves/waveAlpha.md](derived/waves/waveAlpha.md) |
| `waveInletOutlet` | derived/waves | [derived/waves/waveInletOutlet.md](derived/waves/waveInletOutlet.md) |
| `waveSurfacePressure` | derived/waves | [derived/waves/waveSurfacePressure.md](derived/waves/waveSurfacePressure.md) |
| `waveTransmissive` | derived/inlet-outlet | [derived/inlet-outlet/waveTransmissive.md](derived/inlet-outlet/waveTransmissive.md) |
| `waveVelocity` | derived/waves | [derived/waves/waveVelocity.md](derived/waves/waveVelocity.md) |
| `wedge` | constraint | [constraint/wedge.md](constraint/wedge.md) |
| `wedgeLagrangianPatch` | derived/lagrangian | [derived/lagrangian/wedgeLagrangianPatch.md](derived/lagrangian/wedgeLagrangianPatch.md) |
| `wideBandDiffusiveRadiationMixed` / `wideBandDiffusiveRadiation` | derived/radiation | [derived/radiation/wideBandDiffusiveRadiationMixed.md](derived/radiation/wideBandDiffusiveRadiationMixed.md) |
| `zeroFixedValue` | derived/general | [derived/general/zeroFixedValue.md](derived/general/zeroFixedValue.md) |
| `zeroGradient` | basic | [basic/zeroGradient.md](basic/zeroGradient.md) |
| `zeroInletOutlet` | derived/inlet-outlet | [derived/inlet-outlet/zeroInletOutlet.md](derived/inlet-outlet/zeroInletOutlet.md) |

## 覆盖与缺口

见 [`GAPS`.md`](GAPS.md)（教程未命中、非 `fvPatchField`、缺 Description 等）。

## 导航

- 全量机器清单：[`../_inventory/rts-fvPatchFields.md`](../_inventory/rts-fvPatchFields.md)
- 约定与模板：[`../00-conventions.md`](../00-conventions.md)
- 求解器矩阵：[`../01-solver-matrix.md`](../01-solver-matrix.md)
- 手册首页：[`../README.md`](../README.md)
