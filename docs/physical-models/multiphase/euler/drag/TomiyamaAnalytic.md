# TomiyamaAnalytic

## 一句话
Analytical drag model of Tomiyama et al.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 阻力（基类 `dragModel`）
- **注册名**: `TomiyamaAnalytic`

## 字典示例

> （由源码构造函数推断，无官方教程实例）

```cpp
// constant/momentumTransfer — drag 子字典
drag
{
    gas_dispersedIn_liquid
    {
        type            TomiyamaAnalytic;
        residualEo      1e-3;     // [-] Eo 下限
        residualE       1e-3;     // [-] 纵横比 E 下限
        // 另需 aspectRatio 子模型（见 aspectRatioModels）
        aspectRatio
        {
            type            constant;
            E0              1;    // [-]
        }
    }
}
```

## 参数表

| 参数 | 默认 | 说明 |
|------|------|------|
| `residualEo` | （必填） | dimless |
| `residualE` | （必填） | dimless |

嵌套于 `constant/momentumTransfer` 的 `drag` 子字典；`<phasePair>` 键名依相名与 blending（如 `air_dispersedIn_water`）。

## 控制方程与关联式
Analytical drag model of Tomiyama et al.

Reference:
```
Tomiyama, A., Kataoka, I., & Sakaguchi, T. (1995).
Drag coefficients of bubbles (1 st Report, Drag coefficients of a single
bubble in a stagnant liquid).
Nihon Kikaigakkai Ronbunshu, 61, 2357-2364.
```

## 文献与源码依据
- 类: `Foam`::dragModels::TomiyamaAnalytic`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/dragModels/TomiyamaAnalytic/TomiyamaAnalytic.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`TomiyamaAnalytic`。
