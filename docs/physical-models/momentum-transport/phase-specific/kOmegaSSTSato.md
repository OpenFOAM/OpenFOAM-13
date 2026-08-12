# `kOmegaSSTSato`

## 一句话

Sato 气泡诱导 SST

## 适用条件（求解器 / 场 / 前提）

- 适用: `multiphaseEuler` 相动量输运
- 注册：`applications/modules/multiphaseEuler/momentumTransportModels/momentumTransportModels.C`

## 字典示例

```c++
// constant/momentumTransport.<phase>  (multiphaseEuler)
simulationType RAS;   // 或 LES

RAS
{
    model           kOmegaSSTSato;
    turbulence      on;
}
```


## 参数表

系数通常可在模型子字典覆盖（`Cmu`、`Ck` 等）；默认值见源码 `read`()`。

## 控制方程与关联式

Implementation of the k-omega-SST turbulence model for dispersed bubbly
flows with Sato (1981) bubble induced turbulent viscosity model.

Bubble induced turbulent viscosity model described in:
```
    Sato, Y., Sadatomi, M.
    "Momentum and heat transfer in two-phase bubble flow - I, Theory"
    International Journal of Multiphase FLow 7, pp. 167-177, 1981.
```

Turbulence model described in:
```
    Menter, F., Esch, T.
    "Elements of Industrial Heat Transfer Prediction"
    16th Brazilian Congress of Mechanical Engineering (COBEM),
    Nov. 2001
```

with the addition of the optional F3 term for rough walls from
```
    Hellsten, A.
    "Some Improvements in Menter’s k-omega-SST turbulence model"
    29th AIAA Fluid Dynamics Conference,
    AIAA-98-2554,
    June 1998.
```

Note that this implementation is written in terms of alpha diffusion
coefficients rather than the more traditional sigma (alpha = 1/sigma) so
that the blending can be applied to all coefficients in a consistent
manner.  The paper suggests that sigma is blended but this would not be
consistent with the blending of the k-epsilon and k-omega models.

Also note that the error in the last term of equation (2) relating to
sigma has been corrected.

Wall-functions are applied in this implementation by using equations (14)
to specify the near-wall omega as appropriate.

The blending functions (15) and (16) are not currently used because of the
uncertainty in their origin, range of applicability and that as y+ becomes
sufficiently small blending u_tau in this manner is clearly nonsense.

The default model coefficients correspond to the following:
```
    kOmegaSSTCoeffs
    {
        alphaK1     0.85034;
        alphaK2     1.0;
        alphaOmega1 0.5;
        alphaOmega2 0.85616;
        Prt         1.0;    // only for compressible
        beta1       0.075;
        beta2       0.0828;
        betaStar    0.09;
        gamma1      0.5532;
        gamma2      0.4403;
        a1          0.31;
        b1          1.0;
        c1          10.0;
        F3          no;
        Cmub        0.6;
    }
```


## 文献与源码依据

- [`src/MomentumTransportModels/phaseCompressible/RAS/kOmegaSSTSato/kOmegaSSTSato.H`](../../../src/MomentumTransportModels/phaseCompressible/RAS/kOmegaSSTSato/kOmegaSSTSato.H)
- 注册：`applications/modules/multiphaseEuler/momentumTransportModels/momentumTransportModels.C`


## 教程与模板

- `tutorials/multiRegion/CHT/wallBoiling/constant/fluid/momentumTransport.liquid`
- `tutorials/multiphaseEuler/wallBoilingPolydisperseTwoGroups/constant/momentumTransport.liquid`
- `tutorials/multiphaseEuler/wallBoilingPolydisperse/constant/momentumTransport.liquid`
- `tutorials/multiphaseEuler/wallBoilingIATE/constant/momentumTransport.liquid`
- `tutorials/multiphaseEuler/Grossetete/constant/momentumTransport.liquid`
- `tutorials/multiphaseEuler/bubblePipe/constant/momentumTransport.water`


## 注意事项

- 仅 `multiphaseEuler`（及链接同一工厂的多区域流体）可用；单相 `fluid`/`incompressibleFluid` **无**此 RTS。
- 通常写在 `constant/momentumTransport.<phase>`，不是混合物总字典。

