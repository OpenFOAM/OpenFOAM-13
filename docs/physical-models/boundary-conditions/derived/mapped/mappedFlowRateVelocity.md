# mappedFlowRateVelocity

## 一句话
按指定质量/体积流量或平均速度构造入口速度剖面。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`mappedFlowRateVelocity`
- **典型场**：`U`
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            mappedFlowRateVelocity;
    value           uniform (0 0 0);
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `nbrPhi` | name of flux field on neighbour mesh | no | phi |
| `phi` | flux field name | no | phi |
| `rho` | density field name | no | rho |

## 控制方程与关联式
按指定质量/体积流量或平均速度构造入口速度剖面。

类头 `Description` 原文：

> This boundary condition maps the flow rate from a neighbouring patch to
> this patch, then uses it to set a corresponding velocity in a direction
> normal to the patch.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/mappedFlowRateVelocity/mappedFlowRateVelocityFvPatchVectorField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/mappedFlowRateVelocity/mappedFlowRateVelocityFvPatchVectorField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/mappedFlowRateVelocity/mappedFlowRateVelocityFvPatchVectorField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/mappedFlowRateVelocity/mappedFlowRateVelocityFvPatchVectorField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            mappedFlowRateVelocity`。

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
