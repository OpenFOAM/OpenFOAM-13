# TomiyamaCorrelated

## 一句话
Correlation of Tomiyama et al.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 阻力（基类 `dragModel`）
- **注册名**: `TomiyamaCorrelated`

## 字典示例

> （由源码构造函数推断，无官方教程实例）

```cpp
// constant/momentumTransfer — drag 子字典
drag
{
    gas_dispersedIn_liquid
    {
        type            TomiyamaCorrelated;
        A               24;       // [-] 必填；无教程实例，示例取 Stokes 型前因子
    }
}
```

## 参数表

| 参数 | 默认 | 说明 |
|------|------|------|
| `A` | （必填） | dimless |

嵌套于 `constant/momentumTransfer` 的 `drag` 子字典；`<phasePair>` 键名依相名与 blending（如 `air_dispersedIn_water`）。

## 控制方程与关联式
Correlation of Tomiyama et al.

Reference:
```
Tomiyama, A., Celata, G. P., Hosokawa, S., & Yoshida, S. (2002).
Terminal velocity of single bubbles in surface tension force dominant
regime.
International Journal of Multiphase Flow, 28(9), 1497-1519.
```

## 文献与源码依据
- 类: `Foam`::dragModels::TomiyamaCorrelated`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/dragModels/TomiyamaCorrelated/TomiyamaCorrelated.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`TomiyamaCorrelated`。
