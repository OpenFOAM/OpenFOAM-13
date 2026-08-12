# linear

## 一句话
Linear wall heat flux partitioning model.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler `wallBoiling` / `phaseSurfaceBoiling` 子模型
- **族**: 壁面沸腾/partitioningModel（基类 `partitioningModel`）
- **注册名**: `linear`

## 字典示例
```
// 见源码 Usage；`type` 注册名为 `linear`
linear
{
    type    linear;
    // ...
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `linear`
- 基类: `partitioningModel`


## 控制方程与关联式
Linear wall heat flux partitioning model.

Proposed threshold liquid fractions:
- alphaLiquid1 0.1
- alphaLiquid0 0.05

```
Ioilev, A., Samigulin, M., Ustinenko (2007).
Advances in the modeling of cladding heat transfer
and critical heat flux in boiling water reactor fuel assemblies.
In Proc. 12th International Topical Meeting on
Nuclear Reactor Thermal Hydraulics (NURETH-12),
Pittsburgh, Pennsylvania, USA.
```

## 文献与源码依据
- 类: `Foam`::wallBoilingModels::partitioningModels::linear`
- 源码路径: `applications/modules/multiphaseEuler/fvModels/wallBoiling/partitioningModels/linear/linear.C`

## 教程与模板
- `tutorials/multiRegion/CHT/multiphaseCoolingCylinder2D/constant/fluid/phaseProperties`
- `tutorials/multiphaseEuler/mixerVessel2DMRF/constant/phaseProperties`
- `tutorials/multiphaseEuler/mixerVessel2D/constant/phaseProperties`
- `tutorials/multiphaseEuler/injection/constant/phaseProperties`
- `tutorials/multiphaseEuler/bubbleColumnLES/constant/phaseProperties`

## 注意事项
- 类型名必须与 RTS 注册名一致：`linear`。
