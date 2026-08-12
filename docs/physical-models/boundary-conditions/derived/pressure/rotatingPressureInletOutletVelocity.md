# rotatingPressureInletOutletVelocity

## 一句话
按通量方向在入口值与零梯度间切换。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`rotatingPressureInletOutletVelocity`
- **典型场**：`U`, p / p_rgh
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            rotatingPressureInletOutletVelocity;
    phi             phi;
    tangentialVelocity uniform (0 0 0);
    origin          (0 0 0);
    axis            (0 0 1);
    omega           100 [rpm];
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `phi` | flux field name | no | phi |
| `tangentialVelocity` | tangential velocity field | no |  |
| `origin` | origin of rotation in Cartesian co-ordinates | yes |  |
| `axis` | axis of rotation | yes |  |
| `omega` | angular velocity of the frame | no |  |

## 控制方程与关联式
按通量方向在入口值与零梯度间切换。

类头 `Description` 原文：

> This velocity inlet/outlet boundary condition is applied to patches in a
> rotating frame where the pressure is specified.  A zero-gradient is applied
> for outflow (as defined by the flux); for inflow, the velocity is obtained
> from the flux with a direction normal to the patch faces.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/rotatingPressureInletOutletVelocity/rotatingPressureInletOutletVelocityFvPatchVectorField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/rotatingPressureInletOutletVelocity/rotatingPressureInletOutletVelocityFvPatchVectorField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/rotatingPressureInletOutletVelocity/rotatingPressureInletOutletVelocityFvPatchVectorField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/rotatingPressureInletOutletVelocity/rotatingPressureInletOutletVelocityFvPatchVectorField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            rotatingPressureInletOutletVelocity`。

## 注意事项
- Sign conventions:   - positive flux (out of domain): apply zero-gradient condition   - negative flux (into of domain): derive from the flux in the patch-normal     direction
