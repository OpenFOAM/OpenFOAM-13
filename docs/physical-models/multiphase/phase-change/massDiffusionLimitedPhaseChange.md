# massDiffusionLimitedPhaseChange

## 一句话
Model for mass-diffusion rate limited phase change between two phases.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 传质扩散限制相变（基类 `fvModel`）
- **注册名**: `massDiffusionLimitedPhaseChange`

## 字典示例
```
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
species         (H2O);
Le              1.0;
pSat            ArdenBuck;
}
}

diffusiveMassTransfer
{
blending        heatAndDiffusiveMassTransfer;

gas_dispersedIn_liquid_inThe_gas
{
type            spherical;
}

liquid_dispersedIn_gas_inThe_gas
{
type            Frossling;
Le              1.0;
}
}
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `massDiffusionLimitedPhaseChange`
- 基类: `fvModel`


## 控制方程与关联式
Model for mass-diffusion rate limited phase change between two phases.

One of the two phases is considered to be the limiting phase with respect
to the rate of mass-diffusion of a given specie. The transferring specie's
composition on the limiting phase's side of the interface is given by a
run-time selectable interface composition model. A diffusive mass transfer
model then provides a coefficient which when multiplied by the difference
in specie concentration between the interface and the bulk of the limiting
phase gives the rate of mass transfer.

All the specie transfers are combined and the associated latent heat is is
equated to the rate of heat transfer from the two phases to the interface.
This relation is solved for the interface state and the rate of phase
change.

This model requires at least one phase to be multi-component. A
two-resistance heat transfer model must also be in operation between the
two changing phases.

## 文献与源码依据
- 类: `Foam`::fv::massDiffusionLimitedPhaseChange`
- 源码路径: `applications/modules/multiphaseEuler/fvModels/massDiffusionLimitedPhaseChange/massDiffusionLimitedPhaseChange.C`

## 教程与模板
- `tutorials/multiphaseEuler/bubbleColumnEvaporatingReacting/constant/fvModels`
- `tutorials/multiphaseEuler/bubbleColumnEvaporatingDissolving/constant/fvModels`
- `tutorials/multiphaseEuler/bubbleColumnEvaporating/constant/fvModels`

## 注意事项
- 类型名必须与 RTS 注册名一致：`massDiffusionLimitedPhaseChange`。
