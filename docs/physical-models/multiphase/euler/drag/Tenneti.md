# Tenneti

## 一句话
Drag model of Tenneti et al. for monodisperse gas-particle flows obtained

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 阻力（基类 `dragModel`）
- **注册名**: `Tenneti`

## 字典示例


> （由源码构造函数推断，无官方教程实例）

```c++
// constant/momentumTransfer — drag 子字典
drag
{
    <phasePair>
    {
        type            Tenneti;
        // 本模型 ctor 无额外系数（可能继承基类 residual*）
    }
}
```

## 参数表

| 参数 | 说明 |
|------|------|
| `type` | 必须为 `Tenneti` |
| （基类） | 部分模型继承 `residualRe` / `residualAlpha` 等，见对应基类 ctor |

本模型构造函数通常无额外专用系数。

## 控制方程与关联式
Drag model of Tenneti et al. for monodisperse gas-particle flows obtained
with particle-resolved direct numerical simulations and accounting for the
effect of particle ensembles.

Reference:
```
Tenneti, S., Garg, R., & Subramaniam, S. (2011).
Drag law for monodisperse gas–solid systems using particle-resolved
direct numerical simulation of flow past fixed assemblies of spheres.
International Journal of Multiphase Flow, 37(9), 1072–1092.
```

## 文献与源码依据
- 类: `Foam`::dragModels::Tenneti`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/dragModels/Tenneti/Tenneti.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`Tenneti`。
