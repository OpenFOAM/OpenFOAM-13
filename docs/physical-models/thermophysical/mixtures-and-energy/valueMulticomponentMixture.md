# `valueMulticomponentMixture`

## 一句话

值混合多组分混合物

## 适用条件（求解器 / 场 / 前提）

- `thermoType`.mixture valueMulticomponentMixture;`
- `pureMixture`：`psiThermos`/`rhoFluidThermos`/`solidThermos`/`liquidThermos`
- 多组分混合物：见 `rhoFluidMulticomponentThermos`.C` / `psiMulticomponentThermos`.C`

## 字典示例

```c++
thermoType
{
    mixture         valueMulticomponentMixture;
    // ...
}
```

## 参数表

混合物类型本身通常无独立系数；组分数据在 `mixture`/`<specieName>` 子字典。

## 控制方程与关联式

Thermophysical properties mixing class which applies mass-fraction weighted
mixing to thermodynamic properties and mole-fraction weighted mixing to
transport properties.

## 文献与源码依据

- 源码：[`src/thermophysicalModels/multicomponentThermo/mixtures/valueMulticomponentMixture/valueMulticomponentMixture.H`](../../../src/thermophysicalModels/multicomponentThermo/mixtures/valueMulticomponentMixture/valueMulticomponentMixture.H)

## 教程与模板

- `tutorials/multicomponentFluid/**`、`tutorials/fluid/**`

## 注意事项

- 多组分必须与 `fluidMulticomponentThermophysicalTransportModels` 等库匹配。
