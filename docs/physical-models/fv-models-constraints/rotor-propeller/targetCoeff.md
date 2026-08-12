# targetCoeff

## 一句话

按目标推力/力矩（或系数）用 Newton–Raphson 反算旋翼配平桨距

## 适用条件（求解器 / 场 / 前提）

- 适用：`rotorDisk` 的 `trimModel`
- RTS 名：`targetCoeffTrim`（字典中通常写在 trim 子字典）

## 字典示例

> （由源码 `targetCoeffTrim::read` 推断，无完整官方教程副本）

```c++
// 位于 rotorDisk / trim 相关子字典
trimModel   targetCoeffTrim;   // 以 RTS TypeName 为准

targetCoeffTrimCoeffs   // 或实现使用的 coeffs 子字典名
{
    calcFrequency   10;     // 必填：每隔多少步配平一次

    target
    {
        useCoeffs   true;           // 默认 true；false 时读力/力矩绝对值
        thrustCoeff 0.005;          // useCoeffs=true → thrustCoeff/pitchCoeff/rollCoeff
        pitchCoeff  0;
        rollCoeff   0;
        // useCoeffs=false 时改为 thrust/pitch/roll
    }

    pitchAngles
    {
        theta0Ini   10;     // [deg] 总距初值
        theta1cIni  0;      // [deg]
        theta1sIni  0;      // [deg]
    }

    nIter       50;         // 可选，默认 50
    tol         1e-8;       // 可选
    relax       1.0;        // 可选
    dTheta      0.1;        // 可选 [deg]，差分步长
    alpha       1;          // 必填：力/力矩无量纲化系数
}
```

求解：$c^{\mathrm{old}}+J\cdot\mathrm{d}\theta=c^{\mathrm{target}}$，对 $\theta$（collective/roll/pitch）迭代。

## 参数表

| 参数 | 必需 | 默认 | 说明 |
|------|------|------|------|
| `calcFrequency` | 是 | — | 配平频率 |
| `target.useCoeffs` | 否 | true | 是否用无量纲系数 |
| `target.thrustCoeff` 等 | 是 | — | 目标；或 `thrust`/`pitch`/`roll` |
| `pitchAngles.theta0Ini` 等 | 是 | — | 初值 [deg] |
| `nIter`/`tol`/`relax`/`dTheta` | 否 | 50 / 1e-8 / 1 / 0.1° | 迭代控制 |
| `alpha` | 是 | — | 无量纲化系数 |

## 控制方程与关联式

Newton–Raphson 配平。若 `useCoeffs=true`：

$$
c_F=\frac{F}{\alpha\pi\rho\omega^2 R^4},\quad
c_M=\frac{M}{\alpha\pi\rho\omega^2 R^5}
$$

## 文献与源码依据

- [`src/fvModels/rotorDisk/trimModel/targetCoeff/targetCoeffTrim.C`](../../../../src/fvModels/rotorDisk/trimModel/targetCoeff/targetCoeffTrim.C)

## 教程与模板

- `tutorials/incompressibleFluid/rotorDisk`（请对照其实际 trim 段；可能为 `fixedTrim`）

## 注意事项

- TypeName 为 `targetCoeffTrim`；页面名 `targetCoeff` 是简称。
- `alpha` 在 `read` 中为必填 `lookup`，不能省略。
