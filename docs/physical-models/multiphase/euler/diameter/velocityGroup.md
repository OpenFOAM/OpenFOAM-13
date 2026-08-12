# velocityGroup

## 一句话
Computes the Sauter mean diameter based on a user specified size

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 相直径模型（基类 `diameterModel`）
- **注册名**: `velocityGroup`

## 字典示例
```
diameterModel   velocityGroup;

velocityGroupCoeffs
{
populationBalance    bubbles;

shapeModel           spherical;

sizeGroups
(
f1 {dSph 1e-3; }
f2 {dSph 2e-3; }
f3 {dSph 3e-3; }
f4 {dSph 4e-3; }
f5 {dSph 5e-3; }
...
);
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `velocityGroup`
- 基类: `diameterModel`


## 控制方程与关联式
Computes the Sauter mean diameter based on a user specified size
distribution, defined in terms of size class fractions. Intended for use
with a population balance model to account for the evolution of a size
distribution by means of coalescence, breakup, drift and nucleation.

## 文献与源码依据
- 类: `Foam`::diameterModels::velocityGroup`
- 源码路径: `applications/modules/multiphaseEuler/populationBalance/diameterModels/velocityGroup/velocityGroup.C`

## 教程与模板
- `tutorials/multiphaseEuler/wallBoilingPolydisperseTwoGroups/constant/phaseProperties`
- `tutorials/multiphaseEuler/wallBoilingPolydisperse/constant/phaseProperties`
- `tutorials/multiphaseEuler/titaniaSynthesisSurface/constant/phaseProperties`
- `tutorials/multiphaseEuler/titaniaSynthesis/constant/phaseProperties`
- `tutorials/multiphaseEuler/pipeBend/constant/phaseProperties`

## 注意事项
- 类型名必须与 RTS 注册名一致：`velocityGroup`。
