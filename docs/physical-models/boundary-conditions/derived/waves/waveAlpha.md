# waveAlpha

## 一句话
波浪相关边界（造波/消波或自由面）。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`waveAlpha`
- **典型场**：`alpha`.*`
- **库 / 加载**：需 `libwaves`
- **适用标签**：见库说明；不确定时查求解器 `Make/options`。

## 字典示例
```
<patchName>
{
    type        waveAlpha;
    libs        ("libwaves.so");
    liquid      true;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `phi` | Name of the flux field | no | phi |
| `liquid` | Is the alpha field that of the liquid? | no | true |

## 控制方程与关联式
波浪相关边界（造波/消波或自由面）。

类头 `Description` 原文：

> This boundary condition provides a waveAlpha condition. This sets the phase
> fraction to that specified by a superposition of wave models. All the
> wave modelling parameters are obtained from a centrally registered
> waveSuperposition class.

## 文献与源码依据
- 源码：[`src/waves/derivedFvPatchFields/waveAlpha/waveAlphaFvPatchScalarField.C`](../../../src/waves/derivedFvPatchFields/waveAlpha/waveAlphaFvPatchScalarField.C)
- 头文件：[`src/waves/derivedFvPatchFields/waveAlpha/waveAlphaFvPatchScalarField.H`](../../../src/waves/derivedFvPatchFields/waveAlpha/waveAlphaFvPatchScalarField.H)
- Inventory 备注：wave BCs

## 教程与模板
- [`tutorials/incompressibleVoF/wave3D/0/alpha.water.orig`](../../../tutorials/incompressibleVoF/wave3D/0/alpha.water.orig)
- [`tutorials/incompressibleVoF/wave/0/alpha.water.orig`](../../../tutorials/incompressibleVoF/wave/0/alpha.water.orig)
- [`tutorials/incompressibleVoF/floatingObjectWaves/0/alpha.water.orig`](../../../tutorials/incompressibleVoF/floatingObjectWaves/0/alpha.water.orig)
- [`tutorials/incompressibleVoF/DTCHullWave/0/alpha.water.orig`](../../../tutorials/incompressibleVoF/DTCHullWave/0/alpha.water.orig)
- [`tutorials/incompressibleFluid/waveSubSurface/0/alpha.orig`](../../../tutorials/incompressibleFluid/waveSubSurface/0/alpha.orig)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
