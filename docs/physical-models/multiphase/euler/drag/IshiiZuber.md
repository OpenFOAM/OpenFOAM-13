# IshiiZuber

## 一句话
Ishii and Zuber (1979) drag model for dense dispersed bubbly flows.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 阻力（基类 `dragModel`）
- **注册名**: `IshiiZuber`

## 字典示例


> （由源码构造函数推断，无官方教程实例）

```c++
// constant/momentumTransfer — drag 子字典
drag
{
    <phasePair>
    {
        type            IshiiZuber;
        // 本模型 ctor 无额外系数（可能继承基类 residual*）
    }
}
```

## 参数表

| 参数 | 说明 |
|------|------|
| `type` | 必须为 `IshiiZuber` |
| （基类） | 部分模型继承 `residualRe` / `residualAlpha` 等，见对应基类 ctor |

本模型构造函数通常无额外专用系数。

## 控制方程与关联式
Ishii and Zuber (1979) drag model for dense dispersed bubbly flows.

Reference:
```
Ishii, M., & Zuber, N. (1979).
Drag coefficient and relative velocity in bubbly, droplet or particulate
flows.
AIChE Journal, 25(5), 843-855.
```

## 文献与源码依据
- 类: `Foam`::dragModels::IshiiZuber`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/dragModels/IshiiZuber/IshiiZuber.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`IshiiZuber`。
