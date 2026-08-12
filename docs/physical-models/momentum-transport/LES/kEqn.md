# `kEqn`

## 一句话

一方程 SGS 动能模型

## 适用条件（求解器 / 场 / 前提）

- 注册：incompressible + compressible
- phase* 子集：`Smagorinsky`/`kEqn`

## 字典示例

```c++
// tutorials/fluid/pitzDaily/constant/momentumTransport（节选）
simulationType  LES;

LES
{
    model           kEqn;

    turbulence      on;

    delta           cubeRootVol;

    cubeRootVolCoeffs
    {
        deltaCoeff      1;
    }

    // 默认系数（源码头文件）:
    kEqnCoeffs
    {
        Ck              0.094;
        Ce              1.048;
    }
}
```

完整 delta 子字典族（Prandtl/vanDriest/smooth）见同教程文件。

## 参数表

| 参数 | 默认 | 含义 |
|------|------|------|
| `Ck` | 0.094 | $\nu_\mathrm{sgs}=C_k\sqrt{k}\Delta$ |
| `Ce` | 1.048 | $k$ 方程耗散系数 |
| `delta` | 子模型 | 滤波宽度 |

## 控制方程与关联式

One equation eddy-viscosity SGS model using a modeled balance equation for $k$.

文献：Yoshizawa, A. (1986). Statistical theory for compressible turbulent shear flows… Physics of Fluids, 29(7), 2152–2164.

## 文献与源码依据

- [`src/MomentumTransportModels/momentumTransportModels/LES/kEqn/kEqn.H`](../../../../src/MomentumTransportModels/momentumTransportModels/LES/kEqn/kEqn.H)

## 教程与模板

- `tutorials/fluid/pitzDaily/constant/momentumTransport`

## 注意事项

- 需同时求解/提供 SGS $k$ 场；与代数 Smagorinsky 不同。
