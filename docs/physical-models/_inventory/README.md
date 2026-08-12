# 机器生成模型清单（Phase 0）

由源码中 `addToRunTimeSelectionTable` / `makePatch*` / `makeThermo` / `makeRASModel` 等宏及包目录检索生成，供 Phase 1–5 **逐条撰写**时对照，避免凭记忆漏模型。

| 文件 | 内容 | 条目数 |
|------|------|--------|
| [rts-fvPatchFields.md](rts-fvPatchFields.md) | 边界条件（含壁面函数/辐射/大气/波/模块本地） | 299 |
| [rts-thermos.md](rts-thermos.md) | 热物性部件、Properties、`*Thermos.C`、RTS | 168 |
| [rts-thermophysicalTransport.md](rts-thermophysicalTransport.md) | 热输运模型 | 49 |
| [rts-physicalProperties.md](rts-physicalProperties.md) | 不可压物性 / 漂移通量粘度与弥散 | 25 |
| [rts-momentumTransport.md](rts-momentumTransport.md) | laminar/RAS/LES/相专用 | 113 |
| [rts-fvModels.md](rts-fvModels.md) | fvModels | 88 |
| [rts-fvConstraints.md](rts-fvConstraints.md) | fvConstraints | 15 |
| [rts-multiphase-interfacial.md](rts-multiphase-interfacial.md) | multiphaseEuler 界面/直径/PBM | 99 |
| [rts-combustion-radiation.md](rts-combustion-radiation.md) | 燃烧/化学/辐射/Xi | 163 |
| [rts-lagrangian-submodels.md](rts-lagrangian-submodels.md) | Lagrangian 子模型 | 164 |
| [rts-dynamic-mesh-waves-atm.md](rts-dynamic-mesh-waves-atm.md) | 动网格/波/大气 | 82 |
| [coverage-gaps.md](coverage-gaps.md) | **Phase 5** inventory ↔ 手册页交叉缺口 | （生成） |

求解器导读页： **24** 个模块。

Phase 5 域正文：[`../fv-models-constraints/`](../fv-models-constraints/)、[`../dynamic-mesh-waves-atm/`](../dynamic-mesh-waves-atm/)。