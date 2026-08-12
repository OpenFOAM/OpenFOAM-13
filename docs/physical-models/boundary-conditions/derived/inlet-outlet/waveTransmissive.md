# waveTransmissive

## 一句话
基于当地波速的透射（无反射）出口/远场条件。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`waveTransmissive`
- **典型场**：见源码 / 场量纲匹配
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例

摘自 `tutorials/fluid/nacaAirfoil/0/p`（基类 `advective` 关键字一并列出）：

```cpp
OUTL2
{
    type            waveTransmissive;
    field           p;             // 可选；默认为本场
    gamma           1.3;           // [-] Cp/Cv（必填）
    fieldInf        100000;        // 远场参考值 [与场同量纲]
    lInf            1;             // [m] 松弛长度尺度
    // 可选: phi psi rho（默认 phi / psi / rho）
    value           uniform 100000;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `phi` | flux field name | no | phi |
| `rho` | density field name | no | rho |
| `psi` | compressibility field name | no | psi |
| `gamma` | ratio of specific heats (Cp/Cv) | yes |  |

## 控制方程与关联式
基于当地波速的透射（无反射）出口/远场条件。

类头 `Description` 原文：

> This boundary condition provides a wave transmissive outflow condition,
> based on solving DDt(W, field) = 0 at the boundary \c W is the wave velocity
> and \c field is the field to which this boundary condition is applied.
> 
> The wave speed is calculated using:
> 
>     $$
>         w_p = \frac{\phi_p}{|Sf|} + \sqrt{\frac{\gamma}{\psi_p}}
>     $$
> 
> where
> 
> 
>     w_p     | patch wave speed
>     \phi_p  | patch face flux
>     \psi_p  | patch compressibility
>     Sf      | patch face area vector
>     \gamma  | ratio of specific heats
> 

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/waveTransmissive/waveTransmissiveFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/waveTransmissive/waveTransmissiveFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/waveTransmissive/waveTransmissiveFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/waveTransmissive/waveTransmissiveFvPatchField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/XiFluid/1D/0/p`](../../../tutorials/XiFluid/1D/0/p)
- [`tutorials/shockFluid/LadenburgJet60psi/0/p`](../../../tutorials/shockFluid/LadenburgJet60psi/0/p)
- [`tutorials/shockFluid/LadenburgJet60psi/0.orig/p`](../../../tutorials/shockFluid/LadenburgJet60psi/0.orig/p)
- [`tutorials/fluid/prism/0/p`](../../../tutorials/fluid/prism/0/p)
- [`tutorials/fluid/pitzDaily/0/p`](../../../tutorials/fluid/pitzDaily/0/p)
- [`tutorials/fluid/nacaAirfoil/0/p`](../../../tutorials/fluid/nacaAirfoil/0/p)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
