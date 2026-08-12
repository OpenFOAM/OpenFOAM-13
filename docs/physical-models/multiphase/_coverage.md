# Phase 3 覆盖报告

## 计数

| 区域 | 模型页（不含各 README） | 含 README 等总 `.md` |
|------|-------------------------|----------------------|
| VoF | 29 | 35 |
| Euler（含 phase-models） | 100 | 116 |
| 漂移通量 | 13 | 17 |
| 相变/沸腾 | 24 | 26 |
| **multiphase/ 合计** | — | **196** |

八节模板抽检（排除 README / `_coverage` / 索引页）：**incomplete = 0**，**stub/TODO = 0**。

## vs `_inventory/rts-multiphase-interfacial.md`

| 指标 | 值 |
|------|----|
| Inventory 行数 | 99 |
| 已有对应 `*.md` | **99/99** |
| 缺口 | **0** |

## 额外覆盖（inventory 之外，源码 RTS 对账）

| 范围 | RTS 类型数 | 手册覆盖 | 备注 |
|------|------------|----------|------|
| 界面压缩（`defineTypeName`，非 addToRTS 宏） | 6 | 6 页 | `interfaceCompression`/`PLIC`/`PLICU`/`MPLIC`/`MPLICU`/`noInterfaceCompression` |
| 表面张力 | 3 | 3 | `constant`/`temperatureDependent` + 可压库 `liquidProperties` |
| 接触角 | 4 + BC | 5 | 4 模型 + `contactAngle` patch |
| 不可压空化 | 3 | 3（`-incompressible` 页） | Kunz/Merkle/SchnerrSauer |
| 可压空化 | 4 | 4（`-compressible`；含 `Saito`） | |
| VoF fvModels | 4 | 6 页 | Cavitation/Damping 按求解器拆分 |
| 漂移通量 relativeVelocity | 3 | 3 | |
| packingDispersion | 5 | 5 | |
| mixtureViscosity | 5 | 5 | |
| Euler 模块 fvModels + wallBoiling 子模型 | 21（含子模型） | 有对应页 | 见 `phase-change/` |
| 通用相变/凝固/传质 | 3 | 3 | `coefficientPhaseChange`/`solidificationMelting`/`coefficientMassTransfer` |
| phaseModel 注册名 | 8 | **汇总页** [`euler/phase-models.md`](euler/phase-models.md) | 故意不拆 8 个重复文件 |

## 求解器有效性要点（证据见 `vof/solver-validity.md`）

| 模型 | incompressibleVoF | compressibleVoF | *MultiphaseVoF |
|------|-------------------|-----------------|----------------|
| `VoFCavitation` | 是（不可压空化库） | 是（可压库，含 Saito） | 否 |
| `VoFTurbulenceDamping` | 是 | 是 | 否* |
| `VoFClouds` | 否 | 是 | 否 |
| `VoFSolidificationMelting` | 否 | 是 | 否 |

## 求解器导读 / 矩阵

- 已轻量回填：`solvers/incompressibleVoF.md`、`compressibleVoF.md`、`*MultiphaseVoF.md`、`multiphaseEuler.md`、`incompressibleDriftFlux.md`
- [`01-solver-matrix.md`](../01-solver-matrix.md) 多相相关单元格已链到本目录

## 已知文档缺口（质控，非 inventory 漏项）

1. 多数 Euler 界面模型头文件 Description 极短；部分群体平衡页的公式从 Doxygen 转义不完整（如 `Luo.md` 中希腊字母丢失），需对照 `.C`/文献补全——**不影响类型覆盖计数**。
2. 通用相变 fvModel 与单相 `fluid`/`incompressibleFluid` 的完整兼容表留给 Phase 5 / `fv-models-constraints/`。
3. `relativeVelocity` 等个别模型教程链接可能为空（字典关键字扫描未命中）。
4. MultiphaseVoF 未移植两相模块级 `VoFCavitation`：**源码无实现**（非文档遗漏）。
5. `phaseModel` 8 类型仅汇总页、无一对一文件（有意为之）。

## 结论

**Phase 3 交付完成**：VoF / Euler / 漂移通量 / 相变全谱已落盘；相对 `rts-multiphase-interfacial.md` **0 缺口**；VoF/漂移/相变扩展 RTS 亦已对账。
