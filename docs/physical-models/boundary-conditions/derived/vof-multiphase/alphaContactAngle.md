# alphaContactAngle

## 一句话
多相 `alpha` 接触角基类/接口边界。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`alphaContactAngle`
- **典型场**：`alpha`.*`
- **库 / 加载**：需 `libmultiphaseProperties`

## 字典示例
```
<patchName>
{
    type            alphaContactAngle;

    contactAngleProperties
    {
        // Constant contact angle with air
        air
        {
            theta0          90;
        }

        // Dynamic contact angle with water
        oil
        {
            theta0          70;
            uTheta          1;
            thetaA          100;
            thetaR          50;
        }
    }

    value           uniform 0;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `theta0` | Equilibrium contact angle | yes |  |
| `uTheta` | Velocity scale | no | none |
| `thetaA` | Limiting advancing contact angle | if uTheta | none |
| `thetaR` | Limiting receding contact angle | if uTheta | none |

## 控制方程与关联式
多相 `alpha` 接触角基类/接口边界。

类头 `Description` 原文：

> Contact-angle boundary condition for multi-phase interface-capturing
> simulations. Sets of coefficients are given for the contact angle with each
> other phase. These coefficients can specify either a constant or a dynamic
> contact angle.

## 文献与源码依据
- 源码：[`src/multiphaseModels/multiphaseProperties/alphaContactAngle/alphaContactAngleFvPatchScalarField.C`](../../../src/multiphaseModels/multiphaseProperties/alphaContactAngle/alphaContactAngleFvPatchScalarField.C)
- 头文件：[`src/multiphaseModels/multiphaseProperties/alphaContactAngle/alphaContactAngleFvPatchScalarField.H`](../../../src/multiphaseModels/multiphaseProperties/alphaContactAngle/alphaContactAngleFvPatchScalarField.H)
- Inventory 备注：multiphase BCs

## 教程与模板
- [`tutorials/multiphaseEuler/damBreak4phase/0/alpha.air.orig`](../../../tutorials/multiphaseEuler/damBreak4phase/0/alpha.air.orig)
- [`tutorials/multiphaseEuler/damBreak4phase/0/alpha.mercury.orig`](../../../tutorials/multiphaseEuler/damBreak4phase/0/alpha.mercury.orig)
- [`tutorials/multiphaseEuler/damBreak4phase/0/alpha.oil.orig`](../../../tutorials/multiphaseEuler/damBreak4phase/0/alpha.oil.orig)
- [`tutorials/multiphaseEuler/damBreak4phase/0/alpha.water.orig`](../../../tutorials/multiphaseEuler/damBreak4phase/0/alpha.water.orig)
- [`tutorials/incompressibleMultiphaseVoF/damBreak4phaseLaminar/0/alpha.air.orig`](../../../tutorials/incompressibleMultiphaseVoF/damBreak4phaseLaminar/0/alpha.air.orig)
- [`tutorials/incompressibleMultiphaseVoF/damBreak4phaseLaminar/0/alpha.mercury.orig`](../../../tutorials/incompressibleMultiphaseVoF/damBreak4phaseLaminar/0/alpha.mercury.orig)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
