# refiner

## 一句话

自适应网格加密 topo changer

## 适用条件（求解器 / 场 / 前提）

dynamicMeshDict → topoChanger

## 字典示例

```c++
topoChanger
{
    type            refiner;

    libs            ("libfvMeshTopoChangers.so");

    // How often to refine
    refineInterval  1;

    // Field to be refinement on
    field           alpha.water;

    // Refine field in between lower..upper
    lowerRefineLevel 0.001;
    upperRefineLevel 0.999;

    // Have slower than 2:1 refinement
    nBufferLayers   1;

    // Refine cells only up to maxRefinement levels
    maxRefinement   2;

    // Stop refinement if maxCells reached
    maxCells        200000;

    // Flux field and corresponding velocity field. Fluxes on changed
    // faces get recalculated by interpolating the velocity. Use 'none'
    // on surfaceScalarFields that do not need to be reinterpolated.
    correctFluxes
    (
        (phi none)
        (nHatf none)
        (rhoPhi none)
        (alphaPhi.water none)
        (ghf none)
    );

    // Write the refinement level as a volScalarField
    dumpLevel       true;
}
```

## 参数表

主要入口以源码 `Usage` 为准。常见关键字见字典示例；完整列表与默认值见对应 `.H`。

| 说明 | |
|------|--|
| 配置位置 | 通常 `constant/fvModels` 或 `constant/fvConstraints` / `constant/dynamicMeshDict` |
| 选择关键字 | `type`（须与 RTS 注册名一致） |
| 区域选择 | 多数源/约束需要 `cellZone` 或等价选择 |


## 控制方程与关联式

摘自源码头文件 `Description`（原文）：

> Dynamic mesh refinement/unrefinement based on volScalarField values.
>
> Refinement can optionally be specified in a cellZone or in multiple
> regions, each controlled by a different volScalarField.

## 文献与源码依据

- 源码：[`src/fvMeshTopoChangers/refiner/refiner_fvMeshTopoChanger.H`](../../../../src/fvMeshTopoChangers/refiner/refiner_fvMeshTopoChanger.H)
- 实现：同目录 `.C`

## 教程与模板

- 见仓库 `tutorials`/` 中含该 `type` 的案例
- `etc/caseDicts/` 若有同名模板一并对照

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
