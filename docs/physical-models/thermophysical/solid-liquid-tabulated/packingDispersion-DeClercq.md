# `DeClercq`

## 一句话

漂移通量堆积弥散模型 `DeClercq`。

## 适用条件（求解器 / 场 / 前提）

- 适用: `incompressibleDriftFlux`

## 字典示例

```c++
packingDispersionModel DeClercq;
```

## 参数表

见源码。

## 控制方程与关联式

De Clercq packing dispersion model for waste water sludge

## 文献与源码依据

- [`applications/modules/incompressibleDriftFlux/packingDispersionModels/DeClercq/DeClercq.H`](../../../applications/modules/incompressibleDriftFlux/packingDispersionModels/DeClercq/DeClercq.H)

## 教程与模板

- `tutorials/incompressibleDriftFlux/**`

## 注意事项

- `none` 表示关闭弥散。
