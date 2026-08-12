# `Fourier`

## 一句话

层流傅里叶热传导

## 适用条件（求解器 / 场 / 前提）

- 适用: `fluid`、`multicomponentFluid`、`compressibleVoF` 等链接 TTM 的求解器
- 要求 `momentumTransport`.simulationType laminar` 时常用 laminar TTM
- 多组分模型（Fickian/MaxwellStefan*）需 multicomponent thermo

## 字典示例

```c++
// constant/thermophysicalTransport
laminar
{
    model           Fourier;
}
```

## 参数表

湍流模型常见 `Prt`（湍流 Prandtl）；多组分另有 `Sct` / 二元扩散系数表。详见源码。

## 控制方程与关联式

Fourier's temperature gradient heat flux model
for single specie laminar flow.

The heat flux source is implemented as an implicit energy correction to the
temperature gradient based flux source.  At convergence the energy
correction is 0.

## 文献与源码依据

- [`src/ThermophysicalTransportModels/fluid/laminar/Fourier/Fourier.H`](../../../src/ThermophysicalTransportModels/fluid/laminar/Fourier/Fourier.H)
- 注册：`src/ThermophysicalTransportModels/**/*ThermophysicalTransportModels.C`

## 教程与模板

- `tutorials/fluid/**/thermophysicalTransport`、`tutorials/multicomponentFluid/**`

## 注意事项

- TTM 的 `simulationType` 必须与动量输运一致（laminar/RAS/LES）。
