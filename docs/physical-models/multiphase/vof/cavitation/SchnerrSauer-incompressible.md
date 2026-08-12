# SchnerrSauer

## 一句话
SchnerrSauer cavitation model.

## 适用条件（求解器 / 场 / 前提）
- 适用: incompressibleVoF（经 `VoFCavitation` fvModel）；不适用: compressibleVoF（用可压库同名实现）
- **族**: 不可压空化（基类 `cavitationModel`）
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
Schnerr–Sauer 空化模型（不可压两相库实现）。气泡数密度 \(n\)、成核直径 \(d_{Nuc}\) 进入成核体积分数与气泡半径倒数 \(1/R_B\)（见 `rRb` / `alphaNuc`）；蒸发/凝结速率由 \(C_v\)、\(C_c\) 与 \(p-p_{Sat}\) 驱动（`SchnerrSauer`.C`）。

文献（类头 Reference）：

```
Schnerr, G. H., & Sauer, J. (2001, May).
Physical and numerical modeling of unsteady cavitation dynamics.
In Fourth international conference on multiphase flow (Vol. 1).
New Orleans, LO, USA: ICMF New Orleans.
```

不可压构造函数实际读入：`n`, `dNuc`, `Cv`, `Cc`（及基类 `liquid`/`pSat`）。头文件 Usage 表中的 `Uinf` 对本实现**未使用**（对比 Kunz/Merkle）。

## 文献与源码依据
- 类: `Foam`::cavitationModels::SchnerrSauer`
- 源码路径: `src/twoPhaseModels/incompressibleCavitation/SchnerrSauer/SchnerrSauer.C`
- 经 [`VoFCavitation`-incompressibleVoF`](../fvModels/VoFCavitation-incompressibleVoF.md) 挂接

## 教程与模板
- `tutorials/incompressibleVoF/propeller/constant/fvModels`
- `tutorials/incompressibleVoF/cavitatingBullet/constant/fvModels`

## 注意事项
- 可压求解器请用同名页 [`SchnerrSauer`-compressible`](SchnerrSauer-compressible.md)（可压库路径不同）。
- 不可压库**无** `Saito`；勿在本求解器选 Saito。
- 类型名必须与 RTS 注册名一致：`SchnerrSauer`。
