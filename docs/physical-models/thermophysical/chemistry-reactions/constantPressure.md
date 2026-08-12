# `constantPressure`

## 一句话

常饱和压力 $p_\mathrm{sat}=\mathrm{const}$

## 适用条件（求解器 / 场 / 前提）

- 注册：`saturationPressureModel`
- 用于只需固定饱和压力的相变/界面组成场合

## 字典示例

> （由源码构造函数推断，无官方教程实例）

```c++
saturationPressureModel
{
    type    constantPressure;
    value   101325;   // [Pa]
}
```

## 参数表

| 参数 | 必需 | 量纲 | 说明 |
|------|------|------|------|
| `value` | 是 | Pa | 常数 $p_\mathrm{sat}$ |

## 控制方程与关联式

Constant saturation pressure model：与温度无关。

## 文献与源码依据

- [`src/thermophysicalModels/saturationModels/constantPressure/constantPressure.C`](../../../../src/thermophysicalModels/saturationModels/constantPressure/constantPressure.C)

## 教程与模板

- 多见于相变 fvModel 子字典；字面命中因案例而异

## 注意事项

- 只有 `value`；需要 $p_\mathrm{sat}(T)$ 时用 [`Antoine`](Antoine.md) / [`ArdenBuck`](ArdenBuck.md)。
