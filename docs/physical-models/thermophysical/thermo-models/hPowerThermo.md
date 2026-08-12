# `hPowerThermo`

## 一句话

幂律形式比热/焓热力学模型（`hPowerThermo`），用于部分专用拼装；固体侧对应 `ePowerThermo`（见 `forSolids`）。

## 适用条件（求解器 / 场 / 前提）

- 类位于 `src/thermophysicalModels/specie/thermo/hPower/`
- **注意**：默认 `forGases`/`forLiquids`/`forTabulated` **未**注册 `hPowerThermo`；`forSolids` 注册的是 **`ePowerThermo`**
- 若案例 `thermo` hPower` 报错，说明当前工厂未 `makeThermo` 该组合

## 字典示例

```c++
// 仅当对应工厂已注册时可用
thermoType
{
    thermo          hPower;
    energy          sensibleEnthalpy;
    // ...
}
```

## 参数表

见源码头文件 `Usage` / `mixture`.thermodynamics`（幂律系数）。

## 控制方程与关联式

幂律 $c_p(T)$（或等效焓积分）形式；细节以 [`hPowerThermo`.H`](../../../src/thermophysicalModels/specie/thermo/hPower/hPowerThermo.H) Description 为准。

## 文献与源码依据

- `src/thermophysicalModels/specie/thermo/hPower/hPowerThermo.H`
- 固体对照：[`ePowerThermo`](ePowerThermo.md)、`forSolids`.H`

## 教程与模板

- 官方教程极少直接使用；优先查是否被自定义 `*Thermos.C` 注册

## 注意事项

- 与已注册的 `ePowerThermo`（固体）不要混淆能量形式（h vs e）。
