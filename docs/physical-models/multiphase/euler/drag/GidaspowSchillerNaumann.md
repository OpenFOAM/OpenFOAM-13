# GidaspowSchillerNaumann

## 一句话
Gidaspow, Schiller and Naumann drag model

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 阻力（基类 `dragModel`）
- **注册名**: `GidaspowSchillerNaumann`

## 字典示例


> （由源码构造函数推断，无官方教程实例）

```c++
// constant/momentumTransfer — drag 子字典
drag
{
    <phasePair>
    {
        type            GidaspowSchillerNaumann;
        // 本模型 ctor 无额外系数（可能继承基类 residual*）
    }
}
```

## 参数表

| 参数 | 说明 |
|------|------|
| `type` | 必须为 `GidaspowSchillerNaumann` |
| （基类） | 部分模型继承 `residualRe` / `residualAlpha` 等，见对应基类 ctor |

本模型构造函数通常无额外专用系数。

## 控制方程与关联式
Gidaspow, Schiller and Naumann drag model

References:
```
Enwald, H., Peirano, E., & Almstedt, A. E. (1996).
Eulerian two-phase flow theory applied to fluidisation.
International Journal of Multiphase Flow, 22, 21-66.

This is identical to the Wen and Yu, Rowe model Table 3.6 p.56  in
van Wachem, B. G. M. (2000).
Derivation, implementation, and validation of computer simulation models
for gas-solid fluidised beds.
PhD Thesis, TU Delft.
```

## 文献与源码依据
- 类: `Foam`::dragModels::GidaspowSchillerNaumann`
- 源码路径: `applications/modules/multiphaseEuler/phaseSystem/interfacialModels/dragModels/GidaspowSchillerNaumann/GidaspowSchillerNaumann.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`GidaspowSchillerNaumann`。
