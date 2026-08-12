# noDiameter

## 一句话
Diameter model for purely continuous phases.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 相直径模型（基类 `diameterModel`）
- **注册名**: `noDiameter`

## 字典示例
```
// 见源码 Usage；`type` 注册名为 `noDiameter`
noDiameter
{
    type    noDiameter;
    // ...
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `noDiameter`
- 基类: `diameterModel`


## 控制方程与关联式
Diameter model for purely continuous phases.

## 文献与源码依据
- 类: `Foam`::diameterModels::noDiameter`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/diameterModels/noDiameter/noDiameter.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`noDiameter`。
