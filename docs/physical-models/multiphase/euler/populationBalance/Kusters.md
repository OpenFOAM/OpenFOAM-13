# Kusters

## 一句话
Solid particle breakage model of Kusters (1991). The breakage rate is

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler（populationBalance）
- **族**: 破碎（基类 `breakupModel`）
- **注册名**: `Kusters`

## 字典示例


```c++
// `tutorials/multiphaseEuler/pipeBend/constant/phaseProperties`
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

- 注册名 / `type`: `Kusters`
- 基类: `breakupModel`


## 控制方程与关联式
Solid particle breakage model of Kusters (1991). The breakage rate is
calculated by

[
{{4}{15}}{{}{}}
(-{_{crit}}{})
]

[
_{crit}={B}{R_{ci}}
]

[
R_{ci} = 0.5d_{p}({n_i}{k_c})^{1/D_f}
]

[
n_i = ({d_i}{d_{p}})^{D_f}
]

where

B               |   Critical force parameter for breakage [m3/s3]
d_i             |   Diameter of transported particle [m]
d_{p}           |   Diameter of primary particles [m]
D_f             |   Fractal dimension of particle [-]
k_c             |   Constant relative to packing density [-]
n_i             |   Number of primary particles in agglomerate [-]
|   Kinematic viscosity of continuous phase [m2/s]
|   Continuous phase turbulent dissipation rate [m2/s3]
_{crit} |   Critical turbulent dissipation rate [m2/s3]
Reference:
```
Kusters, K. A. (1991).
The influence of turbulence on aggregation of small particles in
agitated vessels.
PhD Thesis
```

## 文献与源码依据
- 类: `Foam`::diameterModels::breakupModels::Kusters`
- 源码路径: `applications/modules/multiphaseEuler/populationBalance/breakupModels/Kusters/Kusters.C`

## 教程与模板
- `tutorials/multiphaseEuler/pipeBend/constant/phaseProperties`

## 注意事项
- 类型名必须与 RTS 注册名一致：`Kusters`。
