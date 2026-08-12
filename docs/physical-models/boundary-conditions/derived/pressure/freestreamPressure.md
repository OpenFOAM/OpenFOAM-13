# freestreamPressure

## 一句话
自由来流：向外部参考状态松弛。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`freestreamPressure`
- **典型场**：p / p_rgh
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            freestreamPressure;
    freestreamValue uniform 1e5;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `U` | velocity field name | no | U |
| `freestreamValue` | freestream pressure | yes |  |
| `supersonic` | Switch for supersonic flow | no | false |

## 控制方程与关联式
自由来流：向外部参考状态松弛。

类头 `Description` 原文：

> This boundary condition provides a free-stream condition for pressure.
> 
> It is an outlet-inlet condition that uses the velocity orientation to
> continuously blend between zero gradient for normal inlet and fixed value
> for normal outlet flow.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/freestreamPressure/freestreamPressureFvPatchScalarField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/freestreamPressure/freestreamPressureFvPatchScalarField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/freestreamPressure/freestreamPressureFvPatchScalarField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/freestreamPressure/freestreamPressureFvPatchScalarField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/incompressibleFluid/rotor2DSRF/0/p`](../../../tutorials/incompressibleFluid/rotor2DSRF/0/p)
- [`tutorials/incompressibleFluid/rotor2D/0/p`](../../../tutorials/incompressibleFluid/rotor2D/0/p)
- [`tutorials/incompressibleFluid/drivaerFastback/0/p`](../../../tutorials/incompressibleFluid/drivaerFastback/0/p)
- [`tutorials/incompressibleFluid/airFoil2D/0/p`](../../../tutorials/incompressibleFluid/airFoil2D/0/p)
- [`tutorials/fluid/stackPlume/0/p_rgh`](../../../tutorials/fluid/stackPlume/0/p_rgh)
- [`tutorials/fluid/aerofoilNACA0012Steady/0/p`](../../../tutorials/fluid/aerofoilNACA0012Steady/0/p)

## 注意事项
- This condition is designed to operate with a freestreamVelocity     condition
