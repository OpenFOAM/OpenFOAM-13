# PiersonMoskowitz

## 一句话

Pierson–Moskowitz 谱

## 适用条件（求解器 / 场 / 前提）

waveSpectrum

## 字典示例

```c++
spectrum    PiersonMoskowitz;

PiersonMoskowitzCoeffs
{
    U19_5       15;
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

> Pierson-Moskowitz wave spectrum. This spectrum has the following form:
>
>     $$
>         S(\omega) = \frac{\alpha g^2}{\omega^5} \exp \left(- \beta \\
>         \left( \frac{\omega_0}{\omega} \right)^4 \right)
>     $$
>
> 
>     \omega    | angular frequency [rad/s], equal to $2 \pi f$
>     f         | frequency [Hz]
>     S(\omega) | spectral density [m^2/Hz]
>     \alpha    | coefficient, equal to 8.1e3
>     \beta     | coefficient, equal to 0.74
>     \omega_0  | reference angular frequency, equal to $g/U_{19.5}$
>     U_{19.5}  | reference velocity magnitude, 19.5 metres above the sea \\
>                 surface
> 
>
> References:
>     >     Pierson Jr, W. J., & Moskowitz, L. (1964).
>     >     A proposed spectral form for fully developed wind seas based on the \\
>     >     similarity theory of SA Kitaigorodskii.
>     >     Journal of geophysical research, 69(24), 5181-5190.
>     > 
>
>     >     Stewart, R. H. (2008).
>     >     Introduction to physical oceanography.
>     >     Robert H. Stewart.
>     > 

## 文献与源码依据

- 源码：[`src/waves/waveModels/irregular/waveSpectra/PiersonMoskowitz/PiersonMoskowitz.H`](../../../../src/waves/waveModels/irregular/waveSpectra/PiersonMoskowitz/PiersonMoskowitz.H)
- 实现：同目录 `.C`

## 教程与模板

- VoF 波浪教程；`etc/caseDicts/annotated/setWavesDict`

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
