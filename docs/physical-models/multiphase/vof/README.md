# VoF 家族

不可压/可压、两相/多相 VoF：界面压缩、表面张力、接触角、空化、混合物与模块专用 fvModels。

## 先读

| 文档 | 用途 |
|------|------|
| [mixtures.md](mixtures.md) | 两相/多相混合物与物性配置 |
| [solver-validity.md](solver-validity.md) | **VoF fvModel 求解器有效性**（compressibleVoF vs incompressibleVoF 等） |

## 子目录

| 目录 | 内容 |
|------|------|
| [interface-compression/](interface-compression/) | `interfaceCompression` / `PLIC` / `MPLIC`…（`fvSchemes`） |
| [surface-tension/](surface-tension/) | `constant` / `temperatureDependent` / `liquidProperties` |
| [contact-angle/](contact-angle/) | 接触角模型 + `contactAngle` BC |
| [cavitation/](cavitation/) | 不可压 vs 可压空化（含仅可压的 `Saito`） |
| [fvModels/](fvModels/) | `VoFCavitation` / `VoFTurbulenceDamping` / `VoFClouds` / `VoFSolidificationMelting` |

## 相关求解器

- [incompressibleVoF](../../solvers/incompressibleVoF.md) · [compressibleVoF](../../solvers/compressibleVoF.md)
- [incompressibleMultiphaseVoF](../../solvers/incompressibleMultiphaseVoF.md) · [compressibleMultiphaseVoF](../../solvers/compressibleMultiphaseVoF.md)

## 导航

- [多相索引](../README.md) · [覆盖报告](../_coverage.md) · [矩阵](../../01-solver-matrix.md)
