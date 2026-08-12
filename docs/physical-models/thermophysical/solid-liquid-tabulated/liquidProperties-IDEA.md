# `IDEA`

## 一句话

预置液体物性库条目 `IDEA`（`liquidProperties` RTS）。

## 适用条件（求解器 / 场 / 前提）

- 适用: `liquidThermo` 路径、Lagrangian 蒸发、需要 `liquidProperties` 选择器的模型
- 通过 `liquidPropertiesSelector` / `type` <name>;` 选择

## 字典示例

```c++
// 典型：liquidThermo 或 liquidProperties 子字典
<name>  // 或 type IDEA;
// 具体关键字见 liquidThermos.C / liquidPropertiesSelector
```

## 参数表

预置关联式系数；一般无需用户改字典（可覆盖时见源码构造）。

## 控制方程与关联式

The IDEA fuel is constructed by adding 30% alphaMethylNaphthalene
with 70% n-decane.

The new properties have been calculated by adding the values in these
proportions and making a least square fit, using the same NSRDS-eq.
so that Y = 0.3*Y_naphthalene + 0.7*Y_decane

The valid Temperature range for n-decane is normally 243.51 - 617.70 K
and for the naphthalene it is 242.67 - 772.04 K
The least square fit was done in the interval 244 - 617 K

The critical temperature was taken to be 618.074 K, since this
is the 'c'-value in the rho-equation, which corresponds to Tcrit,
This value was then used in the fit for the NSRDS6-eq, which uses Tcrit.
(important for the latent heat and surface tension)

The molecular weights are 142.20 and 142.285 and for the IDEA fuel
it is thus 142.26 ( approximately 0.3*142.2 + 0.7*142.285 )

Critical pressure was set to the lowest one (n-Decane)

Critical volume... also the lowest one (naphthalene) 0.523 m^3/kmol

Second Virial Coefficient is n-Decane

## 文献与源码依据

- [`src/thermophysicalModels/thermophysicalProperties/liquidProperties/IDEA/IDEA.H`](../../../src/thermophysicalModels/thermophysicalProperties/liquidProperties/IDEA/IDEA.H)

## 教程与模板

- `src/thermophysicalModels/basic/liquidThermo/liquidThermos.C`

## 注意事项

- 名称大小写敏感；与化学组分名不一定相同。
