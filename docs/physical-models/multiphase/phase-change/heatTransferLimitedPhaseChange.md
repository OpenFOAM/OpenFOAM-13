# heatTransferLimitedPhaseChange

## 一句话
Model for heat transfer rate limited phase change between two phases.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 传热限制相变（基类 `fvModel`）
- **注册名**: `heatTransferLimitedPhaseChange`

## 字典示例
```
phaseChange
{
type            heatTransferLimitedPhaseChange;
libs            ("libmultiphaseEulerFvModels.so");

phases          (steam water);

energySemiImplicit yes;
pressureImplicit no;

saturationTemperature
{
type            constant;
value           372.76;
}
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `heatTransferLimitedPhaseChange`
- 基类: `fvModel`


## 控制方程与关联式
Model for heat transfer rate limited phase change between two phases.

The interface between the two phases is assumed to be at a saturated
condition. This allows the temperature of the interface to be evaluated
from a user-supplied saturation curve. This temperature then defines the
heat flux being transferred to the interface from the surrounding fluid.
The imbalance in the heat fluxes on either side of the interface is then
divided by the latent heat of phase change in order to get the rate at
which mass is being changed from one phase to the other.

This model only supports pure phases. A two-resistance heat transfer model
must also be in operation between the two changing phases.

## 文献与源码依据
- 类: `Foam`::fv::heatTransferLimitedPhaseChange`
- 源码路径: `applications/modules/multiphaseEuler/fvModels/heatTransferLimitedPhaseChange/heatTransferLimitedPhaseChange.C`

## 教程与模板
- `tutorials/multiRegion/CHT/wallBoiling/constant/fluid/fvModels`
- `tutorials/multiphaseEuler/wallBoilingPolydisperseTwoGroups/constant/fvModels`
- `tutorials/multiphaseEuler/wallBoilingPolydisperse/constant/fvModels`
- `tutorials/multiphaseEuler/wallBoilingIATE/constant/fvModels`
- `tutorials/multiphaseEuler/steamInjection/constant/fvModels`

## 注意事项
- 类型名必须与 RTS 注册名一致：`heatTransferLimitedPhaseChange`。
