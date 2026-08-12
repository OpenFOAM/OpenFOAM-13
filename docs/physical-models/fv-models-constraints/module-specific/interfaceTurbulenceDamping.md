# interfaceTurbulenceDamping

## 一句话

界面湍流阻尼

## 适用条件（求解器 / 场 / 前提）

适用: multiphaseEuler

## 字典示例



> （由源码构造函数推断，无官方教程实例）

```c++
interfaceTurbulenceDamping
    {
        type    interfaceTurbulenceDamping;

        libs    ("libmultiphaseEulerFvModels.so");

        phase   water;

        // Interface turbulence damping length scale
        // This is a required input as described in section 3.3 of the paper
        delta   1e-4;
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

> Free-surface phase turbulence damping function
>
> Adds an extra source term to the mixture or phase epsilon or omega
> equation to reduce turbulence generated near a free-surface.  The
> implementation is based on
>
> Reference:
>     >     Frederix, E. M. A., Mathur, A., Dovizio, D., Geurts, B. J.,
>     >     & Komen, E. M. J. (2018).
>     >     Reynolds-averaged modeling of turbulence damping
>     >     near a large-scale interface in two-phase flow.
>     >     Nuclear engineering and design, 333, 122-130.
>     > 
>
> but with an improved formulation for the coefficient \c A appropriate for
> unstructured meshes including those with split-cell refinement patterns.
> However the dimensioned length-scale coefficient \c delta remains and must
> be set appropriately for the case by performing test runs and comparing with
> known results.  Clearly this model is far from general and more research is
> needed in order that \c delta can be obtained directly from the interface
> flow and turbulence conditions.

## 文献与源码依据

- 源码：[`applications/modules/multiphaseEuler/fvModels/interfaceTurbulenceDamping/interfaceTurbulenceDamping.H`](../../../../applications/modules/multiphaseEuler/fvModels/interfaceTurbulenceDamping/interfaceTurbulenceDamping.H)
- 实现：同目录 `.C`

## 教程与模板

- 见对应求解器 tutorials；物理方程细目由 Phase 3/4 目录承接

## 注意事项

- 本页为 Phase 5 **入口目录**（fvModel 类型与字典位置）
- 多相/燃烧物理细节见 `multiphase`/` 或 `combustion`-radiation/` / `lagrangian`/`
