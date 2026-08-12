# `reaction`（概览）

## 一句话

OpenFOAM 反应机理中的单步/基元反应描述与系数结构（`reaction` / `specieCoeffs` / `specieExponent`），供化学求解读取。

## 适用条件（求解器 / 场 / 前提）

- 适用: `multicomponentFluid`、带反应的 `multiphaseEuler`、燃烧相关案例
- 配置通常在 `constant/reactions`（或机理文件）+ `chemistryProperties`
- Phase 1 仅给结构概览；反应速率形式全谱见 Phase 4

## 字典示例

```c++
// 示意：reactions 文件中的一条不可逆 Arrhenius 反应（以教程为准）
reactions
{
    methaneReaction
    {
        type     irreversibleArrheniusReaction;
        reaction "CH4 + 2O2 = CO2 + 2H2O";
        A        5.2e16;
        beta     0;
        Ta       14906;
    }
}
```

## 参数表

| 概念 | 含义 |
|------|------|
| `specieCoeffs` | 反应物/生成物化学计量系数 |
| `specieExponent` | 速率表达式中的浓度指数（可与计量数不同） |
| `reaction` | 反应字符串与类型包装 |

## 控制方程与关联式

基元反应速率一般写为 Arrhenius 型或第三方库导入形式；具体 `type` 名以 `src/thermophysicalModels/specie/reaction/` 与 combustion 库 RTS 为准（Phase 4 展开）。

## 文献与源码依据

- `src/thermophysicalModels/specie/reaction/`
- 清单备注见 [`../../_inventory/rts-thermos.md`](../../_inventory/rts-thermos.md)

## 教程与模板

- `tutorials/multicomponentFluid/counterFlowFlame*`
- `tutorials/multiphaseEuler/*Reacting*`

## 注意事项

- 反应 `type` 必须与已链接的 chemistry/combustion 库一致。
- 热力学必须用兼容的多组分 `thermoType`（常需 JANAF + 绝对/感焓策略按案例）。
