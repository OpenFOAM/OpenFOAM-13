# translatingWallVelocity

## 一句话
运动壁面速度边界。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`translatingWallVelocity`
- **典型场**：`U`
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            translatingWallVelocity;
    U               (100 0 0);
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `U` | translational velocity | yes |  |

## 控制方程与关联式
运动壁面速度边界。

类头 `Description` 原文：

> This boundary condition provides a velocity condition for translational
> motion on walls.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/translatingWallVelocity/translatingWallVelocityFvPatchVectorField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/translatingWallVelocity/translatingWallVelocityFvPatchVectorField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/translatingWallVelocity/translatingWallVelocityFvPatchVectorField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/translatingWallVelocity/translatingWallVelocityFvPatchVectorField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/incompressibleDriftFlux/tank3D/0/U`](../../../tutorials/incompressibleDriftFlux/tank3D/0/U)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
