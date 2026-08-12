# 约定与条目模板

本文约定手册全文写法，保证 Phase 1–5 条目可检索、可对照源码。

## 命名

| 对象 | 约定 |
|------|------|
| 求解器 / 模型 / BC **类型名** | 保持 OpenFOAM 英文，如 `nutkWallFunction`、`kEpsilon`、`perfectGas` |
| 字典关键字 | 英文原文，代码格式：`` `type` `、`` `thermoType` ` |
| 手册文件名 | 与类型名一致或小写短横线；求解器页为 `solvers`/<module>.md` |
| 源码路径 | 相对仓库根，如 `src/finiteVolume/...` 或 `applications/modules/fluid/...` |
| 兼容标签 | `适用: fluid, isothermalFluid` / `不适用: incompressibleFluid` |

中文只用于说明性正文，不翻译类型名。

## 案例字典位置

| 位置 | 典型内容 |
|------|----------|
| `system/controlDict` | `application` foamRun`；`solver` 或多区域 `regionSolvers`；`functions` |
| `system/fvSchemes` / `fvSolution` | 离散与线性求解；PIMPLE 等 |
| `constant`/` | 物性与模型选择：`physicalProperties`、`thermophysicalProperties`、`momentumTransport`、`thermophysicalTransport`、`phaseProperties`、`chemistryProperties`、`combustionProperties`、`dynamicMeshDict`、`fvModels`、`fvConstraints` 等 |
| `0/`（或 `0.orig/`） | 场初值与边界：`U`、`p`、`T`、`alpha`.*`、`nut`、`k`、`epsilon`/`omega`、组分 `Y`.*` 等 |

多区域案例中，上述路径常位于 `constant/<region>/`、`system/<region>/`、`0/<region>/`。

薄膜、固体等区域求解器同样通过 `regionSolvers` 挂接。

## RTS（运行时选择）机制

OpenFOAM 用 **Run-Time Selection**：字典里的 `type` 字符串在运行时解析为已注册的 C++ 类型。

常见注册方式（写 inventory 时检索这些宏）：

- `addToRunTimeSelectionTable` / `addNamedToRunTimeSelectionTable`
- `makePatchFields` / `makeNullConstructablePatchFields`
- `makeThermo` / `forGases` / `forLiquids` / `forTabulated` / `forSolids`
- `makeRASModel` / `makeLESModel` / `makeLaminarModel`
- `makeFvModel` / `makeFvConstraint`

因此：

1. **类型名必须与注册名一致**（大小写敏感）。
2. **库必须已链接进当前 solver**（见各模块 `Make/options`）；仅存在于未链接库中的模型对当前求解器不可用。
3. 完整 `thermoType` 往往是宏展开的合法组合，而非任意拼接——以 [`src/thermophysicalModels/specie/include/`](../../src/thermophysicalModels/specie/include/) 为准。

本手册 [`_inventory`/`](_inventory/) 即上述宏的检索结果。

## 量纲约定

- 场与属性遵循 OpenFOAM `dimensionSet`（SI 基本量纲）。
- 手册参数表中量纲写作 OpenFOAM 风格，例如 `[0 2 -1 0 0 0 0]`（运动粘度）、`[1 -1 -2 0 0 0 0]`（压力）。
- 无量纲模型常数标 `[0 0 0 0 0 0 0]` 或注明「无量纲」。
- 字典示例优先带 `dimensions` 与 `internalField`/`boundaryField`，与 `etc/caseDicts` 一致。

## 强制模型条目模板

每个模型文件（Phase 1 起）必须使用下列章节，便于检索与对照：

```markdown
# <TypeName>

## 一句话
## 适用条件（求解器 / 场 / 前提）
## 字典示例
## 参数表
## 控制方程与关联式
## 文献与源码依据
## 教程与模板
## 注意事项
```

填写要点：

1. **适用条件**：显式列出可用求解器 / 区域 / 场；写清对 `thermoType`、`momentumTransport`、多相框架的依赖。
2. **字典示例**：可复制片段，标明位于 `constant`/`、`0/` 或 `system`/`。
3. **参数表**：每个入口的物理含义与量纲。
4. **控制方程 / 关联式**：优先摘自类头 `Description`、`.C` 实现与注释中的文献；写清假设。
5. **资源指针**：源码路径、`etc/caseDicts`、代表性 `tutorials`/`。
6. **注意事项**：典型拼写错误、与物性/湍流不匹配时的报错线索。

求解器导读页（`solvers/*.md`）在 Phase 0 已按同一结构的简化版落地（能力范围 + 字典提示 + 物理包证据），后续可增补完整字典示例。

## 单元格用语（矩阵）

| 标记 | 含义 |
|------|------|
| **内建** | 模块核心求解路径依赖该物理；案例几乎总要配置 |
| **可选** | 库已链接或 Description 写明可选（如 fvModels、辐射、Lagrangian） |
| **不可用** | 无对应库链接且物理上不适用（有证据） |
| **待填** | Phase 0 证据不足，留给后续 Phase 用教程/源码补全 |

## 质量底线

- 兼容性只写有证据的；不臆造文献号。
- 字典示例优先改写自 `etc/caseDicts` 与官方教程。
- 一条模型一个文件；大族用目录内 `README`.md` 做索引。
