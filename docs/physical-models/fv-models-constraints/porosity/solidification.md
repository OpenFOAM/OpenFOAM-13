# solidification

## 一句话

凝固相关孔隙率模型

## 适用条件（求解器 / 场 / 前提）

经 porosityForce / 凝固模型链路

## 字典示例

```c++
// 嵌在 porosityForceCoeffs 内
type           solidification;
cellZone       <cellZoneName>;
solidificationCoeffs
{
    // 见源码 Usage
}

```

## 参数表

| 参数 | 含义 | 量纲 |
|------|------|------|
| （见源码 Usage） | 以头文件为准 | — |

## 控制方程与关联式

摘自源码头文件 `Description`（原文）：

> Simple solidification porosity model
>
> This is a simple approximation to solidification where the solid phase
> is represented as a porous blockage with the drag-coefficient evaluated from
>
>     $$
>         S = - \alpha \rho D(T) U
>     $$
>
> where
> 
>     \alpha  | Optional phase-fraction of solidifying phase
>     D(T)    | User-defined drag-coefficient as function of temperature
> 
>
> Note that the latent heat of solidification is not included and the
> temperature is unchanged by the modelled change of phase.
>
> Example of the solidification model specification:
>     >     type            solidification;
>     >
>     >     solidificationCoeffs
>     >     {
>     >         // Solidify between 330K and 330.5K
>     >         D table
>     >         (
>     >             (330.0     10000) // Solid below 330K
>     >             (330.5     0)     // Liquid above 330.5K
>     >         );
>     >
>     >         // Optional phase-fraction of solidifying phase
>     >         alpha alpha.liquid;
>     >
>     >         // Solidification porosity is isotropic
>     >         // use the global coordinate system
>     >         coordinateSystem
>     >         {
>     >             type    cartesian;
>     >             origin  (0 0 0);
>     >             coordinateRotation
>     >             {
>     >                 type    axesRotation;
>     >                 e1      (1 0 0);
>     >                 e2      (0 1 0);
>     >             }
>     >         }
>     >     }
>     > 

## 文献与源码依据

- 源码：[`src/finiteVolume/cfdTools/general/porosityModel/solidification/solidification.H`](../../../../src/finiteVolume/cfdTools/general/porosityModel/solidification/solidification.H)
- 实现：同目录 `.C`

## 教程与模板

- `etc/caseDicts/fvModels/porosity/porousZone`（含 DarcyForchheimer / fixedCoeff 示例）

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
