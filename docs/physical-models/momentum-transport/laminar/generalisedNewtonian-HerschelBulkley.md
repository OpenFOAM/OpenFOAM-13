# `generalisedNewtonian-HerschelBulkley`

## 一句话

generalisedNewtonian 粘度子模型：Herschel–Bulkley

## 适用条件（求解器 / 场 / 前提）

- 父模型：`generalisedNewtonian`
- 子字典：`viscosityModel HerschelBulkley;`

## 字典示例

> （由源码构造函数推断，无官方教程实例；数值来自源码头文件 Usage）

```c++
// constant/momentumTransport
simulationType laminar;

laminar
{
    model           generalisedNewtonian;
    viscosityModel  HerschelBulkley;

    tau0       0.01;    // 屈服应力相关阈值
    k          0.001;   // 稠度系数
    n          0.2;     // 幂律指数
}
```

零剪切粘度 $\nu_0$ 来自 `physicalProperties`。

## 参数表

| 参数 | 默认/示例 | 说明 |
|------|-----------|------|
| `tau0` | 0.01 | 屈服应力阈值 |
| `k` | 0.001 | 稠度 |
| `n` | 0.2 | 幂指数 |

正确写法：`laminar.model = generalisedNewtonian`，再设 `viscosityModel HerschelBulkley;`（不是 `model generalisedNewtonian-HerschelBulkley`）。

## 控制方程与关联式

Herschel–Bulkley 结合 Bingham 塑性与幂律：低应变率取 $\mu_0$，超过阈值应力后按幂律。

运动粘度形式：

$$
\mu = \min\bigl(\mu_0,\,(\tau_0 + k\gamma^{n})/\gamma\bigr)
$$

## 文献与源码依据

- [`src/MomentumTransportModels/momentumTransportModels/laminar/generalisedNewtonian/generalisedNewtonianViscosityModels/strainRateViscosityModels/HerschelBulkley/HerschelBulkley.H`](../../../../src/MomentumTransportModels/momentumTransportModels/laminar/generalisedNewtonian/generalisedNewtonianViscosityModels/strainRateViscosityModels/HerschelBulkley/HerschelBulkley.H)

## 教程与模板

- 仓库 tutorials 中未检索到 `HerschelBulkley` 字面配置；可参考同类 `simulationType` 案例并改 `viscosityModel`。

## 注意事项

- 模型必须在对应库中注册；见族 README 注册表。
