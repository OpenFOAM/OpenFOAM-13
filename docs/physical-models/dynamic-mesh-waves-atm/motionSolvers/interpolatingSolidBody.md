# interpolatingSolidBody

## 一句话

插值刚体运动

## 适用条件（求解器 / 场 / 前提）

motionSolver

## 字典示例

```c++
// 经 mover type motionSolver → motionSolver 子字典
motionSolverLibs ("libfvMotionSolvers.so"); // 视类型
motionSolver    interpolatingSolidBody;

```

## 参数表

| 参数 | 含义 | 量纲 |
|------|------|------|
| （见源码 Usage） | 以头文件为准 | — |

## 控制方程与关联式

摘自源码头文件 `Description`（原文）：

> Solid-body motion of the mesh specified by a run-time selectable motion
> function.  Applies SLERP interpolation of movement as function of
> distance to the object surface to move the mesh points.

## 文献与源码依据

- 源码：[`src/motionSolvers/displacement/solidBody/interpolatingSolidBodyMotionSolver/interpolatingSolidBodyMotionSolver.H`](../../../../src/motionSolvers/displacement/solidBody/interpolatingSolidBodyMotionSolver/interpolatingSolidBodyMotionSolver.H)
- 实现：同目录 `.C`

## 教程与模板

- 见仓库 `tutorials`/` 中含该 `type` 的案例
- `etc/caseDicts/` 若有同名模板一并对照

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
