# constantLiftCoefficient

## 一句话
Constant coefficient lift model.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 升力（基类 `liftModel`）
- **注册名**: `constantCoefficient`（类 `constantLiftCoefficient`）

## 字典示例

**RTS 注册名**：`constantCoefficient`（类名 `constantLiftCoefficient`）。

> （由源码构造函数推断，无官方教程实例；教程中升力多用 `Tomiyama`）

```cpp
// constant/momentumTransfer — lift 子字典
lift
{
    gas_dispersedIn_liquid
    {
        type            constantCoefficient;
        Cl              0.5;      // [-]
    }
}
```

## 参数表

| 参数 | 默认 | 说明 |
|------|------|------|
| `Cl` | （必填） | dimless |

写在 `constant/momentumTransfer`（OpenFOAM-13）；相界面键名依 blending/相名；`<phasePair>` 键名依相名与 blending（如 `air_dispersedIn_water`）。

## 控制方程与关联式
Constant coefficient lift model.

## 文献与源码依据
- 类: `Foam`::liftModels::constantLiftCoefficient`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/liftModels/constantLiftCoefficient/constantLiftCoefficient.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`constantLiftCoefficient`。
