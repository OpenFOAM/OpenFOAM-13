# jumpCyclic

## 一句话
周期/循环配对边界。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`jumpCyclic`
- **典型场**：任意场（模板）
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）
- **前提**：`blockMeshDict`/`polyMesh` 中 patch 类型必须匹配（如 `type` wedge;` 配 `wedge` BC）。

## 字典示例
```
<patchName>
{
    type            jumpCyclic;
    // 其余条目见源码 Usage / 教程
    value           $internalField;
}
```

## 参数表
通常无额外物理参数；由约束 patch 拓扑决定行为。

## 控制方程与关联式
周期/循环配对边界。

类头 `Description` 原文：

> This boundary condition provides a base class for cyclic conditions with a
> specified "jump" (or offset) between the sides

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/constraint/jumpCyclic`](../../../src/finiteVolume/fields/fvPatchFields/constraint/jumpCyclic)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/constraint/jumpCyclic/jumpCyclicFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/constraint/jumpCyclic/jumpCyclicFvPatchField.H)
- Inventory 备注：constraint

## 教程与模板
- 模板：[`etc/caseDicts/setConstraintTypes`](../../../etc/caseDicts/setConstraintTypes)

## 注意事项
- 约束 BC 名称必须与 mesh patch 类型一致，否则构造期报错。
