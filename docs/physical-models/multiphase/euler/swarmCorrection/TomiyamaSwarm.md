# TomiyamaSwarm

## 一句话
Swarm correction of Tomiyama et al.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 群体修正（基类 `swarmCorrection`）
- **注册名**: `TomiyamaSwarm`

## 字典示例

> （由源码构造函数推断，无官方教程实例）

```cpp
// 常作为 drag 等模型的 swarmCorrection 子字典
swarmCorrection
{
    type            TomiyamaSwarm;
    l               0.25;         // [-] 必填
    residualAlpha   1e-4;         // [-] 可选；默认取分散相 residualAlpha
}
```

## 参数表

| 参数 | 默认 | 说明 |
|------|------|------|
| `residualAlpha` | （必填） | dimless |
| `l` | （必填） | dimless |

写在 `constant/momentumTransfer`（OpenFOAM-13）；相界面键名依 blending/相名；`<phasePair>` 键名依相名与 blending（如 `air_dispersedIn_water`）。

## 控制方程与关联式
Swarm correction of Tomiyama et al.

Reference:
```
Tomiyama, A., Kataoka, I., Fukuda, T., & Sakaguchi, T. (1995).
Drag coefficients of bubbles: 2nd report, drag coefficient for a swarm
of bubbles and its applicability to transient flow.
JSME Journal of Fluid Engineering, 61, 2810-2817.
```

## 文献与源码依据
- 类: `Foam`::swarmCorrections::TomiyamaSwarm`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/swarmCorrections/TomiyamaSwarm/TomiyamaSwarm.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`TomiyamaSwarm`。
