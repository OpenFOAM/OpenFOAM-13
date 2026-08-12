# atmBoundaryLayerInletK

## 一句话

ABL 入口 k

## 适用条件（求解器 / 场 / 前提）

k 边界

## 字典示例

```c++
// constant/fvModels 或相应字典
atmBoundaryLayerInletK1
{
    type    atmBoundaryLayerInletK;
    // 其余参数见源码头文件 Usage
}

```

## 参数表

| 参数 | 含义 | 量纲 |
|------|------|------|
| （见源码 Usage） | 以头文件为准 | — |

## 控制方程与关联式

摘自源码头文件 `Description`（原文）：

> This boundary condition specifies an inlet value for the turbulence
> kinetic energy, $k$, appropriate for atmospheric boundary layers.
>
> See Foam::atmBoundaryLayer for details.
>
> Example of the boundary condition specification:
>     > ground
>     > {
>     >     type            atmBoundaryLayerInletK;
>     >     flowDir         (1 0 0);
>     >     zDir            (0 0 1);
>     >     Uref            10.0;
>     >     Zref            20.0;
>     >     z0              uniform 0.1;
>     >     zGround         uniform 0.0;
>     > }
>     > 

## 文献与源码依据

- 源码：[`src/atmosphericModels/derivedFvPatchFields/atmBoundaryLayerInletK/atmBoundaryLayerInletKFvPatchScalarField.H`](../../../../src/atmosphericModels/derivedFvPatchFields/atmBoundaryLayerInletK/atmBoundaryLayerInletKFvPatchScalarField.H)
- 实现：同目录 `.C`

## 教程与模板

- 大气/城市冠层相关 tutorials；BC 细目 Phase 2

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
