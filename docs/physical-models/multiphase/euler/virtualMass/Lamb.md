# Lamb

## 一句话
Virtual mass model of Lamb.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 虚拟质量（基类 `virtualMassModel`）
- **注册名**: `Lamb`

## 字典示例


> （由源码构造函数推断，无官方教程实例）

```c++
// constant/momentumTransfer — virtualMass 子字典
virtualMass
{
    <phasePair>
    {
        type            Lamb;
        // 本模型 ctor 无额外系数（可能继承基类 residual*）
    }
}
```

## 参数表

| 参数 | 说明 |
|------|------|
| `type` | 必须为 `Lamb` |
| （基类） | 部分模型继承 `residualRe` / `residualAlpha` 等，见对应基类 ctor |

本模型构造函数通常无额外专用系数。

## 控制方程与关联式
Virtual mass model of Lamb.

Reference:
```
Lamb, H. (1993).
Hydrodynamics.
Cambridge university press.
```

## 文献与源码依据
- 类: `Foam`::virtualMassModels::Lamb`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/virtualMassModels/Lamb/Lamb.C`

## 教程与模板
- `tutorials/incompressibleVoF/climbingRod/constant/fvModels`
- `tutorials/compressibleVoF/climbingRod/constant/fvModels`

## 注意事项
- 类型名必须与 RTS 注册名一致：`Lamb`。
