# `constantTemperature`

## 一句话

常饱和温度 $T_\mathrm{sat}=\mathrm{const}$

## 适用条件（求解器 / 场 / 前提）

- 注册：`saturationTemperatureModel`
- 用于相变 / 壁面沸腾等只需固定饱和温度的场合

## 字典示例

> （由源码构造函数推断，无官方教程实例）

```c++
saturationTemperatureModel
{
    type    constantTemperature;
    value   373.15;   // [K] 饱和温度
}
```

## 参数表

| 参数 | 必需 | 量纲 | 说明 |
|------|------|------|------|
| `value` | 是 | K | 常数 $T_\mathrm{sat}$ |

$T_\mathrm{sat}'(p)=0$。

## 控制方程与关联式

Constant saturation temperature model：与压力无关。

## 文献与源码依据

- [`src/thermophysicalModels/saturationModels/constantTemperature/constantTemperature.C`](../../../../src/thermophysicalModels/saturationModels/constantTemperature/constantTemperature.C)

## 教程与模板

- 多见于 `wallBoiling` / 相变 fvModel 子字典；仓库字面命中因案例而异

## 注意事项

- 勿与 Antoine 系数混淆；本模型只有 `value`。
