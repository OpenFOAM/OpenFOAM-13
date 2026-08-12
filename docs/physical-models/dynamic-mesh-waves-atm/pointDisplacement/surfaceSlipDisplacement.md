# surfaceSlipDisplacement

## 一句话

表面滑移位移

## 适用条件（求解器 / 场 / 前提）

pointDisplacement

## 字典示例

```c++
// 0/pointDisplacement 边界
<patch>
{
    type    surfaceSlipDisplacement;
    value   uniform (0 0 0);
}

```

## 参数表

| 参数 | 含义 | 量纲 |
|------|------|------|
| （见源码 Usage） | 以头文件为准 | — |

## 控制方程与关联式

摘自源码头文件 `Description`（原文）：

> Displacement follows a triSurface. Use in a displacementMotionSolver
> as a bc on the pointDisplacement field.
> Following is done by calculating the projection onto the surface according
> to the projectMode
> - NEAREST : nearest
> - POINTNORMAL : intersection with point normal
> - FIXEDNORMAL : intersection with fixed vector
>
> Optionally (intersection only) removes a component ("wedgePlane") to
> stay in 2D.
>
> Needs:
> - geometry : dictionary with searchableSurfaces. (usually
>   triSurfacees in constant/triSurface)
> - projectMode : see above
> - projectDirection : if projectMode = fixedNormal
> - wedgePlane : -1 or component to knock out of intersection normal
> - frozenPointsZone : empty or name of pointZone containing points
>                      that do not move

## 文献与源码依据

- 源码：[`src/fvMotionSolver/pointPatchFields/derived/surfaceSlipDisplacement/surfaceSlipDisplacementPointPatchVectorField.H`](../../../../src/fvMotionSolver/pointPatchFields/derived/surfaceSlipDisplacement/surfaceSlipDisplacementPointPatchVectorField.H)
- 实现：同目录 `.C`

## 教程与模板

- 动网格教程中的 `0/pointDisplacement`；BC 全谱见 Phase 2

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
