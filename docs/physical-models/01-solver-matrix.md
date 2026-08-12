# 求解器兼容矩阵（Phase 0–5 回填：热物性/动量/热输运 + 多相 + 燃烧/辐射/Lagrangian + fvModels/动网格）

OpenFOAM-13 以 `foamRun` + [`applications/modules/`](../../applications/modules/) 模块架构为准。本表**行齐全**；单元格依据各模块头文件 `Description` 与 `Make/options` 链接库标注为 **内建 / 可选 / 不可用 / 待填**（见 [00-conventions.md](00-conventions.md)）。

详细能力说明见 [`solvers`/`](solvers/) 各页。热物性/动量/热输运细目见 [`thermophysical`/`](thermophysical/)、[`momentum`-transport/`](momentum-transport/)；多相见 [`multiphase`/`](multiphase/)；**燃烧/辐射/Xi** 见 [`combustion`-radiation/`](combustion-radiation/)；**Lagrangian/薄膜** 见 [`lagrangian`/`](lagrangian/)；fvModels/动网格/波见 [`fv`-models-constraints/`](fv-models-constraints/)、[`dynamic`-mesh-waves-atm/`](dynamic-mesh-waves-atm/)；清单与缺口见 [`_inventory`/`](_inventory/)、[`_inventory/coverage-gaps.md`](_inventory/coverage-gaps.md)。

## 图例

| 标记 | 含义 |
|------|------|
| 内建 | 核心路径依赖，通常必须配置 |
| 可选 | 已链接库或 Description 写明可选增强 |
| 不可用 | 有证据表明不适用 / 未链接 |
| 待填 | Phase 0 证据不足 |

**列含义**

| 列 | 通常对应的配置 |
|----|----------------|
| 热物性 | `physicalProperties` / `thermophysicalProperties` / `solidThermo` 等 |
| 动量输运 | `momentumTransport`（laminar/RAS/LES；或相专用） |
| 热输运 | `thermophysicalTransport` |
| 辐射 | 辐射模型（常经 fvModels / radiation 库） |
| 燃烧/化学 | `combustionProperties` / `chemistryProperties` / Xi 子模型 |
| fvModels 子集 | `constant/fvModels`（含模块专用源项） |
| 典型 BC | 该求解器常用场的 BC 族（Phase 2 细化） |

## 矩阵（应用层求解器）

| 求解器 | 热物性 | 动量输运 | 热输运 | 辐射 | 燃烧/化学 | fvModels 子集 | 典型 BC | 导读 |
|--------|--------|----------|--------|------|-----------|---------------|---------|------|
| [incompressibleFluid](solvers/incompressibleFluid.md) | 内建：[`viscosityModel` constant`](thermophysical/solid-liquid-tabulated/viscosityModel-constant.md)（无 `thermoType`） | 可选：[incompressible](momentum-transport/README.md) 全谱 laminar/RAS/LES | 不可用 | 不可用 | 不可用 | 可选（`-lfvModels`，经基类） | `U`/`p`；湍流场壁面函数 | [→](solvers/incompressibleFluid.md) |
| [isothermalFluid](solvers/isothermalFluid.md) | 内建：[`rhoFluid`/`psi` thermo](thermophysical/README.md)（等温，仍需物性） | 可选：[compressible](momentum-transport/README.md)（含 `buoyantKEpsilon`） | 不可用（等温） | 不可用（等温；Description 未列 radiation） | 不可用 | 可选 | `U`/`p`/`T`（等温） | [→](solvers/isothermalFluid.md) |
| [fluid](solvers/fluid.md) | 内建：[`forGases`/`forLiquids`/`forTabulated`](thermophysical/README.md) | 可选：compressible | 内建/可选：[Fourier / eddyDiffusivity 族](thermophysical/thermophysical-transport/)（`coupledThermophysicalTransportModels`） | 可选（Description + 教程 `hotRadiationRoom`*`；[`radiation` fvModel](fv-models-constraints/wrappers/radiation.md)） | 不可用 | 可选（sources/Lagrangian/film；见 [fv-models-constraints](fv-models-constraints/)） | `U`/`p`/`T`；热壁面 / 耦合 | [→](solvers/fluid.md) |
| [multicomponentFluid](solvers/multicomponentFluid.md) | 内建：[多组分 mixture + `forCoeff`*`](thermophysical/mixtures-and-energy/) | 可选：compressible | 可选：[Fickian / MaxwellStefan / Lewis eddy](thermophysical/thermophysical-transport/) | 可选（[`radiation` fvModel](combustion-radiation/radiation-fvModel.md) + [辐射模型](combustion-radiation/radiation-models.md)；教程 `smallPoolFire`*`/`SandiaD_LTS`） | 可选（[combustionModels](combustion-radiation/combustion-models.md) + [chemistry/TDAC](combustion-radiation/chemistry-solvers-reduction-isat.md)；亦见 [chemistry-reactions](thermophysical/chemistry-reactions/)） | 可选（含 [`clouds`](lagrangian/cloud-fvModels.md)/`radiation`） | `U`/`p`/`T`/`Y`.*` | [→](solvers/multicomponentFluid.md) |
| [XiFluid](solvers/XiFluid.md) | 内建：psiu 多组分 thermo | 可选：compressible | 可选：[fluidThermo TTM](thermophysical/thermophysical-transport/) | 可选（Description；[`radiation` fvModel](combustion-radiation/radiation-fvModel.md)） | 内建（[b-Xi 子模型树](combustion-radiation/xi-submodels.md) + [laminarFlameSpeed](combustion-radiation/laminar-flame-speed.md)） | 可选（点火/`clouds/radiation） | `b`/`ft`/`fu`/`Xi`/`U`/`p`/`T` | [→](solvers/XiFluid.md) |
| [shockFluid](solvers/shockFluid.md) | 内建：fluid thermo（高速密度基） | 可选：compressible | 可选：coupled TTM | 可选（`-lfvModels`；可 runtime `libs` ("libradiationModels.so")` + [`radiation`](fv-models-constraints/wrappers/radiation.md)；**无**官方辐射教程） | 不可用 | 可选 | 密度基场；模块内 slip 等 | [→](solvers/shockFluid.md) |
| [incompressibleVoF](solvers/incompressibleVoF.md) | 内建：两相 [`viscosityModel`](thermophysical/solid-liquid-tabulated/viscosityModel-constant.md) / [VoF mixture](multiphase/vof/mixtures.md) | 可选：混合物 incompressible 或相 [phaseIncompressible](momentum-transport/README.md)（RAS/LES **子集**） | 不可用 | 不可用 | 不可用 | 可选：[VoFCavitation](multiphase/vof/fvModels/VoFCavitation-incompressibleVoF.md)、[VoFTurbulenceDamping](multiphase/vof/fvModels/VoFTurbulenceDamping-incompressibleVoF.md)（无 Clouds/凝固；[validity](multiphase/vof/solver-validity.md)） | `alpha`.*`/`U`/`p`；[接触角](multiphase/vof/contact-angle/) | [→](solvers/incompressibleVoF.md) |
| [compressibleVoF](solvers/compressibleVoF.md) | 内建：各相 fluid thermo；[σ 可 liquidProperties](multiphase/vof/surface-tension/) | 可选：compressible + [phaseCompressible](momentum-transport/README.md) | 可选：coupled TTM | 可选（`-lfvModels` + 能量方程；可 runtime 挂 [`radiation`](fv-models-constraints/wrappers/radiation.md)；**无**官方辐射教程） | 不可用 | 可选：[VoFCavitation](multiphase/vof/fvModels/VoFCavitation-compressibleVoF.md)、阻尼、[VoFClouds](multiphase/vof/fvModels/VoFClouds.md)、[VoFSolidificationMelting](multiphase/vof/fvModels/VoFSolidificationMelting.md) | `alpha`.*`/`U`/`p`/`T` | [→](solvers/compressibleVoF.md) |
| [incompressibleMultiphaseVoF](solvers/incompressibleMultiphaseVoF.md) | 内建：`multiphaseProperties` + 各相粘度（[VoF](multiphase/vof/)） | 可选：不可压 + phaseIncompressible | 不可用 | 不可用 | 不可用 | 可选（通用；无两相模块级 VoF 空化，见 [validity](multiphase/vof/solver-validity.md)） | 多相 `alpha`.*`/`U`/`p` | [→](solvers/incompressibleMultiphaseVoF.md) |
| [compressibleMultiphaseVoF](solvers/compressibleMultiphaseVoF.md) | 内建：可压等温混合物 + fluidThermo（[VoF](multiphase/vof/)） | 可选：可压 + phaseIncompressible | 不可用（Description：isothermal） | 不可用 | 不可用 | 可选（通用；无 `VoFClouds/VoF 凝固） | 多相 `alpha`.*`/`U`/`p` | [→](solvers/compressibleMultiphaseVoF.md) |
| [multiphaseEuler](solvers/multiphaseEuler.md) | 内建：相 `physicalProperties`.*` + [thermoType](thermophysical/README.md)；[相模型](multiphase/euler/phase-models.md) | 内建/可选：[相专用 + kineticTheory](momentum-transport/phase-specific/) | 可选：相 TTM（Fourier/eddy…） | 可选（`-lfvModels`；可 runtime 挂 [`radiation`](fv-models-constraints/wrappers/radiation.md)；Description 未强调且**无**官方辐射教程） | 可选（`-lmultiphaseEulerReactions`；[phaseSurfaceArrhenius](combustion-radiation/reactions-overview.md)） | 可选：[wallBoiling/相变/空化](multiphase/phase-change/)；界面力见 [euler/](multiphase/euler/) | 相场/`U`/`p`/`T`；颗粒滑移 BC | [→](solvers/multiphaseEuler.md) |
| [incompressibleDriftFlux](solvers/incompressibleDriftFlux.md) | 内建：[mixtureViscosity + packingDispersion](multiphase/drift-flux/)（亦见 thermophysical 表） | 可选：compressible 动量库 | 不可用 | 不可用 | 不可用 | 可选 | `alpha`/`U`/`p` | [→](solvers/incompressibleDriftFlux.md) |
| [incompressibleDenseParticleFluid](solvers/incompressibleDenseParticleFluid.md) | 内建：`viscosityModel` | 可选：不可压 + phaseIncompressible | 不可用 | 不可用 | 不可用 | 可选；**Lagrangian 内建**（[cloudProperties](lagrangian/cloudProperties-patterns.md)/[MPPIC](lagrangian/mppic.md)） | `U`/`p` + 颗粒云耦合 | [→](solvers/incompressibleDenseParticleFluid.md) |
| [isothermalFilm](solvers/isothermalFilm.md) | 内建：fluid thermo | 可选：[film 仅 laminar](momentum-transport/phase-specific/filmCompressible-laminar.md) | 不可用（等温） | 不可用（等温） | 不可用 | 可选（[filmCloudTransfer](lagrangian/film.md)/filmVoFTransfer） | mapped film patches | [→](solvers/isothermalFilm.md) |
| [film](solvers/film.md) | 内建：同 isothermalFilm | 可选：film laminar | 内建/可选：`filmThermophysicalTransportModels` | 可选（Description；[`radiation` fvModel](combustion-radiation/radiation-fvModel.md)） | 不可用 | 可选（同 [film 耦合](lagrangian/film.md) + 辐射） | 薄膜 + 能量相关 BC | [→](solvers/film.md) |
| [solid](solvers/solid.md) | 内建：[`forSolids`](thermophysical/README.md) / [`constSolidThermo`](thermophysical/solid-liquid-tabulated/constSolidThermo.md) | 不可用 | 内建/可选：[isotropic / anisotropic](thermophysical/thermophysical-transport/) | 可选（教程 `multiRegion/CHT/reverseBurner` solid→`opaqueSolid`） | 不可用 | 可选 | `T`；共轭耦合 | [→](solvers/solid.md) |
| [solidDisplacement](solvers/solidDisplacement.md) | 内建（`solidDisplacementThermo`） | 不可用 | 可选：固体热输运；热应力可选 | 不可用 | 不可用 | 可选 | `D`/`T`；牵引位移 BC | [→](solvers/solidDisplacement.md) |
| [movingMesh](solvers/movingMesh.md) | 不可用 | 不可用 | 不可用 | 不可用 | 不可用 | 不可用（无场方程；用 [`dynamicMeshDict`](dynamic-mesh-waves-atm/)） | 网格运动相关 | [→](solvers/movingMesh.md) |
| [functions](solvers/functions.md) | 视 `subSolver` | 视 `subSolver` | 视 `subSolver` | 视 `subSolver` | 视 `subSolver` | 视子求解器；本模块执行 functionObjects | 视子求解器 | [→](solvers/functions.md) |

## 矩阵（基类 / 支撑模块）

这些模块提供共享算法，通常由上表求解器链接，**不作为**最终 `solver` 名称（`functions`/`movingMesh` 除外，已列于上表）。

| 模块 | 热物性 | 动量输运 | 热输运 | 辐射 | 燃烧/化学 | fvModels | 典型 BC | 导读 |
|------|--------|----------|--------|------|-----------|----------|---------|------|
| [fluidSolver](solvers/fluidSolver.md) | 经派生 | 链接不可压动量库 | 不可用 | 不可用 | 不可用 | 可选 | — | [→](solvers/fluidSolver.md) |
| [VoFSolver](solvers/VoFSolver.md) | 经派生 | 经派生 | 经派生 | 经派生 | 经派生 | 可选 | VoF 场 | [→](solvers/VoFSolver.md) |
| [twoPhaseSolver](solvers/twoPhaseSolver.md) | 经派生 | 混合物或两相输运（Description） | 经派生 | 经派生 | 经派生 | 可选 | 两相 | [→](solvers/twoPhaseSolver.md) |
| [twoPhaseVoFSolver](solvers/twoPhaseVoFSolver.md) | 经派生 | 同两相 VoF | 经派生 | 经派生 | 经派生 | 可选 | 两相 VoF | [→](solvers/twoPhaseVoFSolver.md) |
| [multiphaseVoFSolver](solvers/multiphaseVoFSolver.md) | 经派生 | 经派生 | 经派生 | 经派生 | 经派生 | 可选 | 多相 VoF | [→](solvers/multiphaseVoFSolver.md) |

## 证据索引（Make/options 库摘要）

| 模块 | 关键 `-l` 库（摘录） |
|------|---------------------|
| incompressibleFluid | `fluidSolver`（基类再链 incompressibleMomentumTransport / fvModels） |
| isothermalFluid | `fluidThermophysicalModels`, `compressibleMomentumTransportModels`, `fvModels`, `fvConstraints` |
| fluid | `isothermalFluid`, `fluidThermophysicalModels`, `compressibleMomentumTransportModels`, `coupledThermophysicalTransportModels` |
| multicomponentFluid | 上 + `combustionModels`, `chemistryModel`, `multicomponentThermophysicalModels`, `fluidMulticomponentThermophysicalTransportModels` |
| XiFluid | `multicomponentThermophysicalModels`, `laminarFlameSpeedModels`, `fluidThermoThermophysicalTransportModels` |
| shockFluid | `fluidThermophysicalModels`, `compressibleMomentumTransportModels`, `coupledThermophysicalTransportModels` |
| incompressibleVoF | `twoPhaseVoFSolver`, `phaseIncompressibleMomentumTransportModels`, … |
| compressibleVoF | `fluidThermophysicalModels`, `phaseCompressibleMomentumTransportModels`, `coupledThermophysicalTransportModels` |
| multiphaseEuler | `multiphaseEulerMomentumTransportModels`, `multiphaseEulerThermophysicalTransportModels`, `populationBalance`, `multiphaseEulerReactions` |
| incompressibleDriftFlux | `incompressibleDriftFluxViscosityModel`, `…RelativeVelocity…`, `…PackingDispersion…` |
| incompressibleDenseParticleFluid | `lagrangian`, `lagrangianParcel`, `phaseIncompressibleMomentumTransportModels` |
| isothermalFilm / film | film 动量/热输运库；`film` 另链 `filmThermophysicalTransportModels` |
| solid / solidDisplacement | `solidThermo` / `solidDisplacementThermo`, `solidThermophysicalTransportModels` |

完整列表见各模块 `applications/modules/<name>/Make/options`。

## 辐射列证据（Phase 5）

辐射经运行时 `fvModels` + `libs` ("libradiationModels.so")` + `radiationProperties` 激活（详见 [`fv`-models-constraints/wrappers/radiation.md`](fv-models-constraints/wrappers/radiation.md)）。

| 证据 | 内容 |
|------|------|
| Make/options | `fluid`/`multicomponentFluid`/`XiFluid`/`film`/`solid` 等有能量路径且链 `-lfvModels`（或经基类）；`shockFluid`/`compressibleVoF`/`multiphaseEuler` 亦链 `-lfvModels` |
| 教程实证 | `fluid/hotRadiationRoom*`、`multicomponentFluid/smallPoolFire*`/`SandiaD_LTS`、`multiRegion/CHT/reverseBurner`（含 solid `opaqueSolid`） |
| 无教程但仍可选 | `shockFluid`、`compressibleVoF`、`multiphaseEuler`：库链接允许挂 radiation，但仓库 `tutorials`/` 无对应辐射案例 |
| 不可用 | 等温/无能量模块（`incompressibleFluid`、`isothermalFluid`、`incompressibleVoF`、…） |

## Phase 回填进度

- **Phase 1（已回填）**：热物性 / 动量 / 热输运列已链到 [`thermophysical`/`](thermophysical/)、[`momentum`-transport/`](momentum-transport/)；注册差异见动量 README。
- Phase 2：典型 BC 列链到 `boundary`-conditions/**` 条目（进行中）。
- **Phase 3（已回填多相相关单元格）**：[`multiphase`/`](multiphase/) VoF / Euler / drift-flux / phase-change；inventory 界面模型 99/99。
- **Phase 4（已回填）**：[`combustion`-radiation/`](combustion-radiation/)（燃烧/化学/辐射/Xi）、[`lagrangian`/`](lagrangian/)（parcel/MPPIC/新框架/[film.md](lagrangian/film.md)）；燃烧/化学列与相关辐射、稠密颗粒/薄膜单元格已链到本批文档。
- **Phase 5（已回填）**：辐射列无「待填/需验证」（`shockFluid`/`compressibleVoF`/`multiphaseEuler` 标为可选+无官方辐射教程）；`movingMesh` 动网格；[`fv`-models-constraints/`](fv-models-constraints/)、[`dynamic`-mesh-waves-atm/`](dynamic-mesh-waves-atm/)；[`_inventory/coverage-gaps.md`](_inventory/coverage-gaps.md) 主责 inventory **0 孤立**。
