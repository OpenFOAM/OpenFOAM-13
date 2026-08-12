# OpenFOAM-13 物理模型手册

本地中文速查手册：以**求解器兼容矩阵**为导航核心，覆盖边界条件、热物性、动量/热输运、多相、燃烧辐射、Lagrangian、fvModels 等。正文中文；类型名、字典关键字与源码路径保持英文原文。

> 路径根目录：`docs/physical-models/`（相对仓库根 [`OpenFOAM`-13`](../../)）

## 怎么用本手册

1. **先定求解器**：在 [`01-solver-matrix.md`](01-solver-matrix.md) 找到目标模块行，看哪些物理包是「内建 / 可选 / 不可用」。
2. **再读求解器导读**：打开 [`solvers`/`](solvers/) 对应页面，确认所需字典与能力边界（摘自模块头文件 Description + `Make/options`）。
3. **按模型族下钻**：进入下方目录（边界条件、热物性、湍流…）；Phase 1–5 会逐条补全「字典 + 方程」条目。
4. **查全量类型名**：[`_inventory`/`](_inventory/) 是从 RTS / `make`*` 宏检索出的机器清单，写案例时先核对类型是否存在。
5. **对照约定**：命名、字典位置、量纲与强制条目模板见 [`00-conventions.md`](00-conventions.md)。

权威语法还可对照仓库内 [`etc/caseDicts/`](../../etc/caseDicts/) 与 [`tutorials`/`](../../tutorials/)。

## 案例搭建决策树（简版）

```text
需要模拟什么？
├─ 单相流体
│  ├─ 不可压、等温 ──────────────► incompressibleFluid
│  ├─ 可压、等温 ────────────────► isothermalFluid
│  ├─ 可压 + 传热 ───────────────► fluid
│  ├─ 多组分 ± 燃烧/化学 ────────► multicomponentFluid
│  ├─ 预混/部分预混（b-Xi）──────► XiFluid
│  └─ 高速密度基 / 激波 ─────────► shockFluid
├─ 两相 / 多相界面（VoF）
│  ├─ 不可压两相 ────────────────► incompressibleVoF
│  ├─ 可压两相（非等温）─────────► compressibleVoF
│  ├─ 不可压多相 ────────────────► incompressibleMultiphaseVoF
│  └─ 可压多相（等温）───────────► compressibleMultiphaseVoF
├─ Euler 多相（相间力/传热…）─────► multiphaseEuler
├─ 漂移通量混合物 ────────────────► incompressibleDriftFlux
├─ 稠密颗粒（连续相 + 云）────────► incompressibleDenseParticleFluid
├─ 薄膜区域
│  ├─ 等温薄膜 ──────────────────► isothermalFilm
│  └─ 可压液膜 + 传热 ───────────► film
├─ 固体
│  ├─ 导热 / CHT 固体域 ─────────► solid
│  └─ 线弹性小应变 ± 热应力 ─────► solidDisplacement
├─ 仅动网格 / 后处理函数 ─────────► movingMesh / functions
└─ 不确定 ────────────────────────► 先看 01-solver-matrix.md 与 tutorials/
```

选定求解器后可叠加可选包：`momentumTransport`、`thermophysicalTransport`、`fvModels`（含 `radiation`/`clouds`/孔隙/波浪强迫）、`fvConstraints`、`dynamicMeshDict/MRF、大气 ABL BC——见 [`fv`-models-constraints/`](fv-models-constraints/)、[`dynamic`-mesh-waves-atm/`](dynamic-mesh-waves-atm/)。

基类模块（`fluidSolver`、`VoFSolver`、`twoPhaseSolver` 等）一般不作为 `controlDict` 的最终 `solver`，见各导读页说明。

## 进度

| Phase | 内容 | 状态 |
|-------|------|------|
| **0** | 目录树、约定、求解器矩阵骨架、24 个 solver 导读、`_inventory`/` 全量清单 | **已完成** |
| 1 | 热物性全谱 + 动量/热输运全谱 | **基本完成**（正文在 `thermophysical`/`、`momentum`-transport/`；stem 精确匹配仍有缺口，见 [coverage-gaps](_inventory/coverage-gaps.md)） |
| 2 | 边界条件全谱（含库外 BC） | **已完成**（[`boundary`-conditions/`](boundary-conditions/)：inventory 299→199 页全覆盖；缺口见 [`GAPS`.md`](boundary-conditions/GAPS.md)） |
| 3 | VoF / Euler / 漂移通量 / 相变 | **已完成**（`multiphase`/`；界面模型 inventory 0 缺口） |
| 4 | 燃烧·化学·辐射、Lagrangian、薄膜 | **基本完成**（族概览页齐全；部分 RTS 子类型尚无同名页，见 coverage-gaps） |
| **5** | fvModels/约束、动网格/波/大气 + inventory 交叉总检 | **已完成**（[`fv`-models-constraints/`](fv-models-constraints/) · [`dynamic`-mesh-waves-atm/`](dynamic-mesh-waves-atm/)；主责 inventory **0 孤立**；矩阵辐射列已按 Make/options+教程回填） |

## 导航

### 核心

| 文档 | 说明 |
|------|------|
| [00-conventions.md](00-conventions.md) | 命名、字典位置、RTS、量纲、条目模板 |
| [01-solver-matrix.md](01-solver-matrix.md) | 求解器 × 物理包兼容总表 |
| [solvers/](solvers/) | 全部 `applications/modules/` 导读 |

### 模型族目录（Phase 1–5 填入条目）

| 目录 | 说明 |
|------|------|
| [boundary-conditions/](boundary-conditions/) | basic / constraint / derived |
| [thermophysical/](thermophysical/) | EOS、thermo、transport、混合物、固液表、化学、热输运 |
| [momentum-transport/](momentum-transport/) | laminar / RAS / LES / 相专用 |
| [multiphase/](multiphase/) | VoF / Euler / 漂移通量 / 相变 |
| [combustion-radiation/](combustion-radiation/) | 燃烧、化学、辐射、Xi（Phase 4） |
| [lagrangian/](lagrangian/) | 颗粒/云、MPPIC、薄膜耦合（Phase 4；film 索引在 `lagrangian/film.md`） |
| [fv-models-constraints/](fv-models-constraints/) | fvModels 与 fvConstraints（Phase 5） |
| [dynamic-mesh-waves-atm/](dynamic-mesh-waves-atm/) | 动网格、波、大气（Phase 5） |

### 机器清单

见 [`_inventory`/`](_inventory/)（类型名 + 源码路径）。覆盖缺口：[`_inventory/coverage-gaps.md`](_inventory/coverage-gaps.md)。

## 兼容性原则

单元格与导读中的「内建 / 可选 / 不可用」**只依据**：

- 模块头文件 `Description`
- 模块 [`Make/options`](../../applications/modules/) 链接库
- RTS / 教程实证

不确定处标 **待填** 或 **需验证**，不凭记忆断言。
