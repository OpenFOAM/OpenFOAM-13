# displacementLayered

## 一句话

分层位移运动

## 适用条件（求解器 / 场 / 前提）

motionSolver

## 字典示例

```c++
// 经 mover type motionSolver → motionSolver 子字典
motionSolverLibs ("libfvMotionSolvers.so"); // 视类型
motionSolver    displacementLayered;

```

## 参数表

| 参数 | 含义 | 量纲 |
|------|------|------|
| （见源码 Usage） | 以头文件为准 | — |

## 控制方程与关联式

摘自源码头文件 `Description`（原文）：

> Interpolating motion solver for extruded/layered meshes
>
> Uses a topological walk from points along edges to points from one patch to
> the opposite, accumulating distance and propagating displacement and then
> again in the return direction and uses the distances from each point to the
> two opposite patches to linearly interpolate the displacements of
> these two patches to the each point.
>
> This motion solver is very simple to configure, only the two opposite
> patches between which the mesh is layered need be specified as a pair of
> patch names following the \c oppositePatches keyword, e.g.
>
>     >     mover
>     >     {
>     >         type            motionSolver;
>     >
>     >         libs            ("libfvMotionSolvers.so");
>     >
>     >         motionSolver    displacementLayered;
>     >
>     >         oppositePatches (top bottom);
>     >     }
>     > 

## 文献与源码依据

- 源码：[`src/motionSolvers/displacement/layeredSolver/displacementLayeredMotionSolver.H`](../../../../src/motionSolvers/displacement/layeredSolver/displacementLayeredMotionSolver.H)
- 实现：同目录 `.C`

## 教程与模板

- 见仓库 `tutorials`/` 中含该 `type` 的案例
- `etc/caseDicts/` 若有同名模板一并对照

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
