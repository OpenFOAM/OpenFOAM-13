# pressureInletVelocity

## 一句话
压力相关边界条件。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`pressureInletVelocity`
- **典型场**：`U`, p / p_rgh
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            pressureInletVelocity;
    phi             phi;
    rho             rho;
    value           uniform (0 0 0);
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| | *以下关键字自 `.C` 构造函数字典读取推断，完整语义见源码* | | |
| `phi` | （自构造函数字典读取） | no | "phi" |
| `rho` | （自构造函数字典读取） | no | "rho" |

## 控制方程与关联式
压力相关边界条件。

类头 `Description` 原文：

> This velocity inlet boundary condition is applied to patches where the
> pressure is specified.  The inflow velocity is obtained from the flux with
> a direction normal to the patch faces.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/pressureInletVelocity/pressureInletVelocityFvPatchVectorField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/pressureInletVelocity/pressureInletVelocityFvPatchVectorField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/pressureInletVelocity/pressureInletVelocityFvPatchVectorField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/pressureInletVelocity/pressureInletVelocityFvPatchVectorField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/fluid/helmholtzResonance/0/U`](../../../tutorials/fluid/helmholtzResonance/0/U)

## 注意事项
- If reverse flow is possible or expected use     the pressureInletOutletVelocityFvPatchVectorField condition instead.
