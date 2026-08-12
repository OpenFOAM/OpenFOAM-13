# zeroInletOutlet

## 一句话
按通量方向在入口值与零梯度间切换。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`zeroInletOutlet`
- **典型场**：见源码 / 场量纲匹配
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patchName>
{
    type            zeroInletOutlet;
}
```

## 参数表
源码头文件未提供标准 `Usage` 表，或参数由基类继承——请对照源码构造函数读取字典关键字。

## 控制方程与关联式
按通量方向在入口值与零梯度间切换。

类头 `Description` 原文：

> This boundary condition provides a generic outflow condition
> 
> Zero gradient is applied for outflow and a zero value applied for reverse
> flow.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/zeroInletOutlet/zeroInletOutletFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/zeroInletOutlet/zeroInletOutletFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/zeroInletOutlet/zeroInletOutletFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/zeroInletOutlet/zeroInletOutletFvPatchField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/multiRegion/film/VoFToFilm/0/film/delta`](../../../tutorials/multiRegion/film/VoFToFilm/0/film/delta)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
