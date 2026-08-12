# wallBoiling

## 一句话
Model for nucleate wall boiling between two phases on the surface of a

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: Euler 壁面沸腾（基类 `fvModel`）
- **注册名**: `wallBoiling`

## 字典示例
```
wallBoiling
{
type            wallBoiling;
libs            ("libmultiphaseEulerFvModels.so");

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
Cn              1;
NRef            30000000;
deltaTRef       10;
}

departureDiameterModel
{
type            TolubinskiKostanchuk;
dRef            0.00024;
dMax            0.0014;
dMin            1e-06;
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

- 注册名 / `type`: `wallBoiling`
- 基类: `fvModel`


## 控制方程与关联式
Model for nucleate wall boiling between two phases on the surface of a
number of wall patches.

This model implements a version of the well-known RPI wall boiling model
(Kurul & Podowski, 1991). The model is based on an implementation described
in Peltola et al. (2019) and is similar to the model described by Peltola &
Pättikangas (2012).

References:
```
Kurul, N., & Podowski, M.Z. (1991).
On the modeling of multidimensional effects in boiling channels.
ANS. Proc. National Heat Transfer Con. Minneapolis, Minnesota, USA,
1991.
ISBN: 0-89448-162-1, pp. 30-40.
```

```
Peltola, J., Pättikangas, T., Bainbridge, W., Lehnigk, R., Schlegel, F.
(2019).
On Development and validation of subcooled nucleate boiling models for
OpenFOAM Foundation Release.
NURETH-18 Conference Proceedings, Portland, Oregon, United States, 2019.
```

```
Peltola, J., & Pättikangas, T.J.H. (2012).
Development and validation of a boiling model for OpenFOAM multiphase
solver.
CFD4NRS-4 Conference Proceedings, Daejeon, Korea, 2012.
paper 59.
```

## 文献与源码依据
- 类: `Foam`::fv::wallBoiling`
- 源码路径: `applications/modules/multiphaseEuler/fvModels/wallBoiling/wallBoiling.C`

## 教程与模板
- `tutorials/multiRegion/CHT/wallBoiling/constant/fluid/fvModels`
- `tutorials/multiphaseEuler/wallBoilingPolydisperseTwoGroups/constant/fvModels`
- `tutorials/multiphaseEuler/wallBoilingPolydisperse/constant/fvModels`
- `tutorials/multiphaseEuler/wallBoilingIATE/constant/fvModels`
- `tutorials/multiphaseEuler/boilingBed/constant/fvModels`

## 注意事项
- 类型名必须与 RTS 注册名一致：`wallBoiling`。
