# DeClercq

## 一句话
De Clercq packing dispersion model for waste water sludge

## 适用条件（求解器 / 场 / 前提）
- 适用: incompressibleDriftFlux
- **族**: 堆积弥散（基类 `packingDispersionModel`）
- **注册名**: `DeClercq`

## 字典示例
```
packingDispersionModel DeClercq;

DeClercqCoeffs
{
sigma0          8.022e-4;
beta            2.3429e-3;
alphaGel        4.5857e-3;
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `DeClercq`
- 基类: `packingDispersionModel`


## 控制方程与关联式
De Clercq packing dispersion model for waste water sludge

## 文献与源码依据
- 类: `Foam`::packingDispersionModels::DeClercq`
- 源码路径: `applications/modules/incompressibleDriftFlux/packingDispersionModels/DeClercq/DeClercq.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`DeClercq`。
