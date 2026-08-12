# `kOmega`

## 一句话

标准 k–ω

## 适用条件（求解器 / 场 / 前提）

- 注册：incompressible + compressible
- phaseCompressible 子集含 `kEpsilon`/`RNGkEpsilon`/`kOmegaSST`
- phaseIncompressible 子集含 `kEpsilon`/`kOmegaSST`

## 字典示例


```c++
// `tutorials/compressibleVoF/damBreak/constant/momentumTransport`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

simulationType  RAS;

RAS
{
    model           kEpsilon;
    // model           kOmega;

    turbulence      on;

}


// ************************************************************************* //

// 默认系数（源码头文件 Description；可在 RAS 子字典覆盖）:
kOmegaCoeffs
        {
            betaStar    0.09;
            gamma       0.52;
            beta        0.072;
            alphak      0.5;
            alphaOmega  0.5;
        }
```

## 参数表


默认系数（源码头文件；可在模型子字典/`kOmegaCoeffs` 覆盖）：

| 参数 | 默认 | 含义 |
|------|------|------|
| `betaStar` | 0.09 | 见模型 Description |
| `gamma` | 0.52 | 见模型 Description |
| `beta` | 0.072 | 见模型 Description |
| `alphak` | 0.5 | 见模型 Description |
| `alphaOmega` | 0.5 | 见模型 Description |

量纲：模型常数一般为无量纲（另有注明除外）。

## 控制方程与关联式

Standard high Reynolds-number k-omega turbulence model for
incompressible and compressible flows.

References:
```
Wilcox, D. C. (1998).
Turbulence modeling for CFD
(Vol. 2, pp. 103-217). La Canada, CA: DCW industries.
```

The default model coefficients are
```
kOmegaCoeffs
{
betaStar    0.09;
gamma       0.52;
beta        0.072;
alphak      0.5;
alphaOmega  0.5;
}
```

## 文献与源码依据

- [`src/MomentumTransportModels/momentumTransportModels/RAS/kOmega/kOmega.H`](../../../src/MomentumTransportModels/momentumTransportModels/RAS/kOmega/kOmega.H)

## 教程与模板

- `tutorials/XiFluid/engine2Valve2D/constant/momentumTransport`
- `tutorials/shockFluid/diffuserIntake/constant/momentumTransport`
- `tutorials/multiRegion/CHT/wallBoiling/constant/fluid/momentumTransport.gas`
- `tutorials/multiRegion/CHT/wallBoiling/constant/fluid/momentumTransport.liquid`
- `tutorials/multiRegion/CHT/coolingSphere/templates/materials/air/momentumTransport`
- `tutorials/multiRegion/CHT/coolingSphere/templates/materials/water/momentumTransport`


## 注意事项

- 模型必须在对应库中注册（不可压/可压/相）；见族 README 注册表。
