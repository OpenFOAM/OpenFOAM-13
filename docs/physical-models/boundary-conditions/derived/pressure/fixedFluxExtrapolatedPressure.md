# fixedFluxExtrapolatedPressure

## 一句话
压力相关边界条件。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`fixedFluxExtrapolatedPressure`
- **典型场**：p / p_rgh
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            fixedFluxExtrapolatedPressure;
}
```

## 参数表
源码头文件未提供标准 `Usage` 表，或参数由基类继承——请对照源码构造函数读取字典关键字。

## 控制方程与关联式
压力相关边界条件。

类头 `Description` 原文：

> This boundary condition sets the pressure gradient to the provided value
> such that the flux on the boundary is that specified by the velocity
> boundary condition.
> 
> Example of the boundary condition specification:
> 
> <patchName>
> {
>     type            fixedFluxExtrapolatedPressure;
> }
> 

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/fixedFluxExtrapolatedPressure/fixedFluxExtrapolatedPressureFvPatchScalarField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/fixedFluxExtrapolatedPressure/fixedFluxExtrapolatedPressureFvPatchScalarField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/fixedFluxExtrapolatedPressure/fixedFluxExtrapolatedPressureFvPatchScalarField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/fixedFluxExtrapolatedPressure/fixedFluxExtrapolatedPressureFvPatchScalarField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/XiFluid/engine2Valve2D/0/p`](../../../tutorials/XiFluid/engine2Valve2D/0/p)
- [`tutorials/incompressibleFluid/waveSubSurface/0/p`](../../../tutorials/incompressibleFluid/waveSubSurface/0/p)
- [`tutorials/incompressibleFluid/simpleRushtonNCC/0/p.orig`](../../../tutorials/incompressibleFluid/simpleRushtonNCC/0/p.orig)
- [`tutorials/incompressibleFluid/simpleRushtonMRF/0/p.orig`](../../../tutorials/incompressibleFluid/simpleRushtonMRF/0/p.orig)
- [`tutorials/incompressibleFluid/ductSecondaryFlow/0/p`](../../../tutorials/incompressibleFluid/ductSecondaryFlow/0/p)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
