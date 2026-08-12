# sixDoFRigidBodyControl

## 一句话

Convergence control based on the 6-DoF motion state.

## 适用条件（求解器 / 场 / 前提）

适用: functionObject（controlDict）；监视/控制刚体或六自由度状态

## 字典示例

```c++
sixDoFRigidBodyControl
{
    type           sixDoFRigidBodyControl;
    libs           ("libsixDoFRigidBodyState.so");

    angleUnits     [deg];
    angularVelocityUnits [deg/s];

    window         1;
    convergedVelocity (1e-2 1e-2 1e-2);
    convergedAngularVelocity (5 5 5);
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

> Convergence control based on the 6-DoF motion state.
> 
> The body linear and angular velocities are averaged over a specified time
> window and compared to specified velocity convergence criteria and the run
> stopped after writing the current time results, if the criteria are met.

## 文献与源码依据

- 源码：[`src/rigidBodyMotion/sixDoFRigidBodyState/sixDoFRigidBodyControl/sixDoFRigidBodyControl.H`](../../../../../src/rigidBodyMotion/sixDoFRigidBodyState/sixDoFRigidBodyControl/sixDoFRigidBodyControl.H)
- 实现：同目录 `.C`

## 教程与模板

- 浮体 / rigidBody 教程 functions

## 注意事项

- libs 加载对应 rigidBodyMotion 库
