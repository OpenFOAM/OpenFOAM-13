# fixed

## 一句话

Fixed trim coefficients

## 适用条件（求解器 / 场 / 前提）

适用: rotorDisk trimModel

## 字典示例



```c++
// `tutorials/incompressibleFluid/rotorDisk/constant/fvModels`
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

    blade
    {
        data
        (
            (profile1 (0.1 -6 0.02))
            (profile1 (0.25 -6 0.02))
        );
    }

    profiles
    {
        profile1
        {
            type lookup;
            data
            (
                (-90 0.21 1.45)
                (-18 0.21 1.45)
                (-16 0.165 1.3)
                (-14 0.125 1.1)
                (-12 0.092 0.95)
```

## 参数表

主要入口以源码 `Usage` 为准。常见关键字见字典示例；完整列表与默认值见对应 `.H`。

| 说明 | |
|------|--|
| 选择关键字 | `type`（须与 RTS 注册名一致） |
| 配置位置 | 见适用条件 |

## 控制方程与关联式

摘自源码头文件 `Description`（原文）：

> Fixed trim coefficients

## 文献与源码依据

- 源码：[`src/fvModels/rotorDisk/trimModel/fixed/fixedTrim.H`](../../../../src/fvModels/rotorDisk/trimModel/fixed/fixedTrim.H)
- 实现：同目录 `.C`

## 教程与模板

- `tutorials/incompressibleFluid/rotorDisk`

## 注意事项

- 由 `trimModel` 关键字选择
