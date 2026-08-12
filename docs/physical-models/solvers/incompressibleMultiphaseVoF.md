# incompressibleMultiphaseVoF

## 一句话
不可压多相 VoF（多相分数）界面捕捉。

## 适用条件（求解器 / 场 / 前提）
- **模块类型**: foamRun 求解器模块
- **源码头文件**: [`applications/modules/incompressibleMultiphaseVoF/incompressibleMultiphaseVoF.H`](../../../applications/modules/incompressibleMultiphaseVoF/incompressibleMultiphaseVoF.H)
- **链接库 (Make/options)**: `multiphaseVoFSolver`, `physicalProperties`, `multiphaseProperties`, `interfaceCompression`, `momentumTransportModels`, `incompressibleMomentumTransportModels`, `phaseIncompressibleMomentumTransportModels`, `finiteVolume`, `meshTools`, `fvModels`, `fvConstraints`, `sampling`

## 能力范围（摘自模块 Description）

Solver module for the solution of multiple incompressible, isothermal
immiscible fluids using a VOF (volume of fluid) phase-fraction based
interface capturing approach, with optional mesh motion and mesh topology
changes including adaptive re-meshing.

The momentum and other fluid properties are of the "mixture" and a single
momentum equation is solved.

A mixture approach for momentum transport is provided in which a single
laminar, RAS or LES model is selected to model the momentum stress.

Uses the flexible PIMPLE (PISO-SIMPLE) solution for time-resolved and
pseudo-transient and steady simulations.

## 所需字典（初稿 / 待 Phase 细化）
| 位置 | 典型文件 | 说明 |
|------|----------|------|
| `system`/` | `controlDict`（`solver`/`regionSolvers`） | 选择本模块 |
| `constant`/` | 见下表与矩阵 | 物性 / 输运 / 相系 |
| `0/` | 场文件 | 按求解器所需场 |

**提示**: 多相不可压 VoF

## Phase 3 多相条目
- [multiphase/vof/](../multiphase/vof/)（界面压缩/表面张力/混合物；**无**两相模块内 `VoFCavitation` 实现，见 [solver-validity](../multiphase/vof/solver-validity.md)）

## 物理包使用情况（基于 Make/options 证据）
- **热物性**: 内建 — `multiphaseProperties`
- **动量输运**: 可选 — 不可压 ± phaseIncompressible
- **热输运**: 不可用
- **辐射**: 不可用
- **燃烧/化学**: 不可用
- **fvModels / fvConstraints**: 可选（通用库；无两相 VoF 模块级空化实现）
- **典型场**: 多相 `alpha`.*`, `U`, `p`

## 目录交叉链接（目录页 Phase 1–5 补齐）
- 边界条件 → [boundary-conditions/](../boundary-conditions/)
- 热物性 → [thermophysical/](../thermophysical/)
- 动量输运 → [momentum-transport/](../momentum-transport/)
- 多相 → [multiphase/](../multiphase/)（VoF：[vof/](../multiphase/vof/)）
- 燃烧/辐射 → [combustion-radiation/](../combustion-radiation/)
- Lagrangian → [lagrangian/](../lagrangian/)
- fvModels/约束 → [fv-models-constraints/](../fv-models-constraints/)
- 动网格/波/大气 → [dynamic-mesh-waves-atm/](../dynamic-mesh-waves-atm/)
- 兼容矩阵 → [01-solver-matrix.md](../01-solver-matrix.md)

## 文献与源码依据
- 模块头文件 Description（见上）
- [`applications/modules/incompressibleMultiphaseVoF/Make/options`](../../../applications/modules/incompressibleMultiphaseVoF/Make/options)

## 注意事项
- 与两相 `incompressibleVoF` 共享界面压缩等库，但模块级 `VoFCavitation` 未移植到本求解器。
- 兼容性仅依据 `Make/options` 与头文件描述标注。
