# MichaelsBolger

## 一句话
Michaels & Bolger relative velocity model

## 适用条件（求解器 / 场 / 前提）
- 适用: incompressibleDriftFlux
- **族**: 相对速度（基类 `relativeVelocityModel`）
- **注册名**: `MichaelsBolger`

## 字典示例
```
relativeVelocityModel MichaelsBolger;

MichaelsBolgerCoeffs
{
a0          0;    // Extended Michaels & Bolger coefficient,
a1          4.65; // Exponent
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `MichaelsBolger`
- 基类: `relativeVelocityModel`


## 控制方程与关联式
Michaels & Bolger relative velocity model

Reference:
```
Michaels, A. S., & Bolger, J. C. (1962).
Settling rates and sediment volumes
of flocculated kaolin suspensions.
Industrial & Engineering Chemistry Fundamentals, 1(1), 24-33.
```

## 文献与源码依据
- 类: `Foam`::relativeVelocityModels::MichaelsBolger`
- 源码路径: `applications/modules/incompressibleDriftFlux/relativeVelocityModels/MichaelsBolger/MichaelsBolger.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`MichaelsBolger`。
