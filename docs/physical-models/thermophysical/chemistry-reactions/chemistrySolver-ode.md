# `ode`

## 一句话

ODE 化学求解器：用选定 ODESolver 积分刚性化学。

## 适用条件（求解器 / 场 / 前提）

- `chemistryType`.solver ode;`
- 适用: `multicomponentFluid` 等链接 `chemistryModel` 的求解器

## 字典示例

```c++
chemistryType
{
solver ode;
}
odeCoeffs
{
    solver          seulex;
    absTol          1e-8;
    relTol          1e-1;
}
```

## 参数表

| 关键字 | 含义 |
|--------|------|
| `odeCoeffs`.solver` | OpenFOAM `ODESolver` 名（如 `seulex`） |
| `absTol` / `relTol` | 绝对/相对容差 |

## 控制方程与关联式

An ODE solver for chemistry（源码 Description）。

## 文献与源码依据

- [`src/thermophysicalModels/chemistryModel/chemistrySolver/ode/ode.H`](../../../src/thermophysicalModels/chemistryModel/chemistrySolver/ode/ode.H)
- 注册：`odeChemistrySolvers`.C`（`forCoeffGases`/`forCoeffLiquids`）

## 教程与模板

- `tutorials/multicomponentFluid/counterFlowFlame2D_GRI/constant/chemistryProperties`

## 注意事项

- 需配合 `reactions` 机理；刚性机理对容差敏感。
