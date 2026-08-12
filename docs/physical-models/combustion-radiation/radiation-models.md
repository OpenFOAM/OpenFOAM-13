# 辐射模型（radiationModel）

配置：`constant/radiationProperties`。**必须**同时用 fvModel 激活，见 [radiation-fvModel.md](radiation-fvModel.md)。

---

# P1

## 一句话
P1（球谐一阶）辐射模型，适合光学厚介质。

## 适用条件（求解器 / 场 / 前提）
- **适用**: `fluid`, `multicomponentFluid`, CHT 流体区等（经 radiation fvModel）
- **前提**: `absorptionEmissionModel`；散射常为 `none`

## 字典示例

```cpp
// tutorials/fluid/hotRadiationRoom
radiationModel  P1;
solverFreq 1;

absorptionEmissionModel constant;
constantCoeffs
{
    absorptivity    0.5;
    emissivity      0.5;
    E               0;
}
scatterModel    none;
sootModel       none;
```

## 参数表
| 入口 | 含义 | 量纲 |
|------|------|------|
| `solverFreq` | 每多少次流场迭代解一次辐射 | — |
| 吸收/散射/烟黑 | 见 [absorption-emission-scatter-soot.md](absorption-emission-scatter-soot.md) | |

## 控制方程与关联式
对入射辐射 \(G\) 求解扩散型方程，辐射热流与 \(\nabla G\) 相关（标准 P1 近似）。假设：接近各向同性强度、光学厚度较大时较合理。

## 文献与源码依据
- `src/radiationModels/radiationModels/P1/`

## 教程与模板
- `tutorials/fluid/hotRadiationRoom`

## 注意事项
- 光学薄时 P1 误差大，改用 fvDOM。

---

# fvDOM

## 一句话
有限体积离散纵标法：按方向离散辐射传递方程。

## 适用条件（求解器 / 场 / 前提）
- **适用**: 需要方向分辨、光学薄–中等；燃烧池火常用
- **前提**: `nPhi`/`nTheta`；计算成本随方向数上升

## 字典示例

```cpp
// tutorials/fluid/hotRadiationRoomFvDOM
radiationModel  fvDOM;

fvDOMCoeffs
{
    nPhi        3;
    nTheta      5;
    tolerance   1e-3;
    maxIter     10;
}

solverFreq 10;

absorptionEmissionModel constant;
constantCoeffs { absorptivity 0.5; emissivity 0.5; E 0; }
scatterModel    none;
sootModel       none;
```

池火燃烧（`smallPoolFire3D`）常用 `greyMeanCombustion` 吸收模型。

## 参数表
| 入口 | 含义 | 量纲 |
|------|------|------|
| `nPhi` | \(XY\) 平面方位角四分之一中的划分数 | — |
| `nTheta` | 极角划分数 | — |
| `tolerance` / `maxIter` | 辐射迭代 | — |

## 控制方程与关联式
对各离散方向 \(I_i\) 求解 RTE；用 `radiativeIntensityRay`、黑体发射 `blackBodyEmission` 等辅助类。

## 文献与源码依据
- `src/radiationModels/radiationModels/fvDOM/`

## 教程与模板
- `hotRadiationRoomFvDOM`；`smallPoolFire2D/3D`；`SandiaD_LTS`

## 注意事项
- `nPhi`/`nTheta` 过小 → 射线效应；过大 → 极慢。

---

# viewFactor

## 一句话
基于视角因子的辐射交换（常用于围护/表面主导）。

## 适用条件（求解器 / 场 / 前提）
- **适用**: 表面–表面辐射重要、介质吸收弱时可考虑
- **前提**: 视角因子数据/生成流程（见源码与工具）

## 字典示例
见 `src/radiationModels/radiationModels/viewFactor/viewFactor.H` Usage。

## 参数表
以源码为准（视角因子文件等）。

## 控制方程与关联式
表面净热流由视角因子矩阵与表面辐射力构造。

## 文献与源码依据
- `viewFactor/viewFactor.H`

## 教程与模板
教程覆盖弱于 P1/fvDOM。

## 注意事项
- 设置比 P1 重；缺视角因子文件会失败。

---

# opaqueSolid

## 一句话
不透明固体辐射处理（多区域固体侧常用）。

## 适用条件（求解器 / 场 / 前提）
- **适用**: `solid` 区域 + radiation fvModel（如 `reverseBurner` solid）

## 字典示例
见 `tutorials/multiRegion/CHT/reverseBurner/constant/solid/radiationProperties`。

## 参数表
吸收发射常配合固体边界；见案例。

## 控制方程与关联式
固体不参与介质 RTE，按不透明体边界处理。

## 文献与源码依据
- `radiationModels/opaqueSolid/`

## 教程与模板
`reverseBurner`

## 注意事项
- gas/solid 两侧 `radiationProperties` 类型通常不同。

---

# noRadiation / none

## 一句话
关闭辐射模型。

## 适用条件（求解器 / 场 / 前提）
对比算例或无辐射时。

## 字典示例

```cpp
radiationModel  none;
```

## 参数表
无。

## 控制方程与关联式
无辐射源。

## 文献与源码依据
- `noRadiation`/`

## 教程与模板
—
## 注意事项
即使 `radiationModel` none`，若仍加载 radiation fvModel，行为以实现为准——建议同时去掉 fvModel。

---

## 覆盖计数
RTS 辐射模型目录：**P1, fvDOM, viewFactor, opaqueSolid, noRadiation** → 本页全覆盖。
