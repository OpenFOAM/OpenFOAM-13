# linearSpring

## 一句话

sixDoFRigidBodyMotionRestraints model.

## 适用条件（求解器 / 场 / 前提）

适用: sixDoFRigidBodyMotion `restraints`

## 字典示例

```c++
// 见父字典 Usage；type 名须与 RTS 一致
linearSpring
{
    type    linearSpring;
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

> sixDoFRigidBodyMotionRestraints model.  Linear spring.

## 文献与源码依据

- 源码：[`src/rigidBodyMotion/sixDoFRigidBodyMotion/sixDoFRigidBodyMotion/restraints/linearSpring/linearSpring.H`](../../../../../src/rigidBodyMotion/sixDoFRigidBodyMotion/sixDoFRigidBodyMotion/restraints/linearSpring/linearSpring.H)
- 实现：同目录 `.C`

## 教程与模板

- 浮体 / 刚体阻尼弹簧教程

## 注意事项

- 同名类型可能同时注册于 sixDoF 与 rigidBodyDynamics
