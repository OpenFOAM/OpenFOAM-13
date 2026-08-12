# 多相与相变（Phase 3）

OpenFOAM-13 多相物理模型手册：VoF 家族、`multiphaseEuler` 界面/群体平衡、漂移通量、通用/模块相变。

## 子目录

| 子目录 | 内容 |
|--------|------|
| [vof/](vof/) | 界面压缩、表面张力、接触角、空化、VoF 混合物、VoF fvModels |
| [euler/](euler/) | 相模型、直径、blending、界面力/传热传质、群体平衡 |
| [drift-flux/](drift-flux/) | 相对速度 / 堆积弥散 / 混合物粘度 |
| [phase-change/](phase-change/) | 通用相变与 Euler 沸腾/空化等 fvModels |

## 求解器入口

- [incompressibleVoF](../solvers/incompressibleVoF.md) · [compressibleVoF](../solvers/compressibleVoF.md)
- [incompressibleMultiphaseVoF](../solvers/incompressibleMultiphaseVoF.md) · [compressibleMultiphaseVoF](../solvers/compressibleMultiphaseVoF.md)
- [multiphaseEuler](../solvers/multiphaseEuler.md) · [incompressibleDriftFlux](../solvers/incompressibleDriftFlux.md)

## 清单与覆盖

- RTS 界面清单：[`../_inventory/rts-multiphase-interfacial.md`](../_inventory/rts-multiphase-interfacial.md)
- 本 Phase 覆盖报告：[`_coverage`.md`](_coverage.md)（inventory **99/99**；另含 VoF/漂移通量/相变扩展）
- 矩阵：[`../01-solver-matrix.md`](../01-solver-matrix.md)

## 写作约定

条目遵循 [`../00-conventions.md`](../00-conventions.md) 八节模板；方程/Usage 优先摘自类头 `Description`。
