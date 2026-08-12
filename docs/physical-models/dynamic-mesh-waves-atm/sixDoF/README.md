# 六自由度（sixDoF）与刚体相关

## 一句话

浮体/刚体动力运动：由 `sixDoFRigidBodyMotionSolver` 或 `rigidBodyMeshMotion`*` 驱动网格，约束与阻尼器在 motion 字典中选择。

## 结构

| 类别 | 类型 | 文档 |
|------|------|------|
| motionSolver | `sixDoFRigidBodyMotionSolver` | [../motionSolvers/sixDoFRigidBodyMotionSolver.md](../motionSolvers/sixDoFRigidBodyMotionSolver.md) |
| motionSolver | `rigidBodyMeshMotion` | [../motionSolvers/rigidBodyMeshMotion.md](../motionSolvers/rigidBodyMeshMotion.md) |
| sixDoFSolver | `Newmark` / `CrankNicolson` / `symplectic` | 本目录 |
| 规定运动 | `sixDoFMotion`（solidBody 函数） | [../solidBodyMotionFunctions/sixDoFMotion.md](../solidBodyMotionFunctions/sixDoFMotion.md) |
| fvModel | `sixDoFAcceleration` | [../../fv-models-constraints/general/sixDoFAcceleration.md](../../fv-models-constraints/general/sixDoFAcceleration.md) |
| 约束 | `axis`/`line`/`orientation`/`plane`/`point` | [constraints/](constraints/) |
| 阻尼弹簧 | `linearSpring` 等 | [restraints/](restraints/) |
| 多体关节 | `Px`/`Rx`/`floating`… | [joints/](joints/) |
| 刚体 | `cuboid`/`sphere`… | [bodies/](bodies/) |
| 监视 FO | `rigidBodyState` 等 | [functionObjects/](functionObjects/) |

## 注意事项

- **动力 sixDoF**（求解刚体 ODE）≠ **规定 sixDoFMotion**（时间函数位移）。
- 浮体常与 `waveForcing` / 波浪 BC 同用。
