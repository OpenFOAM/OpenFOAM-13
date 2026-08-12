# 新 Lagrangian 框架（src/Lagrangian）

与经典 `cloudProperties` parcel 子模型并行存在。Inventory 中大量 `LagrangianModel` / `cloud` / `LagrangianPatch` 注册来自此树（常与 `src/lagrangian` 路径重复镜像）。

---

# 框架总览

## 一句话
以 `LagrangianMesh`、云类型（`particle`/`parcel`/`kinematicParticle`/…）和可组合 `LagrangianModel` 描述颗粒相。

## 适用条件（求解器 / 场 / 前提）
- 新案例/库可能直接用此框架；经典教程仍以 parcel `cloudProperties` 为主
- **需验证**具体 foamRun 模块默认链的是哪条路径（看 `Make/options` 与案例字典）

## 字典示例
依云与模型而异；注入类模型例如 `patchInjection`、`diskInjection` 作为 `LagrangianModel` 出现（非旧版 `InjectionModel` 同一基类）。

## 参数表
见下列分型。

## 控制方程与关联式
仍为拉格朗日点粒子/包裹跟踪；力与源项由模型列表累加。

## 文献与源码依据
- `src/Lagrangian/cloud/`
- `src/Lagrangian/Lagrangian/`

## 教程与模板
经典教程多为旧 parcel；新框架以源码测试与 inventory 为准（**缺口：官方 tutorials 覆盖少**）。

## 注意事项
- 同名 `patchInjection` 在两框架中基类不同，勿混拷贝字典结构。

---

# 云类型（cloud RTS）

| 类型 | 一句话 |
|------|--------|
| `particle` | 基础粒子云 |
| `parcel` | 包裹云 |
| `kinematicParticle` | 运动学粒子 |
| `kinematicParcel` | 运动学包裹 |

源码：`src/Lagrangian/cloud/clouds/`。

---

# LagrangianModel（力 / 注入 / 扩散）

| 类型 | 族 | 一句话 |
|------|----|--------|
| `gravity` | Force | 重力 |
| `SchillerNaumannDrag` | Force | Schiller–Naumann 阻力 |
| `GidaspowErgunWenYuDrag` | Force | Gidaspow Ergun–Wen–Yu |
| `SaffmanMeiLift` | Force | Saffman–Mei 升力 |
| `pressureGradientForce` | Force | 压力梯度力 |
| `constantCoefficientVirtualMass` | Force | 常系数虚拟质量 |
| `turbulentDispersion` | Dispersion | 湍流扩散 |
| `patchInjection` | Injection | patch 注入 |
| `diskInjection` | Injection | 盘源注入 |
| `pointInjection` | Injection | 点注入 |
| `volumeInjection` | Injection | 体积注入 |
| `manualInjection` | Injection | 手动位置注入 |

### 条目模板（共用）
- **适用**: 新 Lagrangian 云的模型列表
- **字典**: 模型名 + 模型专用 coeffs（见各 `.H` Usage）
- **方程**: 与经典同名物理类似，接口不同
- **依据**: `src/Lagrangian/cloud/LagrangianModels/<name>/`
- **注意**: inventory 对 `src/lagrangian` 与 `src/Lagrangian` 双份列出 — 计覆盖时去重

---

# LagrangianPatch（inventory 全名）

### 一句话
定义颗粒与边界网格拓扑的相交行为。

### 适用条件
新框架 `LagrangianMesh` 边界；类型名常为 `*LagrangianPatch`。

| TypeName | 角色 |
|----------|------|
| `LagrangianPatch` | 基类默认 |
| `wallLagrangianPatch` | 壁面 |
| `symmetryLagrangianPatch` | 对称 |
| `symmetryPlaneLagrangianPatch` | 对称面 |
| `wedgeLagrangianPatch` | 楔 |
| `emptyLagrangianPatch` | empty |
| `cyclicLagrangianPatch` | cyclic |
| `processorLagrangianPatch` | 处理器边界 |
| `processorCyclicLagrangianPatch` | 处理器 cyclic |
| `nonConformalCyclicLagrangianPatch` | 非共形 cyclic |
| `nonConformalProcessorCyclicLagrangianPatch` | 非共形处理器 cyclic |
| `nonConformalErrorLagrangianPatch` | 非共形误差 |
| `internalLagrangianPatch` | 内部 |
| `cloudVelocityLagrangianPatch` | 云速度派生 |

### 依据
`src/Lagrangian/Lagrangian/LagrangianMesh/LagrangianPatches/`（及 `src/lagrangian` 镜像）

---

# functionObjects（系统级云诊断）

写在 `system/functions`（或 controlDict functions），与 parcel 字典内 `cloudFunctions` **不同**（后者见 [parcel-collision-cloudFunctions.md](parcel-collision-cloudFunctions.md)）。

| TypeName | 一句话 |
|----------|--------|
| `cloudAge` | 云龄 |
| `cloudMass` | 云质量 |
| `cloudVolume` | 云体积 |
| `cloudVolumeFraction` | 体积分数 |
| `cloudLagrangianVolumeFraction` | Lagrangian 体积分数 |
| `cloudSurfaceArea` | 表面积 |
| `cloudSurfaceAreaPerUnitVolume` | 比表面积 |
| `cloudSurfaceDistribution` | 表面分布 |
| `cloudKineticEnergy` | 动能 |
| `cloudGravitationalPotentialEnergy` | 重力势能 |
| `cloudMassFlux` / `cloudNumberFlux` / `cloudVolumeFlux` | 通量 |
| `cloudBoundaryCollisionForce` | 边界碰撞力 |
| `cloudBoundaryCollisionNumberFlux` | 边界碰撞数通量 |
| `cloudInfo` | 云信息摘要 |
| `LagrangianFieldValue` | Lagrangian 场值统计 |
| `LagrangianDistribution` | 分布 |
| `particles` | 粒子写出/可视化辅助 |
| `stopAtEmptyClouds` | 空云停算 |
| `dsmcFields` | DSMC 场 |

### 依据
`src/Lagrangian/cloudFunctionObjects/`、`LagrangianFunctionObjects`/`、`functionObjects`/`

---

# 分子动力学（附：inventory 索引）

与工程 parcel **不同域**；路径 `src/Lagrangian/molecularDynamics/`（镜像 `src/lagrangian/...`）。Phase 4 **仅列类型名，不成独立方程页**。

| 基类 | TypeName |
|------|----------|
| `pairPotential` | `lennardJones`, `coulomb`, `dampedCoulomb`, `azizChen`, `maitlandSmith`, `exponentialRepulsion`, `noInteraction` |
| `tetherPotential` | `harmonicSpring`, `restrainedHarmonicSpring`, `pitchForkRing` |
| `energyScalingFunction` | `noScaling`, `shifted`, `shiftedForce`, `sigmoid`, `doubleSigmoid` |

**缺口**: 无官方工程 tutorials 条目；MD 求解器见 legacy `mdFoam` 等。

---

## 覆盖计数

| 项目 | 数量 |
|------|------|
| 云类型 | 4 |
| 主要 LagrangianModel（表内） | 12 |
| LagrangianPatch | inventory 14 名 ✓ |
| 系统 cloud FO | inventory 所列 ✓ |
| MD 势/缩放/拴系 | 索引表 ✓，方程页不做 |
| 与 parcel 重复路径 | 去重后计 1 |
