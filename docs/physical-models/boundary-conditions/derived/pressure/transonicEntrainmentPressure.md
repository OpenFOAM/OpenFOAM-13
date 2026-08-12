# transonicEntrainmentPressure

## 一句话
压力相关边界条件。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`transonicEntrainmentPressure`
- **典型场**：p / p_rgh
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            transonicEntrainmentPressure;
    gamma           1.4;
    p0              uniform 1e5;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `rho` | Density field name | no | rho |
| `psi` | Compressibility field name | no | psi |
| `gamma` | Heat capacity ratio (cp/Cv) | yes |  |
| `Mb` | Blending Mach No | no | 0.5 |
| `phi` | Flux field name | no | phi |
| `p0` | Reference pressure | yes |  |

## 控制方程与关联式
压力相关边界条件。

类头 `Description` 原文：

> This boundary condition provides an entrainment condition for pressure
> including support for supersonic jets exiting the domain.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/transonicEntrainmentPressure/transonicEntrainmentPressureFvPatchScalarField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/transonicEntrainmentPressure/transonicEntrainmentPressureFvPatchScalarField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/transonicEntrainmentPressure/transonicEntrainmentPressureFvPatchScalarField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/transonicEntrainmentPressure/transonicEntrainmentPressureFvPatchScalarField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            transonicEntrainmentPressure`。

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
