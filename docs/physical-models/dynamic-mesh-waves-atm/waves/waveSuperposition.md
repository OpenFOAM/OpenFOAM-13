# waveSuperposition

## 一句话

波叠加基类/默认叠加

## 适用条件（求解器 / 场 / 前提）

waveSuperposition

## 字典示例

```c++
origin      (0 25 0);

direction   (1 0 0);

waves
(
    Airy
    {
        length      40;
        amplitude   0.5;
        phase       0;
        angle       0;
    }
    Airy
    {
        length      20;
        amplitude   0.25;
        phase       1.5708;
        angle       0;
    }
);

UMean       (2 0 0);

scale       table ((100 1) (200 0));

crossScale  constant 1;

heightAboveWave no;
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

> A wrapper around a list of wave models. Superimposes the modelled values of
> elevation and velocity. The New method looks up or constructs an
> instance of this class on demand and returns a reference. Properties are
> read from a waveProperties dictionary in constant.

## 文献与源码依据

- 源码：[`src/waves/waveSuperpositions/waveSuperposition/waveSuperposition.H`](../../../../src/waves/waveSuperpositions/waveSuperposition/waveSuperposition.H)
- 实现：同目录 `.C`

## 教程与模板

- VoF 波浪教程；`etc/caseDicts/annotated/setWavesDict`

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
