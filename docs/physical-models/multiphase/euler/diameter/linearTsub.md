# linearTsub

## 一句话
Vapour bubble diameter model for modelling of condensation of vapour

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 相直径模型（基类 `diameterModel`）
- **注册名**: `linearTsub`

## 字典示例
```
// 见源码 Usage；`type` 注册名为 `linearTsub`
linearTsub
{
    type    linearTsub;
    // ...
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `linearTsub`
- 基类: `diameterModel`


## 控制方程与关联式
Vapour bubble diameter model for modelling of condensation of vapour
bubbles. Calculates bubble diameter as a linear function of liquid phase
subcooling.

Reference:
```
Anglart, H., Nylund, O., Kurul, N., & Podowski, M. Z. (1997).
CFD prediction of flow and phase distribution in fuel assemblies with
spacers.
Nuclear Engineering and Design, 177(1-3), 215-228.
```

## 文献与源码依据
- 类: `Foam`::linearTsub`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/diameterModels/linearTsubDiameter/linearTsubDiameter.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`linearTsub`。
