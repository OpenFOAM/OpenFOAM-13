# `SmagorinskyZhang`

## 一句话

Zhang 修正 Smagorinsky（相）

## 适用条件（求解器 / 场 / 前提）
- 适用: `multiphaseEuler` 相动量输运
- 注册：`applications/modules/multiphaseEuler/momentumTransportModels/momentumTransportModels.C`

## 字典示例

```c++
// constant/momentumTransport.<phase> (multiphaseEuler) simulationType RAS;
// 或 LES RAS
{
model SmagorinskyZhang;
turbulence on;
}

```
## 参数表

系数通常可在模型子字典覆盖（`Cmu`、`Ck` 等）；默认值见源码 `read`()`。

## 控制方程与关联式

The Smagorinsky SGS model including bubble-generated turbulence



The default model coefficients are
```
    SmagorinskyZhangCoeffs
    {
        Ck              0.094;
        Ce              1.048;
        Cmub            0.6;
    }
```


## 文献与源码依据

- [`src/MomentumTransportModels/phaseCompressible/LES/SmagorinskyZhang/SmagorinskyZhang.H`](../../../src/MomentumTransportModels/phaseCompressible/LES/SmagorinskyZhang/SmagorinskyZhang.H)
- 注册：`applications/modules/multiphaseEuler/momentumTransportModels/momentumTransportModels.C`


## 教程与模板

- `tutorials/multiphaseEuler/bubbleColumnLES/constant/momentumTransport.water`


## 注意事项

- 仅 `multiphaseEuler`（及链接同一工厂的多区域流体）可用；单相 `fluid`/`incompressibleFluid` **无**此 RTS。
- 通常写在 `constant/momentumTransport.<phase>`，不是混合物总字典。

