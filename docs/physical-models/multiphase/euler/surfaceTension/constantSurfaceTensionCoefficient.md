# constantSurfaceTensionCoefficient

## 一句话
Constant value surface tension model.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 表面张力系数（基类 `surfaceTensionCoefficientModel`）
- **注册名**: `constant`（类 `constantSurfaceTensionCoefficient`）

## 字典示例

**RTS 注册名**：`constant`（类名常为 `constantSurfaceTensionCoefficient`）。

摘自 `tutorials/multiphaseEuler/bubbleColumn/constant/phaseProperties`：

```cpp
// constant/phaseProperties — surfaceTension
surfaceTension
{
    air_water
    {
        type            constant;
        sigma           0.07;     // [N/m]
    }
}
```

## 参数表

| 参数 | 默认 | 说明 |
|------|------|------|
| `sigma` | （必填） | dimSigma |

嵌套于 `constant/phaseProperties` 对应族子字典；`<phasePair>` 键名依相名与 blending（如 `air_dispersedIn_water`）。

## 控制方程与关联式
Constant value surface tension model.

## 文献与源码依据
- 类: `Foam`::surfaceTensionCoefficientModels::constantSurfaceTensionCoefficient`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/surfaceTensionCoefficientModels/constantSurfaceTensionCoefficient/constantSurfaceTensionCoefficient.C`

## 教程与模板
- [`tutorials/multiphaseEuler/bubbleColumn/constant/phaseProperties`](../../../../../tutorials/multiphaseEuler/bubbleColumn/constant/phaseProperties)

## 注意事项
- 类型名必须与 RTS 注册名一致：`constantSurfaceTensionCoefficient`。
