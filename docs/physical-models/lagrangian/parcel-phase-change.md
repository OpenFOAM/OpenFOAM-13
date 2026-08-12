# PhaseChangeModel（相变/蒸发）

注册：`makeReactingParcelPhaseChangeModels`.H`。用于 **reacting / spray** 云。

---

# LiquidEvaporation

## 一句话
液滴蒸发（质量/组分向气相传递）。

## 适用条件（求解器 / 场 / 前提）
- **适用**: reactingCloud / sprayCloud；载体多组分可接收蒸汽
- **前提**: `composition` 与液体物性；气相物种名匹配

## 字典示例
摘录 `tutorials/multicomponentFluid/verticalChannel/constant/cloudProperties`：

```cpp
phaseChangeModel liquidEvaporation;

liquidEvaporationCoeffs
{
    enthalpyTransfer enthalpyDifference;

    activeLiquids   ( H2O );
}
```

## 参数表
| 入口 | 含义 |
|------|------|
| `enthalpyTransfer` | `enthalpyDifference` 等（见 `.H`） |
| `activeLiquids` | 参与蒸发的液体物种名列表 |

## 控制方程与关联式
蒸发速率由传热传质数（Spalding 等）闭合；质量从 parcel 移除并源入气相 \(Y_i\)。

## 文献与源码依据
`PhaseChangeModel/LiquidEvaporation/`

## 教程与模板
`multicomponentFluid/verticalChannel*`, `aachenBomb`

## 注意事项
- 气相缺少对应物种 → 质量去向错误或报错。

---

# LiquidEvaporationBoil

## 一句话
含沸腾的液滴蒸发。

## 适用条件
过热/沸点附近液滴。

## 字典示例
摘录 `tutorials/multicomponentFluid/aachenBomb/constant/cloudProperties`：

```cpp
phaseChangeModel liquidEvaporationBoil;

liquidEvaporationBoilCoeffs
{
    enthalpyTransfer enthalpyDifference;

    activeLiquids    ( C7H16 );
}
```

## 参数表
同 `liquidEvaporation`；沸腾分支见 `LiquidEvaporationBoil.H`。

## 控制方程与关联式
在蒸发模型上增加沸腾分支。

## 文献与源码依据
同目录。

## 教程与模板
—
## 注意事项
—

---

# NoPhaseChange

## 一句话
关闭相变。

## 字典示例
`phaseChangeModel` none;`

## 参数表
无。

## 依据
`NoPhaseChange`/`

---

## 覆盖计数
**3** = 宏全覆盖。
