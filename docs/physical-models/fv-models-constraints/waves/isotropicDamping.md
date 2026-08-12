# isotropicDamping

## 一句话

各向同性阻尼区

## 适用条件（求解器 / 场 / 前提）

适用: VoF 波浪；libs libwaves.so

## 字典示例



```c++
// `tutorials/incompressibleVoF/forcedUpstreamWave/constant/fvModels`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

forcing
{
    type            waveForcing;

    libs            ("libwaves.so");

    liquidPhase     water;

    origin          (600 0 0);
    direction       (1 0 0);

    scale
    {
        type        halfCosineRamp;
        start       0;
        duration    300;
    }

    lambda          0.5;
}

damping
{
    type            isotropicDamping;

    libs            ("libwaves.so");

    origin          (0 0 0);
    direction       (-1 0 0);

    scale
    {
        type        halfCosineRamp;
        start       0;
        duration    600;
    }

    lambda          0.5;

    value           (2 0 0);
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

> This fvModel applies an implicit forcing force to all components of the
> vector field to relax the field towards a specified uniform value.  Its
> intended purpose is to damp the motions of an interface in the region
> approaching an outlet so that no reflections are generated.
>
> The forcing force coefficient $\lambda$ should be set based on the
> desired level of forcing and the residence time of a perturbation through
> the forcing zone.  For example, if waves moving at 2 [m/s] are travelling
> through a forcing zone 8 [m] in length, then the residence time is 4 [s]. If
> it is deemed necessary to damp for 5 time-scales, then $\lambda$ should
> be set to equal 5/(4 [s]) = 1.2 [1/s].

## 文献与源码依据

- 源码：[`src/waves/fvModels/isotropicDamping/isotropicDamping.H`](../../../../src/waves/fvModels/isotropicDamping/isotropicDamping.H)
- 实现：同目录 `.C`

## 教程与模板

- `tutorials/incompressibleVoF/forcedUpstreamWave`、`floatingObjectWaves`
- 需 `libs` ("libwaves.so");`

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
