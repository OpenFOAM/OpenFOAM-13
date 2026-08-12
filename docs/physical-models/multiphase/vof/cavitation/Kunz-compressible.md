# Kunz

## 一句话
Kunz cavitation model.

## 适用条件（求解器 / 场 / 前提）
- 适用: compressibleVoF（经 `VoFCavitation`）；亦被 multiphaseEulerCavitation 复用可压库
- **族**: 可压空化（基类 `cavitationModel`）
- **注册名**: `Kunz`

## 字典示例
```
model       Kunz;

liquid      liquid;

pSat        2300;

UInf        20;
tInf        0.005; // L = 0.1 m
Cv          1000;
Cc          1000;
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `liquid` | Name of the liquid phase | yes | — |
| `pSat` | Saturation vapor pressure | yes | — |
| `Uinf` | Free-stream velocity | yes | — |
| `tInf` | Vaporisation/condensation time scale | yes | — |
| `Cv` | Vapourisation rate coefficient | yes | — |
| `Cc` | Condensation rate coefficient | yes | Example: |


## 控制方程与关联式
Kunz cavitation model.

Slightly modified so that the condensation term is switched off when the
pressure is less than the saturation vapour pressure.  This change allows
the condensation term to be formulated as a coefficient multiplying (p -
p_sat) so that it can be included as an implicit term in the pressure
equation.

Reference:
```
Kunz, R. F., Boger, D. A., Stinebring, D. R., Chyczewski,
T. S., Lindau, J. W., Gibeling, H. J., ... & Govindan, T. (2000).
A preconditioned Navier–Stokes method for two-phase flows
with application to cavitation prediction.
Computers & Fluids, 29(8), 849-875.
```

## 文献与源码依据
- 类: `Foam`::compressible::cavitationModels::Kunz`
- 源码路径: `src/twoPhaseModels/compressibleCavitation/Kunz/Kunz.C`

## 教程与模板
- `tutorials/multiphaseEuler/hydrofoil/constant/fvModels`
- `tutorials/incompressibleVoF/propeller/constant/fvModels`
- `tutorials/incompressibleVoF/cavitatingBullet/constant/fvModels`
- `tutorials/compressibleVoF/throttle/constant/fvModels`

## 注意事项
- 类型名必须与 RTS 注册名一致：`Kunz`。
