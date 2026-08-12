# `LESThermophysicalTransportModel`

## 一句话

LES 热物性输运的抽象基类 / 运行时选择入口（字典分支名 `LES`）。

## 适用条件（求解器 / 场 / 前提）

- **适用**: `fluid`、`multicomponentFluid`、`compressibleVoF`、相流体 TTM 等已链接 `ThermophysicalTransportModels` 的求解器
- **前提**: `constant/momentumTransport` 中 `simulationType` LES`；`thermophysicalTransport` 使用同名 `LES` { ... }` 块
- 用户通常不写 C++ 类名，而是写 `simulationType` 隐含的分支 + 具体 `model`（如 `unityLewisEddyDiffusivity`）
- RTS `TypeName`("LES")`：见源码头文件

## 字典示例

```c++
// constant/thermophysicalTransport
LES
{
    model           unityLewisEddyDiffusivity;  // 或多组分 FickianEddyDiffusivity 等
    // 系数如 Prt 在模型子字典 / 默认值中
}
```

须与动量侧一致，例如：

```c++
// constant/momentumTransport
simulationType LES;
LES
{
    model           WALE;
    delta           cubeRootVol;
    turbulence      on;
}
```

## 参数表

| 关键字 | 含义 |
|--------|------|
| `model` | 具体 LES 热输运模型名（注册于 `*ThermophysicalTransportModels.C`） |
| 模型系数 | 由所选 `model` 读取（常见 `Prt`） |

## 控制方程与关联式

Templated abstract base class for LES thermophysical transport models（源码 Description）。

具体热通量 / 扩散通量由派生 `model` 提供；本类负责从 `momentumTransport` 取得湍流粘度等场并转发选择。

## 文献与源码依据

- [`src/ThermophysicalTransportModels/fluid/turbulence/LES/LESThermophysicalTransportModel/LESThermophysicalTransportModel.H`](../../../src/ThermophysicalTransportModels/fluid/turbulence/LES/LESThermophysicalTransportModel/LESThermophysicalTransportModel.H)
- 工厂：`src/ThermophysicalTransportModels/fluidThermo/fluidThermoThermophysicalTransportModels.C` 等（`make`*ThermophysicalTransport*`）

## 教程与模板

- `tutorials/incompressibleFluid/channel395/constant/momentumTransport`（LES；热输运视案例是否有能量方程）
- `tutorials/fluid/**`、`tutorials/multicomponentFluid/**` 中带 `thermophysicalTransport` 且 `LES` 的案例

## 注意事项

- `thermophysicalTransport` 的顶层分支必须与 `momentumTransport`.simulationType` 同为 `LES`，否则构造失败。
- 不要把 `LESThermophysicalTransportModel` 当作字典 `type` 字符串写入案例。
