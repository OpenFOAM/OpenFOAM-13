# Frank

## 一句话
Wall lubrication model of Frank.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 壁面润滑力（基类 `wallLubricationModel`）
- **注册名**: `Frank`

## 字典示例

> （由源码构造函数推断，无官方教程实例）

```cpp
// constant/momentumTransfer — wallLubrication 子字典
wallLubrication
{
    gas_dispersedIn_liquid
    {
        type            Frank;
        Cwd             10;       // [-]
        Cwc             5;        // [-]
        p               1.7;      // [-] 幂指数（lookup<scalar>）
    }
}
```

## 参数表

| 参数 | 默认 | 说明 |
|------|------|------|
| `Cwd` | （必填） | dimless |
| `Cwc` | （必填） | dimless |
| `p` | （必填） |  |

写在 `constant/momentumTransfer`（OpenFOAM-13）；相界面键名依 blending/相名；`<phasePair>` 键名依相名与 blending（如 `air_dispersedIn_water`）。

## 控制方程与关联式
Wall lubrication model of Frank.

References:
```
Otromke, M. (2013).
Implementation and Comparison of Correlations for interfacial Forces in
a Gas-Liquid System within an Euler-Euler Framework.
PhD Thesis.
```

```
Frank, T. (2005, April).
Advances in computational fluid dynamics (CFD) of 3-dimensional
gas-liquid multiphase flows.
In NAFEMS Seminar: Simulation of Complex Flows (CFD)-Applications and
Trends, Wiesbaden, Germany (pp. 1-18).
```

## 文献与源码依据
- 类: `Foam`::wallLubricationModels::Frank`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/wallLubricationModels/Frank/Frank.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`Frank`。
