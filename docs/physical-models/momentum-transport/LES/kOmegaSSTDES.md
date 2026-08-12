# `kOmegaSSTDES`

## 一句话

SST-DES

## 适用条件（求解器 / 场 / 前提）

- 注册：incompressible + compressible
- phase* 子集：`Smagorinsky`/`kEqn`（见 phase*Models.C）

## 字典示例



> （由源码构造函数推断，无官方教程实例）

```c++
// constant/momentumTransport
simulationType LES;

LES
{
    model           kOmegaSSTDES;
    turbulence      on;
}
```

## 参数表

系数通常可在模型子字典覆盖（`Cmu`、`Ck` 等）；默认值见源码 `read`()`。

## 控制方程与关联式

Implementation of the k-omega-SST-DES turbulence model for
incompressible and compressible flows.

DES model described in:
```
Menter, F. R., Kuntz, M., and Langtry, R. (2003).
Ten Years of Industrial Experience with the SST Turbulence Model.
Turbulence, Heat and Mass Transfer 4, ed: K. Hanjalic, Y. Nagano,
& M. Tummers, Begell House, Inc., 625 - 632.
```

Optional support for zonal filtering based on F1 or F2 is provided as
described in the paper.

For further details of the implementation of the base k-omega-SST model
see Foam::kOmegaSST.

See also
Foam::kOmegaSST

## 文献与源码依据

- [`src/MomentumTransportModels/momentumTransportModels/LES/kOmegaSSTDES/kOmegaSSTDES.H`](../../../src/MomentumTransportModels/momentumTransportModels/LES/kOmegaSSTDES/kOmegaSSTDES.H)

## 教程与模板

- 仓库 tutorials 中未检索到 `kOmegaSSTDES` 字面配置；可参考同类 `simulationType` 案例并改 `model`。
- 注册见 [`README`](../README.md) 工厂表。


## 注意事项

- 模型必须在对应库中注册（不可压/可压/相）；见族 README 注册表。
