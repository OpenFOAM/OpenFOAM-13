# entrainmentPressure

## 一句话
卷吸/回流压力条件（混合固定值与零梯度）。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`entrainmentPressure`
- **典型场**：p / p_rgh
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            entrainmentPressure;
    p0              uniform 1e5;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `phi` | Flux field name | no | phi |
| `rho` | Density field name | no | rho |
| `psi` | Compressibility field name | no | none |
| `gamma` | (Cp/Cv) | no | 1 |
| `p0` | Reference pressure | yes |  |

## 控制方程与关联式
卷吸/回流压力条件（混合固定值与零梯度）。

类头 `Description` 原文：

> This is a boundary condition for pressure suitable for boundaries at which
> the flow direction is uncertain but both inflow and/or outflow can occur.
> The condition switches based on the direction of flow. For outflow, the
> patch pressure is simply set to the reference pressure. For inflow, the
> patch pressure is reduced by the dynamic pressure calculated using the
> inflow velocity normal to the patch.
> 
> For incompressible flow, with pressure expressed in kinematic units, the
> pressure with inflow is calculated as:
> 
>     $$
>         p_p = p_0 - 0.5 |Un|^2
>     $$
>     where
>     
>         p_p     | pressure at patch [m^2/s^2]
>         p_0     | reference pressure [m^2/s^2]
>         Un      | patch normal velocity [m/s]
>     
> 
> The condition is similar to the totalPressure condition and includes
> further calculations of pressure for compressible flow under subsonic,
> transonic and supersonic regimes.
> 
> Like totalPressure, entrainmentPressure is usually applied in conjunction
> with the pressureInletOutletVelocity condition for velocity. The
> entrainmentPressure condition calculates the pressure using a normal
> velocity, based on the fluxes at the boundary. The totalPressure condition
> calculates the pressure using the inflow velocity itself.
> 
> With the pressureInletOutletVelocity condition, using the default
> tangentialVelocity of zero, any inflow velocity is constrained to be
> normal to the boundary, making the two pressure boundary conditions
> very similar. The entrainmentPressure condition is, however, more robust
> because it couples with the flux rather than velocity. The condition
> performs particularly well at boundaries where the flow direction tends
> to switch frequently between in and out of the domain.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/entrainmentPressure/entrainmentPressureFvPatchScalarField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/entrainmentPressure/entrainmentPressureFvPatchScalarField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/entrainmentPressure/entrainmentPressureFvPatchScalarField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/entrainmentPressure/entrainmentPressureFvPatchScalarField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/multiRegion/CHT/notchedRoller/0/fluid/p`](../../../tutorials/multiRegion/CHT/notchedRoller/0/fluid/p)
- [`tutorials/multiRegion/CHT/misalignedDuct/0/fluid/p.orig`](../../../tutorials/multiRegion/CHT/misalignedDuct/0/fluid/p.orig)
- [`tutorials/multicomponentFluid/SandiaD_LTS/0/p`](../../../tutorials/multicomponentFluid/SandiaD_LTS/0/p)
- [`tutorials/incompressibleFluid/simpleRushtonNCC/0/p.orig`](../../../tutorials/incompressibleFluid/simpleRushtonNCC/0/p.orig)
- [`tutorials/incompressibleFluid/simpleRushtonMRF/0/p.orig`](../../../tutorials/incompressibleFluid/simpleRushtonMRF/0/p.orig)
- [`tutorials/incompressibleFluid/pitzDailySteadyMappedToPart/0/p.orig`](../../../tutorials/incompressibleFluid/pitzDailySteadyMappedToPart/0/p.orig)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
