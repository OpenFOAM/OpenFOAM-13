# `Antoine`

## 一句话

Antoine 饱和压力/温度关联

## 适用条件（求解器 / 场 / 前提）

- 同时注册为 `saturationPressureModel` 与 `saturationTemperatureModel`
- 用于相变 / 壁面沸腾 / 界面组成等需要 $p_\mathrm{sat}(T)$ 或 $T_\mathrm{sat}(p)$ 的模型

## 字典示例

> （由源码构造函数推断，无官方教程实例）

```c++
// 作为 saturationPressureModel 或 saturationTemperatureModel 子字典
saturationTemperatureModel  // 或 saturationPressureModel
{
    type    Antoine;

    // pSat = 1[Pa] * exp(A + B/(C + T))；T 为开尔文；A,B,C 须配套自然对数
    A       11.683;     // [dimless]  — 示例数值仅示意，请按物性表填写
    B       -3816.44;   // [K]
    C       -46.13;     // [K]
}
```

构造函数（`Antoine.C`）必读：`A`（dimless）、`B`（dimTemperature）、`C`（dimTemperature）。

## 参数表

| 参数 | 必需 | 量纲 | 说明 |
|------|------|------|------|
| `A` | 是 | 无量纲 | $\ln(p/\mathrm{1\,Pa})=A+B/(C+T)$ 中的 $A$ |
| `B` | 是 | K | 温度系数 |
| `C` | 是 | K | 温度偏移 |

逆关系：$T_\mathrm{sat}=B/(\ln(p/\mathrm{1\,Pa})-A)-C$。

## 控制方程与关联式

Antoine equation for the vapour pressure（实现使用**自然对数**与开尔文温度，而非常见 $\log_{10}$ 表格形式——填表时须换算）。

## 文献与源码依据

- [`src/thermophysicalModels/saturationModels/Antoine/Antoine.C`](../../../../src/thermophysicalModels/saturationModels/Antoine/Antoine.C)

## 教程与模板

- 仓库 tutorials 中鲜有字面 `type Antoine`；常见于 `wallBoiling` / 相变 fvModel 的饱和子字典

## 注意事项

- 系数必须与 $\ln$、K、Pa 配套；勿直接粘贴 $\log_{10}$/°C 表系数。
- 扩展形式见 [`AntoineExtended`](AntoineExtended.md)。
