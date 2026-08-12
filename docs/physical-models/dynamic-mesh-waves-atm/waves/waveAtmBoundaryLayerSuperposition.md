# waveAtmBoundaryLayerSuperposition

## 一句话

波 + 大气边界层叠加

## 适用条件（求解器 / 场 / 前提）

waveSuperposition

## 字典示例

```c++
type        waveAtmBoundaryLayer;

// parameters for waveSuperposition ...

UGasRef     (10 0 0);

hRef        10;

hWaveMin    -2;

hWaveMax    3;
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

> An extension of waveSuperposition which adds an atmospheric boundary layer
> model to the gas velocity. The user supplies a gas velocity and a height
> above the wave coordinate system origin at which that velocity is reached.
> Also needed are a maximum and minimum wave height which are used to set the
> surface roughness in the boundary layer model. It is not trivial to
> determine these from an arbitrary superposition of differently oriented
> wave models, so they are required as user inputs instead. For a pure
> sinusoidal wave, the maximum and minimum wave heights can be set to
> positive and negative amplitude, respectively.

## 文献与源码依据

- 源码：[`src/waves/waveSuperpositions/waveAtmBoundaryLayerSuperposition/waveAtmBoundaryLayerSuperposition.H`](../../../../src/waves/waveSuperpositions/waveAtmBoundaryLayerSuperposition/waveAtmBoundaryLayerSuperposition.H)
- 实现：同目录 `.C`

## 教程与模板

- VoF 波浪教程；`etc/caseDicts/annotated/setWavesDict`

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
