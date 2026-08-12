# pressureInletUniformVelocity

## 一句话
压力相关边界条件。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`pressureInletUniformVelocity`
- **典型场**：`U`, p / p_rgh
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            pressureInletUniformVelocity;
    value           uniform (0 0 0);
}
```

## 参数表
源码头文件未提供标准 `Usage` 表，或参数由基类继承——请对照源码构造函数读取字典关键字。

## 控制方程与关联式
压力相关边界条件。

类头 `Description` 原文：

> This velocity inlet boundary condition is applied to patches where the
> pressure is specified.  The uniform inflow velocity is obtained by
> averaging the flux over the patch, and then applying it in the direction
> normal to the patch faces.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/pressureInletUniformVelocity/pressureInletUniformVelocityFvPatchVectorField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/pressureInletUniformVelocity/pressureInletUniformVelocityFvPatchVectorField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/pressureInletUniformVelocity/pressureInletUniformVelocityFvPatchVectorField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/pressureInletUniformVelocity/pressureInletUniformVelocityFvPatchVectorField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            pressureInletUniformVelocity`。

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
