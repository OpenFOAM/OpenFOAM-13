# 动网格、波与大气

Phase **5** 域目录：`dynamicMeshDict` 运动/拓扑/再分配、`motionSolver` 族、刚体与六自由度、MRF、`pointDisplacement` 概览、波浪模型与大气模型。

## dynamicMeshDict 骨架

```c++
/* constant/dynamicMeshDict */
mover
{
    type    motionSolver;
    // ...
}
topoChanger
{
    type    refiner; // 或 meshToMesh / none
}
distributor
{
    type    loadBalancer; // 可选
}
```

求解器模块 [`movingMesh`](../solvers/movingMesh.md) 专用于执行上述组件；流体求解器亦可在同字典下启用网格运动。

## 目录索引

| 子目录 | 内容 |
|--------|------|
| [fvMeshMovers/](fvMeshMovers/) | `motionSolver`、`interpolator`、`inkJet`、`multiValveEngine` 及 zoneGenerators |
| [fvMeshTopoChangers/](fvMeshTopoChangers/) | `refiner`、`meshToMesh`、`meshToMeshAdjustTimeStep` |
| [fvMeshDistributors/](fvMeshDistributors/) | `distributor`、`loadBalancer` |
| [fvMeshStitchers/](fvMeshStitchers/) | `moving` stitcher |
| [motionSolvers/](motionSolvers/) | 位移/速度拉普拉斯、solidBody、sixDoF/rigidBody 等 |
| [solidBodyMotionFunctions/](solidBodyMotionFunctions/) | 旋转/振荡/SDA/六自由度规定运动等 |
| [pointDisplacement/](pointDisplacement/) | 常用点位移/点速度 BC 概览 |
| [MRF/](MRF/) | `MRFZone` 与 MRF 速度 BC 索引 |
| [sixDoF/](sixDoF/) | 六自由度求解器、约束/阻尼、关节/刚体、监视 FO |
| [waves/](waves/) | Airy/Stokes/孤立波/不规则谱与叠加 |
| [atmospheric/](atmospheric/) | Lopes da Costa k-ε、ABL 入口与大气壁面函数 |

波浪相关 **fvModels**（`waveForcing` 等）见 [`../fv-models-constraints/waves/`](../fv-models-constraints/waves/)。

本域 Markdown 页数：**117**（含 README）。

## Inventory

[`../_inventory/rts-dynamic-mesh-waves-atm.md`](../_inventory/rts-dynamic-mesh-waves-atm.md)

## 导航

- [`../01-solver-matrix.md`](../01-solver-matrix.md) · [`../README.md`](../README.md)
