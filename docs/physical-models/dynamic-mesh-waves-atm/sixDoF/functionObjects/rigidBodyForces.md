# rigidBodyForces

## 一句话

Calculates the forces and moments by integrating the pressure and skin-friction forces over a given list of patches of a moving rigid body.

## 适用条件（求解器 / 场 / 前提）

适用: functionObject（controlDict）；监视/控制刚体或六自由度状态

## 字典示例

```c++
// 见父字典 Usage；type 名须与 RTS 一致
rigidBodyForces
{
    type    rigidBodyForces;
}

```

## 参数表

主要入口以源码 `Usage` 为准。常见关键字见字典示例；完整列表与默认值见对应 `.H`。

| 说明 | |
|------|--|
| 选择关键字 | `type`（须与 RTS 注册名一致） |
| 配置位置 | 见适用条件 |

## 控制方程与关联式

摘自源码头文件 `Description`（原文）：

> Calculates the forces and moments by integrating the pressure and
> skin-friction forces over a given list of patches of a moving rigid body.
> 
> The centre of rotation (CofR) of the moving rigid object is obtained
> directly from the corresponding Foam::RBD::rigidBodyMotion of the
> specified body.
> 
> Member function rigidBodyForces::write() calculates the forces/moments and
> writes the forces/moments into the file \<timeDir\>/rigidBodyForces.dat
> and bin data (if selected) to the file \<timeDir\>/rigidBodyForces_bin.dat
> 
> Example of function object specification:
>     > rigidBodyForces1
>     > {
>     >     type        rigidBodyForces;
>     >     libs        ("librigidBodyForces.so");
>     > 
>     >     body        hull;
>     >     patches     (walls);
>     > 
>     >     log         yes;
>     > }
>     > 

## 文献与源码依据

- 源码：[`src/rigidBodyMotion/rigidBodyForces/rigidBodyForces.H`](../../../../../src/rigidBodyMotion/rigidBodyForces/rigidBodyForces.H)
- 实现：同目录 `.C`

## 教程与模板

- 浮体 / rigidBody 教程 functions

## 注意事项

- libs 加载对应 rigidBodyMotion 库
