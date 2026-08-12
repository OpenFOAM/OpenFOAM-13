# Collision / StochasticCollision / SurfaceFilm / cloudFunctions

经典 parcel 子模型中与 **碰撞、喷雾随机碰撞、表面膜开关、云内后处理** 相关的条目。宏：`makeParcelCollisionModels`.H`、`makeSprayParcelStochasticCollisionModels`.H`、`makeParcelStochasticCollisionModels`.H`、`makeParcelSurfaceFilmModels`.H`、`makeParcelCloudFunctionObjects`.H`。

---

# CollisionModel（确定性颗粒碰撞）

## 适用条件（求解器 / 场 / 前提）
- **适用**: 动量 parcel 云（如 `incompressibleFluid` 颗粒教程、`Goldschmidt`）
- **前提**: `subModels`.collisionModel`；与 MPPIC 的 packing 路径不同——二选一思路，勿混用语义

## 字典示例

摘录 `tutorials/incompressibleFluid/mixerVesselHorizontal2DParticles/constant/cloudProperties`：

```cpp
collisionModel pairCollision;

pairCollisionCoeffs
{
    maxInteractionDistance  0.0025;
    writeReferredParticleCloud no;

    pairModel pairSpringSliderDashpot;
    pairSpringSliderDashpotCoeffs
    {
        useEquivalentSize   no;
        alpha               0.02;
        b                   1.5;
        mu                  0.10;
        cohesionEnergyDensity 0;
        collisionResolutionSteps 12;
    }

    wallModel wallSpringSliderDashpot;
    wallSpringSliderDashpotCoeffs
    {
        useEquivalentSize no;
        collisionResolutionSteps 12;
        youngsModulus   1e8;
        poissonsRatio   0.23;
        alpha           0.01;
        b               1.5;
        mu              0.09;
        cohesionEnergyDensity 0;
    }

    U     U;
}
```

关闭：`collisionModel` none;`（`NoCollision`，TypeName `none`）。

## 类型表

| TypeName（字典） | 类 / 角色 | 一句话 |
|------------------|-----------|--------|
| `none` | `NoCollision` | 关闭碰撞 |
| `pairCollision` | `PairCollision` | 成对碰撞框架 |
| `pairSpringSliderDashpot` | `PairSpringSliderDashpot` | 颗粒–颗粒弹簧滑块 |
| `wallSpringSliderDashpot` | `WallSpringSliderDashpot` | 颗粒–壁面弹簧滑块 |
| `wallLocalSpringSliderDashpot` | `WallLocalSpringSliderDashpot` | 按 patch 局部壁面弹簧参数 |

## 参数表（常用）

| 入口 | 含义 | 量纲/说明 |
|------|------|-----------|
| `maxInteractionDistance` | 搜索邻域半径 | m |
| `youngsModulus` / `poissonsRatio` | 接触刚度材料 | Pa / — |
| `alpha`,`b`,`mu` | 阻尼/非线性/摩擦 | 见 `.H` |
| `collisionResolutionSteps` | 接触子步 | — |

## 控制方程与关联式
软球（spring–slider–dashpot）接触力与力矩，更新颗粒速度/角速度；壁面模型对称处理 patch 法向。

## 文献与源码依据
- `src/lagrangian/parcel/submodels/Momentum/CollisionModel/`
- 宏：`makeParcelCollisionModels`.H`

## 教程与模板
- `incompressibleFluid/mixerVesselHorizontal2DParticles`
- `incompressibleFluid/hopperParticles/*`
- `incompressibleDenseParticleFluid/Goldschmidt`（`pairCollision`）

## 注意事项
- 字典类型名多为 **camelCase 短名**（`pairCollision`），与类名 `PairCollision` 不同。
- 稠密流化床更常用 **MPPIC**（[mppic.md](mppic.md)），而非全量 pair 碰撞。

---

# StochasticCollisionModel

## 一句话
统计意义上的液滴/颗粒碰撞（喷雾 coalescence 等），非软球接触。

## 适用条件
- **基础宏** `makeParcelStochasticCollisionModels`：仅 `none`
- **喷雾宏** `makeSprayParcelStochasticCollisionModels`：`none` / `ORourke` / `trajectory`
- **煤粉** 另有 `suppressionCollision`（`SuppressionCollision`）

## 字典示例

多数教程关闭：

```cpp
stochasticCollisionModel none;
```

喷雾可选（推断自源码 TypeName；教程多关）：

```cpp
stochasticCollisionModel ORourke;
// 或 trajectory
// ORourkeCoeffs / trajectoryCoeffs 见对应 .H Usage
```

## 类型表

| TypeName | 类 | 一句话 |
|----------|-----|--------|
| `none` | `NoStochasticCollision` | 关闭 |
| `ORourke` | `ORourkeCollision` | O'Rourke 液滴碰撞 |
| `trajectory` | `TrajectoryCollision` | 轨迹相交碰撞 |
| `suppressionCollision` | `SuppressionCollision` | 反应多相抑制碰撞 |

## 控制方程与关联式
基于碰撞频率/轨迹判据改变粒径与速度（聚并或反弹，模型相关）。

## 文献与源码依据
`StochasticCollision`/`（Momentum / Spray / ReactingMultiphase）

## 教程与模板
`aachenBomb`、`verticalChannel`*` 等多为 `none`；开启时以喷雾案例与源码 Usage 为准。

## 注意事项
- 与 `collisionModel` pairCollision` **不是同一开关**。

---

# SurfaceFilmModel

## 一句话
经典 parcel 侧「表面膜」子模型开关；与区域 `film`/`filmCloudTransfer` 耦合时常为 `none`，传输由 fvModel 承担。

## 适用条件
多数云宏注册 `NoSurfaceFilm`（TypeName `none`）。

## 字典示例

```cpp
surfaceFilmModel none;
```

## 类型表

| TypeName | 类 | 一句话 |
|----------|-----|--------|
| `none` | `NoSurfaceFilm` | 关闭（默认宏唯一类型） |

## 控制方程与关联式
无（关闭）。区域薄膜交换见 [film.md](film.md)。

## 文献与源码依据
`makeParcelSurfaceFilmModels`.H`；`SurfaceFilmModel/NoSurfaceFilm/`

## 注意事项
- 不要与 `filmCloudTransfer` fvModel 混淆：后者在 film 区域配置。

---

# cloudFunctions（云内 CloudFunctionObject）

## 一句话
写在 `cloudProperties` 顶层 `cloudFunctions` { ... }` 内的后处理/采样，**不是** `system/functions` 的全域 functionObject（后者见新框架 inventory 中的 `cloudMass` 等）。

## 适用条件
任意 parcel 云；宏 `makeParcelCloudFunctionObjects`.H`。

## 字典示例

摘录 `tutorials/multicomponentFluid/filter/constant/cloudProperties`：

```cpp
cloudFunctions
{
    patchPostProcessing1
    {
        type            patchPostProcessing;
        maxStoredParcels 20;
        patches         ( /* patch names */ );
    }

    facePostProcessing1
    {
        type            facePostProcessing;
        surfaceFormat   vtk;
        resetOnWrite    no;
        log             yes;
        faceZones       ( /* zones */ );
    }
}
```

空块 `cloudFunctions` {}` 亦常见。

## 类型表（TypeName / 类名）

| TypeName | 类名 | 一句话 |
|----------|------|--------|
| `facePostProcessing` | `FacePostProcessing` | 面区通量/撞击后处理 |
| `patchPostProcessing` | `PatchPostProcessing` | 指定 patch 上 parcel 记录 |
| `patchCollisionDensity` | `PatchCollisionDensity` | patch 碰撞密度 |
| `particleCollector` | `ParticleCollector` | 收集器 |
| `particleErosion` | `ParticleErosion` | 侵蚀 |
| `particleTracks` | `ParticleTracks` | 轨迹 |
| `particleTrap` | `ParticleTrap` | 陷阱捕获 |
| `relativeVelocity` | `RelativeVelocity` | 相对速度场 |
| `sizeDistribution` | `SizeDistribution` | 粒径分布 |
| `volumeFraction` | `VolumeFraction` | 颗粒体积分数场 |
| `massFlux` / `numberFlux` / `volumeFlux` | `Flux` 模板特化 | 通量 |

## 参数表
各 `type` 子字典专用；见对应 `.H` Usage。

## 控制方程与关联式
诊断/采样，不改变控制方程（除少数可移除粒子的 trap/collector 行为）。

## 文献与源码依据
`submodels/CloudFunctionObjects/`；`makeParcelCloudFunctionObjects`.H`

## 教程与模板
`filter`、`verticalChannel`*`、`aachenBomb`、多数 denseParticle 案例。

## 注意事项
- Inventory 中 `cloudMass`、`cloudAge`、`cloudVolumeFlux` 等属 **系统 functionObject**（新/镜像 Lagrangian 库），与本表 `cloudFunctions` 不同入口。

---

## 覆盖计数

| 族 | 宏/源码类型 | 本页 |
|----|-------------|------|
| CollisionModel + Pair/Wall | 5 可配置 TypeName | ✓ |
| StochasticCollision | none + ORourke + trajectory + suppression | ✓ |
| SurfaceFilm | `none` only | ✓ |
| CloudFunctionObject | 宏列出类型 | ✓ |

**缺口**: `SuppressionCollision` 缺官方端到端教程字典副本；系数以源码为准。
