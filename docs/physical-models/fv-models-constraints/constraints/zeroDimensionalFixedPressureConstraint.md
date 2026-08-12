# zeroDimensionalFixedPressureConstraint

## 一句话

零维定压约束

## 适用条件（求解器 / 场 / 前提）

适用: 零维设置

## 字典示例



> （由源码构造函数推断，无官方教程实例）

```c++
{
        type            zeroDimensionalFixedPressure;

        // Name of the pressure field, default = p
        //p               p;

        // Name of the density field, default = rho
        //rho             rho;

        // Pressure value
        pressure        1e5;
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

> Zero-dimensional fixed pressure constraint. Should be used in conjunction
> with the zeroDimensionalFixedPressureModel.
>
> This constraint and model facilitates specification of a constant or
> time-varying pressure. It adds mass source terms proportional to the error
> that remains when the pressure equation is evaluated at the desired
> pressure. Iteration may be necessary to converge the constraint in the case
> of non-linear equations of state.
>
> Properties are added or removed with their current value. The model
> therefore represents a uniform expansion or contraction in infinite space.

## 文献与源码依据

- 源码：[`src/fvConstraints/zeroDimensionalFixedPressure/zeroDimensionalFixedPressureConstraint.H`](../../../../src/fvConstraints/zeroDimensionalFixedPressure/zeroDimensionalFixedPressureConstraint.H)
- 实现：同目录 `.C`

## 教程与模板

- `etc/caseDicts/fvConstraints/`（如 `limitTemperature`、`limitPressure`、`limitLowPressure`）

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
