# LopezDeBertodano

## 一句话
Lopez de Bertodano (1992) turbulent dispersion model.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 湍流扩散（基类 `turbulentDispersionModel`）
- **注册名**: `LopezDeBertodano`

## 字典示例

摘自 `tutorials/multiphaseEuler/wallBoilingPolydisperse/constant/momentumTransfer`：

```cpp
// constant/momentumTransfer — turbulentDispersion 子字典
turbulentDispersion
{
    gas_dispersedIn_liquid
    {
        type            LopezDeBertodano;
        Ctd             1.0;      // [-]
        // 教程另写 residualAlpha 1e-3; —— 本类构造函数不读取该键
    }
}
```

## 参数表

| 参数 | 默认 | 说明 |
|------|------|------|
| `Ctd` | （必填） | dimless |

写在 `constant/momentumTransfer`（OpenFOAM-13）；相界面键名依 blending/相名；`<phasePair>` 键名依相名与 blending（如 `air_dispersedIn_water`）。

## 控制方程与关联式
Lopez de Bertodano (1992) turbulent dispersion model.

```
Lopez, D. B. M. (1992).
Turbulent bubbly two-phase flow in a triangular duct.
PhD Thesis, Rensselaer Polytechnic Institution.
```

## 文献与源码依据
- 类: `Foam`::turbulentDispersionModels::LopezDeBertodano`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/turbulentDispersionModels/LopezDeBertodano/LopezDeBertodano.C`

## 教程与模板
- [`tutorials/multiphaseEuler/wallBoilingPolydisperse/constant/momentumTransfer`](../../../../../tutorials/multiphaseEuler/wallBoilingPolydisperse/constant/momentumTransfer)

## 注意事项
- 类型名必须与 RTS 注册名一致：`LopezDeBertodano`。
