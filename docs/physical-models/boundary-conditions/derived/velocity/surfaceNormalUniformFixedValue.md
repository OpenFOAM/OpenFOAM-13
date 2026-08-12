# surfaceNormalUniformFixedValue

## 一句话
给定固定边界值（Dirichlet）。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`surfaceNormalUniformFixedValue`
- **典型场**：见源码 / 场量纲匹配
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            surfaceNormalUniformFixedValue;
    uniformValue    constant -0.2;         // 0.2 INTO the domain
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `uniformValue` | uniform value | yes |  |

## 控制方程与关联式
给定固定边界值（Dirichlet）。

类头 `Description` 原文：

> Surface-normal fixed value vector boundary condition
> 
> in which the vector field is obtained by scaling the patch normals
> by the evaluated scalar Function1 provided.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/surfaceNormalUniformFixedValue/surfaceNormalUniformFixedValueFvPatchVectorField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/surfaceNormalUniformFixedValue/surfaceNormalUniformFixedValueFvPatchVectorField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/surfaceNormalUniformFixedValue/surfaceNormalUniformFixedValueFvPatchVectorField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/surfaceNormalUniformFixedValue/surfaceNormalUniformFixedValueFvPatchVectorField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            surfaceNormalUniformFixedValue`。

## 注意事项
- Sign conventions:   - the value is positive for outward-pointing vectors
