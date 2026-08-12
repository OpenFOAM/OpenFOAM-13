# `icoPolynomial`

## 一句话

不可压多项式密度 ρ(T)

## 适用条件（求解器 / 场 / 前提）

- **部件类型**：`equationOfState` = `icoPolynomial`（字典中写短名时可能去掉后缀，见 `thermoType`）
- **合法宏组合**：存在于 specie 库；是否进入 RTS 取决于 `*Thermos.C` 是否调用对应 `for`*` 宏（部分 EOS 仅供专用路径）
- **适用**: 使用 `fluidThermophysicalModels` / 多组分 / 固体 thermo 的求解器（见矩阵）
- 字典关键字常见写法：`equationOfState` icoPolynomial;`（`perfectGas` 等）

## 字典示例

```c++
// constant/physicalProperties（节选）
thermoType
{
    type            heRhoThermo;   // 或 hePsiThermo 等
    mixture         pureMixture;
    transport       const;
    thermo          hConst;
    equationOfState icoPolynomial;
    specie          specie;
    energy          sensibleEnthalpy;
}
```

## 参数表

详见源码头文件 `Usage` / 构造函数字典读取；多数 EOS 参数位于 `mixture` 子字典的 `equationOfState` { ... }` 或直接由 `specie`.molWeight` 推导（如 `perfectGas`）。

## 控制方程与关联式

Incompressible, polynomial form of equation of state, using a polynomial
function for density.

Coefficient mixing is very inaccurate and not supported, so this equation of
state is not applicable to mixtures.

The polynomial expression is evaluated from:

```
rho = 1000 - 0.05*T + 0.003*sqr(T)
```

### Usage（源码头文件）

\table
Property     | Description
rhoCoeffs<8> | Density polynomial coefficients
\endtable

Example specification of the icoPolynomial equation of state:
```
equationOfState
{
rhoCoeffs<8>    ( 1000 -0.05 0.003 0 0 0 0 0 );
}
```

## 文献与源码依据

- 源码：[`src/thermophysicalModels/specie/equationOfState/icoPolynomial/icoPolynomial.H`](../../../src/thermophysicalModels/specie/equationOfState/icoPolynomial/icoPolynomial.H)
- 组合宏：`src/thermophysicalModels/specie/include/for*.H`

## 教程与模板

- `tutorials/XiFluid/stratified/constant/physicalProperties`
- `tutorials/XiFluid/moriyoshiHomogeneous/moriyoshiHomogeneous/constant/physicalProperties`
- `tutorials/XiFluid/kivaTest/constant/physicalProperties`
- `tutorials/XiFluid/engine2Valve2D/constant/physicalProperties`
- `tutorials/XiFluid/1D/constant/physicalProperties`

## 注意事项

- `thermoType`.equationOfState` 必须与当前 thermo 工厂（`psiThermos`/`rhoFluidThermos`/…）注册的组合一致，否则运行时报 unknown thermo 组合。
- 一句话：不可压多项式密度 ρ(T)
