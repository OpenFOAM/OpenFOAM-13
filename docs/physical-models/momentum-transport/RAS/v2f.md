# `v2f`

## 一句话

v2–f 模型

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
v2fCoeffs
        {
            Cmu         0.22;
            CmuKEps     0.09;
            C1          1.4;
            C2          0.3;
            CL          0.23;
            Ceta        70;
            Ceps2       1.9;
            Ceps3       -0.33;
            sigmaEps    1.3;
            sigmaK      1;
        }
```

## 参数表


默认系数（源码头文件；可在模型子字典/`v2fCoeffs` 覆盖）：

| 参数 | 默认 | 含义 |
|------|------|------|
| `Cmu` | 0.22 | 见模型 Description |
| `CmuKEps` | 0.09 | 见模型 Description |
| `C1` | 1.4 | 见模型 Description |
| `C2` | 0.3 | 见模型 Description |
| `CL` | 0.23 | 见模型 Description |
| `Ceta` | 70 | 见模型 Description |
| `Ceps2` | 1.9 | 见模型 Description |
| `Ceps3` | -0.33 | 见模型 Description |
| `sigmaEps` | 1.3 | 见模型 Description |
| `sigmaK` | 1 | 见模型 Description |

量纲：模型常数一般为无量纲（另有注明除外）。

## 控制方程与关联式

Lien and Kalitzin's v2-f turbulence model for incompressible and
compressible flows, with a limit imposed on the turbulent viscosity given
by Davidson et al.

The model solves for turbulence kinetic energy k and turbulence dissipation
rate epsilon, with additional equations for the turbulence stress normal to
streamlines, v2, and elliptic damping function, f.

The variant implemented employs N=6, such that f=0 on walls.

Wall boundary conditions are:

k       = kLowReWallFunction
epsilon = epsilonWallFunction
v2      = v2WallFunction
f       = fWallFunction

These are applicable to both low- and high-Reynolds number flows.

Inlet values can be approximated by:

v2      = 2/3 k
f       = zero-gradient

References:
```
Lien, F. S., & Kalitzin, G. (2001).
Computations of transonic flow with the v2f turbulence model.
International Journal of Heat and Fluid Flow, 22(1), 53-61.

Davidson, L., Nielsen, P., & Sveningsson, A. (2003).
Modifications of the v2-f model for computing the flow in a
3D wall jet.
Turbulence, Heat and Mass Transfer, 4, 577-584
```

The default model coefficients are
```
v2fCoeffs
{
Cmu         0.22;
CmuKEps     0.09;
C1          1.4;
C2          0.3;
CL          0.23;
Ceta        70;
Ceps2       1.9;
Ceps3       -0.33;
sigmaEps    1.3;
sigmaK      1;
}
```

Note:
If the kLowReWallFunction is employed, a velocity variant of the
turbulent viscosity wall function should be used, e.g. nutUWallFunction.
Turbulence k variants (nutk...) for this case will not behave correctly.

See also
Foam::RASModels::v2fBase
Foam::RASModels::kEpsilon
Foam::kLowReWallFunctionFvPatchScalarField
Foam::epsilonWallFunctionFvPatchScalarField
Foam::v2WallFunctionFvPatchScalarField
Foam::fWallFunctionFvPatchScalarField

## 文献与源码依据

- [`src/MomentumTransportModels/momentumTransportModels/RAS/v2f/v2f.H`](../../../src/MomentumTransportModels/momentumTransportModels/RAS/v2f/v2f.H)

## 教程与模板

- `tutorials/incompressibleFluid/pitzDailySteady/constant/momentumTransport`
- `tutorials/incompressibleFluid/pitzDailyScalarTransport/constant/momentumTransport`


## 注意事项

- 模型必须在对应库中注册（不可压/可压/相）；见族 README 注册表。
