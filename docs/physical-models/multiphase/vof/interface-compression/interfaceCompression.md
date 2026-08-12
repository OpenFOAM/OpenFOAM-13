# interfaceCompression

## 一句话
基于反梯度输运的界面压缩格式，保持 VoF 相分数界面尖锐。

## 适用条件（求解器 / 场 / 前提）
- **适用**: `incompressibleVoF`, `compressibleVoF`, `*MultiphaseVoF`
- **配置位置**: `system/fvSchemes` → `divSchemes` 中 `div`(phi,alpha)`（及多相对应项）
- **族**: `surfaceInterpolationScheme`（非 `phaseProperties` 子模型）
- **注册名**: `interfaceCompression`
- **前提**: 基格式应为保形 2 阶 NVD/TVD（如 `vanLeer`、`vanAlbada`）

## 字典示例

```c++
// `tutorials/multiphaseEuler/damBreak4phase/constant/phaseProperties`
oil_mercury
    {
        type            constant;
        sigma           0.4;
    }
}

interfaceCompression
{
    air_water       1;
    air_oil         1;
    air_mercury     1;
    water_oil       1;
    water_mercury   1;
    oil_mercury     1;
}

// ************************************************************************* //
```

## 参数表
| 入口 | 含义 | 典型值 |
|------|------|--------|
| 基格式 | `vanLeer` / `vanAlbada` 等 | `vanLeer` |
| 压缩系数 | >1 更强（可能贴网格）；<1 易抹平 | `1` |

## 控制方程与关联式
在合适的面插值相分数上叠加界面压缩通量（counter-gradient），抑制数值扩散导致的界面涂抹。详见类头 Description；同类还有几何重构族 `PLIC`/`PLICU`/`MPLIC`/`MPLICU` 与关闭项 `noInterfaceCompression`。

## 文献与源码依据
- 类: `Foam`::interfaceCompression`（实现类名 `interfaceCompressionNew`）
- 源码: `src/twoPhaseModels/interfaceCompression/interfaceCompression/interfaceCompression.{H,C}`
- See also: `PLIC`, `PLICU`, `MPLIC`, `MPLICU`

## 教程与模板
- 几乎所有 VoF 教程的 `system/fvSchemes`（如 `tutorials/incompressibleVoF/damBreakLaminar`）

## 注意事项
- 写在 **fvSchemes**，不是 `phaseProperties` 的 `type`。
- 压缩系数过大可能使界面贴齐网格线；过小则界面变厚。
- 与 MPLIC 族二选一时，勿混用未经验证的组合。
