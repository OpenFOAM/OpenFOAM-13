# `SpalartAllmaras`

## 一句话

Spalart–Allmaras 一方程 RAS

## 适用条件（求解器 / 场 / 前提）

- 注册：incompressible + compressible

## 字典示例

> （由源码头文件默认系数推断；tutorials 中亦有 `model SpalartAllmaras`）

```c++
// constant/momentumTransport
simulationType RAS;

RAS
{
    model           SpalartAllmaras;
    turbulence      on;
    printCoeffs     on;

    SpalartAllmarasCoeffs
    {
        sigmaNut    0.66666;
        kappa       0.41;
        Cb1         0.1355;
        Cb2         0.622;
        Cw2         0.3;
        Cw3         2.0;
        Cv1         7.1;
        Cs          0.3;
    }
}
```

## 参数表

| 参数 | 默认 | 含义 |
|------|------|------|
| `sigmaNut` | 0.66666 | $\tilde\nu$ 扩散 Prandtl |
| `kappa` | 0.41 | von Kármán |
| `Cb1`/`Cb2` | 0.1355 / 0.622 | 产生/扩散 |
| `Cw2`/`Cw3` | 0.3 / 2.0 | 壁面破坏 |
| `Cv1` | 7.1 | 粘性阻尼 |
| `Cs` | 0.3 | 旋转修正相关 |

（以 `SpalartAllmaras.H` Description 为准。）

## 控制方程与关联式

一方程涡粘模型，求解修正粘度 $\tilde\nu$。文献：Spalart & Allmaras (1992/1994)。

## 文献与源码依据

- [`src/MomentumTransportModels/momentumTransportModels/RAS/SpalartAllmaras/SpalartAllmaras.H`](../../../../src/MomentumTransportModels/momentumTransportModels/RAS/SpalartAllmaras/SpalartAllmaras.H)

## 教程与模板

- 仓库内搜索 `model           SpalartAllmaras`

## 注意事项

- 需壁面距离；与 DES/DDES/IDDES 变体区分（见 LES 目录）。
