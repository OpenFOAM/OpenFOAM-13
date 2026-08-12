# kEpsilonLopesdaCosta

## 一句话

Lopes da Costa 修正 k-ε（植被等）

## 适用条件（求解器 / 场 / 前提）

动量输运 RAS 模型；需 atmosphericModels 库

## 字典示例

```c++
// constant/fvModels 或相应字典
kEpsilonLopesdaCosta1
{
    type    kEpsilonLopesdaCosta;
    // 其余参数见源码头文件 Usage
}

```

## 参数表

| 参数 | 含义 | 量纲 |
|------|------|------|
| （见源码 Usage） | 以头文件为准 | — |

## 控制方程与关联式

摘自源码头文件 `Description`（原文）：

> Variant of the standard k-epsilon turbulence model with additional source
> terms to handle the changes in turbulence in porous regions represented by
> the powerLawLopesdaCosta porosity model.
>
> Reference:
>     >     Costa, J. C. P. L. D. (2007).
>     >     Atmospheric flow over forested and non-forested complex terrain.
>     > 
>
> The default model coefficients are
>     >     kEpsilonLopesdaCostaCoeffs
>     >     {
>     >         Cmu         0.09;
>     >         C1          1.44;
>     >         C2          1.92;
>     >         sigmak      1.0;
>     >         sigmaEps    1.3;
>     >     }
>     > 

## 文献与源码依据

- 源码：[`src/atmosphericModels/kEpsilonLopesdaCosta/kEpsilonLopesdaCosta.H`](../../../../src/atmosphericModels/kEpsilonLopesdaCosta/kEpsilonLopesdaCosta.H)
- 实现：同目录 `.C`

## 教程与模板

- 大气/城市冠层相关 tutorials；BC 细目 Phase 2

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
