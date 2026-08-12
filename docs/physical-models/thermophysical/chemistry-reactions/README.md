# 化学、饱和与火焰速度（Phase 1 概览）

完整燃烧/反应速率全谱见 Phase 4。此处覆盖 inventory 中热物性包内条目，并补齐求解器/降维短页。

## 总览与反应

- [`chemistry`-overview`](chemistry-overview.md)（求解 / 降维 / 表化 / 反应树）
- [`reaction`（概览）](reaction.md)

## 化学求解器

- [`ode`](chemistrySolver-ode.md)
- [`EulerImplicit`](chemistrySolver-EulerImplicit.md)
- [`none`](chemistrySolver-none.md)

## 机理降维

- [`DRG`](reduction-DRG.md)
- [`DAC`](reduction-DAC.md)
- [`DRGEP`](reduction-DRGEP.md)
- [`PFA`](reduction-PFA.md)
- [`EFA`](reduction-EFA.md)
- [`none`](reduction-none.md)

## 表化

- [`ISAT`](ISAT.md)
- [`noChemistryTabulation`](noChemistryTabulation.md)（`method` none`）

## 层流火焰速度

- [`Gulder`](Gulder.md)
- [`RaviPetersen`](RaviPetersen.md)
- [`constant`](constantLaminarFlameSpeed.md)

## 饱和模型

- [`Antoine`](Antoine.md)
- [`AntoineExtended`](AntoineExtended.md)
- [`ArdenBuck`](ArdenBuck.md)
- [`constantPressure`](constantPressure.md)
- [`constantTemperature`](constantTemperature.md)
- [`function1Temperature`](function1Temperature.md)
- [`polynomialTemperature`](polynomialTemperature.md)

## functionObjects

- [`adjustTimeStepToChemistry`](functionObject-adjustTimeStepToChemistry.md)
- [`reactionRates`](functionObject-reactionRates.md)
- [`specieReactionRates`](functionObject-specieReactionRates.md)
- [`massFractions`](functionObject-massFractions.md)
- [`moleFractions`](functionObject-moleFractions.md)

导航：[`../README.md`](../README.md)
