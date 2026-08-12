# multiphaseEulerCavitation

## 一句话
Model for cavitation phase change between two phases.

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler（可压空化模型）
- **族**: Euler 空化（基类 `fvModel`）
- **注册名**: `multiphaseEulerCavitation`

## 字典示例



> （由源码构造函数推断，无官方教程实例）

```c++
// constant/phaseProperties — model 子字典
model
{
    <phasePair>
    {
        type            multiphaseEulerCavitation;
        cavitation
        libs            ("libmultiphaseEulerFvModels.so");
        // Note: Order is important. The liquid should be specified first.
        phases          (liquid gas);
        energySemiImplicit no;
        model           Kunz;
        pSat            79995.75943;
        UInf            5.33;
        tInf            0.028142589;
        Cc              100;
        Cv              100;
    }
}
```

## 参数表

| 参数 | 说明 |
|------|------|
| `type` | 必须为 `multiphaseEulerCavitation` |
| （基类） | 部分模型继承 `residualRe` / `residualAlpha` 等，见对应基类 ctor |

本模型构造函数通常无额外专用系数。

## 控制方程与关联式
Model for cavitation phase change between two phases.

Example usage:
```
cavitation
{
type            multiphaseEuler::cavitation;
libs            ("libmultiphaseEulerFvModels.so");

// Note: Order is important. The liquid should be specified first.
phases          (liquid gas);

energySemiImplicit no;

model           Kunz;

pSat            79995.75943;

UInf            5.33;
tInf            0.028142589;
Cc              100;
Cv              100;
}
```

## 文献与源码依据
- 类: `Foam`::fv::multiphaseEulerCavitation`
- 源码路径: `applications/modules/multiphaseEuler/fvModels/multiphaseEulerCavitation/multiphaseEulerCavitation.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`multiphaseEulerCavitation`。
