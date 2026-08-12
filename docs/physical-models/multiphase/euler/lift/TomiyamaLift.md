# TomiyamaLift

## 一句话
Lift model of Tomiyama et al.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 升力（基类 `liftModel`）
- **注册名**: `TomiyamaLift`

## 字典示例


> （由源码构造函数推断，无官方教程实例）

```c++
// constant/momentumTransfer — lift 子字典
lift
{
    <phasePair>
    {
        type            TomiyamaLift;
        // 本模型 ctor 无额外系数（可能继承基类 residual*）
    }
}
```

## 参数表

| 参数 | 说明 |
|------|------|
| `type` | 必须为 `TomiyamaLift` |
| （基类） | 部分模型继承 `residualRe` / `residualAlpha` 等，见对应基类 ctor |

本模型构造函数通常无额外专用系数。

## 控制方程与关联式
Lift model of Tomiyama et al.

Reference:
```
Tomiyama, A., Tamai, H., Zun, I., & Hosokawa, S. (2002).
Transverse migration of single bubbles in simple shear flows.
Chemical Engineering Science, 57(11), 1849-1858.
```

The coefficient for pow3(EoH) proposed by Tomiyama (2002) has been modified
to make the model continuous at EoH = 10.7 while maintaining the
lift coefficient proposed by Tomiyama (2002) when EoH >= 10.7.

## 文献与源码依据
- 类: `Foam`::liftModels::TomiyamaLift`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/liftModels/TomiyamaLift/TomiyamaLift.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`TomiyamaLift`。
