# symmetryLagrangianPatch

## 一句话
对称面约束。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`symmetryLagrangianPatch`
- **典型场**：Lagrangian 云（非 volField BC）
- **库 / 加载**：Lagrangian 库（`libLagrangian` / cloud）；非标准 `fvPatchField` RTS
- **种类**：`LagrangianPatch`（inventory 收录，但不是标准 volField `fvPatchField`）

## 字典示例
（非场 BC：在 `polyMesh/boundary` 或 Lagrangian 云配置中声明，见 `src/lagrangian/Lagrangian/LagrangianMesh/LagrangianPatches/constraint/symmetry/symmetryLagrangianPatch.C`。）

## 参数表
源码头文件未提供标准 `Usage` 表，或参数由基类继承——请对照源码构造函数读取字典关键字。

## 控制方程与关联式
对称面约束。

类头 `Description` 原文：

> Symmetry Lagrangian patch. This is used for representing
> reflected/mirror-image repetitions of the geometry.

## 文献与源码依据
- 源码：[`src/lagrangian/Lagrangian/LagrangianMesh/LagrangianPatches/constraint/symmetry/symmetryLagrangianPatch.C`](../../../src/lagrangian/Lagrangian/LagrangianMesh/LagrangianPatches/constraint/symmetry/symmetryLagrangianPatch.C)
- 头文件：[`src/lagrangian/Lagrangian/LagrangianMesh/LagrangianPatches/constraint/symmetry/symmetryLagrangianPatch.H`](../../../src/lagrangian/Lagrangian/LagrangianMesh/LagrangianPatches/constraint/symmetry/symmetryLagrangianPatch.H)
- Inventory 备注：lagrangian-related

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            symmetryLagrangianPatch`。

## 注意事项
- 本条目来自 inventory 扩展收录；搭建 volField 边界时勿当作 `fvPatchField` 的 `type`。
