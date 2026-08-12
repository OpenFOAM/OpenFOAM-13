# homogeneousCondensation

## 一句话
Model for the homogeneous nucleation of liquid droplets out of a gaseous

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 均相凝结（基类 `fvModel`）
- **注册名**: `homogeneousCondensation`

## 字典示例
```
homogeneousCondensation
{
type            homogeneousCondensation;
libs            ("libmultiphaseEulerFvModels.so");

// Phases between which the transfer occurs. The first phase is the
// gas, and the second is the condensed liquid.
phases          (gas water);

// The specie that is condensing
specie          H2O;

// Linearise the latent heat contribution into the energy equation?
energySemiImplicit no;

// Saturation curve for the specie in the gaseous phase
pSat            ArdenBuck;
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `homogeneousCondensation`
- 基类: `fvModel`


## 控制方程与关联式
Model for the homogeneous nucleation of liquid droplets out of a gaseous
mixture

## 文献与源码依据
- 类: `Foam`::fv::homogeneousCondensation`
- 源码路径: `applications/modules/multiphaseEuler/fvModels/homogeneousCondensation/homogeneousCondensation.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`homogeneousCondensation`。
