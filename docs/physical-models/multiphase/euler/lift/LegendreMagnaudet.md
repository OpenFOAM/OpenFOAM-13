# LegendreMagnaudet

## 一句话
Lift model of Legendre and Magnaudet.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 升力（基类 `liftModel`）
- **注册名**: `LegendreMagnaudet`

## 字典示例

> （由源码构造函数推断，无官方教程实例；关键字同 `SaffmanMei`）

```cpp
// constant/momentumTransfer — lift 子字典
lift
{
    gas_dispersedIn_liquid
    {
        type            LegendreMagnaudet;
        residualRe      1e-3;     // [-]
    }
}
```

## 参数表

| 参数 | 默认 | 说明 |
|------|------|------|
| `residualRe` | （必填） | dimless |

写在 `constant/momentumTransfer`（OpenFOAM-13）；相界面键名依 blending/相名；`<phasePair>` 键名依相名与 blending（如 `air_dispersedIn_water`）。

## 控制方程与关联式
Lift model of Legendre and Magnaudet.

References:
```
Otromke, M. (2013).
Implementation and Comparison of Correlations for interfacial Forces in
a Gas-Liquid System within an Euler-Euler Framework.
PhD Thesis.
```

```
Legendre, D., & Magnaudet, J. (1998).
The lift force on a spherical bubble in a viscous linear shear flow.
Journal of Fluid Mechanics, 368, 81-126.
```

## 文献与源码依据
- 类: `Foam`::liftModels::LegendreMagnaudet`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/liftModels/LegendreMagnaudet/LegendreMagnaudet.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`LegendreMagnaudet`。
