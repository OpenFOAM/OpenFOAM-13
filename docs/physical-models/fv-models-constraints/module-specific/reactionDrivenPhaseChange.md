# reactionDrivenPhaseChange

## 一句话

反应驱动相变

## 适用条件（求解器 / 场 / 前提）

适用: multiphaseEuler + 反应库

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

> Model for mass-diffusion rate limited phase change between two phases.
>
> This model will transfer species out of a reacting phase at exactly the
> rate at which the reactions produce them. It facilitates a rough
> approximation to surface reactions for which certain species get consumed
> at the interface.

## 文献与源码依据

- 源码：[`applications/modules/multiphaseEuler/fvModels/reactionDrivenPhaseChange/reactionDrivenPhaseChange.H`](../../../../applications/modules/multiphaseEuler/fvModels/reactionDrivenPhaseChange/reactionDrivenPhaseChange.H)
- 实现：同目录 `.C`

## 教程与模板

- 见对应求解器 tutorials；物理方程细目由 Phase 3/4 目录承接

## 注意事项

- 本页为 Phase 5 **入口目录**（fvModel 类型与字典位置）
- 多相/燃烧物理细节见 `multiphase`/` 或 `combustion`-radiation/` / `lagrangian`/`
