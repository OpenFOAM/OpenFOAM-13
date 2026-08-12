# VoFClouds

## 一句话
在可压 VoF 中耦合 Lagrangian 颗粒云，对相连续/能量与混合物动量方程加源。

## 适用条件（求解器 / 场 / 前提）
- **适用**: `compressibleVoF`（独立库 `libVoFClouds`，见模块 `Allwmake`）
- **不适用**: `incompressibleVoF`、`*MultiphaseVoF`（无对应实现）
- **族**: VoF 专用 fvModel（基类 `fvModel`）
- **注册名**: `VoFClouds`
- **前提**: 案例需配置 Lagrangian `cloudProperties` 等；载体相为 VoF 两相之一

## 字典示例

```c++
// `tutorials/multiRegion/film/cylinderVoF/constant/VoF/fvModels`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

VoFClouds
{
    type    VoFClouds;

    phase   liquid;
    carrierPhase air;
}

VoFFilmTransfer
{
    type        VoFFilmTransfer;

    libs        ("libfilmVoFTransfer.so");

    filmPatch   film;
    phase       liquid;

    deltaFactorToFilm 0;
    alphaToFilm       0;

    transferRateCoeff 0.1;
}

// ************************************************************************* //
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `type` | 必须为 `VoFClouds` | yes | — |
| `phase` | Lagrangian 相（云所属相）名 | yes | — |
| `carrierPhase` | 载体连续相名（若字典提供） | no | 实现内解析 |

## 控制方程与关联式
`correct`()` 推进 `parcelCloudList`；`addSup` 分别向：
- 相连续方程（`alpha`, rho`）
- 相能量方程（`alpha`, rho, he`）
- 混合物动量方程（`rho`, U`）

注入质量/动量/能量源。具体曳力、蒸发等由云子模型决定（见 Lagrangian 手册）。

## 文献与源码依据
- 类: `Foam`::fv::VoFClouds`
- 源码: `applications/modules/compressibleVoF/fvModels/VoFClouds/VoFClouds.{H,C}`
- 库: `applications/modules/compressibleVoF/Allwmake` → `libVoFClouds`

## 教程与模板
- `tutorials/multiRegion/film/cylinderVoF/constant/VoF/fvModels`

## 注意事项
- 仅 `compressibleVoF` 链接；在不可压 VoF 中配置会找不到类型/库。
- 与通用 `clouds` fvModel 不同，本模型绑定 VoF 两相 thermo。
- 求解器有效性总表：[../solver-validity.md](../solver-validity.md)
