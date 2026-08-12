# advective

## 一句话
速度相关边界条件。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`advective`
- **典型场**：见源码 / 场量纲匹配
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例

> （由源码构造函数推断；`waveTransmissive` 为其派生）

```cpp
outlet
{
    type            advective;
    fieldInf        0;             // 远场值 [与场同量纲]
    lInf            1;             // [m]
    // 可选: phi（默认 phi）
    value           uniform 0;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `phi` | flux field name | no | phi |
| `rho` | density field name | no | rho |
| `fieldInf` | value of field beyond patch | no |  |
| `lInf` | distance beyond patch for \c fieldInf | no |  |

## 控制方程与关联式
速度相关边界条件。

类头 `Description` 原文：

> This boundary condition provides an advective outflow condition, based on
> solving DDt(W, field) = 0 at the boundary where \c W is the wave velocity
> and \c field is the field to which this boundary condition is applied.
> 
> The standard (Euler, backward, CrankNicolson, localEuler) time schemes are
> supported.  Additionally an optional mechanism to relax the value at
> the boundary to a specified far-field value is provided which is
> switched on by specifying the relaxation length-scale \c lInf and the
> far-field value \c fieldInf.
> 
> The flow/wave speed \c (w) at the outlet is provided by the virtual function
> advectionSpeed() the default implementation of which requires the name of
> the flux field \c (phi) and optionally the density \c (rho) if the
> mass-flux rather than the volumetric-flux is given.
> 
> The flow/wave speed at the outlet can be changed by deriving a specialised
> BC from this class and over-riding advectionSpeed()  e.g. in
> waveTransmissiveFvPatchField the advectionSpeed() calculates and returns
> the flow-speed plus the acoustic wave speed creating an acoustic wave
> transmissive boundary condition.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/advective/advectiveFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/advective/advectiveFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/advective/advectiveFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/advective/advectiveFvPatchField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            advective`。

## 注意事项
- If lInf is specified, fieldInf will be required; rho is only     required in the case of a mass-based flux.
