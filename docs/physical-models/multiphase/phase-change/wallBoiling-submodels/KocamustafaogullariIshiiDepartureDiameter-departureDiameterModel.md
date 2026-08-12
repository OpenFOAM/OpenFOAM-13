# KocamustafaogullariIshiiDepartureDiameter

## 一句话
A correlation for bubble departure diameter.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler `wallBoiling` / `phaseSurfaceBoiling` 子模型
- **族**: 壁面沸腾/departureDiameterModel（基类 `departureDiameterModel`）
- **注册名**: `KocamustafaogullariIshiiDepartureDiameter`

## 字典示例
```
// 见源码 Usage；`type` 注册名为 `KocamustafaogullariIshiiDepartureDiameter`
KocamustafaogullariIshiiDepartureDiameter
{
    type    KocamustafaogullariIshiiDepartureDiameter;
    // ...
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `KocamustafaogullariIshiiDepartureDiameter`
- 基类: `departureDiameterModel`


## 控制方程与关联式
A correlation for bubble departure diameter.

Requires model parameter 'phi': contact angle in degrees.

Reference:
```
Kocamustafaogullari, G., & Ishii, M. (1983).
Interfacial area and nucleation site density in boiling systems.
International Journal of Heat and Mass Transfer, 26(9), 1377-1387.
```

## 文献与源码依据
- 类: `Foam`::wallBoilingModels::departureDiameterModels::`
- 源码路径: `applications/modules/multiphaseEuler/fvModels/wallBoiling/departureDiameterModels/KocamustafaogullariIshiiDepartureDiameter/KocamustafaogullariIshiiDepartureDiameter.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`KocamustafaogullariIshiiDepartureDiameter`。
