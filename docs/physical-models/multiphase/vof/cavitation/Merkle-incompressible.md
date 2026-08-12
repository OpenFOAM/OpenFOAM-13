# Merkle

## 一句话
Merkle cavitation model.

## 适用条件（求解器 / 场 / 前提）
- 适用: incompressibleVoF（经 `VoFCavitation` fvModel）；不适用: compressibleVoF（用可压库同名实现）
- **族**: 不可压空化（基类 `cavitationModel`）
- **注册名**: `Merkle`

## 字典示例
```
model       Merkle;

liquid      liquid;

pSat        2300;

UInf        20;
tInf        0.005;  // L = 0.1 m
Cv          1e-3;
Cc          80;
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
Merkle cavitation model.

Reference:
```
Markle, C. L. (1998).
Computational modeling of the dynamics of sheet cavitation.
In Proc. 3rd International Symposium on Cavitation
(Vol. 2, pp. 307-311).
```

## 文献与源码依据
- 类: `Foam`::cavitationModels::Merkle`
- 源码路径: `src/twoPhaseModels/incompressibleCavitation/Merkle/Merkle.C`

## 教程与模板
- `tutorials/incompressibleVoF/propeller/constant/fvModels`
- `tutorials/incompressibleVoF/cavitatingBullet/constant/fvModels`
- `tutorials/compressibleVoF/throttle/constant/fvModels`

## 注意事项
- 类型名必须与 RTS 注册名一致：`Merkle`。
