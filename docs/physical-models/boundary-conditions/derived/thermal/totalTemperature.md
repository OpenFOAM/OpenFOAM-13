# totalTemperature

## 一句话
温度相关边界条件。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`totalTemperature`
- **典型场**：`T`
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例

摘自 `tutorials/shockFluid/LadenburgJet60psi/0/T`：

```cpp
freestream
{
    type            totalTemperature;
    gamma           1.4;           // [-] Cp/Cv（必填）
    T0              uniform 297;   // [K] 总温
    // 可选: U phi psi（默认 U / phi / psi）
    value           uniform 297;   // [K]
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `U` | Velocity field name | no | U |
| `phi` | Flux field name | no | phi |
| `psi` | Compressibility field name | no | psi |
| `gamma` | ratio of specific heats (Cp/Cv) | yes |  |
| `T0` | reference temperature | yes |  |

## 控制方程与关联式
温度相关边界条件。

类头 `Description` 原文：

> This boundary condition provides a total temperature condition.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/totalTemperature/totalTemperatureFvPatchScalarField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/totalTemperature/totalTemperatureFvPatchScalarField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/totalTemperature/totalTemperatureFvPatchScalarField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/totalTemperature/totalTemperatureFvPatchScalarField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/shockFluid/LadenburgJet60psi/0/T`](../../../tutorials/shockFluid/LadenburgJet60psi/0/T)
- [`tutorials/shockFluid/LadenburgJet60psi/0.orig/T`](../../../tutorials/shockFluid/LadenburgJet60psi/0.orig/T)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
