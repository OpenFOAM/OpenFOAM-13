# interRegionPorosityForce

## 一句话

区域间孔隙阻力

## 适用条件（求解器 / 场 / 前提）

适用: 多区域；多孔结构映射

## 字典示例



```c++
// `tutorials/multiRegion/CHT/heatExchanger/constant/air/fvModels`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

airToPorous
{
    type            interRegionHeatTransfer;

    libs            ("libinterRegionFvModels.so");

    nbrRegion       porous;
    master          false;

    interpolationMethod intersection;

    semiImplicit    no;
}

porosity
{
    type            interRegionPorosityForce;

    libs            ("libinterRegionFvModels.so");

    interRegionPorosityForceCoeffs
    {
        nbrRegion       porous;

        interpolationMethod intersection;

        type            DarcyForchheimer;

        d   (-1000 -1000 1e4);
        f   (0 0 0);

        coordinateSystem
        {
            type    cartesian;
            origin  (0 0 0);
            coordinateRotation
            {
                type    axesRotation;
                e1      (0 1 0);
                e2      (0 0 1);
            }
        }
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

> This model applies the force exerted on the fluid by a porous media, the
> extent of which is defined by an overlapping region

## 文献与源码依据

- 源码：[`src/fvModels/interRegion/interRegionPorosityForce/interRegionPorosityForce.H`](../../../../src/fvModels/interRegion/interRegionPorosityForce/interRegionPorosityForce.H)
- 实现：同目录 `.C`

## 教程与模板

- 多区域 CHT / 换热器相关 `tutorials/multiRegion/`

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
