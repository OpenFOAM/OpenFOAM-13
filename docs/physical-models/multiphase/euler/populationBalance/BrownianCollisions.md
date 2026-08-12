# BrownianCollisions

## 一句话
Model describing coagulation due to Brownian motion. Utilises collisional

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler（populationBalance）
- **族**: 聚并（基类 `coalescenceModel`）
- **注册名**: `BrownianCollisions`

## 字典示例

> 推断：`sigma` 必填；A1–A3 用源码默认。`sigma` 量级参考 titania 案例 Dahneke 的 LJ 参数。

```c++
// constant/phaseProperties — populationBalanceCoeffs
populationBalanceCoeffs
{
    aggregates
    {
        continuousPhase vapour;

        coalescenceModels
        (
            BrownianCollisions
            {
                sigma           340e-12;  // required, m（示例，同 titania Dahneke）
                A1              2.514;    // optional
                A2              0.8;      // optional
                A3              0.55;     // optional
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
| `A1` | Coefficient A1 | no | 2.514 |
| `A2` | Coefficient A2 | no | 0.8 |
| `A3` | Coefficient A2 | no | 0.55 |
| `sigma` | Lennard-Jones parameter | yes | none |


## 控制方程与关联式
Model describing coagulation due to Brownian motion. Utilises collisional
diameters and the Cunningham slip correction. The slip correction
coefficient is implemented in the following form:

[
C_{c_i} = 1 + [A_1 + A_2 (-A_3 d_i/)]/d_i\,.
]

The coefficients default to the values proposed by Davis (1945). The mean
free path is computed by

[
= {kT}{{2} p ^{2}}\,.
]

A_1       | Coefficient [-]
A_2       | Coefficient [-]
A_3       | Coefficient [-]
| Lennard-Jones parameter [m]
Reference:
```
Davies, C. N. (1945).
Definitive equations for the fluid resistance of spheres.
Proceedings of the Physical Society, 57(4), 259.
```

## 文献与源码依据
- 类: `Foam`::diameterModels::coalescenceModels::BrownianCollisions`
- 源码路径: `applications/modules/multiphaseEuler/populationBalance/coalescenceModels/BrownianCollisions/BrownianCollisions.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`BrownianCollisions`。
