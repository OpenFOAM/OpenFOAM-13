# zeroDimensionalMassSource

## 一句话

零维质量源

## 适用条件（求解器 / 场 / 前提）

适用: 零维/简化反应器类设置

## 字典示例



> （由源码构造函数推断，无官方教程实例）

```c++
zeroDimensionalMassSource
    {
        type            zeroDimensionalMassSource;

        massFlowRate    1e-4;
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

> This fvModel applies a mass source to the continuity equation and to all
> field equations, in a zero-dimensional case. Correction is made to account
> for the mass that exits the domain due to expansion in space, so that the
> model correctly applies a total mass flow rate.
>
> This model requires a corresponding field source to be specified for all
> solved-for fields.
>
> This model will write out additional fields, zeroDimensionalMassSource:m
> and zeroDimensionalMassSource:factor. The zeroDimensionalMassSource:m field
> is the total accumulated mass; the sum of the starting mass, plus all mass
> added by models of this type. This may differ from the actual current mass
> (= rho*V) within the zero-dimensional cell if pressure or density
> constraints are being used. The zeroDimensionalMassSource:factor field is
> the ratio between the current mass or volume and the total accumulated mass
> or volume.

## 文献与源码依据

- 源码：[`src/fvModels/general/zeroDimensionalMassSource/zeroDimensionalMassSource.H`](../../../../src/fvModels/general/zeroDimensionalMassSource/zeroDimensionalMassSource.H)
- 实现：同目录 `.C`

## 教程与模板

- `etc/caseDicts/fvModels/`
- 例：`tutorials/fluid/angledDuct`（porosity）、`tutorials/incompressibleFluid/rotorDisk`（转子类）

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
