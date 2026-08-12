# irregular

## 一句话

不规则波（谱）

## 适用条件（求解器 / 场 / 前提）

waveModel；需 waveSpectrum

## 字典示例

```c++
waves
(
    irregular
    {
        spectrum    PiersonMoskowitz;

        PiersonMoskowitzCoeffs
        {
            U19_5       15;
        }

        n           16;
        span        (0.01 0.99);
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

> Irregular wave model. Phase fraction and velocity field are built up from
> multiple first-order waves, sampled from a selectable wave spectrum.

## 文献与源码依据

- 源码：[`src/waves/waveModels/irregular/irregular.H`](../../../../src/waves/waveModels/irregular/irregular.H)
- 实现：同目录 `.C`

## 教程与模板

- VoF 波浪教程；`etc/caseDicts/annotated/setWavesDict`

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
