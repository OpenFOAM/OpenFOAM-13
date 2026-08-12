# sphericalHeatTransfer

## 一句话
Model which applies an analytical solution for heat transfer from the

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 界面传热（基类 `heatTransferModel`）
- **注册名**: `sphericalHeatTransfer`

## 字典示例
```
// 见源码 Usage；`type` 注册名为 `sphericalHeatTransfer`
sphericalHeatTransfer
{
    type    sphericalHeatTransfer;
    // ...
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `sphericalHeatTransfer`
- 基类: `heatTransferModel`


## 控制方程与关联式
Model which applies an analytical solution for heat transfer from the
surface of a sphere to the matter within the sphere.

## 文献与源码依据
- 类: `Foam`::heatTransferModels::sphericalHeatTransfer`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/heatTransferModels/sphericalHeatTransfer/sphericalHeatTransfer.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`sphericalHeatTransfer`。
