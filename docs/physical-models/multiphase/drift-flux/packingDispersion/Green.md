# Green

## 一句话
Green packing dispersion model for industrial separations

## 适用条件（求解器 / 场 / 前提）
- 适用: incompressibleDriftFlux
- **族**: 堆积弥散（基类 `packingDispersionModel`）
- **注册名**: `Green`

## 字典示例



> （由源码构造函数推断，无官方教程实例）

```c++
// constant/physicalProperties.water（或 mixture 相关字典）
type    Green;
sigma0    <value>;  // sqr(dimVelocity)
n    <value>;  // dimless
alphaGel    <value>;  // dimless
// --- Usage from header ---
packingDispersionModel Green;

        GreenCoeffs
        {
            sigma0          2.11e-3;
            n               9;
            alphaGel        0.1;
        }
```

## 参数表

| 参数 | 默认 | 说明 |
|------|------|------|
| `sigma0` | （必填） | sqr(dimVelocity) |
| `n` | （必填） | dimless |
| `alphaGel` | （必填） | dimless |

嵌套于 `constant/phaseProperties` 对应族子字典；`<phasePair>` 键名依相名与 blending（如 `air_dispersedIn_water`）。

## 控制方程与关联式
Green packing dispersion model for industrial separations

Reference:
```
Green, M. D., Eberl, M., & Landman, K. A. (1996).
Compressive yield stress of flocculated suspensions:
determination via experiment.
AIChE journal, 42(8), 2308-2318.
```

## 文献与源码依据
- 类: `Foam`::packingDispersionModels::Green`
- 源码路径: `applications/modules/incompressibleDriftFlux/packingDispersionModels/Green/Green.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`Green`。
