# rotatingTotalPressure

## 一句话
总压入口/出口条件，由静压与动压关系反算。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`rotatingTotalPressure`
- **典型场**：p / p_rgh
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            rotatingTotalPressure;
    U               U;
    phi             phi;
    rho             rho;
    psi             psi;
    gamma           1.4;
    p0              uniform 1e5;
    origin          (0 0 0);
    axis            (0 0 1);
    omega           100 [rpm];
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `U` | velocity field name | no | U |
| `phi` | flux field name | no | phi |
| `rho` | density field name | no | none |
| `psi` | compressibility field name | no | none |
| `gamma` | ratio of specific heats (Cp/Cv) | yes |  |
| `p0` | static pressure reference | yes |  |
| `origin` | origin of rotation in Cartesian co-ordinates | yes |  |
| `axis` | axis of rotation | yes |  |
| `omega` | angular velocity of the frame | no |  |

## 控制方程与关联式
总压入口/出口条件，由静压与动压关系反算。

类头 `Description` 原文：

> This boundary condition provides a total pressure condition for patches
> in a rotating frame.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/rotatingTotalPressure/rotatingTotalPressureFvPatchScalarField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/rotatingTotalPressure/rotatingTotalPressureFvPatchScalarField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/rotatingTotalPressure/rotatingTotalPressureFvPatchScalarField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/rotatingTotalPressure/rotatingTotalPressureFvPatchScalarField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            rotatingTotalPressure`。

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
