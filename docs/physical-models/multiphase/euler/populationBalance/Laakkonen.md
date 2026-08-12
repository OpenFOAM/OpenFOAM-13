# Laakkonen

## 一句话
Model of Laakkonen et al. (2007). The total breakup rate is calculated by

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler（populationBalance）
- **族**: 破碎（基类 `breakupModel`）
- **注册名**: `Laakkonen`

## 字典示例

> 推断：源码默认系数。写在 `breakupModels`。勿与 DSD 的 TypeName `Laakkonen` 混淆。

```c++
// constant/phaseProperties — populationBalanceCoeffs
populationBalanceCoeffs
{
    bubbles
    {
        continuousPhase water;

        coalescenceModels
        ();

        binaryBreakupModels
        ();

        breakupModels
        (
            Laakkonen
            {
                C1              2.25;   // optional
                C2              0.04;   // optional
                C3              0.01;   // optional
                daughterSizeDistributionModel uniformBinary;
            }
        );
    }
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `C1` | coefficient C1 | no | 2.25 |
| `C2` | coefficient C2 | no | 0.04 |
| `C3` | coefficient C3 | no | 0.01 |
| `daughterSizeDistributionModel` | inh. from breakupModel | inherited | — |


## 控制方程与关联式
Model of Laakkonen et al. (2007). The total breakup rate is calculated by

[
C_1 _c^{1/3}
{erfc}
(
{
C_2 {}{_c _c^{2/3} (6v_i/)^{5/9}}
+ C_3 {_c}{{_c _d}
_c^{1/3} (6v_i/)^{4/9}}
}
)
]

where

|  Surface tension [N/m]
v_i         |  Volume of mother bubble i [m3]
_c  |  Turbulent dissipation rate of continuous phase [m^2/s^3]
_c       |  Molecular dynamic viscosity of liquid phase [Pa s]
_c      |  Density of continuous phase [kg/m^3]
_d      |  Density of disperse phase [kg/m^3]
References:
```
Laakkonen, M., Moilanen, P., Alopaeus, V., & Aittamaa, J. (2007).
Modelling local bubble size distributions in agitated vessels.
Chemical Engineering Science, 62, 721–740.
```

## 文献与源码依据
- 类: `Foam`::diameterModels::breakupModels::Laakkonen`
- 源码路径: `applications/modules/multiphaseEuler/populationBalance/breakupModels/Laakkonen/Laakkonen.C`

## 教程与模板
- `tutorials/multiphaseEuler/pipeBend/constant/phaseProperties`

## 注意事项
- 类型名必须与 RTS 注册名一致：`Laakkonen`。
