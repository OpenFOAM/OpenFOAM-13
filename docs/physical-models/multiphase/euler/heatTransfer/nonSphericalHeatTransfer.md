# nonSphericalHeatTransfer

## 一句话
Model which applies an analytical solution for heat transfer from the

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 界面传热（基类 `heatTransferModel`）
- **注册名**: `nonSpherical`（类 `nonSphericalHeatTransfer`）

## 字典示例

**RTS 注册名**：`nonSpherical`（类名 `nonSphericalHeatTransfer`）。

摘自 `tutorials/multiphaseEuler/boilingBed/constant/heatTransfer`：

```cpp
// constant/heatTransfer — 相对接键
solid_dispersedIn_gas
{
    type            nonSpherical;
    factor          5;            // [-] 相对球形传热的面积/形状因子
}
```

## 参数表

| 参数 | 默认 | 说明 |
|------|------|------|
| `factor` | （必填） | dimless |

写在 `constant/heatTransfer`（OpenFOAM-13）；相界面键名依 blending/相名；`<phasePair>` 键名依相名与 blending（如 `air_dispersedIn_water`）。

## 控制方程与关联式
Model which applies an analytical solution for heat transfer from the
surface of a sphere to the matter within the sphere, modified by a
non-spherical factor.

## 文献与源码依据
- 类: `Foam`::heatTransferModels::nonSphericalHeatTransfer`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/heatTransferModels/nonSphericalHeatTransfer/nonSphericalHeatTransfer.C`

## 教程与模板
- [`tutorials/multiphaseEuler/boilingBed/constant/heatTransfer`](../../../../../tutorials/multiphaseEuler/boilingBed/constant/heatTransfer)

## 注意事项
- 类型名必须与 RTS 注册名一致：`nonSphericalHeatTransfer`。
