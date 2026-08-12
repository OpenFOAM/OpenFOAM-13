# `LaunderSharmaKE`

## 一句话

Launder–Sharma 低 Re k–ε

## 适用条件（求解器 / 场 / 前提）

- 注册：incompressible + compressible
- phaseCompressible 子集含 `kEpsilon`/`RNGkEpsilon`/`kOmegaSST`
- phaseIncompressible 子集含 `kEpsilon`/`kOmegaSST`

## 字典示例


```c++
// `tutorials/XiFluid/moriyoshiHomogeneous/moriyoshiHomogeneous/constant/momentumTransport`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

simulationType  RAS;

RAS
{
    model           LaunderSharmaKE;

    turbulence      on;

}


// ************************************************************************* //

// 默认系数（源码头文件 Description；可在 RAS 子字典覆盖）:
LaunderSharmaKECoeffs
        {
            Cmu         0.09;
            C1          1.44;
            C2          1.92;
            C3          0;
            alphah      1.0;    // only for compressible
            alphahk     1.0;    // only for compressible
            alphaEps    0.76923;
        }
```

## 参数表


默认系数（源码头文件；可在模型子字典/`LaunderSharmaKECoeffs` 覆盖）：

| 参数 | 默认 | 含义 |
|------|------|------|
| `Cmu` | 0.09 | 见模型 Description |
| `C1` | 1.44 | 见模型 Description |
| `C2` | 1.92 | 见模型 Description |
| `C3` | 0 | 见模型 Description |
| `alphah` | 1.0 | 见模型 Description |
| `alphahk` | 1.0 | 见模型 Description |
| `alphaEps` | 0.76923 | 见模型 Description |

量纲：模型常数一般为无量纲（另有注明除外）。

## 控制方程与关联式

Launder and Sharma low-Reynolds k-epsilon turbulence model for
incompressible and compressible and combusting flows including
rapid distortion theory (RDT) based compression term.

References:
```
Launder, B. E., & Sharma, B. I. (1974).
Application of the energy-dissipation model of turbulence to the
calculation of flow near a spinning disc.
Letters in heat and mass transfer, 1(2), 131-137.

For the RDT-based compression term:
El Tahry, S. H. (1983).
k-epsilon equation for compressible reciprocating engine flows.
Journal of Energy, 7(4), 345-353.
```

The default model coefficients are
```
LaunderSharmaKECoeffs
{
Cmu         0.09;
C1          1.44;
C2          1.92;
C3          0;
alphah      1.0;    // only for compressible
alphahk     1.0;    // only for compressible
alphaEps    0.76923;
}
```

## 文献与源码依据

- [`src/MomentumTransportModels/momentumTransportModels/RAS/LaunderSharmaKE/LaunderSharmaKE.H`](../../../src/MomentumTransportModels/momentumTransportModels/RAS/LaunderSharmaKE/LaunderSharmaKE.H)

## 教程与模板

- `tutorials/XiFluid/stratified/constant/momentumTransport`
- `tutorials/XiFluid/moriyoshiHomogeneous/moriyoshiHomogeneous/constant/momentumTransport`
- `tutorials/fluid/nacaAirfoil/constant/momentumTransport`


## 注意事项

- 模型必须在对应库中注册（不可压/可压/相）；见族 README 注册表。
