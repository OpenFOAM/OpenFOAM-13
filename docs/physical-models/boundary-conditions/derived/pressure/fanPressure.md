# fanPressure

## 一句话
总压入口/出口条件，由静压与动压关系反算。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`fanPressure`
- **典型场**：p / p_rgh
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
inlet
{
    type            fanPressure;

    fanCurve        table;
    file            "$FOAM_CASE/constant/pressureVsQ";
    format          csv;
    nHeaderLine     1;
    columns         (0 1);
    separator       ",";
    mergeSeparators no;
    outOfBounds     clamp;
    interpolationScheme linear;

    direction       in;
    p0              uniform 0;
    value           uniform 0;
}

outlet
{
    type            fanPressure;

    fanCurve        table;
    file            "$FOAM_CASE/constant/pressureVsQ";
    format          csv;
    nHeaderLine     1;
    columns         (0 1);
    separator       ",";
    mergeSeparators no;
    outOfBounds     clamp;
    interpolationScheme linear;

    direction       out;
    p0              uniform 0;
    value           uniform 0;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `fanCurve` | fan curve function | yes |  |
| `p0` | environmental total pressure | yes |  |

## 控制方程与关联式
总压入口/出口条件，由静压与动压关系反算。

类头 `Description` 原文：

> This boundary condition can be applied to assign either a pressure inlet
> or outlet total pressure condition for a fan.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/fanPressure/fanPressureFvPatchScalarField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/fanPressure/fanPressureFvPatchScalarField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/fanPressure/fanPressureFvPatchScalarField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/fanPressure/fanPressureFvPatchScalarField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            fanPressure`。

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
