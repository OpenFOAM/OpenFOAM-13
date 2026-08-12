# sphericalDiffusiveMassTransfer

## 一句话
Model which applies an analytical solution for mass transfer from the

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 扩散传质（基类 `diffusiveMassTransferModel`）
- **注册名**: `sphericalDiffusiveMassTransfer`

## 字典示例
```
// 见源码 Usage；`type` 注册名为 `sphericalDiffusiveMassTransfer`
sphericalDiffusiveMassTransfer
{
    type    sphericalDiffusiveMassTransfer;
    // ...
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `sphericalDiffusiveMassTransfer`
- 基类: `diffusiveMassTransferModel`


## 控制方程与关联式
Model which applies an analytical solution for mass transfer from the
surface of a sphere to the fluid within the sphere.

## 文献与源码依据
- 类: `Foam`::diffusiveMassTransferModels::sphericalDiffusiveMassTransfer`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/diffusiveMassTransferModels/sphericalDiffusiveMassTransfer/sphericalDiffusiveMassTransfer.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`sphericalDiffusiveMassTransfer`。
