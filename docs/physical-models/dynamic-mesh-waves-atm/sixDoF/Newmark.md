# Newmark

## 一句话

Newmark 六自由度时间积分

## 适用条件（求解器 / 场 / 前提）

sixDoFSolver

## 字典示例

```c++
// constant/fvModels 或相应字典
Newmark1
{
    type    Newmark;
    // 其余参数见源码头文件 Usage
}

```

## 参数表

| 参数 | 含义 | 量纲 |
|------|------|------|
| （见源码 Usage） | 以头文件为准 | — |

## 控制方程与关联式

摘自源码头文件 `Description`（原文）：

> Newmark 2nd-order time-integrator for 6DoF solid-body motion.
>
> Reference:
>     >     Newmark, N. M. (1959).
>     >     A method of computation for structural dynamics.
>     >     Journal of the Engineering Mechanics Division, 85(3), 67-94.
>     > 
>
> Example specification in dynamicMeshDict:
>     > solver
>     > {
>     >     type    Newmark;
>     >     gamma   0.5;    // Velocity integration coefficient
>     >     beta    0.25;   // Position integration coefficient
>     > }
>     > 

## 文献与源码依据

- 源码：[`src/rigidBodyMotion/sixDoFRigidBodyMotion/sixDoFSolvers/Newmark/Newmark.H`](../../../../src/rigidBodyMotion/sixDoFRigidBodyMotion/sixDoFSolvers/Newmark/Newmark.H)
- 实现：同目录 `.C`

## 教程与模板

- 浮体/六自由度 tutorials（如 `floatingObject`*`）

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
