# mappedVelocityFlux

## 一句话
从另一区域/补丁映射场值或通量。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`mappedVelocityFlux`
- **典型场**：`U`
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            mappedVelocityFlux;
    value           uniform (0 0 0);
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `phi` | flux field name | no | phi |

## 控制方程与关联式
从另一区域/补丁映射场值或通量。

类头 `Description` 原文：

> This boundary condition maps the velocity and flux from a neighbouring
> patch to this patch.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/mappedVelocityFlux/mappedVelocityFluxFvPatchField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/mappedVelocityFlux/mappedVelocityFluxFvPatchField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/mappedVelocityFlux/mappedVelocityFluxFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/mappedVelocityFlux/mappedVelocityFluxFvPatchField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            mappedVelocityFlux`。

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
