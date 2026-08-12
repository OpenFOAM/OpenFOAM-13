# Saito

## 一句话
Saito cavitation model.

## 适用条件（求解器 / 场 / 前提）
- 适用: compressibleVoF / multiphaseEulerCavitation；**无**不可压同名实现
- **族**: 可压空化（基类 `cavitationModel`）
- **注册名**: `Saito`

## 字典示例
```
model       Saito;

liquid      liquid;

pSat        2300;

Ca          0.1;  // Interfacial area concentration coefficient [1/m]
Cc          1;
Cv          1;
alphaNuc    0.001;
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `liquid` | Name of the liquid phase | yes | — |
| `pSat` | Saturation vapor pressure | yes | — |
| `Ca` | Interfacial area concentration coefficient [1/m] | yes | — |
| `Cv` | Vapourisation rate coefficient | yes | — |
| `Cc` | Condensation rate coefficient | yes | — |
| `alphaNuc` | Nucleation site volume fraction | yes | Example: |


## 控制方程与关联式
Saito cavitation model.

Reference:
```
Saito, Y., Takami, R., Nakamori, I., & Ikohagi, T. (2007).
Numerical analysis of unsteady behavior of cloud cavitation
around a NACA0015 foil. Computational Mechanics, 40, 85-96.
```

## 文献与源码依据
- 类: `Foam`::compressible::cavitationModels::Saito`
- 源码路径: `src/twoPhaseModels/compressibleCavitation/Saito/Saito.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`Saito`。
