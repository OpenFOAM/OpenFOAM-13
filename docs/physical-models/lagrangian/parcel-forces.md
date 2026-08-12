# ParticleForces（颗粒力）

注册：`makeParcelForces`.H` / `makeThermoParcelForces`.H`。在 `subModels`.particleForces` 中**列出类型名**（可带子字典）。

---

## 共用说明

### 一句话
合力 \(\sum\mathbf{F}\) 驱动颗粒加速度。

### 适用条件
所有动量 parcel 云。

### 字典示例

```cpp
particleForces
{
    sphereDrag;
    gravity;

    // 或带参数：
    PlessisMasliyahDrag
    {
        alphac alpha.air;
    }
}
```

### 控制方程与关联式
\(m\mathrm{d}\mathbf{u}_p/\mathrm{d}t=\mathbf{F}_D+\mathbf{F}_g+\cdots\)

### 依据
`submodels/Momentum/ParticleForces/` + `makeParcelForces`.H`

---

# 阻力（Drag）

| TypeName（字典） | 类名 | 一句话 | 适用提示 |
|------------------|------|--------|----------|
| `sphereDrag` | `SphereDragForce` | 球颗粒标准阻力 | 稀相默认 |
| `nonSphereDrag` | `NonSphereDragForce` | 非球形 | 需形状因子 |
| `SchillerNaumannDrag` | `SchillerNaumannDragForce` | Schiller–Naumann | Re 关联 |
| `WenYuDrag` | `WenYuDragForce` | Wen–Yu | 较密相 |
| `ErgunWenYuDrag` | `ErgunWenYuDragForce` | Ergun–Wen–Yu 切换 | 密相/流化 |
| `PlessisMasliyahDrag` | `PlessisMasliyahDragForce` | Plessis–Masliyah | 稠密；常需 `alphac` |

### 模板（每种）
- **参数表**: 可选 `alphac` 连续相体积分数场名；其余见各类 `.H`
- **方程**: \(C_D(Re,\alpha)\) 形式阻力
- **教程**: `GoldschmidtMPPIC` 用 `PlessisMasliyahDrag`；`etc/caseDicts` 用 `sphereDrag`
- **注意**: 字典键为短名（`sphereDrag`），类名为 `SphereDragForce`

另：`DenseDrag` / `DistortedSphereDrag` 存在于源码树；是否经 `makeParcelForces` 默认注册以宏为准（**默认宏未列 Distorted/Dense** → 标缺口，需核 `makeThermoParcelForces` 等扩展宏）。

---

# 升力（Lift）

| TypeName（字典） | 类名 | 一句话 |
|------------------|------|--------|
| `SaffmanMeiLiftForce` | `SaffmanMeiLiftForce` | Saffman–Mei 升力（经典 parcel TypeName 带 Force 后缀） |
| `TomiyamaLift` | `TomiyamaLiftForce` | Tomiyama 升力 |

参数与关联式见各自 `.H`；气泡/剪切流常用。新框架短名 `SaffmanMeiLift` 见 [new-Lagrangian-framework.md](new-Lagrangian-framework.md)。

---

# 体积力与其它

| TypeName | 类名 | 一句话 |
|----------|------|--------|
| `gravity` | `GravityForce` | 重力（读 `g`） |
| `pressureGradient` | `PressureGradientForce` | 压力梯度力 |
| `virtualMass` | `VirtualMassForce` | 虚拟质量 |
| `nonInertialFrame` | `NonInertialFrameForce` | 非惯性系 |
| `paramagnetic` | `ParamagneticForce` | 顺磁 |
| `scaled` | `ScaledForce` | 对子力缩放 |
| `BrownianMotion` | `BrownianMotionForce` | 布朗力（`makeThermoParcelForces` 追加） |

### gravity
- **字典**: `gravity`;`
- **前提**: `constant/g`；`clouds` fvModel 说明：无 `g` 则默认零
- **教程**: MPPIC / 流化床

### pressureGradient / virtualMass / BrownianMotion
- 压力梯度与虚拟质量需可插值连续相场；系数见源码
- `BrownianMotion` 仅经 `makeThermoParcelForces` 注册的热/反应云可用

### 类名 ↔ 字典名
宏 include 为 `*Force.H`，字典键以各类 `TypeName`(...)` 为准（上表）；审计脚本若按类文件名检索会误报缺口。

---

## 新框架力模型
`gravity`, `SchillerNaumannDrag`, `GidaspowErgunWenYuDrag`, `SaffmanMeiLift`, `pressureGradientForce`, `constantCoefficientVirtualMass` — [new-Lagrangian-framework.md](new-Lagrangian-framework.md)

## 覆盖计数
`makeParcelForces` **13** + `makeThermoParcelForces` 追加 `BrownianMotion` → 本页全覆盖。  
**缺口**: `distortedSphereDrag` / `DenseDrag` 基类源码有、默认 `makeParcelForces` 未注册时用户不可直接用。
