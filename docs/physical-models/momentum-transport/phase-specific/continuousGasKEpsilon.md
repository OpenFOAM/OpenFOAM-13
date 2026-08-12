# `continuousGasKEpsilon`

## 一句话

连续气相 k–ε

## 适用条件（求解器 / 场 / 前提）

- 适用: `multiphaseEuler` 相动量输运
- 注册：`applications/modules/multiphaseEuler/momentumTransportModels/momentumTransportModels.C`

## 字典示例

```c++
// constant/momentumTransport.<phase>  (multiphaseEuler)
simulationType RAS;   // 或 LES

RAS
{
    model           continuousGasKEpsilon;
    turbulence      on;
}
```


## 参数表

系数通常可在模型子字典覆盖（`Cmu`、`Ck` 等）；默认值见源码 `read`()`。

## 控制方程与关联式

k-epsilon model for the gas-phase in a two-phase system
supporting phase-inversion.

In the limit that the gas-phase fraction approaches zero a contribution from
the other phase is blended into the k and epsilon equations up to the
phase-fraction of alphaInversion at which point phase-inversion is
considered to have occurred and the model reverts to the pure single-phase
form.

This model is unpublished and is provided as a stable numerical framework
on which a more physical model may be built.

The default model coefficients are
```
    continuousGasKEpsilonCoeffs
    {
        Cmu             0.09;
        C1              1.44;
        C2              1.92;
        C3              0;
        sigmak          1.0;
        sigmaEps        1.3;
        alphaInversion  0.7;
    }
```


## 文献与源码依据

- [`src/MomentumTransportModels/phaseCompressible/RAS/continuousGasKEpsilon/continuousGasKEpsilon.H`](../../../src/MomentumTransportModels/phaseCompressible/RAS/continuousGasKEpsilon/continuousGasKEpsilon.H)
- 注册：`applications/modules/multiphaseEuler/momentumTransportModels/momentumTransportModels.C`


## 教程与模板

- `tutorials/multiphaseEuler/Grossetete/constant/momentumTransport.gas`
- `tutorials/multiphaseEuler/bubbleColumn/constant/momentumTransport.air`


## 注意事项

- 仅 `multiphaseEuler`（及链接同一工厂的多区域流体）可用；单相 `fluid`/`incompressibleFluid` **无**此 RTS。
- 通常写在 `constant/momentumTransport.<phase>`，不是混合物总字典。

