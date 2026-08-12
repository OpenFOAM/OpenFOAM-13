# mappedFilmSurfaceFvPatch

## 一句话
从另一区域/补丁映射场值或通量。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`mappedFilmSurfaceFvPatch`
- **典型场**：网格 patch 类型（非 fvPatchField）
- **库 / 加载**：模块本地：`isothermalFilm` / `film`
- **适用标签**：见库说明；不确定时查求解器 `Make/options`。
- **种类**：`meshPatch`（inventory 收录，但不是标准 volField `fvPatchField`）

## 字典示例
（非场 BC：在 `polyMesh/boundary` 或 Lagrangian 云配置中声明，见 `applications/modules/isothermalFilm/patches/mappedFilmSurface/mappedFilmSurfaceFvPatch/mappedFilmSurfaceFvPatch.C`。）

## 参数表
源码头文件未提供标准 `Usage` 表，或参数由基类继承——请对照源码构造函数读取字典关键字。

## 控制方程与关联式
未见独立 Description 段落；行为以实现 `.C` 与基类为准。

## 文献与源码依据
- 源码：[`applications/modules/isothermalFilm/patches/mappedFilmSurface/mappedFilmSurfaceFvPatch/mappedFilmSurfaceFvPatch.C`](../../../applications/modules/isothermalFilm/patches/mappedFilmSurface/mappedFilmSurfaceFvPatch/mappedFilmSurfaceFvPatch.C)
- 头文件：[`applications/modules/isothermalFilm/patches/mappedFilmSurface/mappedFilmSurfaceFvPatch/mappedFilmSurfaceFvPatch.H`](../../../applications/modules/isothermalFilm/patches/mappedFilmSurface/mappedFilmSurfaceFvPatch/mappedFilmSurfaceFvPatch.H)
- Inventory 备注：module-local BCs

## 教程与模板
- 未在 `tutorials`/` / `etc/caseDicts/` 中自动检索到 `type` 命中（或极少使用）；请用仓库内搜索 `type`            mappedFilmSurfaceFvPatch`。

## 注意事项
- 模块本地 BC：其他 solver 即使同名字段也不会注册该 `type`。
- 本条目来自 inventory 扩展收录；搭建 volField 边界时勿当作 `fvPatchField` 的 `type`。
