# actuationDisk

## 一句话

致动盘动量源

## 适用条件（求解器 / 场 / 前提）

适用: 流体求解器；风电/推进近似

## 字典示例



```c++
// `tutorials/incompressibleFluid/turbineSiting/constant/fvModels`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

disk1
{
    type            actuationDisk;

    cellZone        actuationDisk1;

    diskDir         (1 0 0);    // Orientation of the disk
    Cp              0.386;
    Ct              0.58;
    diskArea        40;
    upstreamPoint   (581849 4785810 1065);
}

disk2
{
    type            actuationDisk;

    cellZone        actuationDisk2;

    diskDir         (1 0 0);    // Orientation of the disk
    Cp              0.53;
    Ct              0.58;
    diskArea        40;
    upstreamPoint   (581753 4785663 1070);
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

> Actuation disk source
>
> Constant values for momentum source for actuation disk
> $$
>     T = 2 \rho A (\hat{d}\dot U_{o})^2 a (1-a) \hat{d}
> $$
>
> where:
> 
>     A    | Disk area
>     dHat | Unit disk direction
>     U_o  | Upstream velocity
>     a    | 1 - Cp/Ct
>     Cp   | Power coefficient
>     Ct   | Thrust coefficient
> 

## 文献与源码依据

- 源码：[`src/fvModels/general/actuationDisk/actuationDisk.H`](../../../../src/fvModels/general/actuationDisk/actuationDisk.H)
- 实现：同目录 `.C`

## 教程与模板

- `etc/caseDicts/fvModels/`
- 例：`tutorials/fluid/angledDuct`（porosity）、`tutorials/incompressibleFluid/rotorDisk`（转子类）

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
