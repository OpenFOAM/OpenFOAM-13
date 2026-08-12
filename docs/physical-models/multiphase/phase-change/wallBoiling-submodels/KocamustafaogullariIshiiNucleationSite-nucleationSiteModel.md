# KocamustafaogullariIshiiNucleationSite

## 一句话
A correlation for nucleation site density.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler `wallBoiling` / `phaseSurfaceBoiling` 子模型
- **族**: 壁面沸腾/nucleationSiteModel（基类 `nucleationSiteModel`）
- **注册名**: `KocamustafaogullariIshiiNucleationSite`

## 字典示例
```
// 见源码 Usage；`type` 注册名为 `KocamustafaogullariIshiiNucleationSite`
KocamustafaogullariIshiiNucleationSite
{
    type    KocamustafaogullariIshiiNucleationSite;
    // ...
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `KocamustafaogullariIshiiNucleationSite`
- 基类: `nucleationSiteModel`


## 控制方程与关联式
A correlation for nucleation site density.

Reference:
```
Kocamustafaogullari, G., & Ishii, M. (1983).
Interfacial area and nucleation site density in boiling systems.
International Journal of Heat and Mass Transfer, 26(9), 1377-1387.
```

## 文献与源码依据
- 类: `Foam`::wallBoilingModels::nucleationSiteModels::`
- 源码路径: `applications/modules/multiphaseEuler/fvModels/wallBoiling/nucleationSiteModels/KocamustafaogullariIshiiNucleationSite/KocamustafaogullariIshiiNucleationSite.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`KocamustafaogullariIshiiNucleationSite`。
