# powerLawLopesdaCosta

## 一句话

Lopes da Costa 幂律（大气植被等）

## 适用条件（求解器 / 场 / 前提）

适用: 大气案例；porosityForce + atmosphericModels

## 字典示例

```c++
// 嵌在 porosityForceCoeffs 内
type           powerLawLopesdaCosta;
cellZone       <cellZoneName>;
powerLawLopesdaCostaCoeffs
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

> Variant of the power law porosity model with spatially varying
> drag coefficient
>
> given by:
>
>     $$
>         S = -\rho C_d A_v |U|^{(C_1 - 1)} U
>     $$
>
> where
> 
>     A_v    | Porosity surface area per unit volume
>     C_d    | Model linear coefficient
>     C_1    | Model exponent coefficient
> 
>
> Reference:
>     >     Costa, J. C. P. L. D. (2007).
>     >     Atmospheric flow over forested and non-forested complex terrain.
>     > 

## 文献与源码依据

- 源码：[`src/atmosphericModels/porosityModels/powerLawLopesdaCosta/powerLawLopesdaCosta.H`](../../../../src/atmosphericModels/porosityModels/powerLawLopesdaCosta/powerLawLopesdaCosta.H)
- 实现：同目录 `.C`

## 教程与模板

- `etc/caseDicts/fvModels/porosity/porousZone`（含 DarcyForchheimer / fixedCoeff 示例）

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
