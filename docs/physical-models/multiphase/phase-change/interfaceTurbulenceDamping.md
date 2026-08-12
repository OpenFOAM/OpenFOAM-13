# interfaceTurbulenceDamping

## 一句话
Free-surface phase turbulence damping function

## 适用条件（求解器 / 场 / 前提）
- 适用: multiphaseEuler
- **族**: 界面湍流阻尼（基类 `fvModel`）
- **注册名**: `interfaceTurbulenceDamping`

## 字典示例
```
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
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `interfaceTurbulenceDamping`
- 基类: `fvModel`


## 控制方程与关联式
Free-surface phase turbulence damping function

Adds an extra source term to the mixture or phase epsilon or omega
equation to reduce turbulence generated near a free-surface.  The
implementation is based on

Reference:
```
Frederix, E. M. A., Mathur, A., Dovizio, D., Geurts, B. J.,
& Komen, E. M. J. (2018).
Reynolds-averaged modeling of turbulence damping
near a large-scale interface in two-phase flow.
Nuclear engineering and design, 333, 122-130.
```

but with an improved formulation for the coefficient `A` appropriate for
unstructured meshes including those with split-cell refinement patterns.
However the dimensioned length-scale coefficient `delta` remains and must
be set appropriately for the case by performing test runs and comparing with
known results.  Clearly this model is far from general and more research is
needed in order that `delta` can be obtained directly from the interface
flow and turbulence conditions.

## 文献与源码依据
- 类: `Foam`::fv::interfaceTurbulenceDamping`
- 源码路径: `applications/modules/multiphaseEuler/fvModels/interfaceTurbulenceDamping/interfaceTurbulenceDamping.C`

## 教程与模板
- （检索 `tutorials`/` 中含该 `type` 的案例）

## 注意事项
- 类型名必须与 RTS 注册名一致：`interfaceTurbulenceDamping`。
