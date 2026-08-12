# timeVaryingMappedFixedValue

## 一句话
从另一区域/补丁映射场值或通量。

## 适用条件（求解器 / 场 / 前提）
- **字典 `type`**：`timeVaryingMappedFixedValue`
- **典型场**：见源码 / 场量纲匹配
- **库 / 加载**：核心库 `libfiniteVolume`（几乎所有求解器内建）

## 字典示例
```
<patch name>
{
    type            timeVaryingMappedFixedValue;
}
```

```
<patch name>
{
    type            timeVaryingMappedFixedValue;
    dataDir         "../<source case name>/postProcessing/sample";
    points          "0/<sample name>/faceCentres";
    sample          <sample name>;
}
```

## 参数表
| 参数 | 含义 | 必需 | 默认 |
|------|------|------|------|
| `setAverage` | Switch to activate setting of average value | no | false |
| `perturb` | Perturb points for regular geometries | no | 1e-5 |
| `fieldTable` | Alternative field name to sample | no | this field name |
| `mapMethod` | Type of mapping | no | planarInterpolation |
| `offset` | Offset to mapped values | no | Zero |
| `dataDir` | Top-level directory of the points and field data \\ |  |  |
| `` | no | constant/boundaryData/\<patch name\> |  |
| `points` | Path including name of points file relative to dataDir \\ |  |  |
| `` | no | points |  |
| `sample` | Name of the sub-directory in the time directories \\ |  |  |
| `containing` the fields` | no | "" |  |

## 控制方程与关联式
从另一区域/补丁映射场值或通量。

类头 `Description` 原文：

> This boundary conditions interpolates the values from a set of supplied
> points in space and time.
> 
> By default the data files should be provide in
> constant/boundaryData/\<patch name\>/ directory:
>   - points             : pointField of locations
>   - \<time\>/\<field\> : field of values at time \<time\>
> 
> Alternatively the names and locations of the points and field files may be
> specified explicitly via the optional dictionary entries:
>   - dataDir \<optional top-level directory of the points and field data>;
>   - points \<optional path including name of points file relative to
>              dataDir\>;
>   - sample \<optional name of the sub-directory in the time directories
>             containing the fields\>;
> This is particularly useful when mapping data from another case for which
> the \c sample \c functionObject is used to obtain the patch field data for
> mapping.
> 
> The default mode of operation (mapMethod planarInterpolation) is to project
> the points onto a plane (constructed from the first three points) and
> construct a 2D triangulation and finds for the face centres the triangle it
> is in and the weights to the 3 vertices.
> 
> The optional mapMethod nearest will avoid all projection and triangulation
> and just use the value at the nearest vertex.
> 
> Values are interpolated linearly between times.

## 文献与源码依据
- 源码：[`src/finiteVolume/fields/fvPatchFields/derived/timeVaryingMappedFixedValue/timeVaryingMappedFixedValueFvPatchFields.C`](../../../src/finiteVolume/fields/fvPatchFields/derived/timeVaryingMappedFixedValue/timeVaryingMappedFixedValueFvPatchFields.C)
- 头文件：[`src/finiteVolume/fields/fvPatchFields/derived/timeVaryingMappedFixedValue/timeVaryingMappedFixedValueFvPatchField.H`](../../../src/finiteVolume/fields/fvPatchFields/derived/timeVaryingMappedFixedValue/timeVaryingMappedFixedValueFvPatchField.H)
- Inventory 备注：core finiteVolume; core finiteVolume (derived dir)

## 教程与模板
- [`tutorials/incompressibleFluid/pitzDailySteadyExperimentalInlet/0/epsilon`](../../../tutorials/incompressibleFluid/pitzDailySteadyExperimentalInlet/0/epsilon)
- [`tutorials/incompressibleFluid/pitzDailySteadyExperimentalInlet/0/k`](../../../tutorials/incompressibleFluid/pitzDailySteadyExperimentalInlet/0/k)
- [`tutorials/incompressibleFluid/pitzDailySteadyExperimentalInlet/0/U`](../../../tutorials/incompressibleFluid/pitzDailySteadyExperimentalInlet/0/U)

## 注意事项
- 类型名大小写敏感；库未链接时 RTS 报 `Unknown patchField type`。
