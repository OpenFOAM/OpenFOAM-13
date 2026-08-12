# semiImplicitSource

## 一句话

半隐式任意场源/汇

## 适用条件（求解器 / 场 / 前提）

适用: 通用；指定场名

## 字典示例



```c++
// `tutorials/incompressibleFluid/planarPoiseuille/constant/fvModels`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

momentumSource
{
    type            semiImplicitSource;

    cellZone        all;

    volumeMode      specific;

    sources
    {
        U
        {
            explicit    (5 0 0);
            implicit    0;
        }
    }
}


// ************************************************************************* //
```

## 参数表

| 参数 | 含义 | 量纲 |
|------|------|------|
| （见源码 Usage） | 以头文件为准 | — |

## 控制方程与关联式

摘自源码头文件 `Description`（原文）：

> Semi-implicit source, described using an input dictionary.  The injection
> rate coefficients are specified as pairs of Su-Sp coefficients, i.e.
>
>     $$
>         S(x) = S_u + S_p x
>     $$
>
> where
> 
>     S(x)    | net source for field 'x'
>     S_u     | explicit source contribution
>     S_p     | linearised implicit contribution
> 
>
> Example tabulated heat source specification for internal energy:
>     > volumeMode      absolute; // specific
>     > sources
>     > {
>     >     e
>     >     {
>     >         explicit table ((0 0) (1.5 $power));
>     >         implicit 0;
>     >     }
>     > }
>     > 
>
> Example coded heat source specification for enthalpy:
>     > volumeMode      absolute; // specific
>     > sources
>     > {
>     >     h
>     >     {
>     >         explicit
>     >         {
>     >             type coded;
>     >             name heatInjection;
>     >             code
>     >             #{
>     >                 // Power amplitude
>     >                 const scalar powerAmplitude = 1000;
>     >
>     >                 // x is the current time
>     >                 return mag(powerAmplitude*sin(x));
>     >             #};
>     >         }
>     >         implicit 0;
>     >     }
>     > }
>     > 
>
> Valid fvModels for the \c volumeMode entry include:
> - absolute: values are given as \<quantity\>
> - specific: values are given as \<quantity\>/m3

## 文献与源码依据

- 源码：[`src/fvModels/general/semiImplicitSource/semiImplicitSource.H`](../../../../src/fvModels/general/semiImplicitSource/semiImplicitSource.H)
- 实现：同目录 `.C`

## 教程与模板

- `etc/caseDicts/fvModels/`
- 例：`tutorials/fluid/angledDuct`（porosity）、`tutorials/incompressibleFluid/rotorDisk`（转子类）

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
