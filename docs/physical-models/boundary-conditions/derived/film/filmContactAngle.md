# filmContactAngle

## 一句话
薄膜区域壁面接触角条件。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`filmContactAngle`
- **典型场**：`alpha`.*`
- **库 / 加载**：模块本地：`isothermalFilm` / `film`
- **适用标签**：见库说明；不确定时查求解器 `Make/options`。

## 字典示例
```
<patchName>
{
    type            filmContactAngle;

    contactAngle
    {
        type                constant;
        theta0              70;
    }
}
```

```
<patchName>
{
    type            filmContactAngle;

    theta0          70;
}
```

```
<patchName>
{
    type            filmContactAngle;

    contactAngle
    {
        type           dynamic;
        uTheta         1;
        theta0         70;
        thetaAdv       100;
        thetaRec       50;
    }
}
```

## 参数表
源码头文件未提供标准 `Usage` 表，或参数由基类继承——请对照源码构造函数读取字典关键字。

## 控制方程与关联式
薄膜区域壁面接触角条件。

类头 `Description` 原文：

> Film contact angle boundary condition.

## 文献与源码依据
- 源码：[`applications/modules/isothermalFilm/derivedFvPatchFields/filmContactAngle/filmContactAngleFvPatchScalarField.C`](../../../applications/modules/isothermalFilm/derivedFvPatchFields/filmContactAngle/filmContactAngleFvPatchScalarField.C)
- 头文件：[`applications/modules/isothermalFilm/derivedFvPatchFields/filmContactAngle/filmContactAngleFvPatchScalarField.H`](../../../applications/modules/isothermalFilm/derivedFvPatchFields/filmContactAngle/filmContactAngleFvPatchScalarField.H)
- Inventory 备注：module-local BCs

## 教程与模板
- [`tutorials/multiRegion/film/splashPanel/0/film/delta`](../../../tutorials/multiRegion/film/splashPanel/0/film/delta)
- [`tutorials/multiRegion/film/rivuletPanel/0/film/delta`](../../../tutorials/multiRegion/film/rivuletPanel/0/film/delta)
- [`tutorials/multiRegion/film/rivuletBox/0/film/delta`](../../../tutorials/multiRegion/film/rivuletBox/0/film/delta)
- [`tutorials/multiRegion/film/hotBoxes/0/film/delta`](../../../tutorials/multiRegion/film/hotBoxes/0/film/delta)
- [`tutorials/multiRegion/film/cylinderVoF/0/film/delta`](../../../tutorials/multiRegion/film/cylinderVoF/0/film/delta)
- [`tutorials/multiRegion/film/cylinderDripping/0/film/delta`](../../../tutorials/multiRegion/film/cylinderDripping/0/film/delta)

## 注意事项
- 模块本地 BC：其他 solver 即使同名字段也不会注册该 `type`。
