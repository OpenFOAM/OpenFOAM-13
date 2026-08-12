# bound

## 一句话

场值下界约束

## 适用条件（求解器 / 场 / 前提）

适用: 任意链接 `-lfvConstraints` 的求解器

## 字典示例


```c++
// `tutorials/compressibleVoF/throttle/system/fvConstraints`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

boundp
{
    type       bound;

    field      p;
    min        200;
}

// ************************************************************************* //
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

> Bound the specified scalar field where it is below the specified minimum.
>
> Where the field is unbounded it is set to the maximum of the average of
> the neighbouring cell values and the specified minimum.

## 文献与源码依据

- 源码：[`src/fvConstraints/bound/boundConstraint.H`](../../../../src/fvConstraints/bound/boundConstraint.H)
- 实现：同目录 `.C`

## 教程与模板

- `etc/caseDicts/fvConstraints/`（如 `limitTemperature`、`limitPressure`、`limitLowPressure`）

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
