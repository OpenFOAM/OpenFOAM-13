# `continuousGasKEqn`

## 一句话

连续气相 LES kEqn

## 适用条件（求解器 / 场 / 前提）

- 适用: `multiphaseEuler` 相动量输运
- 注册：`applications/modules/multiphaseEuler/momentumTransportModels/momentumTransportModels.C`

## 字典示例

```c++
// constant/momentumTransport.<phase>  (multiphaseEuler)
simulationType RAS;   // 或 LES

RAS
{
    model           continuousGasKEqn;
    turbulence      on;
}
```


## 参数表

系数通常可在模型子字典覆盖（`Cmu`、`Ck` 等）；默认值见源码 `read`()`。

## 控制方程与关联式

One-equation SGS model for the gas-phase in a two-phase system
supporting phase-inversion.

In the limit that the gas-phase fraction approaches zero a contribution from
the other phase is blended into the k-equation up to the phase-fraction of
alphaInversion at which point phase-inversion is considered to have occurred
and the model reverts to the pure single-phase form.

This model is unpublished and is provided as a stable numerical framework
on which a more physical model may be built.

The default model coefficients are
```
    continuousKEqnCoeffs
    {
        Ck              0.094;
        Ce              1.048;
        alphaInversion  0.7;
    }
```


## 文献与源码依据

- [`src/MomentumTransportModels/phaseCompressible/LES/continuousGasKEqn/continuousGasKEqn.H`](../../../src/MomentumTransportModels/phaseCompressible/LES/continuousGasKEqn/continuousGasKEqn.H)
- 注册：`applications/modules/multiphaseEuler/momentumTransportModels/momentumTransportModels.C`


## 教程与模板

- `tutorials/multiphaseEuler/bubbleColumnLES/constant/momentumTransport.air`


## 注意事项

- 仅 `multiphaseEuler`（及链接同一工厂的多区域流体）可用；单相 `fluid`/`incompressibleFluid` **无**此 RTS。
- 通常写在 `constant/momentumTransport.<phase>`，不是混合物总字典。

