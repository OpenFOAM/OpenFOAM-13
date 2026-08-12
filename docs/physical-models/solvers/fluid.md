# fluid

## 一句话
可压单相流体 + 传热（HVAC 等），可选动网格、fvModels/辐射/Lagrangian/薄膜。

## 适用条件（求解器 / 场 / 前提）
- **模块类型**: foamRun 求解器模块
- **源码头文件**: [`applications/modules/fluid/fluid.H`](../../../applications/modules/fluid/fluid.H)
- **链接库 (Make/options)**: `fluidSolver`, `isothermalFluid`, `fluidThermophysicalModels`, `compressibleMomentumTransportModels`, `coupledThermophysicalTransportModels`

## 能力范围（摘自模块 Description）

Solver module for steady or transient turbulent flow of compressible fluids
with heat-transfer for HVAC and similar applications, with optional
mesh motion and change.

Uses the flexible PIMPLE (PISO-SIMPLE) solution for time-resolved and
pseudo-transient and steady simulations.

Optional fvModels and fvConstraints are provided to enhance the simulation
in many ways including adding various sources, Lagrangian particles,
radiation, surface film etc. and constraining or limiting the solution.

Reference:
```
Greenshields, C. J., & Weller, H. G. (2022).
Notes on Computational Fluid Dynamics: General Principles.
CFD Direct Ltd.: Reading, UK.
```

## 所需字典（初稿 / 待 Phase 细化）
| 位置 | 典型文件 | 说明 |
|------|----------|------|
| `system`/` | `controlDict`（`solver`/`regionSolvers`） | 选择本模块 |
| `constant`/` | 见下表与矩阵 | 物性 / 输运 / 相系 |
| `0/` | 场文件 | 按求解器所需场 |

**提示**: `thermophysicalProperties`/`physicalProperties`, `momentumTransport`, `thermophysicalTransport`；可选辐射

## 物理包使用情况（基于 Make/options 证据）
- **热物性**: 内建 — `fluidThermophysicalModels`（经 `isothermalFluid`）
- **动量输运**: 可选 — 可压动量输运
- **热输运**: 内建/可选 — `-lcoupledThermophysicalTransportModels`
- **辐射**: 可选 — Description 写明
- **燃烧/化学**: 不可用
- **fvModels / fvConstraints**: 可选 — Description：源项/Lagrangian/薄膜等
- **典型场**: `U`, `p`, `T`

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
- [`applications/modules/fluid/Make/options`](../../../applications/modules/fluid/Make/options)

## 注意事项
- 本页为 Phase 0 导读骨架；具体模型字典与方程见后续 Phase 目录条目。
- 兼容性仅依据 `Make/options` 与头文件描述标注；未证实处标“待填”。
