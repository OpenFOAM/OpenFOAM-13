# `laminarThermophysicalTransportModel`

## 一句话

层流热物性输运的抽象基类 / 运行时选择入口（字典分支名 `laminar`）。

## 适用条件（求解器 / 场 / 前提）

- **适用**: 带能量（及可选组分）方程且链接 TTM 的求解器
- **前提**: `momentumTransport`.simulationType laminar`；`thermophysicalTransport` 使用 `laminar` { ... }`
- RTS `TypeName`("laminar")`

## 字典示例

```c++
// constant/thermophysicalTransport
laminar
{
    model           Fourier;              // 单组分
    // model        unityLewisFourier;    // 多组分 Le=1
    // model        FickianFourier;       // 多组分 Fick + 傅里叶
    // model        MaxwellStefanFourier; // Maxwell–Stefan + 傅里叶
}
```

## 参数表

| 关键字 | 含义 |
|--------|------|
| `model` | 层流热/组分输运模型名 |
| 扩散系数表等 | 多组分模型在各自子字典中给出 |

## 控制方程与关联式

Templated abstract base class for laminar thermophysical transport models（源码 Description）。

无湍流涡扩散；热通量由 Fourier / 多组分扩散模型给出。

## 文献与源码依据

- [`src/ThermophysicalTransportModels/fluid/laminar/laminarThermophysicalTransportModel/laminarThermophysicalTransportModel.H`](../../../src/ThermophysicalTransportModels/fluid/laminar/laminarThermophysicalTransportModel/laminarThermophysicalTransportModel.H)

## 教程与模板

- `tutorials/fluid/**/thermophysicalTransport` 中 `laminar` 块
- `tutorials/multicomponentFluid/counterFlowFlame2D*/constant/thermophysicalTransport`

## 注意事项

- 单组分常用 `Fourier`；多组分不要误用仅单物种注册的模型。
- 固体区域用 `isotropic`/`anisotropic`，不走本流体 laminar 基类。
