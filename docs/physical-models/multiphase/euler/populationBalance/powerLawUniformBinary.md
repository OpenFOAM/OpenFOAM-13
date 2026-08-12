# powerLawUniformBinary

## 一句话
Powerlaw kernel with a uniform daughter size distribution.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler（populationBalance）
- **族**: 二元破碎（基类 `binaryBreakupModel`）
- **注册名**: `powerLawUniformBinary`

## 字典示例

摘自 `test/multiphaseEuler/populationBalance/binaryBreakup/constant/phaseProperties`：

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
        (
            powerLawUniformBinary
            {
                power           2.0;
            }
        );

        breakupModels
        ();
    }
}
```

## 参数表

| 参数 | 默认 | 说明 |
|------|------|------|
| `power` | （必填） |  |

写在 `constant/phaseProperties` 的 `populationBalanceCoeffs` / `binaryBreakupModels`。

## 控制方程与关联式
Powerlaw kernel with a uniform daughter size distribution.

## 文献与源码依据
- 类: `Foam`::diameterModels::binaryBreakupModels::powerLawUniformBinary`
- 源码路径: `applications/modules/multiphaseEuler/populationBalance/binaryBreakupModels/powerLawUniformBinary/powerLawUniformBinary.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`powerLawUniformBinary`。
