# noLift

## 一句话
SourceFiles

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 升力（基类 `liftModel`）
- **注册名**: `noLift`

## 字典示例
```
// 见源码 Usage；`type` 注册名为 `noLift`
noLift
{
    type    noLift;
    // ...
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `noLift`
- 基类: `liftModel`


## 控制方程与关联式
SourceFiles
noLift.C

*---------------------------------------------------------------------------

## 文献与源码依据
- 类: `Foam`::liftModels::noLift`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/liftModels/noLift/noLift.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`noLift`。
