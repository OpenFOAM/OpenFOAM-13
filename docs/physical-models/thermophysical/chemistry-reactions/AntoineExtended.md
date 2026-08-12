# `AntoineExtended`

## 一句话

扩展 Antoine 饱和压力关联

## 适用条件（求解器 / 场 / 前提）

- 仅注册为 `saturationPressureModel`（无对称的温度模型注册）
- 需要比经典 Antoine 更宽温区的 $p_\mathrm{sat}(T)$

## 字典示例

> （由源码构造函数推断，无官方教程实例）

```c++
saturationPressureModel
{
    type    AntoineExtended;

    // pSat = 1[Pa]*T^D * exp(A + B/(C+T) + E*T^F)
    A    <A>;   // dimless
    B    <B>;   // dimTemperature [K]
    C    <C>;   // dimTemperature [K]
    D    <D>;   // dimless（T 的幂）
    F    <F>;   // dimless
    E    <E>;   // 量纲 dimless/K^F（依赖 F）
}
```

构造函数读取顺序（`AntoineExtended.C`）：`A,B,C,D,F`，再读 `E`（量纲依赖已读入的 `F`）。

## 参数表

| 参数 | 必需 | 量纲 | 说明 |
|------|------|------|------|
| `A` | 是 | 无量纲 | 指数主常数 |
| `B` | 是 | K | Antoine $B$ |
| `C` | 是 | K | Antoine $C$ |
| `D` | 是 | 无量纲 | 前因子 $T^D$ |
| `E` | 是 | $\mathrm{K}^{-F}$ | 额外指数项系数 |
| `F` | 是 | 无量纲 | $T^F$ 指数 |

## 控制方程与关联式

$$
p_\mathrm{sat}= (1\,\mathrm{Pa})\, T^{D}\exp\bigl(A + B/(C+T) + E\,T^{F}\bigr)
$$

$$
\ln(p_\mathrm{sat}/1\,\mathrm{Pa})=A+B/(C+T)+D\ln(T/1\,\mathrm{K})+E\,T^{F}
$$

## 文献与源码依据

- [`src/thermophysicalModels/saturationModels/AntoineExtended/AntoineExtended.C`](../../../../src/thermophysicalModels/saturationModels/AntoineExtended/AntoineExtended.C)

## 教程与模板

- 无官方 tutorials 字面实例；系数取自物性手册时须匹配实现量纲

## 注意事项

- 必须先给出 `F` 再隐含确定 `E` 的量纲；字典中两者都要写。
- 只需 $T_\mathrm{sat}(p)$ 时优先经典 [`Antoine`](Antoine.md)（同时注册温度模型）。
