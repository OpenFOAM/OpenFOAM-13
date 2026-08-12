# solidificationMelting

## 一句话
This source is designed to model the effect of solidification and melting

## 适用条件（求解器 / 场 / 前提）
- 通用凝固熔化；单相/共轭常见；VoF 专用见 `VoFSolidificationMelting`
- **族**: 通用凝固熔化（基类 `fvModel`）
- **注册名**: `solidificationMelting`

## 字典示例
```
solidificationMelting1
{
type            solidificationMelting;

cellZone        iceZone;

Tsol            273;
L               334000;
thermoMode      thermo;
beta            50e-6;
rhoRef          800;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `Tsol` | Solidus temperature [K] | yes | — |
| `Tliq` | Liquidus temperature [K] | no | Tsol |
| `alpha1e` | Max eutectic melt fraction [0-1[ | no | 0 |
| `L` | Latent heat of fusion [J/kg] | yes | — |
| `relax` | Relaxation coefficient [0-1] | no | 0.9 |
| `thermoMode` | Thermo mode [thermo or lookup] | yes | — |
| `rhoRef` | Reference (solid) density [kg/m^3] | yes | — |
| `rho` | Name of density field | no | rho |
| `T` | Name of temperature field | no | T |
| `Cp` | Name of specific heat field | no | Cp |
| `U` | Name of velocity field | no | U |
| `phi` | Name of flux field | no | phi |
| `Cu` | Model coefficient [1/s] | no | 100000 |
| `q` | Model coefficient | no | 0.001 |
| `beta` | Thermal expansion coefficient [1/K] | yes | — |
| `g` | Acceleration due to gravity | no | — |


## 控制方程与关联式
This source is designed to model the effect of solidification and melting
processes, e.g. windshield defrosting.

The isotherm phase change occurs at the melting temperature, `Tsol` (= `Tliq`). The not isotherm phase change occurs between solidus and liquidus
temperature, `Tsol` < `Tliq` respectively, as long as the melt fraction is
greater than the max eutectic melt fraction, `alpha1e` (0 = pure_substance,
1 = eutectic_mixture is not permitted), where a linear eutectic melt
fraction to temperature relation is considered; e.g. given a specific
quantity of a binary system, `alpha1` is its melt fraction and `alpha0` is
its solid fraction, such that `alpha0` = 1 - `alpha1` therefore, assuming
infinite solute diffusion, the quantity of a component in solid phase is
(1 - `alpha1`) * `CS` where `CS` is the solid concentration of the
considered component and the quantity of a component in liquid phase is `alpha1` * `CL` where `CL` is the melt concentration of the considered
component; considering that the total quantity of a component must be equal
to the sum of the quantities of the considered component in the liquid and
solid phases, if `C0` is the initial concentration of the considered
component before the phase change, then:
`C0` = (1 - `alpha1`) * `CS` + `alpha1` * `CL`      (lever rule)
from which: `alpha1` = (`C0` - `CS`) / (`CL` - `CS`)
and thus:
- for a miscible binary system `alpha1e` = 0;
- for a binary system not miscible at solid state
`alpha1e` = `C0` / `CLE` where `CLE` is eutectic melt concentration;
- for a binary system partially-miscible at solid state
`alpha1e` = (`C0` - `CSE`) / (`CLE` - `CSE`) where `CSE` is eutectic
solid concentration of the relative solid solution.

The presence of the solid phase in the flow field is incorporated into the
model as a momentum porosity contribution; the energy associated with the
phase change is added as an enthalpy contribution.

References:
```
Voller, V. R., & Prakash, C. (1987).
A fixed grid numerical modelling methodology for convection-diffusion
mushy region phase-change problems.
International Journal of Heat and Mass Transfer, 30(8), 1709-1719.

Swaminathan, C. R., & Voller, V. R. (1992).
A general enthalpy method for modeling solidification processes.
Metallurgical transactions B, 23(5), 651-664.
```

The model generates the field `\<name\>:alpha1 which can be visualised to
to show the melt distribution as a fraction [0-1].

## 文献与源码依据
- 类: `Foam`::fv::solidificationMelting`
- 源码路径: `src/fvModels/general/solidificationMelting/solidificationMelting.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`solidificationMelting`。
