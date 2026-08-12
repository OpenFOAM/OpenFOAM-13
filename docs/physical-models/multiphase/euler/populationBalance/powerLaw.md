# powerLaw

## 一句话
Powerlaw kernel.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler（populationBalance）
- **族**: 破碎（基类 `breakupModel`）
- **注册名**: `powerLaw`

## 字典示例

摘自 `test/multiphaseEuler/populationBalance/breakup/constant/phaseProperties`：

```c++
// constant/phaseProperties — populationBalanceCoeffs
populationBalanceCoeffs
{
    bubbles
    {
        continuousPhase water;

        coalescenceModels
        ();

        binaryBreakupModels
        ();

        breakupModels
        (
            powerLaw
            {
                power           2.0;
                daughterSizeDistributionModel uniformBinary;
            }
        );
    }
}
```

## 参数表

| 参数 | 默认 | 说明 |
|------|------|------|
| `power` | （必填） |  |
| `daughterSizeDistributionModel` | （继承 breakupModel） | 如 `uniformBinary` |

写在 `constant/phaseProperties` 的 `populationBalanceCoeffs` / `breakupModels`。

## 控制方程与关联式
Powerlaw kernel.

## 文献与源码依据
- 类: `Foam`::diameterModels::breakupModels::powerLaw`
- 源码路径: `applications/modules/multiphaseEuler/populationBalance/breakupModels/powerLaw/powerLaw.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`powerLaw`。
