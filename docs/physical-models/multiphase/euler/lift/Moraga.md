# Moraga

## 一句话
Lift model of Moraga et al.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 升力（基类 `liftModel`）
- **注册名**: `Moraga`

## 字典示例


> （由源码构造函数推断，无官方教程实例）

```c++
// constant/momentumTransfer — lift 子字典
lift
{
    <phasePair>
    {
        type            Moraga;
        // 本模型 ctor 无额外系数（可能继承基类 residual*）
    }
}
```

## 参数表

| 参数 | 说明 |
|------|------|
| `type` | 必须为 `Moraga` |
| （基类） | 部分模型继承 `residualRe` / `residualAlpha` 等，见对应基类 ctor |

本模型构造函数通常无额外专用系数。

## 控制方程与关联式
Lift model of Moraga et al.

References:
```
Otromke, M. (2013).
Implementation and Comparison of Correlations for interfacial Forces in
a Gas-Liquid System within an Euler-Euler Framework.
PhD Thesis.
```

```
Moraga, F. J., Bonetto, F. J., & Lahey, R. T. (1999).
Lateral forces on spheres in turbulent uniform shear flow.
International Journal of Multiphase Flow, 25(6-7), 1321-1372.
```

## 文献与源码依据
- 类: `Foam`::liftModels::Moraga`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/liftModels/Moraga/Moraga.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`Moraga`。
