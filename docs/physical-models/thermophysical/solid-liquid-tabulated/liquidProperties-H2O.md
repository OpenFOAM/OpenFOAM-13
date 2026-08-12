# `H2O`

## 一句话

预置液体物性库条目 `H2O`（`liquidProperties` RTS）：水的密度、饱和蒸汽压、焓、粘度、导热、表面张力等用 NSRDS/API 函数给出。

## 适用条件（求解器 / 场 / 前提）

- **适用**: `liquidThermo` 路径、Lagrangian 蒸发/沸腾、表面张力可引用 `liquidProperties` 的 VoF/欧拉模型
- 通过 `liquidProperties` 选择器：`type` H2O;`（或等价命名构造）
- **不适用**: 仅用 `thermoType`+`pureMixture` 拼装理想气体的常规 `fluid` 气体案例（那是另一条路径）

## 字典示例

```c++
// liquidProperties / liquidThermo 相关子字典
type    H2O;
```

## 参数表

预置关联式（源码成员）：`rho_`（NSRDS5）、`pv_`、`hl_`、`Cp_`、`h_`、`mu_`、`kappa_`、`sigma_`、`D_`（`APIdiffCoef`）等；一般无需用户改字典。

## 控制方程与关联式

water（源码 Description）。各物性为温度（及部分压力）的经验关联式，实现见 `H2O`.C`。

## 文献与源码依据

- [`src/thermophysicalModels/thermophysicalProperties/liquidProperties/H2O/H2O.H`](../../../src/thermophysicalModels/thermophysicalProperties/liquidProperties/H2O/H2O.H)
- 工厂：`src/thermophysicalModels/basic/liquidThermo/liquidThermos.C`

## 教程与模板

- `tutorials/**` 中含 `liquidProperties` / `H2O` 的蒸发、沸腾、VoF 表面张力案例
- 同族其它液体见本目录 `liquidProperties`-*.md`

## 注意事项

- 名称大小写敏感；与多组分化学机理里的 `H2O` 物种名不是同一套 RTS。
- 与 `thermoType`+`rhoConst` 液体拼装不同——本页是预置库路径。
