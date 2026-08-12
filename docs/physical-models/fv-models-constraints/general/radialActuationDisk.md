# radialActuationDisk

## 一句话

径向变化致动盘

## 适用条件（求解器 / 场 / 前提）

适用: 流体求解器

## 字典示例



> （由源码构造函数推断，无官方教程实例）

```c++
radialActuationDisk1
    {
        type            radialActuationDisk;

        cellZone        radialActuationDisk1;

        U               U;              // Name of the velocity field

        diskDir         (-1 0 0);       // Disk direction
        Cp              0.1;            // Power coefficient
        Ct              0.5;            // Thrust coefficient
        diskArea        5.0;            // Disk area
        coeffs          (0.1 0.5 0.01); // Radial distribution coefficients
        upstreamPoint   (0 0 0);        // Upstream point
    }
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

> Actuation disk source including radial thrust
>
> Constant values for momentum source for actuation disk
>
>     $$
>         T = 2 \rho A U_{o}^2 a (1-a)
>     $$
>
> and
>
>     $$
>         U_1 = (1 - a)U_{o}
>     $$
>
> where:
> 
>     A   | disk area
>     U_o | upstream velocity
>     a   | 1 - Cp/Ct
>     U_1 | velocity at the disk
> 
>
> The thrust is distributed by a radial function:
>
>     $$
>         thrust(r) = T (C_0 + C_1 r^2 + C_2 r^4)
>     $$

## 文献与源码依据

- 源码：[`src/fvModels/general/radialActuationDisk/radialActuationDisk.H`](../../../../src/fvModels/general/radialActuationDisk/radialActuationDisk.H)
- 实现：同目录 `.C`

## 教程与模板

- `etc/caseDicts/fvModels/`
- 例：`tutorials/fluid/angledDuct`（porosity）、`tutorials/incompressibleFluid/rotorDisk`（转子类）

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
