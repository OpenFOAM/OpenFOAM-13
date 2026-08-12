# DahnekeInterpolation

## 一句话
Interpolation formula of Dahneke (1983) as presented by Otto et al. (1999).

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler（populationBalance）
- **族**: 聚并（基类 `coalescenceModel`）
- **注册名**: `DahnekeInterpolation`

## 字典示例


```c++
// `tutorials/multiphaseEuler/titaniaSynthesisSurface/constant/phaseProperties`
{
        continuousPhase vapour;

        coalescenceModels
        (
            DahnekeInterpolation
            {
                sigma           340e-12;
            }
        );

        binaryBreakupModels
        ();

        breakupModels
        ();
    }
}

// ************************************************************************* //
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `DahnekeInterpolation`
- 基类: `coalescenceModel`


## 控制方程与关联式
Interpolation formula of Dahneke (1983) as presented by Otto et al. (1999).
Utilises collisional diameters.

References:
```
Dahneke, B. (1983).
Simple kinetic theory of Brownian diffusion in vapors and aerosols.
In Theory of dispersed multiphase flow (pp. 97-133). Academic Press.
```

```
Otto, E., Fissan, H., Park, S. H., & Lee, K. W. (1999).
The log-normal size distribution theory of Brownian aerosol coagulation
for the entire particle size range: part II—analytical solution using
Dahneke’s coagulation kernel.
Journal of aerosol science, 30(1), 17-34.
```

## 文献与源码依据
- 类: `Foam`::diameterModels::coalescenceModels::DahnekeInterpolation`
- 源码路径: `applications/modules/multiphaseEuler/populationBalance/coalescenceModels/DahnekeInterpolation/DahnekeInterpolation.C`

## 教程与模板
- `tutorials/multiphaseEuler/titaniaSynthesisSurface/constant/phaseProperties`
- `tutorials/multiphaseEuler/titaniaSynthesis/constant/phaseProperties`

## 注意事项
- 类型名必须与 RTS 注册名一致：`DahnekeInterpolation`。
