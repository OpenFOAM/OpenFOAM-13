# pressureInletOutletParSlipVelocity

## 一句话
按通量方向在入口值与零梯度间切换。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`pressureInletOutletParSlipVelocity`
- **典型场**：`U`, p / p_rgh
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            pressureInletOutletParSlipVelocity;
    value           uniform (0 0 0);
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `phi` | flux field name | no | phi |
| `rho` | density field name | no | rho |

## 控制方程与关联式
按通量方向在入口值与零梯度间切换。

类头 `Description` 原文：

> This velocity inlet/outlet boundary condition for pressure boundary where
> the pressure is specified.  A zero-gradient is applied for outflow (as
> defined by the flux); for inflow, the velocity is obtained from the flux
> with the specified inlet direction.
> 
> A slip condition is applied tangential to the patch.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/pressureInletOutletParSlipVelocity/pressureInletOutletParSlipVelocityFvPatchVectorField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/pressureInletOutletParSlipVelocity/pressureInletOutletParSlipVelocityFvPatchVectorField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/pressureInletOutletParSlipVelocity/pressureInletOutletParSlipVelocityFvPatchVectorField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/pressureInletOutletParSlipVelocity/pressureInletOutletParSlipVelocityFvPatchVectorField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/isothermalFluid/potentialFreeSurfaceOscillatingBox/0/U`](../../../tutorials/isothermalFluid/potentialFreeSurfaceOscillatingBox/0/U)
- [`tutorials/isothermalFluid/potentialFreeSurfaceMovingOscillatingBox/0.orig/U`](../../../tutorials/isothermalFluid/potentialFreeSurfaceMovingOscillatingBox/0.orig/U)

## 注意事项
- Sign conventions:   - positive flux (out of domain): apply zero-gradient condition   - negative flux (into of domain): derive from the flux with specified     direction
