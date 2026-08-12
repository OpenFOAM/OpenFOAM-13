# reactionDrivenPhaseChange

## 一句话
Model for mass-diffusion rate limited phase change between two phases.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 反应驱动相变（基类 `fvModel`）
- **注册名**: `reactionDrivenPhaseChange`

## 字典示例
```
phaseChange
{
type            reactionDrivenPhaseChange;
libs            ("libmultiphaseEulerFvModels.so");

// Note: Order is important. The reactions in the first phase define
// the rate of phase change. If phase change also occurs as a result of
// reactions in the second phase then a second model should be added
// with the phases reversed.
phases          (vapour particles);

species         (TiO2);

energySemiImplicit no;
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `reactionDrivenPhaseChange`
- 基类: `fvModel`


## 控制方程与关联式
Model for mass-diffusion rate limited phase change between two phases.

This model will transfer species out of a reacting phase at exactly the
rate at which the reactions produce them. It facilitates a rough
approximation to surface reactions for which certain species get consumed
at the interface.

## 文献与源码依据
- 类: `Foam`::fv::reactionDrivenPhaseChange`
- 源码路径: `applications/modules/multiphaseEuler/fvModels/reactionDrivenPhaseChange/reactionDrivenPhaseChange.C`

## 教程与模板
- `tutorials/multiphaseEuler/titaniaSynthesisSurface/constant/fvModels`
- `tutorials/multiphaseEuler/titaniaSynthesis/constant/fvModels`

## 注意事项
- 类型名必须与 RTS 注册名一致：`reactionDrivenPhaseChange`。
