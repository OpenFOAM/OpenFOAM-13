# GodaJONSWAP

## 一句话

Goda 修正 JONSWAP 谱

## 适用条件（求解器 / 场 / 前提）

waveSpectrum

## 字典示例

```c++
spectrum    GodaJONSWAP;

GodaJONSWAPCoeffs
{
    Hs          2;
    Ts          6;
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

> GodaJONSWAP wave spectrum. This is an alternative, approximate
> parameterisation of the JONSWAP spectrum, in which the significant wave
> height and period are specified instead of the wind speed and fetch.
>
> References:
>     >     Goda, Y. (1988).
>     >     Statistical variability of sea state parameters as a function of wave
>     >     spectrum.
>     >     Coastal Engineering in Japan, 31(1), 39-52.
>     > 
>
>     >     Goda, Y. (2010).
>     >     Random seas and design of maritime structures.
>     >     World Scientific Publishing Company.
>     > 
>
> See page 29 of the second reference for a convenient formulation.

## 文献与源码依据

- 源码：[`src/waves/waveModels/irregular/waveSpectra/GodaJONSWAP/GodaJONSWAP.H`](../../../../src/waves/waveModels/irregular/waveSpectra/GodaJONSWAP/GodaJONSWAP.H)
- 实现：同目录 `.C`

## 教程与模板

- VoF 波浪教程；`etc/caseDicts/annotated/setWavesDict`

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
