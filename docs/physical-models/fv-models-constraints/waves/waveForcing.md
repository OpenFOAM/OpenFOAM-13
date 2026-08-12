# waveForcing

## 一句话

波浪松弛/强迫（相分数与速度）

## 适用条件（求解器 / 场 / 前提）

适用: VoF 波浪案例；libs libwaves.so

## 字典示例



```c++
// `tutorials/incompressibleVoF/floatingObjectWaves/constant/fvModels`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

forcing
{
    type            waveForcing;

    libs            ("libwaves.so");

    liquidPhase     water;

    origins
    (
        (0     0.75  0.5)
        (0     0.25  0.5)
        (0.25  0     0.5)
        (0.75  0     0.5)
    );

    directions
    (
        ( 0  1  0)
        ( 0 -1  0)
        (-1  0  0)
        ( 1  0  0)
    );

    scale
    {
        type        halfCosineRamp;
        start       0;
        duration    0.5;
    }

    lambdaCoeff         5;
    lambdaBoundaryCoeff 25;

    // Write the forcing fields: forcing:scale, forcing:forceCoeff
    writeForceFields true;
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

> This fvModel applies forcing to the liquid phase-fraction field and all
> components of the vector field to relax the fields towards those
> calculated from the current wave distribution.
>
> The force coefficient $\lambda$ should be set based on the desired level
> of forcing and the residence time the waves through the forcing zone.  For
> example, if waves moving at 2 [m/s] are travelling through a forcing zone 8
> [m] in length, then the residence time is 4 [s]. If it is deemed necessary
> to force for 5 time-scales, then $\lambda$ should be set to equal 5/(4
> [s]) = 1.2 [1/s].  If more aggressive forcing is required adjacent to the
> boundaries, which is often the case if wave boundary conditions are
> specified at outflow boundaries, the optional \c lambdaBoundary
> coefficient can be specified higher than the value of $\lambda$.
>
> Alternatively the forcing force coefficient \c lambdaCoeff can be
> specified in which case $\lambda$ is evaluated by multiplying the
> maximum wave speed by \c lambdaCoeff and dividing by the forcing region
> length.  \c lambdaBoundary is similarly evaluated from
> \c lambdaBoundaryCoeff if specified.

## 文献与源码依据

- 源码：[`src/waves/fvModels/waveForcing/waveForcing.H`](../../../../src/waves/fvModels/waveForcing/waveForcing.H)
- 实现：同目录 `.C`

## 教程与模板

- `tutorials/incompressibleVoF/forcedUpstreamWave`、`floatingObjectWaves`
- 需 `libs` ("libwaves.so");`

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
