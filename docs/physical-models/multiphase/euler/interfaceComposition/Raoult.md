# Raoult

## 一句话
Raoult's law of ideal mixing. A separate composition model is given for

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 界面组分平衡（基类 `interfaceCompositionModel`）
- **注册名**: `Raoult`

## 字典示例
```
// 见源码 Usage；`type` 注册名为 `Raoult`
Raoult
{
    type    Raoult;
    // ...
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `Raoult`
- 基类: `interfaceCompositionModel`


## 控制方程与关联式
Raoult's law of ideal mixing. A separate composition model is given for
each species. The composition of a species is equal to the value given by
the model scaled by the species fraction in the bulk of the other phase.

## 文献与源码依据
- 类: `Foam`::interfaceCompositionModels::Raoult`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/interfaceCompositionModels/Raoult/Raoult.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`Raoult`。
