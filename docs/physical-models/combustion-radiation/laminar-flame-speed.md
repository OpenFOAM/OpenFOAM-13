# 层流火焰速度（laminarFlameSpeed）

主要用于 **`XiFluid`**（`-llaminarFlameSpeedModels`），在 `combustionProperties` 的 `laminarFlameSpeed` / `unstrainedLaminarFlameSpeed` 段配置。

---

# Gulder

## 一句话
Gulder 关联式：\(S_u=S_{u0}(T,p,\phi)\) 拟合，常用于丙烷/甲烷等。

## 适用条件（求解器 / 场 / 前提）
- **适用**: `XiFluid`；亦注册为通用 `laminarFlameSpeed`
- **前提**: 指定 `fuel` 与燃料子字典系数

## 字典示例

```cpp
// tutorials/XiFluid/moriyoshiHomogeneous/.../combustionPropertiesInclude
laminarFlameSpeed
{
    model           unstrained;

    unstrainedLaminarFlameSpeed
    {
        model           Gulder;
        equivalenceRatio 1;
        fuel            Propane;

        Propane
        {
            W       0.446;
            eta     0.12;
            xi      4.95;
            alpha   1.77;
            beta    -0.2;
            f       2.3;
        }
    }
}
```

## 参数表
| 入口 | 含义 | 量纲 |
|------|------|------|
| `fuel` | 燃料名，对应子字典 | — |
| `W`, `eta`, `xi`, `alpha`, `beta`, `f` | Gulder 拟合系数 | 见实现 |
| `equivalenceRatio` | 可选当量比 | 无量纲 |

## 控制方程与关联式
类头与 XiFluid Description 引用 Gulder 关联；\(S_u\) 随 \(T,p,\phi\) 变化。文献线索：Weller 等与 Gulder 火焰速度对比（见 `XiFluid`.H`）。

## 文献与源码依据
- `src/thermophysicalModels/laminarFlameSpeed/Gulder/`
- `applications/modules/XiFluid/XiFluid.H`

## 教程与模板
- `XiFluid/moriyoshiHomogeneous`, `engine2Valve2D`, `1D`, `stratified`

## 注意事项
- 燃料子字典名必须与 `fuel` 一致；缺系数会 FatalError。

---

# RaviPetersen

## 一句话
Ravi–Petersen 层流火焰速度关联。

## 适用条件（求解器 / 场 / 前提）
- **适用**: `XiFluid` / `laminarFlameSpeed` RTS

## 字典示例

> （由源码构造函数推断，无官方教程实例）

```cpp
unstrainedLaminarFlameSpeed
{
    model   RaviPetersen;

    // Foam::laminarFlameSpeedModels::RaviPetersen 必读（coeffDict）:
    pPoints     (<p0> <p1> ...);   // 压力网格点 [Pa]，须单调
    EqRPoints   (<phi0> ...);      // 当量比网格点，须单调
    alpha       (...);             // 系数数组，形状须与网格匹配
    beta        (...);             // 系数数组，形状须与网格匹配
    TRef        <TRef>;            // 参考温度 [K]
}
```

## 参数表
| 入口 | 必需 | 含义 |
|------|------|------|
| `pPoints` | 是 | 压力插值节点 |
| `EqRPoints` | 是 | 当量比插值节点 |
| `alpha` / `beta` | 是 | 关联式系数数组（形状由 ctor 校验） |
| `TRef` | 是 | 参考温度 |

## 控制方程与关联式
关联式形式见类 Description；系数表与 Gulder 不通用。

## 文献与源码依据
- `src/thermophysicalModels/laminarFlameSpeed/RaviPetersen/RaviPetersen.C`

## 教程与模板
仓库 tutorials 中字面 `RaviPetersen` 很少；优先对照 Gulder 教程骨架后替换模型与系数表。

## 注意事项
- 点列必须单调，否则 ctor 中 `checkPointsMonotonicity` 直接 FatalError。

---

# constant

## 一句话
常值层流火焰速度。

## 适用条件（求解器 / 场 / 前提）
调试、1D 验证或已知恒定 \(S_u\)。

## 字典示例

> （由源码构造函数推断；`Su` 为必填）

```cpp
unstrainedLaminarFlameSpeed
{
    model   constant;
    Su      0.434;   // [m/s] 常数层流火焰速度（dimensionedScalar lookup）
}
```

## 参数表
| 入口 | 含义 | 量纲 |
|------|------|------|
| `Su` | 常数 $S_u$ | m/s |

## 控制方程与关联式
$S_u=\mathrm{const}$（全场均匀）。

## 文献与源码依据
- `src/thermophysicalModels/laminarFlameSpeed/constant/constant.C`

## 教程与模板
`XiFluid/1D` 等可对照（多数教程用 Gulder；`constant` 适合验证）。

## 注意事项
- 忽略压力温度影响，不适合广工况发动机。

---

## 覆盖计数
RTS `laminarFlameSpeed`：**3**（Gulder, RaviPetersen, constant）= inventory 全覆盖。
