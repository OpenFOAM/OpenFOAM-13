# `kEpsilon`

## 一句话

标准 k–ε

## 适用条件（求解器 / 场 / 前提）

- 注册：incompressible + compressible
- phaseCompressible 子集含 `kEpsilon`/`RNGkEpsilon`/`kOmegaSST`
- phaseIncompressible 子集含 `kEpsilon`/`kOmegaSST`

## 字典示例

```c++
// tutorials/XiFluid/1D/constant/momentumTransport
simulationType  RAS;

RAS
{
    model           kEpsilon;
    turbulence      off;
}

// 默认系数（源码头文件 Description；可在 RAS 子字典覆盖）:
kEpsilonCoeffs
{
    Cmu         0.09;
    C1          1.44;
    C2          1.92;
    C3          0;
    sigmak      1.0;
    sigmaEps    1.3;
}
```

## 参数表

默认系数（源码头文件；可在 `RAS { kEpsilonCoeffs { ... } }` 覆盖）：

| 参数 | 默认 | 含义 |
|------|------|------|
| `Cmu` | 0.09 | $C_\mu$，涡粘 $\nu_t = C_\mu k^2/\varepsilon$ |
| `C1` | 1.44 | $\varepsilon$ 方程产生项系数 |
| `C2` | 1.92 | $\varepsilon$ 方程耗散项系数 |
| `C3` | 0 | 浮力/压缩相关系数（默认 0） |
| `sigmak` | 1.0 | $k$ 有效 Prandtl |
| `sigmaEps` | 1.3 | $\varepsilon$ 有效 Prandtl |

量纲：模型常数均为无量纲。

## 控制方程与关联式

Standard k-epsilon turbulence model for incompressible and compressible
flows including rapid distortion theory (RDT) based compression term.

Reference:

- Launder, B. E., & Spalding, D. B. (1972). Lectures in mathematical models of turbulence.
- Launder, B. E., & Spalding, D. B. (1974). The numerical computation of turbulent flows. CMAME, 3(2), 269-289.
- El Tahry, S. H. (1983). k-epsilon equation for compressible reciprocating engine flows. Journal of Energy, 7(4), 345-353.

## 文献与源码依据

- [`src/MomentumTransportModels/momentumTransportModels/RAS/kEpsilon/kEpsilon.H`](../../../../src/MomentumTransportModels/momentumTransportModels/RAS/kEpsilon/kEpsilon.H)

## 教程与模板

- `tutorials/XiFluid/kivaTest/constant/momentumTransport`
- `tutorials/XiFluid/1D/constant/momentumTransport`
- `tutorials/multiRegion/film/hotBoxes/constant/fluid/momentumTransport`
- `tutorials/multiRegion/CHT/shellAndTubeHeatExchanger/constant/shell/momentumTransport`
- `tutorials/multiRegion/CHT/reverseBurner/constant/gas/momentumTransport`
- `tutorials/multiRegion/CHT/notchedRoller/constant/fluid/momentumTransport`

## 注意事项

- 模型必须在对应库中注册（不可压/可压/相）；见族 README 注册表。
