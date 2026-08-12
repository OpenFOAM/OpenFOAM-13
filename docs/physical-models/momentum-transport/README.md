# 动量输运（湍流 / 层流）

配置入口：`constant/momentumTransport`（多相时常为每相一份或混合物一份）。通过 `simulationType` 选择 **laminar / RAS / LES**，再在对应块里选 `model`。

清单：[`../_inventory/rts-momentumTransport.md`](../_inventory/rts-momentumTransport.md)。

## 本目录结构

| 子目录 | 内容 |
|--------|------|
| [laminar/](laminar/) | Stokes、广义牛顿、粘弹性及粘度子模型 |
| [RAS/](RAS/) | RANS（含仅不可压额外模型） |
| [LES/](LES/) | LES/DES、`LESdelta`、`LESfilter` |
| [phase-specific/](phase-specific/) | `multiphaseEuler` 相模型、动力学理论粘度、液膜 |

---

## 字典骨架

```c++
// tutorials/incompressibleFluid/pitzDaily/constant/momentumTransport
simulationType RAS;

RAS
{
    model           kEpsilon;
    turbulence      on;
}
```

层流：

```c++
simulationType laminar;
laminar
{
    model           Stokes;
}
```

LES 另需 `delta`（及动态模型的 `filter`）：

```c++
simulationType LES;
LES
{
    model           SpalartAllmarasDDES;
    turbulence      on;
    delta           cubeRootVol;
    // filter        simple;   // 动态模型
}
```

---

## 注册差异：incompressible / compressible / phase* / film

工厂源文件决定**哪些 `model` 名可用**：

| 库 / 工厂 | α 模板 | ρ 模板 | 层流 | RAS | LES |
|-----------|---------|--------|------|-----|-----|
| [`incompressibleMomentumTransportModels`.C`](../../src/MomentumTransportModels/incompressible/incompressibleMomentumTransportModels.C) | `geometricOneField` | `geometricOneField` | Stokes, generalisedNewtonian, lambdaThixotropic, Maxwell, Giesekus, PTT | SA, kε 族, kω 族, v2f, LRR, SSG + **仅不可压**额外模型 | Smagorinsky, WALE, kEqn, dynamic*, DES 族, Deardorff |
| [`compressibleMomentumTransportModels`.C`](../../src/MomentumTransportModels/compressible/compressibleMomentumTransportModels.C) | `geometricOneField` | `volScalarField` | 同左 | 同上 **+ `buoyantKEpsilon`**（无仅不可压那批） | 同左 |
| [`phaseIncompressibleMomentumTransportModels`.C`](../../src/MomentumTransportModels/phaseIncompressible/phaseIncompressibleMomentumTransportModels.C) | `volScalarField` | `geometricOneField` | 同层流全集 | **仅** `kEpsilon`, `kOmegaSST` | **仅** `Smagorinsky`, `kEqn` |
| [`phaseCompressibleMomentumTransportModels`.C`](../../src/MomentumTransportModels/phaseCompressible/phaseCompressibleMomentumTransportModels.C) | `volScalarField` | `volScalarField` | 同层流全集 | `kEpsilon`, `RNGkEpsilon`, `kOmegaSST` | `Smagorinsky`, `kEqn` |
| [`filmCompressibleMomentumTransportModels`.C`](../../applications/modules/isothermalFilm/filmCompressibleMomentumTransportModels/filmCompressibleMomentumTransportModels.C) | （液膜） | （液膜） | Stokes + 广义牛顿/触变/粘弹性 | **无** | **无** |
| [`multiphaseEuler/.../momentumTransportModels.C`](../../applications/modules/multiphaseEuler/momentumTransportModels/momentumTransportModels.C) | 相 | 相 | 继承相可压/不可压 + **专用** Lahey/Niceno/Sato/… | 专用 RAS/LES | 专用 |

### 仅不可压 RAS（目录 `incompressible/RAS/`）

`LamBremhorstKE`, `LienCubicKE`, `LienLeschziner`, `ShihQuadraticKE`, `kkLOmega`, `qZeta` — **不会**出现在 compressible 工厂中。

### 仅可压 RAS

`buoyantKEpsilon` — 仅 `compressibleMomentumTransportModels`.C`。

### 求解器选用哪张表

| 求解器 | 典型库 |
|--------|--------|
| `incompressibleFluid` | incompressible |
| `isothermalFluid`, `fluid`, `shockFluid`, `multicomponentFluid`, `XiFluid` | compressible |
| `incompressibleVoF`, `incompressibleMultiphaseVoF`, `incompressibleDenseParticleFluid` | incompressible + **phaseIncompressible**（相） |
| `compressibleVoF` | compressible + **phaseCompressible** |
| `compressibleMultiphaseVoF` | compressible + phaseIncompressible（模块 options） |
| `multiphaseEuler` | multiphaseEuler 专用 + kineticTheory 子模型 |
| `isothermalFilm` / `film` | filmCompressible（仅 laminar） |
| `incompressibleDriftFlux` | 链接 compressible 动量库（见模块 options） |

---

## 模型索引（核心）

### Laminar

见 [laminar/](laminar/)：`Stokes`, `generalisedNewtonian`（+ BirdCarreau/powerLaw/…）, `lambdaThixotropic`, `Maxwell`, `Giesekus`, `PTT`。

### RAS

见 [RAS/](RAS/)：共用模型 + 仅不可压额外模型 + `buoyantKEpsilon`。

### LES / DES

见 [LES/](LES/)：SGS 模型、`cubeRootVolDelta` 等 delta、`simpleFilter` 等 filter。

### 相专用

见 [phase-specific/](phase-specific/)。

---

## 与热输运的耦合

需要能量/组分方程时，`thermophysicalTransport` 的 `laminar`/`RAS`/`LES` 分支应与本字典 `simulationType` **一致**，否则构造失败或物理解释错误。见 [`../thermophysical/thermophysical-transport/`](../thermophysical/thermophysical-transport/)。

## 注意事项

1. 在 `phaseIncompressible` 案例中选 `kOmega`（非 SST）会 **unknown model**——该名未注册。
2. film 区域选 `kEpsilon` 同样未注册。
3. LES 忘记 `delta` 子字典会导致构造错误。
4. 壁面函数属于边界条件（Phase 2），但 `nut`/`epsilon`/`omega` 场必须与所选 RAS/LES 匹配。

## 导航

- [`../01-solver-matrix.md`](../01-solver-matrix.md) · [`../README.md`](../README.md) · [`../00-conventions.md`](../00-conventions.md)
