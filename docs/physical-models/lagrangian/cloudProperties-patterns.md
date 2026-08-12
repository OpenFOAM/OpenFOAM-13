# cloudProperties 配置模式

## 一句话
经典 parcel 云的主字典：云类型、数值、物性常数与全部 subModels。

## 适用条件（求解器 / 场 / 前提）
任何使用 `liblagrangianParcel` 云的案例；稠密颗粒与 `clouds` fvModel 共用此模式。

## 字典示例

权威骨架：`etc/caseDicts/solvers/lagrangian/cloudProperties`。精简：

```cpp
type            cloud;
// 或 reactingCloud, sprayCloud, MPPICCloud, ...

solution
{
    transient       true;
    coupled         true;
    cellValueSourceCorrection off;

    sourceTerms
    {
        schemes
        {
            U               semiImplicit 1;
        }
    }

    integrationSchemes
    {
        U               Euler;   // 或 analytical
    }

    interpolationSchemes
    {
        rho             cell;
        U               cellPoint;
        mu              cell;
    }
}

constantProperties
{
    rho0            1000;
}

subModels
{
    particleForces
    {
        sphereDrag;
        // gravity;
    }

    injectionModels
    {
        model1
        {
            type             patchInjection;
            patchName        inlet;
            SOI              0;
            duration         1;
            massTotal        1e-3;           // [kg]
            parcelsPerSecond 1000;           // [1/s]
            flowRateProfile  constant 1;
            U0               (1 0 0);        // [m/s]
            uniformParcelSize volume;
            sizeDistribution
            {
                type         fixedValue;
                fixedValueDistribution { value 1e-3; }  // [m]
            }
        }
    }

    dispersionModel none; // 或 stochasticDispersionRAS
    patchInteractionModel localInteraction;

    localInteractionCoeffs
    {
        patches
        (
            "(wall|.*Wall)"
            {
                type        rebound;
                e           0.97;            // [-] 恢复系数
                mu          0.09;            // [-] 摩擦
            }
        );
    }

    stochasticCollisionModel none;
    surfaceFilmModel none;
}

cloudFunctions
{}
```

MPPIC 示例见 `tutorials/incompressibleDenseParticleFluid/GoldschmidtMPPIC/constant/cloudProperties`（`type` MPPICCloud` + packing/isotropy）。

## 参数表（顶层）

| 入口 | 含义 |
|------|------|
| `type` | 云类型：`cloud` / `thermoCloud` / `reactingCloud` / `reactingMultiphaseCloud` / `sprayCloud` / `MPPICCloud` 等（以注册为准） |
| `solution`.coupled` | 是否反馈欧拉相 |
| `solution`.transient` | 瞬态跟踪 |
| `constantProperties`.rho0` | 颗粒密度等常数 |
| `subModels`.*` | 见各专题页 |
| `cloudFunctions` | 云内后处理函数对象 |

## 控制方程与关联式
颗粒运动：\(m\mathrm{d}\mathbf{u}/\mathrm{d}t=\sum\mathbf{F}\)；积分方案 `Euler`/`analytical`。组分/能量/蒸发依云类型启用对应子模型。

## 文献与源码依据
- `etc/caseDicts/solvers/lagrangian/cloudProperties`
- `src/Lagrangian/parcel/` 云与 `parcels/include/make*.H`

## 教程与模板
见 [README.md](README.md) 教程表；另 `GoldschmidtMPPIC`、`aachenBomb`。

## 注意事项
- `interpolationSchemes` 场名须与载体相场一致（多相时可能是 `U`.air`）。
- `type` 决定可用子模型集合（喷雾才有 breakup 等）。

---

## 常见云 type 与子模型启用关系

| cloud type | 典型额外 subModels |
|------------|-------------------|
| `cloud` / kinematic | forces, injection, dispersion, patchInteraction；可选 `collisionModel` |
| thermo | + heatTransfer；可选 `BrownianMotion` 力 |
| reacting | + composition, phaseChange |
| reactingMultiphase | + devolatilisation, surfaceReaction |
| spray | + atomisation, breakup；可选 `stochasticCollisionModel` |
| MPPICCloud | + packing, damping, isotropy |

顶层 `cloudFunctions` { ... }` 见 [parcel-collision-cloudFunctions.md](parcel-collision-cloudFunctions.md)。
