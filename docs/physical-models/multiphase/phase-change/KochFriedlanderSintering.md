# KochFriedlanderSintering

## 一句话
Sintering model of Koch and Friedlander (1990). The characteristic time for

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler（群体平衡烧结）
- **族**: 烧结（基类 `fvModel`）
- **注册名**: `KochFriedlanderSintering`

## 字典示例
```
sintering
{
type            KochFriedlanderSintering;
libs            ("libmultiphaseEulerFvModels.so");

populationBalance aggregates;

Cs              8.3e24;
n               4.0;
m               1.0;
Ta              3700.0;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `Cs` | Sintering time coefficient | yes | none |
| `n` | Particle diameter exponent | yes | none |
| `m` | Temperature exponent | yes | none |
| `Ta` | Activation temperature | yes | none |
| `dpMin` | Minimum primary particle diameter | no | 0 |


## 控制方程与关联式
Sintering model of Koch and Friedlander (1990). The characteristic time for
sintering is given by

[
= c_s d_{p_i}^n T^m (T_a/T [1 - d_{p,min}/d_{p_i}])\;.
]

Note that the correction factor in the exponential function can be
eliminated by setting $d_{p,min}$ to zero which is done by default.

Reference:
```
Koch, W., & Friedlander, S. K. (1990).
The effect of particle coalescence on the surface area of a coagulating
aerosol.
Journal of Colloid and Interface Science, 140(2), 419-427.
```

## 文献与源码依据
- 类: `Foam`::fv::KochFriedlanderSintering`
- 源码路径: `applications/modules/multiphaseEuler/fvModels/KochFriedlanderSintering/KochFriedlanderSintering.C`

## 教程与模板
- `tutorials/multiphaseEuler/titaniaSynthesisSurface/constant/fvModels`
- `tutorials/multiphaseEuler/titaniaSynthesis/constant/fvModels`

## 注意事项
- 类型名必须与 RTS 注册名一致：`KochFriedlanderSintering`。
