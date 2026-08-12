# heatTransferAv

## 一句话

区域间传热中的比表面积（Av）辅助子模型

## 适用条件（求解器 / 场 / 前提）

适用: interRegion `heatTransfer` 族；作为父模型系数，非独立 fvModel type

## 字典示例


> （由源码构造函数推断，无官方教程实例）

```c++
type heatTransferAv;
Av    <value>;
AoV    <value>;
```

## 参数表

主要入口以源码 `Usage` 为准。常见关键字见字典示例；完整列表与默认值见对应 `.H`。

| 说明 | |
|------|--|
| 选择关键字 | `type`（须与 RTS 注册名一致） |
| 配置位置 | 见适用条件 |

## 控制方程与关联式

摘自源码头文件 `Description`（原文）：

> 提供传热面积密度 Av，配合 htc 得到体积传热系数。

## 文献与源码依据

- 源码：[`src/fvModels/interRegion/heatTransfer/heatTransferAv/`](../../../src/fvModels/interRegion/heatTransfer/heatTransferAv/)

## 教程与模板

- 多区域传热教程

## 注意事项

- inventory 中的 directory 名；由父模型读取
