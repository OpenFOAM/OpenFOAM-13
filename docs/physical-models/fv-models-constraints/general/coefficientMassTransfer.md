# coefficientMassTransfer

## 一句话

系数型相间质量传递

## 适用条件（求解器 / 场 / 前提）

适用: 多相/多组分场景；需验证相名

## 字典示例



> （由源码构造函数推断，无官方教程实例）

```c++
coefficientMassTransfer
    {
        type            coefficientMassTransfer;

        phases          (liquid vapour);

        C               [kg/m^2/s] 0.1;
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

> This simple model generates a mass transfer between two phases calculated
> from the following expression:
>
>     $$
>         \dot{m}/V = C \alpha \grad \alpha
>     $$
>
> 
>     \dot{m}/V | mass transfer rate per unit volume
>     C         | coefficient
>     \alpha    | volume fraction of the source phase
> 

## 文献与源码依据

- 源码：[`src/fvModels/general/massTransfer/coefficientMassTransfer.H`](../../../../src/fvModels/general/massTransfer/coefficientMassTransfer.H)
- 实现：同目录 `.C`

## 教程与模板

- `etc/caseDicts/fvModels/`
- 例：`tutorials/fluid/angledDuct`（porosity）、`tutorials/incompressibleFluid/rotorDisk`（转子类）

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
