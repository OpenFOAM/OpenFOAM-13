# phaseModel 注册类型（multiphaseEuler）

## 一句话
`phaseModels`.C` 用模板叠层注册的 8 个相类型：决定该相是否运动、是否等温、是否多组分/反应。

## 适用条件（求解器 / 场 / 前提）
- **适用**: `multiphaseEuler`
- **配置**: `constant/phaseProperties` 中每个相块的 `type`
- **源码**: `applications/modules/multiphaseEuler/phaseSystem/phaseModels/phaseModels.C`
- 界面力/传热传质不在相 `type` 内，而在同文件的 `drag`/`heatTransfer`/… 与 blending

## 字典示例
```
air
{
    type            purePhaseModel;
    diameterModel   constant;
    constantCoeffs
    {
        d               3e-3;
    }
    residualAlpha   1e-6;
}
```

反应多组分示例见 `bubbleColumnEvaporatingReacting`（`reactingPhaseModel`）。

## 参数表
| 注册名 | 模板叠层摘要 | 说明 |
|--------|--------------|------|
| `purePhaseModel` | Pure + Thermal + Inert + Moving + Thermo(`rhoFluidThermo`) | 纯物质、有能量、运动相 |
| `pureIsothermalPhaseModel` | Pure + Isothermal + Inert + Moving + Thermo | 等温运动相 |
| `pureStationaryPhaseModel` | Pure + SolidThermal + Inert + Stationary + SolidThermo | 静止固体热相 |
| `pureStationaryIsothermalPhaseModel` | Pure + SolidIsothermal + Inert + Stationary + … | 静止等温固体 |
| `multicomponentPhaseModel` | Multicomponent + Thermal + Inert + Moving + `rhoFluidMulticomponentThermo` | 多组分 |
| `multiComponentPhaseModel` | 同上（旧拼写别名） | 向后兼容 |
| `multicomponentIsothermalPhaseModel` | Multicomponent + Isothermal + Inert + Moving | 多组分等温 |
| `reactingPhaseModel` | Multicomponent + Thermal + Reacting + Moving | 相内反应 |

各相另配：`diameterModel`、`residualAlpha`、可选 `momentumTransport` / thermo 文件。

## 控制方程与关联式
- **Moving vs Stationary**：是否求解相动量（静止相用于填料/床层骨架）。
- **Thermal vs Isothermal**：是否求解相能量；等温相温度由系统/参考给定。
- **Pure vs Multicomponent**：是否求解组分；反应相在多组分上叠加 `ReactingPhaseModel`。
- 相间质量/热量/动量传递由 `phaseSystem` + 界面模型 / fvModels 提供，不由本表直接给出关联式。

## 文献与源码依据
- `applications/modules/multiphaseEuler/phaseSystem/phaseModels/phaseModels.C`（`addNamedToRunTimeSelectionTable`）
- 叠层头文件同目录：`PurePhaseModel`.H`、`MovingPhaseModel`.H`、`ThermalPhaseModel`.H` 等

## 教程与模板
- `tutorials/multiphaseEuler/bubbleColumn/constant/phaseProperties`（`purePhaseModel`）
- `tutorials/multiphaseEuler/bubbleColumnEvaporatingReacting/constant/phaseProperties`（`reactingPhaseModel`）
- `tutorials/multiphaseEuler/boilingBed`（含静止固相）

## 注意事项
- `type` 必须与命名注册字符串完全一致（含历史别名 `multiComponentPhaseModel`）。
- 不要为 8 个 typedef 各建重复页：参数差异主要在叠层组合，统一见本页。
- 固体静止相常见于沸腾床/填料案例；误用 `Moving` 固体会导致无物理解。
