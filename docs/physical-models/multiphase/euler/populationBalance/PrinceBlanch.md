# PrinceBlanch

## 一句话
Model of Prince and Blanch (1990). The coalescence rate is calculated by

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler（populationBalance）
- **族**: 聚并（基类 `coalescenceModel`）
- **注册名**: `PrinceBlanch`

## 字典示例


```c++
// `tutorials/multiphaseEuler/wallBoilingPolydisperseTwoGroups/constant/phaseProperties`
{
        continuousPhase liquid;

        coalescenceModels
        (
            PrinceBlanch
            {
                turbulence      on;
                buoyancy        on;
                laminarShear    off;
                C1              0.05;
            }
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
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `C1` | coefficient C1 | no | 0.356 |
| `h0` | initial film thickness | no | 1e-4m |
| `hf` | critical film thickness | no | 1e-8m |
| `turbulence` | Switch for collisions due to turbulence | yes | none |
| `buoyancy` | Switch for collisions due to buoyancy | yes | none |
| `laminarShear` | Switch for collisions due to laminar shear | yes | none |


## 控制方程与关联式
Model of Prince and Blanch (1990). The coalescence rate is calculated by

[
( _{ij}^{T} + _{ij}^{B} + _{ij}^{LS} )
_{ij}\;,
]

with the coalescence efficiency

[
_{ij} =
{exp}
(
- {{r_{ij}^3 _c}{16 }}
{ln} ({h_0}{h_f})
_c^{1/3}/r_{ij}^{2/3}
)\;,
]

the turbulent collision rate

[
_{ij}^{T} =
C_1 (d_i + d_j)^{2} _c^{1/3}
{d_{i}^{2/3} + d_{j}^{2/3}}\;,
]

the buoyancy-driven collision rate

[
_{ij}^{B} = S_{ij} | u_{ri} - u_{rj} |\;,
]

and the laminar shear collision rate

[
_{ij}^{LS} =
{1}{6} (d_i + d_j)^{3} {}_c\;.
]

The rise velocity of bubble i is calculated by

[
u_{ri} = {2.14 / (_c d_i ) + 0.505 g d_i}\;,
]

the equivalent radius by

[
r_{ij} = ( {1}{d_i} + {1}{d_j} )^{-1}\;,
]

the collision cross sectional area by

[
S_{ij} = {}{4} (d_i + d_j)^{2}\;,
]

and the shear strain rate by

[
{}_c = {mag}({symm}({grad}(U_c)))\;.
]

Note that in equation 2, the bubble radius has been substituted by the
bubble diameter, which leads to a different coefficient in equation 8.
Also the expression for the equivalent radius, equation 19 was corrected.

_{ij}^{T}   |  Turbulent collision rate [m3/s]
_{ij}^{B}   |  Buoyancy-driven collision rate [m3/s]
_{ij}^{LS}  |  Laminar shear collision rate [m3/s]
_{ij}      |  Coalescence efficiency [-]
r_{ij}            |  Equivalent radius [m]
_c            |  Density of continuous phase [kg/m3]
|  Surface tension [N/m]
h_0               |  Initial film thickness [m]
h_f               |  Critical film thickness [m]
_c        |  Continuous phase turbulent dissipation rate [m2/s3]
d_i               |  Diameter of bubble i [m]
d_j               |  Diameter of bubble j [m]
u_{ri}            |  Rise velocity of bubble i [m/s]
S_{ij}            |  Collision cross sectional area [m2]
g                 |  Gravitational constant [m/s2]
{}_c    |  Continuous phase shear strain rate [1/s]
U_c               |  Continuous phase velocity field [m/s]
Reference:
```
Prince, M. J., & Blanch, H. W. (1990).
Bubble coalescence and break‐up in air‐sparged bubble columns.
AIChE journal, 36(10), 1485-1499.
```

## 文献与源码依据
- 类: `Foam`::diameterModels::coalescenceModels::PrinceBlanch`
- 源码路径: `applications/modules/multiphaseEuler/populationBalance/coalescenceModels/PrinceBlanch/PrinceBlanch.C`

## 教程与模板
- `tutorials/multiphaseEuler/wallBoilingPolydisperseTwoGroups/constant/phaseProperties`
- `tutorials/multiphaseEuler/wallBoilingPolydisperse/constant/phaseProperties`

## 注意事项
- 类型名必须与 RTS 注册名一致：`PrinceBlanch`。
