# fvModels 与 fvConstraints

Phase **5** 域目录：通用源项、孔隙、转子/螺旋桨、区域间传热、波浪 fvModels、辐射/云包装器，以及全部 `fvConstraints`。模块专用多相/点火等在此给**入口页**，物理细目交叉链到 Phase 3/4。

## 怎么用

1. 在 `constant/fvModels` / `constant/fvConstraints` 中设 `type`。
2. 运行时库模型加 `libs` (...);`（如 `libradiationModels`.so`、`libwaves`.so`、`liblagrangianParcel`.so`）。
3. 对照 [`../_inventory/rts-fvModels.md`](../_inventory/rts-fvModels.md)、[`../_inventory/rts-fvConstraints.md`](../_inventory/rts-fvConstraints.md)。

## 目录索引

| 子目录 | 内容 |
|--------|------|
| [general/](general/) | 通用源：热源、质量源、浮力、孔隙力、凝固熔化、半隐式源等 |
| [porosity/](porosity/) | `porosityModel`：DarcyForchheimer、fixedCoeff、powerLaw、solidification、大气 powerLawLopesdaCosta |
| [rotor-propeller/](rotor-propeller/) | `rotorDisk`、`propellerDisk`、`rigidBodyPropellerDisk` 及 blade/profile/trim |
| [inter-region/](inter-region/) | `heatTransfer`、`interRegionHeatTransfer`、`interRegionPorosityForce`、HTC 子模型 |
| [wrappers/](wrappers/) | `radiation`、`clouds` |
| [waves/](waves/) | `waveForcing`、`isotropicDamping`、`verticalDamping` |
| [module-specific/](module-specific/) | VoF / Euler / Xi / film 模块 fvModels 入口 |
| [constraints/](constraints/) | 全部 fvConstraints |

本域 Markdown 页数：**89**（含 README）。

## 导航

- [`../01-solver-matrix.md`](../01-solver-matrix.md) · [`../README.md`](../README.md) · [`../dynamic-mesh-waves-atm/`](../dynamic-mesh-waves-atm/)
