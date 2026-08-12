# `dynamicKEqn`

## 一句话

动态一方程 SGS（$C_k$、$C_e$ 由滤波求）

## 适用条件（求解器 / 场 / 前提）

- 注册：incompressible + compressible

## 字典示例

```c++
// tutorials/incompressibleFluid/pitzDailyLES/constant/momentumTransport
simulationType  LES;

LES
{
    model           dynamicKEqn;

    turbulence      on;

    delta           cubeRootVol;

    dynamicKEqnCoeffs
    {
        filter simple;   // 必填：用于 KK 的 LES filter 类型
    }

    cubeRootVolCoeffs
    {
        deltaCoeff      1;
    }
}
```

头文件说明：无默认 `Ck`/`Ce` 常数；必须指定 `filter`。

## 参数表

| 参数 | 必需 | 说明 |
|------|------|------|
| `filter` | 是 | LES filter（如 `simple`），写在 `dynamicKEqnCoeffs` |
| `delta` | 是 | 滤波宽度模型 |

## 控制方程与关联式

One-equation eddy-viscosity SGS with dynamically computed coefficients via filtering（见类 Description）。

## 文献与源码依据

- [`src/MomentumTransportModels/momentumTransportModels/LES/dynamicKEqn/dynamicKEqn.H`](../../../../src/MomentumTransportModels/momentumTransportModels/LES/dynamicKEqn/dynamicKEqn.H)

## 教程与模板

- `tutorials/incompressibleFluid/pitzDailyLES/constant/momentumTransport`

## 注意事项

- 缺少 `filter` 会在构造时失败；不要只抄代数 Smagorinsky 的 `Ck`/`Ce`。
