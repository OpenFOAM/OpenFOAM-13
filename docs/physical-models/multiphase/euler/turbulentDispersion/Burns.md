# Burns

## 一句话
Turbulent dispersion model of Burns et al.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 湍流扩散（基类 `turbulentDispersionModel`）
- **注册名**: `Burns`

## 字典示例

摘自 `tutorials/multiphaseEuler/Grossetete/constant/momentumTransfer`：

```cpp
// constant/momentumTransfer — turbulentDispersion 子字典
turbulentDispersion
{
    gas_dispersedIn_liquid
    {
        type            Burns;
        sigma           0.7;      // [-] 湍流 Schmidt/Prandtl
    }
}
```

## 参数表

| 参数 | 默认 | 说明 |
|------|------|------|
| `sigma` | （必填） | dimless |

写在 `constant/momentumTransfer`（OpenFOAM-13）；相界面键名依 blending/相名；`<phasePair>` 键名依相名与 blending（如 `air_dispersedIn_water`）。

## 控制方程与关联式
Turbulent dispersion model of Burns et al.

References:
```
Burns, A. D., Frank, T., Hamill, I., & Shi, J. M. (2004, May).
The Favre averaged drag model for turbulent dispersion in Eulerian
multi-phase flows.
In 5th international conference on multiphase flow,
ICMF (Vol. 4, pp. 1-17).
```

## 文献与源码依据
- 类: `Foam`::turbulentDispersionModels::Burns`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/turbulentDispersionModels/Burns/Burns.C`

## 教程与模板
- [`tutorials/multiphaseEuler/Grossetete/constant/momentumTransfer`](../../../../../tutorials/multiphaseEuler/Grossetete/constant/momentumTransfer)

## 注意事项
- 类型名必须与 RTS 注册名一致：`Burns`。
