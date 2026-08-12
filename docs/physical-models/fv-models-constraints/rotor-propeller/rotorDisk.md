# rotorDisk

## 一句话

旋翼盘动量源

## 适用条件（求解器 / 场 / 前提）

适用: 流体求解器；教程 incompressibleFluid/rotorDisk

## 字典示例



```c++
// `tutorials/incompressibleFluid/rotorDisk/constant/fvModels`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

disk
{
    type            rotorDisk;

    libs            ("librotorDisk.so");

    cellZone        rotatingZone;

    nBlades         3;      // Number of blades
    tipEffect       0.96;   // Normalised radius above which lift = 0

    inletFlowType   local;  // Inlet flow type specification
    inletVelocity   (0 1 0);

    geometryMode    specified;

    origin          (0 0 0);
    axis            (0 1 0);

    refDirection    (0 0 1);  // Reference direction
                              // - used as reference for psi angle
    omega           1000 [rpm];
    // pointAbove    (0 0 0.25);

    trimModel       fixedTrim;  // fixed || targetForce

    rhoRef          1000;
    rhoInf          1;

    fixedTrimCoeffs
    {
         theta0         0;
         theta1c        0;
         theta1s        0;
    }

    flapCoeffs
    {
        beta0           0;  // Coning angle [deg]
        beta1c          0;  // Lateral flapping coeff (cos coeff)
        beta2s          0;  // Longitudinal flapping coeff (sin coeff)
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

> Cell based momentum source which approximates the mean effects of
> rotor forces on a cylindrical region within the domain.

## 文献与源码依据

- 源码：[`src/fvModels/rotorDisk/rotorDisk.H`](../../../../src/fvModels/rotorDisk/rotorDisk.H)
- 实现：同目录 `.C`

## 教程与模板

- `tutorials/incompressibleFluid/rotorDisk`（`rotorDisk`）

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
