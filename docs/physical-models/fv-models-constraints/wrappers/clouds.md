# clouds

## 一句话

Lagrangian parcel 云耦合包装器

## 适用条件（求解器 / 场 / 前提）

适用: 描述/教程含 Lagrangian 的求解器（如 multicomponentFluid、fluid）；需 libs liblagrangianParcel.so

## 字典示例



```c++
// `tutorials/multiRegion/film/cylinderDripping/constant/fluid/fvModels`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

clouds
{
    type    clouds;
    libs    ("liblagrangianParcel.so");
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

> This fvModel adds any number of Lagrangian clouds to any single-phase
> solver. The particles are tracked through, and exchange sources with, the
> Eulerian flow field.
>
> As well as the fvModel controls, properties must be specified for each
> cloud. For a single cloud, these should be provided in the
> constant/cloudProperties file. For multiple clouds, the list of cloud names
> must first be provided in the constant/clouds file. Then, each named cloud
> has its properties specified in its constant/\<cloudName\>Properties file.
>
> The application of sources to the Eulerian fields is controlled by the
> solution/coupled switch in each cloud's properties file. If set to "true"
> then the Eulerian phase will have forces, and heat and mass sources applied
> to it by the Lagrangian phase. If set to "false" then these will be omitted,
> and the Lagrangian phase will not affect the Eulerian phase.
>
> If this model is used with an incompressible solver, then the density of
> the Eulerian phase must be specified in the constant/physicalProperties
> dictionary.
>
> Gravity will be read from the constant/g file if present, otherwise it will
> default to zero.

## 文献与源码依据

- 源码：[`src/lagrangian/parcel/fvModels/clouds/clouds.H`](../../../../src/lagrangian/parcel/fvModels/clouds/clouds.H)
- 实现：同目录 `.C`

## 教程与模板

- 模板：`etc/caseDicts/fvModels/clouds`
- 教程：`tutorials/multicomponentFluid/*` 含 `type` clouds` 的案例；`tutorials/multiRegion/film/*/constant/fluid/fvModels`

## 注意事项

- 需 `libs` ("liblagrangianParcel.so");`（或案例指定库）
- 云属性字典与子模型见 `lagrangian`/`（Phase 4）
