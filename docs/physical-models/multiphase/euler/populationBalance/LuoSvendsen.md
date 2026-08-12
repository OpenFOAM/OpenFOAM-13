# LuoSvendsen

## 一句话
Model of Luo and Svendsen (1996). The breakup rate is calculated by

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler（populationBalance）
- **族**: 二元破碎（基类 `binaryBreakupModel`）
- **注册名**: `LuoSvendsen`

## 字典示例

> 推断：源码默认系数（无官方教程实例）。写在 `binaryBreakupModels`。

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
        (
            LuoSvendsen
            {
                C4              0.923;  // optional, default
                beta            2.05;   // optional, default
                minEddyRatio    11.4;   // optional, default（页表曾写作 C5）
            }
        );

        breakupModels
        ();
    }
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `C4` | Coefficient C4 | no | 0.923 |
| `beta` | Coefficient beta | no | 2.05 |
| `minEddyRatio` | Minimum eddy ratio | no | 11.4 |


## 控制方程与关联式
Model of Luo and Svendsen (1996). The breakup rate is calculated by

[
C_4 _c ({_c}{d_j^2})^{1/3}
_{_{min}}^{1}
{(1 + )^{2}}{^{11/3}}
{exp}
(
- {12c_f}{_c_c^{2/3}d_j^{5/3}^{11/3}}
)
{d} ]

where

[
c_f = ({v_i}{v_j})^{2/3}
+ (1 - {v_i}{v_j})^{2/3} - 1
]

[
_{min} = {_{min}}{d_j}\,,
]

and

[
_{min} = C_5 \,.
]

The integral in the first expression is solved by means of incomplete Gamma
functions as given by Bannari et al. (2008):

[
{3}{11 b^{8/11}}
(
[(8/11, b) - (8/11, t_{m})]
+ 2b^{3/11} [(5/11, b) - (5/11, t_{m})]
+ b^{6/11} [(2/11, b) - (2/11, t_{m})]
)
]

where

[
b = {12c_f}{_c_c^{2/3}d_j^{5/3}}
]

and

[
t_{min} = b _{min}^{-11/3}\,.
]

Note that in the code, the upper incomplete gamma function is expressed as

[
(a,z) = Q(a,z) (a)
]

_c    |  Void fraction of continuous phase [-]
_c  |  Turbulent dissipation rate of continuous phase [m^2/s^3]
d_j         |  Diameter of mother bubble j [m^3]
v_i         |  Volume of daughter bubble i [m^3]
v_j         |  Volume of mother bubble j [m^3]
|  Integration variable [-]
_{min}   |  Lower bound of integral [-]
c_f         |  Increase coefficient of surface area [-]
|  Surface tension [N/m]
_c      |  Density of continuous phase [kg/m^3]
|  Kolmogorov length scale [m]
(a,z) |  Upper incomplete gamma function
Q(a,z)      |  Regularised upper incomplete gamma function
(a)   |  Gamma function
References:
```
Luo, H., & Svendsen, H. F. (1996).
Theoretical model for drop and bubble breakup in turbulent dispersions.
AIChE Journal, 42(5), 1225-1233.
Eq. 27, p. 1229.
```

```
Bannari, R., Kerdouss, F., Selma, B., Bannari, A., & Proulx, P. (2008).
Three-dimensional mathematical modeling of dispersed two-phase flow
using class method of population balance in bubble columns.
Computers & chemical engineering, 32(12), 3224-3237.
Eq. 49, p. 3230.
```

## 文献与源码依据
- 类: `Foam`::diameterModels::binaryBreakupModels::LuoSvendsen`
- 源码路径: `applications/modules/multiphaseEuler/populationBalance/binaryBreakupModels/LuoSvendsen/LuoSvendsen.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`LuoSvendsen`。
