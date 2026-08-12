# fanPressureJump

## 一句话
按指定质量/体积流量或平均速度构造入口速度剖面。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`fanPressureJump`
- **典型场**：p / p_rgh
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            fanPressureJump;
    patchType       cyclic;

    fanCurve        table;
    file            "$FOAM_CASE/constant/pressureVsQ";
    format          csv;
    nHeaderLine     1;
    columns         (0 1);
    separator       ",";
    mergeSeparators no;
    outOfBounds     clamp;
    interpolationScheme linear;

    value           uniform 0;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `patchType` | underlying patch type (should be \c cyclic) | yes |  |
| `fanCurve` | fan curve function | yes |  |
| `jumpTable` | jump table function (backward compatibility mode) | no |  |
| `reverse` | reverse jump direction | no | false |
| `phi` | flux field name | no | phi |
| `rho` | density field name | no | rho |

## 控制方程与关联式
按指定质量/体积流量或平均速度构造入口速度剖面。

类头 `Description` 原文：

> This boundary condition provides a fan pressure jump condition, using the
> \c cyclic condition as a base. The jump is specified as a \c Function1,
> which returns the pressure jump as a function of the total volumetric flow
> rate through the patch.
> 
> A backwards-compatibility option is also provided to specify the pressure
> jump as a function of local velocity. In this mode the boundary condition
> serves as a direct replacement for the old fanFvPatchField.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/fanPressureJump/fanPressureJumpFvPatchScalarField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/fanPressureJump/fanPressureJumpFvPatchScalarField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/fanPressureJump/fanPressureJumpFvPatchScalarField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/fanPressureJump/fanPressureJumpFvPatchScalarField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/incompressibleFluid/TJunctionFan/system/createBafflesDict`](../../../tutorials/incompressibleFluid/TJunctionFan/system/createBafflesDict)
- [`tutorials/incompressibleFluid/TJunctionFan/system/createNonConformalCouplesDict`](../../../tutorials/incompressibleFluid/TJunctionFan/system/createNonConformalCouplesDict)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
