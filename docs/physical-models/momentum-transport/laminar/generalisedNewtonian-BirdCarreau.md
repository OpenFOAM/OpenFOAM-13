# `generalisedNewtonian`-BirdCarreau`

## 一句话

generalisedNewtonian 粘度子模型：Bird–Carreau

## 适用条件（求解器 / 场 / 前提）

- 父模型：`generalisedNewtonian`
- 子字典：`viscosityModel BirdCarreau;`

## 字典示例

> （由源码构造函数推断，无官方教程实例；数值来自源码头文件 Usage 示例）

```c++
// constant/momentumTransport
simulationType laminar;

laminar
{
    model           generalisedNewtonian;
    viscosityModel  BirdCarreau;

    nuInf       1e-5;
    k           10;
    n           0.5;
    // 可选 a（默认 2）→ Bird-Carreau-Yasuda
    // 或用 tauStar 代替 k（见方程第二式）
}
```

## 参数表

| 参数 | 默认/示例 | 说明 |
|------|-----------|------|
| `nuInf` | `1e-5`（Usage） | 无穷剪切运动粘度 [m²/s] |
| `k` | `10`（Usage） | 时间常数；与 `tauStar` 二选一 |
| `n` | `0.5`（Usage） | 幂律指数 |
| `a` | `2`（默认） | Yasuda 指数；可选 |
| `tauStar` | — | 临界应力；若给出则替代 `k` |
| `nu0` | （物性） | 零剪切粘度，写在 `physicalProperties` |

正确写法：`laminar`.model = generalisedNewtonian`，再设 `viscosityModel BirdCarreau;`（不是 `model` generalisedNewtonian-BirdCarreau`）。

## 控制方程与关联式

Bird–Carreau generalised Newtonian 粘度模型。可选系数 `a`（默认 2）时为 Bird–Carreau–Yasuda 形式。应变率系数可写常数 `k`，或写向剪切变稀过渡的临界应力 `tauStar`。

运动粘度 [m²/s]：

$$
\nu = \nu_\infty + (\nu_0 - \nu_\infty)\left(1 + (k\gamma)^a \right)^{(n - 1)/a}
$$

或

$$
\nu = \nu_\infty + (\nu_0 - \nu_\infty)\left(1 + \left(\frac{\nu_0\gamma}{\tau^*}\right)^a \right)^{(n - 1)/a}
$$

头文件第二组 Usage（聚合物 / `tauStar` 形式）：

```c++
viscosityModel BirdCarreau;
nuInf       0;
tauStar     90;
n           0.5;
```

## 文献与源码依据

- [`src/MomentumTransportModels/momentumTransportModels/laminar/generalisedNewtonian/generalisedNewtonianViscosityModels/strainRateViscosityModels/BirdCarreau/BirdCarreau.H`](../../../src/MomentumTransportModels/momentumTransportModels/laminar/generalisedNewtonian/generalisedNewtonianViscosityModels/strainRateViscosityModels/BirdCarreau/BirdCarreau.H)

## 教程与模板

- 仓库 tutorials 中未检索到 `BirdCarreau` 字面配置；可参考同类 `simulationType` 案例并改 `model`。
- 注册见 [`README`](../README.md) 工厂表。


## 注意事项

- 模型必须在对应库中注册（不可压/可压/相）；见族 README 注册表。
