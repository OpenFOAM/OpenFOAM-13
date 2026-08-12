# constantTurbulentDispersionCoefficient

## 一句话
Constant coefficient turbulent dispersion model.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 湍流扩散（基类 `turbulentDispersionModel`）
- **注册名**: `constantCoefficient`（类 `constantTurbulentDispersionCoefficient`）

## 字典示例

**RTS 注册名**：`constantCoefficient`（类名 `constantTurbulentDispersionCoefficient`）。

> （由源码构造函数推断，无官方教程实例）

```cpp
// constant/momentumTransfer — turbulentDispersion 子字典
turbulentDispersion
{
    gas_dispersedIn_liquid
    {
        type            constantCoefficient;
        Ctd             1.0;      // [-]
    }
}
```

## 参数表

| 参数 | 默认 | 说明 |
|------|------|------|
| `Ctd` | （必填） | dimless |

写在 `constant/momentumTransfer`（OpenFOAM-13）；相界面键名依 blending/相名；`<phasePair>` 键名依相名与 blending（如 `air_dispersedIn_water`）。

## 控制方程与关联式
Constant coefficient turbulent dispersion model.

## 文献与源码依据
- 类: `Foam`::turbulentDispersionModels::constantTurbulentDispersionCoefficient`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/turbulentDispersionModels/constantTurbulentDispersionCoefficient/constantTurbulentDispersionCoefficient.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`constantTurbulentDispersionCoefficient`。
