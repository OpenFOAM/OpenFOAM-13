# `coefficientMulticomponentMixture`

## 一句话

系数型多组分混合物

## 适用条件（求解器 / 场 / 前提）

- `thermoType`.mixture coefficientMulticomponentMixture;`
- `pureMixture`：`psiThermos`/`rhoFluidThermos`/`solidThermos`/`liquidThermos`
- 多组分混合物：见 `rhoFluidMulticomponentThermos`.C` / `psiMulticomponentThermos`.C`

## 字典示例

```c++
thermoType
{
    mixture         coefficientMulticomponentMixture;
    // ...
}
```

## 参数表

混合物类型本身通常无独立系数；组分数据在 `mixture`/`<specieName>` 子字典。

## 控制方程与关联式

Thermophysical properties mixing class which applies mass-fraction weighted
mixing to the thermodynamic and transport coefficients.

## 文献与源码依据

- 源码：[`src/thermophysicalModels/multicomponentThermo/mixtures/coefficientMulticomponentMixture/coefficientMulticomponentMixture.H`](../../../src/thermophysicalModels/multicomponentThermo/mixtures/coefficientMulticomponentMixture/coefficientMulticomponentMixture.H)

## 教程与模板

- `tutorials/multicomponentFluid/**`、`tutorials/fluid/**`

## 注意事项

- 多组分必须与 `fluidMulticomponentThermophysicalTransportModels` 等库匹配。
