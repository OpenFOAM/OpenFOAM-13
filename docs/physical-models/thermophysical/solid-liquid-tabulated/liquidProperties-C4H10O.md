# `C4H10O`

## 一句话

预置液体物性库条目 `C4H10O`（`liquidProperties` RTS）。

## 适用条件（求解器 / 场 / 前提）

- 适用: `liquidThermo` 路径、Lagrangian 蒸发、需要 `liquidProperties` 选择器的模型
- 通过 `liquidPropertiesSelector` / `type` <name>;` 选择

## 字典示例

```c++
// 典型：liquidThermo 或 liquidProperties 子字典
<name>  // 或 type C4H10O;
// 具体关键字见 liquidThermos.C / liquidPropertiesSelector
```

## 参数表

预置关联式系数；一般无需用户改字典（可覆盖时见源码构造）。

## 控制方程与关联式

diEthylEther

## 文献与源码依据

- [`src/thermophysicalModels/thermophysicalProperties/liquidProperties/C4H10O/C4H10O.H`](../../../src/thermophysicalModels/thermophysicalProperties/liquidProperties/C4H10O/C4H10O.H)

## 教程与模板

- `src/thermophysicalModels/basic/liquidThermo/liquidThermos.C`

## 注意事项

- 名称大小写敏感；与化学组分名不一定相同。
