# Lavieville

## 一句话
Lavieville wall heat flux partitioning model.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler `wallBoiling` / `phaseSurfaceBoiling` 子模型
- **族**: 壁面沸腾/partitioningModel（基类 `partitioningModel`）
- **注册名**: `Lavieville`

## 字典示例
```
// 见源码 Usage；`type` 注册名为 `Lavieville`
Lavieville
{
    type    Lavieville;
    // ...
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `Lavieville`
- 基类: `partitioningModel`


## 控制方程与关联式
Lavieville wall heat flux partitioning model.

Model parameters:
alphaCrit: critical liquid fraction

Reference:
```
Lavieville, J., Quemerais, E., Mimouni, S., Boucker, M., &
Mechitoua, N. (2006).
NEPTUNE CFD V1. 0 theory manual.
NEPTUNE report Nept_2004_L1, 2(3).
```

## 文献与源码依据
- 类: `Foam`::wallBoilingModels::partitioningModels::Lavieville`
- 源码路径: `applications/modules/multiphaseEuler/fvModels/wallBoiling/partitioningModels/Lavieville/Lavieville.C`

## 教程与模板
- `tutorials/multiRegion/CHT/wallBoiling/constant/fluid/fvModels`
- `tutorials/multiphaseEuler/wallBoilingPolydisperseTwoGroups/constant/fvModels`
- `tutorials/multiphaseEuler/wallBoilingPolydisperse/constant/fvModels`
- `tutorials/multiphaseEuler/wallBoilingIATE/constant/fvModels`
- `tutorials/multiphaseEuler/boilingBed/constant/fvModels`

## 注意事项
- 类型名必须与 RTS 注册名一致：`Lavieville`。
