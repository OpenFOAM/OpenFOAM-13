# liquidProperties（表面张力）

## 一句话
由液相 `liquidProperties` 物性类提供的温度相关表面张力 σ(T)（可压 VoF）。

## 适用条件（求解器 / 场 / 前提）
- **适用**: `compressibleVoF`（库 `compressibleInterfaceProperties`）
- **不适用**: 仅链 `interfaceProperties` 的不可压路径（无此 RTS）
- **族**: `surfaceTensionModel`
- **注册名**: `liquidProperties`
- **前提**: 指定相须有可用的 `liquidProperties` / thermo 液体物性表

## 字典示例
`constant/phaseProperties`：
```
sigma
{
    type    liquidProperties;
    phase   water;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `type` | `liquidProperties` | yes | — |
| `phase` | 提供 σ(T) 的液相名 | yes | — |

## 控制方程与关联式
\[
\sigma = \sigma_{\mathrm{liquidProperties}}(T)
\]
温度场取自网格；具体函数形式由该液体物性类实现（如饱和液体关联式）。

## 文献与源码依据
- 类: `Foam`::surfaceTensionModels::liquidProperties`
- 源码: `src/twoPhaseModels/compressibleInterfaceProperties/surfaceTensionModels/liquidProperties/liquidPropertiesSurfaceTension.{H,C}`

## 教程与模板
- `tutorials/compressibleVoF/damBreak/constant/phaseProperties`
- `tutorials/compressibleVoF/depthCharge2D/constant/phaseProperties`
- `tutorials/compressibleVoF/ballValve/constant/phaseProperties`
- `tutorials/multiRegion/CHT/VoFcoolingCylinder2D/constant/fluid/phaseProperties`

## 注意事项
- 与不可压常用的标量 `sigma` 0.07;` 或 `constant`/`temperatureDependent` 模型不同，本类型只在可压界面物性库中注册。
- `phase` 名须与 `phases` 列表中液体相一致。
