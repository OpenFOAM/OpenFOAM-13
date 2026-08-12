# inletOutletTotalTemperature

## 一句话
按通量方向在入口值与零梯度间切换。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`inletOutletTotalTemperature`
- **典型场**：`T`
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例

```cpp
outlet
{
    type            inletOutletTotalTemperature;
    gamma           1.4;           // [-]
    T0              uniform 300;   // [K] 回流总温
    // 可选: U phi psi
    value           uniform 300;   // [K]
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `U` | velocity field name | no | U |
| `phi` | flux field name | no | phi |
| `psi` | compressibility field name | no | psi |
| `gamma` | heat capacity ration (Cp/Cv) | yes |  |
| `inletValue` | reverse flow (inlet) value | yes |  |
| `T0` | static temperature [K] | yes |  |

## 控制方程与关联式
按通量方向在入口值与零梯度间切换。

类头 `Description` 原文：

> This boundary condition provides an outflow condition for total
> temperature for use with supersonic cases, where a user-specified
> value is applied in the case of reverse flow.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/inletOutletTotalTemperature/inletOutletTotalTemperatureFvPatchScalarField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/inletOutletTotalTemperature/inletOutletTotalTemperatureFvPatchScalarField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/inletOutletTotalTemperature/inletOutletTotalTemperatureFvPatchScalarField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/inletOutletTotalTemperature/inletOutletTotalTemperatureFvPatchScalarField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            inletOutletTotalTemperature`。

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
