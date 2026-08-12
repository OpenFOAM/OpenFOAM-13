# turbulentShear

## 一句话
Model describing coagulation due to turbulent shear. Utilises physical, i.e.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler（populationBalance）
- **族**: 聚并（基类 `coalescenceModel`）
- **注册名**: `turbulentShear`

## 字典示例

> 推断：`C` 无默认、必填。写在 `coalescenceModels`。

```c++
// constant/phaseProperties — populationBalanceCoeffs
populationBalanceCoeffs
{
    aggregates
    {
        continuousPhase vapour;

        coalescenceModels
        (
            turbulentShear
            {
                C               1;  // required, dimless（示例值，需按物理标定）
            }
        );

        binaryBreakupModels
        ();

        breakupModels
        ();
    }
}
```

## 参数表

| 参数 | 默认 | 说明 |
|------|------|------|
| `C` | （必填） | dimless |

写在 `constant/phaseProperties` 的 `populationBalanceCoeffs` / `coalescenceModels`。

## 控制方程与关联式
Model describing coagulation due to turbulent shear. Utilises physical, i.e.
collisional diameters.

## 文献与源码依据
- 类: `Foam`::diameterModels::coalescenceModels::turbulentShear`
- 源码路径: `applications/modules/multiphaseEuler/populationBalance/coalescenceModels/turbulentShear/turbulentShear.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`turbulentShear`。
