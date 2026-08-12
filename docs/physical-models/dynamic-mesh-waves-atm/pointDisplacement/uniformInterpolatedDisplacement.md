# uniformInterpolatedDisplacement

## 一句话

均匀插值位移

## 适用条件（求解器 / 场 / 前提）

pointDisplacement

## 字典示例

```c++
walls
{
    type                uniformInterpolatedDisplacement;
    value               uniform (0 0 0);
    field               wantedDisplacement;
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

> Interpolates pre-specified motion.
>
> Motion specified as pointVectorFields.

## 文献与源码依据

- 源码：[`src/fvMotionSolver/pointPatchFields/derived/uniformInterpolatedDisplacement/uniformInterpolatedDisplacementPointPatchVectorField.H`](../../../../src/fvMotionSolver/pointPatchFields/derived/uniformInterpolatedDisplacement/uniformInterpolatedDisplacementPointPatchVectorField.H)
- 实现：同目录 `.C`

## 教程与模板

- 动网格教程中的 `0/pointDisplacement`；BC 全谱见 Phase 2

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
