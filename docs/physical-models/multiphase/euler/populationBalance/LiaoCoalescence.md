# LiaoCoalescence

## 一句话
Bubble coalescence model of Liao et al. (2015). The terminal velocities and

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler（populationBalance）
- **族**: 聚并（基类 `coalescenceModel`）
- **注册名**: `Liao`（文档页名 `LiaoCoalescence`；与 binaryBreakup `Liao` 同名、分属不同列表）

## 字典示例

> 推断：源码 ctor。RTS TypeName 为 `Liao`，靠 `coalescenceModels` 列表区分。

```c++
// constant/phaseProperties — populationBalanceCoeffs
populationBalanceCoeffs
{
    bubbles
    {
        continuousPhase water;

        coalescenceModels
        (
            Liao
            {
                PMax            0.8;      // optional
                AH              3.7e-20;  // optional, J
                CEff            2.5;      // optional
                CTurb           1;        // optional
                CBuoy           1;        // optional
                CShear          1;        // optional
                CEddy           1;        // optional
                CWake           1;        // optional
                CPackMax        1e5;      // optional
                turbulence      on;       // required
                buoyancy        on;       // required
                laminarShear    off;      // required
                eddyCapture     off;      // required
                wakeEntrainment off;      // required
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
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `PMax` | Maximum packing limit | no | 0.8 |
| `CPackMax` | Maximum CPack coefficient | no | 1.0e5 |
| `AH` | Hamaker constant | no | 3.7e-20 |
| `CEff` | coefficient CEff | no | 2.5 |
| `CTurb` | coefficient CTurb | no | 1.0 |
| `CBuoy` | coefficient CBuoy | no | 1.0 |
| `CShear` | coefficient CShear | no | 1.0 |
| `CEddy` | coefficient CEddy | no | 1.0 |
| `CWake` | coefficient CWake | no | 1.0 |
| `turbulence` | Switch for turbulence | yes | none |
| `buoyancy` | Switch for buoyancy | yes | none |
| `laminarShear` | Switch for laminar shear | yes | none |
| `eddyCapture` | Switch for eddy capture | yes | none |
| `wakeEntrainment` | Switch for wake entrainment | yes | none |


## 控制方程与关联式
Bubble coalescence model of Liao et al. (2015). The terminal velocities and
drag coefficients are computed by an iterative procedure based on the drag
model of Ishii and Zuber (1979) at the beginning of the simulation, assuming
single bubbles rising in quiescent liquid.

Note that the original article contains a mistake concerning the value of
the coefficient CEff. A value of 2.5 instead of 5.0 should be used when
following the Weber number definition in the paper.

References:
```
Liao, Y.; Rzehak, R.; Lucas, D.; Krepper, E. (2015).
Baseline closure models for dispersed bubbly flow: Bubble coalescence
and breakup.
Chemical Engineering Science, 122, 336-349.

Liao, Y., Rzehak, R., Lucas, D., & Krepper, E. (2021).
Corrigendum to "Baseline closure model for dispersed bubbly flow:
Bubble coalescence and breakup" [Chem. Eng. Sci. 122 (2015) 336–349].
Chemical Engineering Science, 241, 116708.

Ishii, M., & Zuber, N. (1979).
Drag coefficient and relative velocity in bubbly, droplet or particulate
flows.
AIChE Journal, 25(5), 843-855.
```

## 文献与源码依据
- 类: `Foam`::diameterModels::coalescenceModels::LiaoCoalescence`
- 源码路径: `applications/modules/multiphaseEuler/populationBalance/coalescenceModels/LiaoCoalescence/LiaoCoalescence.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`Liao`（在 `coalescenceModels` 列表中）。
