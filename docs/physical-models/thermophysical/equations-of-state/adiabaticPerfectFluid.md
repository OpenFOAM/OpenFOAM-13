# `adiabaticPerfectFluid`

## 一句话

绝热完全流体 EOS

## 适用条件（求解器 / 场 / 前提）

- **部件类型**：`equationOfState` = `adiabaticPerfectFluid`（字典中写短名时可能去掉后缀，见 `thermoType`）
- **合法宏组合**：`forLiquids`.H` / `forCoeffLiquids`
- **适用**: 使用 `fluidThermophysicalModels` / 多组分 / 固体 thermo 的求解器（见矩阵）
- 字典关键字常见写法：`equationOfState` adiabaticPerfectFluid;`（`perfectGas` 等）

## 字典示例

```c++
// constant/physicalProperties（节选）
thermoType
{
    type            heRhoThermo;   // 或 hePsiThermo 等
    mixture         pureMixture;
    transport       const;
    thermo          hConst;
    equationOfState adiabaticPerfectFluid;
    specie          specie;
    energy          sensibleEnthalpy;
}
```

## 参数表

详见源码头文件 `Usage` / 构造函数字典读取；多数 EOS 参数位于 `mixture` 子字典的 `equationOfState` { ... }` 或直接由 `specie`.molWeight` 推导（如 `perfectGas`）。

## 控制方程与关联式

Adiabatic perfect fluid equation of state for liquids:

```
rho = rho0*pow((p + B)/(p0 + B), 1/gamma)
```

Equivalent to the Murnaghan-Tait equation of state with different
coefficient specification.

Coefficient mixing is very inaccurate and not supported,
so this equation of state is not applicable to mixtures.

### Usage（源码头文件）

\table
Property     | Description
rho0         | Reference density
R            | Fluid constant
\endtable

Example specification of the adiabaticPerfectFluid equation of state
for LNG:
```
equationOfState
{
rho0            450;
p0              1e5;
gamma           15.4;
B               50000000
}
```

## 文献与源码依据

- 源码：[`src/thermophysicalModels/specie/equationOfState/adiabaticPerfectFluid/adiabaticPerfectFluid.H`](../../../src/thermophysicalModels/specie/equationOfState/adiabaticPerfectFluid/adiabaticPerfectFluid.H)
- 组合宏：`src/thermophysicalModels/specie/include/for*.H`

## 教程与模板

- `tutorials/XiFluid/stratified/constant/physicalProperties`
- `tutorials/XiFluid/moriyoshiHomogeneous/moriyoshiHomogeneous/constant/physicalProperties`
- `tutorials/XiFluid/kivaTest/constant/physicalProperties`
- `tutorials/XiFluid/engine2Valve2D/constant/physicalProperties`
- `tutorials/XiFluid/1D/constant/physicalProperties`

## 注意事项

- `thermoType`.equationOfState` 必须与当前 thermo 工厂（`psiThermos`/`rhoFluidThermos`/…）注册的组合一致，否则运行时报 unknown thermo 组合。
- 一句话：绝热完全流体 EOS
