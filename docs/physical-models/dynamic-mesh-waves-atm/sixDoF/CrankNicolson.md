# CrankNicolson

## 一句话

Crank–Nicolson 六自由度积分

## 适用条件（求解器 / 场 / 前提）

sixDoFSolver

## 字典示例

```c++
// constant/fvModels 或相应字典
CrankNicolson1
{
    type    CrankNicolson;
    // 其余参数见源码头文件 Usage
}

```

## 参数表

| 参数 | 含义 | 量纲 |
|------|------|------|
| （见源码 Usage） | 以头文件为准 | — |

## 控制方程与关联式

摘自源码头文件 `Description`（原文）：

> Crank-Nicolson 2nd-order time-integrator for 6DoF solid-body motion.
>
> The off-centering coefficients for acceleration (velocity integration) and
> velocity (position/orientation integration) may be specified but default
> values of 0.5 for each are used if they are not specified.  With the default
> off-centering this scheme is equivalent to the Newmark scheme with default
> coefficients.
>
> Example specification in dynamicMeshDict:
>     > solver
>     > {
>     >     type    CrankNicolson;
>     >     aoc     0.5;    // Acceleration off-centering coefficient
>     >     voc     0.5;    // Velocity off-centering coefficient
>     > }
>     > 

## 文献与源码依据

- 源码：[`src/rigidBodyMotion/sixDoFRigidBodyMotion/sixDoFSolvers/CrankNicolson/CrankNicolson.H`](../../../../src/rigidBodyMotion/sixDoFRigidBodyMotion/sixDoFSolvers/CrankNicolson/CrankNicolson.H)
- 实现：同目录 `.C`

## 教程与模板

- 浮体/六自由度 tutorials（如 `floatingObject`*`）

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
