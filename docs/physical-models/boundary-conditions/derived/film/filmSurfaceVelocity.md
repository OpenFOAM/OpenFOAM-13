# filmSurfaceVelocity

## 一句话
速度相关边界条件。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`filmSurfaceVelocity`
- **典型场**：`U`
- **库 / 加载**：模块本地：`isothermalFilm` / `film`
- **适用标签**：见库说明；不确定时查求解器 `Make/options`。

## 字典示例
```
<patchName>
{
    type            filmSurfaceVelocity;
    Cs              0.005;
    value           $internalField;
}
```

```
<patchName>
{
    type            filmSurfaceVelocity;
    value           $internalField;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `Cs` | Fluid-film drag coefficient | no | 0 |

## 控制方程与关联式
速度相关边界条件。

类头 `Description` 原文：

> Film surface velocity boundary condition
> 
> Evaluates the surface velocity from the shear imposed by the neighbouring
> fluid velocity using either a simple drag model based on the difference
> between the fluid and film velocities multiplied by the coefficient \c Cs or
> if \c Cs is not specified or set to 0 the fluid viscous shear stress.
> 
> The simple model might be used in preference to the fluid viscous shear
> stress model in order to provide some means to include the drag enhancing
> effect of surface ripples, rivulets etc. in the film surface.

## 文献与源码依据
- 源码：[`applications/modules/isothermalFilm/derivedFvPatchFields/filmSurfaceVelocity/filmSurfaceVelocityFvPatchVectorField.C`](../../../applications/modules/isothermalFilm/derivedFvPatchFields/filmSurfaceVelocity/filmSurfaceVelocityFvPatchVectorField.C)
- 头文件：[`applications/modules/isothermalFilm/derivedFvPatchFields/filmSurfaceVelocity/filmSurfaceVelocityFvPatchVectorField.H`](../../../applications/modules/isothermalFilm/derivedFvPatchFields/filmSurfaceVelocity/filmSurfaceVelocityFvPatchVectorField.H)
- Inventory 备注：module-local BCs

## 教程与模板
- [`tutorials/multiRegion/film/VoFToFilm/0/film/U`](../../../tutorials/multiRegion/film/VoFToFilm/0/film/U)
- [`tutorials/multiRegion/film/splashPanel/0/film/U`](../../../tutorials/multiRegion/film/splashPanel/0/film/U)
- [`tutorials/multiRegion/film/rivuletBox/0/film/U`](../../../tutorials/multiRegion/film/rivuletBox/0/film/U)
- [`tutorials/multiRegion/film/hotBoxes/0/film/U`](../../../tutorials/multiRegion/film/hotBoxes/0/film/U)
- [`tutorials/multiRegion/film/cylinderVoF/0/film/U`](../../../tutorials/multiRegion/film/cylinderVoF/0/film/U)
- [`tutorials/multiRegion/film/cylinderDripping/0/film/U`](../../../tutorials/multiRegion/film/cylinderDripping/0/film/U)

## 注意事项
- 模块本地 BC：其他 solver 即使同名字段也不会注册该 `type`。
