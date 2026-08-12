# SyamlalOBrien

## 一句话
Syamlal, M., Rogers, W., & O’Brien, T. J. (1993).

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 阻力（基类 `dragModel`）
- **注册名**: `SyamlalOBrien`

## 字典示例


> （由源码构造函数推断，无官方教程实例）

```c++
// constant/momentumTransfer — drag 子字典
drag
{
    <phasePair>
    {
        type            SyamlalOBrien;
        // 本模型 ctor 无额外系数（可能继承基类 residual*）
    }
}
```

## 参数表

| 参数 | 说明 |
|------|------|
| `type` | 必须为 `SyamlalOBrien` |
| （基类） | 部分模型继承 `residualRe` / `residualAlpha` 等，见对应基类 ctor |

本模型构造函数通常无额外专用系数。

## 控制方程与关联式
Reference:
```
Syamlal, M., Rogers, W., & O’Brien, T. J. (1993).
Mfix documentation: Theory guide, technical note, doe/metc-94/1004,
ntis/de94000087.
National Technical Information Service.
```

## 文献与源码依据
- 类: `Foam`::dragModels::SyamlalOBrien`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/dragModels/SyamlalOBrien/SyamlalOBrien.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`SyamlalOBrien`。
