# radiation

## 一句话

辐射能量源包装器（加载 radiationModel）

## 适用条件（求解器 / 场 / 前提）

适用: 有能量方程且链 `-lfvModels` 的求解器（教程实证：`fluid`、`multicomponentFluid`、`XiFluid`、`film`、`solid`；库链接允许但无官方辐射教程：`shockFluid`、`compressibleVoF`、`multiphaseEuler`）。需 `libs` ("libradiationModels.so")` 与 `radiationProperties`。

不适用: 等温/无能量模块（如 `incompressibleFluid`、`isothermalFluid`、不可压 VoF）

## 字典示例



```c++
// `tutorials/fluid/hotRadiationRoomFvDOM/constant/fvModels`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

radiation
{
    type    radiation;
    libs    ("libradiationModels.so");
}

// ************************************************************************* //
```

## 参数表

主要入口以源码 `Usage` 为准。常见关键字见字典示例；完整列表与默认值见对应 `.H`。

| 说明 | |
|------|--|
| 配置位置 | 通常 `constant/fvModels` 或 `constant/fvConstraints` / `constant/dynamicMeshDict` |
| 选择关键字 | `type`（须与 RTS 注册名一致） |
| 区域选择 | 多数源/约束需要 `cellZone` 或等价选择 |


## 控制方程与关联式

摘自源码头文件 `Description`（原文）：

> Calculates and applies the radiation source to the energy equation.

## 文献与源码依据

- 源码：[`src/radiationModels/fvModels/radiation/radiation.H`](../../../../src/radiationModels/fvModels/radiation/radiation.H)
- 实现：同目录 `.C`

## 教程与模板

- `tutorials/fluid/hotRadiationRoom`、`hotRadiationRoomFvDOM`
- `tutorials/multicomponentFluid/smallPoolFire*`、`SandiaD_LTS`、`simplifiedSiwek`
- `tutorials/multiRegion/CHT/reverseBurner`（gas/solid）
- 辐射模型细目见 `combustion`-radiation/`（Phase 4）

## 注意事项

- 必须同时配置 `constant/radiationProperties` 的 `radiationModel`
- `fvModels` 中需 `libs` ("libradiationModels.so");`
- 等温求解器无能量方程，不宜使用
