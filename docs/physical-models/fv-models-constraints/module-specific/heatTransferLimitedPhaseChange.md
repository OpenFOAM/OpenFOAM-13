# heatTransferLimitedPhaseChange

## 一句话

传热限制相变

## 适用条件（求解器 / 场 / 前提）

适用: multiphaseEuler

## 字典示例



```c++
// `tutorials/multiRegion/CHT/wallBoiling/constant/fluid/fvModels`
phase           liquid;

    alphaInversion  0.1;
}

heatTransferLimitedPhaseChange
{
    type            heatTransferLimitedPhaseChange;
    libs            ("libmultiphaseEulerFvModels.so");

    phases          (liquid gas);

    energySemiImplicit yes;
    pressureImplicit yes;

    saturationTemperature
    {
        type            function1;
        function
        {
            type            table;
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

> Model for heat transfer rate limited phase change between two phases.
>
> The interface between the two phases is assumed to be at a saturated
> condition. This allows the temperature of the interface to be evaluated
> from a user-supplied saturation curve. This temperature then defines the
> heat flux being transferred to the interface from the surrounding fluid.
> The imbalance in the heat fluxes on either side of the interface is then
> divided by the latent heat of phase change in order to get the rate at
> which mass is being changed from one phase to the other.
>
> This model only supports pure phases. A two-resistance heat transfer model
> must also be in operation between the two changing phases.

## 文献与源码依据

- 源码：[`applications/modules/multiphaseEuler/fvModels/heatTransferLimitedPhaseChange/heatTransferLimitedPhaseChange.H`](../../../../applications/modules/multiphaseEuler/fvModels/heatTransferLimitedPhaseChange/heatTransferLimitedPhaseChange.H)
- 实现：同目录 `.C`

## 教程与模板

- 见对应求解器 tutorials；物理方程细目由 Phase 3/4 目录承接

## 注意事项

- 本页为 Phase 5 **入口目录**（fvModel 类型与字典位置）
- 多相/燃烧物理细节见 `multiphase`/` 或 `combustion`-radiation/` / `lagrangian`/`
