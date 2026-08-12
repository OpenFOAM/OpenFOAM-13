# `RNGkEpsilon`

## 一句话

RNG k–ε

## 适用条件（求解器 / 场 / 前提）

- 注册：incompressible + compressible；phaseCompressible 子集含本模型

## 字典示例

```c++
// tutorials/multiphaseEuler/pipeBend/constant/momentumTransport.water
simulationType  RAS;

RAS
{
    model           RNGkEpsilon;
    turbulence      on;
    printCoeffs     on;

    // 默认系数（源码头文件 Description；可覆盖）:
    RNGkEpsilonCoeffs
    {
        Cmu         0.0845;
        C1          1.42;
        C2          1.68;
        C3          0;
        sigmak      0.71942;
        sigmaEps    0.71942;
        eta0        4.38;
        beta        0.012;
    }
}
```

## 参数表

| 参数 | 默认 | 含义 |
|------|------|------|
| `Cmu` | 0.0845 | $C_\mu$ |
| `C1` | 1.42 | $\varepsilon$ 产生项 |
| `C2` | 1.68 | $\varepsilon$ 耗散项 |
| `C3` | 0 | 压缩/浮力相关 |
| `sigmak` | 0.71942 | $k$ Prandtl |
| `sigmaEps` | 0.71942 | $\varepsilon$ Prandtl |
| `eta0` | 4.38 | RNG $\eta_0$ |
| `beta` | 0.012 | RNG $\beta$ |

## 控制方程与关联式

Renormalisation group k-epsilon turbulence model for incompressible and compressible flows.

文献：Yakhot et al. (1992), Physics of Fluids A, 4(7), 1510–1520；RDT 压缩项见 El Tahry (1983)。

## 文献与源码依据

- [`src/MomentumTransportModels/momentumTransportModels/RAS/RNGkEpsilon/RNGkEpsilon.H`](../../../../src/MomentumTransportModels/momentumTransportModels/RAS/RNGkEpsilon/RNGkEpsilon.H)

## 教程与模板

- `tutorials/multiphaseEuler/pipeBend/constant/momentumTransport.water`

## 注意事项

- 模型必须在对应库中注册；见族 README 注册表。
