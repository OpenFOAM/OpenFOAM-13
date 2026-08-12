# variableHeightFlowRateInletVelocity

## 一句话
按指定质量/体积流量或平均速度构造入口速度剖面。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`variableHeightFlowRateInletVelocity`
- **典型场**：`U`, `alpha`.*`
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            variableHeightFlowRateInletVelocity;
    flowRate        0.2;
    alpha           alpha.water;
    value           uniform (0 0 0); // placeholder
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `flowRate` | volumetric flow rate [m^3/s] | yes |  |
| `alpha` | phase-fraction field | yes |  |

## 控制方程与关联式
按指定质量/体积流量或平均速度构造入口速度剖面。

类头 `Description` 原文：

> This boundary condition provides a velocity boundary condition for
> multiphase flow based on a user-specified volumetric flow rate.
> 
> The flow rate is made proportional to the phase fraction alpha at each
> face of the patch and alpha is ensured to be bound between 0 and 1.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/variableHeightFlowRateInletVelocity/variableHeightFlowRateInletVelocityFvPatchVectorField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/variableHeightFlowRateInletVelocity/variableHeightFlowRateInletVelocityFvPatchVectorField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/variableHeightFlowRateInletVelocity/variableHeightFlowRateInletVelocityFvPatchVectorField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/variableHeightFlowRateInletVelocity/variableHeightFlowRateInletVelocityFvPatchVectorField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/incompressibleVoF/weirOverflow/0/U`](../../../tutorials/incompressibleVoF/weirOverflow/0/U)
- [`tutorials/incompressibleVoF/parshallFlume/0/U`](../../../tutorials/incompressibleVoF/parshallFlume/0/U)

## 注意事项
- - the value is positive into the domain   - may not work correctly for transonic inlets   - strange behaviour with potentialFoam since the momentum equation is     not solved
