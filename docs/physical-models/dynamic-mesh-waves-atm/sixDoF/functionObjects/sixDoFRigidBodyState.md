# sixDoFRigidBodyState

## 一句话

Writes the 6-DoF motion state.

## 适用条件（求解器 / 场 / 前提）

适用: functionObject（controlDict）；监视/控制刚体或六自由度状态

## 字典示例

```c++
sixDoFRigidBodyState
{
    type           sixDoFRigidBodyState;
    libs           ("libsixDoFRigidBodyState.so");
    angleUnits     [deg];
    angularVelocityUnits [rpm];
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

> Writes the 6-DoF motion state.

## 文献与源码依据

- 源码：[`src/rigidBodyMotion/sixDoFRigidBodyState/sixDoFRigidBodyState/sixDoFRigidBodyState.H`](../../../../../src/rigidBodyMotion/sixDoFRigidBodyState/sixDoFRigidBodyState/sixDoFRigidBodyState.H)
- 实现：同目录 `.C`

## 教程与模板

- 浮体 / rigidBody 教程 functions

## 注意事项

- libs 加载对应 rigidBodyMotion 库
