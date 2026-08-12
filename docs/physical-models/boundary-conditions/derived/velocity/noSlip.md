# noSlip

## 一句话
无滑移壁面：速度等于壁面速度（静止壁为零）。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`noSlip`
- **典型场**：`U`
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            noSlip;
}
```

## 参数表
源码头文件未提供标准 `Usage` 表，或参数由基类继承——请对照源码构造函数读取字典关键字。

## 控制方程与关联式
无滑移壁面：速度等于壁面速度（静止壁为零）。

类头 `Description` 原文：

> This boundary condition fixes the velocity to zero at walls and assumes
> the walls are stationary.
> 
> For stationary walls with sliding vertices, e.g. engine liners, the normal
> component of the velocity is set from the wall face-flux to ensure
> continuity.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/noSlip/noSlipFvPatchVectorField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/noSlip/noSlipFvPatchVectorField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/noSlip/noSlipFvPatchVectorField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/noSlip/noSlipFvPatchVectorField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/XiFluid/kivaTest/-180/U`](../../../tutorials/XiFluid/kivaTest/-180/U)
- [`tutorials/XiFluid/engine2Valve2D/0/U`](../../../tutorials/XiFluid/engine2Valve2D/0/U)
- [`tutorials/shockFluid/movingCone/0/U`](../../../tutorials/shockFluid/movingCone/0/U)
- [`tutorials/shockFluid/LadenburgJet60psi/0/U`](../../../tutorials/shockFluid/LadenburgJet60psi/0/U)
- [`tutorials/shockFluid/LadenburgJet60psi/0.orig/U`](../../../tutorials/shockFluid/LadenburgJet60psi/0.orig/U)
- [`tutorials/shockFluid/diffuserIntake/0/U`](../../../tutorials/shockFluid/diffuserIntake/0/U)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
