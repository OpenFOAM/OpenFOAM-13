# `DAC`

## 一句话

Dynamic Adaptive Chemistry 降维（基于 DRGEP 型 rAB）。

## 适用条件（求解器 / 场 / 前提）

- `reduction` { method ...; }`（TDAC）
- 适用: `multicomponentFluid` + `chemistry` on`
- 总览：[chemistry-overview](chemistry-overview.md)

## 字典示例

```c++
reduction
{
    method      DAC;
    tolerance   1e-4;
    initialSet ( CO CH4 HO2 );  // 多数方法需要
}
```

## 参数表

| 关键字 | 含义 |
|--------|------|
| `method` | 降维方法名 |
| `tolerance` | 方法相关容差 |
| `initialSet` | 搜索起始物种（SIS） |

## 控制方程与关联式

见源码 `DAC`.H` Description（含 rAB 定义与文内参考文献编号 [1][2][3]）。

## 文献与源码依据

- [`src/thermophysicalModels/chemistryModel/chemistryModel/reduction/DAC/DAC.H`](../../../src/thermophysicalModels/chemistryModel/chemistryModel/reduction/DAC/DAC.H)

## 教程与模板

- `etc/caseDicts/solvers/chemistry/TDAC/chemistryProperties.cfg`
- `tutorials/multicomponentFluid/counterFlowFlame2D_GRI_TDAC/`

## 注意事项

- 完整燃烧/反应速率见 Phase 4；本页仅降维入口。
