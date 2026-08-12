# massSource

## 一句话

质量源（及可选伴随动量/能量/组分）

## 适用条件（求解器 / 场 / 前提）

适用: 可压或含密度的流体求解器

## 字典示例



```c++
// `tutorials/multicomponentFluid/filter/constant/fvModels`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

buoyancyForce
{
    type        buoyancyForce;
}

clouds
{
    type    clouds;
    libs    ("liblagrangianParcel.so");
}

filter1
{
    type            porosityForce;

    porosityForceCoeffs
    {
        cellZone        filter;

        type            DarcyForchheimer;

        d   (500000 -1000 -1000);
        f   (0 0 0);

        coordinateSystem
        {
            type    cartesian;
            origin  (0 0 0);
            coordinateRotation
            {
                type    axesRotation;
                e1  (1 0 0);
                e2  (0 1 0);
            }
        }
    }
}

massSource
{
    type            massSource;

    cellZone
    {
        type            containsPoints;
        points          ((2.75 0.5 0));
    }

    massFlowRate
    {
        type            scale;
        scale           squarePulse;
        start           0.2;
        duration        2;
        value           1e-4;
    }
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

> This fvModel applies a mass source to the continuity equation and to all
> field equations. It can be applied to compressible solvers, such as fluid,
> isothermalFluid, compressibleVoF and multiphaseEuler. For incompressible
> solvers, use the volumeSource model instead.
>
> This model requires a corresponding field source to be specified for all
> solved-for fields.

## 文献与源码依据

- 源码：[`src/fvModels/general/massSource/massSource.H`](../../../../src/fvModels/general/massSource/massSource.H)
- 实现：同目录 `.C`

## 教程与模板

- `etc/caseDicts/fvModels/`
- 例：`tutorials/fluid/angledDuct`（porosity）、`tutorials/incompressibleFluid/rotorDisk`（转子类）

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
