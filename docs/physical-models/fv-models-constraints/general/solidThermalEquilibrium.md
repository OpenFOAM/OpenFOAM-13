# solidThermalEquilibrium

## 一句话

固液热平衡源

## 适用条件（求解器 / 场 / 前提）

适用: 多孔/填料固体热耦合

## 字典示例



```c++
// `tutorials/fluid/blockedChannel/constant/fvModels`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

volumeBlockage
{
    type            volumeBlockage;
    volumePhase     volume;
}

solidBlockage
{
    type            volumeBlockage;
    volumePhase     solid;
}

solidThermalEquilibrium
{
    type            solidThermalEquilibrium;
    solidPhase      solid;
}

// ************************************************************************* //
```

## 参数表

主要入口以源码 `Usage` 为准。常见关键字见字典示例；完整列表与默认值见对应 `.H`。

| 说明 | |
|------|--|
| 配置位置 | 通常 `constant/fvModels` 或 `constant/fvConstraints` / `constant/dynamicMeshDict` |
| 选择关键字 | `type`（须与 RTS 注册名一致） |
| 区域选择 | 多数源/约束需要 `cellZone` 或等价选择 |


## 控制方程与关联式

摘自源码头文件 `Description`（原文）：

> This fvModel adds the thermal inertia of a solid phase into the energy
> equation. It assumes that the solid is in thermal equilibrium with the
> surrounding fluid phase.
>
> The volume fraction of the solid phase is read from
> constant/alpha.\<solidPhase\>, and the associated thermophysical properties
> are specified in constant/thermophysicalProperties.\<solidPhase\>.

## 文献与源码依据

- 源码：[`src/fvModels/general/solidThermalEquilibrium/solidThermalEquilibrium.H`](../../../../src/fvModels/general/solidThermalEquilibrium/solidThermalEquilibrium.H)
- 实现：同目录 `.C`

## 教程与模板

- `etc/caseDicts/fvModels/`
- 例：`tutorials/fluid/angledDuct`（porosity）、`tutorials/incompressibleFluid/rotorDisk`（转子类）

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
