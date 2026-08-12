# function2

## 一句话

Function2 heat transfer model.

## 适用条件（求解器 / 场 / 前提）

适用: `heatTransfer` / `interRegionHeatTransfer` 子模型（`heatTransferCoefficientModel`）

## 字典示例



> （由源码构造函数推断，无官方教程实例）

```c++
{
        heatTransferCoefficientModel function2;

        htcFunc
        {
            type        constant;
            value       1e5;
        }
    }
```

## 参数表

主要入口以源码 `Usage` 为准。常见关键字见字典示例；完整列表与默认值见对应 `.H`。

| 说明 | |
|------|--|
| 选择关键字 | `type`（须与 RTS 注册名一致） |
| 配置位置 | 见适用条件 |

## 控制方程与关联式

摘自源码头文件 `Description`（原文）：

> Function2 heat transfer model. The 2D function returns the heat transfer
> coefficient as a function of the local and neighbouring velocity
> magnitudes.

## 文献与源码依据

- 源码：[`src/fvModels/interRegion/heatTransferCoefficientModels/function2/function2.H`](../../../../../src/fvModels/interRegion/heatTransferCoefficientModels/function2/function2.H)
- 实现：同目录 `.C`

## 教程与模板

- 多区域 CHT / heat exchanger 教程；父页 [../heatTransfer.md](../heatTransfer.md)

## 注意事项

- 由父 fvModel 的 `heatTransferCoefficientModel` 关键字选择，不是独立 `fvModels` type
