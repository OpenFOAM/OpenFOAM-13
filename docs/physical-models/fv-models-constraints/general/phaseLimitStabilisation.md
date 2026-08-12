# phaseLimitStabilisation

## 一句话

相分数极限稳定化

## 适用条件（求解器 / 场 / 前提）

适用: 多相求解器

## 字典示例



```c++
// `tutorials/compressibleVoF/climbingRod/constant/fvModels`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

stabilisation
{
    type            phaseLimitStabilisation;

    field           sigma.liquid;
    rate            rLambda.liquid;
    residualAlpha   5e-3;
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

> Stabilisation source for phase transport equations
>
> Applies an implicit source to the phase transport equation for the
> specified \c field when the phase volume fraction is below \c
> residualAlpha. The stabilisation rate is provided by the registered \c rate
> which can either be a uniformDimensionedScalarField, a volScalarField or a
> volScalarField::Internal. The \c field is currently stabilised towards zero
> in the limit of the phase volume fraction approaching zero but this could
> be extended to support a specified value or a value or field looked-up from
> the database.

## 文献与源码依据

- 源码：[`src/fvModels/general/phaseLimitStabilisation/phaseLimitStabilisation.H`](../../../../src/fvModels/general/phaseLimitStabilisation/phaseLimitStabilisation.H)
- 实现：同目录 `.C`

## 教程与模板

- `etc/caseDicts/fvModels/`
- 例：`tutorials/fluid/angledDuct`（porosity）、`tutorials/incompressibleFluid/rotorDisk`（转子类）

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
