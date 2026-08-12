# cloudVelocityLagrangianPatch

## 一句话
速度相关边界条件。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`cloudVelocityLagrangianPatch`
- **RTS `TypeName`**：`cloudVelocity`（与字典名不同时以字典 `type` 为准）
- **典型场**：`U`
- **库 / 加载**：Lagrangian 库（`libLagrangian` / cloud）；非标准 `fvPatchField` RTS
- **种类**：`LagrangianPatch`（inventory 收录，但不是标准 volField `fvPatchField`）

## 字典示例
（非场 BC：在 `polyMesh/boundary` 或 Lagrangian 云配置中声明，见 `src/lagrangian/cloud/derivedLagrangianPatches/cloudVelocity/cloudVelocityLagrangianPatch.C`。）

## 参数表
源码头文件未提供标准 `Usage` 表，或参数由基类继承——请对照源码构造函数读取字典关键字。

## 控制方程与关联式
速度相关边界条件。

类头 `Description` 原文：

> A cloud velocity Lagrangian patch. This patch defers to the cloud velocity
> boundary condition to determine the state of a particle after hitting a
> (non-constraint) patch. This allows the velocity boundary condition to
> control the rebound, escape, stick, etc..., behaviour. This is selected
> automatically by the base cloud. The user should never have to specify this
> patch explicitly.

## 文献与源码依据
- 源码：[`src/lagrangian/cloud/derivedLagrangianPatches/cloudVelocity/cloudVelocityLagrangianPatch.C`](../../../src/lagrangian/cloud/derivedLagrangianPatches/cloudVelocity/cloudVelocityLagrangianPatch.C)
- 头文件：[`src/lagrangian/cloud/derivedLagrangianPatches/cloudVelocity/cloudVelocityLagrangianPatch.H`](../../../src/lagrangian/cloud/derivedLagrangianPatches/cloudVelocity/cloudVelocityLagrangianPatch.H)
- Inventory 备注：lagrangian-related

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            cloudVelocityLagrangianPatch`。

## 注意事项
- 本条目来自 inventory 扩展收录；搭建 volField 边界时勿当作 `fvPatchField` 的 `type`。
