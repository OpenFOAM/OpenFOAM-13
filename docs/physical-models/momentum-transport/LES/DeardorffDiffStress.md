# `DeardorffDiffStress`

## 一句话

Deardorff 微分应力 SGS

## 适用条件（求解器 / 场 / 前提）
- 注册：incompressible + compressible
- phase* 子集：`Smagorinsky`/`kEqn`（见 phase*Models.C）

## 字典示例 > （由源码构造函数推断，无官方教程实例）

```c++
// constant/momentumTransport simulationType LES;
LES
{
model DeardorffDiffStress;
turbulence on;
}

```
## 参数表

系数通常可在模型子字典覆盖（`Cmu`、`Ck` 等）；默认值见源码 `read`()`。

## 控制方程与关联式

Differential SGS Stress Equation Model for incompressible and compressible flows



This SGS model uses a full balance equation for the SGS stress tensor to
simulate the behaviour of B.

This implementation is as described in the above paper except that the
triple correlation model of Donaldson is replaced with the generalised
gradient diffusion model of Daly and Harlow:
```
Daly, B. J., & Harlow, F. H. (1970).
Transport equations in turbulence.
Physics of Fluids (1958-1988), 13(11), 2634-2649.
```
with the default value for the coefficient Cs of 0.25 from
```
Launder, B. E., Reece, G. J., & Rodi, W. (1975).
Progress in the development of a Reynolds-stress turbulence closure.
Journal of fluid mechanics, 68(03), 537-566.
```

## 文献与源码依据

- [`src/MomentumTransportModels/momentumTransportModels/LES/DeardorffDiffStress/DeardorffDiffStress.H`](../../../src/MomentumTransportModels/momentumTransportModels/LES/DeardorffDiffStress/DeardorffDiffStress.H)

## 教程与模板

- 仓库 tutorials 中未检索到 `DeardorffDiffStress` 字面配置；可参考同类 `simulationType` 案例并改 `model`。
- 注册见 [`README`](../README.md) 工厂表。


## 注意事项

- 模型必须在对应库中注册（不可压/可压/相）；见族 README 注册表。
