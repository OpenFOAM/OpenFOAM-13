# multiphaseEuler

## 一句话
任意数量可压相的 Euler 多相系（共用压力），可选界面传递与群体平衡。

## 适用条件（求解器 / 场 / 前提）
- **模块类型**: foamRun 求解器模块
- **源码头文件**: [`applications/modules/multiphaseEuler/multiphaseEuler.H`](../../../applications/modules/multiphaseEuler/multiphaseEuler.H)
- **链接库 (Make/options)**: `fluidSolver`, `populationBalance`, `multiphaseEulerMomentumTransportModels`, `multiphaseEulerThermophysicalTransportModels`, `multiphaseEulerReactions`, `fvModels`, `fvConstraints`

## 能力范围（摘自模块 Description）

Solver module for a system of any number of compressible fluid phases with a
common pressure, but otherwise separate properties. The type of phase model
is run time selectable and can optionally represent multiple species and
in-phase reactions. The phase system is also run time selectable and can
optionally represent different types of momentum, heat and mass transfer.

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

**提示**: `phaseProperties` 相系 + 界面模型 + 可选群体平衡

## Phase 3 多相条目
- 相模型：[phase-models.md](../multiphase/euler/phase-models.md)
- 界面/直径/PBE：[multiphase/euler/](../multiphase/euler/)（对账 [`rts`-multiphase-interfacial.md`](../_inventory/rts-multiphase-interfacial.md) **99/99**）
- 沸腾/相变 fvModels：[multiphase/phase-change/](../multiphase/phase-change/)

## 物理包使用情况（基于 Make/options 证据）
- **热物性**: 内建 — 相模型 RTS（phaseSystem）；可选多组分
- **动量输运**: 内建/可选 — `multiphaseEulerMomentumTransportModels`
- **热输运**: 可选 — `multiphaseEulerThermophysicalTransportModels`
- **辐射**: 待填
- **燃烧/化学**: 可选 — `-lmultiphaseEulerReactions`；相内反应可选
- **fvModels / fvConstraints**: 可选 — `wallBoiling`、相变、`multiphaseEulerCavitation` 等
- **群体平衡**: 可选 — `-lpopulationBalance`
- **典型场**: 相分数/`U`/`p`/`T` 等

## 目录交叉链接（目录页 Phase 1–5 补齐）
- 边界条件 → [boundary-conditions/](../boundary-conditions/)
- 热物性 → [thermophysical/](../thermophysical/)
- 动量输运 → [momentum-transport/](../momentum-transport/)
- 多相 → [multiphase/](../multiphase/)（Euler：[euler/](../multiphase/euler/)）
- 燃烧/辐射 → [combustion-radiation/](../combustion-radiation/)
- Lagrangian → [lagrangian/](../lagrangian/)
- fvModels/约束 → [fv-models-constraints/](../fv-models-constraints/)
- 动网格/波/大气 → [dynamic-mesh-waves-atm/](../dynamic-mesh-waves-atm/)
- 兼容矩阵 → [01-solver-matrix.md](../01-solver-matrix.md)

## 文献与源码依据
- 模块头文件 Description（见上）
- [`applications/modules/multiphaseEuler/Make/options`](../../../applications/modules/multiphaseEuler/Make/options)

## 注意事项
- 界面模型经 `blending` 在分散/连续极限间切换；见 [blending/](../multiphase/euler/blending/)。
- 兼容性仅依据 `Make/options` 与头文件描述标注。
