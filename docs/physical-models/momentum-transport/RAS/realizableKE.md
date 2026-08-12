# `realizableKE`

## 一句话

Realizable k–ε

## 适用条件（求解器 / 场 / 前提）

- 注册：incompressible + compressible
- phaseCompressible 子集含 `kEpsilon`/`RNGkEpsilon`/`kOmegaSST`
- phaseIncompressible 子集含 `kEpsilon`/`kOmegaSST`

## 字典示例


```c++
// `tutorials/compressibleVoF/ballValve/constant/momentumTransport`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

simulationType  RAS;

RAS
{
    model           realizableKE;

    turbulence      on;

}


// ************************************************************************* //

// 默认系数（源码头文件 Description；可在 RAS 子字典覆盖）:
realizableKECoeffs
        {
            A0          4.0;
            C2          1.9;
            sigmak      1.0;
            sigmaEps    1.2;
        }
```

## 参数表


默认系数（源码头文件；可在模型子字典/`realizableKECoeffs` 覆盖）：

| 参数 | 默认 | 含义 |
|------|------|------|
| `A0` | 4.0 | 见模型 Description |
| `C2` | 1.9 | 见模型 Description |
| `sigmak` | 1.0 | 见模型 Description |
| `sigmaEps` | 1.2 | 见模型 Description |

量纲：模型常数一般为无量纲（另有注明除外）。

## 控制方程与关联式

Realizable k-epsilon turbulence model for incompressible and compressible
flows.

References:
```
Shih, T. H., Liou, W. W., Shabbir, A., Yang, Z., & Zhu, J. (1994).
A new k-epsilon eddy viscosity model for high Reynolds number
turbulent flows: Model development and validation.
NASA STI/Recon Technical Report N, 95, 11442.

Shih, T. H., Liou, W. W., Shabbir, A., Yang, Z., & Zhu, J. (1995).
A New k-epsilon Eddy Viscosity Model for High Reynolds Number
Turbulent Flows.
Computers and Fluids, 24(3), 227-238.
```

The default model coefficients are
```
realizableKECoeffs
{
A0          4.0;
C2          1.9;
sigmak      1.0;
sigmaEps    1.2;
}
```

## 文献与源码依据

- [`src/MomentumTransportModels/momentumTransportModels/RAS/realizableKE/realizableKE.H`](../../../src/MomentumTransportModels/momentumTransportModels/RAS/realizableKE/realizableKE.H)

## 教程与模板

- `tutorials/incompressibleFluid/pitzDailySteady/constant/momentumTransport`
- `tutorials/incompressibleFluid/pitzDailyScalarTransport/constant/momentumTransport`
- `tutorials/incompressibleFluid/pipeCyclic/constant/momentumTransport`
- `tutorials/incompressibleFluid/oscillatingInlet/constant/momentumTransport`
- `tutorials/compressibleVoF/ballValve/constant/momentumTransport`


## 注意事项

- 模型必须在对应库中注册（不可压/可压/相）；见族 README 注册表。
