# 吸收/发射、散射与烟黑

在 `radiationProperties` 中与 `radiationModel` 并列配置。燃烧专用吸收模型在 `src/combustionModels/radiationModels/`。

---

# absorptionEmissionModel

## constant（constantAbsorptionEmission）

### 一句话
常数吸收/发射系数。

### 适用条件
调试、均匀介质；`hotRadiationRoom`*`。

### 字典示例

```cpp
absorptionEmissionModel constant;
constantCoeffs
{
    absorptivity    0.5;   // [1/m] 量级，见案例
    emissivity      0.5;
    E               0;     // 额外发射贡献
}
```

### 参数表
| 入口 | 含义 | 量纲 |
|------|------|------|
| `absorptivity` | 吸收系数 \(a\) | [0 -1 0 0 0 0 0] |
| `emissivity` | 发射相关 | 同左或实现定义 |
| `E` | 附加发射 | 见源码 |

### 控制方程与关联式
\(a,e\) 为常数。

### 文献与源码依据
`absorptionEmissionModels/constantAbsorptionEmission/`

### 教程与模板
`hotRadiationRoom`, `hotRadiationRoomFvDOM`

### 注意事项
字典类型名写 `constant`，Coeffs 前缀 `constantCoeffs`。

---

## greyMean

### 一句话
灰气体平均吸收（查表/多项式组分加权）。

### 适用条件
多组分非燃烧或通用灰气体。

### 字典示例
见 `greyMean` 源码 Usage（物种系数块类似 greyMeanCombustion）。

### 参数表
`lookUpTableFileName`、各物种 `Tcommon`/`loTcoeffs`/`hiTcoeffs` 等。

### 控制方程与关联式
\(\,a=\sum X_i a_i(T)\) 类灰平均。

### 文献与源码依据
`absorptionEmissionModels/greyMean/`

### 教程与模板
—
### 注意事项
与 `greyMeanCombustion` 区分。

---

## greyMeanCombustion

### 一句话
燃烧工况灰平均吸收（可含热释放耦合系数）。

### 适用条件
`multicomponentFluid` 池火等；需燃烧库。

### 字典示例
见 `tutorials/multicomponentFluid/smallPoolFire3D/constant/radiationProperties`（`CO2`/`H2O`/`CH4`/`O2`/`N2` 多项式）。

### 参数表
| 入口 | 含义 |
|------|------|
| `EhrrCoeff` | 与热释放相关的发射修正系数 |
| `lookUpTableFileName` | 查表文件或 `none` |
| 物种块 | 分段多项式吸收 |

### 控制方程与关联式
同灰平均；燃烧扩展见类 Description。

### 文献与源码依据
`src/combustionModels/radiationModels/absorptionEmissionModels/greyMeanCombustion/`

### 教程与模板
`smallPoolFire2D/3D`

### 注意事项
物种名须存在于混合物。

---

## wideBand / wideBandCombustion

### 一句话
宽谱带吸收发射；`wideBandCombustion` 为燃烧扩展。

### 适用条件
需要分波段时；成本高于灰气体。

### 字典示例
见各自 `.H` Usage。

### 参数表
波段划分与物种系数（源码）。

### 控制方程与关联式
分带 RTE/吸收。

### 文献与源码依据
`absorptionEmissionModels/wideBand/`；`combustionModels/.../wideBandCombustion/`

### 教程与模板
教程少于 greyMeanCombustion。

### 注意事项
—
## binary

### 一句话
组合两个吸收发射模型。

### 适用条件
需要叠加两种模型时。

### 字典示例
见 `binary/binary.H`。

### 参数表
两个子模型名及 coeffs。

### 控制方程与关联式
\(a = a_1+a_2\) 类组合（见实现）。

### 文献与源码依据
`absorptionEmissionModels/binary/`

### 教程与模板
—
### 注意事项
—
## noAbsorptionEmission

### 一句话
无吸收发射。

### 字典示例
`absorptionEmissionModel` none;`（以 RTS 注册名为准）

### 参数表
无。

### 依据
`noAbsorptionEmission`/`

---

# scatterModel

## constantScatter / constant

### 一句话
常散射系数。

### 字典示例

```cpp
scatterModel    constant;
// 或源码注册名
constantScatterCoeffs { /* sigma, C */ }
```

以 `constantScatter` 头文件为准。

### 参数表
散射系数等。

### 依据
`scatterModels/constantScatter/`

## noScatter / none

### 一句话
无散射（教程默认）。

### 字典示例
`scatterModel` none;`

### 依据
`noScatter`/`

---

# sootModel

## mixtureFraction（燃烧库）

### 一句话
混合物分数型烟黑模型。

### 适用条件
燃烧 + 辐射需要烟黑辐射时。

### 字典示例
见 `src/combustionModels/radiationModels/sootModels/mixtureFraction/`。

### 参数表
烟黑产率与混合物分数关系参数（源码）。

### 控制方程与关联式
\(Y_{\mathrm{soot}}=Y_{\mathrm{soot}}(f)\) 类闭合。

### 依据 / 教程
燃烧 radiation 子库；教程默认多为 `sootModel` none`。

### 注意事项
开启后需有混合物分数相关场。

## noSoot / none

### 一句话
关闭烟黑。

### 字典示例
`sootModel` none;`（所有官方辐射教程默认）

---

# 云辐射附加（Lagrangian）

| 类型 | RTS 基类 | 路径 |
|------|----------|------|
| `cloud` | absorptionEmissionModel | `parcel/submodels/addOns/radiation/.../cloudAbsorptionEmission` |
| `cloud` | scatterModel | `.../cloudScatter` |

颗粒云对辐射的吸收/散射；与 [../lagrangian/](../lagrangian/) 联用。

---

## 覆盖计数

| 族 | 类型 | 状态 |
|----|------|------|
| absorptionEmission | constant, greyMean, wideBand, binary, none, greyMeanCombustion, wideBandCombustion, cloud | ✓ 概览 |
| scatter | constant, none, cloud | ✓ |
| soot | mixtureFraction, none | ✓ |

**缺口**: `wideBand`*` / `binary` / `mixtureFraction` 缺少完整官方教程字典副本；细节以源码 Usage 为准。
