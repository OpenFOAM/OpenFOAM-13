# `none` (chemistrySolver)`

## 一句话

关闭化学积分（`TypeName`("none")`）。

## 适用条件（求解器 / 场 / 前提）

- `chemistryType`.solver none;`

## 字典示例

```c++
chemistryType
{
solver none;
}
```

## 参数表

无额外参数。

## 控制方程与关联式

空操作化学求解器；组分源项不积分。

## 文献与源码依据

- [`src/thermophysicalModels/chemistryModel/chemistrySolver/noChemistrySolver/noChemistrySolver.H`](../../../src/thermophysicalModels/chemistryModel/chemistrySolver/noChemistrySolver/noChemistrySolver.H)

## 教程与模板

- 调试或冻结化学时使用

## 注意事项

- 与 `tabulation`.method none`、`reduction`.method none` 分属不同配置层。
