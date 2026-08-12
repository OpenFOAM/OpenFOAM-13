# pressure

## 一句话
压力相关边界条件。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`pressure`
- **典型场**：p / p_rgh
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            pressure;
    p               uniform 0;
    value           uniform 0; // optional initial value
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `p` | static pressure | yes |  |

## 控制方程与关联式
压力相关边界条件。

类头 `Description` 原文：

> Static pressure boundary condition
> 
> Used as the base-class for static pressure boundary conditions force
> alternative pressure variables, e.g. p_rgh.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/pressure/pressureFvPatchScalarField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/pressure/pressureFvPatchScalarField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/pressure/pressureFvPatchScalarField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/pressure/pressureFvPatchScalarField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`etc/caseDicts/functions/pressure/pressure.cfg`](../../../etc/caseDicts/functions/pressure/pressure.cfg)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
