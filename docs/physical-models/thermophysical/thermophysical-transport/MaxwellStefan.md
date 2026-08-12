# `MaxwellStefan`

## 一句话

Maxwell–Stefan 扩散

## 适用条件（求解器 / 场 / 前提）

- 适用: `fluid`、`multicomponentFluid`、`compressibleVoF` 等链接 TTM 的求解器
- 要求 `momentumTransport`.simulationType laminar` 时常用 laminar TTM
- 多组分模型（Fickian/MaxwellStefan*）需 multicomponent thermo

## 字典示例

```c++
// constant/thermophysicalTransport
laminar
{
    model           MaxwellStefan;
}
```

## 参数表

湍流模型常见 `Prt`（湍流 Prandtl）；多组分另有 `Sct` / 二元扩散系数表。详见源码。

## 控制方程与关联式

Base class for multi-component Maxwell Stefan generalised Fick's law
diffusion coefficients based temperature gradient heat flux model with
optional Soret thermal diffusion of species.

The binary mass diffusion coefficients are specified as Function2<scalar>s
of pressure and temperature but independent of composition.

The heat flux source is implemented as an implicit energy correction to the
temperature gradient based flux source.  At convergence the energy
correction is 0.

References:
```
Taylor, R., & Krishna, R. (1993).
Multicomponent mass transfer (Vol. 2).
John Wiley & Sons.

Merk, H. J. (1959).
The macroscopic equations for simultaneous heat and mass transfer
in isotropic, continuous and closed systems.
Applied Scientific Research,
Section A, 8(1), 73-99.
```

## 文献与源码依据

- [`src/ThermophysicalTransportModels/fluid/laminar/MaxwellStefan/MaxwellStefan.H`](../../../src/ThermophysicalTransportModels/fluid/laminar/MaxwellStefan/MaxwellStefan.H)
- 注册：`src/ThermophysicalTransportModels/**/*ThermophysicalTransportModels.C`

## 教程与模板

- `tutorials/fluid/**/thermophysicalTransport`、`tutorials/multicomponentFluid/**`

## 注意事项

- TTM 的 `simulationType` 必须与动量输运一致（laminar/RAS/LES）。
