# 薄膜（film / isothermalFilm）与耦合

本手册将薄膜物理与区域耦合**统一放在 Lagrangian 目录**（与云/VoF 传输紧密），并由 [`film`](../solvers/film.md) / [`isothermalFilm`](../solvers/isothermalFilm.md) 求解器页链入。燃烧目录仅交叉链接至此。

---

# isothermalFilm / film 求解器物理

## 一句话
在薄膜区域网格上求解可压液膜流动；`film` 在等温膜基础上加能量/热输运。

## 适用条件（求解器 / 场 / 前提）
- **适用**: 多区域 `regionSolvers` 中 `film` 或 `isothermalFilm` 区域
- **前提**: 薄膜网格（通常由表面挤压）；`physicalProperties` / thermo；film 动量库 `filmCompressibleMomentumTransportModels`；`film` 另需 `filmThermophysicalTransportModels`
- **不适用**: 作为单区域替代完整 VoF（应用场景是壁面液膜）

## 字典示例


```c++
// `tutorials/multiRegion/film/VoFToFilm/constant/VoF/fvModels`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

VoFFilmTransfer
{
    type        VoFFilmTransfer;

    libs        ("libfilmVoFTransfer.so");

    filmPatch   film;
    phase       liquid;

    deltaFactorToFilm 0.9;
    alphaToFilm       0.86;

    transferRateCoeff 0.1;
}

// ************************************************************************* //
```

## 参数表
| 配置 | 含义 |
|------|------|
| 区域 thermo | 液膜密度、粘度、表面张力相关 |
| `momentumTransport` | film 可压动量输运 |
| 膜厚场等 | 由求解器创建/读取（见模块 Description） |

## 控制方程与关联式
浅水/液膜型质量与动量方程（模块实现）；`film` 增加能量方程与热输运。可选 fvModels 增强（源、云、辐射等——见各模块 Description）。

## 文献与源码依据
- `applications/modules/isothermalFilm/isothermalFilm.H`
- `applications/modules/film/film.H`

## 教程与模板
`tutorials/multiRegion/film/{cylinder,cylinderDripping,cylinderVoF,hotBoxes,splashPanel,VoFToFilm}`

## 注意事项
- 薄膜区域与流体区域通过 **mapped film patches** + fvModel 传输质量，而不是单一网格。

---

# filmCloudTransfer

## 一句话
液膜 ↔ 颗粒云 质量/动量交换（膜上积聚、滴落成云等）。

## 适用条件（求解器 / 场 / 前提）
- **适用**: film 区域 `fvModels`；流体区域通常同时有 `clouds`
- **前提**: 兼容的 parcel 云与 `CloudFilmTransfer` 编译单元

## 字典示例

```cpp
// tutorials/multiRegion/film/cylinder/constant/film/fvModels
filmCloudTransfer
{
    type    filmCloudTransfer;
}
```

流体侧：

```cpp
clouds
{
    type    clouds;
    libs    ("liblagrangianParcel.so");
}
```

## 参数表
基础条目可无额外系数；**弹出/滴落**由 `ejectionModel` 控制：

| ejectionModel | 一句话 |
|---------------|--------|
| `dripping` | 滴落 |
| `BrunDripping` | Brun 滴落关联 |
| `curvatureSeparation` | 曲率分离脱落 |

源码：`applications/modules/isothermalFilm/fvModels/filmCloudTransfer/ejectionModels/`。

## 控制方程与关联式
膜厚过大或满足脱落准则时，将质量转为 parcel 注入云；云撞击可向膜添加质量（`CloudFilmTransfer`）。

## 文献与源码依据
- `filmCloudTransfer/filmCloudTransfer.H`
- `ejectionModels/{dripping,BrunDripping,curvatureSeparation}/`

## 教程与模板
`cylinder`, `cylinderDripping`, `splashPanel`, `hotBoxes`, `cylinderVoF`（film 侧）

## 注意事项
- 只在一侧写 transfer、另一侧无云/无膜会破坏质量守恒预期。

---

# filmVoFTransfer / VoFFilmTransfer

## 一句话
液膜 ↔ VoF 相分数 质量传输（膜变厚并入 VoF，或 VoF 贴壁成膜）。

## 适用条件（求解器 / 场 / 前提）
- **适用**: 多区域 film + VoF（`incompressibleVoF` / `compressibleVoF` 等）
- **前提**: 两侧均配置对应 fvModel（film 侧 `filmVoFTransfer`，VoF 侧常有对称 `VoFFilmTransfer`）

## 字典示例

```cpp
// film 侧：cylinderVoF / VoFToFilm
filmVoFTransfer
{
    type    filmVoFTransfer;

    deltaFactorToVoF  0.15;  // 或 1.5（案例而异）
    alphaToVoF        0.15;  // 或 0.9
    transferRateCoeff 0.1;
}
```

## 参数表
| 入口 | 含义 | 量纲 |
|------|------|------|
| `deltaFactorToVoF` | 膜厚相对网格尺度阈值，超过则传向 VoF | 无量纲因子 |
| `alphaToVoF` | 传向 VoF 的相分数相关阈值 | 无量纲 |
| `transferRateCoeff` | 传输速率系数 | 1/s 量级（见实现） |

## 控制方程与关联式
当膜厚或邻接 VoF \(\alpha\) 满足阈值，按 `transferRateCoeff` 交换质量源，使膜与 VoF 表示一致过渡。

## 文献与源码依据
- `fvModels/filmVoFTransfer/filmVoFTransfer.H`
- `VoFFilmTransfer`.H`（VoF 侧配对）

## 教程与模板
- `multiRegion/film/cylinderVoF`（同时 filmCloud + filmVoF）
- `multiRegion/film/VoFToFilm`

## 注意事项
- 阈值在案例间差异大（0.15 vs 1.5），需按网格尺度标定。

---

# mapped film 边界

## mappedFilmSurface（patch 类型）

### 一句话
薄膜表面与流体/固体区域表面的映射耦合几何。

### 适用条件
多区域 film 案例的边界定义（`constant/*/polyMesh/boundary` 或 create 脚本）。

### 依据
`applications/modules/isothermalFilm/patches/mappedFilmSurface/`

### 教程
所有 `multiRegion/film/*`

### 注意事项
映射邻居区域名、patch 名必须配对。

---

## mappedFilmPressure（BC）

### 一句话
从邻居区域映射压力到薄膜边界。

### 适用条件
薄膜压力场边界。

### 字典示例
`type` mappedFilmPressure;`（见 BC 头文件）

### 依据
`derivedFvPatchFields/mappedFilmPressure/`

### 注意
完整 BC 目录属 Phase 2；此处仅耦合要点。

---

## filmSurfaceVelocity（BC）

### 一句话
薄膜表面速度边界（与气相剪切等耦合相关）。

### 依据
`derivedFvPatchFields/filmSurfaceVelocity/`

---

# 与燃烧/辐射交叉

- `film` Description 写明可选 radiation；激活方式同 [../combustion-radiation/radiation-fvModel.md](../combustion-radiation/radiation-fvModel.md)
- 薄膜**无**燃烧/化学包（矩阵：不可用）

---

## 覆盖计数

| 项目 | 状态 |
|------|------|
| isothermalFilm / film 导读联动 | ✓ |
| filmCloudTransfer | ✓ |
| ejectionModel ×3 | ✓ |
| filmVoFTransfer | ✓ |
| mappedFilmSurface / mappedFilmPressure / filmSurfaceVelocity | ✓ 索引 |
| 完整 film 动量/热输运模型条目 | **缺口** → Phase 1 动量/热输运或 Phase 5 |
