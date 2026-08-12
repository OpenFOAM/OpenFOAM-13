# XiFluid

## 一句话
可压预混/部分预混燃烧（Weller b-Xi），含层流火焰速度子模型。

## 适用条件（求解器 / 场 / 前提）
- **模块类型**: foamRun 求解器模块
- **源码头文件**: [`applications/modules/XiFluid/XiFluid.H`](../../../applications/modules/XiFluid/XiFluid.H)
- **链接库 (Make/options)**: `fluidSolver`, `isothermalFluid`, `momentumTransportModels`, `compressibleMomentumTransportModels`, `fluidThermoThermophysicalTransportModels`, `coupledThermophysicalTransportModels`, `multicomponentThermophysicalModels`, `specie`, `laminarFlameSpeedModels`, `finiteVolume`, `fvModels`, `fvConstraints`, `sampling`, `meshTools`

## 能力范围（摘自模块 Description）

Solver module for compressible premixed/partially-premixed combustion with
turbulence modelling.

Combusting RANS code using the Weller b-Xi two-equation combustion model.
Xi may be obtained by either the solution of the Xi transport equation or
from an algebraic expression.

Reference:
```
Weller, H. G. (1993).
The development of a new flame area combustion model
using conditional averaging.
Thermo-fluids section report TF 9307.
```

Both approaches are based on Gulder's flame speed correlation which has been
shown to be appropriate by comparison with the results from the spectral
model.

Reference:
```
Weller, H. G., Marooney, C. J., & Gosman, A. D. (1991, January).
A new spectral method for calculation of the time-varying area
of a laminar flame in homogeneous turbulence.
In Symposium (International) on Combustion
(Vol. 23, No. 1, pp. 629-636). Elsevier.
```

Strain effects are incorporated directly into the Xi equation
but not in the algebraic approximation.  Further work need to be
done on this issue, particularly regarding the enhanced removal rate
caused by flame compression.  Analysis using results of the spectral
model will be required.

For cases involving very lean Propane flames or other flames which are
very strain-sensitive, a transport equation for the laminar flame
speed is present.  This equation is derived using heuristic arguments
involving the strain time scale and the strain-rate at extinction.
the transport velocity is the same as that for the Xi equation.

Reference:
```
Weller, H. G., Tabor, G., Gosman, A. D., & Fureby, C. (1998, January).
Application of a flame-wrinkling LES combustion model
to a turbulent mixing layer.
In Symposium (International) on combustion
(Vol. 27, No. 1, pp. 899-907). Elsevier.
```

For inhomogeneous mixtures, in addition to the regress variable `b`, it is
necessary to solve for the mixture-fraction `ft` provided by the \c
leanInhomogeneousMixture and also the fuel mass-fraction `fu` if there are
rich regions in the mixture, provided by the `inhomogeneousMixture`.
Details of the extension of the Weller b-Xi combustion model to non-premixed
combustion can be found in the Technical Report TR/HGW/03.

Reference:
```
Weller, H. G. (2002, August).
The Application of the Weller Combustion Models to
Non-Premixed Combustion.
(Technical Report TR/HGW/03)
```

For inhomogeneous mixtures with exhaust gas re-circulation it is necessary
to additionally solve for the recirculated exhaust gas mass-fraction \c
egr which is provided by the `inhomogeneousEGRMixture` mixture.

Uses the flexible PIMPLE (PISO-SIMPLE) solution for time-resolved and
pseudo-transient and steady simulations.

Reference:
```
Greenshields, C. J., & Weller, H. G. (2022).
Notes on Computational Fluid Dynamics: General Principles.
CFD Direct Ltd.: Reading, UK.
```

Optional fvModels and fvConstraints are provided to enhance the simulation
in many ways including adding various sources, chemical reactions,
combustion, Lagrangian particles, radiation, surface film etc. and
constraining or limiting the solution.

## 所需字典（Phase 4 要点）
| 位置 | 典型文件 | 说明 |
|------|----------|------|
| `system`/` | `controlDict` | `solver` XiFluid` |
| `constant`/` | 多组分 / psiu thermo | 预混或分层混合物 |
| `constant`/` | `combustionProperties` | `laminarFlameSpeed` + `flameWrinkling`（Xi/XiEq/XiG/Su）→ [xi-submodels](../combustion-radiation/xi-submodels.md) |
| `constant`/` | `fvModels` | 可选 `constantbXiIgnition` 等点火；可选 `radiation` |
| `0/` | `b`, `Xi`, （`ft`/`fu`/`egr`）, `U`, `p`, `T` | 视 mixture |

## 物理包使用情况（基于 Make/options 证据）
- **热物性**: 内建 — 多组分 / 预混相关 thermo
- **动量输运**: 可选 — 可压
- **热输运**: 可选 — `fluidThermoThermophysicalTransportModels`
- **辐射**: **可选** — Description 写明 radiation；经 fvModel 激活（教程覆盖弱于 multicomponentFluid）
- **燃烧/化学**: **内建** — b-Xi + `-llaminarFlameSpeedModels`（非 EDC/PaSR 路径）
- **fvModels / fvConstraints**: 可选（点火、辐射、云等）
- **典型场**: `b`, `Xi`, `ft`/`fu`（视混合物）, `U`, `p`, `T`

## 目录交叉链接
- Xi / 火焰速度 → [xi-submodels](../combustion-radiation/xi-submodels.md) · [laminar-flame-speed](../combustion-radiation/laminar-flame-speed.md)
- 燃烧总目录 → [combustion-radiation/](../combustion-radiation/)
- 兼容矩阵 → [01-solver-matrix.md](../01-solver-matrix.md)

## 文献与源码依据
- 模块头文件 Description（见上）
- [`applications/modules/XiFluid/Make/options`](../../../applications/modules/XiFluid/Make/options)
- 教程：`moriyoshiHomogeneous`, `engine2Valve2D`, `stratified`, `kivaTest`, `1D`

## 注意事项
- 不要使用 `combustionModel` EDC/laminar` 字典形态；XiFluid 使用 `flameWrinkling` 树。
- 分层/EGR 需正确 mixture 类型，否则缺 `ft`/`fu`/`egr` 场。
