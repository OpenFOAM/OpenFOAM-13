# SurfaceReaction / Devolatilisation（煤粉等）

用于 **reactingMultiphase** 云。宏：`makeReactingMultiphaseParcelSurfaceReactionModels`.H` 等。

---

# SurfaceReactionModel

| 类型 | 一句话 |
|------|--------|
| `NoSurfaceReaction` | 关闭 |
| `COxidationDiffusionLimitedRate` | 扩散限制炭氧化 |
| `COxidationKineticDiffusionLimitedRate` | 动力–扩散限制 |
| `COxidationIntrinsicRate` | 本征速率 |
| `COxidationHurtMitchell` | Hurt–Mitchell |
| `COxidationMurphyShaddix` | Murphy–Shaddix |

## 共用模板

### 适用条件（求解器 / 场 / 前提）
- **适用**: `reactingMultiphaseCloud`；固体碳/煤粉燃烧
- **前提**: 多相组成（水分/挥发分/固定碳/灰）；气相 \(O_2\) 等

### 字典示例
摘录 `tutorials/multicomponentFluid/simplifiedSiwek/constant/coalCloudProperties`：

```cpp
devolatilisationModel constantRateDevolatilisation;
surfaceReactionModel COxidationKineticDiffusionLimitedRate;

constantRateDevolatilisationCoeffs
{
    volatileData
    (
        (CH4            12)
        (H2             12)
        (CO2            12)
    );
    residualCoeff   0.001;
}

COxidationKineticDiffusionLimitedRateCoeffs
{
    Sb              1;
    C1              5.0E-12;
    C2              0.002;
    E               7.9E+07;
}
```

关闭：`surfaceReactionModel none;` / `devolatilisationModel none;`

### 参数表
| 模型 | 关键入口 |
|------|----------|
| `COxidationKineticDiffusionLimitedRate` | `Sb`,`C1`,`C2`,`E` |
| `constantRateDevolatilisation` | `volatileData`,`residualCoeff` |
| 其他 COxidation* | 见各 `.H`（`A`,`E`、扩散系数等） |

### 控制方程与关联式
表面反应消耗固定碳、释放热与气相产物；速率受动力与氧气扩散限制（模型相关）。

### 文献与源码依据
`ReactingMultiphase/SurfaceReactionModel/*/`

### 教程与模板
`tutorials/multicomponentFluid/simplifiedSiwek`

### 注意事项
- 组成模型须为多相混合物（见 composition 页）。

---

# DevolatilisationModel

宏：`makeReactingMultiphaseParcelDevolatilisationModels`.H`。

| TypeName（字典） | 类 | 一句话 |
|------------------|-----|--------|
| `none` | `NoDevolatilisation` | 关闭 |
| `constantRateDevolatilisation` | `ConstantRateDevolatilisation` | 恒定速率析出 |
| `singleKineticRateDevolatilisation` | `SingleKineticRateDevolatilisation` | 单速率 Arrhenius 析出 |

### 适用条件
煤粉加热析出挥发分；`reactingMultiphaseCloud`。

### 字典示例
见上节 `simplifiedSiwek` 完整片段（`constantRateDevolatilisation`）。单速率：

```cpp
devolatilisationModel singleKineticRateDevolatilisation;
// singleKineticRateDevolatilisationCoeffs { ... }  // A, E 等见 .H
```

### 参数表
挥发分析出动力学参数（\(A,E_a\) 或恒定速率）——各类 `.H`。

### 控制方程与关联式
\(\mathrm{d}Y_{\mathrm{vol}}/\mathrm{d}t=-k(T)Y_{\mathrm{vol}}\) 或恒定 \(\dot{Y}\)。

### 依据
`DevolatilisationModel/{NoDevolatilisation,ConstantRateDevolatilisation,SingleKineticRateDevolatilisation}/`

### 教程
`tutorials/multicomponentFluid/simplifiedSiwek`

### 注意事项
与表面反应顺序：通常先挥发分再焦炭氧化。

---

## 覆盖计数
SurfaceReaction 宏 **6** + Devolatilisation 宏 **3** → 本表全覆盖。
