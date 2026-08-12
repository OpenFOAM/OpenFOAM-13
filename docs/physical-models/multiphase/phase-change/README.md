# 相变 / 凝固熔化 / 沸腾

跨求解器的相变相关 fvModels，以及 `multiphaseEuler` 模块内沸腾、空化、凝结等。

## 通用（`src/fvModels`）

| 类型 | 说明 |
|------|------|
| [coefficientPhaseChange](coefficientPhaseChange.md) | 系数型相变 |
| [solidificationMelting](solidificationMelting.md) | 通用凝固熔化（非 VoF 专用） |
| [coefficientMassTransfer](coefficientMassTransfer.md) | 系数型传质 |

VoF 专用凝固见 [../vof/fvModels/VoFSolidificationMelting.md](../vof/fvModels/VoFSolidificationMelting.md)（**仅 compressibleVoF**）。

## multiphaseEuler 模块

| 类型 | 说明 |
|------|------|
| [wallBoiling](wallBoiling.md) | 壁面沸腾 |
| [phaseSurfaceBoiling](phaseSurfaceBoiling.md) | 相表面沸腾 |
| [heatTransferLimitedPhaseChange](heatTransferLimitedPhaseChange.md) | 传热限制相变 |
| [massDiffusionLimitedPhaseChange](massDiffusionLimitedPhaseChange.md) | 传质扩散限制相变 |
| [reactionDrivenPhaseChange](reactionDrivenPhaseChange.md) | 反应驱动相变 |
| [homogeneousCondensation](homogeneousCondensation.md) | 均相凝结 |
| [homogeneousLiquidPhaseSeparation](homogeneousLiquidPhaseSeparation.md) | 均相液相分离 |
| [multiphaseEulerCavitation](multiphaseEulerCavitation.md) | Euler 空化（可压空化库） |
| [interfaceTurbulenceDamping](interfaceTurbulenceDamping.md) | 界面湍流阻尼 |
| [phaseTurbulenceStabilisation](phaseTurbulenceStabilisation.md) | 相湍流稳定 |
| [KochFriedlanderSintering](KochFriedlanderSintering.md) | 烧结（群体平衡） |

子模型：[wallBoiling-submodels/](wallBoiling-submodels/)（分区 / 成核点 / 脱离直径与频率）。

## 与 VoF 空化的关系

| 路径 | 求解器 |
|------|--------|
| [../vof/fvModels/](../vof/fvModels/) `VoFCavitation` | incompressibleVoF / compressibleVoF |
| `multiphaseEulerCavitation` | multiphaseEuler |

## 导航

- [多相索引](../README.md) · [覆盖报告](../_coverage.md) · [fvModels 总清单](../../_inventory/rts-fvModels.md)
