# mappedInternalValue

## 一句话
从另一区域/补丁映射场值或通量。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`mappedInternalValue`
- **典型场**：见源码 / 场量纲匹配
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
摘录 `tutorials/multiRegion/CHT/wallBoiling/0/fluid/U.liquid`：

```
inlet
{
    type            mappedInternalValue;
    average         (1.75175 0 0);
    interpolationScheme cell;
    value           uniform (1.75175 0 0);
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `field` | name of field to be mapped | no | this field name |
| `setAverage` / `average` | 是否/设定平均 | no / if setAverage | — |
| `interpolationScheme` | 插值格式 | yes | — |

## 控制方程与关联式
从另一区域/补丁映射场值或通量。

类头 `Description` 原文：

> This boundary condition maps the values from a internal cells to this
> patch.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/mappedInternalValue/mappedInternalValueFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/mappedInternalValue/mappedInternalValueFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/mappedInternalValue/mappedInternalValueFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/mappedInternalValue/mappedInternalValueFvPatchField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/multiRegion/CHT/wallBoiling/0/fluid/epsilon.gas`](../../../tutorials/multiRegion/CHT/wallBoiling/0/fluid/epsilon.gas)
- [`tutorials/multiRegion/CHT/wallBoiling/0/fluid/epsilon.liquid`](../../../tutorials/multiRegion/CHT/wallBoiling/0/fluid/epsilon.liquid)
- [`tutorials/multiRegion/CHT/wallBoiling/0/fluid/k.gas`](../../../tutorials/multiRegion/CHT/wallBoiling/0/fluid/k.gas)
- [`tutorials/multiRegion/CHT/wallBoiling/0/fluid/k.liquid`](../../../tutorials/multiRegion/CHT/wallBoiling/0/fluid/k.liquid)
- [`tutorials/multiRegion/CHT/wallBoiling/0/fluid/omega.gas`](../../../tutorials/multiRegion/CHT/wallBoiling/0/fluid/omega.gas)
- [`tutorials/multiRegion/CHT/wallBoiling/0/fluid/omega.liquid`](../../../tutorials/multiRegion/CHT/wallBoiling/0/fluid/omega.liquid)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
