# `SpalartAllmarasDDES`

## 一句话

SA-DDES

## 适用条件（求解器 / 场 / 前提）
- 注册：incompressible + compressible
- phase* 子集：`Smagorinsky`/`kEqn`（见 phase*Models.C）

## 字典示例

```c++
// `tutorials/incompressibleFluid/cylinder/constant/momentumTransport`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// simulationType laminar;
RAS
{
model kOmegaSST;
turbulence on;
printCoeffs on;
}
LES
{
model SpalartAllmarasDDES;
delta cubeRootVol;
turbulence on;
printCoeffs on;
cubeRootVolCoeffs
{
deltaCoeff 1;
}
smoothCoeffs
{
delta cubeRootVol;
cubeRootVolCoeffs
{
deltaCoeff 1;
}
maxDeltaRatio 1.1;
}

}
// *************************************************************************
//

```
## 参数表

系数通常可在模型子字典覆盖（`Cmu`、`Ck` 等）；默认值见源码 `read`()`。

## 控制方程与关联式

SpalartAllmaras DDES turbulence model for incompressible and compressible flows



## 文献与源码依据

- [`src/MomentumTransportModels/momentumTransportModels/LES/SpalartAllmarasDDES/SpalartAllmarasDDES.H`](../../../src/MomentumTransportModels/momentumTransportModels/LES/SpalartAllmarasDDES/SpalartAllmarasDDES.H)

## 教程与模板

- `tutorials/multiRegion/CHT/coolingSphere/templates/materials/air/momentumTransport`
- `tutorials/multiRegion/CHT/coolingSphere/templates/materials/water/momentumTransport`
- `tutorials/incompressibleFluid/motorBike/lesFiles/momentumTransport`
- `tutorials/incompressibleFluid/drivaerFastback/constant/momentumTransport`
- `tutorials/incompressibleFluid/cylinder/constant/momentumTransport`


## 注意事项

- 模型必须在对应库中注册（不可压/可压/相）；见族 README 注册表。
