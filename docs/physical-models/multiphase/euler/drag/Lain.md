# Lain

## 一句话
Drag model of Lain et al.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 阻力（基类 `dragModel`）
- **注册名**: `Lain`

## 字典示例


> （由源码构造函数推断，无官方教程实例）

```c++
// constant/momentumTransfer — drag 子字典
drag
{
    <phasePair>
    {
        type            Lain;
        // 本模型 ctor 无额外系数（可能继承基类 residual*）
    }
}
```

## 参数表

| 参数 | 说明 |
|------|------|
| `type` | 必须为 `Lain` |
| （基类） | 部分模型继承 `residualRe` / `residualAlpha` 等，见对应基类 ctor |

本模型构造函数通常无额外专用系数。

## 控制方程与关联式
Drag model of Lain et al.

References:
```
Otromke, M. (2013).
Implementation and Comparison of Correlations for interfacial Forces in
a Gas-Liquid System within an Euler-Euler Framework.
PhD Thesis.
```

```
Laın, S., Bröder, D., Sommerfeld, M., & Göz, M. F. (2002).
Modelling hydrodynamics and turbulence in a bubble column using the
Euler–Lagrange procedure.
International journal of multiphase flow, 28(8), 1381-1407.
```

## 文献与源码依据
- 类: `Foam`::dragModels::Lain`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/dragModels/Lain/Lain.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`Lain`。
