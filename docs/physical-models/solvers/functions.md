# functions

## 一句话
按 controlDict 执行 functionObjects；经 subSolver 实例化物理场。

## 适用条件（求解器 / 场 / 前提）
- **模块类型**: 基类 / 支撑模块（通常不作为 controlDict 最终 solver 单独使用，或仅作父类）
- **源码头文件**: [`applications/modules/functions/functions.H`](../../../applications/modules/functions/functions.H)
- **链接库 (Make/options)**: `movingMesh`, `finiteVolume`

## 能力范围（摘自模块 Description）

Solver module to execute the `functionObjects` for a specified solver

The solver specified by either the `subSolver` or if not present the \c
solver entry in the `controlDict` is instantiated to provide the physical
fields needed by the `functionObjects`.  The `functionObjects` are then
instantiated from the specifications are read from the `functions` entry in
the `controlDict` and executed in a time-loop also controlled by entries in
`controlDict` and the `maxDeltaT`() returned by the sub-solver.

The fields and other objects registered by the sub-solver are set to
NO_WRITE as they are not changed by the execution of the functionObjects and
should not be written out each write-time.  Fields and other objects created
and changed by the execution of the functionObjects are written out.

When restarting from a time directory which does contain the `subSolver`
fields the optional `controlDict` entry `subSolverTime` may be provided to
specify which time the `subSolver` should be instantiated for, after which
time is reset to `startTime` for the restart.

## 所需字典（初稿 / 待 Phase 细化）
| 位置 | 典型文件 | 说明 |
|------|----------|------|
| `system`/` | `controlDict`（`solver`/`regionSolvers`） | 选择本模块 |
| `constant`/` | 见下表与矩阵 | 物性 / 输运 / 相系 |
| `0/` | 场文件 | 按求解器所需场 |

**提示**: `controlDict` 中 `subSolver` + `functions`

## 物理包使用情况（基于 Make/options 证据）
- **全部物理包**: 视 `controlDict` 中 `subSolver` / `solver` 而定
- **本模块职责**: 实例化子求解器场供 functionObjects 使用，并按时间推进执行
- **fvModels**: 视子求解器

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
- [`applications/modules/functions/Make/options`](../../../applications/modules/functions/Make/options)

## 注意事项
- 本页为 Phase 0 导读骨架；具体模型字典与方程见后续 Phase 目录条目。
- 兼容性仅依据 `Make/options` 与头文件描述标注；未证实处标“待填”。
