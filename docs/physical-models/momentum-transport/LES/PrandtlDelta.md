# `PrandtlDelta`

## 一句话

Prandtl 混合长度型 Δ

## 适用条件（求解器 / 场 / 前提）

- LES `delta` 模型：`delta` PrandtlDelta;`
- 所有 LES 求解路径

## 字典示例


> （由源码构造函数/头文件默认系数推断，无官方教程实例）

```c++
// constant/momentumTransport （由源码构造函数/头文件默认系数推断，无官方教程实例）
simulationType LES;

LES
{
    model           PrandtlDelta;
    turbulence      on;

    delta           Prandtl;

        kappa           0.41;

        PrandtlCoeffs
        {
            delta   cubeRootVol;

            cubeRootVolCoeffs
            {
                deltaCoeff      1;
            }

            Cdelta          0.158;
        }
}
```

## 参数表


默认系数（源码头文件；可在模型子字典/`PrandtlDeltaCoeffs` 覆盖）：

| 参数 | 默认 | 含义 |
|------|------|------|
| `delta` | Prandtl | 见模型 Description |
| `kappa` | 0.41 | 见模型 Description |
| `delta` | cubeRootVol | 见模型 Description |
| `deltaCoeff` | 1 | 见模型 Description |
| `Cdelta` | 0.158 | 见模型 Description |

量纲：模型常数一般为无量纲（另有注明除外）。

## 控制方程与关联式

Apply Prandtl mixing-length based damping function to the specified
geometric delta to improve near-wall behavior or LES SGS models.

```
delta = min(geometricDelta, (kappa/Cdelta)*y)
```

Example specification in the momentumTransport dictionary:
```
delta           Prandtl;

kappa           0.41;

PrandtlCoeffs
{
delta   cubeRootVol;

cubeRootVolCoeffs
{
deltaCoeff      1;
}

Cdelta          0.158;
}
```

## 文献与源码依据

- [`src/MomentumTransportModels/momentumTransportModels/LES/LESdeltas/PrandtlDelta/PrandtlDelta.H`](../../../src/MomentumTransportModels/momentumTransportModels/LES/LESdeltas/PrandtlDelta/PrandtlDelta.H)

## 教程与模板

- 仓库 tutorials 中未检索到 `PrandtlDelta` 字面配置；可参考同类 `simulationType` 案例并改 `model`。
- 注册见 [`README`](../README.md) 工厂表。


## 注意事项

- 模型必须在对应库中注册（不可压/可压/相）；见族 README 注册表。
