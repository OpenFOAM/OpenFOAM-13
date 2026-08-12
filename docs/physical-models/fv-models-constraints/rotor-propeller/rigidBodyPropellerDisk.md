# rigidBodyPropellerDisk

## 一句话

刚体运动耦合螺旋桨盘

## 适用条件（求解器 / 场 / 前提）

适用: 配合 rigidBody 动网格

## 字典示例



> （由源码构造函数推断，无官方教程实例）

```c++
diskSource
    {
        type            rigidBodyPropellerDisk;

        libs            ("librigidBodyPropellerDisk.so");

        cellZone        propeller;

        body            hull;

        centre          (0 0 0);    // Centre of the propeller
        normal          (1 0 0);    // Normal direction of the propeller

        n               26.03;      // Rotation speed [1/s]

        dPropeller      0.203;      // Propeller diameter
        dHub            0.039179;   // Hub diameter

        propellerCurve
        {
            type table;

            //   J     Kt     Kq
            values
            (
                (0.10 (0.3267 0.03748))
                (0.15 (0.3112 0.03629))
                (0.20 (0.2949 0.03500))
                (0.25 (0.2777 0.03361))
                (0.30 (0.2598 0.03210))
                (0.35 (0.2410 0.03047))
                (0.40 (0.2214 0.02871))
                (0.45 (0.2010 0.02682))
                (0.50 (0.1798 0.02479))
                (0.55 (0.1577 0.02261))
                (0.60 (0.1349 0.02027))
                (0.65 (0.1112 0.01777))
                (0.70 (0.0867 0.01509))
                (0.75 (0.0614 0.01224))
                (0.80 (0.0353 0.00921))
            );
        }
    }
```

## 参数表

主要入口以源码 `Usage` 为准。常见关键字见字典示例；完整列表与默认值见对应 `.H`。

| 说明 | |
|------|--|
| 配置位置 | 通常 `constant/fvModels` 或 `constant/fvConstraints` / `constant/dynamicMeshDict` |
| 选择关键字 | `type`（须与 RTS 注册名一致） |
| 区域选择 | 多数源/约束需要 `cellZone` 或等价选择 |


## 控制方程与关联式

摘自源码头文件 `Description`（原文）：

> Disk momentum source derived from Foam::fv::propellerDisk with support
> for motion of the body the propeller is attached to.

## 文献与源码依据

- 源码：[`src/fvModels/rigidBodyPropellerDisk/rigidBodyPropellerDisk.H`](../../../../src/fvModels/rigidBodyPropellerDisk/rigidBodyPropellerDisk.H)
- 实现：同目录 `.C`

## 教程与模板

- `tutorials/incompressibleFluid/rotorDisk`（`rotorDisk`）

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
