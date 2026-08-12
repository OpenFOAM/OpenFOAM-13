# swirlInletVelocity

## 一句话
速度相关边界条件。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`swirlInletVelocity`
- **典型场**：`U`
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            swirlInletVelocity;
    origin          (0 0 0);
    axis            (0 0 1);
    axialVelocity   constant 30;
    radialVelocity  constant 10;
    tangentialVelocity  constant 100;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `origin` | Origin of rotation | no | patch centre |
| `axis` | Axis of rotation | no | patch normal |
| `axialVelocity` | Axial velocity [m/s] | yes |  |
| `radialVelocity` | Radial velocity [m/s] | yes |  |
| `omega` | Angular velocity of the frame | no |  |
| `tangentialVelocity` | Tangential velocity [m/s] | no |  |

## 控制方程与关联式
速度相关边界条件。

类头 `Description` 原文：

> Velocity inlet boundary condition creating axial, radial and tangential
> velocity fields specified by functions of time and radius or by a given
> angular speed.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/swirlInletVelocity/swirlInletVelocityFvPatchVectorField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/swirlInletVelocity/swirlInletVelocityFvPatchVectorField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/swirlInletVelocity/swirlInletVelocityFvPatchVectorField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/swirlInletVelocity/swirlInletVelocityFvPatchVectorField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            swirlInletVelocity`。

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
