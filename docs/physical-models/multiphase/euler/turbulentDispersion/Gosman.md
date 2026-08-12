# Gosman

## 一句话
Turbulent dispersion model of Gosman et al.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 湍流扩散（基类 `turbulentDispersionModel`）
- **注册名**: `Gosman`

## 字典示例

> （由源码构造函数推断，无官方教程实例；关键字同 Burns 的 `sigma`）

```cpp
// constant/momentumTransfer — turbulentDispersion 子字典
turbulentDispersion
{
    gas_dispersedIn_liquid
    {
        type            Gosman;
        sigma           0.9;      // [-]
    }
}
```

## 参数表

| 参数 | 默认 | 说明 |
|------|------|------|
| `sigma` | （必填） | dimless |

写在 `constant/momentumTransfer`（OpenFOAM-13）；相界面键名依 blending/相名；`<phasePair>` 键名依相名与 blending（如 `air_dispersedIn_water`）。

## 控制方程与关联式
Turbulent dispersion model of Gosman et al.

Reference:
```
Gosman, A. D., Lekakou, C., Politis, S., Issa, R. I., &
Looney, M. K. (1992).
Multidimensional modeling of turbulent two-phase flows in stirred
vessels.
AIChE Journal, 38(12), 1946-1956.
```

## 文献与源码依据
- 类: `Foam`::turbulentDispersionModels::Gosman`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/turbulentDispersionModels/Gosman/Gosman.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`Gosman`。
