# AttouFerschneider

## 一句话
Attou and Ferschneider's Drag model for film flow through packed beds. The

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 阻力（基类 `dragModel`）
- **注册名**: `AttouFerschneider`

## 字典示例

摘自 `tutorials/multiphaseEuler/bed/constant/momentumTransfer`：

```cpp
// constant/momentumTransfer — drag 子字典
drag
{
    air_water_displacedBy_solid
    {
        type            AttouFerschneider;
        gas             air;      // 相名
        liquid          water;    // 相名
        solid           solid;    // 相名
        E1              280;      // [-]
        E2              4.8;      // [-]
    }
}
```

## 参数表

| 参数 | 默认 | 说明 |
|------|------|------|
| `E1` | （必填） | dimless |
| `E2` | （必填） | dimless |
| `gas` | （必填） |  |
| `liquid` | （必填） |  |
| `solid` | （必填） |  |

嵌套于 `constant/momentumTransfer` 的 `drag` 子字典；`<phasePair>` 键名依相名与 blending（如 `air_dispersedIn_water`）。

## 控制方程与关联式
Attou and Ferschneider's Drag model for film flow through packed beds. The
implementation follows the description of Gunjal and Ranade, who, in the
reference below, formulate the model in more convenient terms.

Reference:
```
Gunjal, P. R., & Ranade, V. V. (2007).
Modeling of laboratory and commercial scale hydro-processing reactors
using CFD.
Chemical Engineering Science, 62(18-20), 5512-5526.
```

## 文献与源码依据
- 类: `Foam`::dragModels::AttouFerschneider`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/dragModels/AttouFerschneider/AttouFerschneider.C`

## 教程与模板
- [`tutorials/multiphaseEuler/bed/constant/momentumTransfer`](../../../../../tutorials/multiphaseEuler/bed/constant/momentumTransfer)

## 注意事项
- 类型名必须与 RTS 注册名一致：`AttouFerschneider`。
