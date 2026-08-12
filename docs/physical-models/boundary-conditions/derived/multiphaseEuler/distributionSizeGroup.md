# distributionSizeGroup

## 一句话
multiphaseEuler类边界条件 `distributionSizeGroup`。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`distributionSizeGroup`
- **典型场**：f.* (size group)
- **库 / 加载**：模块本地：仅 `multiphaseEuler`
- **适用标签**：见库说明；不确定时查求解器 `Make/options`。

## 字典示例
```
<patchName>
{
    type        distributionSizeGroup;
    distribution
    {
        type        RosinRammler;
        Q           0;
        min         1 [mm];
        max         15 [mm];
        d           14 [mm];
        n           2 [];
    }
    value       $internalField;
}
```

## 参数表
源码头文件未提供标准 `Usage` 表，或参数由基类继承——请对照源码构造函数读取字典关键字。

## 控制方程与关联式
multiphaseEuler类边界条件 `distributionSizeGroup`。

类头 `Description` 原文：

> Boundary condition for size-group fractions that sets values corresponding
> to a given distribution

## 文献与源码依据
- 源码：[`applications/modules/multiphaseEuler/populationBalance/derivedFvPatchFields/distributionSizeGroup/distributionSizeGroupFvPatchScalarField.C`](../../../applications/modules/multiphaseEuler/populationBalance/derivedFvPatchFields/distributionSizeGroup/distributionSizeGroupFvPatchScalarField.C)
- 头文件：[`applications/modules/multiphaseEuler/populationBalance/derivedFvPatchFields/distributionSizeGroup/distributionSizeGroupFvPatchScalarField.H`](../../../applications/modules/multiphaseEuler/populationBalance/derivedFvPatchFields/distributionSizeGroup/distributionSizeGroupFvPatchScalarField.H)
- Inventory 备注：module-local BCs

## 教程与模板
- [`tutorials/multiphaseEuler/titaniaSynthesisSurface/0/f0.particles`](../../../tutorials/multiphaseEuler/titaniaSynthesisSurface/0/f0.particles)
- [`tutorials/multiphaseEuler/titaniaSynthesisSurface/0/fDefault.particles`](../../../tutorials/multiphaseEuler/titaniaSynthesisSurface/0/fDefault.particles)
- [`tutorials/multiphaseEuler/titaniaSynthesis/0/f0.particles`](../../../tutorials/multiphaseEuler/titaniaSynthesis/0/f0.particles)
- [`tutorials/multiphaseEuler/titaniaSynthesis/0/fDefault.particles`](../../../tutorials/multiphaseEuler/titaniaSynthesis/0/fDefault.particles)

## 注意事项
- 模块本地 BC：其他 solver 即使同名字段也不会注册该 `type`。
