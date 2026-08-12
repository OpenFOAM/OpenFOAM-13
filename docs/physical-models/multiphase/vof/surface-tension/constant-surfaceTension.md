# constant

## 一句话
Uniform constant surface tension model.

## 适用条件（求解器 / 场 / 前提）
- 适用: incompressibleVoF / incompressibleMultiphaseVoF（`interfaceProperties`）
- **族**: VoF 表面张力（基类 `surfaceTensionModel`）
- **注册名**: `constant`

## 字典示例
```
sigma
{
type                constant;
sigma               0.07;
}
```

## 参数表
（头文件未提供参数 `\table`；以源码构造函数读入的字典关键字为准。）

- 注册名 / `type`: `constant`
- 基类: `surfaceTensionModel`


## 控制方程与关联式
Uniform constant surface tension model.

## 文献与源码依据
- 类: `Foam`::surfaceTensionModels::constant`
- 源码路径: `src/twoPhaseModels/interfaceProperties/surfaceTensionModels/constant/constantSurfaceTension.C`

## 教程与模板
- `tutorials/multiRegion/film/VoFToFilm/constant/VoF/phaseProperties`
- `tutorials/multiRegion/film/cylinderVoF/constant/VoF/phaseProperties`
- `tutorials/multiRegion/CHT/wallBoiling/constant/fluid/phaseProperties`
- `tutorials/multiRegion/CHT/VoFcoolingCylinder2D/constant/fluid/phaseProperties`
- `tutorials/multiRegion/CHT/multiphaseCoolingCylinder2D/constant/fluid/phaseProperties`

## 注意事项
- 类型名必须与 RTS 注册名一致：`constant`。
