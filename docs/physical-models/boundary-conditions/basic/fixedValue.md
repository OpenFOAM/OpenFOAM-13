# fixedValue

## 一句话
给定固定边界值（Dirichlet）。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`fixedValue`
- **典型场**：任意场（模板）
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            fixedValue;
    value           uniform 0;  // Example for scalar field usage
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `value` | Patch face values | yes |  |

## 控制方程与关联式
给定固定边界值（Dirichlet）。

类头 `Description` 原文：

> This boundary condition supplies a fixed value constraint, and is the base
> class for a number of other boundary conditions.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/basic/fixedValue/fixedValueFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/basic/fixedValue/fixedValueFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/basic/fixedValue/fixedValueFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/basic/fixedValue/fixedValueFvPatchField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (basic dir)

## 教程与模板
- [`tutorials/XiFluid/kivaTest/-180/T`](../../../tutorials/XiFluid/kivaTest/-180/T)
- [`tutorials/XiFluid/kivaTest/-180/Tu`](../../../tutorials/XiFluid/kivaTest/-180/Tu)
- [`tutorials/XiFluid/engine2Valve2D/0/T`](../../../tutorials/XiFluid/engine2Valve2D/0/T)
- [`tutorials/XiFluid/engine2Valve2D/0/Tu`](../../../tutorials/XiFluid/engine2Valve2D/0/Tu)
- [`tutorials/XiFluid/1D/0/b.orig`](../../../tutorials/XiFluid/1D/0/b.orig)
- [`tutorials/XiFluid/1D/0/epsilon`](../../../tutorials/XiFluid/1D/0/epsilon)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
