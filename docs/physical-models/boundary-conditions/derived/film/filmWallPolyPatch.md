# filmWallPolyPatch

## 一句话
薄膜类边界条件 `filmWallPolyPatch`。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`filmWallPolyPatch`
- **RTS `TypeName`**：`filmWall`（与字典名不同时以字典 `type` 为准）
- **典型场**：网格 patch 类型（非 fvPatchField）
- **库 / 加载**：模块本地：`isothermalFilm` / `film`
- **适用标签**：见库说明；不确定时查求解器 `Make/options`。
- **种类**：`meshPatch`（inventory 收录，但不是标准 volField `fvPatchField`）

## 字典示例
（非场 BC：在 `polyMesh/boundary` 或 Lagrangian 云配置中声明，见 `applications/modules/isothermalFilm/patches/filmWall/filmWallPolyPatch/filmWallPolyPatch.C`。）

## 参数表
源码头文件未提供标准 `Usage` 表，或参数由基类继承——请对照源码构造函数读取字典关键字。

## 控制方程与关联式
薄膜类边界条件 `filmWallPolyPatch`。

类头 `Description` 原文：

> Foam::filmWallPolyPatch

## 文献与源码依据
- 源码：[`applications/modules/isothermalFilm/patches/filmWall/filmWallPolyPatch/filmWallPolyPatch.C`](../../../applications/modules/isothermalFilm/patches/filmWall/filmWallPolyPatch/filmWallPolyPatch.C)
- 头文件：[`applications/modules/isothermalFilm/patches/filmWall/filmWallPolyPatch/filmWallPolyPatch.H`](../../../applications/modules/isothermalFilm/patches/filmWall/filmWallPolyPatch/filmWallPolyPatch.H)
- Inventory 备注：module-local BCs

## 教程与模板
- [`tutorials/isothermalFilm/rivuletPanel/system/blockMeshDict`](../../../tutorials/isothermalFilm/rivuletPanel/system/blockMeshDict)

## 注意事项
- 模块本地 BC：其他 solver 即使同名字段也不会注册该 `type`。
- 本条目来自 inventory 扩展收录；搭建 volField 边界时勿当作 `fvPatchField` 的 `type`。
