# constantAspectRatio

## 一句话
Constant value aspect ratio model.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 气泡纵横比（基类 `aspectRatioModel`）
- **注册名**: `constant`（类 `constantAspectRatio`）

## 字典示例

**RTS 注册名**：`constant`（类名 `constantAspectRatio`）。

摘自 `tutorials/multiphaseEuler/Grossetete/constant/momentumTransfer`：

```cpp
aspectRatio
{
    type            constant;
    E0              1;            // [-]
}
```

## 参数表

| 参数 | 默认 | 说明 |
|------|------|------|
| `E0` | （必填） | dimless |

嵌套于 `constant/phaseProperties` 对应族子字典；`<phasePair>` 键名依相名与 blending（如 `air_dispersedIn_water`）。

## 控制方程与关联式
Constant value aspect ratio model.

## 文献与源码依据
- 类: `Foam`::aspectRatioModels::constantAspectRatio`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/aspectRatioModels/constantAspectRatio/constantAspectRatio.C`

## 教程与模板
- [`tutorials/multiphaseEuler/Grossetete/constant/momentumTransfer`](../../../../../tutorials/multiphaseEuler/Grossetete/constant/momentumTransfer)

## 注意事项
- 类型名必须与 RTS 注册名一致：`constantAspectRatio`。
