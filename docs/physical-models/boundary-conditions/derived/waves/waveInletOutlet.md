# waveInletOutlet

## 一句话
按通量方向在入口值与零梯度间切换。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`waveInletOutlet`
- **典型场**：见源码 / 场量纲匹配
- **库 / 加载**：需 `libwaves`
- **适用标签**：见库说明；不确定时查求解器 `Make/options`。

## 字典示例
```
<patchName>
{
    type        waveInletOutlet;
    libs        ("libwaves.so");
    inletValueAbove 0.01;
    inletValueBelow table ((0 0.01) (10 0.1));
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `phi` | Name of the flux field | no | phi |
| `inletValueAbove` | inlet value above the wave | no | None |
| `inletValueBelow` | inlet value below the wave | no | None |

## 控制方程与关联式
按通量方向在入口值与零梯度间切换。

类头 `Description` 原文：

> This boundary condition provides an inlet-outlet condition with differing
> inlet values on either side of a wave interface. All the wave modelling
> parameters are obtained from a centrally registered waveSuperposition
> class.

## 文献与源码依据
- 源码：[`src/waves/derivedFvPatchFields/waveInletOutlet/waveInletOutletFvPatchFields.C`](../../../src/waves/derivedFvPatchFields/waveInletOutlet/waveInletOutletFvPatchFields.C)
- 头文件：[`src/waves/derivedFvPatchFields/waveInletOutlet/waveInletOutletFvPatchField.H`](../../../src/waves/derivedFvPatchFields/waveInletOutlet/waveInletOutletFvPatchField.H)
- Inventory 备注：wave BCs

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            waveInletOutlet`。

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
