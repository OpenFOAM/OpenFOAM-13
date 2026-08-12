# DarcyForchheimer

## 一句话

Darcy–Forchheimer 孔隙阻力

## 适用条件（求解器 / 场 / 前提）

经 porosityForce / interRegionPorosityForce 选用

## 字典示例



```c++
// `tutorials/compressibleVoF/angledDuct/constant/fvModels`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

porosity1
{
    type            porosityForce;

    porosityForceCoeffs
    {
        cellZone        porosity;

        type            DarcyForchheimer;

        d   (2e8 -1000 -1000);
        f   (0 0 0);

        coordinateSystem
        {
            type    cartesian;
            origin  (0 0 0);
            coordinateRotation
            {
                type    axesRotation;
                e1  (0.70710678 0.70710678 0);
                e2  (0 0 1);
            }
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

> Darcy-Forchheimer law porosity model, given by:
>
>     $$
>         S = - (\mu d + \frac{\rho |U|}{2} f) U
>     $$
>
> where
> 
>     d        | Darcy coefficient [1/m^2]
>     f        | Forchheimer coefficient [1/m]
> 
>
> Since negative Darcy/Forchheimer parameters are invalid, they can be used
> to specify a multiplier (of the max component).
>
> The orientation of the porous region is defined with the same notation as
> a co-ordinate system, but only a Cartesian co-ordinate system is valid.

## 文献与源码依据

- 源码：[`src/finiteVolume/cfdTools/general/porosityModel/DarcyForchheimer/DarcyForchheimer.H`](../../../../src/finiteVolume/cfdTools/general/porosityModel/DarcyForchheimer/DarcyForchheimer.H)
- 实现：同目录 `.C`

## 教程与模板

- `etc/caseDicts/fvModels/porosity/porousZone`（含 DarcyForchheimer / fixedCoeff 示例）

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
