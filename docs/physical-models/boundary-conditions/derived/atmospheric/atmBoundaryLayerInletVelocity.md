# atmBoundaryLayerInletVelocity

## 一句话
大气边界层入口剖面。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`atmBoundaryLayerInletVelocity`
- **典型场**：`U`
- **库 / 加载**：需 `libatmosphericModels`
- **适用标签**：见库说明；不确定时查求解器 `Make/options`。

## 字典示例
摘录 `tutorials/incompressibleFluid/turbineSiting`（`0/U` + `0/include/ABLConditions`）：

```
inlet
{
    type            atmBoundaryLayerInletVelocity;
    #include        "include/ABLConditions"
    // 展开后等价于：
    // flowDir  (1 0 0);
    // zDir     (0 0 1);
    // Uref     10.0;
    // Zref     20;
    // z0       uniform 0.1;
    // zGround  uniform 935.0;
}
```

头文件 Usage 示例（平地）：

```
ground
{
    type            atmBoundaryLayerInletVelocity;
    flowDir         (1 0 0);
    zDir            (0 0 1);
    Uref            10.0;
    Zref            20.0;
    z0              uniform 0.1;
    zGround         uniform 0.0;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `flowDir` | 流动方向 | yes | — |
| `zDir` | 竖直方向 | yes | — |
| `Uref` | 参考风速 | yes | — |
| `Zref` | 参考高度 | yes | — |
| `z0` | 粗糙长度场 | yes | — |
| `zGround` | 地面高度场 | yes | — |
| `phi` | 通量场名 | no | `"phi"` |

## 控制方程与关联式
大气边界层入口剖面。

类头 `Description` 原文：

> This boundary condition specifies a velocity inlet profile appropriate
> for atmospheric boundary layers (ABL).
> 
> See Foam::atmBoundaryLayer for details.
> 
> Example of the boundary condition specification:
> 
> ground
> {
>     type            atmBoundaryLayerInletVelocity;
>     flowDir         (1 0 0);
>     zDir            (0 0 1);
>     Uref            10.0;
>     Zref            20.0;
>     z0              uniform 0.1;
>     zGround         uniform 0.0;
> }
> 

## 文献与源码依据
- 源码：[`src/atmosphericModels/derivedFvPatchFields/atmBoundaryLayerInletVelocity/atmBoundaryLayerInletVelocityFvPatchVectorField.C`](../../../src/atmosphericModels/derivedFvPatchFields/atmBoundaryLayerInletVelocity/atmBoundaryLayerInletVelocityFvPatchVectorField.C)
- 头文件：[`src/atmosphericModels/derivedFvPatchFields/atmBoundaryLayerInletVelocity/atmBoundaryLayerInletVelocityFvPatchVectorField.H`](../../../src/atmosphericModels/derivedFvPatchFields/atmBoundaryLayerInletVelocity/atmBoundaryLayerInletVelocityFvPatchVectorField.H)
- Inventory 备注：atmospheric BCs

## 教程与模板
- [`tutorials/incompressibleFluid/turbineSiting/0/U`](../../../tutorials/incompressibleFluid/turbineSiting/0/U)
- [`tutorials/fluid/stackPlume/0/U.orig`](../../../tutorials/fluid/stackPlume/0/U.orig)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
