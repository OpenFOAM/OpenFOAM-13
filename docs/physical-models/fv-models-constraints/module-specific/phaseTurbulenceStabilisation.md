# phaseTurbulenceStabilisation

## 一句话

相湍流稳定化

## 适用条件（求解器 / 场 / 前提）

适用: multiphaseEuler

## 字典示例



```c++
// `tutorials/multiRegion/CHT/wallBoiling/constant/fluid/fvModels`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

phaseTurbulenceStabilisationGas
{
    type            phaseTurbulenceStabilisation;
    libs            ("libmultiphaseEulerFvModels.so");

    phase           gas;

    alphaInversion  0.1;
}

phaseTurbulenceStabilisationLiquid
{
    type            phaseTurbulenceStabilisation;
    libs            ("libmultiphaseEulerFvModels.so");

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

> Phase turbulence stabilisation
>
> In the limit of a phase-fraction->0 the turbulence properties cannot be
> obtained from the phase turbulence model, coupling to the other phase/phases
> is required.  The phaseTurbulenceStabilisation fvModel stabilises the phase
> turbulence properties by adding transfer terms from the corresponding
> properties of the other phases when the phase-fraction is less than the
> specified \c alphaInversion.  This implementation is a generalisation of
> the approach used in the Foam::RASModels::LaheyKEpsilon and
> Foam::RASModels::continuousGasKEpsilon models to handle phase-inversion and
> free-surface flow and can be used with any combination of RAS turbulence
> models.
>
> To stabilise the solution of the phase turbulence equations \c
> alphaInversion can be set to a small value e.g. 1e-2, but unless the phase
> turbulence model is specifically designed to handle phase-inversion and both
> continuous and dispersed regimes it may be useful to set \c alphaInversion
> to a higher value, corresponding to the phase-fraction at which transition
> from continuous to dispersed happens and effectively use the turbulence
> properties of the other phase when the phase is dispersed.  This is of
> course an approximation to the real system and if accurate handling of both
> the continuous and dispersed phase regimes is required specially developed
> models should be used.

## 文献与源码依据

- 源码：[`applications/modules/multiphaseEuler/fvModels/phaseTurbulenceStabilisation/phaseTurbulenceStabilisation.H`](../../../../applications/modules/multiphaseEuler/fvModels/phaseTurbulenceStabilisation/phaseTurbulenceStabilisation.H)
- 实现：同目录 `.C`

## 教程与模板

- 见对应求解器 tutorials；物理方程细目由 Phase 3/4 目录承接

## 注意事项

- 本页为 Phase 5 **入口目录**（fvModel 类型与字典位置）
- 多相/燃烧物理细节见 `multiphase`/` 或 `combustion`-radiation/` / `lagrangian`/`
