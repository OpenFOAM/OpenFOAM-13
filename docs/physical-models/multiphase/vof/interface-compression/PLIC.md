# PLIC

## 一句话
Piecewise-Linear Interface Calculation (PLIC) corrected scheme is a surface

## 适用条件（求解器 / 场 / 前提）
- 适用: VoF 家族
- **族**: 界面压缩格式（基类 `surfaceInterpolationScheme`）
- **注册名**: `PLIC`

## 字典示例


> （由源码构造函数推断，无官方教程实例）

```c++
// system/fvSchemes — divSchemes
div(phi,alpha)  Gauss PLIC;
```

## 参数表

| 参数 | 说明 |
|------|------|
| `type` | 必须为 `PLIC` |
| （基类） | 部分模型继承 `residualRe` / `residualAlpha` 等，见对应基类 ctor |

本模型构造函数通常无额外专用系数。

## 控制方程与关联式
Piecewise-Linear Interface Calculation (PLIC) corrected scheme is a surface
interpolation scheme for flux calculation in advection of a bounded
variable, e.g. phase fraction and for interface capturing in the volume of
fluid (VoF) method.

The interface is represented by single cuts which split each cell to match
the volume fraction of the phase in the cell. The cut planes are oriented
according to the point field of the local phase fraction.  The phase
fraction at each cell face - the interpolated value - is then calculated
from the face area on either side of the cut.  For cases where the
single-cut does not accurately represent the cell volume fraction the
specified default scheme is used, e.g. interfaceCompression.

Example:
```
divSchemes
{
.
.
div(phi,alpha)     Gauss PLIC interfaceCompression vanLeer 1;
.
.
}
```

## 文献与源码依据
- 类: `Foam`::PLIC`
- 源码路径: `src/twoPhaseModels/interfaceCompression/PLIC/PLIC.C`

## 教程与模板
- `tutorials/incompressibleVoF/planingHullW3/system/fvSchemes`
- `tutorials/incompressibleVoF/damBreak3D/system/fvSchemes`

## 注意事项
- 类型名必须与 RTS 注册名一致：`PLIC`。
