# `perfectGas`

## 一句话

理想气体 EOS：ρ = p/(R T)

## 适用条件（求解器 / 场 / 前提）

- **部件类型**：`equationOfState` = `perfectGas`（字典中写短名时可能去掉后缀，见 `thermoType`）
- **合法宏组合**：`forGases`.H` / `forCoeffGases`（气体）; `forAbsoluteGases`.H`（绝对焓气体）
- **适用**: 使用 `fluidThermophysicalModels` / 多组分 / 固体 thermo 的求解器（见矩阵）
- 字典关键字常见写法：`equationOfState` perfectGas;`（`perfectGas` 等）

## 字典示例

```c++
// 改编自 tutorials/fluid/aerofoilNACA0012Steady/constant/physicalProperties
thermoType
{
    type            hePsiThermo;
    mixture         pureMixture;
    transport       const;
    thermo          hConst;
    equationOfState perfectGas;
    specie          specie;
    energy          sensibleEnthalpy;
}
mixture
{
    specie { molWeight 28.9; }
    thermodynamics { Cp 1005; hf 0; }
    transport { mu 1.82e-05; Pr 0.71; }
}
```

## 参数表

详见源码头文件 `Usage` / 构造函数字典读取；多数 EOS 参数位于 `mixture` 子字典的 `equationOfState` { ... }` 或直接由 `specie`.molWeight` 推导（如 `perfectGas`）。

## 控制方程与关联式

Perfect gas equation of state:

```
rho = p/(R*T)
```

### Usage（源码头文件）

理想气体常数 $R$ 由组分/混合物分子量直接得到，一般**不必**在 `mixture` 中再写 `equationOfState` 子字典。

## 文献与源码依据

- 源码：[`src/thermophysicalModels/specie/equationOfState/perfectGas/perfectGas.H`](../../../src/thermophysicalModels/specie/equationOfState/perfectGas/perfectGas.H)
- 组合宏：`src/thermophysicalModels/specie/include/for*.H`

## 教程与模板

- `tutorials/XiFluid/stratified/constant/physicalProperties`
- `tutorials/XiFluid/moriyoshiHomogeneous/moriyoshiHomogeneous/constant/physicalProperties`
- `tutorials/XiFluid/kivaTest/constant/physicalProperties`
- `tutorials/XiFluid/engine2Valve2D/constant/physicalProperties`
- `tutorials/XiFluid/1D/constant/physicalProperties`

## 注意事项

- `thermoType`.equationOfState` 必须与当前 thermo 工厂（`psiThermos`/`rhoFluidThermos`/…）注册的组合一致，否则运行时报 unknown thermo 组合。
- 一句话：理想气体 EOS：ρ = p/(R T)
