# aerosolDrag

## 一句话
Stokes drag with Cunningham slip correction. The slip correction coefficient

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 阻力（基类 `dragModel`）
- **注册名**: `aerosolDrag`

## 字典示例

摘自 `tutorials/multiphaseEuler/titaniaSynthesis/constant/momentumTransfer`
（常嵌在 `timeScaleFiltered` 的 `dragModel` 子字典内）：

```cpp
// constant/momentumTransfer — drag / dragModel
type            aerosolDrag;
sigma           340e-12;  // [m] Lennard-Jones 特征长度
A1              2.514;    // [-] 可选，默认 2.514
A2              0.8;      // [-] 可选，默认 0.8
A3              0.55;     // [-] 可选，默认 0.55
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `A1` | Coefficient A1 | no | 2.514 |
| `A2` | Coefficient A2 | no | 0.8 |
| `A3` | Coefficient A2 | no | 0.55 |
| `sigma` | Lennard-Jones parameter | yes | none |


## 控制方程与关联式
Stokes 阻力 + Cunningham 滑移修正：

$$
C_c = 1 + \lambda [A_1 + A_2 \exp(-A_3 d/\lambda)]/d
$$

平均自由程：

$$
\lambda = \frac{kT}{\sqrt{2}\,\pi\, p\, \sigma^{2}}
$$

| 符号 | 含义 |
|------|------|
| \(A_1,A_2,A_3\) | Cunningham 系数 [-] |
| \(\sigma\) | Lennard-Jones 参数 [m] |

文献：Davies, C. N. (1945). Definitive equations for the fluid resistance of spheres. Proceedings of the Physical Society, 57(4), 259.

## 文献与源码依据
- 类: `Foam`::dragModels::aerosolDrag`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/dragModels/aerosolDrag/aerosolDrag.C`

## 教程与模板
- [`tutorials/multiphaseEuler/titaniaSynthesis/constant/momentumTransfer`](../../../../../tutorials/multiphaseEuler/titaniaSynthesis/constant/momentumTransfer)

## 注意事项
- 类型名必须与 RTS 注册名一致：`aerosolDrag`。
