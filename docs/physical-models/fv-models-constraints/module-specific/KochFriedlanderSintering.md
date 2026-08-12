# KochFriedlanderSintering

## 一句话

Koch-Friedlander 烧结

## 适用条件（求解器 / 场 / 前提）

适用: multiphaseEuler + 群体平衡

## 字典示例



```c++
// `tutorials/multiphaseEuler/titaniaSynthesisSurface/constant/fvModels`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

reactionDrivenPhaseChange
{
    type            reactionDrivenPhaseChange;
    libs            ("libmultiphaseEulerFvModels.so");

    phases          (vapour particles);

    species         (TiO2);

    energySemiImplicit no;
}

surfaceReactionDrivenPhaseChange
{
    type            reactionDrivenPhaseChange;
    libs            ("libmultiphaseEulerFvModels.so");

    phases          (vapour particles);

    species         (TiO2_s);

    energySemiImplicit no;
}

sintering
{
    type            KochFriedlanderSintering;
    libs            ("libmultiphaseEulerFvModels.so");

    populationBalance aggregates;

    Cs              8.3e24;
    n               4.0;
    m               1.0;
    Ta              3700.0;
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

> Sintering model of Koch and Friedlander (1990). The characteristic time for
> sintering is given by
>
> $$
>     \tau = c_s d_{p_i}^n T^m \exp(T_a/T \cdot [1 - d_{p,min}/d_{p_i}])\;.
> $$
>
> Note that the correction factor in the exponential function can be
> eliminated by setting $d_{p,min}$ to zero which is done by default.
>
> Reference:
>     >     Koch, W., & Friedlander, S. K. (1990).
>     >     The effect of particle coalescence on the surface area of a coagulating
>     >     aerosol.
>     >     Journal of Colloid and Interface Science, 140(2), 419-427.
>     > 

## 文献与源码依据

- 源码：[`applications/modules/multiphaseEuler/fvModels/KochFriedlanderSintering/KochFriedlanderSintering.H`](../../../../applications/modules/multiphaseEuler/fvModels/KochFriedlanderSintering/KochFriedlanderSintering.H)
- 实现：同目录 `.C`

## 教程与模板

- 见对应求解器 tutorials；物理方程细目由 Phase 3/4 目录承接

## 注意事项

- 本页为 Phase 5 **入口目录**（fvModel 类型与字典位置）
- 多相/燃烧物理细节见 `multiphase`/` 或 `combustion`-radiation/` / `lagrangian`/`
