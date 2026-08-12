# VoF 专用 fvModel / 子模型 — 求解器有效性

证据：各模块目录下是否存在实现、`Make/options` / `Allwmake` 是否编译对应库。

| 模型 | incompressibleVoF | compressibleVoF | *MultiphaseVoF | 备注 |
|------|-------------------|-----------------|----------------|------|
| 界面压缩格式（`interfaceCompression`/`PLIC`/`MPLIC`…） | 是 | 是 | 是（链 `interfaceCompression`） | `fvSchemes` |
| `interfaceProperties` 表面张力/接触角 | 是 | 经 `compressibleInterfaceProperties` | 视模块 | 可压多用 `liquidProperties` σ |
| `VoFCavitation` | **是**（不可压空化库） | **是**（可压空化库，含 `Saito`） | **否**（无模块内实现） | 同名不同命名空间 |
| `VoFTurbulenceDamping` | 是 | 是 | 否* | *未见 MultiphaseVoF 模块内文件 |
| `VoFClouds` | **否** | **是**（`libVoFClouds`） | 否 | 仅 compressibleVoF/Allwmake |
| `VoFSolidificationMelting` | **否** | **是**（`libVoFSolidificationMelting`） | 否 | 仅 compressibleVoF |
| 通用 `solidificationMelting` | 可选（`libfvModels`） | 可选 | 可选 | 非 VoF 专用；见 [../phase-change/](../phase-change/) |

## 空化模型矩阵

| 空化 `model` | 不可压库 | 可压库 |
|--------------|----------|--------|
| `Kunz` | 有 | 有 |
| `Merkle` | 有 | 有 |
| `SchnerrSauer` | 有 | 有 |
| `Saito` | **无** | 有 |

## 注意事项
- 不要在 `incompressibleVoF` 案例中配置仅存在于 `compressibleVoF` 的 `VoFClouds` / `VoFSolidificationMelting`。
- `VoFCavitation` 的 `model` 必须与该求解器链接的空化库一致（不可压不能选 `Saito`）。
