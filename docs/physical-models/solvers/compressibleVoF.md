# compressibleVoF

## 一句话
可压非等温两相 VoF，可选混合物或分相动量输运与热输运。

## 适用条件（求解器 / 场 / 前提）
- **模块类型**: foamRun 求解器模块
- **源码头文件**: [`applications/modules/compressibleVoF/compressibleVoF.H`](../../../applications/modules/compressibleVoF/compressibleVoF.H)
- **链接库 (Make/options)**: `twoPhaseVoFSolver`, `physicalProperties`, `fluidThermophysicalModels`, `interfaceCompression`, `compressibleInterfaceProperties`, `compressibleTwoPhases`, `momentumTransportModels`, `compressibleMomentumTransportModels`, `phaseCompressibleMomentumTransportModels`, `thermophysicalTransportModel`, `coupledThermophysicalTransportModels`, `finiteVolume`, `meshTools`, `fvModels`, `fvConstraints`, `sampling`

## 能力范围（摘自模块 Description）

Solver module for 2 compressible, non-isothermal immiscible fluids
using a VOF (volume of fluid) phase-fraction based interface capturing
approach, with optional mesh motion and mesh topology changes including
adaptive re-meshing.

The momentum and other fluid properties are of the "mixture" and a single
momentum equation is solved.

Either mixture or two-phase transport modelling may be selected.  In the
mixture approach a single laminar, RAS or LES model is selected to model the
momentum stress.  In the Euler-Euler two-phase approach separate laminar,
RAS or LES selected models are selected for each of the phases.

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

**提示**: 可压两相 VoF + thermo + 可选相动量输运

## Phase 3 多相条目
- 总览：[multiphase/vof/](../multiphase/vof/) · [求解器有效性](../multiphase/vof/solver-validity.md)
- 可压表面张力：`liquidProperties`；空化含 `Saito`
- fvModels：`VoFCavitation`、`VoFTurbulenceDamping`、**`VoFClouds`**、**`VoFSolidificationMelting`**（后二者仅本模块 Allwmake）

## 物理包使用情况（基于 Make/options 证据）
- **热物性**: 内建 — `fluidThermophysicalModels`
- **动量输运**: 可选 — 可压 ± `phaseCompressible`
- **热输运**: 可选 — coupled TTM
- **辐射**: 待填
- **燃烧/化学**: 不可用
- **fvModels / fvConstraints**: 可选 — 上列 VoF 专用模型（见 multiphase/vof/fvModels）
- **典型场**: `alpha`.*`, `U`, `p`, `T`

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
- [`applications/modules/compressibleVoF/Make/options`](../../../applications/modules/compressibleVoF/Make/options)
- [`applications/modules/compressibleVoF/Allwmake`](../../../applications/modules/compressibleVoF/Allwmake)（`libVoFClouds` / `libVoFSolidificationMelting`）

## 注意事项
- `VoFClouds` / `VoFSolidificationMelting` **不适用于** incompressibleVoF。
- 兼容性仅依据 `Make/options` 与头文件描述标注。
