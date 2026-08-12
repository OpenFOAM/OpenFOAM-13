# massDiffusionLimitedPhaseChange

## 一句话

扩散限制相变

## 适用条件（求解器 / 场 / 前提）

适用: multiphaseEuler

## 字典示例



```c++
// `tutorials/multiphaseEuler/bubbleColumnEvaporatingDissolving/constant/fvModels`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

phaseChange
{
    type            massDiffusionLimitedPhaseChange;
    libs            ("libmultiphaseEulerFvModels.so");

    phases          (gas liquid);

    energySemiImplicit yes;

    interfaceComposition
    {
        gas_liquid_inThe_gas
        {
            type            saturated;
            species         (water);
            Le              1.0;
            pSat            ArdenBuck;
        }

        gas_liquid_inThe_liquid
        {
            type            Henry;
            species         (air);
            k               (1.492e-2);
            Le              1.0;
        }
    }

    diffusiveMassTransfer
    {
        blending        heatAndDiffusiveMassTransfer;

        gas_dispersedIn_liquid_inThe_gas
        {
            type            spherical;
        }

        gas_dispersedIn_liquid_inThe_liquid
        {
            type            Frossling;
            Le              1.0;
        }

        liquid_dispersedIn_gas_inThe_gas
        {
            type            Frossling;
            Le              1.0;
        }

        liquid_dispersedIn_gas_inThe_liquid
        {
            type            spherical;
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

> Model for mass-diffusion rate limited phase change between two phases.
>
> One of the two phases is considered to be the limiting phase with respect
> to the rate of mass-diffusion of a given specie. The transferring specie's
> composition on the limiting phase's side of the interface is given by a
> run-time selectable interface composition model. A diffusive mass transfer
> model then provides a coefficient which when multiplied by the difference
> in specie concentration between the interface and the bulk of the limiting
> phase gives the rate of mass transfer.
>
> All the specie transfers are combined and the associated latent heat is is
> equated to the rate of heat transfer from the two phases to the interface.
> This relation is solved for the interface state and the rate of phase
> change.
>
> This model requires at least one phase to be multi-component. A
> two-resistance heat transfer model must also be in operation between the
> two changing phases.

## 文献与源码依据

- 源码：[`applications/modules/multiphaseEuler/fvModels/massDiffusionLimitedPhaseChange/massDiffusionLimitedPhaseChange.H`](../../../../applications/modules/multiphaseEuler/fvModels/massDiffusionLimitedPhaseChange/massDiffusionLimitedPhaseChange.H)
- 实现：同目录 `.C`

## 教程与模板

- 见对应求解器 tutorials；物理方程细目由 Phase 3/4 目录承接

## 注意事项

- 本页为 Phase 5 **入口目录**（fvModel 类型与字典位置）
- 多相/燃烧物理细节见 `multiphase`/` 或 `combustion`-radiation/` / `lagrangian`/`
