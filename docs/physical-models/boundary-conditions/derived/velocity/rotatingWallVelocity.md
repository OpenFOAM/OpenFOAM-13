# rotatingWallVelocity

## 一句话
运动壁面速度边界。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`rotatingWallVelocity`
- **典型场**：`U`
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            rotatingWallVelocity;
    origin          (0 0 0);
    axis            (0 0 1);
    omega           100 [rpm];
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `origin` | origin of rotation in Cartesian co-ordinates | yes |  |
| `axis` | axis of rotation | yes |  |
| `omega` | angular velocity of the frame | no |  |

## 控制方程与关联式
运动壁面速度边界。

类头 `Description` 原文：

> Condition on velocity for a boundary consisting of a rotating solid of
> revolution, e.g. cylinder. Calculates a tangential component of velocity
> from the angular velocity and rotational axis and ensures a zero normal
> component.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/rotatingWallVelocity/rotatingWallVelocityFvPatchVectorField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/rotatingWallVelocity/rotatingWallVelocityFvPatchVectorField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/rotatingWallVelocity/rotatingWallVelocityFvPatchVectorField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/rotatingWallVelocity/rotatingWallVelocityFvPatchVectorField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/multiphaseEuler/aeratedStirredTankMRF/0/U.gas`](../../../tutorials/multiphaseEuler/aeratedStirredTankMRF/0/U.gas)
- [`tutorials/multiphaseEuler/aeratedStirredTankMRF/0/U.liquid`](../../../tutorials/multiphaseEuler/aeratedStirredTankMRF/0/U.liquid)
- [`tutorials/incompressibleVoF/mixerVessel/0/U`](../../../tutorials/incompressibleVoF/mixerVessel/0/U)
- [`tutorials/incompressibleVoF/climbingRod/0/U`](../../../tutorials/incompressibleVoF/climbingRod/0/U)
- [`tutorials/incompressibleFluid/drivaerFastback/0/U`](../../../tutorials/incompressibleFluid/drivaerFastback/0/U)
- [`tutorials/compressibleVoF/climbingRod/0/U`](../../../tutorials/compressibleVoF/climbingRod/0/U)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
