# displacementLinear

## 一句话

线性位移运动

## 适用条件（求解器 / 场 / 前提）

motionSolver

## 字典示例

```c++
// 经 mover type motionSolver → motionSolver 子字典
motionSolverLibs ("libfvMotionSolvers.so"); // 视类型
motionSolver    displacementLinear;

```

## 参数表

| 参数 | 含义 | 量纲 |
|------|------|------|
| （见源码 Usage） | 以头文件为准 | — |

## 控制方程与关联式

摘自源码头文件 `Description`（原文）：

> Mesh motion solver simple linear expansion and contraction of a mesh
> region defined by a motion axis and the extents of the motion.
>
> Example:
>     >     mover           motionSolver;
>     >
>     >     libs            ("libfvMotionSolvers.so");
>     >
>     >     motionSolver    displacementLinearMotion;
>     >
>     >     axis            (0 1 0);
>     >     xFixed          0.8;
>     >     xMoving         0;
>     >     displacement    table
>     >     (
>     >         (0 0)
>     >         (4 0.7)
>     >     );
>     > 
>
> This mesh is compressed between \c xFixed and \c xMoving in the direction
> \c axis between time 0 and 4 with a maximum displacement of 0.7.
> The mesh beyond \c xFixed is fixed and beyond \c xMoving moves with maximum
> displacement.

## 文献与源码依据

- 源码：[`src/motionSolvers/displacement/linearSolver/displacementLinearMotionSolver.H`](../../../../src/motionSolvers/displacement/linearSolver/displacementLinearMotionSolver.H)
- 实现：同目录 `.C`

## 教程与模板

- 见仓库 `tutorials`/` 中含该 `type` 的案例
- `etc/caseDicts/` 若有同名模板一并对照

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
