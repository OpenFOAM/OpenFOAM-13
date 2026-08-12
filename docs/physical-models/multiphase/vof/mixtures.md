# VoF 混合物（twoPhase / multiphase）

## 一句话
VoF 求解器通过混合物类把两相/多相物性合成单一动量方程用的 ρ、μ（及可压能量相关量）。

## 适用条件（求解器 / 场 / 前提）
| 求解器 | 混合物 / 物性证据 |
|--------|-------------------|
| `incompressibleVoF` | `incompressibleTwoPhaseVoFMixture`；链 `-lincompressibleTwoPhases` `-ltwoPhaseProperties` `-linterfaceProperties` |
| `compressibleVoF` | `compressibleTwoPhaseVoFMixture`；链 `-lcompressibleTwoPhases` `-lcompressibleInterfaceProperties` + fluidThermo |
| `incompressibleMultiphaseVoF` | 多相 VoF 混合物（`multiphaseProperties` / multiphaseVoFSolver 路径） |
| `compressibleMultiphaseVoF` | 可压等温多相混合物 + fluidThermo |

## 字典示例
两相不可压（`tutorials/incompressibleVoF/damBreakLaminar`）：
```
phases          (water air);
sigma           0.07;
```
各相密度/粘度在 `constant/physicalProperties.<phase>`（或等价物性文件）。

可压两相另需各相 `thermophysicalProperties` / `thermoType`，表面张力可用 `liquidProperties` 模型。

## 参数表
| 入口 | 含义 |
|------|------|
| `phases` | 相名列表；第一相常为“主”相（空化 `liquid` 指向） |
| `sigma` / `surfaceTensionForce` 相关 | 表面张力；可为标量或子字典 `type` |
| 分相 `physicalProperties`.*` | ν 或 thermo |

## 控制方程与关联式
混合物密度/粘度按相分数加权（具体实现见各 `*VoFMixture`）；动量方程对混合物求解，相分数输运带界面压缩通量。

## 文献与源码依据
- `src/twoPhaseModels/twoPhaseMixture/`
- `src/twoPhaseModels/incompressibleTwoPhases/` · `compressibleTwoPhases`/`
- `applications/modules/incompressibleVoF/incompressibleTwoPhaseVoFMixture/`
- `applications/modules/compressibleVoF/`（可压混合物）

## 教程与模板
- `tutorials/incompressibleVoF/damBreakLaminar`
- `tutorials/compressibleVoF/throttle`
- `tutorials/incompressibleMultiphaseVoF/damBreak4phaseLaminar`

## 注意事项
- 不可压与可压空化/表面张力库不同：见 [cavitation/](cavitation/) 与 [surface-tension/](surface-tension/)。
- 多相 VoF 的 `sigma` 常按相界面对给出（见各案例 `phaseProperties`）。
