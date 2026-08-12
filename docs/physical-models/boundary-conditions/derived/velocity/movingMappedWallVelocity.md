# movingMappedWallVelocity

## 一句话
无滑移壁面：速度取壁面速度（静止壁为零）。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`movingMappedWallVelocity`
- **典型场**：`U`
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            movingMappedWallVelocity;
    value           uniform (0 0 0);    // Initial value
}
```

## 参数表
源码头文件未提供标准 `Usage` 表，或参数由基类继承——请对照源码构造函数读取字典关键字。

## 控制方程与关联式
无滑移壁面：速度取壁面速度（静止壁为零）。

类头 `Description` 原文：

> This boundary condition provides a no-slip velocity condition for mapped
> walls. The wall velocity is taken to be the mesh velocity of the
> neighbouring region.
> 
> This will typically be used in CHT simulations in order to apply the
> mesh motion of a solid region to the boundary of the adjacent fluid
> region.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/movingMappedWallVelocity/movingMappedWallVelocityFvPatchVectorField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/movingMappedWallVelocity/movingMappedWallVelocityFvPatchVectorField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/movingMappedWallVelocity/movingMappedWallVelocityFvPatchVectorField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/movingMappedWallVelocity/movingMappedWallVelocityFvPatchVectorField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/multiRegion/CHT/notchedRoller/0/fluid/U`](../../../tutorials/multiRegion/CHT/notchedRoller/0/fluid/U)
- [`tutorials/multiRegion/CHT/engine2Valve2D/0/fluid/U`](../../../tutorials/multiRegion/CHT/engine2Valve2D/0/fluid/U)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
