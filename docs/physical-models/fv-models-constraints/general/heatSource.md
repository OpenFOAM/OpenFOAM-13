# heatSource

## 一句话

体积热源

## 适用条件（求解器 / 场 / 前提）

适用: 有能量方程的流体/固体

## 字典示例



```c++
// `tutorials/fluid/roomHeating/constant/fvModels`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#includeModel heatSource

// ************************************************************************* //
```

## 参数表

主要入口以源码 `Usage` 为准。常见关键字见字典示例；完整列表与默认值见对应 `.H`。

| 说明 | |
|------|--|
| 配置位置 | 通常 `constant/fvModels` 或 `constant/fvConstraints` / `constant/dynamicMeshDict` |
| 选择关键字 | `type`（须与 RTS 注册名一致） |
| 区域选择 | 多数源/约束需要 `cellZone` 或等价选择 |


## 控制方程与关联式

摘自源码头文件 `Description`（原文）：

> Model for applying a heat source. Requires either the power, Q, or the
> power per unit volume, q, to be specified.

## 文献与源码依据

- 源码：[`src/fvModels/general/heatSource/heatSource.H`](../../../../src/fvModels/general/heatSource/heatSource.H)
- 实现：同目录 `.C`

## 教程与模板

- `etc/caseDicts/fvModels/`
- 例：`tutorials/fluid/angledDuct`（porosity）、`tutorials/incompressibleFluid/rotorDisk`（转子类）

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
