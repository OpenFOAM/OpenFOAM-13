# freestreamVelocity

## 一句话
按通量方向在入口值与零梯度间切换。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`freestreamVelocity`
- **典型场**：`U`
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            freestreamVelocity;
    freestreamValue uniform (300 0 0);
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `freestreamValue` | freestream velocity | yes |  |

## 控制方程与关联式
按通量方向在入口值与零梯度间切换。

类头 `Description` 原文：

> This boundary condition provides a free-stream condition for velocity.
> 
> It is an inlet-outlet condition that uses the velocity orientation to
> continuously blend between fixed value for normal inlet and zero gradient
> for normal outlet flow.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/freestreamVelocity/freestreamVelocityFvPatchVectorField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/freestreamVelocity/freestreamVelocityFvPatchVectorField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/freestreamVelocity/freestreamVelocityFvPatchVectorField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/freestreamVelocity/freestreamVelocityFvPatchVectorField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/incompressibleFluid/rotor2D/0/U`](../../../tutorials/incompressibleFluid/rotor2D/0/U)
- [`tutorials/incompressibleFluid/drivaerFastback/0/U`](../../../tutorials/incompressibleFluid/drivaerFastback/0/U)
- [`tutorials/incompressibleFluid/airFoil2D/0/U`](../../../tutorials/incompressibleFluid/airFoil2D/0/U)
- [`tutorials/fluid/stackPlume/0/U.orig`](../../../tutorials/fluid/stackPlume/0/U.orig)
- [`tutorials/fluid/aerofoilNACA0012Steady/0/U`](../../../tutorials/fluid/aerofoilNACA0012Steady/0/U)
- [`tutorials/fluid/aerofoilNACA0012/0/U`](../../../tutorials/fluid/aerofoilNACA0012/0/U)

## 注意事项
- This condition is designed to operate with the freestreamPressure     condition
