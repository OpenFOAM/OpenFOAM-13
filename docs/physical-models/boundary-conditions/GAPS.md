# Phase 2 边界条件 — 覆盖与缺口

- Inventory 行：299
- 去重文档页：199
- `fvPatchField`：173
- 非 fvPatchField（Lagrangian/网格 patch）：26
- 缺 Description 头文件：4
- 无 tutorials/caseDicts `type` 命中：86

## 未建页（相对 inventory 短名）

无（全覆盖）

## 说明

- `no`-tutorial-hit` 不等于不可用，仅表示自动检索未在教程场文件中找到该 `type`。
- 能量类 BC（`fixedEnergy` 等）通常由 thermo 从 `T` 边界映射生成，教程中可能不显式写出。
- film `*PolyPatch`/`*FvPatch`/`*PointPatch` 与 LagrangianPatch 为关联类型，非 volField BC。
