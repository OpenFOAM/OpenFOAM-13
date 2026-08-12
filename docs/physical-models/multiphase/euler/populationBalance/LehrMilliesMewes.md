# LehrMilliesMewes

## 一句话
Model of Lehr et al. (2002). The breakup rate is calculated by

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler（populationBalance）
- **族**: 二元破碎（基类 `binaryBreakupModel`）
- **注册名**: `LehrMilliesMewes`

## 字典示例


```c++
// `tutorials/multiphaseEuler/bubblePipe/constant/phaseProperties`
{
        continuousPhase water;

        coalescenceModels
        (
            LehrMilliesMewes
            {}
        );

        binaryBreakupModels
        (
            LehrMilliesMewes
            {}
        );

        breakupModels
        ();
    }
}

// ************************************************************************* //
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `LehrMilliesMewes`
- 基类: `binaryBreakupModel`


## 控制方程与关联式
Model of Lehr et al. (2002). The breakup rate is calculated by

[
0.5 d_j^{*^{5/3}} {exp}(-{{2}}{d_j^{*^{3}}})
{6}{^{3/2}d_i^{*^{3}}}
{exp}
(
- {9}{4}[{ln}(2^{2/5} d_i^{*})]^{2}
)
(
1
+ {erf}
[
{3}{2}{ln} (2^{1/15} d_j^{*})
]
)^{-1}
{1}{L^{3}T}
]

with the time scale

[
T = ({}{_c})^{2/5} {1}{_c^{3/5}}
]

the dimensionless diameter

[
d^{*} = {d}{L}
]

and the length scale

[
L = ({}{_c})^{3/5} {1}{_c^{2/5}}
]

_c          |  Density of continuous phase [kg/m^3]
|  Surface tension [N/m]
_c      |  Continuous phase turbulent dissipation rate [m^2/s^3]
d_i             |  Diameter of daughter bubble i [m]
d_j             |  Diameter of mother bubble j [m]
References:
```
Lehr, F., Millies, M., & Mewes, D. (2002).
Bubble‐size distributions and flow fields in bubble columns.
AIChE Journal, 48(11), 2426-2443.
Eq. 12-16, p. 2429-2430.
```

## 文献与源码依据
- 类: `Foam`::diameterModels::binaryBreakupModels::LehrMilliesMewes`
- 源码路径: `applications/modules/multiphaseEuler/populationBalance/binaryBreakupModels/LehrMilliesMewes/LehrMilliesMewes.C`

## 教程与模板
- `tutorials/multiphaseEuler/wallBoilingPolydisperseTwoGroups/constant/phaseProperties`
- `tutorials/multiphaseEuler/wallBoilingPolydisperse/constant/phaseProperties`
- `tutorials/multiphaseEuler/bubblePipe/constant/phaseProperties`

## 注意事项
- 类型名必须与 RTS 注册名一致：`LehrMilliesMewes`。
