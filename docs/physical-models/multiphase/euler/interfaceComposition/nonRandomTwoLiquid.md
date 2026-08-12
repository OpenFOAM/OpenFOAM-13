# nonRandomTwoLiquid

## 一句话
Non ideal law for the mixing of two species. A separate composition model

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 界面组分平衡（基类 `interfaceCompositionModel`）
- **注册名**: `nonRandomTwoLiquid`

## 字典示例


> （由源码构造函数推断，无官方教程实例）

```c++
// constant/phaseProperties — interfaceComposition 子字典
interfaceComposition
{
    <phasePair>
    {
        type            nonRandomTwoLiquid;
        // 本模型 ctor 无额外系数（可能继承基类 residual*）
    }
}
```

## 参数表

| 参数 | 说明 |
|------|------|
| `type` | 必须为 `nonRandomTwoLiquid` |
| （基类） | 部分模型继承 `residualRe` / `residualAlpha` 等，见对应基类 ctor |

本模型构造函数通常无额外专用系数。

## 控制方程与关联式
Non ideal law for the mixing of two species. A separate composition model
is given for each species. The composition of a species is equal to the
value given by the model, scaled by the species fraction in the bulk of the
other phase, and multiplied by the activity coefficient for that species.
The gas behaviour is assumed ideal; i.e. the fugacity coefficient is taken
as equal to 1.

## 文献与源码依据
- 类: `Foam`::interfaceCompositionModels::nonRandomTwoLiquid`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/interfaceCompositionModels/nonRandomTwoLiquid/nonRandomTwoLiquid.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`nonRandomTwoLiquid`。
