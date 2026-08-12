# fixedValueConstraint

## 一句话

任意场固定值约束

## 适用条件（求解器 / 场 / 前提）

适用: 通用；指定 field

## 字典示例



> （由源码构造函数推断，无官方教程实例）

```c++
porosityTurbulence
    {
        type            fixedValueConstraint;

        cellZone        porosity;

        fieldValues
        {
            k           1;
            epsilon     150;
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

> Constrain the field values within a specified region.

## 文献与源码依据

- 源码：[`src/fvConstraints/fixedValue/fixedValueConstraint.H`](../../../../src/fvConstraints/fixedValue/fixedValueConstraint.H)
- 实现：同目录 `.C`

## 教程与模板

- `etc/caseDicts/fvConstraints/`（如 `limitTemperature`、`limitPressure`、`limitLowPressure`）

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
