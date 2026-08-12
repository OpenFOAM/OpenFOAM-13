# PLICU

## 一句话
Velocity-weighted Piecewise-Linear Interface Calculation (PLICU) corrected

## 适用条件（求解器 / 场 / 前提）
- 适用: VoF 家族
- **族**: 界面压缩格式（基类 `surfaceInterpolationScheme`）
- **注册名**: `PLICU`

## 字典示例


> （由源码构造函数推断，无官方教程实例）

```c++
// system/fvSchemes — divSchemes
div(phi,alpha)  Gauss PLICU;
```

## 参数表

| 参数 | 说明 |
|------|------|
| `type` | 必须为 `PLICU` |
| （基类） | 部分模型继承 `residualRe` / `residualAlpha` 等，见对应基类 ctor |

本模型构造函数通常无额外专用系数。

## 控制方程与关联式
Velocity-weighted Piecewise-Linear Interface Calculation (PLICU) corrected
scheme is a surface interpolation scheme for flux calculation in advection
of a bounded variable, e.g. phase fraction and for interface capturing in
the volume of fluid (VoF) method.

The interface is represented by single cuts which split each cell to match
the volume fraction of the phase in the cell. The cut planes are oriented
according to the point field of the local phase fraction.  The phase
fraction at each cell face - the interpolated value - is then calculated
from the face area on either side of the cut.  For cases where the
single-cut does not accurately represent the cell volume fraction the
specified default scheme is used, e.g. interfaceCompression.

Additionally the face point velocity values are used to calculate the face
flux which is likely to be more accurate in the presence of high shear.

Example:
```
divSchemes
{
.
.
div(phi,alpha)     Gauss PLICU interfaceCompression vanLeer 1;
.
.
}
```

## 文献与源码依据
- 类: `Foam`::PLICU`
- 源码路径: `src/twoPhaseModels/interfaceCompression/PLIC/PLICU.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`PLICU`。
