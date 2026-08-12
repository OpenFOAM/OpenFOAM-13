# `kOmegaSST`

## 一句话

k–ω SST

## 适用条件（求解器 / 场 / 前提）

- 注册：incompressible + compressible
- phaseCompressible 子集含 `kEpsilon`/`RNGkEpsilon`/`kOmegaSST`
- phaseIncompressible 子集含 `kEpsilon`/`kOmegaSST`

## 字典示例



```c++
// `tutorials/XiFluid/engine2Valve2D/constant/momentumTransport`
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

simulationType  RAS;

RAS
{
  model        kOmegaSST;
  turbulence   on;
}

// ************************************************************************* //
```

## 参数表

系数通常可在模型子字典覆盖（`Cmu`、`Ck` 等）；默认值见源码 `read`()`。

## 控制方程与关联式

Specialisation for RAS of the generic kOmegaSSTBase base class.
For more information, see Description of kOmegaSSTBase.H

See also
Foam::kOmegaSST

## 文献与源码依据

- [`src/MomentumTransportModels/momentumTransportModels/RAS/kOmegaSST/kOmegaSST.H`](../../../src/MomentumTransportModels/momentumTransportModels/RAS/kOmegaSST/kOmegaSST.H)

## 教程与模板

- `tutorials/XiFluid/engine2Valve2D/constant/momentumTransport`
- `tutorials/shockFluid/diffuserIntake/constant/momentumTransport`
- `tutorials/multiRegion/CHT/wallBoiling/constant/fluid/momentumTransport.gas`
- `tutorials/multiRegion/CHT/wallBoiling/constant/fluid/momentumTransport.liquid`
- `tutorials/multiRegion/CHT/coolingSphere/templates/materials/air/momentumTransport`
- `tutorials/multiRegion/CHT/coolingSphere/templates/materials/water/momentumTransport`


## 注意事项

- 模型必须在对应库中注册（不可压/可压/相）；见族 README 注册表。
