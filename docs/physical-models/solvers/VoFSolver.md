# VoFSolver

## 一句话
VoF 类求解器基类（混合物动量 + 界面压缩基础设施）。

## 适用条件（求解器 / 场 / 前提）
- **模块类型**: 基类 / 支撑模块（通常不作为 controlDict 最终 solver 单独使用，或仅作父类）
- **源码头文件**: [`applications/modules/VoFSolver/VoFSolver.H`](../../../applications/modules/VoFSolver/VoFSolver.H)
- **链接库 (Make/options)**: `fluidSolver`, `physicalProperties`, `interfaceCompression`, `finiteVolume`, `meshTools`, `fvModels`, `fvConstraints`, `sampling`

## 能力范围（摘自模块 Description）

Base solver module base-class for the solution of immiscible fluids using
a VOF (volume of fluid) phase-fraction based interface capturing approach,
with optional mesh motion and mesh topology changes including adaptive
re-meshing.

The momentum and other fluid properties are of the "mixture" and a single
momentum equation is solved.

Uses the flexible PIMPLE (PISO-SIMPLE) solution for time-resolved and
pseudo-transient and steady simulations.

Optional fvModels and fvConstraints are provided to enhance the simulation
in many ways including adding various sources, Lagrangian
particles, surface film etc. and constraining or limiting the solution.

## 所需字典（初稿 / 待 Phase 细化）
| 位置 | 典型文件 | 说明 |
|------|----------|------|
| `system`/` | `controlDict`（`solver`/`regionSolvers`） | 选择本模块 |
| `constant`/` | 见下表与矩阵 | 物性 / 输运 / 相系 |
| `0/` | 场文件 | 按求解器所需场 |

**提示**: 见模块源码与 tutorials/

## 物理包使用情况（基于 Make/options 证据）
- **角色**: VoF 基类 — 混合物动量 + 界面压缩基础设施
- **物理包**: 由派生 VoF 求解器决定
- **fvModels / fvConstraints**: 可选

## 目录交叉链接（目录页 Phase 1–5 补齐）
- 边界条件 → [boundary-conditions/](../boundary-conditions/)
- 热物性 → [thermophysical/](../thermophysical/)
- 动量输运 → [momentum-transport/](../momentum-transport/)
- 多相 → [multiphase/](../multiphase/)
- 燃烧/辐射 → [combustion-radiation/](../combustion-radiation/)
- Lagrangian → [lagrangian/](../lagrangian/)
- fvModels/约束 → [fv-models-constraints/](../fv-models-constraints/)
- 动网格/波/大气 → [dynamic-mesh-waves-atm/](../dynamic-mesh-waves-atm/)
- 兼容矩阵 → [01-solver-matrix.md](../01-solver-matrix.md)

## 文献与源码依据
- 模块头文件 Description（见上）
- [`applications/modules/VoFSolver/Make/options`](../../../applications/modules/VoFSolver/Make/options)

## 注意事项
- 本页为 Phase 0 导读骨架；具体模型字典与方程见后续 Phase 目录条目。
- 兼容性仅依据 `Make/options` 与头文件描述标注；未证实处标“待填”。
