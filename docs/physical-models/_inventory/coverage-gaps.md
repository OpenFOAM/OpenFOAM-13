# Inventory 覆盖缺口（Phase 5 交叉总检）

> 机器对照 `_inventory/*.md` 类型名与 `docs/physical-models/**/*.md` 文件名（stem）。
> **孤立** = inventory 有类型名，手册尚无同名页（或明显别名页）。

扫描到手册 Markdown stem 数： **765**。

## fvModels（`rts-fvModels.md`）

- Inventory 唯一类型： **48**
- 已有同名/别名页： **48**
- 仍缺页： **0**

（无缺口）

## fvConstraints（`rts-fvConstraints.md`）

- Inventory 唯一类型： **9**
- 已有同名/别名页： **9**
- 仍缺页： **0**

（无缺口）

## 动网格/波/大气（`rts-dynamic-mesh-waves-atm.md`）

- Inventory 唯一类型： **75**
- 已有同名/别名页： **75**
- 仍缺页： **0**

（无缺口）

## 其他 inventory（摘要）

| Inventory | 唯一类型 | 有同名/别名页 | 缺页（约） | 负责 Phase |
|-----------|----------|---------------|------------|------------|
| `rts-fvPatchFields.md` | 191 | 75 | 116 | 2 |
| `rts-thermos.md` | 106 | ~106（含别名页） | **0** | 1 |
| `rts-momentumTransport.md` | 57 | ~57 | **0** | 1 |
| `rts-thermophysicalTransport.md` | 25 | ~25 | **0** | 1 |
| `rts-physicalProperties.md` | 16 | ~16 | **0** | 1 |
| `rts-multiphase-interfacial.md` | 97 | 97 | 0 | 3 |
| `rts-combustion-radiation.md` | 46 | catalog | 文内 **46/46**（见域 README） | 4 |
| `rts-lagrangian-submodels.md` | 83 | catalog | 文内全覆盖 + MD 仅索引（见域 README） | 4 |

说明：stem 精确匹配会因 `liquidProperties-H2O`、`functionObject-*`、`kineticTheoryViscosity-*` 等别名误报；Phase 1 以别名规则复核为 **0 缺页**。Phase 4 以 [`../combustion-radiation/README.md`](../combustion-radiation/README.md)、[`../lagrangian/README.md`](../lagrangian/README.md) 为准。

## Phase 1（热物性 / 动量 / 热输运）结论

- 目录：[`../thermophysical/`](../thermophysical/)（含 `thermoType` 合法组合表）、[`../momentum-transport/`](../momentum-transport/)（含 incompressible/compressible/phase*/film 注册差异）。
- 化学支撑：求解器 `ode`/`EulerImplicit`/`none`、降维 DRG/DAC/DRGEP/PFA/EFA、表化 ISAT；反应速率形式全谱仍属 Phase 4。
- **质量缺口（不阻塞）**：部分稀有 RAS/LES/delta/filter 无官方教程字面配置；`liquidProperties-*` 页为短页（预置 NSRDS 库）。

## Phase 4（燃烧 / 辐射 / Lagrangian / 薄膜）结论

| Inventory | 唯一非 directory | 文内可检索覆盖 | 有意不成方程页 |
|-----------|------------------|----------------|----------------|
| `rts-combustion-radiation.md` | 46 | **46/46** | directory / ISAT 实现树 |
| `rts-lagrangian-submodels.md` | 83 | **83/83**（含 MD/Patch/FO 索引表） | MD 势函数无独立方程页 |

入口：[`../combustion-radiation/`](../combustion-radiation/) · [`../lagrangian/`](../lagrangian/)（薄膜 [`../lagrangian/film.md`](../lagrangian/film.md)）。

**已知细缺口（不阻塞）**：FSD/zoneCombustion/wideBand 等缺完整教程字典副本；新 Lagrangian 官方 tutorials 少；`distortedSphereDrag`/`DenseDrag` 默认宏未注册；film 动量/热输运细节归 Phase 1。

## Phase 5 结论

- **通用 fvModels / fvConstraints / 孔隙 / 转子 / interRegion / waves fvModels / radiation·clouds 包装器**：条目齐全。
- **动网格 movers / topo / distributor / stitcher / motionSolver / solidBody / MRF / pointDisplacement / 波浪 / 大气**：条目齐全。
- **sixDoF 约束·阻尼·关节·刚体·监视 FO、rotorDisk blade/profile/trim、interRegion HTC**：已补独立页（见 `sixDoF/`、`rotor-propeller/`、`inter-region/heatTransferCoefficientModels/`）。
- **模块专用 fvModels**（VoF/Euler/Xi/film）：`module-specific/` 入口；方程细节交叉 Phase 3/4。
- **Phase 5 主责 inventory 孤立类型：0**。

## 建议后续（非 Phase 5 阻塞）

1. Phase 2：继续补 `rts-fvPatchFields` 缺页（约 116）。
2. Phase 1：thermos / TTM 别名或补页，降低 stem 误报。
3. 与 Phase 2 互链：大气/波浪/MRF BC 在 `boundary-conditions/` 与本域保持双向链接。
