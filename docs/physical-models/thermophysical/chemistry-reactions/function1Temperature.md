# `function1Temperature`

## 一句话

Function1 饱和温度

## 适用条件（求解器 / 场 / 前提）

- 类别：`saturationModels`
- 适用: `multicomponentFluid` / `XiFluid` / 相变饱和模型相关求解器（见矩阵）

## 字典示例



> （由源码构造函数推断，无官方教程实例）

```c++
// saturationPressureModel / saturationTemperatureModel
type function1Temperature;
// 无额外入口或见父类
```

## 参数表

见源码头文件。

## 控制方程与关联式

Saturation vapour temperature in terms of the vapour pressure (in Pa). The
saturation temperature in Kelvins is specified as a Foam::Function1 type,
to enable use of, e.g. constant, polynomial, table values.

Examples:

```
type function1;
function polynomial
(
308.0422
0.0015096
-1.61589e-8
1.114106e-13
-4.52216e-19
1.05192e-24
-1.2953e-30
6.5365e-37
);
```

```
type function1;
function
{
type                table;
file                "filename.csv";
format              csv;
nHeaderLine         1;
columns             (0 1);
separator           ",";
mergeSeparators     no;
outOfBounds         clamp;
interpolationScheme linear;
}
```

## 文献与源码依据

- [`src/thermophysicalModels/saturationModels/function1Temperature/function1Temperature.H`](../../../src/thermophysicalModels/saturationModels/function1Temperature/function1Temperature.H)

## 教程与模板

- `tutorials/multicomponentFluid/**`、`tutorials/XiFluid/**`、相变教程

## 注意事项

- Phase 4 将补充燃烧机理与反应速率全谱；此处给出物性/化学支撑模型。
