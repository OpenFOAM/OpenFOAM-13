# Luo

## 一句话
Model of Luo (1993). The coalescence rate is calculated by

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler（populationBalance）
- **族**: 聚并（基类 `coalescenceModel`）
- **注册名**: `Luo`

## 字典示例

> 推断：源码默认系数（无官方教程实例）。写在 `populationBalanceCoeffs` / `coalescenceModels`。

```c++
// constant/phaseProperties — populationBalanceCoeffs
populationBalanceCoeffs
{
    bubbles
    {
        continuousPhase water;

        coalescenceModels
        (
            Luo
            {
                beta            2.05;  // optional, default
                C1              1;     // optional, default
            }
        );

        binaryBreakupModels
        ();

        breakupModels
        ();
    }
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `beta` | Coefficient beta | no | 2.05 |
| `C1` | Coefficient C1 | no | 1 |


## 控制方程与关联式
Model of Luo (1993). The coalescence rate is calculated by

[
{}{4} (d_i + d_j)^2 u_{ij}
{exp}
[
- C_1
{[0.75(1 + _{ij}^2)(1 + _{ij}^3)]^{1/2}}
{(_d/_c + C_{vm})^{1/2} (1 + _{ij})^3}
({_c d_i u_{ij}^2}{})^{1/2}
]\,,
]

where

[
u_{ij} = {} (_c d_i)^{1/3} {1 + _{ij}^{-2/3}}
]

is the mean approach velocity of the bubbles and

[
_{ij} = d_i/d_j
]

their size ratio.

d_i         |  Diameter of bubble i [m]
d_j         |  Diameter of bubble j [m]
u_{ij}      |  Mean approach velocity [m/s]
_{ij}    |  Bubble size ratio [-]
_d      |  Density of dispersed phase [kg/m^3]
_c      |  Density of continuous phase [kg/m^3]
|  Surface tension [N/m]
C_{vm}      |  Virtual mass coefficient [-]
C_1         |  Coefficient [-]
|  Coefficient [-]
_c  |  Continuous phase turbulent dissipation rate [m^2/s^3]
Reference:
```
Luo, H. (1993).
Coalescence, breakup and liquid circulation in bubble column reactors.
Dr. Ing (Doctoral dissertation, Thesis, Department of Chemical
Engineering, The Norwegian Institute of Technology, Trondheim, Norway).
```

## 文献与源码依据
- 类: `Foam`::diameterModels::coalescenceModels::Luo`
- 源码路径: `applications/modules/multiphaseEuler/populationBalance/coalescenceModels/Luo/Luo.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`Luo`。
