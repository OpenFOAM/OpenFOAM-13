# `RASThermophysicalTransportModel`

## 一句话

RAS（RANS）热物性输运的抽象基类 / 运行时选择入口（字典分支名 `RAS`）。

## 适用条件（求解器 / 场 / 前提）

- **适用**: `fluid`、`multicomponentFluid`、`compressibleVoF`、相流体 TTM 等
- **前提**: `momentumTransport`.simulationType RAS`；`thermophysicalTransport` 使用 `RAS` { ... }`
- RTS `TypeName`("RAS")`

## 字典示例

```c++
// constant/thermophysicalTransport
RAS
{
    model           unityLewisEddyDiffusivity;
}
```

```c++
// constant/momentumTransport
simulationType RAS;
RAS
{
    model           kOmegaSST;
    turbulence      on;
}
```

## 参数表

| 关键字 | 含义 |
|--------|------|
| `model` | 具体 RAS 热输运模型（如 `eddyDiffusivity`、`unityLewisEddyDiffusivity`、`FickianEddyDiffusivity`） |
| `Prt` 等 | 由所选模型读取的湍流 Prandtl / Schmidt |

## 控制方程与关联式

Templated abstract base class for RAS thermophysical transport models（源码 Description）。

热通量通常含分子项 + 湍流扩散项（$\mu_t/\mathrm{Pr}_t$ 等），细节在派生模型页。

## 文献与源码依据

- [`src/ThermophysicalTransportModels/fluid/turbulence/RAS/RASThermophysicalTransportModel/RASThermophysicalTransportModel.H`](../../../src/ThermophysicalTransportModels/fluid/turbulence/RAS/RASThermophysicalTransportModel/RASThermophysicalTransportModel.H)
- 工厂：`src/ThermophysicalTransportModels/**/*ThermophysicalTransportModels.C`

## 教程与模板

- `tutorials/fluid/aerofoilNACA0012Steady/constant/thermophysicalTransport`（若存在）
- `tutorials/fluid/**/thermophysicalTransport`、`tutorials/multicomponentFluid/**/thermophysicalTransport`

## 注意事项

- 分支名是 `RAS`，不是类全名 `RASThermophysicalTransportModel`。
- 与动量 `simulationType` 不一致会导致 New 失败。
