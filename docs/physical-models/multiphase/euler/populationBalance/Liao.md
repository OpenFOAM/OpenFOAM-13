# Liao

## 一句话
Bubble breakup model of Liao et al. (2015). The terminal velocities and drag

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler（populationBalance）
- **族**: 二元破碎（基类 `binaryBreakupModel`）
- **注册名**: `Liao`

## 字典示例

> 推断：源码 ctor；开关为必填。写在 `binaryBreakupModels`。TypeName：`Liao`。

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
            Liao
            {
                BTurb               1;      // optional, default
                BShear              1;      // optional, default
                BEddy               1;      // optional, default
                BFric               0.25;   // optional, default
                turbulence          on;     // required
                laminarShear        off;    // required
                turbulentShear      off;    // required
                interfacialFriction off;    // required
            }
        );

        breakupModels
        ();
    }
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `BTurb` | coefficient BTurb | no | 1 |
| `BShear` | coefficient BShear | no | 1 |
| `BEddy` | coefficient BEddy | no | 1 |
| `BFric` | coefficient BFric | no | 0.25 |
| `turbulence` | Switch for turbulence | yes | none |
| `laminarShear` | Switch for laminar shear | yes | none |
| `turbulentShear` | Switch for eddies | yes | none |
| `interfacialFriction` | Switch for friction | yes | none |


## 控制方程与关联式
Bubble breakup model of Liao et al. (2015). The terminal velocities and drag
coefficients are computed by an iterative procedure based on the drag model
of Ishii and Zuber (1979) at the beginning of the simulation, assuming
single bubbles rising in quiescent liquid.

References:
```
Liao, Y.; Rzehak, R.; Lucas, D.; Krepper, E. (2015).
Baseline closure models for dispersed bubbly flow: Bubble coalescence
and breakup.
Chemical Engineering Science, 122, 336-349.

Ishii, M., & Zuber, N. (1979).
Drag coefficient and relative velocity in bubbly, droplet or particulate
flows.
AIChE Journal, 25(5), 843-855.
```

## 文献与源码依据
- 类: `Foam`::diameterModels::binaryBreakupModels::Liao`
- 源码路径: `applications/modules/multiphaseEuler/populationBalance/binaryBreakupModels/Liao/Liao.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`Liao`。
