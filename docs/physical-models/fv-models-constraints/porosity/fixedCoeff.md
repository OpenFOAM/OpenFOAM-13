# fixedCoeff

## 一句话

固定系数孔隙阻力

## 适用条件（求解器 / 场 / 前提）

经 porosityForce 选用

## 字典示例



```c++
// `tutorials/fluid/angledDuctExplicitFixedCoeff/constant/fvModels`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

porosity
{
    type            porosityForce;

    porosityForceCoeffs
    {
        cellZone        porosity;

        type            fixedCoeff;

        fixedCoeffCoeffs
        {
            alpha       (500 -1000 -1000);
            beta        (0 0 0);
            rhoRef      1;

            coordinateSystem
            {
                type    cartesian;
                origin  (0 0 0);
                coordinateRotation
                {
                    type    axesRotation;
                    e1      (0.70710678 0.70710678 0);
                    e2      (0 0 1);
                }
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

> Fixed coefficient form of porosity model
>
>     $$
>         S = - \rho_ref (\alpha + \beta |U|) U
>     $$
>
> In the case of compressible flow, a value for the reference density is
> required

## 文献与源码依据

- 源码：[`src/finiteVolume/cfdTools/general/porosityModel/fixedCoeff/fixedCoeff.H`](../../../../src/finiteVolume/cfdTools/general/porosityModel/fixedCoeff/fixedCoeff.H)
- 实现：同目录 `.C`

## 教程与模板

- `etc/caseDicts/fvModels/porosity/porousZone`（含 DarcyForchheimer / fixedCoeff 示例）

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
