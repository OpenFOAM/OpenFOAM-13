# Prandtl

## 一句话
This simple model creates a heat transfer coefficient in proportion with

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 界面传热（基类 `heatTransferModel`）
- **注册名**: `Prandtl`

## 字典示例



> （由源码构造函数推断，无官方教程实例）

```c++
// constant/heatTransfer — heatTransfer 子字典
heatTransfer
{
    <phasePair>
    {
        type            Prandtl;
        heatTransfer
        gas_segregatedWith_liquid
        Pr              0.7;
    }
}
```

## 参数表

| 参数 | 默认 | 说明 |
|------|------|------|
| `Pr` | （必填） | dimless |

写在 `constant/heatTransfer`（OpenFOAM-13）；相界面键名依 blending/相名；`<phasePair>` 键名依相名与 blending（如 `air_dispersedIn_water`）。

## 控制方程与关联式
This simple model creates a heat transfer coefficient in proportion with
the corresponding drag model's momentum transfer coefficient. A
user-defined Prandtl number and a harmonic average of the phases'
specific heats are used to specify the constant of proportionality.

This model has no physical basis. It exists primarily for testing
purposes. It has the advantage of being applicable to any interface,
including those representing segregated configurations.

Example usage:
```
heatTransfer
{
gas_segregatedWith_liquid
{
type            Prandtl;
Pr              0.7;
}
}
```

## 文献与源码依据
- 类: `Foam`::heatTransferModels::Prandtl`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/heatTransferModels/Prandtl/Prandtl.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`Prandtl`。
