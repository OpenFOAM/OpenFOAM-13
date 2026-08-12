# heatTransfer

## 一句话

区域内传热（HTC 模型）

## 适用条件（求解器 / 场 / 前提）

适用: 多区域；需对侧区域映射

## 字典示例



> （由源码构造函数推断，无官方教程实例）

```c++
heatTransfer
    {
        type            heatTransfer;

        cellZone        c0;

        semiImplicit    no;

        Ta              300;

        Av              200;

        heatTransferCoefficientModel constant;

        htc             10;
    }
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

> Model for heat exchange. Requires specification of an ambient temperature
> with which to exchange heat, and a model for the heat transfer coefficient
> (htc) and the area per unit volume (Av). These are then used to apply the
> following source to the energy equation:
>
> $$
>     -htc*Av*(T_a - T)
> $$
>
> If the semiImplicit option is set, then this becomes:
>
> $$
>     -htc*Av*(T_a - T) + htc*Av/Cp*h - Sp(htc*Av/Cp, h);
> $$

## 文献与源码依据

- 源码：[`src/fvModels/interRegion/heatTransfer/heatTransfer.H`](../../../../src/fvModels/interRegion/heatTransfer/heatTransfer.H)
- 实现：同目录 `.C`

## 教程与模板

- 多区域 CHT / 换热器相关 `tutorials/multiRegion/`

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
