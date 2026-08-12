# constantCoalescence

## 一句话
Constant coalescence kernel.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler（populationBalance）
- **族**: 聚并（基类 `coalescenceModel`）
- **注册名**: `constant`（类名 `constantCoalescence`）

## 字典示例

> 推断：`rate` 必填。RTS TypeName 为 `constant`。

```c++
// constant/phaseProperties — populationBalanceCoeffs
populationBalanceCoeffs
{
    bubbles
    {
        continuousPhase water;

        coalescenceModels
        (
            constant
            {
                rate            1e-3;  // required, m^3/s（示例）
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
| `rate` | （必填） | dimVolume/dimTime |

写在 `constant/phaseProperties` 的 `populationBalanceCoeffs` / `coalescenceModels`。

## 控制方程与关联式
Constant coalescence kernel.

## 文献与源码依据
- 类: `Foam`::diameterModels::coalescenceModels::constantCoalescence`
- 源码路径: `applications/modules/multiphaseEuler/populationBalance/coalescenceModels/constantCoalescence/constantCoalescence.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`constant`。
