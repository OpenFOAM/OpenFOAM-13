# `LaheyKEpsilon`

## 一句话

Lahey 气泡诱导湍流 k–ε

## 适用条件（求解器 / 场 / 前提）
- 适用: `multiphaseEuler` 相动量输运
- 注册：`applications/modules/multiphaseEuler/momentumTransportModels/momentumTransportModels.C`

## 字典示例

```c++
// constant/momentumTransport.<phase> (multiphaseEuler) simulationType RAS;
// 或 LES RAS
{
model LaheyKEpsilon;
turbulence on;
}

```
## 参数表

默认系数（源码头文件 `LaheyKEpsilonCoeffs`；可在 `RAS` 子字典覆盖）：
| 参数 | 默认 | 含义 |
|------|------|------|
| `Cmu` | 0.09 | 涡粘系数 |
| `C1` / `C2` / `C3` / `C4` | 1.44 / 1.92 / 0 / 1.92 | ε 方程与气泡相关项 |
| `sigmak` / `sigmaEps` | 1.0 / 1.3 | k、ε 有效 Prandtl |
| `Cp` | 0.25 | 气泡产生项系数 |
| `Cmub` | 0.6 | 气泡诱导涡粘系数 |
| `alphaInversion` | 0.3 | 相分数反转阈值 |

## 控制方程与关联式

Continuous-phase k-epsilon model including bubble-generated turbulence.



The default model coefficients are
```
    LaheyKEpsilonCoeffs
    {
        Cmu             0.09;
        C1              1.44;
        C2              1.92;
        C3              0;
        C4              1.92;
        sigmak          1.0;
        sigmaEps        1.3;
        Cp              0.25;
        Cmub            0.6;
        alphaInversion  0.3;
    }
```


## 文献与源码依据

- [`src/MomentumTransportModels/phaseCompressible/RAS/LaheyKEpsilon/LaheyKEpsilon.H`](../../../src/MomentumTransportModels/phaseCompressible/RAS/LaheyKEpsilon/LaheyKEpsilon.H)
- 注册：`applications/modules/multiphaseEuler/momentumTransportModels/momentumTransportModels.C`


## 教程与模板

- `tutorials/multiphaseEuler/bubbleColumn/constant/momentumTransport.water`


## 注意事项

- 仅 `multiphaseEuler`（及链接同一工厂的多区域流体）可用；单相 `fluid`/`incompressibleFluid` **无**此 RTS。
- 通常写在 `constant/momentumTransport.<phase>`，不是混合物总字典。

