# `mixtureKEpsilon`

## 一句话

混合物 k–ε

## 适用条件（求解器 / 场 / 前提）

- 适用: `multiphaseEuler` 相动量输运
- 注册：`applications/modules/multiphaseEuler/momentumTransportModels/momentumTransportModels.C`

## 字典示例

```c++
// constant/momentumTransport.<phase>  (multiphaseEuler)
simulationType RAS;   // 或 LES

RAS
{
    model           mixtureKEpsilon;
    turbulence      on;
}
```


## 参数表

系数通常可在模型子字典覆盖（`Cmu`、`Ck` 等）；默认值见源码 `read`()`。

## 控制方程与关联式

Mixture k-epsilon turbulence model for two-phase gas-liquid systems

The basic structure of the model is based on:
```
    Behzadi, A., Issa, R. I., & Rusche, H. (2004).
    Modelling of dispersed bubble and droplet flow at high phase fractions.
    Chemical Engineering Science, 59(4), 759-770.
```

but an effective density for the gas is used in the averaging and an
alternative model for bubble-generated turbulence from:
```
    Lahey Jr, R. T. (2005).
    The simulation of multidimensional multiphase flows.
    Nuclear Engineering and Design, 235(10), 1043-1060.
```

The default model coefficients are
```
    mixtureKEpsilonCoeffs
    {
        Cmu         0.09;
        C1          1.44;
        C2          1.92;
        C3          C2;
        Cp          0.25; // Bubble generated turbulence
        alphap      0.3;  // Gas phase fraction below which
                          // bubble generated turbulence is included
        sigmak      1.0;
        sigmaEps    1.3;
    }
```


## 文献与源码依据

- [`src/MomentumTransportModels/phaseCompressible/RAS/mixtureKEpsilon/mixtureKEpsilon.H`](../../../src/MomentumTransportModels/phaseCompressible/RAS/mixtureKEpsilon/mixtureKEpsilon.H)
- 注册：`applications/modules/multiphaseEuler/momentumTransportModels/momentumTransportModels.C`


## 教程与模板

- `tutorials/multiRegion/CHT/multiphaseCoolingCylinder2D/constant/fluid/momentumTransport.oil`
- `tutorials/multiRegion/CHT/multiphaseCoolingCylinder2D/constant/fluid/momentumTransport.water`
- `tutorials/multiphaseEuler/bubbleColumn/constant/momentumTransport.air`
- `tutorials/multiphaseEuler/bubbleColumn/constant/momentumTransport.water`


## 注意事项

- 仅 `multiphaseEuler`（及链接同一工厂的多区域流体）可用；单相 `fluid`/`incompressibleFluid` **无**此 RTS。
- 通常写在 `constant/momentumTransport.<phase>`，不是混合物总字典。

