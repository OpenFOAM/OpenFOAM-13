# line

## 一句话

Translation constraint on the centre of rotation:     may only move along a line.

## 适用条件（求解器 / 场 / 前提）

适用: `sixDoFRigidBodyMotion` 的 `constraints` 子字典；配合 sixDoFRigidBodyMotionSolver

## 字典示例

```c++
lineConstraint
{
    sixDoFRigidBodyMotionConstraint line;
    // 其余见源码
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

> Translation constraint on the centre of rotation:
>     may only move along a line.
> 
> If 'centreOfRotation' is not provided in the dictionary the centre of mass
> is used.

## 文献与源码依据

- 源码：[`src/rigidBodyMotion/sixDoFRigidBodyMotion/sixDoFRigidBodyMotion/constraints/line/sixDoFRigidBodyMotionLineConstraint.H`](../../../../../src/rigidBodyMotion/sixDoFRigidBodyMotion/sixDoFRigidBodyMotion/constraints/line/sixDoFRigidBodyMotionLineConstraint.H)
- 实现：同目录 `.C`

## 教程与模板

- 浮体 / 铰接六自由度教程（`tutorials` 中 sixDoF / floatingObject 等）

## 注意事项

- 在 motion 字典 constraints { ... type axis; } 中选用
