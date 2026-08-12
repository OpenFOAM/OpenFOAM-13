# interfaceCompression

## 一句话
VoF / 多相类边界条件 `interfaceCompression`。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`interfaceCompression`
- **典型场**：`alpha`.*`
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            interfaceCompression;
    // 其余条目见源码 Usage / 教程
    value           $internalField;
}
```

## 参数表
源码头文件未提供标准 `Usage` 表，或参数由基类继承——请对照源码构造函数读取字典关键字。

## 控制方程与关联式
VoF / 多相类边界条件 `interfaceCompression`。

类头 `Description` 原文：

> Applies interface-compression to the phase-fraction distribution at the
> patch by setting the phase-fraction to 0 if it is below 0.5, otherwise
> to 1.
> 
> This approach is useful to avoid unphysical "bleed" of the lighter phase
> along the surface in regions of high shear adjacent to the surface which
> is at a shallow angle to the interface.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/interfaceCompression/interfaceCompressionFvPatchScalarField.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/interfaceCompression/interfaceCompressionFvPatchScalarField.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/interfaceCompression/interfaceCompressionFvPatchScalarField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/interfaceCompression/interfaceCompressionFvPatchScalarField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/incompressibleVoF/planingHullW3/0/alpha.water.orig`](../../../tutorials/incompressibleVoF/planingHullW3/0/alpha.water.orig)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
