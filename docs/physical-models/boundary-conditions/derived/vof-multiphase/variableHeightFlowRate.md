# variableHeightFlowRate

## 一句话
按指定质量/体积流量或平均速度构造入口速度剖面。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`variableHeightFlowRate`
- **典型场**：`alpha`.*`
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            variableHeightFlowRate;
    lowerBound      0.0;
    upperBound      0.9;
    value           uniform 0;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `phi` | flux field name | no | phi |
| `lowerBound` | lower bound for clipping | yes |  |
| `upperBound` | upper bound for clipping | yes |  |

## 控制方程与关联式
按指定质量/体积流量或平均速度构造入口速度剖面。

类头 `Description` 原文：

> This boundary condition provides a phase fraction condition based on the
> local flow conditions, whereby the values are constrained to lay between
> user-specified upper and lower bounds.  The behaviour is described by:
> 
> if alpha > upperBound:
> - apply a fixed value condition, with a uniform level of the upper bound
> 
> if lower bound <= alpha <= upper bound:
> - apply a  zero-gradient condition
> 
> if alpha < lowerBound:
> - apply a fixed value condition, with a uniform level of the lower bound

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/variableHeightFlowRate/variableHeightFlowRateFvPatchField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/variableHeightFlowRate/variableHeightFlowRateFvPatchField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/variableHeightFlowRate/variableHeightFlowRateFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/variableHeightFlowRate/variableHeightFlowRateFvPatchField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/incompressibleVoF/weirOverflow/0/alpha.water.orig`](../../../tutorials/incompressibleVoF/weirOverflow/0/alpha.water.orig)
- [`tutorials/incompressibleVoF/rotatingCube/0/alpha.water.orig`](../../../tutorials/incompressibleVoF/rotatingCube/0/alpha.water.orig)
- [`tutorials/incompressibleVoF/planingHullW3/0/alpha.water.orig`](../../../tutorials/incompressibleVoF/planingHullW3/0/alpha.water.orig)
- [`tutorials/incompressibleVoF/parshallFlume/0/alpha.water.orig`](../../../tutorials/incompressibleVoF/parshallFlume/0/alpha.water.orig)
- [`tutorials/incompressibleVoF/DTCHullWave/0/alpha.water.orig`](../../../tutorials/incompressibleVoF/DTCHullWave/0/alpha.water.orig)
- [`tutorials/incompressibleVoF/DTCHullMoving/0/alpha.water.orig`](../../../tutorials/incompressibleVoF/DTCHullMoving/0/alpha.water.orig)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
