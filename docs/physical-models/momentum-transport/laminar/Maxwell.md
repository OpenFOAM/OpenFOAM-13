# `Maxwell`

## 一句话

广义 Maxwell 粘弹性（上随体导数，可多模态）

## 适用条件（求解器 / 场 / 前提）

- `simulationType laminar;` + `model Maxwell;`
- 注册：incompressible / compressible / phase* / film（子集）

## 字典示例

```c++
// tutorials/incompressibleFluid/planarPoiseuille/constant/momentumTransport
simulationType laminar;

laminar
{
    model               Maxwell;

    MaxwellCoeffs
    {
        nuM             1;      // [m^2/s] 聚合物/模态运动粘度
        lambda          5;      // [s] 松弛时间

        // 多模态时改为:
        // modes
        // (
        //     { nuM 0.5; lambda 1; }
        //     { nuM 0.5; lambda 10; }
        // );
    }
}
```

另见 `tutorials/incompressibleVoF/climbingRod/constant/momentumTransport.liquid`。

## 参数表

| 参数 | 必需 | 量纲 | 说明 |
|------|------|------|------|
| `nuM` | 单模态时是 | m²/s | 聚合物粘度；多模态时在各 `modes` 子字典 |
| `lambda` | 单模态时是 | s | 松弛时间 |
| `modes` | 否 | — | 多模态列表；若给出则按模态读 `nuM`/`lambda` |

另有溶剂粘度来自实例化所用的粘度模型（`nu`≠0 时等价 Oldroyd-B）。

## 控制方程与关联式

Generalised Maxwell model using the upper-convected derivative of the stress tensor，支持多模态。溶剂粘度非零时等价 Oldroyd-B。

文献线索：Wiechert (1889/1893)；Amoreira & Oliveira (2010)。

## 文献与源码依据

- [`src/MomentumTransportModels/momentumTransportModels/laminar/Maxwell/Maxwell.C`](../../../../src/MomentumTransportModels/momentumTransportModels/laminar/Maxwell/Maxwell.C)

## 教程与模板

- `tutorials/incompressibleFluid/planarPoiseuille/constant/momentumTransport`
- `tutorials/incompressibleVoF/climbingRod/constant/momentumTransport.liquid`

## 注意事项

- 不要写 `turbulence on;`（这是 laminar 粘弹性模型）。
- 多模态时顶层 `nuM`/`lambda` 读法见 `readModeCoefficients`。
