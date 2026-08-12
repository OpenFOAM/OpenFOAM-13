# fixedFluxPressure

## 一句话
使压力梯度与速度边界通量一致（壁面/`p_rgh` 常用）。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`fixedFluxPressure`
- **典型场**：p / p_rgh
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            fixedFluxPressure;
}
```

## 参数表
源码头文件未提供标准 `Usage` 表，或参数由基类继承——请对照源码构造函数读取字典关键字。

## 控制方程与关联式
使压力梯度与速度边界通量一致（壁面/`p_rgh` 常用）。

类头 `Description` 原文：

> This boundary condition sets the pressure gradient to the provided value
> such that the flux on the boundary is that specified by the velocity
> boundary condition.
> 
> Example of the boundary condition specification:
> 
> <patchName>
> {
>     type            fixedFluxPressure;
> }
> 

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/fixedFluxPressure/fixedFluxPressureFvPatchScalarField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/fixedFluxPressure/fixedFluxPressureFvPatchScalarField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/fixedFluxPressure/fixedFluxPressureFvPatchScalarField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/fixedFluxPressure/fixedFluxPressureFvPatchScalarField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/multiRegion/film/VoFToFilm/0/VoF/p_rgh`](../../../tutorials/multiRegion/film/VoFToFilm/0/VoF/p_rgh)
- [`tutorials/multiRegion/film/splashPanel/0/fluid/p_rgh`](../../../tutorials/multiRegion/film/splashPanel/0/fluid/p_rgh)
- [`tutorials/multiRegion/film/rivuletBox/0/box/ph_rgh.orig`](../../../tutorials/multiRegion/film/rivuletBox/0/box/ph_rgh.orig)
- [`tutorials/multiRegion/film/rivuletBox/0/box/p_rgh`](../../../tutorials/multiRegion/film/rivuletBox/0/box/p_rgh)
- [`tutorials/multiRegion/film/hotBoxes/0/fluid/p_rgh`](../../../tutorials/multiRegion/film/hotBoxes/0/fluid/p_rgh)
- [`tutorials/multiRegion/film/cylinderVoF/0/VoF/p_rgh`](../../../tutorials/multiRegion/film/cylinderVoF/0/VoF/p_rgh)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
