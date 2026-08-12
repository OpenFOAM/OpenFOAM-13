# Quemada

## 一句话
Quemada viscosity model for colloidal dispersions.

## 适用条件（求解器 / 场 / 前提）
- 适用: incompressibleDriftFlux
- **族**: 混合物粘度（基类 `mixtureViscosityModel`）
- **注册名**: `Quemada`

## 字典示例
```
viscosityModel  Quemada;

rho         1996; // Dispersed phase density

q           2;    // Exponent, defaults to 2
muMax       1e-2; // Maximum viscosity (for numerical stability)
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `Quemada`
- 基类: `mixtureViscosityModel`


## 控制方程与关联式
Quemada viscosity model for colloidal dispersions.

Reference:
```
Quemada, D. (1998).
Rheological modelling of complex fluids. I.
The concept of effective volume fraction revisited.
The European Physical Journal-Applied Physics, 1(1), 119-127.
```

## 文献与源码依据
- 类: `Foam`::mixtureViscosityModels::Quemada`
- 源码路径: `applications/modules/incompressibleDriftFlux/mixtureViscosityModels/Quemada/Quemada.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`Quemada`。
