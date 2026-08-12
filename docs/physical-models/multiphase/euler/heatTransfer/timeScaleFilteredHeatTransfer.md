# timeScaleFilteredHeatTransfer

## 一句话
A time scale filtering wrapper around an underlying heat transfer model

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 界面传热（基类 `heatTransferModel`）
- **注册名**: `timeScaleFiltered`（类 `timeScaleFilteredHeatTransfer`）

## 字典示例

**RTS 注册名**：`timeScaleFiltered`（类名 `timeScaleFilteredHeatTransfer`）。

摘自 `tutorials/multiphaseEuler/titaniaSynthesis/constant/heatTransfer`：

```cpp
// constant/heatTransfer
particles_dispersedIn_vapour
{
    type            timeScaleFiltered;
    minRelaxTime    1e-4;         // [s]

    heatTransferModel
    {
        type            constantNu;
        Nu              1;        // [-]
    }
}
```

## 参数表

| 参数 | 默认 | 说明 |
|------|------|------|
| `minRelaxTime` | （必填） | dimTime |

写在 `constant/heatTransfer`（OpenFOAM-13）；相界面键名依 blending/相名；`<phasePair>` 键名依相名与 blending（如 `air_dispersedIn_water`）。

## 控制方程与关联式
A time scale filtering wrapper around an underlying heat transfer model
intended for simulations involving dispersed phase with a very small
diameter. The model limits the heat transfer coefficient based on the
relaxation time given.

## 文献与源码依据
- 类: `Foam`::heatTransferModels::timeScaleFiltered`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/heatTransferModels/timeScaleFilteredHeatTransfer/timeScaleFilteredHeatTransfer.C`

## 教程与模板
- [`tutorials/multiphaseEuler/titaniaSynthesis/constant/heatTransfer`](../../../../../tutorials/multiphaseEuler/titaniaSynthesis/constant/heatTransfer)

## 注意事项
- 类型名必须与 RTS 注册名一致：`timeScaleFilteredHeatTransfer`。
