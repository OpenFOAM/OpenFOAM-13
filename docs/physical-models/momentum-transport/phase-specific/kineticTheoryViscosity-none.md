# `kineticTheoryViscosity`-none`

## 一句话

颗粒动力学理论粘度子模型 `none`

## 适用条件（求解器 / 场 / 前提）

- 适用: `multiphaseEuler` kineticTheory
- `viscosityModel` 子字典

## 字典示例

```c++
// 在 multiphaseEuler 颗粒相 kineticTheoryModel 子字典中
viscosityModel  none;
```


## 参数表

系数通常可在模型子字典覆盖（`Cmu`、`Ck` 等）；默认值见源码 `read`()`。

## 控制方程与关联式

动力学理论颗粒粘度子模型 `type` none`。


## 文献与源码依据

- [`applications/modules/multiphaseEuler/momentumTransportModels/kineticTheoryModels/viscosityModel/none/noneViscosity.H`](../../../applications/modules/multiphaseEuler/momentumTransportModels/kineticTheoryModels/viscosityModel/none/noneViscosity.H)


## 教程与模板

- `tutorials/multiphaseEuler/LBend/constant/momentumTransport.solids`
- `tutorials/multiphaseEuler/fluidisedBedLaminar/constant/momentumTransport.particles`
- `tutorials/multiphaseEuler/fluidisedBed/constant/momentumTransport.particles`


## 注意事项

- 模型必须在对应库中注册（不可压/可压/相）；见族 README 注册表。
