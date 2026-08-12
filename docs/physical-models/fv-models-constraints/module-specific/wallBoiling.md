# wallBoiling

## 一句话

壁面沸腾

## 适用条件（求解器 / 场 / 前提）

适用: multiphaseEuler；Phase 3

## 字典示例



```c++
// `tutorials/multiRegion/CHT/wallBoiling/constant/fluid/fvModels`
format          csv;
            nHeaderLine     1;
            units           ([MPa] [K]);
            columns         (1 0);
            mergeSeparators no;
            file "$FOAM_TUTORIALS/resources/thermoData/wallBoiling-saturation.csv";
            outOfBounds     clamp;
            interpolationScheme linear;
        }
    }
}

wallBoiling
{
    type            wallBoiling;

    libs            ("libmultiphaseEulerFvModels.so");

    phases          (liquid gas);

    energySemiImplicit no;

    saturationTemperature
    {
        $../../heatTransferLimitedPhaseChange/saturationTemperature;
    }

    partitioningModel
    {
        type            Lavieville;
        alphaCrit       0.2;
    }

    nucleationSiteModel
    {
        type            LemmertChawla;
        Cn              1;
        NRef            30000000;
        deltaTRef       10;
    }

    departureDiameterModel
    {
        type            TolubinskiKostanchuk;
        dRef            0.00024;
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

> Model for nucleate wall boiling between two phases on the surface of a
> number of wall patches.
>
> This model implements a version of the well-known RPI wall boiling model
> (Kurul & Podowski, 1991). The model is based on an implementation described
> in Peltola et al. (2019) and is similar to the model described by Peltola &
> Pättikangas (2012).
>
> References:
>     >     Kurul, N., & Podowski, M.Z. (1991).
>     >     On the modeling of multidimensional effects in boiling channels.
>     >     ANS. Proc. National Heat Transfer Con. Minneapolis, Minnesota, USA,
>     >     1991.
>     >     ISBN: 0-89448-162-1, pp. 30-40.
>     > 
>
>     >     Peltola, J., Pättikangas, T., Bainbridge, W., Lehnigk, R., Schlegel, F.
>     >     (2019).
>     >     On Development and validation of subcooled nucleate boiling models for
>     >     OpenFOAM Foundation Release.
>     >     NURETH-18 Conference Proceedings, Portland, Oregon, United States, 2019.
>     > 
>
>     >     Peltola, J., & Pättikangas, T.J.H. (2012).
>     >     Development and validation of a boiling model for OpenFOAM multiphase
>     >     solver.
>     >     CFD4NRS-4 Conference Proceedings, Daejeon, Korea, 2012.
>     >     paper 59.
>     > 

## 文献与源码依据

- 源码：[`applications/modules/multiphaseEuler/fvModels/wallBoiling/wallBoiling.H`](../../../../applications/modules/multiphaseEuler/fvModels/wallBoiling/wallBoiling.H)
- 实现：同目录 `.C`

## 教程与模板

- 见对应求解器 tutorials；物理方程细目由 Phase 3/4 目录承接

## 注意事项

- 本页为 Phase 5 **入口目录**（fvModel 类型与字典位置）
- 多相/燃烧物理细节见 `multiphase`/` 或 `combustion`-radiation/` / `lagrangian`/`
