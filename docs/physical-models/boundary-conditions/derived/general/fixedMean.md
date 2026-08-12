# fixedMean

## 一句话
通用派生类边界条件 `fixedMean`。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`fixedMean`
- **典型场**：见源码 / 场量纲匹配
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            fixedMean;
    meanValue       1.0;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `meanValue` | mean value Function1 | yes |  |

## 控制方程与关联式
通用派生类边界条件 `fixedMean`。

类头 `Description` 原文：

> This boundary condition extrapolates field to the patch using the near-cell
> values and adjusts the distribution to match the specified, optionally
> time-varying, mean value.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/fixedMean/fixedMeanFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/fixedMean/fixedMeanFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/fixedMean/fixedMeanFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/fixedMean/fixedMeanFvPatchField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/fluid/helmholtzResonance/0/p`](../../../tutorials/fluid/helmholtzResonance/0/p)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
