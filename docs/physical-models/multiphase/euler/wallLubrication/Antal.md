# Antal

## 一句话
Wall lubrication model of Antal et al.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 壁面润滑力（基类 `wallLubricationModel`）
- **注册名**: `Antal`

## 字典示例

摘自 `tutorials/multiphaseEuler/Grossetete/constant/momentumTransfer`：

```cpp
// constant/momentumTransfer — wallLubrication 子字典
wallLubrication
{
    gas_dispersedIn_liquid
    {
        type            Antal;
        Cw1             -0.01;    // [-]
        Cw2             0.05;     // [-]
    }
}
```

## 参数表

| 参数 | 默认 | 说明 |
|------|------|------|
| `Cw1` | （必填） | dimless |
| `Cw2` | （必填） | dimless |

写在 `constant/momentumTransfer`（OpenFOAM-13）；相界面键名依 blending/相名；`<phasePair>` 键名依相名与 blending（如 `air_dispersedIn_water`）。

## 控制方程与关联式
Wall lubrication model of Antal et al.

Reference:
```
Antal, S. P., Lahey Jr, R. T., & Flaherty, J. E. (1991).
Analysis of phase distribution in fully developed laminar bubbly
two-phase flow.
International Journal of Multiphase Flow, 17(5), 635-652.
```

## 文献与源码依据
- 类: `Foam`::wallLubricationModels::Antal`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/wallLubricationModels/Antal/Antal.C`

## 教程与模板
- [`tutorials/multiphaseEuler/Grossetete/constant/momentumTransfer`](../../../../../tutorials/multiphaseEuler/Grossetete/constant/momentumTransfer)

## 注意事项
- 类型名必须与 RTS 注册名一致：`Antal`。
