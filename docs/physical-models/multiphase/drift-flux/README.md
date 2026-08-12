# 漂移通量（incompressibleDriftFlux）

混合物动量 + 相对速度近似；配置位于 `constant/phaseProperties` 与相物性中的混合物粘度。

## 子目录

| 目录 | 基类 |
|------|------|
| [relativeVelocity/](relativeVelocity/) | `relativeVelocityModel`：`simple` / `general` / `MichaelsBolger` |
| [packingDispersion/](packingDispersion/) | `packingDispersionModel`：`none` / `DeClercq` / `Green` / `Landman` / `Usher` |
| [mixtureViscosity/](mixtureViscosity/) | `mixtureViscosityModel`：`slurry` / `plastic` / `BinghamPlastic` / `HerschelBulkley` / `Quemada` |

## 字典提示

```
phases (sludge water);
relativeVelocityModel simple;
"(simple|general)Coeffs"
{
    Vc              2.241e-4;
    a               285.84;
    a1              0.1;
    residualAlpha   0;
}
```

（摘自 `tutorials/incompressibleDriftFlux/mixerVessel2DMRF/constant/phaseProperties`）

## 相关求解器

- [incompressibleDriftFlux](../../solvers/incompressibleDriftFlux.md)

## 导航

- [多相索引](../README.md) · [覆盖报告](../_coverage.md)
