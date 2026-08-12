# IATE

## 一句话
IATE (Interfacial Area Transport Equation) bubble diameter model.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 相直径模型（基类 `diameterModel`）
- **注册名**: `IATE`

## 字典示例


```c++
// `tutorials/multiphaseEuler/wallBoilingIATE/constant/phaseProperties`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

phases (gas liquid);

gas
{
    type            purePhaseModel;

    diameterModel   IATE;

    IATECoeffs
    {
        dMax            1e-2;
        dMin            1e-4;

        residualAlpha   1e-4;

        sources
        (
            wakeEntrainmentCoalescence
            {
                Cwe             0.002;
            }

            randomCoalescence
            {
                Crc             0.04;
                C               3;
                alphaMax        0.75;
            }

            turbulentBreakUp
            {
                Cti             0.085;
                WeCr            6;
            }
        );
    }

    residualAlpha   1e-6;
}

liquid
{
    type            purePhaseModel;

    diameterModel   none;

    residualAlpha   1e-6;
}

blending
{
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `IATE`
- 基类: `diameterModel`


## 控制方程与关联式
IATE (Interfacial Area Transport Equation) bubble diameter model.

Solves for the interfacial curvature per unit volume of the phase rather
than interfacial area per unit volume to avoid stability issues relating to
the consistency requirements between the phase fraction and interfacial area
per unit volume.  In every other respect this model is as presented in the
paper:

Reference:
```
Ishii, M., Kim, S., & Kelly, J. (2005).
Development of interfacial area transport equation.
Nuclear Engineering and Technology, 37(6), 525-536.
```

## 文献与源码依据
- 类: `Foam`::diameterModels::IATE`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/diameterModels/IATE/IATE.C`

## 教程与模板
- `tutorials/multiphaseEuler/wallBoilingIATE/constant/phaseProperties`
- `tutorials/multiphaseEuler/bubbleColumnIATE/constant/phaseProperties`

## 注意事项
- 类型名必须与 RTS 注册名一致：`IATE`。
