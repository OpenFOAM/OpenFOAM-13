# Lagrangian

Phase **4** 正文：parcel 云（`cloudProperties`）、新 `Lagrangian` 框架、MPPIC、云 fvModel，以及**薄膜区域耦合**（本手册将 film 索引放于此）。

## 本目录结构

| 文档 | 内容 |
|------|------|
| [cloudProperties-patterns.md](cloudProperties-patterns.md) | `type`、solution、constantProperties、subModels 总模式 |
| [cloud-fvModels.md](cloud-fvModels.md) | `fvModels` → `type` clouds` 激活 |
| [parcel-injection.md](parcel-injection.md) | InjectionModel 全谱 |
| [parcel-patch-interaction.md](parcel-patch-interaction.md) | PatchInteraction |
| [parcel-dispersion.md](parcel-dispersion.md) | Dispersion |
| [parcel-forces.md](parcel-forces.md) | ParticleForces |
| [parcel-breakup-atomisation.md](parcel-breakup-atomisation.md) | Breakup / Atomisation（喷雾） |
| [parcel-phase-change.md](parcel-phase-change.md) | PhaseChange |
| [parcel-surface-reaction.md](parcel-surface-reaction.md) | SurfaceReaction / Devolatilisation |
| [parcel-heat-transfer-composition.md](parcel-heat-transfer-composition.md) | HeatTransfer / Composition |
| [parcel-collision-cloudFunctions.md](parcel-collision-cloudFunctions.md) | Collision / StochasticCollision / SurfaceFilm / cloudFunctions |
| [mppic.md](mppic.md) | MPPIC：packing / damping / isotropy / stress |
| [new-Lagrangian-framework.md](new-Lagrangian-framework.md) | `src/Lagrangian` 云、Patch、系统 FO、MD 索引 |
| [film.md](film.md) | **薄膜**：isothermalFilm/film、filmCloudTransfer、filmVoFTransfer、mapped patches |

## 求解器入口

| 求解器 | Lagrangian |
|--------|------------|
| [incompressibleDenseParticleFluid](../solvers/incompressibleDenseParticleFluid.md) | **内建** `-llagrangian` `-llagrangianParcel`（体积分数反作用） |
| [multicomponentFluid](../solvers/multicomponentFluid.md) / [fluid](../solvers/fluid.md) / 多数单相 | **可选**：`fvModels` + `clouds` |
| [isothermalFilm](../solvers/isothermalFilm.md) / [film](../solvers/film.md) | 区域求解器；与云/VoF 经 fvModel 耦合 |

## 两套框架对照

| | 经典 parcel | 新 Lagrangian |
|--|-------------|---------------|
| 源码 | `src/lagrangian` / `src/Lagrangian/parcel`（镜像） | `src/Lagrangian/cloud` 等 |
| 配置 | `constant/cloudProperties` | 云类型 + `LagrangianModels` |
| 激活 | `fvModels`:`clouds` 或稠密颗粒求解器内建 | 见 new-Lagrangian 页 |
| Inventory | 子模型多由 `make`*Parcel*` 宏注册，**未全部出现在 RTS 清单** | RTS 清单较全 |

清单：[`../_inventory/rts-lagrangian-submodels.md`](../_inventory/rts-lagrangian-submodels.md)（**164** 行 / 去重非 directory **83** 唯一类型；含 `src/lagrangian` 与 `src/Lagrangian` 重复及 MD 势函数等）。

### Phase 4 覆盖摘要（对人：catalog 页，非一类型一文件）

| 子集 | 状态 |
|------|------|
| parcel Injection / Forces / Dispersion / PatchInteraction / Breakup / Atomisation / PhaseChange / SurfaceReaction / Devolatilisation / HeatTransfer / Composition | ✓ 专题页 |
| Collision / StochasticCollision / SurfaceFilm / cloudFunctions | ✓ [parcel-collision-cloudFunctions.md](parcel-collision-cloudFunctions.md) |
| MPPIC packing/damping/isotropy/stress | ✓ [mppic.md](mppic.md) |
| 新框架云 + LagrangianModel + Patch + 系统 FO | ✓ [new-Lagrangian-framework.md](new-Lagrangian-framework.md) |
| MD pair/tether/energyScaling | ✓ 类型索引；**不成方程页** |
| film / filmCloudTransfer / filmVoFTransfer / mapped | ✓ [film.md](film.md) |
| `clouds` fvModel | ✓ [cloud-fvModels.md](cloud-fvModels.md) |

**交叉**：`clouds`/`filmCloudTransfer` 包装亦见 [`../fv-models-constraints/`](../fv-models-constraints/)；本目录给 cloudProperties 子模型全谱与薄膜耦合专页。

## 导航

- [`../combustion-radiation/`](../combustion-radiation/) · [`../01-solver-matrix.md`](../01-solver-matrix.md) · [`../README.md`](../README.md)
