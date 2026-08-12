# PrghPressure

## 一句话
`p_rgh` 压力族模板基类（由具体 `prgh`*` 类型使用）。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`PrghPressure`
- **典型场**：p / p_rgh
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            PrghPressure;
    // 其余条目见源码 Usage / 教程
    value           $internalField;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| | *以下关键字自 `.C` 构造函数字典读取推断，完整语义见源码* | | |
| `rho` | （自构造函数字典读取） | no | "rho" |

## 控制方程与关联式
`p_rgh` 压力族模板基类（由具体 `prgh`*` 类型使用）。

类头 `Description` 原文：

> This boundary condition provides the p_rgh equivalent of a pressure
> boundary condition calculated as:
> 
>     $$
>         p_rgh = p - \rho g (h - hRef)
>     $$
> 
> where
> 
>     p_rgh   | Pseudo hydrostatic pressure [Pa]
>     p       | Static pressure [Pa]
>     h       | Height in the opposite direction to gravity
>     hRef    | Reference height in the opposite direction to gravity
>     \rho    | density
>     g       | acceleration due to gravity [m/s^2]
> \endtable

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/PrghPressure`](../../../src/finiteVolume/fields/fvPatchFields/derived/PrghPressure)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/PrghPressure/PrghPressureFvPatchScalarField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/PrghPressure/PrghPressureFvPatchScalarField.H)
- Inventory 备注：core finiteVolume (derived dir)

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            PrghPressure`。

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
