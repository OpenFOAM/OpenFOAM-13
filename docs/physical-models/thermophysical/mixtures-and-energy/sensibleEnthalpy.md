# `sensibleEnthalpy`

## 一句话

感焓能量形式 he = hs

## 适用条件（求解器 / 场 / 前提）

- `thermoType`.energy sensibleEnthalpy;`
- 气体 `forGases`：`sensibleEnthalpy` / `sensibleInternalEnergy`；`forAbsoluteGases`：`absoluteEnthalpy`；固体 `forSolids`：仅 `sensibleInternalEnergy`

## 字典示例

```c++
thermoType
{
    energy          sensibleEnthalpy;
    // thermo / equationOfState 须与能量形式匹配
}
```

## 参数表

无额外字典参数（能量形式由类型选择）。

## 控制方程与关联式

Thermodynamics mapping class to expose the sensible enthalpy functions.

*---------------------------------------------------------------------------

## 文献与源码依据

- 源码：[`src/thermophysicalModels/specie/thermo/sensibleEnthalpy/sensibleEnthalpy.H`](../../../src/thermophysicalModels/specie/thermo/sensibleEnthalpy/sensibleEnthalpy.H)

## 教程与模板

- 几乎所有含能量方程的 `physicalProperties`

## 注意事项

- 选错 energy 会导致焓/内能求解变量不一致；绝对能量用于需要生成焓的化学路径。
