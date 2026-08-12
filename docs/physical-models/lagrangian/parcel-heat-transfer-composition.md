# HeatTransfer / Composition

---

# HeatTransferModel

注册：`makeParcelHeatTransferModels`.H`。

## RanzMarshall

### 一句话
Ranz–Marshall 颗粒–流体对流传热。

### 适用条件（求解器 / 场 / 前提）
thermo / reacting / spray 云；需连续相 \(T\)、物性。

### 字典示例
`heatTransferModel` RanzMarshall;`

### 参数表
可选系数见源码（常默认）。

### 控制方程与关联式
\(Nu=2+0.6Re^{1/2}Pr^{1/3}\)（经典 Ranz–Marshall）；热流量 \(\dot{Q}=hA(T_\infty-T_p)\)。

### 文献与源码依据
`HeatTransferModel/RanzMarshall/`

### 教程与模板
含热颗粒/蒸发的通道与喷雾案例。

### 注意事项
—

## NoHeatTransfer

### 一句话
关闭传热。

### 字典示例
`heatTransferModel` none;`（`GoldschmidtMPPIC`）

### 依据
`NoHeatTransfer`/`

---

# CompositionModel

| 宏 | 类型 | 一句话 |
|----|------|--------|
| makeParcelCompositionModels | `SinglePhaseMixture` | 单相混合物组成 |
| | `NoComposition` | 无 |
| makeReactingMultiphaseParcelCompositionModels | `SingleMixtureFraction` | 单混合物分数多相组成 |
| | `NoComposition` | 无 |

### 适用条件
reacting 云必须正确 composition，否则相变/反应无法映射物种。

### 字典示例
见 reacting 教程 `compositionModel` 与 `phaseProperties`/`constantProperties` 液体成分。

### 参数表
相质量分数、物种列表。

### 控制方程与关联式
定义 parcel 内 \(Y_i\) 存储与气相耦合映射。

### 依据
`Reacting/CompositionModel/`、`ReactingMultiphase/...`

### 教程
`verticalChannel`, `simplifiedSiwek`, `aachenBomb`

### 注意事项
物种名与 `thermophysicalProperties`/`chemistry` 一致。

---

## 覆盖计数
HeatTransfer **2**；Composition 宏类型 **已列**。
