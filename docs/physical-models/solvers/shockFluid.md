# shockFluid

## 一句话
密度基可压流（Kurganov–Tadmor 型中心迎风），适合高速/激波。

## 适用条件（求解器 / 场 / 前提）
- **模块类型**: foamRun 求解器模块
- **源码头文件**: [`applications/modules/shockFluid/shockFluid.H`](../../../applications/modules/shockFluid/shockFluid.H)
- **链接库 (Make/options)**: `fluidSolver`, `fluidThermophysicalModels`, `momentumTransportModels`, `compressibleMomentumTransportModels`, `coupledThermophysicalTransportModels`, `finiteVolume`, `meshTools`, `fvModels`, `fvConstraints`

## 能力范围（摘自模块 Description）

Solver module for density-based solution of compressible flow

Based on central-upwind schemes of Kurganov and Tadmor with support for
mesh-motion and topology change.

Reference:
```
Greenshields, C. J., Weller, H. G., Gasparini, L.,
& Reese, J. M. (2010).
Implementation of semi‐discrete, non‐staggered central schemes
in a colocated, polyhedral, finite volume framework,
for high‐speed viscous flows.
International journal for numerical methods in fluids, 63(1), 1-21.
```

## 所需字典（初稿 / 待 Phase 细化）
| 位置 | 典型文件 | 说明 |
|------|----------|------|
| `system`/` | `controlDict`（`solver`/`regionSolvers`） | 选择本模块 |
| `constant`/` | 见下表与矩阵 | 物性 / 输运 / 相系 |
| `0/` | 场文件 | 按求解器所需场 |

**提示**: 密度基；thermo + 可压动量/热输运；模块内滑移等 BC

## 物理包使用情况（基于 Make/options 证据）
- **热物性**: 内建 — `fluidThermophysicalModels`
- **动量输运**: 可选 — 可压
- **热输运**: 可选 — coupled TTM
- **辐射**: 待填
- **燃烧/化学**: 不可用
- **fvModels / fvConstraints**: 可选
- **典型场**: 密度基守恒变量；模块内 slip 等 BC

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
- [`applications/modules/shockFluid/Make/options`](../../../applications/modules/shockFluid/Make/options)

## 注意事项
- 本页为 Phase 0 导读骨架；具体模型字典与方程见后续 Phase 目录条目。
- 兼容性仅依据 `Make/options` 与头文件描述标注；未证实处标“待填”。
