# propellerDiskForce

## 一句话

刚体螺旋桨盘对刚体系统施加的力（配合 rigidBodyPropellerDisk）

## 适用条件（求解器 / 场 / 前提）

适用: `rigidBodyPropellerDisk` / rigidBody 约束力路径

## 字典示例



> （由源码构造函数推断，无官方教程实例）

```c++
restraints
    {
        force
        {
            type        propellerDiskForce;
            body        floatingObject;
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

> 将螺旋桨盘推力/力矩反馈到 rigidBodyMotion。

## 文献与源码依据

- [`src/fvModels/rigidBodyPropellerDisk/propellerDiskForce/`](../../../src/fvModels/rigidBodyPropellerDisk/propellerDiskForce/)

## 教程与模板

- 含 rigidBody + propeller 的教程（如浮体螺旋桨案例，若有）

## 注意事项

- inventory directory；随父模型启用
