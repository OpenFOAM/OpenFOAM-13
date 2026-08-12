# cosine

## 一句话
SourceFiles

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 壁面阻尼（升力）（基类 `wallDampingModel`）
- **注册名**: `cosine`

## 字典示例

摘自 `tutorials/multiphaseEuler/Grossetete/constant/momentumTransfer`
（嵌在 `wallDamped` lift 的 `wallDamping` 子字典）：

```cpp
wallDamping
{
    type            cosine;
    Cd              1.0;          // [-]
    zeroInNearWallCells yes;      // 或 zeroWallDist 0.0002; // [m]
}
```

## 参数表

| 参数 | 默认 | 说明 |
|------|------|------|
| `alphaLiquid0` | （必填） |  |
| `alphaLiquid1` | （必填） |  |

写在 `constant/momentumTransfer`（OpenFOAM-13）；相界面键名依 blending/相名；`<phasePair>` 键名依相名与 blending（如 `air_dispersedIn_water`）。

## 控制方程与关联式
SourceFiles
cosineWallDamping.C

*---------------------------------------------------------------------------

## 文献与源码依据
- 类: `Foam`::wallDampingModels::cosine`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/wallDampingModels/cosine/cosineWallDamping.C`

## 教程与模板
- [`tutorials/multiphaseEuler/Grossetete/constant/momentumTransfer`](../../../../../tutorials/multiphaseEuler/Grossetete/constant/momentumTransfer)

## 注意事项
- 类型名必须与 RTS 注册名一致：`cosine`。
