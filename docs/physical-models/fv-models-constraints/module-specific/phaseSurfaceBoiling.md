# phaseSurfaceBoiling

## 一句话

相界面沸腾

## 适用条件（求解器 / 场 / 前提）

适用: multiphaseEuler

## 字典示例



```c++
// `tutorials/multiphaseEuler/boilingBed/constant/fvModels`
}
}

solidSurfaceBoiling
{
    type            phaseSurfaceBoiling;

    libs            ("libmultiphaseEulerFvModels.so");

    phase           solid;
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
    }

    departureDiameterModel
    {
        type            TolubinskiKostanchuk;
    }

    departureFrequencyModel
    {
        type            KocamustafaogullariIshii;
        Cf              1.18;
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

> Model for nucleate wall boiling on the surface of a third (solid) phase.
>
> This model functions very similarly to the wall boiling model (see that
> model for references). The same sub-models are used, with exactly the same
> specification syntax. The only difference is that the third phase must be
> additionally specified, and that a two-resistance heat transfer model must
> be in operation between the liquid phase and the third phase.

## 文献与源码依据

- 源码：[`applications/modules/multiphaseEuler/fvModels/phaseSurfaceBoiling/phaseSurfaceBoiling.H`](../../../../applications/modules/multiphaseEuler/fvModels/phaseSurfaceBoiling/phaseSurfaceBoiling.H)
- 实现：同目录 `.C`

## 教程与模板

- 见对应求解器 tutorials；物理方程细目由 Phase 3/4 目录承接

## 注意事项

- 本页为 Phase 5 **入口目录**（fvModel 类型与字典位置）
- 多相/燃烧物理细节见 `multiphase`/` 或 `combustion`-radiation/` / `lagrangian`/`
