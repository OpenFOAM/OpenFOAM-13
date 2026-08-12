# surfaceNormalFixedValue

## 一句话
给定固定边界值（Dirichlet）。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`surfaceNormalFixedValue`
- **典型场**：见源码 / 场量纲匹配
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            surfaceNormalFixedValue;
    refValue        uniform -10;           // 10 INTO the domain
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `refValue` | reference value | yes |  |

## 控制方程与关联式
给定固定边界值（Dirichlet）。

类头 `Description` 原文：

> Surface-normal fixed value vector boundary condition
> 
> in which the vector field is obtained by scaling the patch normals
> by the scalar field provided.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/surfaceNormalFixedValue/surfaceNormalFixedValueFvPatchVectorField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/surfaceNormalFixedValue/surfaceNormalFixedValueFvPatchVectorField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/surfaceNormalFixedValue/surfaceNormalFixedValueFvPatchVectorField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/surfaceNormalFixedValue/surfaceNormalFixedValueFvPatchVectorField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            surfaceNormalFixedValue`。

## 注意事项
- Sign conventions:   - the value is positive for outward-pointing vectors
