# mappedFilmPressure

## 一句话
从另一区域/补丁映射场值或通量。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`mappedFilmPressure`
- **典型场**：p / p_rgh
- **库 / 加载**：模块本地：`isothermalFilm` / `film`
- **适用标签**：见库说明；不确定时查求解器 `Make/options`。

## 字典示例
摘录 `tutorials/multiRegion/film/splashPanel/0/film/p`：

```
surface
{
    type            mappedFilmPressure;
    value           $internalField;
}
```

（映射邻接流体 patch 压力到膜表面与内部；通常只需 `type` + `value`。）

## 参数表
| 参数 | 含义 | 必需 |
|------|------|------|
| `value` | 初值 / 重启 | 常见 |
| （映射几何） | 由 `mapped` patch/`mappedFilm*` polyPatch 拓扑提供 | — |

## 控制方程与关联式
从另一区域/补丁映射场值或通量。

类头 `Description` 原文：

> Film pressure boundary condition which maps the neighbouring fluid patch
> pressure to both the surface patch and internal film pressure field.

## 文献与源码依据
- 源码：[`applications/modules/isothermalFilm/derivedFvPatchFields/mappedFilmPressure/mappedFilmPressureFvPatchScalarField.C`](../../../applications/modules/isothermalFilm/derivedFvPatchFields/mappedFilmPressure/mappedFilmPressureFvPatchScalarField.C)
- 头文件：[`applications/modules/isothermalFilm/derivedFvPatchFields/mappedFilmPressure/mappedFilmPressureFvPatchScalarField.H`](../../../applications/modules/isothermalFilm/derivedFvPatchFields/mappedFilmPressure/mappedFilmPressureFvPatchScalarField.H)
- Inventory 备注：module-local BCs

## 教程与模板
- [`tutorials/multiRegion/film/VoFToFilm/0/film/p`](../../../tutorials/multiRegion/film/VoFToFilm/0/film/p)
- [`tutorials/multiRegion/film/splashPanel/0/film/p`](../../../tutorials/multiRegion/film/splashPanel/0/film/p)
- [`tutorials/multiRegion/film/rivuletBox/0/film/p`](../../../tutorials/multiRegion/film/rivuletBox/0/film/p)
- [`tutorials/multiRegion/film/hotBoxes/0/film/p`](../../../tutorials/multiRegion/film/hotBoxes/0/film/p)
- [`tutorials/multiRegion/film/cylinderVoF/0/film/p`](../../../tutorials/multiRegion/film/cylinderVoF/0/film/p)
- [`tutorials/multiRegion/film/cylinderDripping/0/film/p`](../../../tutorials/multiRegion/film/cylinderDripping/0/film/p)

## 注意事项
- 模块本地 BC：其他 solver 即使同名字段也不会注册该 `type`。
