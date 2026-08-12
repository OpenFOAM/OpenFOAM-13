# `constSolidThermo`

## 一句话

常物性固体 thermo（非拼装 thermoType）

## 适用条件（求解器 / 场 / 前提）

- 适用: `solid`、`solidDisplacement`、多区域 CHT 固体域
- `thermoType` constSolidThermo;` 或等价字典（见教程）

## 字典示例

```c++
Example of uniform constant solid properties specification:
```
thermoType          constSolidThermo;

rho
{
type        uniform;
value       8940;
}

Cv
{
type        uniform;
value       385;
}

kappa
{
type        uniform;
value       380;
}
```

Example of zonal constant solid properties specification where kappa is
different in different zones:
```
thermoType          constSolidThermo;

rho
{
type        uniform;
value       8940;
}

Cv
{
type        uniform;
value       385;
}

kappa
{
type        zonal;
value       380;

zones
{
heater      560;
insulation  100;
}
}
```

Example of non-uniform constant solid properties specification:
```
thermoType          constSolidThermo;

rho
{
type        file;
}

Cv
{
type        file;
}

kappa
{
type        file;
}
```
where each of the field files are read from the constant directory.
```

## 参数表

见源码头文件与教程固体区域物性。

## 控制方程与关联式

Uniform or non-uniform constant solid thermodynamic properties

Each physical property can specified as either `uniform` in which case the
value entry is read, `zonal` in which case the value entry and zone list
are read or `file` in which case the field file in read from the constant
directory.

## 文献与源码依据

- [`src/thermophysicalModels/solidThermo/constSolidThermo/constSolidThermo.H`](../../../src/thermophysicalModels/solidThermo/constSolidThermo/constSolidThermo.H)

## 教程与模板

- `tutorials/multiRegion/CHT/**/constant/solid/physicalProperties`

## 注意事项

- 与拼装型 `heSolidThermo`+`forSolids` 路径并存，勿混用关键字。
