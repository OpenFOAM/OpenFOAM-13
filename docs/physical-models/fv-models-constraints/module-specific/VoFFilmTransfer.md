# VoFFilmTransfer

## 一句话

VoF→薄膜质量传递

## 适用条件（求解器 / 场 / 前提）

适用: 与 film/isothermalFilm 多区域耦合

## 字典示例



```c++
// `tutorials/multiRegion/film/VoFToFilm/constant/VoF/fvModels`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

VoFFilmTransfer
{
    type        VoFFilmTransfer;

    libs        ("libfilmVoFTransfer.so");

    filmPatch   film;
    phase       liquid;

    deltaFactorToFilm 0.9;
    alphaToFilm       0.86;

    transferRateCoeff 0.1;
}

// ************************************************************************* //
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

> Film<->VoF transfer model

## 文献与源码依据

- 源码：[`applications/modules/isothermalFilm/fvModels/filmVoFTransfer/VoFFilmTransfer.H`](../../../../applications/modules/isothermalFilm/fvModels/filmVoFTransfer/VoFFilmTransfer.H)
- 实现：同目录 `.C`

## 教程与模板

- 见对应求解器 tutorials；物理方程细目由 Phase 3/4 目录承接

## 注意事项

- 本页为 Phase 5 **入口目录**（fvModel 类型与字典位置）
- 多相/燃烧物理细节见 `multiphase`/` 或 `combustion`-radiation/` / `lagrangian`/`
