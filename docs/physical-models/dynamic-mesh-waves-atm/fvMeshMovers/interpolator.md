# interpolator

## 一句话

插值驱动网格运动

## 适用条件（求解器 / 场 / 前提）

dynamicMeshDict → mover

## 字典示例

```c++
mover   interpolator;

interpolatorCoeffs
{
    field               wantedDisplacement;
    displacement        yes;
    interpolationScheme linear;
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

> Interpolates pre-specified motion specified as a set of pointVectorFields.
>
> The motion can be provided either as a set of displacement or position
> fields and the entry \c displacement specified accordingly.

## 文献与源码依据

- 源码：[`src/fvMeshMovers/interpolator/interpolator_fvMeshMover.H`](../../../../src/fvMeshMovers/interpolator/interpolator_fvMeshMover.H)
- 实现：同目录 `.C`

## 教程与模板

- `movingMesh` 模块与含 `dynamicMeshDict` 的流体教程

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
