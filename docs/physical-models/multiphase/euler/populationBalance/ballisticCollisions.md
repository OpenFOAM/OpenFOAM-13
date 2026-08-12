# ballisticCollisions

## 一句话
Model describing coagulation due to ballistic collisions. Utilises

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler（populationBalance）
- **族**: 聚并（基类 `coalescenceModel`）
- **注册名**: `ballisticCollisions`

## 字典示例
```
// 见源码 Usage；`type` 注册名为 `ballisticCollisions`
ballisticCollisions
{
    type    ballisticCollisions;
    // ...
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `ballisticCollisions`
- 基类: `coalescenceModel`


## 控制方程与关联式
Model describing coagulation due to ballistic collisions. Utilises
collisional diameters.

## 文献与源码依据
- 类: `Foam`::diameterModels::coalescenceModels::ballisticCollisions`
- 源码路径: `applications/modules/multiphaseEuler/populationBalance/coalescenceModels/ballisticCollisions/ballisticCollisions.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`ballisticCollisions`。
