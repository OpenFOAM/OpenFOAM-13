# Usher

## 一句话
Usher packing dispersion model for sewage and mineral slurries,

## 适用条件（求解器 / 场 / 前提）
- 适用: incompressibleDriftFlux
- **族**: 堆积弥散（基类 `packingDispersionModel`）
- **注册名**: `Usher`

## 字典示例
```
packingDispersionModel Usher;

UsherCoeffs
{
alphaGel        0.1;
alphap          0.8;
alphacp         0.8;
alphag          0;
alphaMax        1;
b1              2e-3;
sigma01         3.18663;
n1              11;
b2              1;
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `Usher`
- 基类: `packingDispersionModel`


## 控制方程与关联式
Usher packing dispersion model for sewage and mineral slurries,
both cetrifugated and filtered.

Reference:
```
Usher, S. P., Studer, L. J., Wall, R. C., & Scales, P. J. (2013).
Characterisation of dewaterability from equilibrium
and transient centrifugation test data.
Chemical Engineering Science, 93, 277-291.
```

## 文献与源码依据
- 类: `Foam`::packingDispersionModels::Usher`
- 源码路径: `applications/modules/incompressibleDriftFlux/packingDispersionModels/Usher/Usher.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`Usher`。
