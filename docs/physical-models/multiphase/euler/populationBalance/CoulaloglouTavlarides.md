# CoulaloglouTavlarides

## 一句话
Model of Coulaloglou and Tavlarides (1977). The coalescence rate is

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler（populationBalance）
- **族**: 聚并（基类 `coalescenceModel`）
- **注册名**: `CoulaloglouTavlarides`

## 字典示例

> 推断：源码默认系数。写在 `coalescenceModels`。

```c++
// constant/phaseProperties — populationBalanceCoeffs
populationBalanceCoeffs
{
    bubbles
    {
        continuousPhase water;

        coalescenceModels
        (
            CoulaloglouTavlarides
            {
                C1              2.8;      // optional, default
                C2              1.83e9;   // optional, 1/m^2
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
| `C1` | Coefficient C1 | no | 2.8 |
| `C2` | Coefficient C2 | no | 1.83e9 |


## 控制方程与关联式
Model of Coulaloglou and Tavlarides (1977). The coalescence rate is
calculated by

[
C_1 (v_i^{2/3} + v_j^{2/3}) (v_i^{2/9} + v_j^{2/9})^{1/2}
{_c^{1/3}}{1 + _d}
{exp}
[
- C_2 {_c _c}{^2}
{_c}{(1 + _d)^{3}}
(
{v_i^{1/3} v_j^{1/3}}{v_i^{1/3} + v_j^{1/3}}
)^{4}
]
]

where

|  Surface tension [N/m]
v_i         |  Volume of droplet i [m^3]
v_j         |  Volume of droplet j [m^3]
_c  |  Turbulent dissipation rate of continuous phase [m^2/s^3]
_d    |  Total void fraction of disperse phase [-]
_c       |  Molecular dynamic viscosity of liquid phase [Pa s]
_c      |  Density of continuous phase [kg/m^3]
References:
```
Coulaloglou, C. A., & Tavlarides, L. L. (1977).
Description of interaction processes in agitated liquid-liquid
dispersions.
Chemical Engineering Science, 32(11), 1289-1297.
Eq. 37, p. 1294.
```

## 文献与源码依据
- 类: `Foam`::diameterModels::coalescenceModels::CoulaloglouTavlarides`
- 源码路径: `applications/modules/multiphaseEuler/populationBalance/coalescenceModels/CoulaloglouTavlarides/CoulaloglouTavlarides.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`CoulaloglouTavlarides`。
