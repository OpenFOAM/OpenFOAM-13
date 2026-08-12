# bladeModel

## 一句话

转子盘叶片几何：按半径插值扭转角与弦长

## 适用条件（求解器 / 场 / 前提）

适用: `rotorDisk` 子组件（非独立 fvModel）

## 字典示例


> （由源码构造函数推断，无官方教程实例）

```c++
type bladeModel;
data    <value>;
```

## 参数表

主要入口以源码 `Usage` 为准。常见关键字见字典示例；完整列表与默认值见对应 `.H`。

| 说明 | |
|------|--|
| 选择关键字 | `type`（须与 RTS 注册名一致） |
| 配置位置 | 见适用条件 |

## 控制方程与关联式

摘自源码头文件 `Description`（原文）：

> Linear interpolated blade twist and chord based on radial position; Interpolation factor (for interpolating profile performance).

## 文献与源码依据

- 源码：[`src/fvModels/rotorDisk/bladeModel/bladeModel.H`](../../../src/fvModels/rotorDisk/bladeModel/bladeModel.H)

## 教程与模板

- `tutorials/incompressibleFluid/rotorDisk`

## 注意事项

- radius [m]；twist [deg]→内部 rad；chord [m]
