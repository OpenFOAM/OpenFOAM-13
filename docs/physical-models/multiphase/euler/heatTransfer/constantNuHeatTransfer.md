# constantNuHeatTransfer

## 一句话
Model which applies a user provided constant Nusselt number for interfacial

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 界面传热（基类 `heatTransferModel`）
- **注册名**: `constantNu`（类 `constantNuHeatTransfer`）

## 字典示例

**RTS 注册名**：`constantNu`（类名 `constantNuHeatTransfer`）。

摘自 `tutorials/multiphaseEuler/titaniaSynthesis/constant/heatTransfer`
（嵌在 `timeScaleFiltered` 的 `heatTransferModel` 内）：

```cpp
// constant/heatTransfer
type            constantNu;
Nu              1;            // [-]
```

## 参数表

| 参数 | 默认 | 说明 |
|------|------|------|
| `Nu` | （必填） | dimless |

写在 `constant/heatTransfer`（OpenFOAM-13）；相界面键名依 blending/相名；`<phasePair>` 键名依相名与 blending（如 `air_dispersedIn_water`）。

## 控制方程与关联式
Model which applies a user provided constant Nusselt number for interfacial
heat transfer.

## 文献与源码依据
- 类: `Foam`::heatTransferModels::constantNuHeatTransfer`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/heatTransferModels/constantNu/constantNuHeatTransfer.C`

## 教程与模板
- [`tutorials/multiphaseEuler/titaniaSynthesis/constant/heatTransfer`](../../../../../tutorials/multiphaseEuler/titaniaSynthesis/constant/heatTransfer)

## 注意事项
- 类型名必须与 RTS 注册名一致：`constantNuHeatTransfer`。
