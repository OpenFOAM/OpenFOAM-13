# multicomponentFluid

## 一句话
可压多组分流体，可选燃烧与化学反应。

## 适用条件（求解器 / 场 / 前提）
- **模块类型**: foamRun 求解器模块
- **源码头文件**: [`applications/modules/multicomponentFluid/multicomponentFluid.H`](../../../applications/modules/multicomponentFluid/multicomponentFluid.H)
- **链接库 (Make/options)**: `fluidSolver`, `isothermalFluid`, `fluidThermophysicalModels`, `specie`, `chemistryModel`, `ODE`, `combustionModels`, `multicomponentThermophysicalModels`, `momentumTransportModels`, `compressibleMomentumTransportModels`, `coupledThermophysicalTransportModels`, `fluidMulticomponentThermophysicalTransportModels`, `finiteVolume`, `fvModels`, `fvConstraints`, `meshTools`, `sampling`

## 能力范围（摘自模块 Description）

Solver module for steady or transient turbulent flow of compressible
multicomponent fluids with optional mesh motion and change.

Uses the flexible PIMPLE (PISO-SIMPLE) solution for time-resolved and
pseudo-transient and steady simulations.

Optional fvModels and fvConstraints are provided to enhance the simulation
in many ways including adding various sources, chemical reactions,
combustion, Lagrangian particles, radiation, surface film etc. and
constraining or limiting the solution.

Reference:
```
Greenshields, C. J., & Weller, H. G. (2022).
Notes on Computational Fluid Dynamics: General Principles.
CFD Direct Ltd.: Reading, UK.
```

## 所需字典（Phase 4 要点）
| 位置 | 典型文件 | 说明 |
|------|----------|------|
| `system`/` | `controlDict` | `solver` multicomponentFluid` |
| `constant`/` | `thermophysicalProperties` / 多组分 thermo | 物种与 `thermoType` |
| `constant`/` | `combustionProperties` | `combustionModel`：laminar / EDC / PaSR / … → [combustion-models](../combustion-radiation/combustion-models.md) |
| `constant`/` | `chemistryProperties` | ode / 降维 / ISAT → [chemistry](../combustion-radiation/chemistry-solvers-reduction-isat.md) |
| `constant`/` | `radiationProperties` + `fvModels`(`radiation`) | 可选辐射 → [radiation-fvModel](../combustion-radiation/radiation-fvModel.md) |
| `constant`/` | `fvModels`(`clouds`) + `cloudProperties` | 可选喷雾/颗粒 → [lagrangian](../lagrangian/) |
| `0/` | `U` `p` `T` `Y`.*` | 多组分场 |

## 物理包使用情况（基于 Make/options 证据）
- **热物性**: 内建 — 多组分 thermophysical
- **动量输运**: 可选 — 可压
- **热输运**: 可选 — `fluidMulticomponentThermophysicalTransportModels`
- **辐射**: **可选** — Description + 教程 `fvModels` type radiation` + `libradiationModels`.so`
- **燃烧/化学**: **可选** — `-lcombustionModels` `-lchemistryModel`
- **fvModels / fvConstraints**: 可选（含 `clouds`、`radiation`）
- **典型场**: `U`, `p`, `T`, `Y`.*`

## 目录交叉链接
- 燃烧/辐射 → [combustion-radiation/](../combustion-radiation/)
- Lagrangian → [lagrangian/](../lagrangian/)
- 兼容矩阵 → [01-solver-matrix.md](../01-solver-matrix.md)
- 其它族 → [boundary-conditions/](../boundary-conditions/) · [thermophysical/](../thermophysical/) · [momentum-transport/](../momentum-transport/)

## 文献与源码依据
- 模块头文件 Description（见上）
- [`applications/modules/multicomponentFluid/Make/options`](../../../applications/modules/multicomponentFluid/Make/options)
- 教程：`counterFlowFlame2D`*`, `SandiaD_LTS`, `aachenBomb`, `smallPoolFire3D`, `simplifiedSiwek`

## 注意事项
- 辐射必须经 `fvModels` 激活，仅写 `radiationProperties` 不够（v13）。
- 燃烧模型与 XiFluid 的 b-Xi 字典不互通。
