# film

## 一句话
可压液膜 + 传热（基于 isothermalFilm）。

## 适用条件（求解器 / 场 / 前提）
- **模块类型**: foamRun 求解器模块
- **源码头文件**: [`applications/modules/film/film.H`](../../../applications/modules/film/film.H)
- **链接库 (Make/options)**: `isothermalFilm`, `filmThermophysicalTransportModels`, `coupledThermophysicalTransportModels`, `momentumTransportModels`, `compressibleMomentumTransportModels`, `finiteVolume`, `meshTools`, `sampling`, `fvModels`, `fvConstraints`

## 能力范围（摘自模块 Description）

Solver module for flow of compressible liquid films

Uses the flexible PIMPLE (PISO-SIMPLE) solution for time-resolved and
pseudo-transient and steady simulations.

Optional fvModels and fvConstraints are provided to enhance the simulation
in many ways including adding various sources, Lagrangian particles,
radiation, surface film etc. and constraining or limiting the solution.

## 所需字典（Phase 4 要点）
| 位置 | 典型文件 | 说明 |
|------|----------|------|
| `system`/` | `controlDict` `regionSolvers` | 区域名 → `film` |
| `constant/<filmRegion>/` | thermo + film 动量/热输运 | 可压液膜 + 传热 |
| `constant/<filmRegion>/fvModels` | `filmCloudTransfer` / `filmVoFTransfer` | 与云或 VoF 耦合 |
| 边界 | `mappedFilmSurface` 等 | 见薄膜专页 |

**薄膜专页（耦合与物理）**: [../lagrangian/film.md](../lagrangian/film.md)

## 物理包使用情况（基于 Make/options 证据）
- **热物性**: 内建 — 依赖 `isothermalFilm`
- **动量输运**: 可选 — 可压 + film 动量库
- **热输运**: 内建/可选 — `filmThermophysicalTransportModels`
- **辐射**: **可选** — Description；经 `radiation` fvModel
- **燃烧/化学**: 不可用
- **fvModels / fvConstraints**: 可选（filmCloudTransfer 等）
- **典型场**: 薄膜厚度/速度 + 能量

## 目录交叉链接
- 薄膜耦合 → [lagrangian/film.md](../lagrangian/film.md)
- 辐射激活 → [combustion-radiation/radiation-fvModel.md](../combustion-radiation/radiation-fvModel.md)
- 兼容矩阵 → [01-solver-matrix.md](../01-solver-matrix.md)

## 文献与源码依据
- 模块头文件 Description（见上）
- [`applications/modules/film/Make/options`](../../../applications/modules/film/Make/options)
- 教程：`multiRegion/film/hotBoxes` 等

## 注意事项
- 在 `isothermalFilm` 之上增加能量；耦合字典写在对应区域的 `fvModels`。
