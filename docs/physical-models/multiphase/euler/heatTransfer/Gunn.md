# Gunn

## 一句话
Gunn (1978) correlation for fixed and fluidised beds with Re < 10^5

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 界面传热（基类 `heatTransferModel`）
- **注册名**: `Gunn`

## 字典示例


> （由源码构造函数推断，无官方教程实例）

```c++
// constant/heatTransfer — heatTransfer 子字典
heatTransfer
{
    <phasePair>
    {
        type            Gunn;
        // 本模型 ctor 无额外系数（可能继承基类 residual*）
    }
}
```

## 参数表

| 参数 | 说明 |
|------|------|
| `type` | 必须为 `Gunn` |
| （基类） | 部分模型继承 `residualRe` / `residualAlpha` 等，见对应基类 ctor |

本模型构造函数通常无额外专用系数。

## 控制方程与关联式
Gunn (1978) correlation for fixed and fluidised beds with Re < 10^5
and continuous phase fraction between 0.35 and 1.

Reference:
```
Gunn, D. J. (1978).
Transfer of heat or mass to particles in fixed and fluidised beds.
International Journal of Heat and Mass Transfer, 21(4), 467-476.
```

## 文献与源码依据
- 类: `Foam`::heatTransferModels::Gunn`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/heatTransferModels/Gunn/Gunn.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`Gunn`。
