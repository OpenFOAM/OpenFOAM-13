# exponential

## 一句话
Exponential kernel.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler（populationBalance）
- **族**: 破碎（基类 `breakupModel`）
- **注册名**: `exponential`

## 字典示例

摘自 `test/multiphaseEuler/populationBalance/coalescenceAndBreakup/constant/phaseProperties`：

```c++
// constant/phaseProperties — populationBalanceCoeffs
populationBalanceCoeffs
{
    bubbles
    {
        continuousPhase water;

        coalescenceModels
        (
            hydrodynamic
            {}
        );

        binaryBreakupModels
        ();

        breakupModels
        (
            exponential
            {
                C               0.1;
                exponent        0.01;
                daughterSizeDistributionModel uniformBinary;
            }
        );
    }
}
```

## 参数表

| 参数 | 默认 | 说明 |
|------|------|------|
| `exponent` | （必填） |  |
| `C` | （必填） |  |
| `daughterSizeDistributionModel` | （继承 breakupModel） | 如 `uniformBinary` |

写在 `constant/phaseProperties` 的 `populationBalanceCoeffs` / `breakupModels`。

## 控制方程与关联式
Exponential kernel.

## 文献与源码依据
- 类: `Foam`::diameterModels::breakupModels::exponential`
- 源码路径: `applications/modules/multiphaseEuler/populationBalance/breakupModels/exponential/exponential.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`exponential`。
