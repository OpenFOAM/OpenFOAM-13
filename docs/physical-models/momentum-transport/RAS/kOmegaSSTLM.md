# `kOmegaSSTLM`

## 一句话

SST 转捩（Langtry–Menter）

## 适用条件（求解器 / 场 / 前提）

- 注册：incompressible + compressible
- phaseCompressible 子集含 `kEpsilon`/`RNGkEpsilon`/`kOmegaSST`
- phaseIncompressible 子集含 `kEpsilon`/`kOmegaSST`

## 字典示例


```c++
// `tutorials/incompressibleFluid/T3A/constant/momentumTransport`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

simulationType RAS;

RAS
{
    model           kOmegaSSTLM;

    turbulence      on;

}


// ************************************************************************* //

// 默认系数（源码头文件 Description；可在 RAS 子字典覆盖）:
kOmegaSSTCoeffs
        {
            // Default SST coefficients
            alphaK1     0.85;
            alphaK2     1;
            alphaOmega1 0.5;
            alphaOmega2 0.856;
            beta1       0.075;
            beta2       0.0828;
            betaStar    0.09;
            gamma1      5/9;
            gamma2      0.44;
            a1          0.31;
            b1          1;
            c1          10;
            F3          no;

            // Default LM coefficients
            ca1         2;
            ca2         0.06;
            ce1         1;
            ce2         50;
            cThetat     0.03;
            sigmaThetat 2;

            lambdaErr   1e-6;
            maxLambdaIter 10;
        }
```

## 参数表


默认系数（源码头文件；可在模型子字典/`kOmegaSSTLMCoeffs` 覆盖）：

| 参数 | 默认 | 含义 |
|------|------|------|
| `alphaK1` | 0.85 | 见模型 Description |
| `alphaK2` | 1 | 见模型 Description |
| `alphaOmega1` | 0.5 | 见模型 Description |
| `alphaOmega2` | 0.856 | 见模型 Description |
| `beta1` | 0.075 | 见模型 Description |
| `beta2` | 0.0828 | 见模型 Description |
| `betaStar` | 0.09 | 见模型 Description |
| `gamma1` | 5/9 | 见模型 Description |
| `gamma2` | 0.44 | 见模型 Description |
| `a1` | 0.31 | 见模型 Description |
| `b1` | 1 | 见模型 Description |
| `c1` | 10 | 见模型 Description |
| `F3` | no | 见模型 Description |
| `ca1` | 2 | 见模型 Description |
| `ca2` | 0.06 | 见模型 Description |
| `ce1` | 1 | 见模型 Description |
| `ce2` | 50 | 见模型 Description |
| `cThetat` | 0.03 | 见模型 Description |
| `sigmaThetat` | 2 | 见模型 Description |
| `lambdaErr` | 1e-6 | 见模型 Description |
| `maxLambdaIter` | 10 | 见模型 Description |

量纲：模型常数一般为无量纲（另有注明除外）。

## 控制方程与关联式

Langtry-Menter 4-equation transitional SST model
based on the k-omega-SST RAS model.

References:
```
Langtry, R. B., & Menter, F. R. (2009).
Correlation-based transition modeling for unstructured parallelized
computational fluid dynamics codes.
AIAA journal, 47(12), 2894-2906.

Menter, F. R., Langtry, R., & Volker, S. (2006).
Transition modelling for general purpose CFD codes.
Flow, turbulence and combustion, 77(1-4), 277-303.

Langtry, R. B. (2006).
A correlation-based transition model using local variables for
unstructured parallelized CFD codes.
Phd. Thesis, Universität Stuttgart.
```

The model coefficients are
```
kOmegaSSTCoeffs
{
// Default SST coefficients
alphaK1     0.85;
alphaK2     1;
alphaOmega1 0.5;
alphaOmega2 0.856;
beta1       0.075;
beta2       0.0828;
betaStar    0.09;
gamma1      5/9;
gamma2      0.44;
a1          0.31;
b1          1;
c1          10;
F3          no;

// Default LM coefficients
ca1         2;
ca2         0.06;
ce1         1;
ce2         50;
cThetat     0.03;
sigmaThetat 2;

lambdaErr   1e-6;
maxLambdaIter 10;
}
```

## 文献与源码依据

- [`src/MomentumTransportModels/momentumTransportModels/RAS/kOmegaSSTLM/kOmegaSSTLM.H`](../../../src/MomentumTransportModels/momentumTransportModels/RAS/kOmegaSSTLM/kOmegaSSTLM.H)

## 教程与模板

- `tutorials/incompressibleFluid/T3A/constant/momentumTransport`


## 注意事项

- 模型必须在对应库中注册（不可压/可压/相）；见族 README 注册表。
