# TomiyamaWallLubrication

## 一句话
Wall lubrication model of Tomiyama.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 壁面润滑力（基类 `wallLubricationModel`）
- **注册名**: `Tomiyama`（类 `TomiyamaWallLubrication`）

## 字典示例

**RTS 注册名**：`Tomiyama`（类名 `TomiyamaWallLubrication`；与 lift 族的 `Tomiyama` 分属不同 RTS 表）。

> （由源码构造函数推断，无官方教程实例；字典键为 `Cwd`，量纲 [m]）

```cpp
// constant/momentumTransfer — wallLubrication 子字典
wallLubrication
{
    gas_dispersedIn_liquid
    {
        type            Tomiyama;
        Cwd             0.025;    // [m] 特征通道尺度 D
    }
}
```

## 参数表

| 参数 | 默认 | 说明 |
|------|------|------|
| `Cwd` | （必填） | dimLength |

写在 `constant/momentumTransfer`（OpenFOAM-13）；相界面键名依 blending/相名；`<phasePair>` 键名依相名与 blending（如 `air_dispersedIn_water`）。

## 控制方程与关联式
Wall lubrication model of Tomiyama.

References:
```
Otromke, M. (2013).
Implementation and Comparison of Correlations for interfacial Forces in
a Gas-Liquid System within an Euler-Euler Framework.
PhD Thesis.
```

```
Tomiyama, A. (1998).
Struggle with computational bubble dynamics.
Multiphase Science and Technology, 10(4), 369-405.
```

## 文献与源码依据
- 类: `Foam`::wallLubricationModels::TomiyamaWallLubrication`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/wallLubricationModels/TomiyamaWallLubrication/TomiyamaWallLubrication.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`TomiyamaWallLubrication`。
