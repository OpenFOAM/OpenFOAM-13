# `none`

## 一句话

漂移通量堆积弥散模型 `none`。

## 适用条件（求解器 / 场 / 前提）

- 适用: `incompressibleDriftFlux`

## 字典示例

```c++
packingDispersionModel none;
```

## 参数表

见源码。

## 控制方程与关联式

Dummy packing dispersion model

## 文献与源码依据

- [`applications/modules/incompressibleDriftFlux/packingDispersionModels/none/none_packingDispersionModel.H`](../../../applications/modules/incompressibleDriftFlux/packingDispersionModels/none/none_packingDispersionModel.H)

## 教程与模板

- `tutorials/incompressibleDriftFlux/**`

## 注意事项

- `none` 表示关闭弥散。
