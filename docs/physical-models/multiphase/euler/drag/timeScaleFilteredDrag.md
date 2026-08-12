# timeScaleFilteredDrag

## 一句话
A time scale filtering wrapper around an underlying drag model intended for

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 阻力（基类 `dragModel`）
- **注册名**: `timeScaleFiltered`（类 `timeScaleFilteredDrag`）

## 字典示例

**RTS 注册名**：`timeScaleFiltered`（类名 `timeScaleFilteredDrag`）。

摘自 `tutorials/multiphaseEuler/titaniaSynthesis/constant/momentumTransfer`：

```cpp
// constant/momentumTransfer — drag 子字典
drag
{
    particles_dispersedIn_vapour
    {
        type            timeScaleFiltered;
        minRelaxTime    1e-4;     // [s]

        dragModel
        {
            type            aerosolDrag;
            sigma           340e-12;  // [m]
        }
    }
}
```

## 参数表

| 参数 | 默认 | 说明 |
|------|------|------|
| `minRelaxTime` | （必填） | dimTime |

嵌套于 `constant/momentumTransfer` 的 `drag` 子字典；`<phasePair>` 键名依相名与 blending（如 `air_dispersedIn_water`）。

## 控制方程与关联式
A time scale filtering wrapper around an underlying drag model intended for
simulations involving dispersed phase with a very small diameter.
The model limits the drag coefficient based on the relaxation time given.

## 文献与源码依据
- 类: `Foam`::dragModels::timeScaleFiltered`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/dragModels/timeScaleFilteredDrag/timeScaleFilteredDrag.C`

## 教程与模板
- [`tutorials/multiphaseEuler/titaniaSynthesis/constant/momentumTransfer`](../../../../../tutorials/multiphaseEuler/titaniaSynthesis/constant/momentumTransfer)

## 注意事项
- 类型名必须与 RTS 注册名一致：`timeScaleFilteredDrag`。
