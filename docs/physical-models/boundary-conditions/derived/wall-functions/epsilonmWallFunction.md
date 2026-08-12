# epsilonmWallFunction

## 一句话
高 Re 壁面函数，用近壁解析关联闭合湍流量。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`epsilonmWallFunction`
- **典型场**：nut / nuTilda, k / epsilon / omega / f / v2
- **库 / 加载**：需动量输运库（如 `libmomentumTransportModels` / 相专用库）；通常由启用湍流的求解器链接
- **前提**：启用 RAS/LES 壁面函数湍流模型；近壁网格满足 y+ 假设。

## 字典示例
```
<patchName>
{
    type            epsilonmWallFunction;
    value           uniform 0;
}
```

## 参数表
源码头文件未提供标准 `Usage` 表，或参数由基类继承——请对照源码构造函数读取字典关键字。

## 控制方程与关联式
高 Re 壁面函数，用近壁解析关联闭合湍流量。

类头 `Description` 原文：

> This boundary condition provides a turbulence dissipation wall constraint
> for the mixtureKEpsilon model

## 文献与源码依据
- 源码：[`src/MomentumTransportModels/phaseCompressible/derivedFvPatchFields/wallFunctions/epsilonWallFunctions/epsilonmWallFunction/epsilonmWallFunctionFvPatchScalarField.C`](../../../src/MomentumTransportModels/phaseCompressible/derivedFvPatchFields/wallFunctions/epsilonWallFunctions/epsilonmWallFunction/epsilonmWallFunctionFvPatchScalarField.C)
- 头文件：[`src/MomentumTransportModels/phaseCompressible/derivedFvPatchFields/wallFunctions/epsilonWallFunctions/epsilonmWallFunction/epsilonmWallFunctionFvPatchScalarField.H`](../../../src/MomentumTransportModels/phaseCompressible/derivedFvPatchFields/wallFunctions/epsilonWallFunctions/epsilonmWallFunction/epsilonmWallFunctionFvPatchScalarField.H)
- Inventory 备注：momentum transport / wall functions

## 教程与模板
- [`tutorials/multiRegion/CHT/multiphaseCoolingCylinder2D/0/fluid/epsilonm`](../../../tutorials/multiRegion/CHT/multiphaseCoolingCylinder2D/0/fluid/epsilonm)
- [`tutorials/multiphaseEuler/bubbleColumn/0/epsilonm`](../../../tutorials/multiphaseEuler/bubbleColumn/0/epsilonm)

## 注意事项
- 壁面函数场（`nut`/`k`/`epsilon`/`omega`/`alphat`）需成套配置，勿与低 Re 积分壁面混用。
