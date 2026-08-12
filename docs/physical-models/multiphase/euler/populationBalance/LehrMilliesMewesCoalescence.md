# LehrMilliesMewesCoalescence

## 一句话
Model of Lehr et al. (2002). The coalescence rate is calculated by

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler（populationBalance）
- **族**: 聚并（基类 `coalescenceModel`）
- **注册名**: `LehrMilliesMewes`（文档页名区分 coalescence / binaryBreakup）

## 字典示例

> 推断：源码默认。RTS TypeName 为 `LehrMilliesMewes`，靠 `coalescenceModels` 列表区分。

```c++
// constant/phaseProperties — populationBalanceCoeffs
populationBalanceCoeffs
{
    bubbles
    {
        continuousPhase water;

        coalescenceModels
        (
            LehrMilliesMewes
            {
                uCrit           0.08;  // optional, m/s
                alphaMax        0.6;   // optional
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
| `uCrit` | Crit. coalescence velocity | no | 0.08 |
| `alphaMax` | Maximum packing density | no | 0.6 |


## 控制方程与关联式
Model of Lehr et al. (2002). The coalescence rate is calculated by

[
{}{4} (d_i + d_j)^2 {min}(u^{}, u_{{crit}})
{exp}
[
- ({_{{max}}^{1/3}}{^{1/3}} - 1)^2
]\,,
]

where

[
u^{}
=
{max}
(
{2} _c^{1/3} {d_i^{2/3} + d_j^{2/3}},
|{u}_i - {u}_j|
)
]

is the characteristic velocity for coalescence. Note that a velocity
difference between bubble i and j is only present if the corresponding
size groups are assigned to different velocity groups.

d_i          |  Diameter of bubble i [m]
d_j          |  Diameter of bubble j [m]
_c   |  Turbulent dissipation rate of continuous phase [m^2/s^3]
|  Total void fraction of the bubbles [-]
_{max} |  Maximum packing density of the bubbles [-]
u_{crit}     |  Critical velocity for coalescence [m/s]
{u}_i    |  Velocity vector of bubble i [m/s]
{u}_j    |  Velocity vector of bubble j [m/s]
Reference:
```
Lehr, F., Millies, M., & Mewes, D. (2002).
Bubble‐size distributions and flow fields in bubble columns.
AIChE Journal, 48(11), 2426-2443.
```

## 文献与源码依据
- 类: `Foam`::diameterModels::coalescenceModels::LehrMilliesMewesCoalescence`
- 源码路径: `applications/modules/multiphaseEuler/populationBalance/coalescenceModels/LehrMilliesMewesCoalescence/LehrMilliesMewesCoalescence.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`LehrMilliesMewes`（在 `coalescenceModels` 中）。
