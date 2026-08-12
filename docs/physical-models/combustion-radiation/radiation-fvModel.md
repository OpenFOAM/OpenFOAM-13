# radiation（fvModel 激活）

## 一句话
OpenFOAM-13 中辐射源项通过 `constant/fvModels` 的 `type` radiation` 加载，再由 `constant/radiationProperties` 选择具体辐射模型。

## 适用条件（求解器 / 场 / 前提）
- **适用**: `fluid`, `multicomponentFluid`, `XiFluid`（Description 写明 radiation），多区域 CHT 的 fluid/solid 区域；其它链接了 `fvModels` 且加载 `libradiationModels`.so` 的区域
- **不适用**: 纯等温不可压路径（如默认 `incompressibleFluid`）通常无能量方程可接收辐射源
- **前提**: 区域有能量方程；`radiationProperties` 中配置 `radiationModel` 与吸收/散射/烟黑

## 字典示例

`constant/fvModels`（改写自 `tutorials/fluid/hotRadiationRoom`）：

```cpp
radiation
{
    type    radiation;
    libs    ("libradiationModels.so");
}
```

头文件 Usage 亦写作子字典形式：

```cpp
radiationCoeffs
{
    libs    ("libradiationModels.so");
    type    radiation;
}
```

同时需要 `constant/radiationProperties`（见 [radiation-models.md](radiation-models.md)）。

## 参数表

| 入口 | 含义 | 量纲/说明 |
|------|------|-----------|
| `type` | 必须为 `radiation` | — |
| `libs` | 动态库 `libradiationModels`.so` | 未链入模块静态库时必需 |

辐射模型自身参数在 `radiationProperties`，不在本 fvModel 条目内。

## 控制方程与关联式
fvModel 调用 `radiationModel`，向能量方程施加辐射源（吸收/发射净热流）。具体方程见所选 `radiationModel`（P1、fvDOM 等）。

## 文献与源码依据
- `src/radiationModels/fvModels/radiation/radiation.H`
- 教程：`tutorials/fluid/hotRadiationRoom`、`hotRadiationRoomFvDOM`；`tutorials/multicomponentFluid/smallPoolFire3D`；`tutorials/multiRegion/CHT/reverseBurner`

## 教程与模板
| 案例 | 说明 |
|------|------|
| `fluid/hotRadiationRoom` | P1 + `type` radiation` |
| `fluid/hotRadiationRoomFvDOM` | fvDOM |
| `multicomponentFluid/smallPoolFire3D` | 燃烧 + greyMeanCombustion + radiation fvModel |
| `multiRegion/CHT/reverseBurner` | gas/solid 双侧 radiation |

## 注意事项
- **仅写 `radiationProperties` 而不加 fvModel，在 v13 模块求解器上通常不会激活辐射源**（与旧 monolithic solver 习惯不同）。
- `libs` 拼写错误会导致 `Unknown fvModel type radiation`。
- 固体区域用 `opaqueSolid` 等时仍需同区域的 `fvModels` 条目。
