# volumeBlockage

## 一句话

体积阻塞修正

## 适用条件（求解器 / 场 / 前提）

适用: 流体求解器

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

> This fvModel adds transport terms into the equations to account for the
> presence of a constant volume fraction. The volume fraction is read from
> constant/alpha.\<volumePhase\>, where \<volumePhase\> is given as a
> parameter to the fvModel. Both advective and diffusive terms are added, and
> the resulting solution is time-accurate. The flux and velocity are treated
> as superficial.
>
> This can be used to represent the effect of porous media that are caused
> purely by the reduction in volume of the fluid phase; i.e., additional
> volumeBlockage, and changes to transport and diffusion rates. It does not
> represent losses or transfers with the porous media. That requires separate
> sub-modelling.

## 文献与源码依据

- 源码：[`src/fvModels/general/volumeBlockage/volumeBlockage.H`](../../../../src/fvModels/general/volumeBlockage/volumeBlockage.H)
- 实现：同目录 `.C`

## 教程与模板

- `etc/caseDicts/fvModels/`
- 例：`tutorials/fluid/angledDuct`（porosity）、`tutorials/incompressibleFluid/rotorDisk`（转子类）

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
