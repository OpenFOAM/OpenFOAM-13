# SchnerrSauer

## 一句话
SchnerrSauer cavitation model.

## 适用条件（求解器 / 场 / 前提）
- 适用: compressibleVoF（经 `VoFCavitation`）；亦被 multiphaseEulerCavitation 复用可压库
- **族**: 可压空化（基类 `cavitationModel`）
- **注册名**: `SchnerrSauer`

## 字典示例
```
model       SchnerrSauer;

liquid      liquid;

pSat        2300;

n           1.6e+13;
dNuc        2e-6;
Cv          1;
Cc          1;
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `liquid` | Name of the liquid phase | yes | — |
| `pSat` | Saturation vapor pressure | yes | — |
| `Uinf` | Free-stream velocity | yes | — |
| `n` | Bubble number density | yes | — |
| `dNuc` | Nucleation site diameter | yes | — |
| `Cv` | Vapourisation rate coefficient | yes | — |
| `Cc` | Condensation rate coefficient | yes | Example: |


## 控制方程与关联式
SchnerrSauer cavitation model.

Reference:
```
Schnerr, G. H., & Sauer, J. (2001, May).
Physical and numerical modeling of unsteady cavitation dynamics.
In Fourth international conference on multiphase flow (Vol. 1).
New Orleans, LO, USA: ICMF New Orleans.
```

## 文献与源码依据
- 类: `Foam`::compressible::cavitationModels::SchnerrSauer`
- 源码路径: `src/twoPhaseModels/compressibleCavitation/SchnerrSauer/SchnerrSauer.C`

## 教程与模板
- `tutorials/incompressibleVoF/propeller/constant/fvModels`
- `tutorials/incompressibleVoF/cavitatingBullet/constant/fvModels`
- `tutorials/compressibleVoF/throttle/constant/fvModels`
- `tutorials/compressibleVoF/ballValve/constant/fvModels`

## 注意事项
- 类型名必须与 RTS 注册名一致：`SchnerrSauer`。
