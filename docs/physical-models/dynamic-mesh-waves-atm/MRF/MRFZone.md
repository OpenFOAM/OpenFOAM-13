# MRFZone

## 一句话

多参考系（MRF）旋转区：在 cellZone 内以给定原点、轴与角速度处理相对/绝对通量。

## 适用条件（求解器 / 场 / 前提）

适用: 绝大多数流体求解器（finiteVolume MRF）；常配合 `MRFnoSlip` / `MRFslip` 等速度 BC。

## 字典示例

```c++
// constant/MRFProperties（或案例等价字典）
MRF1
{
    cellZone    rotor;
    origin      (0 0 0);
    axis        (0 0 1);
    omega       100;   // [rad/s] 或 Function1
}

```

## 参数表

| 参数 | 含义 | 量纲 |
|------|------|------|
| `cellZone` | MRF 旋转区 | — |
| `origin` | 旋转原点 | [m] |
| `axis` | 旋转轴 | — |
| `omega` | 角速度（`Function1`） | [rad/s] |


## 控制方程与关联式

在 MRF 区内将绝对速度与旋转参考系相对速度通过 \(\boldsymbol{\omega}\times\mathbf{r}\) 关联；通量在求解中作相对/绝对转换。细节见 `MRFZone`.C`。


## 文献与源码依据

- [`src/finiteVolume/cfdTools/general/MRF/MRFZone.H`](../../../../src/finiteVolume/cfdTools/general/MRF/MRFZone.H)

## 教程与模板

- `tutorials/fluid/mixerVessel2DMRF`
- 相关 BC：`MRFnoSlip`、`MRFslip`、`MRFFreestreamVelocity`

## 注意事项

- MRF 是参考系方法，不是动网格；与 `solidBody`/`sixDoF` 动网格勿混淆
- 旋转补丁通常需 MRF 专用速度 BC
