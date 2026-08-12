# AdachiStuartFokkink

## 一句话
Model describing aggregation of solid particles in turbulent flows.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler（populationBalance）
- **族**: 聚并（基类 `coalescenceModel`）
- **注册名**: `AdachiStuartFokkink`

## 字典示例


```c++
// `tutorials/multiphaseEuler/pipeBend/constant/phaseProperties`
{
        continuousPhase water;

        coalescenceModels
        (
            AdachiStuartFokkink
            {}
        );

        binaryBreakupModels
        ();

        breakupModels
        (
            Kusters
            {
                daughterSizeDistributionModel Laakkonen;
                C4 2;
                B 50e-7;
                dP 250e-9;
                Df 2.4;
            }
        );
    }
}

// ************************************************************************* //
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `AdachiStuartFokkink`
- 基类: `coalescenceModel`


## 控制方程与关联式
Model describing aggregation of solid particles in turbulent flows.
Applicable when particles are smaller than the Kolmogorov length scale.
The coalescence rate is calculated by

[
{4}{3}({3}{10})^{0.5}
({}{})^{0.5}(d_i+d_j)^3
]

where

d_i      | Diameter of particle i [m]
d_j      | Diameter of particle j [m]
| Kinematic viscosity of continuous phase [m2/s]
| Continuous phase turbulent dissipation rate [m2/s3]
Reference:
```
Adachi, Y., Stuart, M. C., & Fokkink, R. (1994).
Kinetics of turbulent coagulation studied by means of end-over-end
rotation.
Journal of colloid and interface science, 165(2), 310-317.
```

## 文献与源码依据
- 类: `Foam`::diameterModels::coalescenceModels::AdachiStuartFokkink`
- 源码路径: `applications/modules/multiphaseEuler/populationBalance/coalescenceModels/AdachiStuartFokkink/AdachiStuartFokkink.C`

## 教程与模板
- `tutorials/multiphaseEuler/pipeBend/constant/phaseProperties`

## 注意事项
- 类型名必须与 RTS 注册名一致：`AdachiStuartFokkink`。
