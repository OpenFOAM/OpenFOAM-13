# homogeneousLiquidPhaseSeparation

## 一句话
Model for the homogeneous nucleation of a solid or liquid phase separating

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 均相液相分离（基类 `fvModel`）
- **注册名**: `homogeneousLiquidPhaseSeparation`

## 字典示例
```
homogeneousLiquidPhaseSeparation
{
type            homogeneousLiquidPhaseSeparation;
libs            ("libmultiphaseEulerFvModels.so");

// Phases between which the transfer occurs. The first phase is the
// solution, and the second is the precipitate.
phases          (liquid sugar);

// The specie that is condensing
specie          C6H12O6;

// Linearise the latent heat contribution into the energy equation?
energySemiImplicit no;

// Solubility given in mass of solute per mass of solvent
solubility      constant 0.9;
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `homogeneousLiquidPhaseSeparation`
- 基类: `fvModel`


## 控制方程与关联式
Model for the homogeneous nucleation of a solid or liquid phase separating
out of a liquid solution

## 文献与源码依据
- 类: `Foam`::fv::homogeneousLiquidPhaseSeparation`
- 源码路径: `applications/modules/multiphaseEuler/fvModels/homogeneousLiquidPhaseSeparation/homogeneousLiquidPhaseSeparation.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`homogeneousLiquidPhaseSeparation`。
