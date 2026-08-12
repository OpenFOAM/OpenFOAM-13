# `buoyantKEpsilon`

## 一句话

浮力修正 k–ε（可压注册）

## 适用条件（求解器 / 场 / 前提）

- **仅 compressible** 注册（`compressibleMomentumTransportModels.C`）
- 不适用: 纯 incompressible 库

## 字典示例

```c++
// tutorials/incompressibleDriftFlux/dahl/constant/momentumTransport
simulationType  RAS;

RAS
{
    model    buoyantKEpsilon;

    turbulence      on;

    buoyantKEpsilonCoeffs
    {
        Cg      0.85;
    }
}

// 头文件默认 Cg = 1.0；亦可省略 coeffs 子字典
// 另见 tutorials/fluid/stackPlume/constant/momentumTransport（无显式 coeffs）
```

## 参数表

默认系数（源码头文件；可在 `RAS { buoyantKEpsilonCoeffs { ... } }` 覆盖）：

| 参数 | 默认 | 含义 |
|------|------|------|
| `Cg` | 1.0 | 浮力产生/耗散项系数（替代 $1/\mathrm{Pr}_t$ 的通用增益） |

另继承标准 `kEpsilon` 的 `Cmu/C1/C2/C3/sigmak/sigmaEps`（见 [`kEpsilon`](kEpsilon.md)）。

## 控制方程与关联式

在标准 k–ε 的 $k$、$\varepsilon$ 方程上附加基于**密度梯度**的浮力产生/耗散项（相对仅温度梯度的形式，可覆盖组分导致的密度变化）。

文献：Henkes, R.A.W.M., Van Der Vlugt, F.F. & Hoogendoorn, C.J. (1991). Natural Convection Flow in a Square Cavity… Int. J. Heat Mass Transfer, 34, 1543–1557.

See also：`Foam::RASModels::kEpsilon`

## 文献与源码依据

- [`src/MomentumTransportModels/compressible/RAS/buoyantKEpsilon/buoyantKEpsilon.H`](../../../../src/MomentumTransportModels/compressible/RAS/buoyantKEpsilon/buoyantKEpsilon.H)

## 教程与模板

- `tutorials/incompressibleDriftFlux/tank3D/constant/momentumTransport`
- `tutorials/incompressibleDriftFlux/mixerVessel2DMRF/constant/momentumTransport`
- `tutorials/incompressibleDriftFlux/dahl/constant/momentumTransport`
- `tutorials/fluid/stackPlume/constant/momentumTransport`

## 注意事项

- 模型必须在对应库中注册（不可压/可压/相）；见族 README 注册表。
