# simple

## 一句话
漂移通量相对速度的简单指数衰减模型：\(U_{dm} = U_{dm,\mathrm{coeff}}\times\) 加速度。

## 适用条件（求解器 / 场 / 前提）
- 适用: incompressibleDriftFlux
- **族**: 相对速度（基类 `relativeVelocityModel`）
- **注册名**: `simple`

## 字典示例
```
// constant/phaseProperties
phases (sludge water);
relativeVelocityModel simple;

"(simple|general)Coeffs"
{
    Vc              2.241e-4;
    a               285.84;
    a1              0.1;      // general 用；simple 可读忽略
    residualAlpha   0;
}
```
（`tutorials/incompressibleDriftFlux/mixerVessel2DMRF`）

## 参数表
| 参数 | 含义 | 量纲 | 必需 |
|------|------|------|------|
| `a` | 分散相分数衰减指数 | 无量纲 | yes |
| `Vc` | 特征漂移时间尺度系数 | `[0 0 1 0 0 0 0]` | yes |

## 控制方程与关联式
`UdmCoeff`()`（`simple`.C`）：

\[
U_{dm,\mathrm{coeff}}
= \frac{\rho_c}{\rho}\, V_c \, 10^{-a\,\max(\alpha_d,0)}
\]

其中 \(\rho_c\) 连续相密度、\(\rho\) 混合物密度、\(\alpha_d\) 分散相分数；漂移速度 \(U_{dm}=U_{dm,\mathrm{coeff}}\times\) 加速度（重力等，见基类）。

## 文献与源码依据
- 类: `Foam`::relativeVelocityModels::simple`
- 源码: `applications/modules/incompressibleDriftFlux/relativeVelocityModels/simple/simple.C`

## 教程与模板
- `tutorials/incompressibleDriftFlux/mixerVessel2DMRF/constant/phaseProperties`

## 注意事项
- 与 `general` / `MichaelsBolger` 二选一；Coeffs 子字典名需匹配所选 `relativeVelocityModel`。
