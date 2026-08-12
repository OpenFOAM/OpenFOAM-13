# `SSG`

## 一句话

Speziale–Sarkar–Gatski RSM

## 适用条件（求解器 / 场 / 前提）
- 注册：incompressible + compressible
- phaseCompressible 子集含 `kEpsilon`/`RNGkEpsilon`/`kOmegaSST`
- phaseIncompressible 子集含 `kEpsilon`/`kOmegaSST`

## 字典示例 > （由源码构造函数/头文件默认系数推断，无官方教程实例）

```c++
// constant/momentumTransport （由源码构造函数/头文件默认系数推断，无官方教程实例） simulationType RAS;
RAS
{
model SSG;
turbulence on;
SSGCoeffs
{
Cmu 0.09;
C1 3.4;
C1s 1.8;
C2 4.2;
C3 0.8;
C3s 1.3;
C4 1.25;
C5 0.4;
Ceps1 1.44;
Ceps2 1.92;
Cs 0.25;
Ceps 0.15;
couplingFactor 0.0;
}

}

```
## 参数表

默认系数（源码头文件；可在模型子字典/`SSGCoeffs` 覆盖）：
| 参数 | 默认 | 含义 |
|------|------|------|
| `Cmu` | 0.09 | 见模型 Description |
| `C1` | 3.4 | 见模型 Description |
| `C1s` | 1.8 | 见模型 Description |
| `C2` | 4.2 | 见模型 Description |
| `C3` | 0.8 | 见模型 Description |
| `C3s` | 1.3 | 见模型 Description |
| `C4` | 1.25 | 见模型 Description |
| `C5` | 0.4 | 见模型 Description |
| `Ceps1` | 1.44 | 见模型 Description |
| `Ceps2` | 1.92 | 见模型 Description |
| `Cs` | 0.25 | 见模型 Description |
| `Ceps` | 0.15 | 见模型 Description |
| `couplingFactor` | 0.0 | 见模型 Description |

## 控制方程与关联式

Speziale, Sarkar and Gatski Reynolds-stress turbulence model for incompressible and compressible flows.



Including the generalised gradient diffusion model of
Daly and Harlow:
```
Daly, B. J., & Harlow, F. H. (1970).
Transport equations in turbulence.
Physics of Fluids (1958-1988), 13(11), 2634-2649.
```

The default model coefficients are:
```
SSGCoeffs
{
Cmu             0.09;

C1              3.4;
C1s             1.8;
C2              4.2;
C3              0.8;
C3s             1.3;
C4              1.25;
C5              0.4;

Ceps1           1.44;
Ceps2           1.92;
Cs              0.25;
Ceps            0.15;

couplingFactor  0.0;
}
```

## 文献与源码依据

- [`src/MomentumTransportModels/momentumTransportModels/RAS/SSG/SSG.H`](../../../src/MomentumTransportModels/momentumTransportModels/RAS/SSG/SSG.H)

## 教程与模板

- 仓库 tutorials 中未检索到 `SSG` 字面配置；可参考同类 `simulationType` 案例并改 `model`。
- 注册见 [`README`](../README.md) 工厂表。


## 注意事项

- 模型必须在对应库中注册（不可压/可压/相）；见族 README 注册表。
