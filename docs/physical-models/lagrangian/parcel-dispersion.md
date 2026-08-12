# DispersionModel（湍流扩散）

注册：`makeParcelDispersionModels`.H`。

---

# StochasticDispersionRAS

## 一句话
RANS 随机游走湍流扩散。

## 适用条件（求解器 / 场 / 前提）
- **适用**: 载体为 RAS 湍流；`dispersionModel` stochasticDispersionRAS`
- **前提**: \(k\)（及 \(\varepsilon\)/\(\omega\)）可插值

## 字典示例
摘录 `tutorials/multicomponentFluid/verticalChannel/constant/cloudProperties`：

```cpp
dispersionModel stochasticDispersionRAS;
```

同案亦可关闭：

```cpp
dispersionModel none;  // e.g. GoldschmidtMPPIC / aachenBomb
```

（无额外 `*Coeffs` 子字典。）

## 参数表
多数无额外 coeffs；细节见源码。

## 控制方程与关联式
在颗粒速度上叠加与湍流脉动相关的随机增量（离散随机游走）。

## 文献与源码依据
`DispersionModel/StochasticDispersionRAS/`

## 教程与模板
`etc/caseDicts` 默认；通道颗粒案例。

## 注意事项
- LES 下应换用合适模型或 `none`；与 RAS 场名一致。

---

# GradientDispersionRAS

## 一句话
基于湍动能梯度的 RAS 扩散。

## 适用条件
RANS；与 stochastic 二选一。

## 字典示例
`dispersionModel gradientDispersionRAS;`（无额外 coeffs；与 stochastic 二选一）

## 参数表
见源码。

## 控制方程与关联式
扩散速度与 \(\nabla k\) 相关。

## 文献与源码依据
`GradientDispersionRAS`/`

## 教程与模板
—
## 注意事项
—

---

# NoDispersion

## 一句话
无湍流扩散（颗粒只跟平均速度）。

## 适用条件
层流、MPPIC 演示、或忽略扩散。

## 字典示例
`dispersionModel` none;`（`GoldschmidtMPPIC`）

## 参数表
无。

## 依据
`NoDispersion`/`

## 注意事项
—

---

## 新框架
`turbulentDispersion` LagrangianModel — 见 [new-Lagrangian-framework.md](new-Lagrangian-framework.md)。

## 覆盖计数
**3** = 宏全覆盖。
