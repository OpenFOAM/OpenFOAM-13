# `singleComponentMixture`

## 一句话

多组分框架下的单组分

## 适用条件（求解器 / 场 / 前提）

- `thermoType`.mixture singleComponentMixture;`
- `pureMixture`：`psiThermos`/`rhoFluidThermos`/`solidThermos`/`liquidThermos`
- 多组分混合物：见 `rhoFluidMulticomponentThermos`.C` / `psiMulticomponentThermos`.C`

## 字典示例

```c++
thermoType
{
    mixture         singleComponentMixture;
    // ...
}
```

## 参数表

混合物类型本身通常无独立系数；组分数据在 `mixture`/`<specieName>` 子字典。

## 控制方程与关联式

Single component mixture

## 文献与源码依据

- 源码：[`src/thermophysicalModels/multicomponentThermo/mixtures/singleComponentMixture/singleComponentMixture.H`](../../../src/thermophysicalModels/multicomponentThermo/mixtures/singleComponentMixture/singleComponentMixture.H)

## 教程与模板

- `tutorials/multicomponentFluid/**`、`tutorials/fluid/**`

## 注意事项

- 多组分必须与 `fluidMulticomponentThermophysicalTransportModels` 等库匹配。
