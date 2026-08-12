# phaseFraction

## 一句话
Wall heat-flux partitioned according to the phase volume fraction.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler `wallBoiling` / `phaseSurfaceBoiling` 子模型
- **族**: 壁面沸腾/partitioningModel（基类 `partitioningModel`）
- **注册名**: `phaseFraction`

## 字典示例
```
// 见源码 Usage；`type` 注册名为 `phaseFraction`
phaseFraction
{
    type    phaseFraction;
    // ...
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `phaseFraction`
- 基类: `partitioningModel`


## 控制方程与关联式
Wall heat-flux partitioned according to the phase volume fraction.

## 文献与源码依据
- 类: `Foam`::wallBoilingModels::partitioningModels::phaseFraction`
- 源码路径: `applications/modules/multiphaseEuler/fvModels/wallBoiling/partitioningModels/phaseFraction/phaseFraction.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`phaseFraction`。
