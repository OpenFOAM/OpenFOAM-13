# JONSWAP

## 一句话

JONSWAP 谱

## 适用条件（求解器 / 场 / 前提）

waveSpectrum

## 字典示例

```c++
spectrum    JONSWAP;

JONSWAPCoeffs
{
    U10         10;
    F           200e3;
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

> JONSWAP wave spectrum. This is similar to the Pierson-Moskowitz spectrum,
> but with an additional empirical correction to account for the fetch
> (distance to the lee shore).
>
> References:
>     >     Hasselmann, K., Barnett, T. P., Bouws, E., Carlson, H., Cartwright, \\
>     >     D. E., Enke, K., ... & Walden, H. (1973).
>     >     Measurements of wind-wave growth and swell decay during the Joint \\
>     >     North Sea Wave Project (JONSWAP).
>     >     Ergaenzungsheft zur Deutschen Hydrographischen Zeitschrift, Reihe A.
>     > 
>
>     >     Stewart, R. H. (2008).
>     >     Introduction to physical oceanography.
>     >     Robert H. Stewart.
>     > 

## 文献与源码依据

- 源码：[`src/waves/waveModels/irregular/waveSpectra/JONSWAP/JONSWAP.H`](../../../../src/waves/waveModels/irregular/waveSpectra/JONSWAP/JONSWAP.H)
- 实现：同目录 `.C`

## 教程与模板

- VoF 波浪教程；`etc/caseDicts/annotated/setWavesDict`

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
