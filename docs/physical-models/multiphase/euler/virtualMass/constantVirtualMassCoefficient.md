# constantVirtualMassCoefficient

## 一句话
Constant coefficient virtual mass model.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 虚拟质量（基类 `virtualMassModel`）
- **注册名**: `constantCoefficient`（类 `constantVirtualMassCoefficient`）

## 字典示例

**RTS 注册名**：`constantCoefficient`（类名 `constantVirtualMassCoefficient`）。

摘自 `tutorials/multiphaseEuler/bubbleColumn/constant/momentumTransfer`：

```cpp
// constant/momentumTransfer — virtualMass 子字典
virtualMass
{
    air_dispersedIn_water
    {
        type            constantCoefficient;
        Cvm             0.5;      // [-]
    }
}
```

## 参数表

| 参数 | 默认 | 说明 |
|------|------|------|
| `Cvm` | （必填） | dimless |

写在 `constant/momentumTransfer`（OpenFOAM-13）；相界面键名依 blending/相名；`<phasePair>` 键名依相名与 blending（如 `air_dispersedIn_water`）。

## 控制方程与关联式
Constant coefficient virtual mass model.

## 文献与源码依据
- 类: `Foam`::virtualMassModels::constantVirtualMassCoefficient`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/virtualMassModels/constantVirtualMassCoefficient/constantVirtualMassCoefficient.C`

## 教程与模板
- [`tutorials/multiphaseEuler/bubbleColumn/constant/momentumTransfer`](../../../../../tutorials/multiphaseEuler/bubbleColumn/constant/momentumTransfer)

## 注意事项
- 类型名必须与 RTS 注册名一致：`constantVirtualMassCoefficient`。
