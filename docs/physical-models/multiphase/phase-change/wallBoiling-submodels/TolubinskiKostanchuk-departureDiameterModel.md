# TolubinskiKostanchuk

## 一句话
Tolubinski-Kostanchuk correlation for bubble departure diameter.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler `wallBoiling` / `phaseSurfaceBoiling` 子模型
- **族**: 壁面沸腾/departureDiameterModel（基类 `departureDiameterModel`）
- **注册名**: `TolubinskiKostanchuk`

## 字典示例
```
// 见源码 Usage；`type` 注册名为 `TolubinskiKostanchuk`
TolubinskiKostanchuk
{
    type    TolubinskiKostanchuk;
    // ...
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `TolubinskiKostanchuk`
- 基类: `departureDiameterModel`


## 控制方程与关联式
Tolubinski-Kostanchuk correlation for bubble departure diameter.

Reference:
```
Tolubinsky, V. I., & Kostanchuk, D. M. (1970).
Vapour bubbles growth rate and heat transfer intensity at subcooled
water boiling.
In International Heat Transfer Conference 4 (Vol. 23). Begel House Inc.
```

## 文献与源码依据
- 类: `Foam`::wallBoilingModels::departureDiameterModels::TolubinskiKostanchuk`
- 源码路径: `applications/modules/multiphaseEuler/fvModels/wallBoiling/departureDiameterModels/TolubinskiKostanchuk/TolubinskiKostanchuk.C`

## 教程与模板
- `tutorials/multiRegion/CHT/wallBoiling/constant/fluid/fvModels`
- `tutorials/multiphaseEuler/wallBoilingPolydisperseTwoGroups/constant/fvModels`
- `tutorials/multiphaseEuler/wallBoilingPolydisperse/constant/fvModels`
- `tutorials/multiphaseEuler/wallBoilingIATE/constant/fvModels`
- `tutorials/multiphaseEuler/boilingBed/constant/fvModels`

## 注意事项
- 类型名必须与 RTS 注册名一致：`TolubinskiKostanchuk`。
