# `rPolynomial`

## 一句话

倒数多项式密度（液体常用）

## 适用条件（求解器 / 场 / 前提）

- **部件类型**：`equationOfState` = `rPolynomial`（字典中写短名时可能去掉后缀，见 `thermoType`）
- **合法宏组合**：`forLiquids`.H` / `forCoeffLiquids`
- **适用**: 使用 `fluidThermophysicalModels` / 多组分 / 固体 thermo 的求解器（见矩阵）
- 字典关键字常见写法：`equationOfState` rPolynomial;`（`perfectGas` 等）

## 字典示例

```c++
// constant/physicalProperties（节选）
thermoType
{
    type            heRhoThermo;   // 或 hePsiThermo 等
    mixture         pureMixture;
    transport       const;
    thermo          hConst;
    equationOfState rPolynomial;
    specie          specie;
    energy          sensibleEnthalpy;
}
```

## 参数表

详见源码头文件 `Usage` / 构造函数字典读取；多数 EOS 参数位于 `mixture` 子字典的 `equationOfState` { ... }` 或直接由 `specie`.molWeight` 推导（如 `perfectGas`）。

## 控制方程与关联式

Reciprocal polynomial equation of state for liquids and solids

```
1/rho = C[0] + C[1]*T + C[2]*sqr(T) - C[3]*p - C[4]*p*T
```

This polynomial for the reciprocal of the density provides a much better fit
than the equivalent polynomial for the density and has the advantage that it
support coefficient mixing to support liquid and solid mixtures in an
efficient manner.

### Usage（源码头文件）

\table
Property     | Description
C            | Density polynomial coefficients
\endtable

Example specification of the rPolynomial equation of state for pure water:
```
equationOfState
{
C (0.001278 -2.1055e-06 3.9689e-09 4.3772e-13 -2.0225e-16);
}
```
Note: This fit is based on the small amount of data which is freely
available for the range 20-65degC and 1-100bar.

## 文献与源码依据

- 源码：[`src/thermophysicalModels/specie/equationOfState/rPolynomial/rPolynomial.H`](../../../src/thermophysicalModels/specie/equationOfState/rPolynomial/rPolynomial.H)
- 组合宏：`src/thermophysicalModels/specie/include/for*.H`

## 教程与模板

- `tutorials/XiFluid/stratified/constant/physicalProperties`
- `tutorials/XiFluid/moriyoshiHomogeneous/moriyoshiHomogeneous/constant/physicalProperties`
- `tutorials/XiFluid/kivaTest/constant/physicalProperties`
- `tutorials/XiFluid/engine2Valve2D/constant/physicalProperties`
- `tutorials/XiFluid/1D/constant/physicalProperties`

## 注意事项

- `thermoType`.equationOfState` 必须与当前 thermo 工厂（`psiThermos`/`rhoFluidThermos`/…）注册的组合一致，否则运行时报 unknown thermo 组合。
- 一句话：倒数多项式密度（液体常用）
