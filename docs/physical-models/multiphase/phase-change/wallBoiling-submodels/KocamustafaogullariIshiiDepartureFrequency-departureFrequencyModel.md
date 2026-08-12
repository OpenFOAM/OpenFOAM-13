# KocamustafaogullariIshiiDepartureFrequency

## 一句话
Correlation for bubble departure frequency.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler `wallBoiling` / `phaseSurfaceBoiling` 子模型
- **族**: 壁面沸腾/departureFrequencyModel（基类 `departureFrequencyModel`）
- **注册名**: `KocamustafaogullariIshiiDepartureFrequency`

## 字典示例
```
// 见源码 Usage；`type` 注册名为 `KocamustafaogullariIshiiDepartureFrequency`
KocamustafaogullariIshiiDepartureFrequency
{
    type    KocamustafaogullariIshiiDepartureFrequency;
    // ...
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `KocamustafaogullariIshiiDepartureFrequency`
- 基类: `departureFrequencyModel`


## 控制方程与关联式
Correlation for bubble departure frequency.

Reference:
```
Kocamustafaogullari, G., & Ishii, M. (1995).
Foundation of the interfacial area transport equation and its closure
relations.
International Journal of Heat and Mass Transfer, 38(3), 481-493.
```

## 文献与源码依据
- 类: `Foam`::wallBoilingModels::departureFrequencyModels::`
- 源码路径: `applications/modules/multiphaseEuler/fvModels/wallBoiling/departureFrequencyModels/KocamustafaogullariIshiiDepartureFrequency/KocamustafaogullariIshiiDepartureFrequency.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`KocamustafaogullariIshiiDepartureFrequency`。
