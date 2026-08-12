# `reactionRates`

## 一句话

functionObject：`reactionRates`。

## 适用条件（求解器 / 场 / 前提）

- 在 `system/controlDict` / `functions` 中启用

## 字典示例

```c++
functions
{
    reactionRates
    {
        type reactionRates;
        libs ("libchemicalFunctionObjects.so"); // 以实际 Make 为准
    }
}
```

## 参数表

见源码。

## 控制方程与关联式

Writes volume averaged reaction rates in [kmol/m^3/s] for
each reaction into the file \<timeDir\>/reactionRates.dat

Example of function object specification:
```
reactionRates1
{
type            reactionRates;
libs            ("libchemistryModel.so");

cellZone        all; // Or points, cellSet, cellZone

//phase         <phaseName>; // Optional name of the phase

//writeFields   false; // Optionally also write the rate fields. Note
// that this can create a lot of data.
}
```

See also
Foam::functionObjects::fvMeshFunctionObject
Foam::fvCellZone
Foam::functionObjects::logFiles

## 文献与源码依据

- [`src/thermophysicalModels/chemistryModel/functionObjects/reactionRates/reactionRates.H`](../../../src/thermophysicalModels/chemistryModel/functionObjects/reactionRates/reactionRates.H)

## 教程与模板

- 多组分/化学教程的 `functions`

## 注意事项

- 库名以模块链接为准。
