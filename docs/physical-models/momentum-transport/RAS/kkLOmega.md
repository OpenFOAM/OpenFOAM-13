# `kkLOmega`

## 一句话

k–kl–ω 转捩（仅不可压）

## 适用条件（求解器 / 场 / 前提）

- **仅 incompressible** 额外 RAS（`incompressible/RAS/...`）
- 不适用: compressible 注册表

## 字典示例


```c++
// constant/momentumTransport
simulationType RAS;

RAS
{
    model           kkLOmega;
    turbulence      on;   // RAS/LES
}

// 默认系数（源码头文件）:
kkLOmegaCoeffs
        {
            A0             4.04
            As             2.12
            Av             6.75
            Abp            0.6
            Anat           200
            Ats            200
            CbpCrit        1.2
            Cnc            0.1
            CnatCrit       1250
            Cint           0.75
            CtsCrit        1000
            CrNat          0.02
            C11            3.4e-6
            C12            1.0e-10
            CR             0.12
            CalphaTheta    0.035
            Css            1.5
            CtauL          4360
            Cw1            0.44
            Cw2            0.92
            Cw3            0.3
            CwR            1.5
            Clambda        2.495
            CmuStd         0.09
            Prtheta        0.85
            Sigmak         1
            Sigmaw         1.17
        }
    
```

## 参数表

系数通常可在模型子字典覆盖（`Cmu`、`Ck` 等）；默认值见源码 `read`()`。

## 控制方程与关联式

Low Reynolds-number k-kl-omega turbulence model for
incompressible flows.

This turbulence model is described in:
```
Walters, D. K., & Cokljat, D. (2008).
A three-equation eddy-viscosity model for Reynolds-averaged
Navier–Stokes simulations of transitional flow.
Journal of Fluids Engineering, 130(12), 121401.
```

corrected according to:

```
Furst, J. (2013).
Numerical simulation of transitional flows with laminar kinetic energy.
Engineering Mechanics, 20(5), 379-388.
```

and includes the improvements proposed in:

```
Lopez, M., and Keith Walters, D. (2016).
A Recommended Correction to the kT−kL−ω Transition-Sensitive
Eddy-Viscosity Model.
Journal of Fluids Engineering, 139(2), 024501.
```

The default model coefficients are
```
kkLOmegaCoeffs
{
A0             4.04
As             2.12
Av             6.75
Abp            0.6
Anat           200
Ats            200
CbpCrit        1.2
Cnc            0.1
CnatCrit       1250
Cint           0.75
CtsCrit        1000
CrNat          0.02
C11            3.4e-6
C12            1.0e-10
CR             0.12
CalphaTheta    0.035
Css            1.5
CtauL          4360
Cw1            0.44
Cw2            0.92
Cw3            0.3
CwR            1.5
Clambda        2.495
CmuStd         0.09
Prtheta        0.85
Sigmak         1
Sigmaw         1.17
}
```

## 文献与源码依据

- [`src/MomentumTransportModels/incompressible/RAS/kkLOmega/kkLOmega.H`](../../../src/MomentumTransportModels/incompressible/RAS/kkLOmega/kkLOmega.H)

## 教程与模板

- `tutorials/incompressibleFluid/elipsekkLOmega/constant/momentumTransport`


## 注意事项

- 模型必须在对应库中注册（不可压/可压/相）；见族 README 注册表。
