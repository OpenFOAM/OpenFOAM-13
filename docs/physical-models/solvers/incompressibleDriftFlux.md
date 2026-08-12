# incompressibleDriftFlux

## 一句话
不可压两相漂移通量近似（混合物动量 + 相对速度模型）。

## 适用条件（求解器 / 场 / 前提）
- **模块类型**: foamRun 求解器模块
- **源码头文件**: [`applications/modules/incompressibleDriftFlux/incompressibleDriftFlux.H`](../../../applications/modules/incompressibleDriftFlux/incompressibleDriftFlux.H)
- **链接库 (Make/options)**: `incompressibleDriftFluxViscosityModel`, `incompressibleDriftFluxRelativeVelocityModels`, `incompressibleDriftFluxPackingDispersionModels`, `twoPhaseSolver`, `physicalProperties`, `interfaceCompression`, `incompressibleTwoPhases`, `twoPhaseProperties`, `interfaceProperties`, `momentumTransportModels`, `compressibleMomentumTransportModels`, `finiteVolume`, `meshTools`, `fvModels`, `fvConstraints`, `sampling`

## 能力范围（摘自模块 Description）

Solver module for 2 incompressible fluids using the mixture approach with
the drift-flux approximation for relative motion of the phases, with
optional mesh motion and mesh topology changes including adaptive
re-meshing.

The momentum and other fluid properties are of the "mixture" and a single
momentum equation is solved with mixture transport modelling in which a
single laminar, RAS or LES model is selected to model the momentum stress.

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

**提示**: 漂移通量混合物粘度 / packingDispersion

## Phase 3 多相条目
- [multiphase/drift-flux/](../multiphase/drift-flux/)：相对速度 / 堆积弥散 / 混合物粘度

## 物理包使用情况（基于 Make/options 证据）
- **热物性**: 内建 — 两相 mixture + 专用粘度/相对速度/弥散库
- **动量输运**: 可选 — 链接 `compressibleMomentumTransportModels`
- **热输运**: 不可用
- **辐射**: 不可用
- **燃烧/化学**: 不可用
- **fvModels / fvConstraints**: 可选
- **典型场**: `alpha`, `U`, `p`

## 目录交叉链接（目录页 Phase 1–5 补齐）
- 边界条件 → [boundary-conditions/](../boundary-conditions/)
- 热物性 → [thermophysical/](../thermophysical/)
- 动量输运 → [momentum-transport/](../momentum-transport/)
- 多相 → [multiphase/](../multiphase/)（漂移通量：[drift-flux/](../multiphase/drift-flux/)）
- 燃烧/辐射 → [combustion-radiation/](../combustion-radiation/)
- Lagrangian → [lagrangian/](../lagrangian/)
- fvModels/约束 → [fv-models-constraints/](../fv-models-constraints/)
- 动网格/波/大气 → [dynamic-mesh-waves-atm/](../dynamic-mesh-waves-atm/)
- 兼容矩阵 → [01-solver-matrix.md](../01-solver-matrix.md)

## 文献与源码依据
- 模块头文件 Description（见上）
- [`applications/modules/incompressibleDriftFlux/Make/options`](../../../applications/modules/incompressibleDriftFlux/Make/options)

## 注意事项
- `relativeVelocityModel` 与 `packingDispersion` / `mixtureViscosity` 关键字见 drift-flux 各页。
- 兼容性仅依据 `Make/options` 与头文件描述标注。
