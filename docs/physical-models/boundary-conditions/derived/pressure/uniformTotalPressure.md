# uniformTotalPressure

## 一句话
总压入口/出口条件，由静压与动压关系反算。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`uniformTotalPressure`
- **典型场**：p / p_rgh
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            uniformTotalPressure;
    p0              1e5;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `U` | Velocity field name | no | U |
| `phi` | Flux field name | no | phi |
| `rho` | Density field name | no | rho |
| `psi` | Compressibility field name | no | none |
| `gamma` | (Cp/Cv) | no | 1 |
| `p0` | Total pressure as a function of time | yes |  |

## 控制方程与关联式
总压入口/出口条件，由静压与动压关系反算。

类头 `Description` 原文：

> This boundary condition provides a time-varying form of the uniform total
> pressure boundary condition Foam::totalPressureFvPatchField.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/uniformTotalPressure/uniformTotalPressureFvPatchScalarField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/uniformTotalPressure/uniformTotalPressureFvPatchScalarField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/uniformTotalPressure/uniformTotalPressureFvPatchScalarField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/uniformTotalPressure/uniformTotalPressureFvPatchScalarField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/XiFluid/engine2Valve2D/0/p`](../../../tutorials/XiFluid/engine2Valve2D/0/p)
- [`tutorials/multiRegion/CHT/engine2Valve2D/0/fluid/p`](../../../tutorials/multiRegion/CHT/engine2Valve2D/0/fluid/p)
- [`tutorials/incompressibleFluid/TJunctionFan/0/p.orig`](../../../tutorials/incompressibleFluid/TJunctionFan/0/p.orig)
- [`tutorials/incompressibleFluid/TJunction/0/p`](../../../tutorials/incompressibleFluid/TJunction/0/p)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
