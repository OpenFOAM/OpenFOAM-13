# profileModel

## 一句话

翼型升阻系数模型基类；常用 `lookup` / `series`

## 适用条件（求解器 / 场 / 前提）

适用: `rotorDisk` 的 `profiles` 列表

## 字典示例


> （由源码构造函数推断，无官方教程实例）

```c++
type profileModel;
file    <value>;
```

## 参数表

主要入口以源码 `Usage` 为准。常见关键字见字典示例；完整列表与默认值见对应 `.H`。

| 说明 | |
|------|--|
| 选择关键字 | `type`（须与 RTS 注册名一致） |
| 配置位置 | 见适用条件 |

## 控制方程与关联式

摘自源码头文件 `Description`（原文）：

> lookup：按迎角线性插值 Cd/Cl；series：级数展开（见 seriesProfile）。

## 文献与源码依据

- [`src/fvModels/rotorDisk/profileModel/`](../../../src/fvModels/rotorDisk/profileModel/)

## 教程与模板

- `tutorials/incompressibleFluid/rotorDisk`

## 注意事项

- 注册类型名为 `lookup` / `series`（类名 lookupProfile / seriesProfile）
