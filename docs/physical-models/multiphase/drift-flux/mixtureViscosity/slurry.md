# slurry

## 一句话
Thomas' viscosity correction for slurry.

## 适用条件（求解器 / 场 / 前提）
- 适用: incompressibleDriftFlux
- **族**: 混合物粘度（基类 `mixtureViscosityModel`）
- **注册名**: `slurry`

## 字典示例


> （由源码构造函数推断，无官方教程实例）

```c++
// constant/physicalProperties.water（或 mixture 相关字典）
type    slurry;
```

## 参数表

| 参数 | 说明 |
|------|------|
| `type` | 必须为 `slurry` |
| （基类） | 部分模型继承 `residualRe` / `residualAlpha` 等，见对应基类 ctor |

本模型构造函数通常无额外专用系数。

## 控制方程与关联式
Thomas' viscosity correction for slurry.

Reference:
```
"Transport characteristics of suspension:
VIII. A note on the viscosity of Newtonian suspensions
of uniform spherical particles".
D.G. Thomas,
J. Colloid Sci. 20 (3), 1965, p267.
```

## 文献与源码依据
- 类: `Foam`::mixtureViscosityModels::slurry`
- 源码路径: `applications/modules/incompressibleDriftFlux/mixtureViscosityModels/slurry/slurry.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`slurry`。
