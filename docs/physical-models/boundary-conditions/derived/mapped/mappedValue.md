# mappedValue

## 一句话
从另一区域/补丁映射场值或通量。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`mappedValue`
- **典型场**：见源码 / 场量纲匹配
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
摘录 `tutorials/multiRegion/film/splashPanel/0/fluid/U`：

```
film
{
    type            mappedValue;
    value           $internalField;
}
```

头文件可选平均修正：

```
<patchName>
{
    type            mappedValue;
    field           T;
    average         300;
    value           uniform 300;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `field` | name of field to be mapped | no | this field name |
| `setAverage` | set the average value? | no | yes if average \\ |
| `average` | average value to apply | if setAverage is true |  |

## 控制方程与关联式
从另一区域/补丁映射场值或通量。

类头 `Description` 原文：

> This boundary condition maps the values from a neighbouring patch to this
> patch.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/mappedValue/mappedValueFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/mappedValue/mappedValueFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/mappedValue/mappedValueFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/mappedValue/mappedValueFvPatchField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/multiRegion/film/VoFToFilm/0/VoF/U`](../../../tutorials/multiRegion/film/VoFToFilm/0/VoF/U)
- [`tutorials/multiRegion/film/splashPanel/0/fluid/U`](../../../tutorials/multiRegion/film/splashPanel/0/fluid/U)
- [`tutorials/multiRegion/film/rivuletBox/0/box/U`](../../../tutorials/multiRegion/film/rivuletBox/0/box/U)
- [`tutorials/multiRegion/film/hotBoxes/0/fluid/U`](../../../tutorials/multiRegion/film/hotBoxes/0/fluid/U)
- [`tutorials/multiRegion/film/cylinderVoF/0/VoF/U`](../../../tutorials/multiRegion/film/cylinderVoF/0/VoF/U)
- [`tutorials/multiRegion/film/cylinderDripping/0/fluid/U`](../../../tutorials/multiRegion/film/cylinderDripping/0/fluid/U)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
