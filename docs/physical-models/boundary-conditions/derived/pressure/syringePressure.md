# syringePressure

## 一句话
压力相关边界条件。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`syringePressure`
- **典型场**：p / p_rgh
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
inlet
{
    type            syringePressure;
    Ap              1.388e-6;  // [m^2] 活塞面积
    Sp              0.01;      // [m/s] 活塞速度
    VsI             1.388e-8;  // [m^3] 初始容积
    tas             0.001;     // [s] 加速开始
    tae             0.002;     // [s] 加速结束
    tds             0.005;     // [s] 减速开始
    tde             0.006;     // [s] 减速结束
    psI             1e5;       // [Pa] 初始压力
    psi             1e-5;      // [1/Pa] 压缩率
    ams             0;         // [kg] 初始质量
    // phi           phi;      // 可选通量场名
    value           uniform 1e5;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `Ap` | syringe piston area [m^2] | yes |  |
| `Sp` | syringe piston speed [m/s] | yes |  |
| `VsI` | initial syringe volume [m^3] | yes |  |
| `tas` | start of piston acceleration [s] | yes |  |
| `tae` | end of piston acceleration [s] | yes |  |
| `tds` | start of piston deceleration [s] | yes |  |
| `tde` | end of piston deceleration [s] | yes |  |
| `psI` | initial syringe pressure [Pa] | yes |  |
| `psi` | gas compressibility [m^2/s^2] | yes |  |
| `ams` | added (or removed) gas mass [kg] | yes |  |

## 控制方程与关联式
压力相关边界条件。

类头 `Description` 原文：

> This boundary condition provides a pressure condition, obtained from a
> zero-D model of the cylinder of a syringe.
> 
> The syringe cylinder is defined by its initial volume, piston area and
> velocity profile specified by regions of constant acceleration, speed
> and deceleration.  The gas in the cylinder is described by its initial
> pressure and compressibility which is assumed constant, i.e. isothermal
> expansion/compression.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/syringePressure/syringePressureFvPatchScalarField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/syringePressure/syringePressureFvPatchScalarField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/syringePressure/syringePressureFvPatchScalarField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/syringePressure/syringePressureFvPatchScalarField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            syringePressure`。

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
