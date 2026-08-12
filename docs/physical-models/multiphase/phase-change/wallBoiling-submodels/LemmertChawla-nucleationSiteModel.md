# LemmertChawla

## 一句话
Lemmert & Chawla function for nucleation site density,

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler `wallBoiling` / `phaseSurfaceBoiling` 子模型
- **族**: 壁面沸腾/nucleationSiteModel（基类 `nucleationSiteModel`）
- **注册名**: `LemmertChawla`

## 字典示例
```
// 见源码 Usage；`type` 注册名为 `LemmertChawla`
LemmertChawla
{
    type    LemmertChawla;
    // ...
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `LemmertChawla`
- 基类: `nucleationSiteModel`


## 控制方程与关联式
Lemmert & Chawla function for nucleation site density,
correlation by Egorov & Menter.

References:
```
Lemmert, M., & Chawla, J. M. (1977).
Influence of flow velocity on surface boiling heat transfer coefficient.
Heat Transfer in Boiling, 237, 247.

Egorov, Y., & Menter, F. (2004).
Experimental implementation of the RPI wall boiling model in CFX-5.6.
Staudenfeldweg, 12, 83624.
Technical Report ANSYS/TR-04-10, ANSYS Gmbh.
```

## 文献与源码依据
- 类: `Foam`::wallBoilingModels::nucleationSiteModels::LemmertChawla`
- 源码路径: `applications/modules/multiphaseEuler/fvModels/wallBoiling/nucleationSiteModels/LemmertChawla/LemmertChawla.C`

## 教程与模板
- `tutorials/multiRegion/CHT/wallBoiling/constant/fluid/fvModels`
- `tutorials/multiphaseEuler/wallBoilingPolydisperseTwoGroups/constant/fvModels`
- `tutorials/multiphaseEuler/wallBoilingPolydisperse/constant/fvModels`
- `tutorials/multiphaseEuler/wallBoilingIATE/constant/fvModels`
- `tutorials/multiphaseEuler/boilingBed/constant/fvModels`

## 注意事项
- 类型名必须与 RTS 注册名一致：`LemmertChawla`。
