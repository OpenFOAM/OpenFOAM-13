# lumpedMassTemperature

## 一句话
集总热容固体/壁面温度（能量守恒 ODE）。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`lumpedMassTemperature`
- **典型场**：`T`
- **库 / 加载**：需 `libthermophysicalTransportModels`（`fluid`、`multicomponentFluid`、CHT 等）

## 字典示例
```
<patchName>
{
    type       lumpedMassTemperature;
    rho        1000;
    Cv         1300;
    T          500;
    Q          constant 0.5;
    value      uniform $T; // placeholder
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `rho` | density | yes |  |
| `Cv` | specific heat capacity | yes |  |
| `T` | temperature | yes |  |
| `Q` | power source | no | 0 |
| `volume` | volume of the lumped mass | no | calculated |

## 控制方程与关联式
集总热容固体/壁面温度（能量守恒 ODE）。

类头 `Description` 原文：

> This boundary condition is applied to a patch which bounds a solid body,
> wholly or partially.  It represents the body as a lumped mass, i.e. by a
> single temperature \c T which is fixed across the patch.  The body has a
> volume \c V which is either specified by the user, or is calculated when
> the patch describes a closed volume (including in 2D meshes). Starting from
> an initial, specified \c T, the change in temperature is calculated over
> time according to an applied power source \c Q and the heat transferred
> across the boundary $Q_{b}$ (positive into the lumped mass):
> 
>     $$
>          dT/dt = frac{Q + Q_{b}}{\rho C_{v} V}
>     $$
> 
> where
> 
>     Q      | specified power source [W]
>     Q_{b}  | total calculated heat transferred across the boundary [W]
>     \rho   | density [kg/m^3]
>     C_{v}  | specific heat capacity [J/(kg K)]
>     V      | volume of the lumped mass [m^3}
> \endtable

## 文献与源码依据
- 源码：[`src/ThermophysicalTransportModels/coupledThermophysicalTransportModels/lumpedMassTemperature/lumpedMassTemperatureFvPatchScalarField.C`](../../../src/ThermophysicalTransportModels/coupledThermophysicalTransportModels/lumpedMassTemperature/lumpedMassTemperatureFvPatchScalarField.C)
- 头文件：[`src/ThermophysicalTransportModels/coupledThermophysicalTransportModels/lumpedMassTemperature/lumpedMassTemperatureFvPatchScalarField.H`](../../../src/ThermophysicalTransportModels/coupledThermophysicalTransportModels/lumpedMassTemperature/lumpedMassTemperatureFvPatchScalarField.H)
- Inventory 备注：thermophysical transport BCs

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            lumpedMassTemperature`。

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
