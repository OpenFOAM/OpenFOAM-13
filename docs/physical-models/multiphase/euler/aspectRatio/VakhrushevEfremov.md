# VakhrushevEfremov

## 一句话
Aspect ratio model of Vakhrushev and Efremov.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 气泡纵横比（基类 `aspectRatioModel`）
- **注册名**: `VakhrushevEfremov`

## 字典示例


> （由源码构造函数推断，无官方教程实例）

```c++
// constant/phaseProperties — aspectRatio 子字典
aspectRatio
{
    <phasePair>
    {
        type            VakhrushevEfremov;
        // 本模型 ctor 无额外系数（可能继承基类 residual*）
    }
}
```

## 参数表

| 参数 | 说明 |
|------|------|
| `type` | 必须为 `VakhrushevEfremov` |
| （基类） | 部分模型继承 `residualRe` / `residualAlpha` 等，见对应基类 ctor |

本模型构造函数通常无额外专用系数。

## 控制方程与关联式
Aspect ratio model of Vakhrushev and Efremov.

Reference:
```
Vakhrushev, I. A., & Efremov, G. I. (1970).
Interpolation formula for computing the velocities of single gas bubbles
in liquids.
Chemistry and Technology of Fuels and Oils, 6(5), 376-379.
```

## 文献与源码依据
- 类: `Foam`::aspectRatioModels::VakhrushevEfremov`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/aspectRatioModels/VakhrushevEfremov/VakhrushevEfremov.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`VakhrushevEfremov`。
