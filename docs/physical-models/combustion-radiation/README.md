# 燃烧、化学与辐射

Phase **4** 正文：`combustionProperties`、化学求解/降维/ISAT、反应速率概览、`XiFluid` 子模型树、辐射与吸收/散射/烟黑，以及经 `fvModels` 激活辐射。

## 本目录结构

| 文档 | 内容 |
|------|------|
| [combustion-models.md](combustion-models.md) | `combustionModel`：laminar / EDC / PaSR / FSD / diffusion / infinitelyFastChemistry / zoneCombustion / noCombustion |
| [chemistry-solvers-reduction-isat.md](chemistry-solvers-reduction-isat.md) | `chemistryProperties`：ode / EulerImplicit、降维 DAC·DRG·…、ISAT |
| [reactions-overview.md](reactions-overview.md) | 反应类型与速率形式（Arrhenius、fall-off、表面…） |
| [laminar-flame-speed.md](laminar-flame-speed.md) | `laminarFlameSpeed`：Gulder / RaviPetersen / constant |
| [xi-submodels.md](xi-submodels.md) | XiFluid：Xi / XiEq / XiG / XiProfile / Su / 点火 fvModels |
| [radiation-models.md](radiation-models.md) | `radiationModel`：P1 / fvDOM / viewFactor / opaqueSolid / none |
| [absorption-emission-scatter-soot.md](absorption-emission-scatter-soot.md) | 吸收发射、散射、烟黑（含燃烧专用 greyMeanCombustion 等） |
| [radiation-fvModel.md](radiation-fvModel.md) | **必读**：OpenFOAM-13 经 `fvModels` 的 `type` radiation` 激活 |

## 求解器入口

| 求解器 | 燃烧/化学 | 辐射 |
|--------|-----------|------|
| [multicomponentFluid](../solvers/multicomponentFluid.md) | 可选：`combustionProperties` + `chemistryProperties` | 可选：`radiation` fvModel + `radiationProperties` |
| [XiFluid](../solvers/XiFluid.md) | **内建** b-Xi + `laminarFlameSpeed`；字典结构不同于 EDC 系 | 可选（Description + fvModels） |
| [fluid](../solvers/fluid.md) | 不可用 | 可选辐射 |
| [multiphaseEuler](../solvers/multiphaseEuler.md) | 可选相表面反应库（见 reactions 概览） | 需验证（无官方辐射教程；可经 libs 挂接） |
| [film](../solvers/film.md) / [isothermalFilm](../solvers/isothermalFilm.md) | 不可用 | film 可选；耦合见 [../lagrangian/film.md](../lagrangian/film.md) |

薄膜物理与区域耦合统一放在 **[../lagrangian/film.md](../lagrangian/film.md)**。

## Inventory 对照

机器清单：[`../_inventory/rts-combustion-radiation.md`](../_inventory/rts-combustion-radiation.md)（**163** 行 / 去重非 directory **46** 唯一类型，含 directory 镜像与重复基类）。

### Phase 4 覆盖摘要

| 子集 | 状态 |
|------|------|
| `combustionModel`（laminar/PaSR/EDC/FSD/diffusion/infinitelyFastChemistry/zoneCombustion/noCombustion） | ✓ [combustion-models.md](combustion-models.md) |
| chemistry solvers / reduction / ISAT / FO | ✓ [chemistry-solvers-reduction-isat.md](chemistry-solvers-reduction-isat.md) |
| 反应速率形式概览 | ✓ [reactions-overview.md](reactions-overview.md) |
| `laminarFlameSpeed` | ✓ [laminar-flame-speed.md](laminar-flame-speed.md) |
| Xi / XiEq / XiG / XiProfile / Su / 点火 | ✓ [xi-submodels.md](xi-submodels.md) |
| `radiationModel` + absorption/scatter/soot | ✓ [radiation-models.md](radiation-models.md) · [absorption-emission-scatter-soot.md](absorption-emission-scatter-soot.md) |
| `fvModels` → `radiation` | ✓ [radiation-fvModel.md](radiation-fvModel.md) |
| directory-only / ISAT 树实现类 | **不成页**（有意） |

可配置 RTS 类型文内提及：**46/46**（审计：非 directory 唯一名）。

**与 Phase 1 交叉**：详细化学/ISAT/火焰速度单页亦见 [`../thermophysical/chemistry-reactions/`](../thermophysical/chemistry-reactions/)；本目录侧重 `combustionProperties`、Xi 树、辐射与求解器用法。辐射/云 fvModel 包装页亦见 [`../fv-models-constraints/wrappers/`](../fv-models-constraints/wrappers/)。

## 导航

- [`../01-solver-matrix.md`](../01-solver-matrix.md) · [`../README.md`](../README.md) · [`../lagrangian/`](../lagrangian/)
