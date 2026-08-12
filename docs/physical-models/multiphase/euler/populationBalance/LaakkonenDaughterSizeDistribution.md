# LaakkonenDaughterSizeDistribution

## 一句话
Daughter size distribution model of Laakkonen et al. (2007). Note that the

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler（populationBalance）
- **族**: 子粒径分布（基类 `daughterSizeDistributionModel`）
- **注册名**: `Laakkonen`（类名 `LaakkonenDaughterSizeDistribution`）

## 字典示例

> 作为 `breakupModels` 内嵌套的 `daughterSizeDistributionModel`。RTS TypeName 为 `Laakkonen`。

摘自 `tutorials/multiphaseEuler/pipeBend/constant/phaseProperties`：

```c++
// constant/phaseProperties — populationBalanceCoeffs
breakupModels
(
    Kusters
    {
        daughterSizeDistributionModel Laakkonen;
        C4              2;       // DSD coeff（覆盖默认 18.25）
        B               50e-7;
        dP              250e-9;
        Df              2.4;
    }
);
```

仅 DSD 默认：

```c++
daughterSizeDistributionModel Laakkonen;
// 可选：C4  18.25;  // source default
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `C4` | Coefficient C4 | no | 18.25 |


## 控制方程与关联式
Daughter size distribution model of Laakkonen et al. (2007). Note that the
diameters in the original expression were substituted by bubble volumes
giving

[
(1 + C_4)(2 + C_4)(3 + C_4)(4 + C_4)
({1}{3}) ({1}{v_j})
({v_i}{v_j})^{2} (1 - {v_i}{v_j})^{C_4}
]

where

v_i         |  Volume of daughter bubble i [m3]
v_j         |  Volume of mother bubble j [m3]
The total number of daughter bubbles generated depends on C4 and evaluates
to

[
{4}{3} + {C_4}{3}
]

References:
```
Laakkonen, M., Moilanen, P., Alopaeus, V., & Aittamaa, J. (2007).
Modelling local bubble size distributions in agitated vessels.
Chemical Engineering Science, 62, 721–740.
```

## 文献与源码依据
- 类: `Foam`::diameterModels::daughterSizeDistributionModels::`
- 源码路径: `applications/modules/multiphaseEuler/populationBalance/daughterSizeDistributionModels/LaakkonenDaughterSizeDistribution/LaakkonenDaughterSizeDistribution.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`Laakkonen`（作为 `daughterSizeDistributionModel`）。
