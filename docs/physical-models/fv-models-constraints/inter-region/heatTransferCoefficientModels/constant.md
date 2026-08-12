# constant

## 一句话

Constant heat transfer model.

## 适用条件（求解器 / 场 / 前提）

适用: `heatTransfer` / `interRegionHeatTransfer` 子模型（`heatTransferCoefficientModel`）

## 字典示例



```c++
// `etc/caseDicts/fvModels/fvModels`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

// include packaged fvModels using #includeModel
// #includeModel ...

//************************************************************************ //
```

## 参数表

主要入口以源码 `Usage` 为准。常见关键字见字典示例；完整列表与默认值见对应 `.H`。

| 说明 | |
|------|--|
| 选择关键字 | `type`（须与 RTS 注册名一致） |
| 配置位置 | 见适用条件 |

## 控制方程与关联式

摘自源码头文件 `Description`（原文）：

> Constant heat transfer model. The heat transfer coefficient [W/m^2/K] (htc)
> must be provided as a value in the coefficients dictionary or as a field in
> constant.

## 文献与源码依据

- 源码：[`src/fvModels/interRegion/heatTransferCoefficientModels/constant/constant.H`](../../../../../src/fvModels/interRegion/heatTransferCoefficientModels/constant/constant.H)
- 实现：同目录 `.C`

## 教程与模板

- 多区域 CHT / heat exchanger 教程；父页 [../heatTransfer.md](../heatTransfer.md)

## 注意事项

- 由父 fvModel 的 `heatTransferCoefficientModel` 关键字选择，不是独立 `fvModels` type
