# 反应速率与反应类型概览

反应写入 `chemistryProperties` 所 include 的机理文件（或 `thermophysicalProperties` 反应段，视案例）。实现位于 `src/thermophysicalModels/specie/reaction/`。本页为**概览**（非每个模板系数的百科）；与 Phase 1 `thermophysical/chemistry-reactions/` 交叉。

---

# Reaction 类型

## 一句话
将化学计量与正/逆速率律绑定为可积分反应。

## 适用条件（求解器 / 场 / 前提）
- **适用**: 任何启用 `chemistryModel` 的多组分求解器；`multiphaseEuler` 另有相表面 Arrhenius

## 字典示例（概念）

```cpp
reactions
{
    methaneReaction
    {
        type     irreversibleArrheniusReaction; // 名称以机理文件为准
        reaction "CH4 + 2O2 = CO2 + 2H2O";
        A        5.2e16;
        beta     0;
        Ta       14906;
    }
}
```

具体 `type` 字符串以教程机理（如 GRI include）为准。

## 参数表（反应外壳）
| 概念类 | 含义 |
|--------|------|
| `IrreversibleReaction` | 仅正向 |
| `ReversibleReaction` | 正逆（逆由平衡常数） |
| `NonEquilibriumReversibleReaction` | 非平衡可逆形式 |

## 控制方程与关联式
\(\dot{\omega}_i=\nu_i\,q\)，\(q\) 由所选 `ReactionRate` 给出。

## 文献与源码依据
- `src/thermophysicalModels/specie/reaction/Reactions/`

## 教程与模板
- `tutorials/multicomponentFluid/counterFlowFlame2D_GRI*/constant/reactionsGRI`

## 注意事项
- 物种名、元素守恒必须与 `thermoType`/混合物列表一致。

---

# 气相 ReactionRate 形式

## 一句话
提供正向速率常数 \(k(T,p,c)\) 的闭包。

## 适用条件（求解器 / 场 / 前提）
气相详细/简化机理。

## 字典示例
速率系数通常嵌在反应条目的 `A`, `beta`, `Ta` 或 fall-off 子字典中。

## 参数表

| 类型目录 | 一句话 | 典型参数 |
|----------|--------|----------|
| `ArrheniusReactionRate` | \(k=A T^\beta\exp(-T_a/T)\) | `A`, `beta`, `Ta` |
| `thirdBodyArrheniusReactionRate` | 第三体增强 Arrhenius | + `thirdBodyEfficiencies` |
| `FallOffReactionRate` | 低压/高压极限 + fall-off 函数 | `k0`, `kInf`, fall-off |
| `ChemicallyActivatedReactionRate` | 化学活化 | 见源码 |
| `LandauTellerReactionRate` | Landau–Teller | 见源码 |
| `JanevReactionRate` | Janev 形式 | 见源码 |
| `surfaceArrheniusReactionRate` | 表面 Arrhenius | 表面积相关 |
| `fluxLimitedLangmuirHinshelwoodReactionRate` | 通量限制 L-H | 催化/表面 |

### Fall-off 函数
| 类型 | 说明 |
|------|------|
| `LindemannFallOffFunction` | Lindemann |
| `TroeFallOffFunction` | Troe |
| `SRIFallOffFunction` | SRI |

## 控制方程与关联式
标准化学动力学教科书形式；系数单位依 OpenFOAM 约定（浓度用 kmol/m³ 等）——以机理文件注释与 `specie` 实现为准。

## 文献与源码依据
- `src/thermophysicalModels/specie/reaction/reactionRate/`
- Inventory：`rts`-combustion-radiation.md` reaction 段

## 教程与模板
GRI / nc7h16 等 include 文件。

## 注意事项
- Fall-off 高低压极限单位不一致是常见报错来源。

---

# multiphaseEuler：phaseSurfaceArrheniusReactionRate

## 一句话
多相欧拉框架下的相表面 Arrhenius 反应速率（模块库 `multiphaseEulerReactions`）。

## 适用条件（求解器 / 场 / 前提）
- **适用**: `multiphaseEuler`（`-lmultiphaseEulerReactions`）
- **不适用**: 单相 `multicomponentFluid` 默认路径

## 字典示例
见 `applications/modules/multiphaseEuler/reactions/` 与相关教程（如含 reacting 的 bubbleColumn）。

## 参数表
以 `phaseSurfaceArrheniusReactionRate` 头文件为准。

## 控制方程与关联式
速率依赖相界面面积浓度等欧拉相量。

## 文献与源码依据
- `applications/modules/multiphaseEuler/reactions/phaseSurfaceArrheniusReactionRate/`

## 教程与模板
`tutorials/multiphaseEuler/*Reacting*` / `titaniaSynthesis`*`（需核对）

## 注意事项
- 属 Phase 3/4 交叉；完整相系字典见 multiphase 目录（Phase 3）。

---

## 覆盖计数

| Inventory reaction 目录项 | 本页 |
|---------------------------|------|
| Arrhenius / thirdBody / FallOff / Janev / LandauTeller / ChemicallyActivated / surface / fluxLimited LH / 三类 fall-off / Reaction 外壳 | **已概览** |
| `specieCoeffs` / `specieExponent` / `reaction` 工具类 | 实现细节，不成页 |

**缺口**: 未为每一种 ReactionRate 单独复制完整字典模板（依官方机理文件）；用户应以 `tutorials/**/reactions*` 为可运行真源。
