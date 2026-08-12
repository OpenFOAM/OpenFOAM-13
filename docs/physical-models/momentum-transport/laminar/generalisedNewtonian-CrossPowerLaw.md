# `generalisedNewtonian`-CrossPowerLaw`

## 一句话

generalisedNewtonian 粘度子模型：Cross

## 适用条件（求解器 / 场 / 前提）

- 父模型：`generalisedNewtonian`
- 子字典 `viscosityModel CrossPowerLaw;`

## 字典示例



```c++
// `tutorials/incompressibleFluid/offsetCylinder/constant/momentumTransport`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

simulationType laminar;

laminar
{
    model        generalisedNewtonian;

    viscosityModel CrossPowerLaw;

    nuInf           10;
    m               0.4;
    n               3;
}

// ************************************************************************* //
```

## 参数表


| 参数 | 默认/示例 | 说明 |
|------|-----------|------|
| `nuInf` | 10 | Usage |
| `m` | 0.4 | Usage |
| `n` | 3 | Usage |

正确写法：`laminar`.model = generalisedNewtonian`，再设 `viscosityModel CrossPowerLaw;`（不是 `model` generalisedNewtonian-CrossPowerLaw`）。

## 控制方程与关联式


Cross-Power law generalised Newtonian viscosity model

    The coefficient applied to strain rate $\gamma$ can be specified either
    as the constant `m` or the critical stress level at the transition to
    shear thinning `tauStar` if `tauStar` is provided:

    Kinematic viscosity [m^2/s]

$$
\nu = \nu_\infty + \frac{(\nu_0 - \nu_\infty)}{1 + (m\gamma)^n}
$$

or

$$
\nu = \nu_\infty
            + \frac{(\nu_0 - \nu_\infty)}
                   {1 + \left(\frac{\nu_0\gamma}{\tau^*}\right)^n}
$$

```c++
viscosityModel CrossPowerLaw;

         nuInf      10;
         m          0.4;
         n          3;
    
```

Note：零剪切粘度 `nu0` 是物性，通常写在 `physicalProperties` 而非本粘度子模型字典。

## 文献与源码依据

- [`src/MomentumTransportModels/momentumTransportModels/laminar/generalisedNewtonian/generalisedNewtonianViscosityModels/strainRateViscosityModels/CrossPowerLaw/CrossPowerLaw.H`](../../../src/MomentumTransportModels/momentumTransportModels/laminar/generalisedNewtonian/generalisedNewtonianViscosityModels/strainRateViscosityModels/CrossPowerLaw/CrossPowerLaw.H)

## 教程与模板

- `tutorials/incompressibleFluid/offsetCylinder/constant/momentumTransport`


## 注意事项

- 模型必须在对应库中注册（不可压/可压/相）；见族 README 注册表。
