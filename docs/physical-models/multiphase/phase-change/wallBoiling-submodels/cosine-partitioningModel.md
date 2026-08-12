# cosine

## 一句话
Cosine wall heat flux partitioning model.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler `wallBoiling` / `phaseSurfaceBoiling` 子模型
- **族**: 壁面沸腾/partitioningModel（基类 `partitioningModel`）
- **注册名**: `cosine`

## 字典示例
```
// 见源码 Usage；`type` 注册名为 `cosine`
cosine
{
    type    cosine;
    // ...
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `cosine`
- 基类: `partitioningModel`


## 控制方程与关联式
Cosine wall heat flux partitioning model.

Proposed threshold liquid fractions:
- alphaLiquid1 0.1
- alphaLiquid0 0.05

```
Tentner, A., Lo, S., & Kozlov, V. (2006).
Advances in computational fluid dynamics modeling
of two-phase flow in boiling water reactor fuel assemblies.
In International Conference of Nuclear Engineering,
Miami, Florida, USA.
```

## 文献与源码依据
- 类: `Foam`::wallBoilingModels::partitioningModels::cosine`
- 源码路径: `applications/modules/multiphaseEuler/fvModels/wallBoiling/partitioningModels/cosine/cosine.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`cosine`。
