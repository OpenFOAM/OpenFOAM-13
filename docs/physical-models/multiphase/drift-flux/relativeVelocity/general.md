# general

## 一句话
General relative velocity model

## 适用条件（求解器 / 场 / 前提）
- 适用: incompressibleDriftFlux
- **族**: 相对速度（基类 `relativeVelocityModel`）
- **注册名**: `general`

## 字典示例


```c++
// `tutorials/incompressibleDriftFlux/dahl/constant/phaseProperties`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

phases (sludge water);

relativeVelocityModel simple;

"(simple|general)Coeffs"
{
    Vc              2.241e-4;
    a               285.84;
    a1              0.1;
    residualAlpha   0;
}

// ************************************************************************* //
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `general`
- 基类: `relativeVelocityModel`


## 控制方程与关联式
General relative velocity model

## 文献与源码依据
- 类: `Foam`::relativeVelocityModels::general`
- 源码路径: `applications/modules/incompressibleDriftFlux/relativeVelocityModels/general/general.C`

## 教程与模板
- `tutorials/incompressibleDriftFlux/tank3D/constant/phaseProperties`
- `tutorials/incompressibleDriftFlux/mixerVessel2DMRF/constant/phaseProperties`
- `tutorials/incompressibleDriftFlux/dahl/constant/phaseProperties`

## 注意事项
- 类型名必须与 RTS 注册名一致：`general`。
