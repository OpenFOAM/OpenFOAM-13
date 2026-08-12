# `kOmegaSSTSAS`

## 一句话

SST-SAS

## 适用条件（求解器 / 场 / 前提）

- 注册：incompressible + compressible
- phaseCompressible 子集含 `kEpsilon`/`RNGkEpsilon`/`kOmegaSST`
- phaseIncompressible 子集含 `kEpsilon`/`kOmegaSST`

## 字典示例


> （由源码构造函数/头文件默认系数推断，无官方教程实例）

```c++
// constant/momentumTransport （由源码构造函数/头文件默认系数推断，无官方教程实例）
simulationType RAS;

RAS
{
    model           kOmegaSSTSAS;
    turbulence      on;

    kOmegaSSTSASCoeffs
            {
                // Default SST coefficients
                alphaK1     0.85;
                alphaK2     1.0;
                alphaOmega1 0.5;
                alphaOmega2 0.856;
                beta1       0.075;
                beta2       0.0828;
                betaStar    0.09;
                gamma1      5/9;
                gamma2      0.44;
                a1          0.31;
                b1          1.0;
                c1          10.0;
                F3          no;

                // Default SAS coefficients
                Cs          0.11;
                kappa       0.41;
                zeta2       3.51;
                sigmaPhi    2.0/3.0;
                C           2;

                // Delta must be specified for SAS e.g.
                delta cubeRootVol;

                cubeRootVolCoeffs
                {}
            }
}
```

## 参数表


默认系数（源码头文件；可在模型子字典/`kOmegaSSTSASCoeffs` 覆盖）：

| 参数 | 默认 | 含义 |
|------|------|------|
| `alphaK1` | 0.85 | 见模型 Description |
| `alphaK2` | 1.0 | 见模型 Description |
| `alphaOmega1` | 0.5 | 见模型 Description |
| `alphaOmega2` | 0.856 | 见模型 Description |
| `beta1` | 0.075 | 见模型 Description |
| `beta2` | 0.0828 | 见模型 Description |
| `betaStar` | 0.09 | 见模型 Description |
| `gamma1` | 5/9 | 见模型 Description |
| `gamma2` | 0.44 | 见模型 Description |
| `a1` | 0.31 | 见模型 Description |
| `b1` | 1.0 | 见模型 Description |
| `c1` | 10.0 | 见模型 Description |
| `F3` | no | 见模型 Description |
| `Cs` | 0.11 | 见模型 Description |
| `kappa` | 0.41 | 见模型 Description |
| `zeta2` | 3.51 | 见模型 Description |
| `sigmaPhi` | 2.0/3.0 | 见模型 Description |
| `C` | 2 | 见模型 Description |
| `delta` | cubeRootVol | 见模型 Description |

量纲：模型常数一般为无量纲（另有注明除外）。

## 控制方程与关联式

Scale-adaptive URAS model based on the k-omega-SST RAS model.

References:
```
Egorov, Y., & Menter F.R. (2008).
Development and Application of SST-SAS Model in the DESIDER Project.
Advances in Hybrid RANS-LES Modelling,
Notes on Num. Fluid Mech. And Multidisciplinary Design,
Volume 97, 261-270.
```

The model coefficients are
```
kOmegaSSTSASCoeffs
{
// Default SST coefficients
alphaK1     0.85;
alphaK2     1.0;
alphaOmega1 0.5;
alphaOmega2 0.856;
beta1       0.075;
beta2       0.0828;
betaStar    0.09;
gamma1      5/9;
gamma2      0.44;
a1          0.31;
b1          1.0;
c1          10.0;
F3          no;

// Default SAS coefficients
Cs          0.11;
kappa       0.41;
zeta2       3.51;
sigmaPhi    2.0/3.0;
C           2;

// Delta must be specified for SAS e.g.
delta cubeRootVol;

cubeRootVolCoeffs
{}
}
```

## 文献与源码依据

- [`src/MomentumTransportModels/momentumTransportModels/RAS/kOmegaSSTSAS/kOmegaSSTSAS.H`](../../../src/MomentumTransportModels/momentumTransportModels/RAS/kOmegaSSTSAS/kOmegaSSTSAS.H)

## 教程与模板

- 仓库 tutorials 中未检索到 `kOmegaSSTSAS` 字面配置；可参考同类 `simulationType` 案例并改 `model`。
- 注册见 [`README`](../README.md) 工厂表。


## 注意事项

- 模型必须在对应库中注册（不可压/可压/相）；见族 README 注册表。
