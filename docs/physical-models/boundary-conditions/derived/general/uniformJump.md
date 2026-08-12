# uniformJump

## 一句话
周期/循环配对边界。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`uniformJump`
- **典型场**：见源码 / 场量纲匹配
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            uniformJump;
    patchType       cyclic;
    jumpTable       constant 10;
}
```

```
<patchName>
{
    type            uniformJump;
    patchType       cyclic;
    jumpTable
    {
        type            table;
        values
        (
            (0 0)
            (0.1 10)
            (0.9 10)
            (1 0)
        );
    }
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `patchType` | underlying patch type (should be \c cyclic) | yes |  |
| `jumpTable` | jump value | yes |  |

## 控制方程与关联式
周期/循环配对边界。

类头 `Description` 原文：

> This boundary condition provides a jump condition, using the \c cyclic
> condition as a base. The jump is specified as the difference between the
> neighbour patch and the owner patch value (i.e., neighbour minus owner).
> The jump value is uniform across the patches, and can vary in time.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/uniformJump/uniformJumpFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/uniformJump/uniformJumpFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/uniformJump/uniformJumpFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/uniformJump/uniformJumpFvPatchField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            uniformJump`。

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
