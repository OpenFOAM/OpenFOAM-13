# SaffmanMei

## 一句话
Lift model of Saffman (1965) as extended by Mei (1992). Applicable to

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 升力（基类 `liftModel`）
- **注册名**: `SaffmanMei`

## 字典示例

摘自 `tutorials/multiphaseEuler/pipeBend/constant/momentumTransfer`：

```cpp
// constant/momentumTransfer — lift 子字典
lift
{
    particles_dispersedIn_water
    {
        type            SaffmanMei;
        residualRe      1e-6;     // [-]
    }
}
```

## 参数表

| 参数 | 默认 | 说明 |
|------|------|------|
| `residualRe` | （必填） | dimless |

写在 `constant/momentumTransfer`（OpenFOAM-13）；相界面键名依 blending/相名；`<phasePair>` 键名依相名与 blending（如 `air_dispersedIn_water`）。

## 控制方程与关联式
Lift model of Saffman (1965) as extended by Mei (1992). Applicable to
spherical particles.

References:
```
Saffman, P. G. T. (1965).
The lift on a small sphere in a slow shear flow.
Journal of fluid mechanics, 22(2), 385-400.

Mei, R. (1992).
An approximate expression for the shear lift force on a spherical
particle at finite Reynolds number.
International Journal of Multiphase Flow, 18(1), 145-147.
```

## 文献与源码依据
- 类: `Foam`::liftModels::SaffmanMei`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/liftModels/SaffmanMei/SaffmanMei.C`

## 教程与模板
- [`tutorials/multiphaseEuler/pipeBend/constant/momentumTransfer`](../../../../../tutorials/multiphaseEuler/pipeBend/constant/momentumTransfer)

## 注意事项
- 类型名必须与 RTS 注册名一致：`SaffmanMei`。
