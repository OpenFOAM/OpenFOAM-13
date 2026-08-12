# externalCoupledTemperatureMixed

## 一句话
温度相关边界条件。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`externalCoupledTemperatureMixed`
- **RTS `TypeName`**：`externalCoupledTemperature`（与字典名不同时以字典 `type` 为准）
- **典型场**：`T`
- **库 / 加载**：需 `libthermophysicalTransportModels`（`fluid`、`multicomponentFluid`、CHT 等）

## 字典示例
```
# Patch: <patch name>
    <magSf1> <value1> <qDot1> <htc1>
    <magSf2> <value2> <qDot2> <htc2>
    <magSf3> <value3> <qDot3> <htc2>
    ...
    <magSfN> <valueN> <qDotN> <htcN>
# Patch: <patch name>
    <value1> <gradient1> <valueFraction1>
    <value2> <gradient2> <valueFraction2>
    <value3> <gradient3> <valueFraction3>
    ...
    <valueN> <gradientN> <valueFractionN>
$FOAM_CASE/<commsDir>
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `commsDir` | communications directory | yes |  |
| `file` | transfer file name | yes |  |
| `waitInterval` | interval [s] between file checks | no | 1 |
| `timeOut` | time after which error invoked [s] | no | 100*waitInterval |
| `calcFrequency` | calculation frequency | no | 1 |
| `log` | log program control | no | no |

## 控制方程与关联式
温度相关边界条件。

类头 `Description` 原文：

> This boundary condition provides a temperature interface to an external
> application.  Values are transferred as plain text files, where OpenFOAM
> data is written as:
> 
> 
>     # Patch: <patch name>
>     <magSf1> <value1> <qDot1> <htc1>
>     <magSf2> <value2> <qDot2> <htc2>
>     <magSf3> <value3> <qDot3> <htc2>
>     ...
>     <magSfN> <valueN> <qDotN> <htcN>
> 
> 
> and received as the constituent pieces of the `mixed`' condition, i.e.
> 
> 
>     # Patch: <patch name>
>     <value1> <gradient1> <valueFraction1>
>     <value2> <gradient2> <valueFraction2>
>     <value3> <gradient3> <valueFraction3>
>     ...
>     <valueN> <gradientN> <valueFractionN>
> 
> 
> Data is sent/received as a single file for all patches from the directory
> 
> 
>     $FOAM_CASE/<commsDir>
> 
> 
> At start-up, the boundary creates a lock file, i.e..
> 
> 
>     OpenFOAM.lock
> 
> 
> ... to signal the external source to wait.  During the boundary condition
> update, boundary values are written to file, e.g.
> 
> 
>     <fileName>.out
> 
> 
> The lock file is then removed, instructing the external source to take
> control of the program execution.  When ready, the external program
> should create the return values, e.g. to file
> 
> 
>     <fileName>.in
> 
> 
> ... and then re-instate the lock file.  The boundary condition will then
> read the return values, and pass program execution back to OpenFOAM.

## 文献与源码依据
- 源码：[`src/ThermophysicalTransportModels/fluid/derivedFvPatchFields/externalCoupledTemperatureMixed/externalCoupledTemperatureMixedFvPatchScalarField.C`](../../../src/ThermophysicalTransportModels/fluid/derivedFvPatchFields/externalCoupledTemperatureMixed/externalCoupledTemperatureMixedFvPatchScalarField.C)
- 头文件：[`src/ThermophysicalTransportModels/fluid/derivedFvPatchFields/externalCoupledTemperatureMixed/externalCoupledTemperatureMixedFvPatchScalarField.H`](../../../src/ThermophysicalTransportModels/fluid/derivedFvPatchFields/externalCoupledTemperatureMixed/externalCoupledTemperatureMixedFvPatchScalarField.H)
- Inventory 备注：thermophysical transport BCs

## 教程与模板
- [`tutorials/fluid/externalCoupledCavity/0/T`](../../../tutorials/fluid/externalCoupledCavity/0/T)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
