# `WALE`

## 一句话

Wall-Adapting Local Eddy-viscosity (WALE) SGS

## 适用条件（求解器 / 场 / 前提）

- 注册：incompressible + compressible LES

## 字典示例

```c++
// tutorials/incompressibleFluid/channel395/constant/momentumTransport
simulationType      LES;

LES
{
    model           WALE;

    turbulence      on;

    printCoeffs     on;

    delta           cubeRootVol;

    cubeRootVolCoeffs
    {
        deltaCoeff      1;
    }

    // 默认系数（源码头文件 Description）:
    WALECoeffs
    {
        Ck              0.094;
        Ce              1.048;
        Cw              0.325;
    }
}
```

## 参数表

| 参数 | 默认 | 含义 |
|------|------|------|
| `Ck` | 0.094 | 与 Smagorinsky/kEqn 家族一致的 $C_k$ |
| `Ce` | 1.048 | 耗散相关（基类/平衡估计） |
| `Cw` | 0.325 | WALE 特有壁面自适应系数 |
| `delta` | 子模型 | 滤波宽度 |

## 控制方程与关联式

The Wall-adapting local eddy-viscosity (WALE) SGS model.

文献：Nicoud, F., & Ducros, F. (1999). Subgrid-scale stress modelling based on the square of the velocity gradient tensor. Flow, Turbulence and Combustion, 62(3), 183–200.

See also：`Foam::LESModels::Smagorinsky`

## 文献与源码依据

- [`src/MomentumTransportModels/momentumTransportModels/LES/WALE/WALE.H`](../../../../src/MomentumTransportModels/momentumTransportModels/LES/WALE/WALE.H)

## 教程与模板

- `tutorials/incompressibleFluid/channel395/constant/momentumTransport`

## 注意事项

- 头文件 Description 中 `Ce` 行末曾出现笔误字符；以 `read()`/默认 `dimensionedScalar` 实现为准。
