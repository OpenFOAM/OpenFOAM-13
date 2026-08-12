# `kOmega2006`

## 一句话

Wilcox 2006 k–ω

## 适用条件（求解器 / 场 / 前提）

- 注册：incompressible + compressible
- phaseCompressible 子集含 `kEpsilon`/`RNGkEpsilon`/`kOmegaSST`
- phaseIncompressible 子集含 `kEpsilon`/`kOmegaSST`

## 字典示例


```c++
// `tutorials/incompressibleFluid/pitzDailyScalarTransport/constant/momentumTransport`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

simulationType RAS;

RAS
{
    // Tested with kEpsilon, realizableKE, kOmega, kOmega2006, kOmegaSST, v2f,
    // ShihQuadraticKE, LienCubicKE.
    model           kEpsilon;

    turbulence      on;


    viscosityModel  Newtonian;
}


// ************************************************************************* //

// 默认系数（源码头文件 Description；可在 RAS 子字典覆盖）:
kOmega2006Coeffs
        {
            Cmu         0.09;
            beta0       0.0708;
            gamma       0.52;
            Clim        0.875;
            alphak      0.6;
            alphaOmega  0.5;
        }
```

## 参数表


默认系数（源码头文件；可在模型子字典/`kOmega2006Coeffs` 覆盖）：

| 参数 | 默认 | 含义 |
|------|------|------|
| `Cmu` | 0.09 | 见模型 Description |
| `beta0` | 0.0708 | 见模型 Description |
| `gamma` | 0.52 | 见模型 Description |
| `Clim` | 0.875 | 见模型 Description |
| `alphak` | 0.6 | 见模型 Description |
| `alphaOmega` | 0.5 | 见模型 Description |

量纲：模型常数一般为无量纲（另有注明除外）。

## 控制方程与关联式

Standard (2006) high Reynolds-number k-omega turbulence model for
incompressible and compressible flows.

References:
```
Wilcox, D. C. (2006).
Turbulence modeling for CFD, 3rd edition
La Canada, CA: DCW industries, Inc.

Wilcox, D. C. (2008).
Formulation of the kw turbulence model revisited.
AIAA journal, 46(11), 2823-2838.
```

The default model coefficients are
```
kOmega2006Coeffs
{
Cmu         0.09;
beta0       0.0708;
gamma       0.52;
Clim        0.875;
alphak      0.6;
alphaOmega  0.5;
}
```

## 文献与源码依据

- [`src/MomentumTransportModels/momentumTransportModels/RAS/kOmega2006/kOmega2006.H`](../../../src/MomentumTransportModels/momentumTransportModels/RAS/kOmega2006/kOmega2006.H)

## 教程与模板

- `tutorials/incompressibleFluid/pitzDailySteady/constant/momentumTransport`
- `tutorials/incompressibleFluid/pitzDailyScalarTransport/constant/momentumTransport`


## 注意事项

- 模型必须在对应库中注册（不可压/可压/相）；见族 README 注册表。
