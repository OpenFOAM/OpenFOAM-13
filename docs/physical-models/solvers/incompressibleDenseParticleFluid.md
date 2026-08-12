# incompressibleDenseParticleFluid

## 一句话
不可压连续相与稠密颗粒云耦合（含颗粒体积分数反作用）。

## 适用条件（求解器 / 场 / 前提）
- **模块类型**: foamRun 求解器模块
- **源码头文件**: [`applications/modules/incompressibleDenseParticleFluid/incompressibleDenseParticleFluid.H`](../../../applications/modules/incompressibleDenseParticleFluid/incompressibleDenseParticleFluid.H)
- **链接库 (Make/options)**: `fluidSolver`, `momentumTransportModels`, `incompressibleMomentumTransportModels`, `phaseIncompressibleMomentumTransportModels`, `physicalProperties`, `lagrangian`, `lagrangianParcel`, `finiteVolume`, `fvModels`, `fvConstraints`, `sampling`, `meshTools`

## 能力范围（摘自模块 Description）

Solver module for transient flow of incompressible isothermal fluids coupled
with particle clouds including the effect of the volume fraction of
particles on the continuous phase, with optional mesh motion and change.

Uses the flexible PIMPLE (PISO-SIMPLE) solution for time-resolved and
pseudo-transient and steady simulations.

Optional fvModels and fvConstraints are provided to enhance the simulation
in many ways including adding various sources, constraining or limiting
the solution.

Reference:
```
Greenshields, C. J., & Weller, H. G. (2022).
Notes on Computational Fluid Dynamics: General Principles.
CFD Direct Ltd.: Reading, UK.
```

## 所需字典（Phase 4 要点）
| 位置 | 典型文件 | 说明 |
|------|----------|------|
| `system`/` | `controlDict` | `solver` incompressibleDenseParticleFluid` |
| `constant`/` | `physicalProperties` | 连续相密度/粘度 |
| `constant`/` | `cloudProperties` | `type` cloud` 或 `MPPICCloud`；forces / injection / MPPIC → [lagrangian](../lagrangian/) |
| `0/` | `U`, `p` + 相体积分数相关场 | 颗粒反作用连续相 |

## 物理包使用情况（基于 Make/options 证据）
- **热物性**: 内建 — `physicalProperties`
- **动量输运**: 可选 — 不可压 ± phaseIncompressible
- **热输运**: 不可用
- **辐射**: 不可用
- **燃烧/化学**: 不可用
- **Lagrangian**: **内建耦合** — `-llagrangian` `-llagrangianParcel`（含颗粒体积分数对连续相影响）
- **fvModels / fvConstraints**: 可选
- **典型场**: `U`, `p` + 云

## 目录交叉链接
- 云配置 → [lagrangian/cloudProperties-patterns.md](../lagrangian/cloudProperties-patterns.md)
- MPPIC → [lagrangian/mppic.md](../lagrangian/mppic.md)
- 力 / 注入 → [parcel-forces](../lagrangian/parcel-forces.md) · [parcel-injection](../lagrangian/parcel-injection.md)
- 兼容矩阵 → [01-solver-matrix.md](../01-solver-matrix.md)

## 文献与源码依据
- 模块头文件 Description（见上）
- [`applications/modules/incompressibleDenseParticleFluid/Make/options`](../../../applications/modules/incompressibleDenseParticleFluid/Make/options)
- 教程：`Goldschmidt`, `GoldschmidtMPPIC`, `cyclone`, `column`, `injectionChannel`

## 注意事项
- 稠密阻力常用 `PlessisMasliyahDrag` / Ergun–Wen–Yu 族，并插值 `alpha`.*`。
- MPPIC 需 `packingModel` / `isotropyModel` 等，见 mppic 专页。
