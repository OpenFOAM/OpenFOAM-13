# `Usher`

## 一句话

漂移通量堆积弥散模型 `Usher`。

## 适用条件（求解器 / 场 / 前提）
- 适用: `incompressibleDriftFlux`

## 字典示例

```c++
packingDispersionModel Usher;

```
## 参数表

见源码。

## 控制方程与关联式

Usher packing dispersion model for sewage and mineral slurries, both cetrifugated and filtered.



## 文献与源码依据

- [`applications/modules/incompressibleDriftFlux/packingDispersionModels/Usher/Usher.H`](../../../applications/modules/incompressibleDriftFlux/packingDispersionModels/Usher/Usher.H)

## 教程与模板

- `tutorials/incompressibleDriftFlux/**`

## 注意事项

- `none` 表示关闭弥散。
