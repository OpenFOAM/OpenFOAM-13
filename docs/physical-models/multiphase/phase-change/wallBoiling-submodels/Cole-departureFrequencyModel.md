# Cole

## 一句话
Cole correlation for bubble departure frequency.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler `wallBoiling` / `phaseSurfaceBoiling` 子模型
- **族**: 壁面沸腾/departureFrequencyModel（基类 `departureFrequencyModel`）
- **注册名**: `Cole`

## 字典示例
```
// 见源码 Usage；`type` 注册名为 `Cole`
Cole
{
    type    Cole;
    // ...
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `Cole`
- 基类: `departureFrequencyModel`


## 控制方程与关联式
Cole correlation for bubble departure frequency.

Reference:
```
Cole, R. (1960).
A photographic study of pool boiling in the region of the critical heat
flux.
AIChE Journal, 6(4), 533-538.
```

## 文献与源码依据
- 类: `Foam`::wallBoilingModels::departureFrequencyModels::Cole`
- 源码路径: `applications/modules/multiphaseEuler/fvModels/wallBoiling/departureFrequencyModels/Cole/Cole.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`Cole`。
