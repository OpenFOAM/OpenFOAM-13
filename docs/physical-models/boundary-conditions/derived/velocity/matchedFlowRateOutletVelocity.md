# matchedFlowRateOutletVelocity

## 一句话
按指定质量/体积流量或平均速度构造入口速度剖面。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`matchedFlowRateOutletVelocity`
- **典型场**：`U`
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
outlet
{
    type                matchedFlowRateOutletVelocity;
    inletPatch          inlet;           // 对应入口 patch 名
    volumetric          false;           // true=体积流量匹配；false=质量（默认）
    // rho              rho;             // 质量匹配时密度场名，默认 rho
    value               uniform (0 0 0); // [m/s]
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `inletPatch` | Corresponding inlet patch name | yes |  |
| `volumetric` | Set volumetric or mass flow-rate | no | false |
| `rho` | density field name | no | rho |

## 控制方程与关联式
按指定质量/体积流量或平均速度构造入口速度剖面。

类头 `Description` 原文：

> Velocity outlet boundary condition which corrects the extrapolated velocity
> to match the flow rate of the specified corresponding inlet patch.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/matchedFlowRateOutletVelocity/matchedFlowRateOutletVelocityFvPatchVectorField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/matchedFlowRateOutletVelocity/matchedFlowRateOutletVelocityFvPatchVectorField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/matchedFlowRateOutletVelocity/matchedFlowRateOutletVelocityFvPatchVectorField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/matchedFlowRateOutletVelocity/matchedFlowRateOutletVelocityFvPatchVectorField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            matchedFlowRateOutletVelocity`。

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
