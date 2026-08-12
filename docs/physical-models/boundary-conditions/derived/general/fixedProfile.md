# fixedProfile

## 一句话
给定固定边界值（Dirichlet）。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`fixedProfile`
- **典型场**：见源码 / 场量纲匹配
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            fixedProfile;
    profile         table;
    profileCoeffs
    {
        file                "UProfile";
        format              csv;
        nHeaderLine         0;
        columns             (0 (1 2 3));
        separator           ",";
        mergeSeparators     no;
        outOfBounds         clamp;
        interpolationScheme linear;
    }
    direction        (0 1 0);
    origin           0;
}
```

```
inlet
{
    type            fixedProfile;
    profile         polynomial
    (
        ((1 0 0)        (0 0 0))
        ((-6200 0 0)    (2 0 0))
    );
    direction       (0 1 0);
    origin          0.0127;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `profile` | Profile function | yes |  |
| `direction` | Direction of the line along which the profile is \\ |  |  |
| `evaluated` | yes |  |  |
| `origin` | Origin of the line along which the profile is \\ |  |  |
| `evaluated` | yes |  |  |

## 控制方程与关联式
给定固定边界值（Dirichlet）。

类头 `Description` 原文：

> This boundary condition provides a fixed value profile condition.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/fixedProfile/fixedProfileFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/fixedProfile/fixedProfileFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/fixedProfile/fixedProfileFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/fixedProfile/fixedProfileFvPatchField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/multiphaseEuler/titaniaSynthesisSurface/0/T.particles`](../../../tutorials/multiphaseEuler/titaniaSynthesisSurface/0/T.particles)
- [`tutorials/multiphaseEuler/titaniaSynthesisSurface/0/T.vapour`](../../../tutorials/multiphaseEuler/titaniaSynthesisSurface/0/T.vapour)
- [`tutorials/multiphaseEuler/titaniaSynthesis/0/T.particles`](../../../tutorials/multiphaseEuler/titaniaSynthesis/0/T.particles)
- [`tutorials/multiphaseEuler/titaniaSynthesis/0/T.vapour`](../../../tutorials/multiphaseEuler/titaniaSynthesis/0/T.vapour)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
