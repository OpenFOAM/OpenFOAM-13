# `Gulder`

## 一句话

Gulder 层流火焰速度关联

## 适用条件（求解器 / 场 / 前提）

- 类别：`laminarFlameSpeed`
- 适用：`XiFluid`（主场景）；亦注册为通用 `laminarFlameSpeed`
- 前提：指定 `fuel` 与对应燃料子字典系数；可选 EGR 场 `egr`

## 字典示例

```c++
// tutorials/XiFluid/moriyoshiHomogeneous/.../combustionPropertiesInclude
laminarFlameSpeed
{
    model           unstrained;

    unstrainedLaminarFlameSpeed
    {
        model           Gulder;

        equivalenceRatio 1;

        fuel            Propane;

        Propane
        {
            W               0.446;
            eta             0.12;
            xi              4.95;
            alpha           1.77;
            beta            -0.2;
            f               2.3;
        }

        Methane
        {
            W               0.422;
            eta             0.15;
            xi              5.18;
            alpha           2;
            beta            -0.5;
            f               2.3;
        }

        IsoOctane
        {
            W               0.4658;
            eta             -0.326;
            xi              4.48;
            alpha           1.56;
            beta            -0.22;
            f               2.3;
        }
    }
}
```

构造函数（`Gulder.C`）从燃料子字典 **必读**：`W`, `eta`, `xi`, `f`, `alpha`, `beta`。

## 参数表

| 参数 | 必需 | 含义 |
|------|------|------|
| `fuel` | 是 | 燃料名，须有同名子字典 |
| `W` | 是 | 参考火焰速度幅值系数 [m/s 量级] |
| `eta` | 是 | $\phi$ 幂指数 |
| `xi` | 是 | 当量比偏离指数 |
| `alpha` | 是 | 温度指数（相对 300 K） |
| `beta` | 是 | 压力指数（相对 1.013e5 Pa） |
| `f` | 是 | EGR 抑制系数（乘 **质量分数** `egr`，非摩尔分数） |
| `equivalenceRatio` | 可选 | 固定当量比 |

实现：$\mathrm{SuRef}(\phi)=W\phi^{\eta}\exp(-\xi(\phi-1.075)^2)$，再乘 $(T_u/T_\mathrm{ref})^\alpha(p/p_\mathrm{ref})^\beta(1-f Y_\mathrm{res})$。

## 控制方程与关联式

Laminar flame speed obtained from Gulder's correlation，可选 EGR。

文献：Gülder, Ö. L. (1984). Correlations of laminar combustion data for alternative SI engine fuels (No. 841000). SAE technical paper.

## 文献与源码依据

- [`src/thermophysicalModels/laminarFlameSpeed/Gulder/Gulder.C`](../../../../src/thermophysicalModels/laminarFlameSpeed/Gulder/Gulder.C)
- 交叉：[`../../combustion-radiation/laminar-flame-speed.md`](../../combustion-radiation/laminar-flame-speed.md)

## 教程与模板

- `tutorials/XiFluid/moriyoshiHomogeneous/.../combustionPropertiesInclude`
- `tutorials/XiFluid/engine2Valve2D/constant/combustionProperties`
- `tutorials/XiFluid/stratified/constant/combustionProperties`
- `tutorials/XiFluid/kivaTest/constant/combustionProperties`

## 注意事项

- 燃料子字典名必须与 `fuel` 一致；缺任一系数会 FatalError。
- `f` 作用于质量分数 `egr`，与原文摩尔分数表述不同。
