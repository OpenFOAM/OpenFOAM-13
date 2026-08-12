# phaseSurfaceBoiling

## 一句话
Model for nucleate wall boiling on the surface of a third (solid) phase.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: Euler 相表面沸腾（基类 `fvModel`）
- **注册名**: `phaseSurfaceBoiling`

## 字典示例
```
phaseSurfaceBoiling
{
type            phaseSurfaceBoiling;
libs            ("libmultiphaseEulerFvModels.so");

phase           solid;

// Note: Order is important. This model is one-way. It turns liquid
// into vapour. The phases should be specified in this order.
phases          (water steam);

energySemiImplicit no;

saturationTemperature
{
type            constant;
value           372.76;
}

partitioningModel
{
type            Lavieville;
alphaCrit       0.2;
}

nucleationSiteModel
{
type            LemmertChawla;
}

departureDiameterModel
{
type            TolubinskiKostanchuk;
}

departureFrequencyModel
{
type            KocamustafaogullariIshii;
Cf              1.18;
}
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `phaseSurfaceBoiling`
- 基类: `fvModel`


## 控制方程与关联式
Model for nucleate wall boiling on the surface of a third (solid) phase.

This model functions very similarly to the wall boiling model (see that
model for references). The same sub-models are used, with exactly the same
specification syntax. The only difference is that the third phase must be
additionally specified, and that a two-resistance heat transfer model must
be in operation between the liquid phase and the third phase.

## 文献与源码依据
- 类: `Foam`::fv::phaseSurfaceBoiling`
- 源码路径: `applications/modules/multiphaseEuler/fvModels/phaseSurfaceBoiling/phaseSurfaceBoiling.C`

## 教程与模板
- `tutorials/multiphaseEuler/boilingBed/constant/fvModels`

## 注意事项
- 类型名必须与 RTS 注册名一致：`phaseSurfaceBoiling`。
