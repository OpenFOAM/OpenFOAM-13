# coupled

## 一句话
基本边界条件类型 `coupled`。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`coupled`
- **典型场**：任意场（模板）
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            coupled;
    // 其余条目见源码 Usage / 教程
    value           $internalField;
}
```

## 参数表
见类头 `Usage`；多数仅需 `value` / `gradient` / mixed 三元组。

## 控制方程与关联式
基本边界条件类型 `coupled`。

类头 `Description` 原文：

> Abstract base class for coupled patches.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/basic/coupled`](../../../src/finiteVolume/fields/fvPatchFields/basic/coupled)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/basic/coupled/coupledFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/basic/coupled/coupledFvPatchField.H)
- Inventory 备注：core finiteVolume (basic dir)

## 教程与模板
- [`tutorials/incompressibleFluid/cavityCoupledU/system/fvSolution`](../../../tutorials/incompressibleFluid/cavityCoupledU/system/fvSolution)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
