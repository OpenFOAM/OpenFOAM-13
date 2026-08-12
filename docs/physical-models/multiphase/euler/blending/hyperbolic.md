# hyperbolic

## 一句话
Blending method based on smooth hyperbolic functions. Supports the full

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: BlendedInterfacialModel 混合方法（基类 `blendingMethod`）
- **注册名**: `hyperbolic`

## 字典示例
```
// 见源码 Usage；`type` 注册名为 `hyperbolic`
hyperbolic
{
    type    hyperbolic;
    // ...
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `hyperbolic`
- 基类: `blendingMethod`


## 控制方程与关联式
Blending method based on smooth hyperbolic functions. Supports the full
range of phase fraction space. E.g., from droplets in air, through a
segregated regime, to bubbly flow.

This method requires a volume fraction at which the phase is considered to
become continuous, and a range of volume fraction over which this occurs,
to be specified for both phases.

Alternatively, the volume fraction can be omitted or replaced with the
keyword "none" to represent a phase which cannot become continuous. E.g.,
a particulate phase.

## 文献与源码依据
- 类: `Foam`::blendingMethods::hyperbolic`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/BlendedInterfacialModel/blendingMethods/hyperbolic/hyperbolic.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`hyperbolic`。
