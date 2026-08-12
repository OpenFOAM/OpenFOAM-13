# hydrodynamic

## 一句话
Hydrodynamic kernel.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler（populationBalance）
- **族**: 聚并（基类 `coalescenceModel`）
- **注册名**: `hydrodynamic`

## 字典示例
```
// 见源码 Usage；`type` 注册名为 `hydrodynamic`
hydrodynamic
{
    type    hydrodynamic;
    // ...
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `hydrodynamic`
- 基类: `coalescenceModel`


## 控制方程与关联式
Hydrodynamic kernel.

## 文献与源码依据
- 类: `Foam`::diameterModels::coalescenceModels::hydrodynamic`
- 源码路径: `applications/modules/multiphaseEuler/populationBalance/coalescenceModels/hydrodynamic/hydrodynamic.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`hydrodynamic`。
