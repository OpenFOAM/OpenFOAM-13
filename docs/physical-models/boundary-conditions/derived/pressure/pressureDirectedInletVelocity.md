# pressureDirectedInletVelocity

## 一句话
压力相关边界条件。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`pressureDirectedInletVelocity`
- **典型场**：`U`, p / p_rgh
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            pressureDirectedInletVelocity;
    phi             phi;
    rho             rho;
    inletDirection  uniform (1 0 0);
    value           uniform (0 0 0);
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `phi` | flux field name | no | phi |
| `rho` | density field name | no | rho |
| `inletDirection` | inlet direction per patch face | yes |  |

## 控制方程与关联式
压力相关边界条件。

类头 `Description` 原文：

> This velocity inlet boundary condition is applied to patches where the
> pressure is specified.  The inflow velocity is obtained from the flux with
> the specified inlet direction" direction.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/pressureDirectedInletVelocity/pressureDirectedInletVelocityFvPatchVectorField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/pressureDirectedInletVelocity/pressureDirectedInletVelocityFvPatchVectorField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/pressureDirectedInletVelocity/pressureDirectedInletVelocityFvPatchVectorField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/pressureDirectedInletVelocity/pressureDirectedInletVelocityFvPatchVectorField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            pressureDirectedInletVelocity`。

## 注意事项
- If reverse flow is possible or expected use the     pressureDirectedInletOutletVelocityFvPatchVectorField condition instead.
