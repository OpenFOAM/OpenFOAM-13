# `ArdenBuck`

## 一句话

Arden–Buck 饱和压力

## 适用条件（求解器 / 场 / 前提）

- 类别：`saturationModels`
- 适用: `multicomponentFluid` / `XiFluid` / 相变饱和模型相关求解器（见矩阵）

## 字典示例




> （由源码构造函数推断，无官方教程实例）

```c++
// （由源码构造函数推断，无官方教程实例）
// ArdenBuck 无用户系数：饱和蒸汽压关联内置于实现
type ArdenBuck;
```

## 参数表

见源码头文件。

## 控制方程与关联式

ArdenBuck equation for the vapour pressure of moist air.

## 文献与源码依据

- [`src/thermophysicalModels/saturationModels/ArdenBuck/ArdenBuck.H`](../../../src/thermophysicalModels/saturationModels/ArdenBuck/ArdenBuck.H)

## 教程与模板

- `tutorials/multicomponentFluid/**`、`tutorials/XiFluid/**`、相变教程

## 注意事项

- Phase 4 将补充燃烧机理与反应速率全谱；此处给出物性/化学支撑模型。
