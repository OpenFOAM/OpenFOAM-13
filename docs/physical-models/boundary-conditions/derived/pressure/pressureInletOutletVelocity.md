# pressureInletOutletVelocity

## 一句话
压力驱动开口：出流零梯度、入流由内场推速度。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`pressureInletOutletVelocity`
- **典型场**：`U`, p / p_rgh
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            pressureInletOutletVelocity;
    phi             phi;
    tangentialVelocity (0 0 0);
    value           uniform (0 0 0);
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `phi` | flux field name | no | phi |
| `tangentialVelocity` | tangential velocity | no |  |

## 控制方程与关联式
压力驱动开口：出流零梯度、入流由内场推速度。

类头 `Description` 原文：

> Velocity inlet/outlet boundary condition for patches where the pressure is
> specified in some manner, e.g. fixedValue, totalPressure,
> entrainmentPressure etc.
> 
> This boundary condition is directionMixed:
>     Flux outflow: zeroGradient condition
>     Flux inflow: zeroGradient condition for normal component
>                  fixedValue for tangential component
> 
> The external tangential velocity can be optionally specified otherwise it
> is assumed zero.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/pressureInletOutletVelocity/pressureInletOutletVelocityFvPatchVectorField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/pressureInletOutletVelocity/pressureInletOutletVelocityFvPatchVectorField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/pressureInletOutletVelocity/pressureInletOutletVelocityFvPatchVectorField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/pressureInletOutletVelocity/pressureInletOutletVelocityFvPatchVectorField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/XiFluid/engine2Valve2D/0/U`](../../../tutorials/XiFluid/engine2Valve2D/0/U)
- [`tutorials/shockFluid/movingCone/0/U`](../../../tutorials/shockFluid/movingCone/0/U)
- [`tutorials/multiRegion/film/VoFToFilm/0/VoF/U`](../../../tutorials/multiRegion/film/VoFToFilm/0/VoF/U)
- [`tutorials/multiRegion/film/splashPanel/0/fluid/U`](../../../tutorials/multiRegion/film/splashPanel/0/fluid/U)
- [`tutorials/multiRegion/film/rivuletBox/0/box/U`](../../../tutorials/multiRegion/film/rivuletBox/0/box/U)
- [`tutorials/multiRegion/film/cylinderVoF/0/VoF/U`](../../../tutorials/multiRegion/film/cylinderVoF/0/VoF/U)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
