# solitary

## 一句话

孤立波

## 适用条件（求解器 / 场 / 前提）

waveModel

## 字典示例

```c++
waves
(
    solitary
    {
        length      40;
        amplitude   0.5;
        offset      0;
    }
);
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

> Solitary wave model.
>
> Reference:
>     >     Dean, R. G., & Dalrymple, R. A. (1991).
>     >     Water wave mechanics for engineers and scientists (Vol. 2).
>     >     World Scientific Publishing Company.
>     > 
>
> See pages 314-317.

## 文献与源码依据

- 源码：[`src/waves/waveModels/solitary/solitary.H`](../../../../src/waves/waveModels/solitary/solitary.H)
- 实现：同目录 `.C`

## 教程与模板

- VoF 波浪教程；`etc/caseDicts/annotated/setWavesDict`

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
