# dynamicPressure

## 一句话
能量/焓场边界（通常由 `T` BC 经 thermo 映射）。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`dynamicPressure`
- **典型场**：p / p_rgh
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            dynamicPressure;
    // 其余条目见源码 Usage / 教程
    value           $internalField;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| | *以下关键字自 `.C` 构造函数字典读取推断，完整语义见源码* | | |
| `rho` | （自构造函数字典读取） | no | "rho" |
| `psi` | （自构造函数字典读取） | no | "none" |
| `gamma` | （自构造函数字典读取） | no | dimless, 1 |

## 控制方程与关联式
能量/焓场边界（通常由 `T` BC 经 thermo 映射）。

类头 `Description` 原文：

> This boundary condition provides a dynamic pressure condition. It subtracts
> a kinetic energy term from a reference pressure to get a value which is
> fixed on the boundary. It forms the base class for the total and
> entrainment pressure conditions.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/dynamicPressure`](../../../src/finiteVolume/fields/fvPatchFields/derived/dynamicPressure)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/dynamicPressure/dynamicPressureFvPatchScalarField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/dynamicPressure/dynamicPressureFvPatchScalarField.H)
- Inventory 备注：core finiteVolume (derived dir)

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            dynamicPressure`。

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
