# `LRR`

## 一句话

Launder–Reece–Rodi RSM

## 适用条件（求解器 / 场 / 前提）
- 注册：incompressible + compressible
- phaseCompressible 子集含 `kEpsilon`/`RNGkEpsilon`/`kOmegaSST`
- phaseIncompressible 子集含 `kEpsilon`/`kOmegaSST`

## 字典示例

```c++
// `tutorials/incompressibleFluid/ductSecondaryFlow/constant/momentumTransport`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// simulationType RAS;
RAS
{
RASModel LRR;
turbulence on;
}
// *************************************************************************
// 
// 默认系数（源码头文件 Description；可在 RAS 子字典覆盖）: LRRCoeffs
{
Cmu 0.09;
C1 1.8;
C2 0.6;
Ceps1 1.44;
Ceps2 1.92;
Cs 0.25;
Ceps 0.15;
wallReflection yes;
kappa 0.41 Cref1 0.5;
Cref2 0.3;
couplingFactor 0.0;
}

```
## 参数表

默认系数（源码头文件；可在模型子字典/`LRRCoeffs` 覆盖）：
| 参数 | 默认 | 含义 |
|------|------|------|
| `Cmu` | 0.09 | 见模型 Description |
| `C1` | 1.8 | 见模型 Description |
| `C2` | 0.6 | 见模型 Description |
| `Ceps1` | 1.44 | 见模型 Description |
| `Ceps2` | 1.92 | 见模型 Description |
| `Cs` | 0.25 | 见模型 Description |
| `Ceps` | 0.15 | 见模型 Description |
| `wallReflection` | yes | 见模型 Description |
| `Cref1` | 0.5 | 见模型 Description |
| `Cref2` | 0.3 | 见模型 Description |
| `couplingFactor` | 0.0 | 见模型 Description |

## 控制方程与关联式

Launder, Reece and Rodi Reynolds-stress turbulence model for incompressible and compressible flows.



Including the recommended generalised gradient diffusion model of
Daly and Harlow:
```
Daly, B. J., & Harlow, F. H. (1970).
Transport equations in turbulence.
Physics of Fluids (1958-1988), 13(11), 2634-2649.
```

Optional Gibson-Launder wall-reflection is also provided:
```
Gibson, M. M., & Launder, B. E. (1978).
Ground effects on pressure fluctuations in the
atmospheric boundary layer.
Journal of Fluid Mechanics, 86(03), 491-511.
```

The default model coefficients are:
```
LRRCoeffs
{
Cmu             0.09;
C1              1.8;
C2              0.6;
Ceps1           1.44;
Ceps2           1.92;
Cs              0.25;
Ceps            0.15;

wallReflection  yes;
kappa           0.41
Cref1           0.5;
Cref2           0.3;

couplingFactor  0.0;
}
```

## 文献与源码依据

- [`src/MomentumTransportModels/momentumTransportModels/RAS/LRR/LRR.H`](../../../src/MomentumTransportModels/momentumTransportModels/RAS/LRR/LRR.H)

## 教程与模板

- `tutorials/incompressibleFluid/ductSecondaryFlow/constant/momentumTransport`


## 注意事项

- 模型必须在对应库中注册（不可压/可压/相）；见族 README 注册表。
