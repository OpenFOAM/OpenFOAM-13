# MPPIC 子模型

云类型：`MPPICCloud`。用于稠密颗粒流动（`incompressibleDenseParticleFluid` 教程 `GoldschmidtMPPIC`）。

宏：`makeMPPICParcelPackingModels`.H` 等。

---

# PackingModel

| 类型 | 一句话 |
|------|--------|
| `explicit` / `Explicit` | 显式体积分数校正 |
| `implicit` / `Implicit` | 隐式校正 |
| `NoPacking` | 关闭 |

## explicit（示例完整模板）

### 一句话
用颗粒应力显式限制堆积。

### 适用条件
`type` MPPICCloud`；`packingModel` explicit;`

### 字典示例

```cpp
// 摘录 GoldschmidtMPPIC
packingModel explicit;

explicitCoeffs
{
    particleStressModel
    {
        type HarrisCrighton;
        alphaPacked 0.65;
        pSolid 10.0;
        beta 2.0;
        eps 1.0e-7;
    }
    correctionLimitingMethod
    {
        type absolute;
        e 0.9;
    }
}
```

### 参数表
| 入口 | 含义 |
|------|------|
| `alphaPacked` | 堆积限体积分数 |
| `pSolid`,`beta`,`eps` | Harris–Crighton 应力参数 |
| `correctionLimitingMethod` | `absolute` / `relative` / `noCorrectionLimiting` |

### 控制方程与关联式
颗粒应力随 \(\alpha\) 上升，产生排斥性速度修正，防止过度堆积。

### 文献与源码依据
`MPPIC/PackingModels/`；`ParticleStressModels/{HarrisCrighton,Lun,exponential}/`

### 教程与模板
`incompressibleDenseParticleFluid/GoldschmidtMPPIC`

### 注意事项
- `interpolationSchemes` 需 `alpha`.air` 等。

## implicit
摘录同案 `implicitCoeffs`：

```cpp
implicitCoeffs
{
    alphaMin 0.0001;
    rhoMin 1.0;
    applyLimiting true;
    applyGravity false;
    particleStressModel
    {
        type HarrisCrighton;
        alphaPacked 0.65;
        pSolid 5.0;
        beta 2.0;
        eps 1.0e-2;
    }
}
```

参数含 `alphaMin`,`rhoMin`,`applyLimiting`,`applyGravity`。

---

# DampingModel

| 类型 | 一句话 |
|------|--------|
| `Relaxation` | 弛豫阻尼 |
| `NoDamping` | 关闭 |

### 字典示例
摘录 `GoldschmidtMPPIC`（关闭 + 可选 relaxation coeffs）：

```cpp
dampingModel none; // relaxation;

relaxationCoeffs
{
    timeScaleModel
    {
        type nonEquilibrium;
        alphaPacked 0.65;
        e 0.9;
    }
}
```

### TimeScaleModel（阻尼/各向同性共用）
| 类型 | 一句话 |
|------|--------|
| `equilibrium` | 平衡时间尺度 |
| `nonEquilibrium` | 非平衡 |
| `isotropic` | 各向同性 |

---

# IsotropyModel

| 类型 | 一句话 |
|------|--------|
| `Stochastic` | 随机各向同性化 |
| `NoIsotropy` | 关闭 |

### 字典示例
```cpp
isotropyModel stochastic;
stochasticCoeffs
{
    timeScaleModel
    {
        type isotropic;
        alphaPacked 0.65;
        e 0.9;
    }
}
```

### 控制方程与关联式
对颗粒速度脉动进行各向同性松弛，闭合颗粒温度类效应。

### 依据
`MPPIC/IsotropyModels/`

---

# CorrectionLimitingMethod / ParticleStressModel

已在 packing 示例中覆盖：`absolute`,`relative`,`noCorrectionLimiting`；`HarrisCrighton`,`Lun`,`exponential`。

---

# AveragingMethod
案例中 `averagingMethod` dual;` — 双重平均；源码 `MPPIC/AveragingMethods/`。

---

## 覆盖计数
Packing/Damping/Isotropy 宏类型 + Stress/TimeScale/CorrectionLimit → **与 inventory MPPIC 段及宏一致**。  
非 MPPIC 的 `pairCollision` / 弹簧滑块 → [parcel-collision-cloudFunctions.md](parcel-collision-cloudFunctions.md)。
