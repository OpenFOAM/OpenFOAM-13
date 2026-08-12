# multiphaseEuler

任意数量可压相的 Euler 多相系：相模型、直径、blending、界面力/传热传质、群体平衡。

## 先读

| 文档 | 用途 |
|------|------|
| [phase-models.md](phase-models.md) | `phaseProperties` 中相的 `type`（`purePhaseModel` 等） |

典型字典骨架见 `tutorials/multiphaseEuler/bubbleColumn/constant/phaseProperties`。

## 子目录

| 目录 | 基类 / 内容 |
|------|-------------|
| [blending/](blending/) | `blendingMethod` |
| [diameter/](diameter/) | `diameterModel` / IATE 源 / `shapeModel` |
| [drag/](drag/) | `dragModel` |
| [lift/](lift/) | `liftModel` |
| [virtualMass/](virtualMass/) | `virtualMassModel` |
| [wallLubrication/](wallLubrication/) | `wallLubricationModel` |
| [wallDamping/](wallDamping/) | `wallDampingModel` |
| [turbulentDispersion/](turbulentDispersion/) | `turbulentDispersionModel` |
| [swarmCorrection/](swarmCorrection/) | `swarmCorrection` |
| [heatTransfer/](heatTransfer/) | `heatTransferModel` |
| [diffusiveMassTransfer/](diffusiveMassTransfer/) | `diffusiveMassTransferModel` |
| [interfaceComposition/](interfaceComposition/) | `interfaceCompositionModel` |
| [aspectRatio/](aspectRatio/) | `aspectRatioModel` |
| [surfaceTension/](surfaceTension/) | `surfaceTensionCoefficientModel` |
| [populationBalance/](populationBalance/) | 聚并 / 破碎 / 子粒径分布 |

相变与壁面沸腾等模块 fvModels 见 [../phase-change/](../phase-change/)。

## 相关求解器

- [multiphaseEuler](../../solvers/multiphaseEuler.md)

## 导航

- [多相索引](../README.md) · [RTS 清单](../../_inventory/rts-multiphase-interfacial.md) · [覆盖报告](../_coverage.md)
