# isothermalFilm

## 一句话
等温可压液膜区域求解模块。

## 适用条件（求解器 / 场 / 前提）
- **模块类型**: foamRun 求解器模块
- **源码头文件**: [`applications/modules/isothermalFilm/isothermalFilm.H`](../../../applications/modules/isothermalFilm/isothermalFilm.H)
- **链接库 (Make/options)**: `fluidThermophysicalModels`, `momentumTransportModels`, `filmCompressibleMomentumTransportModels`, `interfaceProperties`, `finiteVolume`, `meshTools`, `sampling`, `fvModels`, `fvConstraints`

## 能力范围（摘自模块 Description）

Solver module for flow of compressible isothermal liquid films

Uses the flexible PIMPLE (PISO-SIMPLE) solution for time-resolved and
pseudo-transient and steady simulations.

Optional fvModels and fvConstraints are provided to enhance the simulation
in many ways including adding various sources, Lagrangian
particles, surface film etc. and constraining or limiting the solution.

## 所需字典（Phase 4 要点）
| 位置 | 典型文件 | 说明 |
|------|----------|------|
| `system`/` | `regionSolvers` | 区域 → `isothermalFilm` |
| `constant/<filmRegion>/` | 物性 + film 动量输运 | 等温液膜 |
| `constant/<filmRegion>/fvModels` | `filmCloudTransfer`、`filmVoFTransfer` | 滴落/与 VoF 交换 |
| 边界 | `mappedFilmSurface`、`mappedFilmPressure`、`filmSurfaceVelocity` | 区域耦合 |

**专页**: [../lagrangian/film.md](../lagrangian/film.md)

## 物理包使用情况（基于 Make/options 证据）
- **热物性**: 内建 — `fluidThermophysicalModels`
- **动量输运**: 可选 — `filmCompressibleMomentumTransportModels`
- **热输运**: 不可用（等温）
- **辐射**: **通常不强调**（等温无能量方程接收辐射源）；传热场景改用 `film`
- **燃烧/化学**: 不可用
- **fvModels / fvConstraints**: 可选（`filmCloudTransfer`、`filmVoFTransfer` 及 ejectionModels）
- **典型场**: 薄膜区域场；专用 mapped patch

## 目录交叉链接
- 薄膜耦合全谱 → [lagrangian/film.md](../lagrangian/film.md)
- 云侧 → [lagrangian/cloud-fvModels.md](../lagrangian/cloud-fvModels.md)
- 兼容矩阵 → [01-solver-matrix.md](../01-solver-matrix.md)

## 文献与源码依据
- 模块头文件 Description（见上）
- [`applications/modules/isothermalFilm/Make/options`](../../../applications/modules/isothermalFilm/Make/options)
- 教程：`multiRegion/film/cylinder*`, `VoFToFilm`, `splashPanel`

## 注意事项
- ejectionModel：`dripping` / `BrunDripping` / `curvatureSeparation`。
- 与 VoF 耦合时两侧阈值（`deltaFactorToVoF` 等）需按网格标定。
