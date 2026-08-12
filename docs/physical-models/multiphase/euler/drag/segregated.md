# segregated

## 一句话
Segregated drag model for use in regions with no obvious dispersed phase.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 阻力（基类 `dragModel`）
- **注册名**: `segregated`

## 字典示例

摘录 `tutorials/multiRegion/CHT/multiphaseCoolingCylinder2D/constant/fluid/momentumTransfer`：

```c++
// constant/fluid/momentumTransfer（OpenFOAM-13；勿写入 phaseProperties）
drag
{
    blending            segregated;

    oil_dispersedIn_water
    {
        type            SchillerNaumann;
    }

    water_dispersedIn_oil
    {
        type            SchillerNaumann;
    }

    oil_segregatedWith_water
    {
        type            segregated;
        m               0.5;
        n               8;
    }
}
```

## 参数表
| 参数 | 含义 | 必需 |
|------|------|------|
| `m`,`n` | segregated 阻力幂次系数 | yes（见 ctor） |

（`blending segregated` 与相定义仍在 `phaseProperties`；阻力模型本身在 `momentumTransfer`。）

## 控制方程与关联式
Segregated drag model for use in regions with no obvious dispersed phase.

Reference:
```
Marschall, H. (2011).
Towards the numerical simulation of multi-scale two-phase flows.
PhD Thesis, TU München.
```

## 文献与源码依据
- 类: `Foam`::dragModels::segregated`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/dragModels/segregated/segregated.C`

## 教程与模板
- `tutorials/multiRegion/CHT/multiphaseCoolingCylinder2D/constant/fluid/momentumTransfer`
- `tutorials/multiphaseEuler/mixerVessel2DMRF/constant/momentumTransfer`
- `tutorials/multiphaseEuler/mixerVessel2D/constant/momentumTransfer`
- `tutorials/multiphaseEuler/injection/constant/momentumTransfer`
- `tutorials/multiphaseEuler/damBreak4phase/constant/momentumTransfer`

## 注意事项
- 类型名必须与 RTS 注册名一致：`segregated`。
- 界面键名如 `oil_segregatedWith_water` 由 `phaseProperties` 的 blending 与相名决定。
