# totalPressure

## 一句话
总压边界：按可压/不可压公式由 `p0` 与速度反算静压。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`totalPressure`
- **典型场**：p / p_rgh
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例

可压亚声速入口示例（关键字来自构造函数 / Usage）：

```cpp
inlet
{
    type            totalPressure;
    p0              uniform 1e5;   // [Pa] 或不可压 [m^2/s^2]
    // 可选场名与比热比：
    U               U;             // 默认 U
    phi             phi;           // 默认 phi
    rho             rho;           // 可压亚声速用密度场名；或 none
    psi             none;          // 跨声速/超声速用 psi；默认 none
    gamma           1.4;           // [-] Cp/Cv；跨声速=1，超声速>1
    value           uniform 1e5;   // [Pa]
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `U` | Velocity field name | no | U |
| `phi` | Flux field name | no | phi |
| `rho` | Density field name | no | rho |
| `psi` | Compressibility field name | no | none |
| `gamma` | (Cp/Cv) | no | 1 |
| `p0` | External pressure | yes |  |

## 控制方程与关联式
总压边界：按可压/不可压公式由 `p0` 与速度反算静压。

类头 `Description` 原文：

> Inflow, outflow and entrainment pressure boundary condition based on a
> constant total pressure assumption.
> 
> For outflow the patch pressure is set to the external static pressure.
> 
> For inflow the patch pressure is evaluated from the patch velocity and the
> external total pressure obtained from the external static pressure \c p_0
> and external velocity \c U_0 which is looked-up from the the optional \c
> tangentialVelocity entry in the \c pressureInletOutletVelocity velocity
> boundary condition for the patch if that boundary condition is used,
> otherwise \c U_0 is assumed zero and the external total pressure is equal to
> the external static pressure.
> 
> The patch pressure is evaluated from the external conditions using one of
> the following expressions depending on the flow conditions and
> specification of ratio of specific heats \c gamma:
> 
> 1. incompressible subsonic:
>     $$
>         p_p = p_0 + 0.5 |U_0|^2 - 0.5 |U|^2
>     $$
>     where
>     
>         p_p     | pressure at patch [m^2/s^2]
>         p_0     | external static pressure [m^2/s^2]
>         U       | velocity [m/s]
>         U_0     | external velocity [m/s]
>     
> 
> 2. compressible subsonic:
>     $$
>         p_p = p_0 + \rho (0.5 |U_0|^2 - 0.5 |U|^2)
>     $$
>     where
>     
>         p_p     | pressure at patch [Pa]
>         p_0     | external static pressure [Pa]
>         \rho    | density [kg/m^3]
>         U       | velocity [m/s]
>         U_0     | external velocity [m/s]
>     
> 
> 3. compressible transonic ($\gamma = 1$):
>     $$
>         p_p = \frac{p_0}{1 + \psi (0.5 |U|^2 - 0.5 |U_0|^2)}
>     $$
>     where
>     
>         p_p     | pressure at patch [Pa]
>         p_0     | external static pressure [Pa]
>         \psi    | compressibility [m^2/s^2]
>         \rho    | density [kg/m^3]
>         U       | velocity [m/s]
>         U_0     | external velocity [m/s]
>     
> 
> 4. compressible supersonic ($\gamma > 1$):
>     $$
>         p_p = \frac{p_0}
>               {(1 - G \psi (0.5 |U|^2 - 0.5 |U_0|^2))^{\frac{1}{G}}}
>     $$
>     where
>     
>         p_p     | pressure at patch [Pa]
>         p_0     | external static pressure [Pa]
>         \psi    | compressibility [m^2/s^2]
>         \rho    | density [kg/m^3]
>         G       | coefficient given by $\frac{\gamma - 1}{\gamma}$ []
>         \gamma  | ratio of specific heats (Cp/Cv) []
>         U       | velocity [m/s]
>         U_0     | external velocity [m/s]
>     
> 
> The modes of operation are set by the dimensions of the pressure field
> to which this boundary condition is applied, the \c psi entry and the value
> of \c gamma:
> \table
>     Mode                    | dimensions | psi   | gamma
>     incompressible subsonic | p/rho      |       |
>     compressible subsonic   | p          | none  |
>     compressible transonic  | p          | psi   | 1
>     compressible supersonic | p          | psi   | > 1
> \endtable

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/totalPressure/totalPressureFvPatchScalarField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/totalPressure/totalPressureFvPatchScalarField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/totalPressure/totalPressureFvPatchScalarField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/totalPressure/totalPressureFvPatchScalarField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/shockFluid/movingCone/0/p`](../../../tutorials/shockFluid/movingCone/0/p)
- [`tutorials/shockFluid/LadenburgJet60psi/0/p`](../../../tutorials/shockFluid/LadenburgJet60psi/0/p)
- [`tutorials/shockFluid/LadenburgJet60psi/0.orig/p`](../../../tutorials/shockFluid/LadenburgJet60psi/0.orig/p)
- [`tutorials/multicomponentFluid/verticalChannelSteady/0/p`](../../../tutorials/multicomponentFluid/verticalChannelSteady/0/p)
- [`tutorials/multicomponentFluid/membrane/0/p`](../../../tutorials/multicomponentFluid/membrane/0/p)
- [`tutorials/multicomponentFluid/DLR_A_LTS/0/p`](../../../tutorials/multicomponentFluid/DLR_A_LTS/0/p)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
