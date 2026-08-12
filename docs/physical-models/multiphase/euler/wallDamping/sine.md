# sine

## 一句话
SourceFiles

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 壁面阻尼（升力）（基类 `wallDampingModel`）
- **注册名**: `sine`

## 字典示例



> （由源码构造函数推断，无官方教程实例）

```c++
// constant/phaseProperties — wallDamping 子字典
wallDamping
{
    <phasePair>
    {
        type            sine;
        <name> sine;
        <name>Coeffs
        amplitude (1 0.1 0);
        frequency 10;
        start     0;
        level     (10 1 0);
    }
}
```

## 参数表

| 参数 | 默认 | 说明 |
|------|------|------|
| `start` | units.x, 0 |  |

写在 `constant/momentumTransfer`（OpenFOAM-13）；相界面键名依 blending/相名；`<phasePair>` 键名依相名与 blending（如 `air_dispersedIn_water`）。

## 控制方程与关联式
SourceFiles
sineWallDamping.C

*---------------------------------------------------------------------------

## 文献与源码依据
- 类: `Foam`::wallDampingModels::sine`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/wallDampingModels/sine/sineWallDamping.C`

## 教程与模板
- `tutorials/incompressibleVoF/wave/constant/fvModels`
- `tutorials/incompressibleVoF/forcedUpstreamWave/constant/fvModels`
- `tutorials/incompressibleVoF/floatingObjectWaves/constant/fvModels`
- `tutorials/fluid/stackPlume/constant/physicalProperties`
- `tutorials/fluid/roomHeating/constant/physicalProperties`

## 注意事项
- 类型名必须与 RTS 注册名一致：`sine`。
