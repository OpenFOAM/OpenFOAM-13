# meanVelocityForce

## 一句话

维持平均流速的体积力

## 适用条件（求解器 / 场 / 前提）

适用: 流体；周期通道等

## 字典示例



> （由源码构造函数推断，无官方教程实例）

```c++
meanVelocityConstraint
    {
        type            meanVelocityForce;

        cellZone        all;

        U               U;          // Name of velocity field

        Ubar            (10.0 0 0); // Desired mean velocity
        relaxation      0.2;        // Optional relaxation factor
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

> Calculates and applies the force necessary to maintain the specified mean
> velocity.

## 文献与源码依据

- 源码：[`src/fvConstraints/meanVelocityForce/meanVelocityForce.H`](../../../../src/fvConstraints/meanVelocityForce/meanVelocityForce.H)
- 实现：同目录 `.C`

## 教程与模板

- `etc/caseDicts/fvConstraints/`（如 `limitTemperature`、`limitPressure`、`limitLowPressure`）

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
