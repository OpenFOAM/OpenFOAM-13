# Landman

## 一句话
Landman packing dispersion model for industrial separations

## 适用条件（求解器 / 场 / 前提）
- 适用: incompressibleDriftFlux
- **族**: 堆积弥散（基类 `packingDispersionModel`）
- **注册名**: `Landman`

## 字典示例
```
packingDispersionModel Landman;

LandmanCoeffs
{
sigma0          2.11e-3;
n               5;
alphaGel        0.14;
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `Landman`
- 基类: `packingDispersionModel`


## 控制方程与关联式
Landman packing dispersion model for industrial separations

## 文献与源码依据
- 类: `Foam`::packingDispersionModels::Landman`
- 源码路径: `applications/modules/incompressibleDriftFlux/packingDispersionModels/Landman/Landman.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`Landman`。
