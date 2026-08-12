# symplectic

## 一句话

辛格式六自由度积分

## 适用条件（求解器 / 场 / 前提）

sixDoFSolver

## 字典示例

```c++
// constant/fvModels 或相应字典
symplectic1
{
    type    symplectic;
    // 其余参数见源码头文件 Usage
}

```

## 参数表

| 参数 | 含义 | 量纲 |
|------|------|------|
| （见源码 Usage） | 以头文件为准 | — |

## 控制方程与关联式

摘自源码头文件 `Description`（原文）：

> Symplectic 2nd-order explicit time-integrator for 6DoF solid-body motion.
>
> Reference:
>     >     Dullweber, A., Leimkuhler, B., & McLachlan, R. (1997).
>     >     Symplectic splitting methods for rigid body molecular dynamics.
>     >     The Journal of chemical physics, 107(15), 5840-5851.
>     > 
>
> Can only be used for explicit integration of the motion of the body,
> i.e. may only be called once per time-step, no outer-correctors may be
> applied.  For implicit integration with outer-correctors choose either
> CrankNicolson or Newmark schemes.
>
> Example specification in dynamicMeshDict:
>     > solver
>     > {
>     >     type    symplectic;
>     > }
>     > 

## 文献与源码依据

- 源码：[`src/rigidBodyMotion/sixDoFRigidBodyMotion/sixDoFSolvers/symplectic/symplectic.H`](../../../../src/rigidBodyMotion/sixDoFRigidBodyMotion/sixDoFSolvers/symplectic/symplectic.H)
- 实现：同目录 `.C`

## 教程与模板

- 浮体/六自由度 tutorials（如 `floatingObject`*`）

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
