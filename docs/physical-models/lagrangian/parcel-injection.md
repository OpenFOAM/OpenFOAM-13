# InjectionModel（注入）

宏注册见 `src/Lagrangian/parcel/parcels/include/make*ParcelInjectionModels.H`。

---

## 共用适用条件
- **适用**: 所有 parcel 云；在 `subModels`.injectionModels` 下可挂多个命名模型
- **场**: 向云注入粒径、速度、质量/数量

---

# patchInjection

## 一句话
从边界 patch 按质量流率/数量注入。

## 适用条件（求解器 / 场 / 前提）
任意载体相；需合法 `patchName`。

## 字典示例

```cpp
model1
{
    type             patchInjection;
    patchName        inlet;
    SOI              0;
    duration         0.1;
    parcelsPerSecond 1000;
    flowRateProfile  constant 1;
    U0               (1 0 0);
    uniformParcelSize volume;
    massTotal        1e-3;
    sizeDistribution
    {
        type         fixedValue;
        fixedValueDistribution { value 1e-3; }
    }
}
```

（`etc/caseDicts/.../cloudProperties`）

## 参数表
| 入口 | 含义 | 量纲 |
|------|------|------|
| `SOI` | 开始注入时刻 | s |
| `duration` | 持续时间 | s |
| `parcelsPerSecond` | 包裹注入率 | 1/s |
| `massTotal` | 总质量 | kg |
| `U0` | 初速 | m/s |
| `sizeDistribution` | 粒径分布 | m |

## 控制方程与关联式
在 patch 面元采样位置，按流率创建 parcel。

## 文献与源码依据
`InjectionModel/PatchInjection/`

## 教程与模板
`etc/caseDicts`；多数喷射案例。

## 注意事项
- `patchName` 错误 → 空注入。

---

# patchFlowRateInjection

## 一句话
按 patch 流体体积/质量流率耦合注入。

## 适用条件
需要与入口流量一致时。

## 字典示例

> （由源码构造函数推断；对照 `PatchFlowRateInjection`）

```cpp
model1
{
    type             patchFlowRateInjection;
    patchName        inlet;
    duration         1;              // [s]（读 Duration）
    volumeRatio      constant 0.001; // [-] 或 concentration；与 massRatio 二选一
    // massRatio     constant 0.001;
    parcelConcentration 1e12;        // [1/m^3] 必填
    // 可选: phi rho（默认 phi / rho）
    sizeDistribution
    {
        type         fixedValue;
        fixedValueDistribution { value 100e-6; }  // [m]
    }
}
```

## 参数表
| 入口 | 含义 | 量纲 |
|------|------|------|
| `patchName` | 注入 patch | — |
| `volumeRatio` / `concentration` / `massRatio` | 相对体积或质量流率 Function1 | [-] |
| `parcelConcentration` | 单位体积包裹数 | 1/m^3 |
| `sizeDistribution` | 粒径分布 | m |

## 控制方程与关联式
注入质量与 patch 通量相关。

## 文献与源码依据
`PatchFlowRateInjection`/`

## 教程与模板
—
## 注意事项
—

---

# coneInjection

## 一句话
锥形喷雾注入（实心/空心锥）。

## 适用条件
喷油器、喷雾燃烧（`aachenBomb` 等）。

## 字典示例

精简自 `tutorials/multicomponentFluid/aachenBomb/constant/cloudProperties`：

```cpp
model1
{
    type             coneInjection;
    SOI              0;                 // [s]
    duration         1.25e-3;           // [s]
    massTotal        6.0e-6;            // [kg]
    uniformParcelSize volume;
    injectionMethod  disc;
    flowType         flowRateAndDischarge;
    dInner           0;                 // [m]
    dOuter           1.9e-4;            // [m]
    position         (0 0.0995 0);      // [m]
    direction        (0 -1 0);          // [-]
    parcelsPerSecond 20000000;          // [1/s]
    flowRateProfile  constant 1;        // 教程用 table
    Cd               constant 0.9;      // [-]
    thetaInner       constant 0;        // [deg]
    thetaOuter       constant 10;       // [deg]
    sizeDistribution
    {
        type            RosinRammler;
        Q               3;
        min             1e-6;           // [m]
        max             1.5e-4;         // [m]
        d               1.5e-4;         // [m]
        n               3;              // [-]
    }
}
```

## 参数表
| 入口 | 含义 | 量纲 |
|------|------|------|
| `position` / `direction` | 喷孔位置与轴向 | m / — |
| `dInner` / `dOuter` | 环形喷孔内外径 | m |
| `thetaInner` / `thetaOuter` | 内/外锥角 | deg |
| `Cd` | 流量系数（flowRateAndDischarge） | [-] |
| `massTotal` | 总质量 | kg |
| `sizeDistribution` | 粒径分布 | m |

## 控制方程与关联式
在锥内采样方向与速度。

## 文献与源码依据
`ConeInjection`/`

## 教程与模板
`multicomponentFluid/aachenBomb`

## 注意事项
—

---

# cellZoneInjection

## 一句话
在 cellZone 内体积注入。

## 适用条件
区域初始填充或源区注入。

## 字典示例
`type` cellZoneInjection;` + zone 名。

## 参数表
`cellZone`、数量、粒径、`U0`。

## 控制方程与关联式
在 zone 单元内随机/指定放置。

## 文献与源码依据
`CellZoneInjection`/`

## 教程与模板
—
## 注意事项
zone 必须存在。

---

# manualInjection

## 一句话
从位置文件手动放置颗粒。

## 适用条件
已知初始颗粒分布（流化床等）。

## 字典示例

```cpp
// GoldschmidtMPPIC
type            manualInjection;
nParticle       1;
SOI             0;
positionsFile   "cloudPositions";
U0              (0 0 0);
sizeDistribution { type fixedValue; value 0.0025; }
```

## 参数表
| `positionsFile` | 点坐标文件 |
| `nParticle` | 每位置代表颗粒数 |

## 控制方程与关联式
读入坐标创建 parcel。

## 文献与源码依据
`ManualInjection`/`

## 教程与模板
`Goldschmidt`, `GoldschmidtMPPIC`, `column`

## 注意事项
路径相对 `constant`/`。

---

# fieldActivatedInjection

## 一句话
由场阈值触发的注入。

## 适用条件
条件注入。

## 字典示例 / 参数表 / 方程
见 `FieldActivatedInjection`.H`。

## 依据
同目录。

## 教程与模板
—
## 注意事项
—

---

# NoInjection

## 一句话
不注入。

## 字典示例
`type` none;` / `NoInjection`（以注册名为准）。

## 参数表
无。

## 依据
`NoInjection`/`

---

# LookupTable 注入族

| 类型 | 云宏 | 一句话 |
|------|------|--------|
| `MomentumLookupTableInjection` | makeParcelInjectionModels | 动量 parcel 查表 |
| `ThermoLookupTableInjection` | makeThermoParcelInjectionModels | 热 parcel 查表 |
| `ReactingLookupTableInjection` | makeReactingParcelInjectionModels | 反应 parcel 查表 |
| `ReactingMultiphaseLookupTableInjection` | makeReactingMultiphase… | 多相反应查表 |

### 共用模板要点
- **适用**: 对应云 type
- **字典**: 查表文件路径与列定义（源码）
- **方程**: 按表插值状态初始化
- **注意**: 表与云组分结构必须匹配

---

## 新框架注入（对照）
`diskInjection`, `patchInjection`, `pointInjection`, `volumeInjection`, `manualInjection` — 见 [new-Lagrangian-framework.md](new-Lagrangian-framework.md)。

## 覆盖计数
经典 InjectionModel：**9+**（含 lookup 族与 NoInjection）= `make`*InjectionModels` 宏全覆盖。
