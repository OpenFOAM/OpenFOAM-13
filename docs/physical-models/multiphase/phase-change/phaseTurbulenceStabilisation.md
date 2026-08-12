# phaseTurbulenceStabilisation

## 一句话

相分数很低时，用其他相的湍流属性稳定本相湍流方程

## 适用条件（求解器 / 场 / 前提）

- 适用：`multiphaseEuler`
- 基类：`fvModel`；库：`libmultiphaseEulerFvModels.so`
- 注册名：`phaseTurbulenceStabilisation`

## 字典示例

```c++
// tutorials/multiphaseEuler/wallBoilingPolydisperse/constant/fvModels（结构）
phaseTurbulenceStabilisation
{
    type    phaseTurbulenceStabilisation;

    libs    ("libmultiphaseEulerFvModels.so");

    phase   air;            // 被稳定的相名
    alphaInversion  0.1;    // 相分数阈值：低于此值开始耦合他相湍流
}
```

## 参数表

| 参数 | 必需 | 说明 |
|------|------|------|
| `type` | 是 | `phaseTurbulenceStabilisation` |
| `libs` | 是（若未链入） | `libmultiphaseEulerFvModels.so` |
| `phase` | 是 | 目标相 |
| `alphaInversion` | 是 | 相分数阈值（无量纲） |

## 控制方程与关联式

当相分数 → 0 时，该相湍流模型无法自洽给出属性。本 fvModel 在 $\alpha < \alpha_\mathrm{inversion}$ 时从其他相引入传递项以稳定 $k/\varepsilon/\omega$ 等方程。是对 `LaheyKEpsilon` / `continuousGasKEpsilon` 相翻转处理的推广，可与任意 RAS 组合使用。

调试：可用很小的 `alphaInversion`（如 `1e-2`）仅数值稳定；若模型本身不擅长分散相，可把阈值提高到连续→分散过渡分数。

## 文献与源码依据

- `applications/modules/multiphaseEuler/fvModels/phaseTurbulenceStabilisation/`

## 教程与模板

- `tutorials/multiRegion/CHT/wallBoiling/constant/fluid/fvModels`
- `tutorials/multiphaseEuler/wallBoilingPolydisperse/constant/fvModels`
- `tutorials/multiphaseEuler/wallBoilingIATE/constant/fvModels`
- `tutorials/multiphaseEuler/hydrofoil/constant/fvModels`

## 注意事项

- 类型名必须与 RTS 一致；忘记 `libs` 时会报 unknown fvModel。
