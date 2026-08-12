# randomCoalescence

## 一句话
Random coalescence IATE source as defined in paper:

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler（IATE）
- **族**: IATE 源项（基类 `IATEsource`）
- **注册名**: `randomCoalescence`

## 字典示例

```c++
// `tutorials/multiphaseEuler/wallBoilingIATE/constant/phaseProperties`
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
    default
    {
        type            continuous;
        phase           liquid;
    }
}

surfaceTension
{
    gas_liquid
    {
        type            constant;
        sigma           0.00176574;
    }
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `randomCoalescence`
- 基类: `IATEsource`


## 控制方程与关联式
Random coalescence IATE source as defined in paper:

Reference:
```
Ishii, M., Kim, S., & Kelly, J. (2005).
Development of interfacial area transport equation.
Nuclear Engineering and Technology, 37(6), 525-536.
```

## 文献与源码依据
- 类: `Foam`::diameterModels::IATEsources::randomCoalescence`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/diameterModels/IATE/IATEsources/randomCoalescence/IATErandomCoalescence.C`

## 教程与模板
- `tutorials/multiphaseEuler/wallBoilingIATE/constant/phaseProperties`
- `tutorials/multiphaseEuler/bubbleColumnIATE/constant/phaseProperties`

## 注意事项
- 类型名必须与 RTS 注册名一致：`randomCoalescence`。
