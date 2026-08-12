# uniformBinary

## 一句话
Daughter size distribution for uniform binary breakup.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler（populationBalance）
- **族**: 子粒径分布（基类 `daughterSizeDistributionModel`）
- **注册名**: `uniformBinary`

## 字典示例
```
// 见源码 Usage；`type` 注册名为 `uniformBinary`
uniformBinary
{
    type    uniformBinary;
    // ...
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `uniformBinary`
- 基类: `daughterSizeDistributionModel`


## 控制方程与关联式
Daughter size distribution for uniform binary breakup.

## 文献与源码依据
- 类: `Foam`::diameterModels::daughterSizeDistributionModels::uniformBinary`
- 源码路径: `applications/modules/multiphaseEuler/populationBalance/daughterSizeDistributionModels/uniformBinary/uniformBinary.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`uniformBinary`。
