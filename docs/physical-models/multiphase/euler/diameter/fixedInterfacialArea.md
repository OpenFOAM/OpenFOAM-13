# fixedInterfacialArea

## 一句话
fixedInterfacialArea dispersed-phase diameter model.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 相直径模型（基类 `diameterModel`）
- **注册名**: `fixedInterfacialArea`

## 字典示例
```
// 见源码 Usage；`type` 注册名为 `fixedInterfacialArea`
fixedInterfacialArea
{
    type    fixedInterfacialArea;
    // ...
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `fixedInterfacialArea`
- 基类: `diameterModel`


## 控制方程与关联式
fixedInterfacialArea dispersed-phase diameter model.
The interfacial are is set by providing phase surface area divided by phase
volume, AvbyAlpha, either as a constant value or as a field.

## 文献与源码依据
- 类: `Foam`::diameterModels::fixedInterfacialArea`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/diameterModels/fixedInterfacialAreaDiameter/fixedInterfacialAreaDiameter.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`fixedInterfacialArea`。
