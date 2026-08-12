# externalForce

## 一句话

Time-dependent external force restraint using Function1.

## 适用条件（求解器 / 场 / 前提）

适用: rigidBodyDynamics `restraints`（多体）

## 字典示例

```c++
restraints
{
    force
    {
        type        externalForce;
        body        floatingObject;
        location    (0 0 0);
        force       (100 0 0);
    }
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

> Time-dependent external force restraint using Function1.

## 文献与源码依据

- 源码：[`src/rigidBodyMotion/rigidBodyDynamics/restraints/externalForce/externalForce.H`](../../../../../src/rigidBodyMotion/rigidBodyDynamics/restraints/externalForce/externalForce.H)
- 实现：同目录 `.C`

## 教程与模板

- 浮体 / 刚体阻尼弹簧教程

## 注意事项

- 同名类型可能同时注册于 sixDoF 与 rigidBodyDynamics
