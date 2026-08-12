# totalFlowRateAdvectiveDiffusive

## 一句话
按指定质量/体积流量或平均速度构造入口速度剖面。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`totalFlowRateAdvectiveDiffusive`
- **典型场**：见源码 / 场量纲匹配
- **库 / 加载**：需 `libthermophysicalTransportModels`（`fluid`、`multicomponentFluid`、CHT 等）

## 字典示例
```
<patchName>
{
    type            totalFlowRateAdvectiveDiffusive;
    // 其余条目见源码 Usage / 教程
    value           $internalField;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| | *以下关键字自 `.C` 构造函数字典读取推断，完整语义见源码* | | |
| `phi` | （自构造函数字典读取） | no | "phi" |
| `rho` | （自构造函数字典读取） | no | "none" |
| `massFluxFraction` | （自构造函数字典读取） | no | dimless, 1.0 |

## 控制方程与关联式
按指定质量/体积流量或平均速度构造入口速度剖面。

类头 `Description` 原文：

> This BC is used for species inlets. The diffusion and advection fluxes are
> considered to calculate the inlet value for the species
> The massFluxFraction sets the fraction of the flux of each particular
> species.

## 文献与源码依据
- 源码：[`src/ThermophysicalTransportModels/fluid/derivedFvPatchFields/totalFlowRateAdvectiveDiffusive/totalFlowRateAdvectiveDiffusiveFvPatchScalarField.C`](../../../src/ThermophysicalTransportModels/fluid/derivedFvPatchFields/totalFlowRateAdvectiveDiffusive/totalFlowRateAdvectiveDiffusiveFvPatchScalarField.C)
- 头文件：[`src/ThermophysicalTransportModels/fluid/derivedFvPatchFields/totalFlowRateAdvectiveDiffusive/totalFlowRateAdvectiveDiffusiveFvPatchScalarField.H`](../../../src/ThermophysicalTransportModels/fluid/derivedFvPatchFields/totalFlowRateAdvectiveDiffusive/totalFlowRateAdvectiveDiffusiveFvPatchScalarField.H)
- Inventory 备注：thermophysical transport BCs

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            totalFlowRateAdvectiveDiffusive`。

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
