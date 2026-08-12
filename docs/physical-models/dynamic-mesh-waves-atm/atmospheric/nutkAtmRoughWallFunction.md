# nutkAtmRoughWallFunction

## 一句话

大气粗糙壁 nut 壁面函数

## 适用条件（求解器 / 场 / 前提）

nut 边界

## 字典示例

```c++
<patchName>
{
    type            nutkAtmRoughWallFunction;
    z0              uniform 0;
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

> This boundary condition provides a turbulent kinematic viscosity for
> atmospheric velocity profiles.  It is designed to be used in conjunction
> with the atmBoundaryLayerInletVelocity boundary condition.  The values
> are calculated using:
>
>     $$
>         U = frac{U_f}{\kappa} ln(\frac{z + z_0}{z_0})
>     $$
>
> where
>
> 
>     U_f    | frictional velocity
>     \kappa | Von Karman's constant
>     z_0    | surface roughness length
>     z      | vertical co-ordinate
> 

## 文献与源码依据

- 源码：[`src/atmosphericModels/derivedFvPatchFields/nutkAtmRoughWallFunction/nutkAtmRoughWallFunctionFvPatchScalarField.H`](../../../../src/atmosphericModels/derivedFvPatchFields/nutkAtmRoughWallFunction/nutkAtmRoughWallFunctionFvPatchScalarField.H)
- 实现：同目录 `.C`

## 教程与模板

- 大气/城市冠层相关 tutorials；BC 细目 Phase 2

## 注意事项

- `type` 拼写须与 RTS 一致
- 库未 `libs` 加载或不在求解器链接集时会报 unknown type
